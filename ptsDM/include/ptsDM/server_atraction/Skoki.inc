/*
	@Polski TOP Serwer - Skoki.inc
	@Last update: 14 marca 2014 23:25

*/
CMD:ss(playerid, params[]) return cmd_skoki(playerid, params);
CMD:skoki(playerid, params[])
{
	if(SS_Trwa == 1)
	    return SCM(playerid, -1, ""C_B"Skoki "C_O"spadochronowe juz wystartowa³y");

	if(SS_Off == 1)
		return SCM(playerid, -1, ""C_O"Ta zabawa jest tymczasowo wy³¹czona.");


	if(GetPVarInt(playerid, "pZapisanySS") == 1)
	{
		SetPVarInt(playerid, "pZapisanySS", 0);
		SCM(playerid, 0x00AAFFFF,""C_O"Wypisa³eœ siê z "C_B"Skokw Spadochronowych");
		SS_Zapisanych--;
	}else{
		SetPVarInt(playerid, "pZapisanySS", 1);
		SS_Zapisanych++;
		SCM(playerid, 0xDD0000FF,""C_O"Zapisa³eœ siê na "C_B"Skoki Spadochronowe");
	}
	UpdateFunTextDraw();

	if(SS_Odliczanie == -1 && SS_Zapisanych >= 2)
	{
		SCMToAll(-1, ""C_B"Skoki Spadochronowe "C_O"wystartuj¹ za "C_B"20 "C_O"sekund. Mo¿na jeszcze siê zapisywaæ!");
		SS_Odliczanie = SetTimer("SS_Start", 20000, 0);
        if(EventTimer != 0) KillTimer(EventTimer);
        TextDrawHideForAll(Event);
        TextDrawSetString(Event, " ");
        TextDrawShowForAll(Event);
   	    EventTimer = SetTimerEx("TD_Startuje_Event", 10, 0, "dd", 20, 4);
	}
	return 1;
}

SS_ClearFun(i)
{
	SetPVarInt(i, "pZapisanyHAY", 0);
	SetPVarInt(i, "pZapisanyCH", 0);
	SetPVarInt(i, "pZapisanyWG", 0);
	SetPVarInt(i, "pZapisanyDD", 0);
	SetPVarInt(i, "pZapisanyTW", 0);
	return 1;
}
forward SS_Start();
public SS_Start()
{
	SS_Trwa = 1;
	SS_Timer = SetTimer("SS_End", 120000, 0);
	SS_Zapisanych = 0;

	mysql_query("SELECT `x`,`y`,`z`,`cpx`,`cpy`,`cpz` FROM `ss_areny` ORDER BY RAND() LIMIT 1");
	mysql_store_result();
	new param[200];
	mysql_fetch_row(param, "|");
	sscanf(param, "p<|>ffffff", PozycjeSS[0],PozycjeSS[1],PozycjeSS[2],PozycjeSS[3],PozycjeSS[4],PozycjeSS[5]);
	mysql_free_result();

	SS_CP = CreateDynamicCP(PozycjeSS[3],PozycjeSS[4],PozycjeSS[5], 5.0, 22, -1, -1, 5000.0);

	pLoop(i)
	{
	    if(pInFun[i] == 1 || IsPlayerAFK(i) == 1) SetPVarInt(i, "pZapisanySS", 0);

	    if(IsPlayerConnected(i) == 1 && GetPVarInt(i, "pZapisanySS") == 1 && pInFun[i] == 0)
	    {
			new Float:flo[3];
			GetPlayerPos(i, flo[0],flo[1],flo[2]);
			SetPVarFloat(i, "floX", flo[0]);
			SetPVarFloat(i, "floY", flo[1]);
			SetPVarFloat(i, "floZ", flo[2]);
			SetPVarInt(i, "floInt", GetPlayerInterior(i));
			SetPVarInt(i, "floVW", GetPlayerVirtualWorld(i));

	        ResetPlayerWeapons(i);
	        SetPlayerVirtualWorld(i, 22);
	        SetPlayerInterior(i, 0);
	        SetPlayerDrunkLevel(i, 0);
			pInFun[i] = 1;
			SS_ClearFun(i);
			TogglePlayerControllable(i, 1);
		    SetPlayerPos(i, PozycjeSS[0] + random(2) - random(2),PozycjeSS[1] + random(2) - random(2), PozycjeSS[2]);

            TogglePlayerDynamicCP(i, SS_CP, 1);
			GivePlayerWeapon(i, 46, 1);
			SS_Zapisanych++;
		}
	}
	if(SS_Zapisanych <= 1)
	{
	    KillTimer(SS_Timer);
	    SS_End();
	    return 1;
	}
	UpdateFunStat("SS", SS_Zapisanych);
	UpdateFunTextDraw();
	return 1;
}
forward SS_End();
public SS_End()
{
	SS_Trwa = 0;
	SS_Timer = -1;
	SS_Zapisanych = 0;
	SS_Odliczanie = -1;

	DestroyDynamicCP(SS_CP);

	pLoop(i)
	{
		if(IsPlayerConnected(i) == 1 && GetPVarInt(i, "pZapisanySS") == 1 && pInFun[i] == 1)
		{
			SetPVarInt(i, "pZapisanySS", 0);
			pInFun[i] = 0;
			Odstaw(i);
			DisablePlayerCheckpoint(i);
			SCM(i, -1, "*{00AAFF}Nikt nie wygra³ Skokow! Czas min¹³!");
		}
	}

	UpdateFunTextDraw();
	return 1;
}