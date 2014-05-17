/*
	@Polski TOP Serwer - define.inc
	@Last update: 21 marca 2014 23:25

*/
#define PLAYER_MUTE_TIME_MINUTES (2)
#define C_B "{00DF38}"
#define C_O "{A0A0A0}"
#define czat "{FFFFFF}|{009700}TOP-DM{FFFFFF}|"
#define LEVEL_UP_TIME 10
#define COLOR_ERROR 0xFB0000FF
#define COLOR_MSG 0xFFFFFF00
#define BLACK 0x000000C7//1
#define WHITE 0xFFFFFFBE//2
#define ORANGE 0xFF8000B8//3
#define RED 0xFF0000C7//4
#define BLUE 0x0000FFC5//5
#define VIOLET 0x8000FFC9//6
#define GREEN 0x00FF00D0//7
#define YELLOW 0xFFFF00CC//8
#define PINK 0xFF80FFC7//9
#define SEABLUE 0x5BB9E6CA//10
#define BROWN 0x562C2CD2//11
#define ZLOTY 0xBBBB00FF//12
#define C_WHITE 0xFFFFFFFF
#define C_ORANGE 0xFFA800FF
#define ARMEDBODY_USE_HEAVY_WEAPON (false)
#define SpamLimit (3000)
#undef MAX_PLAYERS
#define MAX_PLAYERS (1)

#define DIALOG_GANG_INFO 1
#define MAKE_COLOUR(%0,%1,%2) ((((%0) & 0xFF) << 16) | (((%1) & 0xFF) << 8) | (((%2) & 0xFF) << 0))

#define SCM SendClientMessage
#define SCMToAll SendClientMessageToAll
#define ShowPlayerDialogEx(%0,%1,%2,%3,%4,%5,%6) ShowPlayerDialog(%0,%1,%2,"{FFCC33}"%3,%4,%5,%6)
#define Dialog(%0,%1,%2,%3,%4,%5) ShowPlayerDialog(%0,%1,%2,DIALOG_T,%3,%4,%5)
#define DIALOG_INPUT DIALOG_STYLE_INPUT
#define DIALOG_BOX DIALOG_STYLE_MSGBOX
#define DIALOG_LIST DIALOG_STYLE_LIST
#define DIALOG_PASS DIALOG_STYLE_PASSWORD
#define DIALOG_T "{FF8B17} ~ Polski TOP Serwer"
#define InfoBox(%0,%1) ShowPlayerDialog(%0,9999,0,DIALOG_T,%1,"Zamknij","")
#define TD_Hide(%0) TextDrawHideForPlayer(%0)
#define TD_Show(%0) TextDrawShowForPlayer(%0)
#define pLoop(%0) for(new %0;%0<=highestID;%0++)
#define ADMIN_PASSWORD "haslo" //has³o administratora.
#define foreachPly(%1) foreach(new %1 : Player)
#define Code_ExTimer_Begin(%0) new CET_%0 = GetTickCount()
#define Code_ExTimer_End(%0) (GetTickCount() - CET_%0)
#define callback->%0(%1) forward %0(%1); public %0(%1)
callback->OnKicked(playerid) return Kick(playerid);
stock KickEx(playerid)
{
	SetTimerEx("OnKicked", 100, false, "i", playerid);
	return 1;
}
#define Kick KickEx
