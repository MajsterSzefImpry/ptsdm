/*
	@Polski TOP Serwer - admin.inc
	@Last update: 14 marca 2014 23:25

*/
CMD:acmd(playerid, params[])
{
	if(Administrator[playerid] < 1)
	    return 0;

	format(bstrx, sizeof(bstrx), ""C_B"Komendy administratorów:\n\n"C_O"");
	strcat(bstrx, "/lastraports - Ostatnie 5 raportów\n");
	strcat(bstrx, "/spec - Podgl¹dasz gracza\n");
	strcat(bstrx, "/givemoney - Dajesz kase\n");
	strcat(bstrx, "/giveexp - Dajesz exp\n");
    strcat(bstrx, "/startvote - g³osowanie\n");
	strcat(bstrx, "/freeze - Zamra¿asz gracza\n");
	strcat(bstrx, "/warn - dajesz ostrzeæenie\n");
	strcat(bstrx, "/acolor - kolor admina\n");
	strcat(bstrx, "/invisible - znikasz z radaru\n");
	strcat(bstrx, "/unfreeze - Odmra¿asz gracza\n");
	strcat(bstrx, "/ann - Piszesz na œrodku ekranu\n");
	strcat(bstrx, "/tpto - Teleport do ...\n");
	strcat(bstrx, "/tp - Teleport A do B\n");
	strcat(bstrx, "/getweapon - Sprawdzasz bronie gracza\n");
	strcat(bstrx, "/ban - Dajesz bana graczowi\n");
	strcat(bstrx, "/kick - Wyrzucasz gracza z serwera\n");
	strcat(bstrx, "/say - Piszesz jako admin w chacie\n");
	strcat(bstrx, "/givejetpack - Dajesz jetpack\n");
	strcat(bstrx, "/givegun - Dajesz broñ\n");
	strcat(bstrx, "/vgod - Niezniszczalny pojazd\n");
	strcat(bstrx, "/god - Nieœmiertelnoœæ\n");
	strcat(bstrx, "/setarmor - Ustawiasz pancerz\n");
	strcat(bstrx, "/sethp - Ustawiasz ¿ycie\n");
	strcat(bstrx, "/objective - Oznaczenie pojazdu\n");
	strcat(bstrx, "/rozbroj - Pozbywasz gracza broni\n");
	strcat(bstrx, "/settime - Ustawiasz godzinê\n");
	strcat(bstrx, "/pogoda - Ustawiasz pogodê\n");
	strcat(bstrx, "/getip - Sprawdzasz IP gracza\n");
	strcat(bstrx, "/walizka - Stawiasz walizkê\n");
	strcat(bstrx, "/clear - Czyœcisz chat\n");
	strcat(bstrx, "/mute - Wyciszasz gracza (chat)\n");
	strcat(bstrx, "/maxping - Ustawiasz maxping\n");
	strcat(bstrx, "/explode - Wybuch\n");
	strcat(bstrx, "/respawn - Respawn pojazdów\n");
	strcat(bstrx, "/eye - Podgl¹d komend\n");
	strcat(bstrx, "/pmeye - Podgl¹d PW\n");
	strcat(bstrx, "/unban - Odbanowujesz nick\n");
	strcat(bstrx, "/addban - Dajesz bana graczowi offline\n");
	strcat(bstrx, "/zpos - Zmiana wysokoœci gracza\n");
	strcat(bstrx, "/darea - Rozbrajasz wszystkich w pobli¿u ciebie\n");
	strcat(bstrx, "/setcolor - Zmieniasz kolor\n");
	strcat(bstrx, "/jail - wrzucasz \n");
    strcat(bstrx, "/unjail - wypuszczasz z wiezienia\n");
	strcat(bstrx, "/r - piszesz wiadomoœæ na czacie\n");
	strcat(bstrx, "/startvote - rozpoczynasz g³osowanie.\n");
	InfoBox(playerid, bstrx);
	return 1;
}

CMD:startvote(playerid, params[])
{
	if(Administrator[playerid] < 1)
	   return 0;
	   
	if(mVote[vOdliczanka]) return SCM(playerid, -1, ""C_O"Nie mo¿esz rozpocz¹æ kolejnego g³osowania.");
	if(isnull(params)) return SCM(playerid, -1, ""C_O"Wpisz: /startvote [pytanie]");
	
	if(strlen(params)< 0) {
		SCM(playerid, -1, ""C_O"Musi byæ minimum "C_B"1 "C_O"znak.");
		return 1;
	}

	for(new x, l = 2; x != l; x++)
	{
	    TextDrawShowForAll(mVote[TDVote][x]);
		mVote[glos][x] = 0;
	}

	mVote[vOdliczanka] = 30;
	mVote[TimerGlosowanie] = SetTimerEx("StartVote", 1000, true, "s", params);
	return 1;
}

CMD:walizka(playerid, params[])
{
	if(Administrator[playerid] < 1)
	    return 0;

	if(GetPlayerVirtualWorld(playerid) != 0
		|| GetPlayerInterior(playerid) != 0
		|| GetPlayerDistanceFromPoint(playerid, 0.0, 0.0, 0.0 ) > 4000)
	    return SCM(playerid, -1, "Nie mo¿esz tutaj podstawiæ walizki!");

	if(walizka[2] == 1)
	    return Dialog(playerid, 43, DIALOG_BOX, "Walizka jest juz pod³o¿ona.\n{DD0000}Czy chcesz j¹ usun¹æ?", "NIE", "TAK");

	if(isnull(params))
	    return SCM(playerid, -1, "/walizka [podpowiedŸ]");

 	if(strlen(params) > 16)
	    return SCM(playerid, -1, "PodpowiedŸ musi byæ krótka! Max. 16 znaków.");

	new Float:ppos[3];
	GetPlayerPos(playerid, ppos[0], ppos[1], ppos[2]);
	new mstr[64];
	format(mstr, 64, "~g~Walizka~w~: ~r~%s", params);
	TextDrawSetString(WalizkaDraw[1], mstr);
	TextDrawShowForAll(WalizkaDraw[1]);
	TextDrawShowForAll(WalizkaDraw[0]);

	walizka[0] = playerid;
	walizka[2] = 1;
    walizka[1] = CreatePickup(1210, 2, ppos[0], ppos[1],ppos[2]+0.3, 0);
	return 1;
}

CMD:givemoney(playerid, params[])
{
	if(Administrator[playerid] < 1)
	    return 0;

	new player[4], amount;
	if(sscanf(params, "s[4]d", player, amount))
	    return SCM(playerid, -1, "/givemoney [id/all/area] [money]");

	if(amount > 200000 || amount < -200000)
	{
	    if(Administrator[playerid] < 2)
		    return SCM(playerid, -1, "{FF0000}Nie przesadzasz troszke z iloœci¹?");
	}

	if(IsNumeric(player))
	{
		if(!IsPlayerConnected(strval(player)))
	   		return SCM(playerid, -1, "{DD0000}Gracz o takim ID nie jest po³¹czony");

		format(strx, 128, "{11BB11}Admin {DDDDDD}%s{11BB11} da³ Ci{DDDDDD} %d{11BB11} kasy!", pName[playerid], amount);
		SCM(strval(player), -1, strx);
		format(strx, 128, "{11BB11}Da³eœ {DDDDDD}%d{11BB11} kasy graczowi {DDDDDD}%s{11BB11}!",  amount,pName[strval(player)]);
		SCM(playerid, -1, strx);
		GivePlayerMoney(strval(player), amount);

		if(strval(player) == playerid)
		{
			SCM(playerid, -1, "Pamiêtaj, ¿e wykorzystywanie admina we w³asnej korzyœci jest zabronione. Ta czynnoœæ zosta³a zapisana w logach.");
		}

	}else if(!strcmp(player, "all", true))
	{
	    pLoop(i)
			GivePlayerMoney(i, amount);

		format(strx, 128, "{11BB11}Admin {DDDDDD}%s{11BB11} da³ wszystkim {DDDDDD}%d{11BB11} kasy!", pName[playerid], amount);
		SCMToAll(-1, strx);

	}else if(!strcmp(player, "area", true, strlen(player)) && strlen(player) > 2)
	{
	    new Float:x,Float:y,Float:z;
	    GetPlayerPos(playerid, x,y,z);

	    format(strx, 128, "{11BB11}Admin {DDDDDD}%s{11BB11} da³ graczom w pobli¿u {DDDDDD}%d${11BB11}!", pName[playerid], amount);

	    pLoop(i)
	    {
	        if(!IsPlayerConnected(i)
				|| GetPlayerState(i) == 0
				|| GetPlayerVirtualWorld(i) != GetPlayerVirtualWorld(playerid)
				|| IsPlayerInRangeOfPoint(i, 35.0, x,y,z) == 0) continue;

			GivePlayerMoney(i, amount);
			SCM(i, -1, strx);
	    }

	}else SCM(playerid, -1, "/givemoney [id/all/area] [money]");
	return 1;
}

