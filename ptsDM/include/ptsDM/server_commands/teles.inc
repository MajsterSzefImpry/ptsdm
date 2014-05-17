/*
	@Polski TOP Serwer - teles.inc
	@Last update: 14 marca 2014 23:25

*/

forward CarTeleport(playerid,interior,Float:x,Float:y,Float:z);
public CarTeleport(playerid,interior,Float:x,Float:y,Float:z)
{
	if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
	{
		new VehicleID = GetPlayerVehicleID(playerid);
		SetVehiclePos(VehicleID, x,y,z);
		SetPlayerInterior(playerid,interior);
		LinkVehicleToInterior(VehicleID,interior);
		SetVehicleVirtualWorld(VehicleID,0);
	} else {
		SetPlayerPos(playerid, x,y,z);
		SetPlayerVirtualWorld(playerid,0);
		SetPlayerInterior(playerid,interior);
	}
	return 1;
}

CMD:teles(playerid, params[])
{
	new long_string[1359];
	strcat(long_string, "/armata - teleportujesz siê na armate.\n/zadupie - teleportujesz siê na zadupie.\n/wojsko - teleportujesz siê na strefê œmierci.\n/molo - teleportujesz siê na molo.\n/plaza - teleportujesz siê na pla¿ê.\n/lslot - teleportujesz siê na lotnisko w LS.\n/ls - teleportujesz siê do LS.\n/lv - teleportujesz siê do LV.\n/lv2 - teleportujesz siê do LV 2.\n/sf - teleportujesz siê do SF.\n/rury1 - teleportujesz siê na rury 1.\n/impra1 - teleportujesz siê na imprezê 1.\n/impra2 - teleportu");
	strcat(long_string, "jesz siê na imprezê 2.\n/parkour1 - teleportujesz siê na parkour 1.\n/parkour2 - teleportujesz siê na parkour 2.\n/parkour3 - teleportujesz siê na parkour 3.\n/starelotnisko - teleportujesz siê na stare lotnisko.\n/kart - teleportujesz siê na tor kartingowy.\n/rampy1 - teleportujesz siê na rampy 1.\n/stunt1 - teleportujesz siê na stunt 1.\n/stunt2 - teleportujesz siê na stunt 2.\n/tunel - teleport");
	strcat(long_string, "ujesz siê do tunelu.\n/sflot - teleportujesz siê na lotnisko w SF.\n/lvlot - teleportujesz siê na lotnisko w LV.\n/drift - teleportujesz siê na drift.\n/arenasolo - teleportujesz siê na miejsce solówek.\n/szpital - teleportujesz siê do szpitala.\n/jump1 - teleportujesz siê na jump 1.\n/jump2 - teleportujesz siê na jump 2.\n/baza - teleportujesz siê na bazê.\n/tor - teleportujesz siê na tor.\n/zjaz");
	strcat(long_string, "d1 - teleportujesz siê na zjazd 1.\n/zjazd2 - teleportujesz siê na zjazd 2.");
	ShowPlayerDialog(playerid, 31, DIALOG_STYLE_MSGBOX, "Spis teleportów.", long_string, "Zamknij", "");
	return 1;
}

CMD:armata(playerid,cmdtext[],inputtext[]){
	CarTeleport(playerid,0,-2385.02, 2924.03, 362.552);
	new telepos[300];
    format(telepos, sizeof(telepos), "(Teleport):~r~ /Armata");
    TextDrawSetString(TD_Teleport_, telepos);
    TD_Show(playerid, TD_Teleport_);
    SetTimerEx("TD_Teleport_Hide", 4000, 0, "d", playerid);
    PlayerPlaySound(playerid,1150,0.0,0.0,0.0);
	return 1;
	#pragma unused cmdtext
}

CMD:zadupie(playerid,cmdtext[],inputtext[]){
	CarTeleport(playerid,0,-1383.3280,-1507.3010,102.2328);
	new telepos[300];
    format(telepos, sizeof(telepos), "(Teleport):~r~ /Zadupie");
    TextDrawSetString(TD_Teleport_, telepos);
    TD_Show(playerid, TD_Teleport_);
    SetTimerEx("TD_Teleport_Hide", 4000, 0, "d", playerid);
    PlayerPlaySound(playerid,1150,0.0,0.0,0.0);
	return 1;
	#pragma unused cmdtext
}

