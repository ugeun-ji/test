﻿// Rule
// CT->DS : 1 ~ 10000
// DS->CT : 40001 ~ 50000
// CT->User : 20001 ~ 30000
// User->CT : 30001 ~ 40000
// Login->User : 50001 ~ 53000
// User->Login : 53001 ~ 56000
constexpr XUSHORT C2U_ASSIGN_SERVER = 20001;
constexpr XUSHORT C2U_CLIENT_EXPIRATION = 20002;
constexpr XUSHORT C2U_SERVER_LIST = 20003;

constexpr XUSHORT U2C_VERIFICATION = 30001;
constexpr XUSHORT U2C_ASSIGN_SERVER = 30002;
constexpr XUSHORT U2C_SERVER_LIST = 30003;

constexpr XUSHORT D2C_CHEAT						= 60000;
constexpr XUSHORT D2C_REGISTER_SERVER			= 40001;
constexpr XUSHORT D2C_ENTER_CHARACTER			= 40002;
constexpr XUSHORT D2C_LEAVE_CHARACTER			= 40003;
constexpr XUSHORT D2C_CREATE_PARTY				= 40004;
constexpr XUSHORT D2C_PARTY_JOIN				= 40005;
constexpr XUSHORT D2C_PARTY_LEAVE				= 40006;
constexpr XUSHORT D2C_PARTY_INVITE				= 40007;
// 40008
constexpr XUSHORT D2C_PVP_REGISTER_MATCH		= 40009;
constexpr XUSHORT D2C_PVP_CANCEL_MATCH			= 40010;
constexpr XUSHORT D2C_PVP_CREATE_GAME_RESULT    = 40011;
constexpr XUSHORT D2C_PVP_START_GAME			= 40012;
constexpr XUSHORT D2C_PVP_FINISH_GAME			= 40013;
constexpr XUSHORT D2C_NEW_ITEM					= 40014;
constexpr XUSHORT D2C_UPDATE_ITEM				= 40015;
constexpr XUSHORT D2C_UPDATE_CHECKPOINT			= 40016;
constexpr XUSHORT D2C_EQUIP_UNEQUIP				= 40017;
constexpr XUSHORT D2C_UPDATE_MONEY				= 40018;
constexpr XUSHORT D2C_PARTY_MATCH				= 40019;
constexpr XUSHORT D2C_PARTY_MATCH_CANCEL		= 40020;
constexpr XUSHORT D2C_ALLOC_CHANNEL				= 40021;
constexpr XUSHORT D2C_ADD_ITEM					= 40022;
constexpr XUSHORT D2C_UPDATE_BULLET				= 40023;
constexpr XUSHORT D2C_PRODUCT_ITEM				= 40024;
constexpr XUSHORT D2C_UPDATE_AMMO				= 40025;
constexpr XUSHORT D2C_WEAPON_BULLET				= 40026;
constexpr XUSHORT D2C_PARTY_BEACON				= 40027;
constexpr XUSHORT D2C_PARTY_BEACON_LIST			= 40028;
constexpr XUSHORT D2C_PARTY_DENY				= 40029;
constexpr XUSHORT D2C_BEGIN_QUEST				= 40032;
constexpr XUSHORT D2C_UPDATE_QUEST_OBJECTIVE	= 40033;
constexpr XUSHORT D2C_CANCEL_QUEST				= 40034;
constexpr XUSHORT D2C_PARTY_MOVE				= 40035;
constexpr XUSHORT D2C_OPEN_WAYPOINT				= 40036;

constexpr XUSHORT C2D_CHEAT						= 20000;
constexpr XUSHORT C2D_UNEXPECTED_ERROR			= 1;
constexpr XUSHORT C2D_REGISTER_SERVER			= 2;
constexpr XUSHORT C2D_ENTER_CHARACTER			= 3;
constexpr XUSHORT C2D_PARTY_INFO				= 4;
constexpr XUSHORT C2D_PARTY_INVITE				= 5;
// 6
constexpr XUSHORT C2D_PVP_MATCHING_SUCCESS		= 7;
constexpr XUSHORT C2D_PVP_CREATE_GAME			= 8;
constexpr XUSHORT C2D_NEW_ITEM					= 11;
constexpr XUSHORT C2D_REMOVE_ITEM				= 12;
constexpr XUSHORT C2D_EQUIP_UNEQUIP				= 13;
constexpr XUSHORT C2D_PVP_FINISH_GAME			= 14;
constexpr XUSHORT C2D_UPDATE_ITEM				= 15;
constexpr XUSHORT C2D_PRODUCT_ITEM				= 16;
constexpr XUSHORT C2D_UPDATE_AMMO				= 17;
constexpr XUSHORT C2D_UPDATE_GOLD				= 18;
constexpr XUSHORT C2D_PARTY_BEACON_LIST			= 19;
constexpr XUSHORT C2D_PARTY_DENY				= 20;
constexpr XUSHORT C2D_ALLOC_CHANNEL				= 21;
constexpr XUSHORT C2D_PARTY_DISMISS				= 22;
constexpr XUSHORT C2D_BEGIN_QUEST				= 23;
constexpr XUSHORT C2D_END_QUEST					= 24;
constexpr XUSHORT C2D_UPDATE_QUEST_OBJECTIVE	= 25;
constexpr XUSHORT C2D_CANCEL_QUEST				= 26;
constexpr XUSHORT C2D_PARTY_QUEST_INFO				= 28;
constexpr XUSHORT C2D_UPDATE_UNLOCK_QUEST		= 29;

constexpr XUSHORT U2L_LOGIN = 53001;
constexpr XUSHORT U2L_NEWCHAR = 53002;
constexpr XUSHORT U2L_CHARLIST = 53003;
constexpr XUSHORT U2L_REMOVECHAR = 53004;
constexpr XUSHORT U2L_RELOGIN = 53005;

constexpr XUSHORT L2U_LOGIN = 50001;
constexpr XUSHORT L2U_NEWCHAR = 50002;
constexpr XUSHORT L2U_CHARLIST = 50003;