CMD:objective(playerid, params[])
{
	if(Administrator[playerid] < 1)
	    return 0;

	if(!IsPlayerInAnyVehicle(playerid))
	    return SCM(playerid, -1, ""C_O"Musisz byæ w pojeŸdzie!");

	new engine,lights,alarm,doors,bonnet,boot,objective;
	GetVehicleParamsEx(GetPlayerVehicleID(playerid),engine,lights,alarm,doors,bonnet,boot,objective);

	if(objective == 0) SetVehicleParamsEx(GetPlayerVehicleID(playerid),engine,lights,alarm,doors,bonnet,boot,1);
	else SetVehicleParamsEx(GetPlayerVehicleID(playerid),engine,lights,alarm,doors,bonnet,boot,0);

	return 1;
}

CMD:disarm(playerid, params[]) return cmd_rozbroj(playerid, params);
CMD:rozbroj(playerid, params[])
{
	if(Administrator[playerid] < 1)
	    return 0;

	new player;
	if(sscanf(params, "d", player))
	    return SCM(playerid, -1, "/rozbroj [ID]");

	if(!IsPlayerConnected(player))
	    return SCM(playerid, -1, "Ten gracz nie jest po³¹czony!");

	ResetPlayerWeapons(player);
	format(strx, 128, "{11BB11}Admin {DDDDDD}%s{11BB11} rozbroi³ Ciê!", pName[playerid]);
	SCM(player, -1, strx);
	format(strx, 128, "{11BB11}Rozbroi³eœ {DDDDDD}%s{11BB11}!",  pName[player]);
	SCM(playerid, -1, strx);
	return 1;
}

CMD:unfreeze(playerid, params[])
{
	if(Administrator[playerid] < 1)
	    return 0;

	if(isnull(params) || !IsNumeric(params) || strval(params) < 0 || strval(params) >= MAX_PLAYERS)
	    return SCM(playerid, -1, "/unfreeze [ID]");

	new i = strval(params);

	if(!IsPlayerConnected(i))
	    return SCM(playerid, -1, "Ten gracz nie jest po³¹czony!");

	TogglePlayerControllable(i, 1);
	format(strx, sizeof strx, "{11BB11}Admin {DDDDDD}%s{11BB11} odmrozi³ Ciê!", pName[playerid]);
	SCM(i, -1, strx);
	format(strx, sizeof strx, "{11BB11}Odmrozi³eœ {DDDDDD}%s", pName[i]);
	SCM(playerid, -1, strx);
	return 1;
}
CMD:freeze(playerid, params[])
{
	if(Administrator[playerid] < 1)
	    return 0;

	if(isnull(params) || !IsNumeric(params) || strval(params) < 0 || strval(params) >= MAX_PLAYERS)
	    return SCM(playerid, -1, "/freeze [ID]");

	new i = strval(params);

	if(!IsPlayerConnected(i))
	    return SCM(playerid, -1, "Ten gracz nie jest po³¹czony!");

	TogglePlayerControllable(i, 0);
	format(strx, sizeof strx, "{11BB11}Admin {DDDDDD}%s{11BB11} zamrozi³ Ciê!", pName[playerid]);
	SCM(i, -1, strx);
	format(strx, sizeof strx, "{11BB11}Zamrozi³eœ {DDDDDD}%s", pName[i]);
	SCM(playerid, -1, strx);
	return 1;
}
CMD:settime(playerid, params[])
{
	if(Administrator[playerid] < 1)
	    return 0;

	if(isnull(params) || !IsNumeric(params) || strval(params) < 0 || strval(params) > 50)
	    return SCM(playerid, -1, "/settime [hour]");

 	SetWorldTime(strval(params));
 	format(strx, sizeof strx, "{DD0000}Admin {DDDDDD}%s{DD0000} zmieni³ godzinê na {DDDDDD}%d", pName[playerid], strval(params));
	SCMToAll(-1, strx);
	return 1;
}
CMD:pogoda(playerid, params[])
{
	if(Administrator[playerid] < 1)
	    return 0;

	if(isnull(params) || !IsNumeric(params) || strval(params) < 0 || strval(params) > 50)
	    return SCM(playerid, -1, "/pogoda [ID]");

 	SetWeather(strval(params));
 	format(strx, sizeof strx, "{DD0000}Admin {DDDDDD}%s{DD0000} zmieni³ pogodê na {DDDDDD}%d", pName[playerid], strval(params));
	SCMToAll(-1, strx);
	return 1;
}
CMD:getip(playerid, params[])
{
	if(Administrator[playerid] < 1)
	    return 0;

	if(isnull(params) || !IsNumeric(params))
	    return SCM(playerid, -1, "/getip [id]");

	if(!IsPlayerConnected(strval(params)))
	    return SCM(playerid, -1, "Ten gracz nie jest po³¹czony");

	new ip[20];
	GetPlayerIp(strval(params), ip, 20);
	format(strx, sizeof strx, "{FEFEFE}%s"C_O" - %s", pName[strval(params)], ip);
	InfoBox(playerid, strx);
	return 1;
}

CMD:query(playerid, params[])
{
	if(Administrator[playerid] < 4)
		return 0;

	if(isnull(params))
	    return SCM(playerid, -1, "/query [zapytanie]");

	mysql_query(params);
	SCM(playerid, -1, params);
	return 1;
}

CMD:teleto(playerid, params[])
{
	if(Administrator[playerid] < 4)
	    return 0;

	new Float:x,Float:y,Float:z;
	if(sscanf(params, "fff", x,y,z))
	    return SCM(playerid, -1, "/teleto X Y Z");

	SetPlayerPos(playerid, x,y,z);
	return 1;
}

CMD:tpto(playerid, params[]) return cmd_goto(playerid, params);
CMD:goto(playerid, params[])
{
    if(Administrator[playerid] < 1)
        return 0;

	new player2, Float:xyz[3];
    if(sscanf(params, "d", player2))
        return SCM(playerid, -1, "/goto [gracz]");

    if(!IsPlayerConnected(player2))
        return SCM(playerid, 0xFF0000FF, "Gracz nie jest po³¹czony!");

	if(GetPlayerVirtualWorld(playerid) != GetPlayerVirtualWorld(player2))
        return SCM(playerid, 0xFF0000FF, "Nie mo¿esz teleportowaæ siê do gracza o innym VirtualWorld.");

	if(GetPlayerInterior(playerid) != GetPlayerInterior(player2))
        return SCM(playerid, 0xFF0000FF, "Nie mo¿esz teleportowaæ siê do gracza, który jest w budynku.");

    GetPlayerPos(player2, xyz[0], xyz[1], xyz[2]);
    if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
    {
        SetVehiclePos(GetPlayerVehicleID(playerid), xyz[0] + 2.5, xyz[1], xyz[2] + 2.0);
	}else SetPlayerPos(playerid, xyz[0] + 1.0, xyz[1], xyz[2]);

	format(strx, sizeof strx, "Administrator %s teleportowa³ siê do ciebie", pName[playerid]);
	SCM(player2, 0x00DD00FF, strx);
	return 1;
}
CMD:tp(playerid, params[])
{
    if(Administrator[playerid] < 1)
        return 0;

	new player, player2, Float:xyz[3];
    if(sscanf(params, "dd", player, player2))
        return SCM(playerid, -1, "/tp [gracz] {C9C9C9}(do)"C_O" [gracza]");

    if(!IsPlayerConnected(player) || !IsPlayerConnected(player2))
        return SCM(playerid, 0xFF0000FF, "Jeden z graczy nie jest po³¹czony!");

	if(GetPlayerVirtualWorld(player) != 0 || GetPlayerVirtualWorld(player2) != 0)
        return SCM(playerid, 0xFF0000FF, "Nie mo¿na teraz teleportowaæ jednego z graczy.");

	if(GetPlayerInterior(player) != 0 || GetPlayerInterior(player2) != 0)
        return SCM(playerid, 0xFF0000FF, "Nie mo¿na teraz teleportowaæ jednego z graczy.");

    GetPlayerPos(player2, xyz[0], xyz[1], xyz[2]);
    if(GetPlayerState(player) == PLAYER_STATE_DRIVER)
    {
        SetVehiclePos(GetPlayerVehicleID(player), xyz[0] + 2.5, xyz[1], xyz[2] + 2.0);
	}else SetPlayerPos(player, xyz[0] + 1.0, xyz[1], xyz[2]);

	format(strx, sizeof strx, "Administrator: %s teleportowa³ do ciebie: %s", pName[playerid], pName[player]);
	SCM(player2, 0x00DD00FF, strx);
	format(strx, sizeof strx, "Administrator: %s teleportowa³ ciebie do: %s", pName[playerid], pName[player2]);
	SCM(player, 0x00DD00FF, strx);
	return 1;
}
CMD:newtele(playerid, params[])
{
	if(Administrator[playerid] < 4)
		return 0;

	new Float:pos[3];
	GetPlayerPos(playerid, pos[0], pos[1], pos[2]);

    format(strx, sizeof strx, "INSERT INTO `spawn` (`interior`, `world`, `X`, `Y`, `Z`) VALUES ('%d', '%d', '%.2f', '%.2f', '%.2f');",
     GetPlayerInterior(playerid),GetPlayerVirtualWorld(playerid),pos[0],pos[1],pos[2]);

    mysql_query(strx);

	SCM(playerid, 0xD7C214FF, "Pozycja zapisana");
	return 1;
}
CMD:getweapon(playerid, params[])
{
	if(Administrator[playerid] < 1)
	    return 0;

	if(isnull(params) || !IsNumeric(params) || strval(params) < 0 || strval(params) >= MAX_PLAYERS)
	    return SCM(playerid, -1, "/getweapon [ID]");

	new i = strval(params);
	if(!IsPlayerConnected(i))
	    return SCM(playerid, -1, "Ten gracz nie jest po³¹czony!");

	format(bstrx, sizeof bstrx, "Bronie gracza %s:\n\n", pName[i]);
	new weapons[2];
	new wname[30];
	for (new x = 2; x < 13; x++)
	{
	    GetPlayerWeaponData(i, x, weapons[0], weapons[1]);
	    GetWeaponName(weapons[0], wname, 30);

		if(!strlen(wname)) continue;

	    format(bstrx, sizeof bstrx, "%sBroñ: %s Ammo: %d\n", bstrx, wname, weapons[1]);
	}
	InfoBox(playerid, bstrx);
	return 1;
}
CMD:ban(playerid, params[])
{
	if(Administrator[playerid] < 2)
	    return 0;

	new player, reason[80];
	if(sscanf(params, "us[80]", player, reason))
	    return SCM(playerid, -1, "/ban [gracz] [powód]");

	if(!IsPlayerConnected(player))
	{
		SCM(playerid,-1,"Ten gracz nie jest po³¹czony!");
		return 1;
	}

	BanPlayer(player, pName[playerid], reason);
	return 1;
}