CMD:wojsko(playerid,cmdtext[],inputtext[]){
	CarTeleport(playerid,0,353.3343,1786.4851,17.7532);
	new telepos[300];
    format(telepos, sizeof(telepos), "(Teleport):~r~ /Wojsko");
    TextDrawSetString(TD_Teleport_, telepos);
    TD_Show(playerid, TD_Teleport_);
    SetTimerEx("TD_Teleport_Hide", 4000, 0, "d", playerid);
    PlayerPlaySound(playerid,1150,0.0,0.0,0.0);
	return 1;
	#pragma unused cmdtext
}

CMD:molo(playerid,cmdtext[],inputtext[]){
	CarTeleport(playerid,0,369.33,-2034.75,7.23);
	new telepos[300];
    format(telepos, sizeof(telepos), "(Teleport):~r~ /Molo");
    TextDrawSetString(TD_Teleport_, telepos);
    TD_Show(playerid, TD_Teleport_);
    SetTimerEx("TD_Teleport_Hide", 4000, 0, "d", playerid);
    PlayerPlaySound(playerid,1150,0.0,0.0,0.0);
	return 1;
	#pragma unused cmdtext
}

CMD:plaza(playerid,cmdtext[]){
	CarTeleport(playerid,0,333.33,-1799.07,4.25);
	new telepos[300];
    format(telepos, sizeof(telepos), "(Teleport):~r~ /Plaza");
    TextDrawSetString(TD_Teleport_, telepos);
    TD_Show(playerid, TD_Teleport_);
    SetTimerEx("TD_Teleport_Hide", 4000, 0, "d", playerid);
    PlayerPlaySound(playerid,1150,0.0,0.0,0.0);
	return 1;
	#pragma unused cmdtext
}

CMD:lslot(playerid,cmdtext[]){
	CarTeleport(playerid,0,1929.67,-2363.46,13.11);
	new telepos[300];
    format(telepos, sizeof(telepos), "(Teleport):~r~ /LsLot");
    TextDrawSetString(TD_Teleport_, telepos);
    TD_Show(playerid, TD_Teleport_);
    SetTimerEx("TD_Teleport_Hide", 4000, 0, "d", playerid);
    PlayerPlaySound(playerid,1150,0.0,0.0,0.0);
	return 1;
	#pragma unused cmdtext
}

CMD:ls(playerid,cmdtext[]){
	CarTeleport(playerid,0,2511.62,-1671.87,13.01);
	new telepos[300];
    format(telepos, sizeof(telepos), "(Teleport):~r~ /Ls");
    TextDrawSetString(TD_Teleport_, telepos);
    TD_Show(playerid, TD_Teleport_);
    SetTimerEx("TD_Teleport_Hide", 4000, 0, "d", playerid);
    PlayerPlaySound(playerid,1150,0.0,0.0,0.0);
	return 1;
	#pragma unused cmdtext
}

CMD:lv(playerid,cmdtext[]){
	CarTeleport(playerid,0,2151.58,1020.5,10.39);
	new telepos[300];
    format(telepos, sizeof(telepos), "(Teleport):~r~ /Lv");
    TextDrawSetString(TD_Teleport_, telepos);
    TD_Show(playerid, TD_Teleport_);
    SetTimerEx("TD_Teleport_Hide", 4000, 0, "d", playerid);
    PlayerPlaySound(playerid,1150,0.0,0.0,0.0);
	return 1;
	#pragma unused cmdtext
}

CMD:lv2(playerid,cmdtext[]){
	CarTeleport(playerid,0,2524.38,2468.37,21.97);
	new telepos[300];
    format(telepos, sizeof(telepos), "(Teleport):~r~ /Lv2");
    TextDrawSetString(TD_Teleport_, telepos);
    TD_Show(playerid, TD_Teleport_);
    SetTimerEx("TD_Teleport_Hide", 4000, 0, "d", playerid);
    PlayerPlaySound(playerid,1150,0.0,0.0,0.0);
	return 1;
	#pragma unused cmdtext
}

CMD:sf(playerid,cmdtext[]){
	CarTeleport(playerid,0,-2034.62,171.13,28.94);
	new telepos[300];
    format(telepos, sizeof(telepos), "(Teleport):~r~ /Sf");
    TextDrawSetString(TD_Teleport_, telepos);
    TD_Show(playerid, TD_Teleport_);
    SetTimerEx("TD_Teleport_Hide", 4000, 0, "d", playerid);
    PlayerPlaySound(playerid,1150,0.0,0.0,0.0);
	return 1;
	#pragma unused cmdtext
}

