#pragma once

NMCOMM_API DECLARE_LOG_CATEGORY_EXTERN(LogCommEntity, Log, All);

namespace ctnet
{
#define CTNET_ENTITY_MEMBER(Member, Type) \
private:\
	Type __Entity##Member;\
public:\
	virtual Type& CommGetEntity##Member() { return __Entity##Member; }\
	virtual const Type& CommGetEntity##Member() const { return __Entity##Member; }

#define CTNET_ENTITY_MEMBER_VIRTUAL(Member, Type) \
public:\
	virtual Type* CommGetEntity##Member() { return nullptr; }

	class Entity
	{
		CTNET_ENTITY_MEMBER(ID, int64)
		CTNET_ENTITY_MEMBER(Expire, int32)
		CTNET_ENTITY_MEMBER(Name, FString)
		CTNET_ENTITY_MEMBER(PendingKey, FString)
		CTNET_ENTITY_MEMBER(Active, bool)

	public:
		template<typename EntityType>
		static EntityType* FindPendingEntity(const FString& Key);

		template<typename EntityType>
		static EntityType* FindActiveEntity(int64 Key);

		template<typename EntityType>
		static void CleanupEntity(Entity* E);

		template<typename EntityType>
		static void MarkActive(Entity* E);

		template<typename EntityType>
		static void MarkPending(Entity* E, const FString& InKey = TEXT(""));

		/** kick ct-sync but not completed */
		virtual void CommOnPending() {}

		/** ct-sync completed */
		virtual void CommOnActivated() {}

		/** unloaded */
		virtual void CommOnDeactivated() {}

		virtual ~Entity() {}
	};

	template<typename EntityType>
	class EntityCollection
	{
	public:
		static EntityType* FindPendingEntity(const FString& Key);
		static EntityType* FindActiveEntity(int64 Key);	
		static void MarkActive(Entity* E);
		static void MarkPending(Entity* E, const FString& InKey = TEXT(""));
		static void CleanupEntity(Entity* E);

	private:
		static NMCOMM_API TMap<int64, EntityType*> ActiveEntities;
		static NMCOMM_API TMap<FString, EntityType*> PendingEntities;
	};

	template<typename EntityType>
	FORCEINLINE EntityType* Entity::FindPendingEntity(const FString& Key)
	{
		return EntityCollection<EntityType>::FindPendingEntity(Key);
	}

	template<typename EntityType>
	FORCEINLINE EntityType* Entity::FindActiveEntity(int64 Key)
	{
		return EntityCollection<EntityType>::FindActiveEntity(Key);
	}

	template<typename EntityType>
	FORCEINLINE void Entity::CleanupEntity(Entity* E)
	{
		EntityCollection<EntityType>::CleanupEntity(E);
	}

	template<typename EntityType>
	FORCEINLINE void Entity::MarkActive(Entity* E)
	{
		EntityCollection<EntityType>::MarkActive(E);
	}

	template<typename EntityType>
	FORCEINLINE void Entity::MarkPending(Entity* E, const FString& InKey)
	{
		EntityCollection<EntityType>::MarkPending(E, InKey);
	}

	template<typename EntityType>
	EntityType* EntityCollection<EntityType>::FindPendingEntity(const FString& Key)
	{
		if (PendingEntities.Contains(Key))
		{
			return PendingEntities.FindChecked(Key);
		}
		return nullptr;
	}

	template<typename EntityType>
	EntityType* EntityCollection<EntityType>::FindActiveEntity(int64 Key)
	{
		if (ActiveEntities.Contains(Key))
		{
			return ActiveEntities.FindChecked(Key);
		}
		return nullptr;
	}

	template<typename EntityType>
	void EntityCollection<EntityType>::MarkActive(Entity* E)
	{
		PendingEntities.Remove(E->CommGetEntityPendingKey());
		ActiveEntities.Add(E->CommGetEntityID(), static_cast<EntityType*>(E));
		E->CommGetEntityActive() = true;
		E->CommOnActivated();

		UE_LOG(LogCommEntity, Verbose, TEXT("MarkActive %x %lld %s (pendingKey=%s)"), E, E->CommGetEntityID(), *E->CommGetEntityName(), *E->CommGetEntityPendingKey());
	}

	template<typename EntityType>
	void EntityCollection<EntityType>::MarkPending(Entity* E, const FString& InKey)
	{
		if (InKey.Len() > 0)
		{
			E->CommGetEntityPendingKey() = InKey;
		}
		PendingEntities.Add(E->CommGetEntityPendingKey(), static_cast<EntityType*>(E));
		E->CommOnPending();

		UE_LOG(LogCommEntity, Verbose, TEXT("MarkPending %x %s"), E, *InKey);
	}

	template<typename EntityType>
	void EntityCollection<EntityType>::CleanupEntity(Entity* E)
	{
		UE_LOG(LogCommEntity, Verbose, TEXT("Cleanup %x %lld %s"), E, E->CommGetEntityID(), *E->CommGetEntityName());

		E->CommOnDeactivated();
		E->CommGetEntityActive() = false;
		ActiveEntities.Remove(E->CommGetEntityID());
		PendingEntities.Remove(E->CommGetEntityPendingKey());
		E->CommGetEntityID() = 0;
		E->CommGetEntityExpire() = 0;
		E->CommGetEntityName() = TEXT("");
	}
}