CMD:kick(playerid, params[])
{
	if(Administrator[playerid] < 1)
	    return 0;

	new player, reason[128];
	if(sscanf(params, "us[128]", player, reason))
	    return SCM(playerid, -1, "/kick [gracz] [powód]");


	if(!IsPlayerConnected(player))
	{
		SCM(playerid,-1,"Ten gracz nie jest po³¹czony!");
		return 1;
	}

	KickPlayer(player, pName[playerid], reason);
	return 1;
}

CMD:r(playerid, params[])
{
	if(Administrator[playerid] < 1)
	    return 0;

	if(isnull(params))
	    return SCM(playerid, -1, "/r [tekst]");

	format(strx, sizeof strx, "{A40000}%s" , params);
	SCMToAll(-1, strx);
	return 1;
}

CMD:say(playerid, params[])
{
	if(Administrator[playerid] < 1)
	    return 0;

	if(isnull(params))
	    return SCM(playerid, -1, "/say [tekst]");

	format(strx, sizeof strx, "{FFDD00}* Admin %s:{FFFF00} %s", pName[playerid], params);
	SCMToAll(-1, strx);
	return 1;
}
CMD:givejetpack(playerid, params[])
{
	if(Administrator[playerid] < 1)
	    return 0;

	new player;
	if(sscanf(params, "d", player))
	    return SCM(playerid, -1, "/givejetpack [gracz]");

   	if(!IsPlayerConnected(player))
		return SCM(playerid, -1, "{DD0000}Gracz o takim ID nie jest po³¹czony");

	SetPlayerSpecialAction(player, SPECIAL_ACTION_USEJETPACK);
	format(strx, 128, "{11BB11}Admin {DDDDDD}%s{11BB11} da³ Ci {DDDDDD}Jetpacka{11BB11}!", pName[playerid]);
	SCM(player, -1, strx);
	format(strx, 128, "{11BB11}Da³eœ {DDDDDD}Jetpacka{11BB11} graczowi {DDDDDD}%s{11BB11}!",  pName[player]);
	SCM(playerid, -1, strx);
	return 1;
}
CMD:givegun(playerid, params[])
{
	if(Administrator[playerid] < 1)
	    return 0;

	new player[5], weapon, ammo;
	if(sscanf(params, "s[4]dd", player, weapon, ammo))
	    return SCM(playerid, -1, "/givegun [id/area] [weaponid] [ammo]");

	if(weapon > 46 || weapon < 0 || weapon == 45 || weapon == 44)
		return SCM(playerid, -1, "Nieprawidlowe ID broni");

	if(ammo < 0 || ammo > 10000)
	    return SCM(playerid, -1, "Nieprawidlowa iloœæ ammunicji");


	if(IsNumeric(player))
	{
		if(!IsPlayerConnected(strval(player)))
	   		return SCM(playerid, -1, "{DD0000}Gracz o takim ID nie jest po³¹czony");

		new name[52];
		GetWeaponName(weapon, name, 52);
		format(strx, 128, "{11BB11}Admin {DDDDDD}%s{11BB11} da³ Ci {DDDDDD}%s (ammo: %d){11BB11}!", pName[playerid], name, ammo);
		SCM(strval(player), -1, strx);
		format(strx, 128, "{11BB11}Da³eœ {DDDDDD}%s (ammo: %d){11BB11} graczowi {DDDDDD}%s{11BB11}!",  name, ammo, pName[strval(player)]);
		SCM(playerid, -1, strx);
		GivePlayerWeapon(strval(player), weapon, ammo);

	}else if(!strcmp(player, "area", true, strlen(player)) && strlen(player) > 2)
	{
	    new Float:x,Float:y,Float:z;
	    GetPlayerPos(playerid, x,y,z);

	    new name[52];
		GetWeaponName(weapon, name, 52);

	    format(strx, 128, "{11BB11}Admin {DDDDDD}%s{11BB11} da³ graczom w pobli¿u {DDDDDD}%s (ammo: %d){11BB11}!", pName[playerid], name, ammo);

		pLoop(i)
	    {
	        if(GetPlayerState(i) == 0
				|| GetPlayerVirtualWorld(i) != GetPlayerVirtualWorld(playerid)
				|| IsPlayerInRangeOfPoint(i, 35.0, x,y,z) == 0) continue;

			GivePlayerWeapon(i, weapon, ammo);
			SCM(i, -1, strx);
	    }

	}
	return 1;
}
CMD:vgod(playerid, params[])
{
	if(Administrator[playerid] < 1)
	    return 0;

	new player;
	if(sscanf(params, "d", player))
	    return SCM(playerid, -1, "/vgod [id]");

	if(!IsPlayerConnected(player))
		return SCM(playerid, -1, "{DD0000}Gracz o takim ID nie jest po³¹czony");

	if(!IsPlayerInAnyVehicle(player))
	    return SCM(playerid, -1, "{DD0000}Gracz o takim ID nie jest w "C_O"pojeŸdzie");

	format(strx, 128, "{11BB11}Admin {DDDDDD}%s{11BB11} da³ Ci {DDDDDD}vehgoda{11BB11}!", pName[playerid]);
	SCM(player, -1, strx);
	format(strx, 128, "{11BB11}Da³eœ {DDDDDD}vehgoda{11BB11} graczowi {DDDDDD}%s{11BB11}!",  pName[player]);
	SCM(playerid, -1, strx);
    SetVehicleHealth(GetPlayerVehicleID(player), 999999.0);
	return 1;
}
CMD:god(playerid, params[])
{
	if(Administrator[playerid] < 1)
	    return 0;

	new player;
	if(sscanf(params, "d", player))
	    return SCM(playerid, -1, "/god [id]");

	if(!IsPlayerConnected(player))
	    return SCM(playerid, -1, "{DD0000}Gracz o takim ID nie jest po³¹czony");

	if(GetPVarInt(player, "adminGOD") == 0)
	{
		format(strx, 128, "{11BB11}Admin {DDDDDD}%s{11BB11} da³ Ci {DDDDDD}goda{11BB11}!", pName[playerid]);
		SCM(player, -1, strx);
		format(strx, 128, "{11BB11}Da³eœ {DDDDDD}goda{11BB11} graczowi {DDDDDD}%s{11BB11}!",  pName[player]);
		SCM(playerid, -1, strx);
	    SetPlayerHealth(player, 9999999.0);
	   	format(strx, sizeof strx, "[GOD]Admin %s nadal goda graczowi %s.", pName[playerid], player);
		WriteLog(strx);
	}
	return 1;
}
CMD:setarmor(playerid, params[])
{
	if(Administrator[playerid] < 1)
	    return 0;

	new player[4], Float:amount;
	if(sscanf(params, "s[4]f", player, amount))
	    return SCM(playerid, -1, "/setarmor [id/all] [armor]");

	if(amount > 100 || amount < 0)
	    return SCM(playerid, -1, "{FF0000}Nie przesadzasz troszkê z iloœci¹?");

	if(IsNumeric(player))
	{
		if(!IsPlayerConnected(strval(player)))
		    return SCM(playerid, -1, "{DD0000}Gracz o takim ID nie jest po³¹czony");

		format(strx, 128, "{11BB11}Admin {DDDDDD}%s{11BB11} ustawi³ Ci{DDDDDD} %.1f{11BB11} pancerza!", pName[playerid], amount);
		SCM(strval(player), -1, strx);
		format(strx, 128, "{11BB11}Ustawi³eœ {DDDDDD}%f{11BB11} pancerza graczowi {DDDDDD}%s{11BB11}!",  amount,pName[strval(player)]);
		SCM(playerid, -1, strx);
		SetPlayerArmour(strval(player), amount);

	}else if(!strcmp(player, "all", true) )
	{
 		pLoop(i)
			SetPlayerArmour(i, amount);

		format(strx, 128, "{11BB11}Admin {DDDDDD}%s{11BB11} ustawi³ wszystkim {DDDDDD}%.1f{11BB11} pancerza!", pName[playerid], amount);
		SCMToAll(-1, strx);

	}else if(!strcmp(player, "area", true, strlen(player)) && strlen(player) >= 2)
	{
	    new Float:x,Float:y,Float:z;
	    GetPlayerPos(playerid, x,y,z);

	    format(strx, 128, "{11BB11}Admin {DDDDDD}%s{11BB11} ustawi³ graczom w pobli¿u {DDDDDD}%.2f{11BB11} pancerza!", pName[playerid], amount);

		pLoop(i)
	    {
	        if(GetPlayerState(i) == 0
				|| GetPlayerVirtualWorld(i) != GetPlayerVirtualWorld(playerid)
				|| IsPlayerInRangeOfPoint(i, 35.0, x,y,z) == 0) continue;

			SetPlayerArmour(i, amount);
			SCM(i, -1, strx);
	    }

	}else SCM(playerid, -1, "/setarmor [id/all] [armor]");
	return 1;
}
CMD:sethp(playerid, params[])
{
	if(Administrator[playerid] < 1)
	    return 0;

	new player[4], Float:amount;
	if(sscanf(params, "s[4]f", player, amount))
	    return SCM(playerid, -1, "/sethp [id/all] [hp]");

	if(amount > 100 || amount <= 0)
	    return SCM(playerid, -1, "{FF0000}Nie przesadzasz troszke z iloœci¹? Granice: 1-100");


	if(IsNumeric(player))
	{
		if(!IsPlayerConnected(strval(player)))
		    return SCM(playerid, -1, "{DD0000}Gracz o takim ID nie jest po³¹czony");

		format(strx, 128, "{11BB11}Admin {DDDDDD}%s{11BB11} ustawi³ Ci{DDDDDD} %.2f{11BB11} ¿ycia!", pName[playerid], amount);
		SCM(strval(player), -1, strx);
		format(strx, 128, "{11BB11}Ustawi³eœ {DDDDDD}%.2f{11BB11}hp graczowi {DDDDDD}%s{11BB11}!",  amount,pName[strval(player)]);
		SCM(playerid, -1, strx);
		SetPlayerHealth(strval(player), amount);

	}else if(!strcmp(player, "all", true) && amount > 1)
	{
	    pLoop(i)
	    {
			if(GetPlayerState(i) == 0) continue;

			SetPlayerHealth(i, amount);
		}
		format(strx, 128, "{11BB11}Admin {DDDDDD}%s{11BB11} ustawi³ wszystkim {DDDDDD}%.2f{11BB11} ¿ycia!", pName[playerid], amount);
		SCMToAll(-1, strx);

	}else if(!strcmp(player, "area", true, strlen(player)) && strlen(player) >= 2 && amount > 2)
	{
	    new Float:x,Float:y,Float:z;
	    GetPlayerPos(playerid, x,y,z);

	    format(strx, 128, "{11BB11}Admin {DDDDDD}%s{11BB11} ustawi³ graczom w pobli¿u {DDDDDD}%.2f{11BB11} ¿ycia!", pName[playerid], amount);

	    pLoop(i)
	    {
	        if(GetPlayerState(i) == 0
				|| GetPlayerVirtualWorld(i) != GetPlayerVirtualWorld(playerid)
				|| IsPlayerInRangeOfPoint(i, 35.0, x,y,z) == 0) continue;

			SetPlayerHealth(i, amount);
			SCM(i, -1, strx);
	    }

	}else SCM(playerid, -1, "/sethp [id/all/area] [hp]");

	return 1;
}