CMD:rury1(playerid,cmdtext[]){
	CarTeleport(playerid,0,2258.82,561.3,7.91);
	new telepos[300];
    format(telepos, sizeof(telepos), "(Teleport):~r~ /Rury1");
    TextDrawSetString(TD_Teleport_, telepos);
    TD_Show(playerid, TD_Teleport_);
    SetTimerEx("TD_Teleport_Hide", 4000, 0, "d", playerid);
    PlayerPlaySound(playerid,1150,0.0,0.0,0.0);
	return 1;
	#pragma unused cmdtext
}

CMD:impra1(playerid,cmdtext[]){
	CarTeleport(playerid,0,2110.45,2163.49,10.84);
	new telepos[300];
    format(telepos, sizeof(telepos), "(Teleport):~r~ /Impra1");
    TextDrawSetString(TD_Teleport_, telepos);
    TD_Show(playerid, TD_Teleport_);
    SetTimerEx("TD_Teleport_Hide", 4000, 0, "d", playerid);
    new Handleid[MAX_PLAYERS];
    Handleid[playerid] = Audio_PlayStreamed(playerid, "http://top.xaa.pl/ptsdm/impra/impra_1.mp3");
    Audio_Set3DPosition(playerid, Handleid[playerid], 2058.5076, 2178.6829, 10.8660 , 60.0);
    PlayerPlaySound(playerid,1150,0.0,0.0,0.0);
	return 1;
	#pragma unused cmdtext
}

CMD:impra2(playerid,cmdtext[]){
	CarTeleport(playerid,0,-2087.53,-2323.48,30.69);
	new telepos[300];
    format(telepos, sizeof(telepos), "(Teleport):~r~ /Impra2");
    TextDrawSetString(TD_Teleport_, telepos);
    TD_Show(playerid, TD_Teleport_);
    SetTimerEx("TD_Teleport_Hide", 4000, 0, "d", playerid);
    new Handleid[MAX_PLAYERS];
    Handleid[playerid] = Audio_PlayStreamed(playerid, "http://top.xaa.pl/ptsdm/impra/impra_2.mp3");
    Audio_Set3DPosition(playerid, Handleid[playerid], -2095.1377,-2313.1892,23.6385 , 60.0);
    PlayerPlaySound(playerid,1150,0.0,0.0,0.0);
	return 1;
	#pragma unused cmdtext
}

CMD:parkour1(playerid,cmdtext[]){
	CarTeleport(playerid,0,-2018.66,36.4,33.35);
	new telepos[300];
    format(telepos, sizeof(telepos), "(Teleport):~r~ /Parkour1");
    TextDrawSetString(TD_Teleport_, telepos);
    TD_Show(playerid, TD_Teleport_);
    SetTimerEx("TD_Teleport_Hide", 4000, 0, "d", playerid);
    PlayerPlaySound(playerid,1150,0.0,0.0,0.0);
	return 1;
	#pragma unused cmdtext
}

CMD:parkour2(playerid,cmdtext[]){
	CarTeleport(playerid,0,1454.63,-1740.79,13.73);
	new telepos[300];
    format(telepos, sizeof(telepos), "(Teleport):~r~ /Parkour2");
    TextDrawSetString(TD_Teleport_, telepos);
    TD_Show(playerid, TD_Teleport_);
    SetTimerEx("TD_Teleport_Hide", 4000, 0, "d", playerid);
    PlayerPlaySound(playerid,1150,0.0,0.0,0.0);
	return 1;
	#pragma unused cmdtext
}

CMD:parkour3(playerid,cmdtext[]){
	CarTeleport(playerid,0,1440.95,-1584.12,13.63);
	new telepos[300];
    format(telepos, sizeof(telepos), "(Teleport):~r~ /Parkour3");
    TextDrawSetString(TD_Teleport_, telepos);
    TD_Show(playerid, TD_Teleport_);
    SetTimerEx("TD_Teleport_Hide", 4000, 0, "d", playerid);
    PlayerPlaySound(playerid,1150,0.0,0.0,0.0);
	return 1;
	#pragma unused cmdtext
}

CMD:starelotnisko(playerid,cmdtext[]){
	CarTeleport(playerid,0,402.98,2535.57,16.65);
	new telepos[300];
    format(telepos, sizeof(telepos), "(Teleport):~r~ /StareLotnisko");
    TextDrawSetString(TD_Teleport_, telepos);
    TD_Show(playerid, TD_Teleport_);
    SetTimerEx("TD_Teleport_Hide", 4000, 0, "d", playerid);
    PlayerPlaySound(playerid,1150,0.0,0.0,0.0);
	return 1;
	#pragma unused cmdtext
}

