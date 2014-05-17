/*
	@Polski TOP Serwer - Derby.inc
	@Last update: 14 marca 2014 23:25

*/
CMD:dd(playerid, params[]) return cmd_derby(playerid, params);
CMD:derby(playerid, params[])
{
	if(DD_Trwa == 1)
	    return SCM(playerid, -1, ""C_B"Derby "C_O"juz wystartowa³y!");

	if(DD_Off == 1)
		return SCM(playerid, -1, ""C_O"Ta zabawa jest tymczasowo wy³¹czona.");

	if(GetPVarInt(playerid, "pZapisanyDD") == 1)
	{
		SetPVarInt(playerid, "pZapisanyDD", 0);
		SCM(playerid, 0x00AAFFFF,""C_O"Wypisa³eœ siê z "C_B"Derby");
		DD_Zapisanych--;
	}else{
		SetPVarInt(playerid, "pZapisanyDD", 1);
		DD_Zapisanych++;
		SCM(playerid, 0xDD0000FF,""C_O"Zapisa³eœ siê na "C_B"Derby");
	}
	UpdateFunTextDraw();

	if(DD_Odliczanie == -1 && DD_Zapisanych >= 4)
	{
		SCMToAll(-1, ""C_B"Derby "C_O"wystartuj¹ za "C_B"20 "C_O"sekund. Mo¿na jeszcze siê zapisywaæ!");
		DD_Odliczanie = SetTimer("DD_Start", 20000, 0);
        if(EventTimer != 0) KillTimer(EventTimer);
        TextDrawHideForAll(Event);
        TextDrawSetString(Event, " ");
        TextDrawShowForAll(Event);
   	    EventTimer = SetTimerEx("TD_Startuje_Event", 10, 0, "dd", 20, 2);
	}
	if(DD_Zapisanych >= 14 && DD_Odliczanie != -1)
	{
	    KillTimer(DD_Odliczanie);
	    DD_Start();
	}
	return 1;
}

DD_ClearFun(i)
{
	SetPVarInt(i, "pZapisanyHAY", 0);
	SetPVarInt(i, "pZapisanyCH", 0);
	SetPVarInt(i, "pZapisanySS", 0);
	SetPVarInt(i, "pZapisanyWG", 0);
	SetPVarInt(i, "pZapisanyTW", 0);
	return 1;
}
forward DD_Start();
public DD_Start()
{
	DD_Odliczanie = -1;
	DD_Timer = SetTimer("DD_End", 360000, 0);
	DD_Zapisanych = 0;
	DD_InCar = 0;

	pLoop(i)
	{
	    if(pInFun[i] == 1 || IsPlayerAFK(i) == 1) SetPVarInt(i, "pZapisanyDD", 0);

	    if(IsPlayerConnected(i) == 1 && GetPVarInt(i, "pZapisanyDD") && pInFun[i] == 0)
	    {
   			new Float:flo[3];
			GetPlayerPos(i, flo[0],flo[1],flo[2]);
			SetPVarFloat(i, "floX", flo[0]);
			SetPVarFloat(i, "floY", flo[1]);
			SetPVarFloat(i, "floZ", flo[2]);
			SetPVarInt(i, "floInt", GetPlayerInterior(i));
			SetPVarInt(i, "floVW", GetPlayerVirtualWorld(i));

	        pInFun[i] = 1;
	        DD_ClearFun(i);
	        SetPlayerVirtualWorld(i, 23);
			SetPlayerInterior(i, 0);
			SetPlayerDrunkLevel(i, 0);
			SetPlayerHealth(i, 100.0);
			ResetPlayerWeapons(i);
			SetPlayerPos(i, -1041.93, 614.23, 140.48);
			TogglePlayerControllable(i, 0);
            ShowGameDraw(i, "~w~_~n~_~n~Ladowanie obiektow...", 7500);

			DD_Zapisanych++;
	    }
	}
	DD_Trwa = 1;
	if(DD_Zapisanych <= 1)
	{
	    KillTimer(DD_Timer);
	    DD_End();
	    return 1;
	}
	UpdateFunStat("DD", DD_Zapisanych);
	UpdateFunTextDraw();
	SetTimer("DD_Teleport", 1000, 0);
	return 1;
}
forward DD_Teleport();
public DD_Teleport()
{
    for(new x; x < sizeof DD_Vehicles; x++)
	{
	    SetVehicleToRespawn(DD_Vehicles[x]);
	}
	new spawn;
	pLoop(i)
	{
		if(IsPlayerConnected(i) == 1 && pInFun[i] == 1 && GetPVarInt(i, "pZapisanyDD") == 1)
		{
			TogglePlayerControllable(i, 1);
			SetVehicleParamsEx(DD_Vehicles[spawn], 1,1,0,1,0,0,1);
			PutPlayerInVehicle(i, DD_Vehicles[spawn], 0);
			SetVehicleHealth(DD_Vehicles[spawn], 99999.0);
			spawn++;
		}
	}
	DD_InCar = 1;
	return 1;
}
forward DD_End();
public DD_End()
{
    DD_Trwa = 0;
	DD_Timer = -1;
	DD_Zapisanych = 0;
	DD_Odliczanie = -1;

    pLoop(i)
	{
		if(IsPlayerConnected(i) == 1 && GetPVarInt(i, "pZapisanyDD") == 1 && pInFun[i] == 1)
		{
			SetPVarInt(i, "pZapisanyDD", 0);
			pInFun[i] = 0;
			Odstaw(i);
			SCM(i, -1, ""C_O"Nikt nie wygra³ "C_B"Derby "C_O"Czas min¹³!");
		}
	}

	UpdateFunTextDraw();
	return 1;
}