CMD:giveexp(playerid, params[])
{
	if(Administrator[playerid] < 3)
	    return 0;

	new player[4], amount;
	if(sscanf(params, "s[4]d", player, amount))
	    return SCM(playerid, -1, "/giveexp [id/all] [exp]");

	if(IsNumeric(player))
	{
		if(!IsPlayerConnected(strval(player)))
		    return SCM(playerid, -1, "{DD0000}Gracz o takim ID nie jest po³¹czony");

		format(strx, 128, "{11BB11}Admin {DDDDDD}%s{11BB11} da³ Ci{DDDDDD} %d{11BB11} exp!", pName[playerid], amount);
		SCM(strval(player), -1, strx);
		format(strx, 128, "{11BB11}Da³eœ {DDDDDD}%d{11BB11}exp graczowi {DDDDDD}%s{11BB11}!",  amount,pName[strval(player)]);
		SCM(playerid, -1, strx);
		GivePlayerScore(strval(player), amount);

		if(strval(player) == playerid)
		{
			SCM(playerid, -1, "Pamiêtaj, ¿e wykorzystywanie admina we w³asnej korzyœci jest zabronione. Ta czynnoœæ zosta³a zapisana w logach.");
		}

	}else if(!strcmp(player, "all", true))
	{
		pLoop(i)
			GivePlayerScore(i, amount);

		format(strx, 128, "{11BB11}Admin {DDDDDD}%s{11BB11} da³ wszystkim {DDDDDD}%d{11BB11} exp!", pName[playerid], amount);
		SCMToAll(-1, strx);

	}else SCM(playerid, -1, "/giveexp [id/all] [money]");
	return 1;
}

CMD:c_dom(playerid, params[])
{
	if(Administrator[playerid] < 3)
	    return 0;

	if(isnull(params) || !IsNumeric(params) || strval(params) < 100)
	    return SCM(playerid, -1, "/c_dom [cena]");

	new Float:x, Float:y, Float:z, Float:a, mstr[250];
	GetPlayerPos(playerid, x,y,z);
	GetPlayerFacingAngle(playerid, a);
	new i = HouseCount, rid[11];

	if(i >= MAX_HOUSES) return SCM(playerid, -1, "MAX_HOUSES error");

	format(mstr, 250, "INSERT INTO `house` (`x`,`y`,`z`,`outx`,`outy`,`outz`,`outa`,`cost`) VALUES ('%.3f', '%.3f', '%.3f', '%.3f', '%.3f', '%.3f', '%.3f', '%d')", x,y,z,x,y,z,a, strval(params));
	mysql_query(mstr);
	format(mstr, 250, "SELECT `id` FROM `house` WHERE `x` = '%.3f' AND `y` = '%.3f' AND `z` = '%.3f'", x,y,z);
	mysql_query(mstr);
	mysql_store_result();
	mysql_fetch_field("id", rid);
	mysql_free_result();

	HouseInfo[i][hID] = strval(rid);
	HouseInfo[i][hX] = x;
	HouseInfo[i][hY] = y;
	HouseInfo[i][hZ] = z;
	HouseInfo[i][hOX] = x;
	HouseInfo[i][hOY] = y;
	HouseInfo[i][hOZ] = z;
	HouseInfo[i][hOA] = a;
	HouseInfo[i][hCost] = strval(params);
	HouseInfo[i][hInt] = 0;
	HouseInfo[i][hCP] = CreatePickup(1277, 1, x,y,z + 0.2, 0);
	format(HouseInfo[i][hName], 40, "Dom na sprzeda¿!");
	format(HouseInfo[i][hOwner], 40, "#");
	format(mstr, sizeof mstr, ""C_O"Dom na sprzeda¿!"C_O"\n\n"C_O"Cena: "C_B"%d", strval(params));
	HouseInfo[i][hLabel] = Create3DTextLabel(mstr, -1, x,y,z + 1.5, 15.0, 0, 1);
    CreateDynamicMapIcon(x, y, z, 35, -1, 0, 0);

	HouseCount++;
	return 1;
}

