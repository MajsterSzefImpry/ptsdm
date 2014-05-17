/*
	@Polski TOP Serwer - Tower.inc
	@Last update: 14 marca 2014 23:25

*/
CMD:tw(playerid, params[])
{
	if(TW_Trwa == 1)
	    return SCM(playerid, -1, ""C_B"Tower "C_O"juz wystartowa³");

	if(TW_Off == 1)
		return SCM(playerid, -1, ""C_O"Ta zabawa jest tymczasowo wy³¹czona.");

	if(GetPVarInt(playerid, "pZapisanyTW") == 1)
	{
		SetPVarInt(playerid, "pZapisanyTW", 0);
		SCM(playerid, 0x00AAFFFF,""C_O"Wypisa³eœ siê z "C_B"Tower");
		TW_Zapisanych--;
	}else{
		SetPVarInt(playerid, "pZapisanyTW", 1);
		TW_Zapisanych++;
		SCM(playerid, 0xDD0000FF,""C_O"Zapisa³eœ siê na "C_B"Tower");
	}
	UpdateFunTextDraw();

	if(TW_Odliczanie == -1 && TW_Zapisanych >= 2)
	{
		SCMToAll(-1, ""C_B"Tower "C_O"wystartuje za "C_B"20 "C_O"sekund. Mo¿na jeszcze siê zapisywac!");
		TW_Odliczanie = SetTimer("TW_Start", 20000, 0);
        if(EventTimer != 0) KillTimer(EventTimer);
        TextDrawHideForAll(Event);
        TextDrawSetString(Event, " ");
        TextDrawShowForAll(Event);
   	    EventTimer = SetTimerEx("TD_Startuje_Event", 10, 0, "dd", 20, 5);
	}
	return 1;
}

TW_ClearFun(i)
{
	SetPVarInt(i, "pZapisanyHAY", 0);
	SetPVarInt(i, "pZapisanyCH", 0);
	SetPVarInt(i, "pZapisanyWG", 0);
	SetPVarInt(i, "pZapisanyDD", 0);
	SetPVarInt(i, "pZapisanySS", 0);
	return 1;
}

forward TW_Start();
public TW_Start()
{
	TW_Trwa = 1;
	TW_Timer = SetTimer("TW_End", 360000, 0);
	TW_Tick = GetTickCount();
	new count;
	pLoop(i)
	{
	    if(pInFun[i] == 1 || IsPlayerAFK(i) == 1) SetPVarInt(i, "pZapisanyTW", 0);

	    if(IsPlayerConnected(i) == 1 && GetPVarInt(i, "pZapisanyTW") == 1 && pInFun[i] == 0)
	    {
			new Float:flo[3];
			GetPlayerPos(i, flo[0],flo[1],flo[2]);
			SetPVarFloat(i, "floX", flo[0]);
			SetPVarFloat(i, "floY", flo[1]);
			SetPVarFloat(i, "floZ", flo[2]);
			SetPVarInt(i, "floInt", GetPlayerInterior(i));
			SetPVarInt(i, "floVW", GetPlayerVirtualWorld(i));

	        ResetPlayerWeapons(i);
	        SetPlayerVirtualWorld(i, 27);
	        SetPlayerInterior(i, 0);
			pInFun[i] = 1;
			TW_ClearFun(i);
		    SetPlayerPos(i, -3096.76 + random(2) - random(2), 78.76 + random(2) - random(2), 17.56);
            TogglePlayerControllable(i, 0);
			TogglePlayerDynamicCP(i, TW_Checkpoint, 1);
			count++;
		}
	}
	TW_Zapisanych = count;

	if(TW_Zapisanych == 0)
	{
	    KillTimer(TW_Timer);
	    TW_End();
	    return 1;
	}
	UpdateFunStat("TW", TW_Zapisanych);
	SetTimer("TW_Tele", 5000, 0);
	UpdateFunTextDraw();
	return 1;
}
forward TW_Tele();
public TW_Tele()
{
	pLoop(i)
	{
	    if(IsPlayerConnected(i) == 1 && GetPVarInt(i, "pZapisanyTW") == 1 && pInFun[i] == 1)
	    {
	        TogglePlayerControllable(i, 1);
	        SCM(i, -1, ""C_O"Aby wygraæ, musisz wejœæ na szczyt!");
	    }
	}
	return 1;
}

forward TW_End();
public TW_End()
{
	TW_Trwa = 0;
	TW_Timer = -1;
	TW_Zapisanych = 0;
	TW_Odliczanie = -1;

	pLoop(i)
	{
		if(IsPlayerConnected(i) == 1 && GetPVarInt(i, "pZapisanyTW") == 1 && pInFun[i] == 1)
		{
			SetPVarInt(i, "pZapisanyTW", 0);
			pInFun[i] = 0;
			Odstaw(i);
			DisablePlayerCheckpoint(i);
			SCM(i, -1, ""C_O"Nikt nie wygra³ "C_B"Tower "C_O"Czas min¹³!");
		}
	}

	UpdateFunTextDraw();
	return 1;
}
