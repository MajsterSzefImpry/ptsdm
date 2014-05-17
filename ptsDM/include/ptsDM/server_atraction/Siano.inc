/*
	@Polski TOP Serwer - Siano.inc
	@Last update: 14 marca 2014 23:25

*/
CMD:hy(playerid, params[]) return cmd_hay(playerid, params);
CMD:hay(playerid, params[])
{
	if(HAY_Trwa == 1)
	    return SCM(playerid, -1, ""C_B"Hay "C_O"juz wystartowa³!");

	if(HAY_Off == 1)
		return SCM(playerid, -1, ""C_O"Ta zabawa jest tymczasowo wy³¹czona.");

	if(GetPVarInt(playerid, "pZapisanyHay") == 1)
	{
		SetPVarInt(playerid, "pZapisanyHay", 0);
		SCM(playerid, 0x00AAFFFF,""C_O"Wypisa³eœ siê z "C_B"Hay");
		HAY_Zapisanych--;
	}else{
		SetPVarInt(playerid, "pZapisanyHay", 1);
		HAY_Zapisanych++;
		SCM(playerid, 0xDD0000FF,""C_O"Zapisa³eœ siê na "C_B"Hay");
	}
	UpdateFunTextDraw();

	if(HAY_Odliczanie == -1 && HAY_Zapisanych >= 3)
	{
		SCMToAll(-1, ""C_B"Hay "C_O"wystartuje za "C_B"20 "C_O"sekund. Mo¿na jeszcze siê zapisywaæ!");
		HAY_Odliczanie = SetTimer("HAY_Start", 20000, 0);
        if(EventTimer != 0) KillTimer(EventTimer);
        TextDrawHideForAll(Event);
        TextDrawSetString(Event, " ");
        TextDrawShowForAll(Event);
   	    EventTimer = SetTimerEx("TD_Startuje_Event", 10, 0, "dd", 20, 3);
	}
	if(HAY_Zapisanych >= 25 && HAY_Odliczanie != -1)
	{
	    KillTimer(HAY_Odliczanie);
	    HAY_Start();
	}
	return 1;
}

HAY_ClearFun(i)
{
	SetPVarInt(i, "pZapisanyCH", 0);
	SetPVarInt(i, "pZapisanySS", 0);
	SetPVarInt(i, "pZapisanyWG", 0);
	SetPVarInt(i, "pZapisanyDD", 0);
	SetPVarInt(i, "pZapisanyTW", 0);
	return 1;
}

forward HAY_Start();
public HAY_Start()
{
	HAY_Trwa = 1;
	HAY_Timer = SetTimer("HAY_End", 240000, 0);
	HAY_Zapisanych = 0;

    Iter_Clear(HAY_Array);
	new pos;
	pLoop(i)
	{
	    if(GetPVarInt(i, "pZapisanyHay") == 1 && IsPlayerAFK(i) == 0 && pInFun[i] == 0)
	    {
   			new Float:flo[3];
			GetPlayerPos(i, flo[0],flo[1],flo[2]);
			SetPVarFloat(i, "floX", flo[0]);
			SetPVarFloat(i, "floY", flo[1]);
			SetPVarFloat(i, "floZ", flo[2]);
			SetPVarInt(i, "floInt", GetPlayerInterior(i));
			SetPVarInt(i, "floVW", GetPlayerVirtualWorld(i));

	        ResetPlayerWeapons(i);
	        SetPlayerVirtualWorld(i, 24);
	        SetPlayerInterior(i, 0);
	        pInFun[i] = 1;
	        HAY_ClearFun(i);
	        SetPlayerHealth(i, 100.0);
	        SetPlayerPos(i,  -571.54 + random(5) - random(5), 789.22 + random(5) - random(5), 90.58);
	        TogglePlayerControllable(i, 0);
	        SetPlayerFacingAngle(i, 0.0);
	        Iter_Add(HAY_Array, i);
	        pos++;
	        HAY_Zapisanych++;
	    }
	}
	if(HAY_Zapisanych <= 1)
	{
	    KillTimer(HAY_Timer);
	    HAY_End();
	    return 1;
	}
	SetTimer("HAY_Tele", 3000, 0);
	UpdateFunStat("HY", HAY_Zapisanych);
	UpdateFunTextDraw();
	return 1;
}
forward HAY_Tele();
public HAY_Tele()
{
	pLoop(i)
	{
	    if(IsPlayerConnected(i) == 1 && pInFun[i] == 1 && GetPVarInt(i, "pZapisanyHay") == 1)
	    {
	        TogglePlayerControllable(i, 1);
	    }
	}
	SetTimer("HAY_Przebieg", 5000, 0);
	return 1;
}
forward HAY_Przebieg();
public HAY_Przebieg()
{
	if(HAY_Trwa == 0) return 0;

	GivePlayerWeapon(Iter_Random(HAY_Array), 24, 1);
	SetTimer("HAY_Przebieg", 5000, 0);
	return 1;
}
forward HAY_End();
public HAY_End()
{
	HAY_Trwa = 0;
	HAY_Odliczanie = -1;
	HAY_Zapisanych = 0;
	HAY_Timer = -1;

	Iter_Clear(HAY_Array);
	pLoop(i)
	{
		if(IsPlayerConnected(i) == 1 && GetPVarInt(i, "pZapisanyHay") == 1 && pInFun[i] == 1)
		{
			SetPVarInt(i, "pZapisanyHay", 0);
			pInFun[i] = 0;
			Odstaw(i);
			SCM(i, -1, ""C_O"Nikt nie wygra³ "C_B"Hay "C_O"Czas min¹³!");
		}
	}
	UpdateFunTextDraw();
	return 1;
}