CMD:tp_dom(playerid, params[])
{
	if(Administrator[playerid] < 4)
	    return 0;

	if(isnull(params) || !IsNumeric(params))
	    return SCM(playerid, -1, "/tp_dom [hID]");

	new hid = strval(params);

 	SetPlayerInterior(playerid, 0);
	SetPlayerVirtualWorld(playerid, 0);
	SetPlayerPos(playerid, HouseInfo[hid][hOX], HouseInfo[hid][hOY], HouseInfo[hid][hOZ]);
	SetPlayerFacingAngle(playerid, HouseInfo[hid][hOA]);
	return 1;
}


CMD:p_race(playerid, params[])
{
	if(Administrator[playerid] < 4) return 0;

	new size, typ, i;
	if(sscanf(params, "ddd", i, size, typ))
	    return SCM(playerid, -1, "/p_race [race id] [size] [typ]");

	new Float:x,Float:y,Float:z;
	GetPlayerPos(playerid, x,y,z);

	if(typ == 0 || typ == 1) z = z - 1.5;
	if(typ == 3 || typ == 4) z = z - 2.5;

	new mstr[150];
	format(mstr, 150, "INSERT INTO `race_cp` (`race_id`, `x`,`y`,`z`,`typ`,`size`) VALUES ('%d','%.3f','%.3f','%.3f','%d','%d');", i, x,y,z,typ,size);
	mysql_query(mstr);
	format(mstr, 150, "CP dla %d dodano.", i);
	SCM(playerid, -1, mstr);

	for(new r; r < MAX_RACE; r++)
	{
	    if(RaceInfo[r][Rid] == i)
	    {
	        RaceInfo[r][Rall_cp]++;
	        break;
	    }
	}
	return 1;
}

Float:GetInteriorExit( id, &Float:x, &Float:y, &Float:z ){
	if( id > MAX_INTERIORS ) return 0.0;
	else {
	    x = interiorInfo[id][inExitX];
	    y = interiorInfo[id][inExitY];
	    z = interiorInfo[id][inExitZ];
		return interiorInfo[id][inExitA];
	}
}

GetInteriorIntID( id ){
	if( id > MAX_INTERIORS ) return -1;
	else return interiorInfo[id][inIntID];
}

forward Float:GetPropertyEntrance( id, &Float:x, &Float:y, &Float:z );
Float:GetPropertyEntrance( id, &Float:x, &Float:y, &Float:z ){
	if( id > MAX_PROPERTIES ) return 0.0;
	x = properties[id][eEntX];
	y = properties[id][eEntY];
	z = properties[id][eEntZ];
	return properties[id][eEntA];
}

Float:GetPropertyExit( id, &Float:xxx, &Float:yyy, &Float:zzz )
{
	if( id > MAX_PROPERTIES ) return 0.0;
	return GetInteriorExit( properties[id][eUniqIntId], xxx, yyy, zzz );
}

GetPropertyInteriorId( id ){
	if( id > MAX_PROPERTIES ) return 0;
	else return GetInteriorIntID( properties[id][eUniqIntId] );
}
PutPlayerInProperty( playerid, propId, propVW = 0 )
{
	new Float:x, Float:y, Float:z, Float:a;

    a = GetPropertyExit( propId, x, y, z );
	SetPlayerPos( playerid, x, y, z );
	SetPlayerFacingAngle( playerid, a );
	SetPlayerInterior( playerid, GetPropertyInteriorId( propId ));
	SetPlayerVirtualWorld( playerid, (propVW==0)? propId+PROP_VW:propVW );
	currentInt[playerid] = propId;
}

CMD:c_race(playerid, params[])
{
	if(Administrator[playerid] < 4)
	    return 0;

	if(!IsPlayerInAnyVehicle(playerid))
	    return SCM(playerid, -1, "Pojazd");

	if(isnull(params))
	    return SCM(playerid, -1, "/c_race [nazwa]");

	new Float:x, Float:y, Float:z, modelid, Float:r, mstr[200];
	new v = GetPlayerVehicleID(playerid);
	GetVehiclePos(v, x,y,z);
	GetVehicleZAngle(v, r);
	modelid = GetVehicleModel(v);
	new i = RacesCount, rid[11];

	if(i >= MAX_RACE) return SCM(playerid, -1, "MAX_RACE error");

	format(mstr, 150, "INSERT INTO `race_id` (`name`,`x`,`y`,`z`,`r`,`modelid`) VALUES ('%s','%.3f','%.3f','%.3f','%.3f','%d');", params, x,y,z,r,modelid);
	mysql_query(mstr);
	format(mstr, 150, "SELECT `id` FROM `race_id` WHERE `name` = '%s' AND `modelid` = '%d'", params, modelid);
	mysql_query(mstr);
	mysql_store_result();
	mysql_fetch_field("id", rid);
	mysql_free_result();

	SCM(playerid, -1, rid);
   	format(RaceInfo[i][Rname], 40, "%s", params);
	RaceInfo[i][Rx] = x;
	RaceInfo[i][Ry] = y;
	RaceInfo[i][Rz] = z;
	RaceInfo[i][Rr] = r;
	RaceInfo[i][Rmodelid] = modelid;
	RaceInfo[i][Rid] = strval(rid);

	RaceInfo[i][Rcp] = CreateDynamicCP(x,y,z, 3.5, 0, 0, -1, 40.0);
	format(mstr, 200, "* {00AAFF}Wyœcig"C_O" *\n\n{FFAA00}%s", params);
	Create3DTextLabel(mstr, -1, x,y,z + 1, 25.0, 0, 1);
	CreateDynamicMapIcon(x,y,z, 55, -1, 0, 0);
	RacesCount++;
	return 1;
}

CMD:annoff(playerid, params[])
{
	if(Administrator[playerid] < 1)
	{
		if(!AnnON) return SCM(playerid, 0xDD0000FF, "Announce jest teraz wy³¹czone!");

		TD_Hide(playerid, AnnTD);
	}else{
		if(!AnnON) return SCM(playerid, 0xDD0000FF, "Announce jest teraz wy³¹czone!");

		WylanczAnn();
		SCM(playerid, -1, "Announce zosta³o wy³¹czone.");
	}
	return 1;
}
CMD:ann(playerid, params[])
{
	if(Administrator[playerid] < 1)
	    return 0;

	new msg[512], time;
	if(sscanf(params, "ds[384]", time, msg))
	    return SCM(playerid, -1, "/ann [sekundy] [tresc]");

	new count = 0;
	for(new i; i < strlen(msg); i++)
	{
		if(msg[i] == '~') count++;
	}
	if(IsNumberEven(count) == 0 && count != 0)
	{
	    SCM(playerid, -1, "Wpisano nieprawid³ow¹ iloœæ tyld (~)");
	    return 1;
	}


	TextDrawSetString(AnnTD, msg);

	if(AnnON == 1)
	   	KillTimer(AnnTim);

	AnnTim = SetTimer("WylanczAnn", time * 1000, 0);
    TextDrawShowForAll(AnnTD);
    AnnON = 1;
	return 1;
}

CMD:p_figurka(playerid, params)
{
   	if(Administrator[playerid] < 2)
		return 0;

	if(GetPlayerVirtualWorld(playerid) != 0 || GetPlayerInterior(playerid) != 0)
		return SCM(playerid, -1, "Musisz byæ w Interior:0 oraz VirtualWorld:0");

	new x = -1;
	for(new i; i < sizeof Figurki_ID; i++)
	{
		if(Figurki_ID[i] == -1)
		{
			x = i;
			break;
		}
	}

	if(x == -1) return SCM(playerid, -1, "Nie mo¿na postawiæ wiêcej figurek.");

	new Float:pos[3];
	GetPlayerPos(playerid, pos[0], pos[1], pos[2]);
	Figurki_PICKUP[x] = CreatePickup(1276, 1, pos[0], pos[1], pos[2], 0);
	format(strx, sizeof strx, "INSERT INTO `figurki` (`X`, `Y`, `Z`) VALUES ('%.3f','%.3f','%.3f');",pos[0], pos[1], pos[2]);
	mysql_query(strx);

	new idf[20];

	format(strx, sizeof strx, "SELECT `id` FROM `figurki` WHERE `X` = '%.3f' AND `Y` = '%.3f'", pos[0], pos[1]);
	mysql_query(strx);
	mysql_store_result();
	mysql_fetch_field("id", idf);
	mysql_free_result();

	Figurki_ID[x] = strval(idf);

	SCM(playerid, -1, "Figurka zosta³a postawiona.");
	return 1;
}