CMD:kart(playerid,cmdtext[]){
	CarTeleport(playerid,0,283.3,1425.16,10.71);
	new telepos[300];
    format(telepos, sizeof(telepos), "(Teleport):~r~ /Kart");
    TextDrawSetString(TD_Teleport_, telepos);
    TD_Show(playerid, TD_Teleport_);
    SetTimerEx("TD_Teleport_Hide", 4000, 0, "d", playerid);
    PlayerPlaySound(playerid,1150,0.0,0.0,0.0);
	return 1;
	#pragma unused cmdtext
}

CMD:rampy1(playerid,cmdtext[]){
	CarTeleport(playerid,0,1372.18,-1128.78,24.54);
	new telepos[300];
    format(telepos, sizeof(telepos), "(Teleport):~r~ /Rampy1");
    TextDrawSetString(TD_Teleport_, telepos);
    TD_Show(playerid, TD_Teleport_);
    SetTimerEx("TD_Teleport_Hide", 4000, 0, "d", playerid);
    PlayerPlaySound(playerid,1150,0.0,0.0,0.0);
	return 1;
	#pragma unused cmdtext
}

CMD:stunt1(playerid,cmdtext[]){
	CarTeleport(playerid,0,-296.1,89.15,23.6);
	new telepos[300];
    format(telepos, sizeof(telepos), "(Teleport):~r~ /Stunt1");
    TextDrawSetString(TD_Teleport_, telepos);
    TD_Show(playerid, TD_Teleport_);
    SetTimerEx("TD_Teleport_Hide", 4000, 0, "d", playerid);
    PlayerPlaySound(playerid,1150,0.0,0.0,0.0);
	return 1;
	#pragma unused cmdtext
}

CMD:stunt2(playerid,cmdtext[]){
	CarTeleport(playerid,0,2700.25,-2449.92,13.64);
	new telepos[300];
    format(telepos, sizeof(telepos), "(Teleport):~r~ /Stunt2");
    TextDrawSetString(TD_Teleport_, telepos);
    TD_Show(playerid, TD_Teleport_);
    SetTimerEx("TD_Teleport_Hide", 4000, 0, "d", playerid);
    PlayerPlaySound(playerid,1150,0.0,0.0,0.0);
	return 1;
	#pragma unused cmdtext
}

CMD:tunel(playerid,cmdtext[]){
	CarTeleport(playerid,0,1712.51,-2666.9,-1.25);
	new telepos[300];
    format(telepos, sizeof(telepos), "(Teleport):~r~ /Tunel");
    TextDrawSetString(TD_Teleport_, telepos);
    TD_Show(playerid, TD_Teleport_);
    SetTimerEx("TD_Teleport_Hide", 4000, 0, "d", playerid);
    PlayerPlaySound(playerid,1150,0.0,0.0,0.0);
	return 1;
	#pragma unused cmdtext
}

CMD:sflot(playerid,cmdtext[]){
	CarTeleport(playerid,0,-1351.06,-287.89,14.24);
	new telepos[300];
    format(telepos, sizeof(telepos), "(Teleport):~r~ /SfLot");
    TextDrawSetString(TD_Teleport_, telepos);
    TD_Show(playerid, TD_Teleport_);
    SetTimerEx("TD_Teleport_Hide", 4000, 0, "d", playerid);
    PlayerPlaySound(playerid,1150,0.0,0.0,0.0);
	return 1;
	#pragma unused cmdtext
}

CMD:lvlot(playerid,cmdtext[]){
	CarTeleport(playerid,0,1479.68,1180.3,10.82);
	new telepos[300];
    format(telepos, sizeof(telepos), "(Teleport):~r~ /LvLot");
    TextDrawSetString(TD_Teleport_, telepos);
    TD_Show(playerid, TD_Teleport_);
    SetTimerEx("TD_Teleport_Hide", 4000, 0, "d", playerid);
    PlayerPlaySound(playerid,1150,0.0,0.0,0.0);
	return 1;
	#pragma unused cmdtext
}

CMD:drift(playerid,cmdtext[]){
	CarTeleport(playerid,0,-9391.8984,-1018.3461,16.7271);
	new telepos[300];
    format(telepos, sizeof(telepos), "(Teleport):~r~ /Drift");
    TextDrawSetString(TD_Teleport_, telepos);
    TD_Show(playerid, TD_Teleport_);
    SetTimerEx("TD_Teleport_Hide", 4000, 0, "d", playerid);
    PlayerPlaySound(playerid,1150,0.0,0.0,0.0);
	return 1;
	#pragma unused cmdtext
}

