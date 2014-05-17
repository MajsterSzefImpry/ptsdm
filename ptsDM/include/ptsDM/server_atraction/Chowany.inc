/*
	@Polski TOP Serwer - Chowany.inc
	@Last update: 14 marca 2014 23:25

*/
CMD:ch(playerid, params[]) return cmd_chowany(playerid, params);
CMD:chowany(playerid, params[])
{
	if(CH_Trwa == 1)
	    return SCM(playerid, -1, ""C_B"Chowany "C_O"juz wystartowa³!");

	if(CH_Off == 1)
		return SCM(playerid, -1, ""C_O"Ta zabawa jest tymczasowo wy³¹czona.");


	if(GetPVarInt(playerid, "pZapisanyCH") == 1)
	{
		SetPVarInt(playerid, "pZapisanyCH", 0);
		SCM(playerid, 0x00AAFFFF,""C_O"Wypisa³eœ siê z "C_B"Chowanego");
		CH_Zapisanych--;
	}else{
		SetPVarInt(playerid, "pZapisanyCH", 1);
		CH_Zapisanych++;
		SCM(playerid, 0xDD0000FF,""C_O"Zapisa³eœ siê na "C_B"Chowanego");
	}
	UpdateFunTextDraw();

	if(CH_Odliczanie == -1 && CH_Zapisanych >= 4)
	{
		SCMToAll(-1, ""C_O"Chowany "C_O"wystartuje za "C_B"20 "C_O"sekund. Mo¿na jeszcze siê zapisywaæ!");
		CH_Odliczanie = SetTimer("CH_Start", 20000, 0);
        if(EventTimer != 0) KillTimer(EventTimer);
        TextDrawHideForAll(Event);
        TextDrawSetString(Event, " ");
        TextDrawShowForAll(Event);
   	    EventTimer = SetTimerEx("TD_Startuje_Event", 10, 0, "dd", 20, 1);
	}
	return 1;
}

CH_ClearFun(i)
{
	SetPVarInt(i, "pZapisanyHAY", 0);
	SetPVarInt(i, "pZapisanySS", 0);
	SetPVarInt(i, "pZapisanyWG", 0);
	SetPVarInt(i, "pZapisanyDD", 0);
	SetPVarInt(i, "pZapisanyTW", 0);
	return 1;
}
new Iterator:CH_Array<MAX_PLAYERS>;

forward CH_Start();
public CH_Start()
{
	CH_Trwa = 1;
	CH_Timer = SetTimer("CH_End", 120000, 0);
	mysql_query("SELECT `x`,`y`,`z`,`sx`,`sy`,`sz`,`int` FROM `ch_areny` ORDER BY RAND() LIMIT 1");
	mysql_store_result();
	new param[200];
	mysql_fetch_row(param, "|");
	sscanf(param, "p<|>ffffffi", PozycjeCH[0],PozycjeCH[1],PozycjeCH[2],PozycjeCH[3],PozycjeCH[4],PozycjeCH[5], IntCH);
	mysql_free_result();
	CH_Odliczanie = -1;
	CH_Zapisanych = 0;

	Iter_Clear(CH_Array);

	foreach (Player, i)
	{
		if(IsPlayerAFK(i) == 0 && pInFun[i] == 0 && GetPVarInt(i, "pZapisanyCH") == 1)
	    {
	        Iter_Add(CH_Array, i);
		}
	}
	CH_Szukajacy = Iter_Random(CH_Array);

	pLoop(i)
	{
	    if(pInFun[i] == 1 || IsPlayerAFK(i) == 1) SetPVarInt(i, "pZapisanyCH", 0);

	    if(IsPlayerConnected(i) == 1 && GetPVarInt(i, "pZapisanyCH") == 1)
	    {
			new Float:flo[3];
			GetPlayerPos(i, flo[0],flo[1],flo[2]);
			SetPVarFloat(i, "floX", flo[0]);
			SetPVarFloat(i, "floY", flo[1]);
			SetPVarFloat(i, "floZ", flo[2]);
			SetPVarInt(i, "floInt", GetPlayerInterior(i));
			SetPVarInt(i, "floVW", GetPlayerVirtualWorld(i));

			SetPlayerArmedWeapon(i, 0);
	        ResetPlayerWeapons(i);
	        TogglePlayerControllable(i, 1);
	        SetPlayerVirtualWorld(i, 21);
	        CH_ClearFun(i);
	        SetPlayerTeam(i, NO_TEAM);
	        pInFun[i] = 1;
			SetPlayerInterior(i, IntCH);
 			if(CH_Szukajacy == i)
			{
			    SetPlayerColor(i, 0x00000000);
			    SetPlayerArmour(i, 100.0);
			    SetPlayerPos(i, PozycjeCH[3],PozycjeCH[4],PozycjeCH[5]);
				GivePlayerWeapon(i, 38, 999999);
				SetPlayerHealth(i, 10000.0);
				TogglePlayerControllable(i, 1);
				SCM(i, -1, "{FF00FF}Za 10 sekund mo¿esz zacz¹æ szukaæ!");
				SetTimerEx("ControlOn", 10000, 0, "d", i);
			}else{
			    SetPlayerPos(i, PozycjeCH[0],PozycjeCH[1],PozycjeCH[2]);
				SetPlayerColor(i, 0x77777700);
				SetPlayerArmour(i, 0.0);
				SetPlayerHealth(i, 100.0);
			}
			CH_Zapisanych++;
		}
	}


	if(CH_Zapisanych < 2)
	{
	    KillTimer(CH_Timer);
	    CH_End();
		return 1;
	}
	UpdateFunStat("CH", CH_Zapisanych);
	UpdateFunTextDraw();
	return 1;
}

forward CH_End();
public CH_End()
{
	CH_Trwa = 0;
	CH_Timer = -1;
	CH_Odliczanie = -1;

	pLoop(i)
	{
		if(IsPlayerConnected(i) == 1 && GetPVarInt(i, "pZapisanyCH") == 1)
		{
			SetPVarInt(i, "pZapisanyCH", 0);
			pInFun[i] = 0;
			ResetPlayerWeapons(i);
			Odstaw(i);
			SetPlayerVirtualWorld(i, 0);
			SetPlayerInterior(i, 0);
			GivePlayerScore(i, 20);
			GivePlayerMoney(i, 10000);
			if(CH_Szukajacy != i)
			{
				SCM(i, 0xDD0000FF, ""C_O"Prze¿y³eœ na "C_B"chowanym! Dostajesz "C_B"20 exp + 10000$");
				format(strx, sizeof strx, "UPDATE `players` SET `won_ch` = `won_ch` + 1 WHERE `nick` = '%s'", pName[i]);
		        mysql_query(strx);  
			}
			SetPlayerInterior(i, 0);
		}
	}
	if(CH_Zapisanych <= 1)
	{
	    GivePlayerScore(CH_Szukajacy, 25);
	    GivePlayerMoney(CH_Szukajacy, 10000);
	    SCM(CH_Szukajacy, 0xDD0000FF, ""C_O"Zabi³eœ wszystkich na "C_B"chowanym! Dostajesz"C_B"25 exp + 10000$");
		format(strx, sizeof strx, "UPDATE `players` SET `won_ch` = `won_ch` + 1 WHERE `nick` = '%s'", pName[CH_Szukajacy]);
		mysql_query(strx);
	}
	CH_Zapisanych = 0;
	CH_Szukajacy = -1;
	UpdateFunTextDraw();
	return 1;
}