new lraport[5][128], craport;
CMD:lastraports(playerid, params[]) return cmd_lastreports(playerid, params);
CMD:lastreports(playerid,params[])
{
	if(Administrator[playerid] < 1) return 0;

	format(bstrx, sizeof bstrx, ""C_B"5 "C_O"Ostatnich raportów:\n\n%s\n%s\n%s\n%s\n%s\n", lraport[0],lraport[1],lraport[2],lraport[3],lraport[4]);
	InfoBox(playerid, bstrx);
	return 1;
}

CMD:spec(playerid, params[])
{
    if(Administrator[playerid] < 1)
        return 0;

	new player;
    if(sscanf(params, "d", player))
        return SCM(playerid, -1, "/spec [id]");

    if(!IsPlayerConnected(player) || player == playerid)
        return SCM(playerid, -1, "{FF0000}Nieprawidowy gracz!");

	StartSpec(playerid, player);
	return 1;
}

CMD:specoff(playerid, params[])
{
    if(Administrator[playerid] < 1)
        return 0;

	TogglePlayerSpectating(playerid, 0);
	SpecPlayer[playerid] = -1;
	return 1;
}

CMD:clear(playerid, params[])
{
    if(Administrator[playerid] < 1)
        return 0;

    for(new i; i< 100; i++) SCMToAll(-1, " ");

    SCMToAll(0xEE0000FF, "Czat zosta³ wyczyszczony przez Administratora.");
	return 1;
}

JailPlayer(playerid, admin[], reason[])
{
	GivePlayerScore(playerid, -5);
	ResetPlayerWeapons(playerid);
	pInFun[playerid] = 1;
	SetPlayerInterior(playerid, 0);
	SetPlayerVirtualWorld(playerid, 0);
	SetPVarInt(playerid, "pJailed", 1);
	new rand = random(sizeof(CelaSpawn));
	PlayerTeleport(playerid,0,CelaSpawn[rand][0], CelaSpawn[rand][1], CelaSpawn[rand][2]);
	SetPlayerVirtualWorld(playerid,10);
	ResetPlayerWeapons(playerid);

	SetTimerEx("UnJail", 120000, 0, "d", playerid);

	format(strx, sizeof strx, "UPDATE `players` SET `jail` = 1 WHERE `nick` = '%s'", pName[playerid]);
	mysql_query(strx);

	format(strx, sizeof(strx), "* {DDDDDD}%s {DD0000}zosta³ zamkniêty w Wiêzieniu przez {DDDDDD}%s", pName[playerid], admin);
	SCMToAll(-1, strx);
	format(strx, sizeof(strx), "{DD0000}Powód:{DDDDDD} %s", reason);
	SCMToAll(-1, strx);
	return 1;
}
forward PlayerTeleport(playerid,interior,Float:x,Float:y,Float:z);
public PlayerTeleport(playerid,interior,Float:x,Float:y,Float:z)
{

	SetPlayerPos(playerid, x,y,z);
	SetPlayerInterior(playerid,interior);
	SetPlayerVirtualWorld(playerid,0);
	return 1;
}

CMD:unjail(playerid, params[])
{
	if(Administrator[playerid] < 1)
	    return 0;

	new player;
	if(sscanf(params, "d", player))
	    return SCM(playerid, -1, "/unjail [ID]");

	if(GetPVarInt(player, "pJailed") == 0 || !IsPlayerConnected(player))
	    return SCM(playerid, -1, "Ten gracz nie jest w wiêzieniu!");

	UnJail(player);
	SCM(player, -1, "Gracz zosta³ uwolniony z wiêzienia.");
	return 1;
}
forward UnJail(playerid);
public UnJail(playerid)
{
	if(GetPVarInt(playerid, "pJailed") == 1)
	{
		pInFun[playerid] = 0;
		SCM(playerid, -1, "{FF0000}Zosta³eœ wypuszczony z wiêzienia!");
		SetPlayerVirtualWorld(playerid, 0);
		SetPlayerPos(playerid, 2159.64,997.485,10.8203);
		format(strx, sizeof strx, "UPDATE `players` SET `jail` = 0 WHERE `nick` = '%s'", pName[playerid]);
		mysql_query(strx);
	}
	SetPVarInt(playerid, "pJailed", 0);
	return 1;
}
CMD:setcolor(playerid, params[])
{
	if(Administrator[playerid] < 1)
	    return 0;

	new player, kolor;
    if(sscanf(params, "dh", player, kolor))
        return SCM(playerid, 0xFFFFFFFF, "/setcolor [id] [kod HEX np. 0xFF0000FF]");

    if(!IsPlayerConnected(player))
        return SCM(playerid, 0xEE0000FF, "Ten gracz nie jest po³¹czony!");

    SetPlayerColor(player, kolor);

	format(strx, sizeof strx, "Administrator {D9D9D9}%s{00DD00} zmieni³ Ci kolor nicku na %h", pName[playerid], kolor);
	SCM(player, 0x00DD00FF, strx);
	return 1;
}
CMD:darea(playerid, params[])
{
	if(Administrator[playerid] < 1)
	    return 0;

	new Float:pos[3];
	GetPlayerPos(playerid, pos[0],pos[1],pos[2]);

	format(strx, sizeof bstrx, "{11BB11}Admin {DDDDDD}%s{11BB11} rozbroi³ wszystkich w twojej okolicy!", pName[playerid]);
	pLoop(i)
	{
		if(IsPlayerInRangeOfPoint(i, 30.0, pos[0],pos[1],pos[2]) && Administrator[playerid] && GetPlayerVirtualWorld(i) == GetPlayerVirtualWorld(playerid))
	    {
			ResetPlayerWeapons(i);
			SCM(i, -1, strx);
	    }
	}
	return 1;
}
CMD:zpos(playerid, params[])
{
	if(Administrator[playerid] < 1)
	    return 0;

	new player, Float:posz;
	if(sscanf(params, "uf", player, posz))
	    return SCM(playerid, -1, ""C_O"/zpos "C_B"[player] [+/- Wysokoœæ]");

	if(posz < -1000 || posz > 1000)
	    return SCM(playerid, -1, ""C_O"Wysokoœæ w granicach: "C_B"-1000...1000");

	if(!IsPlayerConnected(player))
	    return SCM(playerid, -1, ""C_O"Nieprawid³owy gracz");

	new Float:x, Float:y, Float:z;
	GetPlayerPos(player, x,y,z);
	SetPlayerPos(player, x,y,z + posz);

	if(posz > 0) SCM(playerid, -1, ""C_B" Gracz zosta³ podniesiony");
	if(posz < 0) SCM(playerid, -1, ""C_B" Gracz zosta³ obni¿ony");
	return 1;
}
CMD:me(playerid, params[])
{
	if(isnull(params))
	    return SCM(playerid, -1, "/me [czynnoœæ]");

	new Float:pos[3];
	GetPlayerPos(playerid, pos[0],pos[1],pos[2]);
	format(strx, sizeof strx, ""C_B"%s %s", pName[playerid], params);
	pLoop(i)
	{
	    if(GetPlayerVirtualWorld(playerid) == GetPlayerVirtualWorld(i) && IsPlayerInRangeOfPoint(i, 20.0,pos[0],pos[1],pos[2]))
	    {
	        SCM(i, -1, strx);
	    }
	}
	return 1;
}
CMD:console(playerid, params[])
{
	if(Administrator[playerid] < 4)
	    return 0;

	if(isnull(params)) return SCM(playerid, -1, "/console [cmd]");

	SendRconCommand(params);
	SCM(playerid, -1, ""C_B"Send to Remote Console.");
	return 1;
}
CMD:setvw(playerid, params[])
{
	if(Administrator[playerid] < 4)
	    return 0;

	new player, vw;
	if(sscanf(params, "ui", player, vw))
	    return SCM(playerid, -1, ""C_O"/setvw "C_B"[player] [vw]");

	SetPlayerVirtualWorld(player, vw);
	SCM(playerid, -1, ""C_B"VW Changed.");
	return 1;
}
CMD:emulate(playerid, params[])
{
	if(Administrator[playerid] < 4)
	    return 0;

	new player, text[120];
	if(sscanf(params, "ds[120]", player, text))
        return SCM(playerid, 0xFFFFFFFF, "/emulate [id] [emulate]");

    if(!IsPlayerConnected(player))
        return SCM(playerid, 0xEE0000FF, "Ten gracz nie jest po³¹czony!");

	if(text[0] == '/')
	{
	    CallLocalFunction("OnPlayerCommandText", "is", player, text);
	}else{
	    CallLocalFunction("OnPlayerText", "is", player, text);
	}
	return 1;
}
CMD:addban(playerid, params[])
{
	if(Administrator[playerid] < 1)
        return 0;

    new player[20], powod[64];
    if(sscanf(params, "s[20]s[64]", player, powod))
        return SCM(playerid, -1, "/addban [nick] [powód]");

	format(strx, sizeof strx, "SELECT `ip` FROM `players` WHERE `nick` = '%s'", player);
	mysql_query(strx);
	mysql_store_result();

	if(mysql_num_rows() == 0)
	    return SCM(playerid, -1, "Taki gracz nie jest zarejestrowany!"), mysql_free_result();

	new ip[24];
	mysql_fetch_field("ip", ip);
	mysql_free_result();

	pLoop(i)
	{
	    if(!strcmp(pName[i], player) && IsPlayerConnected(i))
	    {
	        format(strx, sizeof strx, "%d %s", i, powod);
	        return cmd_ban(playerid, strx);
	    }
	}

	new mstr[250];
    format(mstr, 250,  "INSERT INTO `bans` (`nick`,`ip`,`date`,`admin`,`reason`) VALUES ('%s','%s','%s','%d.%s.%dr.','%s')",player,ip,day,namemonth[month - 1],year,pName[playerid],powod);
   	mysql_query(mstr);

   	format(strx, sizeof strx, "Zbanowa³eœ %s za %s", player, powod);
   	SCM(playerid, -1, strx);
	return 1;
}
CMD:unbanip(playerid, params[])
{
    if(Administrator[playerid] < 1)
        return 0;

	if(isnull(params) || IsIP(params) == 0)
	    return SCM(playerid, -1, "/unbanip [IP]");

	format(strx,sizeof strx, "SELECT `admin` FROM `bans` WHERE `ip` = '%s'", params);
	mysql_query(strx);
    mysql_store_result();
	if(mysql_num_rows() == 0)
	{
		SCM(playerid, -1, "Nie znaleziono takiego bana.");
		mysql_free_result();
		return 1;
	}

	new admin[30];
	mysql_fetch_field("admin", admin);
	mysql_free_result();

	if(strcmp(pName[playerid], admin) != 0 && Administrator[playerid] < 2)
	{
		format(strx, sizeof strx, "Admin, który wstawi³ tego bana to {FF0000}%s"C_O". Tylko on moze odbanowaæ!", admin);
		SCM(playerid, -1, strx);
		return 1;
	}
	UnbanIP(playerid, params);
	return 1;
}
UnbanIP(playerid, ip[])
{
	new mstr[150];
	format(mstr, 150, "DELETE FROM `bans` WHERE `ip` = '%s'", ip);
	mysql_query(mstr);
	SCM(playerid, -1, "Ban zosta³ usuniêty!");
	return 1;
}
CMD:unban(playerid, params[])
{
    if(Administrator[playerid] < 1)
        return 0;

	if(isnull(params))
	    return SCM(playerid, -1, "/unban [nick]");

	format(strx,sizeof strx, "SELECT `admin`,`ip` FROM `bans` WHERE `nick` = '%s'", params);
	mysql_query(strx);
	mysql_store_result();
	if(mysql_num_rows() == 0)
	{
		SCM(playerid, -1, "Nie znaleziono takiego bana.");
		mysql_free_result();
		return 1;
	}

	new admin[30], ip[24];
	mysql_fetch_field("admin", admin);
	mysql_fetch_field("ip", ip);
	mysql_free_result();

	if(strcmp(pName[playerid], admin) != 0 && Administrator[playerid] < 2 && strcmp(admin, "Anty Cheat") != 0)
	{
		format(strx, sizeof strx, "Admin, który wstawi³ tego bana to {FF0000}%s"C_O". Tylko on mo¿e odbanowaæ!", admin);
		SCM(playerid, -1, strx);
		return 1;
	}
	UnbanIP(playerid, ip);
	return 1;
}
CMD:eye(playerid, params[])
{
    if(Administrator[playerid] < 1)
        return 0;

    if(GetPVarInt(playerid, "eye") == 1)
	{
		SetPVarInt(playerid, "eye", 0);
        SCM(playerid, 0xFF0000FF, "[EYE]: Podgl¹d komend wpisywanych przez graczy zosta³ wy³aczony");
	}else
	{
	    SetPVarInt(playerid, "eye", 1);
	    SCM(playerid, 0x00BB00FF, "[EYE]: Podglad komend wpisywanych przez graczy zosta³ w³aczony");
	}
	return 1;
}