CMD:arenasolo(playerid,cmdtext[]){
	CarTeleport(playerid,0,1161.0435,8966.9961,15.4284);
	new telepos[300];
    format(telepos, sizeof(telepos), "(Teleport):~r~ /ArenaSolo");
    TextDrawSetString(TD_Teleport_, telepos);
    TD_Show(playerid, TD_Teleport_);
    SetTimerEx("TD_Teleport_Hide", 4000, 0, "d", playerid);
    PlayerPlaySound(playerid,1150,0.0,0.0,0.0);
	return 1;
	#pragma unused cmdtext
}

CMD:szpital(playerid,cmdtext[]){
	CarTeleport(playerid,0,2032.8450,-1416.2668,18.1493);
	new telepos[300];
    format(telepos, sizeof(telepos), "(Teleport):~r~ /Szpital");
    TextDrawSetString(TD_Teleport_, telepos);
    TD_Show(playerid, TD_Teleport_);
    SetTimerEx("TD_Teleport_Hide", 4000, 0, "d", playerid);
    PlayerPlaySound(playerid,1150,0.0,0.0,0.0);
	return 1;
	#pragma unused cmdtext
}

CMD:jump1(playerid,cmdtext[]){
	CarTeleport(playerid,0,1372.4186,-1128.6395,24.8559);
	new telepos[300];
    format(telepos, sizeof(telepos), "(Teleport):~r~ /Jump1");
    TextDrawSetString(TD_Teleport_, telepos);
    TD_Show(playerid, TD_Teleport_);
    SetTimerEx("TD_Teleport_Hide", 4000, 0, "d", playerid);
    PlayerPlaySound(playerid,1150,0.0,0.0,0.0);
	return 1;
	#pragma unused cmdtext
}

CMD:jump2(playerid,cmdtext[]){
	CarTeleport(playerid,0,1383.9862,-1553.5475,14.5795);
	new telepos[300];
    format(telepos, sizeof(telepos), "(Teleport):~r~ /Jump2");
    TextDrawSetString(TD_Teleport_, telepos);
    TD_Show(playerid, TD_Teleport_);
    SetTimerEx("TD_Teleport_Hide", 4000, 0, "d", playerid);
    PlayerPlaySound(playerid,1150,0.0,0.0,0.0);
	return 1;
	#pragma unused cmdtext
}

CMD:baza(playerid,cmdtext[]){
	CarTeleport(playerid,0,2696.6431,-1737.8375,42.0512);
	new telepos[300];
    format(telepos, sizeof(telepos), "(Teleport):~r~ /Baza");
    TextDrawSetString(TD_Teleport_, telepos);
    TD_Show(playerid, TD_Teleport_);
    SetTimerEx("TD_Teleport_Hide", 4000, 0, "d", playerid);
    PlayerPlaySound(playerid,1150,0.0,0.0,0.0);
	return 1;
	#pragma unused cmdtext
}

CMD:tor(playerid,cmdtext[]){
	CarTeleport(playerid,0,-7251.6104,2370.2471,13.6709);
	new telepos[300];
    format(telepos, sizeof(telepos), "(Teleport):~r~ /Tor1");
    TextDrawSetString(TD_Teleport_, telepos);
    TD_Show(playerid, TD_Teleport_);
    SetTimerEx("TD_Teleport_Hide", 4000, 0, "d", playerid);
    PlayerPlaySound(playerid,1150,0.0,0.0,0.0);
	return 1;
	#pragma unused cmdtext
}

CMD:zjazd1(playerid,cmdtext[]){
	CarTeleport(playerid,0,3589.8950,-1858.1565,319.6302);
	new telepos[300];
    format(telepos, sizeof(telepos), "(Teleport):~r~ /Zjazd1");
    TextDrawSetString(TD_Teleport_, telepos);
    TD_Show(playerid, TD_Teleport_);
    SetTimerEx("TD_Teleport_Hide", 4000, 0, "d", playerid);
    PlayerPlaySound(playerid,1150,0.0,0.0,0.0);
	return 1;
	#pragma unused cmdtext
}

CMD:zjazd2(playerid,cmdtext[]){
	CarTeleport(playerid,0,-3569.0496,-284.9429,333.8637);
	new telepos[300];
    format(telepos, sizeof(telepos), "(Teleport):~r~ /Zjazd2");
    TextDrawSetString(TD_Teleport_, telepos);
    TD_Show(playerid, TD_Teleport_);
    SetTimerEx("TD_Teleport_Hide", 4000, 0, "d", playerid);
    PlayerPlaySound(playerid,1150,0.0,0.0,0.0);
	return 1;
	#pragma unused cmdtext
}
