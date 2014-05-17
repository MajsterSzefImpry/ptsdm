/*
	@Polski TOP Serwer - Wojna_Gangow.inc
	@Last update: 14 marca 2014 23:25

*/
CMD:wg(playerid, params[])
{
	if(WG_Trwa == 1)
	    return SCM(playerid, -1, ""C_B"WG "C_O"Juz wystartowa³o!");

	if(WG_Off == 1)
		return SCM(playerid, -1, ""C_O"Ta zabawa jest tymczasowo wy³¹czona.");

	if(GetPVarInt(playerid, "pZapisanyWG") == 1)
	{
		SetPVarInt(playerid, "pZapisanyWG", 0);
		SCM(playerid, 0x00AAFFFF,""C_O"Wypisa³eœ siê z "C_B"WG");
		WG_Zapisanych--;
	}else{
		SetPVarInt(playerid, "pZapisanyWG", 1);
		WG_Zapisanych++;
		SCM(playerid, 0xDD0000FF,""C_O"Zapisa³eœ siê na "C_B"WG");
	}
	UpdateFunTextDraw();

	if(WG_Odliczanie == -1 && WG_Zapisanych >= 4)
	{
		SCMToAll(-1, ""C_B"WG "C_O"wystartuje za "C_B"20 "C_O"sekund. Mo¿na jeszcze siê zapisywaæ!");
		WG_Odliczanie = SetTimer("WG_Start", 20000, 0);
        if(EventTimer != 0) KillTimer(EventTimer);
        TextDrawHideForAll(Event);
        TextDrawSetString(Event, " ");
        TextDrawShowForAll(Event);
   	    EventTimer = SetTimerEx("TD_Startuje_Event", 10, 0, "dd", 20, 6);
	}
	return 1;
}

WG_ClearFun(i)
{
	SetPVarInt(i, "pZapisanyHAY", 0);
	SetPVarInt(i, "pZapisanyCH", 0);
	SetPVarInt(i, "pZapisanySS", 0);
	SetPVarInt(i, "pZapisanyDD", 0);
	SetPVarInt(i, "pZapisanyTW", 0);

	return 1;
}

forward WG_Start();
public WG_Start()
{
	WG_Timer = SetTimer("WG_End", 240000, 0);
	mysql_query("SELECT `bx`,`by`,`bz`,`rx`,`ry`,`rz`,`int` FROM `wg_areny` ORDER BY RAND() LIMIT 1");
	mysql_store_result();
	new param[200];
	mysql_fetch_row(param, "|");
	sscanf(param, "p<|>ffffffi", PozycjeWG[0],PozycjeWG[1],PozycjeWG[2],PozycjeWG[3],PozycjeWG[4],PozycjeWG[5], IntWG);
	mysql_free_result();
	WG_Zapisanych = 0;
	WG_Odliczanie = -1;
	WG_Team[0] = 0;
	WG_Team[1] = 0;

	WG_Dystans[1] = (PozycjeWG[0] + PozycjeWG[3]) / 2;
	WG_Dystans[2] = (PozycjeWG[1] + PozycjeWG[4]) / 2;
	WG_Dystans[0] = PointToPoint(WG_Dystans[1],WG_Dystans[2], PozycjeWG[0],PozycjeWG[1]) + 25;

	new team;
	pLoop(i)
	{
		if(pInFun[i] == 1 || IsPlayerAFK(i) == 1)
		{
			SetPVarInt(i, "pZapisanyWG", 0);
			continue;
		}
		if(IsPlayerConnected(i) == 1 && GetPVarInt(i, "pZapisanyWG") == 1 && pInFun[i] == 0)
		{
		    WG_ClearFun(i);

			new Float:flo[3];
			GetPlayerPos(i, flo[0],flo[1],flo[2]);
			SetPVarFloat(i, "floX", flo[0]);
			SetPVarFloat(i, "floY", flo[1]);
			SetPVarFloat(i, "floZ", flo[2]);
			SetPVarInt(i, "floInt", GetPlayerInterior(i));
			SetPVarInt(i, "floVW", GetPlayerVirtualWorld(i));

			if(team == 0)
			{
				SetPlayerPos(i, PozycjeWG[0],PozycjeWG[1],PozycjeWG[2]);
				SetPlayerTeam(i, 10);
				SetPlayerColor(i, 0xDD0000FF);
				WG_Team[team]++;
				team = 1;
			}else{
			    SetPlayerPos(i, PozycjeWG[3],PozycjeWG[4],PozycjeWG[5]);
				SetPlayerTeam(i, 11);
				SetPlayerColor(i, 0x0000DDFF);
				WG_Team[team]++;
				team = 0;
			}
			SetPlayerInterior(i, IntWG);
            SetPlayerHealth(i, 100.0);
            SetPlayerArmour(i, 100.0);
			TogglePlayerControllable(i, true);
			ResetPlayerWeapons(i);
			SetPlayerVirtualWorld(i, 20);
			pInFun[i] = 1;
			GivePlayerWeapon(i, 16, 1);
			GivePlayerWeapon(i, 24, 200);
			GivePlayerWeapon(i, 27, 200);
			GivePlayerWeapon(i, 29, 200);
			GivePlayerWeapon(i, 31, 200);
			GivePlayerWeapon(i, 34, 200);
			WG_Zapisanych++;

		}else SetPVarInt(i, "pZapisanyWG", 0);

	}
    WG_Trwa = 1;
	if(WG_Zapisanych < 2)
	{
	    KillTimer(WG_Timer);
	    WG_End();
		return 1;
	}

	UpdateFunStat("WG", WG_Zapisanych);

	UpdateFunTextDraw();
	return 1;
}
forward WG_End();
public WG_End()
{
	if(WG_Zapisanych >= 3)
	{
		if(WG_Team[0] < WG_Team[1])
		{
			pLoop(i)
			{
				if(IsPlayerConnected(i) == 1 && GetPlayerTeam(i) == 11)
				{
					SCM(i, 0xDD0000FF, ""C_O"Twoja dru¿yna wygra³a "C_B"WG! Otrzymujesz "C_B"15exp + 10.000$");
					GivePlayerScore(i, 15);
					GivePlayerMoney(i, 10000);
					format(strx, sizeof strx, "UPDATE `players` SET `won_wg` = `won_wg` + 1 WHERE `nick` = '%s'", pName[i]);
		            mysql_query(strx);
				}
			}
		}else
		{
			pLoop(i)
			{
				if(IsPlayerConnected(i) == 1 && GetPlayerTeam(i) == 10)
				{
					SCM(i, 0xDD0000FF, ""C_O"Twoja dru¿yna wygra³a "C_B"WG! Otrzymujesz "C_B"15exp + 10.000$");
					GivePlayerScore(i, 15);
					GivePlayerMoney(i, 10000);
					format(strx, sizeof strx, "UPDATE `players` SET `won_wg` = `won_wg` + 1 WHERE `nick` = '%s'", pName[i]);
		            mysql_query(strx);
				}
			}
		}
	}

	pLoop(i)
	{
		if(GetPVarInt(i, "pZapisanyWG") == 1 && pInFun[i] == 1)
		{
			SetPVarInt(i, "pZapisanyWG", 0);
			ResetPlayerWeapons(i);
			Odstaw(i);
			pInFun[i] = 0;
		}
	}


	WG_Trwa = 0;
	WG_Zapisanych = 0;
	WG_Team[0] = 0;
	WG_Team[1] = 0;
	WG_Timer = -1;
	WG_Odliczanie = -1;

	UpdateFunTextDraw();
	return 1;
}