CMD:pmeye(playerid, params[])
{
    if(Administrator[playerid] < 1)
        return 0;

    if(GetPVarInt(playerid, "pmeye") == 1)
	{
		SetPVarInt(playerid, "pmeye", 0);
        SCM(playerid, 0xFF0000FF, "[EYE]: Podgl¹d wiadomoœci zosta³ wy³aczony");
	}else
	{
	    SetPVarInt(playerid, "pmeye", 1);
	    SCM(playerid, 0x00BB00FF, "[EYE]: Podglad wiadomoœci zosta³ w³aczony");
	}
	return 1;
}

CMD:unmute(playerid, params[])
{
    if(Administrator[playerid] < 1)
        return 0;

    new player;
    if(sscanf(params, "d", player))
        return SCM(playerid, -1, "/unmute [id]");

	if(!IsPlayerConnected(player))
        return SCM(playerid, 0xFF0000FF, "Ten gracz nie jest po³¹czony!");

	if(GetPVarInt(player, "mute") < GetTickCount()) return SCM(playerid, -1, "Ten gracz nie jest uciszony!");


	format(strx, sizeof strx, "Gracz {DDDDDD}%s{DD0000} zosta³ odciszony przez administratora {DDDDDD}%s", pName[player],pName[playerid]);
    SCMToAll(0xDD0000FF, strx);
	SetPVarInt(player, "mute", 0);
	return 1;
}

CMD:mute(playerid, params[])
{
    if(Administrator[playerid] < 1)
        return 0;

    new player, czas, powod[64];

	if(sscanf(params, "uds[64]", player, czas, powod))
        return SCM(playerid, -1, "/mute [id] [czas w minutach] [powód]");

    if(!IsPlayerConnected(player))
        return SCM(playerid, 0xFF0000FF, "Ten gracz nie jest po³¹czony!");

	if(Administrator[player]) return SCM(playerid, 0xFF0000FF, "Nie mo¿esz uciszyc Administratora!");

	if(GetPVarInt(player, "mute") > GetTickCount()) return SCM(playerid, -1, "Ten gracz jest ju¿ uciszony!");

	format(strx, sizeof strx, "{DD0000}Gracz {DDDDDD}%s{DD0000} zosta³ uciszony przez {DDDDDD}%s{DD0000}, na czas {DDDDDD}%d{DD0000} min.", pName[player],pName[playerid],czas);
	format(powod, sizeof powod, "Powód: {DDDDDD}%s {DD0000}.", powod);
    SCMToAll(0xDD0000FF, strx);
	SCMToAll(0xDD0000FF, powod);
	SetPVarInt(player, "mute", GetTickCount() + czas * 60000);
	return 1;
}
CMD:ping(playerid, params[])
{
	format(strx, sizeof strx, ""C_O"Ograniczenie pingu do "C_B"%d"C_O" ms", max_ping);
	SCM(playerid, 0xDD0000FF, strx);
	return 1;
}
CMD:maxping(playerid, params[])
{
    if(Administrator[playerid] < 1)
        return 0;

	new ping;
    if(sscanf(params, "i", ping))
        return SCM(playerid, -1, "/maxping [ping]");

    if((ping < 120) || (ping > 700))
        return SCM(playerid, -1, "Ping musi byæ z przedzia³u 120..700");

	format(strx, sizeof strx, "Administrator {D9D9D9}%s{DD0000} ustawi³ maksymalny ping na {D9D9D9}%d{DD0000} ms.", pName[playerid],ping);
    SCMToAll(0xDD0000FF, strx);
    max_ping = ping;
	return 1;
}

CMD:respawn(playerid, params[])
{
	if(Administrator[playerid] < 1)
	    return 0;

    new UsedVeh[MAX_VEHICLES] = {false, ...};

	pLoop(i)
        if(IsPlayerInAnyVehicle(i))
            UsedVeh[GetPlayerVehicleID(i)] = true;

    for(new i = 1; i != MAX_VEHICLES; i++)
        if(!UsedVeh[i])
            SetVehicleToRespawn(i);

	format(strx, sizeof strx, "{FF0000}Admin {DDDDDD}%s{FF0000} zrespawnowa³ nieu¿ywane pojazdy.", pName[playerid]);
	SCMToAll(-1, strx);
	return 1;
}

CMD:explode(playerid, params[])
{
    if(Administrator[playerid] < 1)
        return 0;

    new player, Float:xyz[3];
    if(sscanf(params, "d", player))
        return SCM(playerid, -1, "/explode [id]");

    if(!IsPlayerConnected(player))
        return SCM(playerid, 0xFF0000FF, "Ten gracz nie jest po³¹czony!");

	if(GetPlayerInterior(player) != 0)
	    return SCM(playerid, 0xFF0000FF, "Nie mo¿na explodowaæ gracza, kiedy jest w budynku!");

	new Float:hp;
	GetPlayerHealth(player, hp);
	SetTimerEx("ExplodeTimer", 800, 0, "ddf", playerid, player, hp);

	GetPlayerPos(player,xyz[0], xyz[1], xyz[2]);
 	CreateExplosion(xyz[0], xyz[1], xyz[2], 10, 1);
	CreateExplosion(xyz[0], xyz[1], xyz[2], 10, 1);
	CreateExplosion(xyz[0], xyz[1], xyz[2], 10, 1);
	SetPVarInt(player, "explode", 1);
	return 1;
}

CMD:jail(playerid, params[])
{
	if(Administrator[playerid] < 1)
	    return 0;

	new player, reason[64];
	if(sscanf(params, "ds[64]", player, reason))
	    return SCM(playerid, -1, ""C_B"/jail [ID] [Powód]");

	if(!IsPlayerConnected(player))
	    return SCM(playerid, -1, ""C_O"Gracz o takim ID nie jest polaczony");

	if(GetPVarInt(player, "pJailed") == 1)
	    return SCM(playerid, -1, ""C_O"Ten gracz jest juz w wiezieniu!");

	JailPlayer(player, pName[playerid], reason);
	return 1;
}
CMD:nazwaserwa(playerid,cmdtext[])
{
	if(Administrator[playerid] < 4) return 0;
	new nazwa[128],
	    NazwaSerwa[128];
	if(sscanf(cmdtext,"s[128]",nazwa)){
	    SCM(playerid, -1, ""C_O"/NazwaSerwa "C_B"[Nowa Nazwa]");
		return 1;
	}
	NazwaSerwa = nazwa;
	return 1;
}

CMD:warn(playerid,cmdtext[])
{
	if(Administrator[playerid] < 1) return 0;
	
	new gracz,powod[128];
	if(sscanf(cmdtext,"us[128]",gracz,powod)){
	    SCM(playerid, -1, ""C_O"/Warn "C_B"[ID] [Powód]");
		return 1;
	}
	if(gracz < 0 || gracz >= MAX_PLAYERS) return SCM(playerid, -1, ""C_O"Zle ID gracza");
	if(!IsPlayerConnected(gracz)) return SCM(playerid, -1, " "C_O"Nie ma takiego gracza");
	if(WarnBlock[gracz]) return SCM(playerid, -1,""C_O"Ten gracz otrzyma³ przed chwil¹ odstrze¿enie od admina!");
	WarnBlock[gracz] = true;
	SetTimerEx("WarnUnlock",10000,0,"i",gracz);
	WarnSystem[gracz] ++;
	new tmp[128];
	new powodx[128];
	format(tmp, sizeof(tmp), "{DD0000}Admin {DDDDDD}%s{DD0000} nada³ ostrze¿enie graczowi {DDDDDD}%s. {DD0000}(%d/3)", pName[playerid], pName[gracz], WarnSystem[gracz]);
	format(powodx, sizeof(powodx), "Powód: {DDDDDD}%s {DD0000}.", powod);
	SCMToAll(-1, tmp);
	SCMToAll(-1, powodx);
	InfoBox(gracz,""C_B"Otrzymales/as ostrzezenie od Admina!");
	if(WarnSystem[gracz]==3){
		KickPlayer(gracz, "Warn System", "Nie stosuje sie do ostrze¿eñ!");
		return 1;
	}
	return 1;
}

CMD:acolor(playerid,cmdtext[])
{
	if(Administrator[playerid] < 1) return 0;
	SetPlayerColor(playerid,0xDD0000FF);
	ColorAdmina[playerid] = true;
	SCM(playerid, -1, ""C_O"Ustawi³eœ Sobie kolor admina");
	return 1;
}

CMD:invisible(playerid,cmdtext[])
{
	if(Administrator[playerid] < 1) return 0;
	SetPlayerColor(playerid,0xFFFFFF00);
	Invisible[playerid] = true;
	SCM(playerid, -1, ""C_O"Jestes niewidoczny/a na mapie!");
	SCM(playerid,	-1,""C_O"Aby wy³¹czyæ niewidzialnoœæ wpisz "C_B"/visible");
	return 1;
}

CMD:visible(playerid,cmdtext[])
{
    if(Administrator[playerid] < 1) return 0;
    SetPlayerColor(playerid, playerColors[playerid]);
	SCM(playerid, -1, ""C_O"Jestes widoczny.");
	return 1;
}

CMD:offwg(playerid, params[])
{
    if(Administrator[playerid] < 4) return 0;

	if(WG_Off == 0)
	{
	    WG_Off = 1;
	    SCM(playerid, -1, "OFF");
	}else{
	    WG_Off = 0;
	    SCM(playerid, -1, "ON");
	}
	return 1;
}
CMD:offhay(playerid, params[])
{
    if(Administrator[playerid] < 4) return 0;

	if(HAY_Off == 0)
	{
	    HAY_Off = 1;
	    SCM(playerid, -1, "OFF");
	}else{
	    HAY_Off = 0;
	    SCM(playerid, -1, "ON");
	}
	return 1;
}
CMD:offch(playerid, params[])
{
    if(Administrator[playerid] < 4) return 0;

	if(CH_Off == 0)
	{
	    CH_Off = 1;
	    SCM(playerid, -1, "OFF");
	}else{
	    CH_Off = 0;
	    SCM(playerid, -1, "ON");
	}
	return 1;
}
CMD:offss(playerid, params[])
{
    if(Administrator[playerid] < 4) return 0;

	if(SS_Off == 0)
	{
	    SS_Off = 1;
	    SCM(playerid, -1, "OFF");
	}else{
	    SS_Off = 0;
	    SCM(playerid, -1, "ON");
	}
	return 1;
}
CMD:offtw(playerid, params[])
{
    if(Administrator[playerid] < 4) return 0;

	if(TW_Off == 0)
	{
	    TW_Off = 1;
	    SCM(playerid, -1, "OFF");
	}else{
	    TW_Off = 0;
	    SCM(playerid, -1, "ON");
	}
	return 1;
}
CMD:offdd(playerid, params[])
{
    if(Administrator[playerid] < 4) return 0;

	if(DD_Off == 0)
	{
	    DD_Off = 1;
	    SCM(playerid, -1, "OFF");
	}else{
	    DD_Off = 0;
	    SCM(playerid, -1, "ON");
	}
	return 1;
}

CMD:admin(playerid, cmdtext[])
{
	if(Administrator[playerid] < 3) return SCM(playerid, -1, "|TOP-DM| Musisz byæ administratorem 4 poziomu!");

	new id, poz, string2[400];
	if(sscanf(cmdtext, "ud", id, poz)) return SCM(playerid, -1, "|Error| /dajadma <id gracza> <poziom 1-2>");

	if(!IsPlayerConnected(id)) return SCM(playerid, -1, "|TOP-DM| Ten gracz nie jest pod³¹czony!");
	if(poz < 1 || poz > 2) return SCM(playerid, -1, "|TOP-DM| Nieprawid³owy poziom rangi administratora. (1-2)");
	if(Administrator[id] == poz) return SCM(playerid, -1, "|TOP-DM| Ten gracz ju¿ jest Administratorem tego poziomu!");

	Administrator[id] = poz;
	Admins_Online++;
	format(string2, sizeof(string2), ""C_B"%s (%d) "C_O"zalogowal "C_B"%s (%d) jako "C_O"Administrator poziom "C_B"%d", pName[playerid], playerid, pName[id], id, poz);
	SCMToAll(-1, string2);
	return 1;
}
CMD:out_dom(playerid, params[])
{
	if(Administrator[playerid] < 4)
	    return 0;

	if(isnull(params) || !IsNumeric(params))
	    return SCM(playerid, -1, "/out_dom [hID]");

	new i = strval(params);
	new Float:x,Float:y,Float:z,Float:a;
	GetPlayerPos(playerid, x,y,z);
	GetPlayerFacingAngle(playerid, a);

	HouseInfo[i][hOX] = x;
	HouseInfo[i][hOY] = y;
	HouseInfo[i][hOZ] = z;
	HouseInfo[i][hOA] = a;

	format(strx, sizeof strx, "UPDATE `house` SET `outx` = '%.3f',`outy` = '%.3f',`outz` = '%.3f', `outa` = '%.3f' WHERE `id` = '%d'", x,y,z,a, HouseInfo[i][hID]);
	mysql_query(strx);
	return 1;
}
