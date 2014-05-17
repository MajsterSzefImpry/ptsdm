/*
	@Polski TOP Serwer - vip.inc
	@Last update: 14 marca 2014 23:25

*/
CMD:premium(playerid, params[]) return cmd_vcmd(playerid, params);
CMD:vip(playerid, params[]) return cmd_vcmd(playerid, params);
CMD:vcmd(playerid, params[])
{
	format(bstrx, sizeof bstrx, "{FFFF00}Komendy dla VIP'ów:"C_O"\n\n");
	strcat(bstrx, "/vkolor - Zmieniasz sobie kolor.\n");
	strcat(bstrx, "/vcolor - Otrzymujesz specjalny kolor dla VIP'ów.\n");
	strcat(bstrx, "/vjetpack - Dostajesz jetpack'a.\n");
	strcat(bstrx, "/vczas - Zmieniasz sobie godzine.\n");
	strcat(bstrx, "/vpogoda - Zmieniasz sobie pogodê.\n");
	strcat(bstrx, "/vtele - W³¹czasz/Wy³¹czasz teleport za pomoc mapy.\n/vbronie - Ustawiasz zestaw broni.\n");
	strcat(bstrx, "/vdotacja - otrzymujesz 1 mln $\n");
	strcat(bstrx, "/vpozostalo - sprawdzasz wa¿noœæ vipa\n");
	strcat(bstrx, "\n\n\n{FFFF00}Dodatkowo otrzymujesz:"C_O"\n\n");
	strcat(bstrx, "- Kamizelka na spawnie.\n");
	strcat(bstrx, "- O po³owê zmniejszony czas oczekiwania na /zycie oraz /pancerz.\n");
	strcat(bstrx, "- Range w chacie\n");
	strcat(bstrx, "- Dodatkowe +2 exp za zabicie.\n");
	strcat(bstrx, "- Dodatkowe 10000$ na spawnie.\n");
	strcat(bstrx, "- Dwukrotnie powiêkszony limit maksymalnego pingu.\n");
	strcat(bstrx, "- Brak straty exp'a przy samobójstwie.\n");
	strcat(bstrx, "- Teleportowanie siê w dowolne miejsce zaznaczone na mapie.\n");
	strcat(bstrx, "- Powiekszone zycie pojazdu do 120.\n");
	strcat(bstrx, "- W³asny zestaw bronii na spawnie.\n\n\n");
	Dialog(playerid, 753, DIALOG_BOX, bstrx, "Zamknij", "Kup VIP!");
	return 1;
}
CMD:vdotacja(playerid)
{
	if(Vip[playerid] == false)
       return SCM(playerid, -1, "Kup konto VIP! Wiêcej na: {FF0000}/vip");
	if(vdot[playerid] == true) return SCM(playerid, -1, ""C_O"Ju¿ otrzyma³eœ dotacjê dla "C_B"Vipa!");

    vdot[playerid] = true;
	GivePlayerMoney(playerid, 1000000);
	SCM(playerid, -1, ""C_O"Otrzyma³eœ "C_B"1 "C_O"mln $ dotacji.");
	return 1;
}
CMD:vpozostalo(playerid, params[]){
	if(Vip[playerid] == false)
       return SCM(playerid, -1, "Kup konto VIP! Wiêcej na: {FF0000}/vip");
	new buff[128],str[200];
	format(str,sizeof str,"SELECT IFNULL(DATEDIFF(vip,NOW()),'-1') FROM `players` WHERE `nick`='%s' limit 1;", pName[playerid]);
	mysql_query(str);
	mysql_store_result();
	format(buff,sizeof buff,"Twoje konto VIP jest wa¿ne przez %d dni", mysql_fetch_int());
	ShowPlayerDialog(playerid,680,0,"VPozostalo",buff,"OK", "");
	return mysql_free_result();
}
CMD:vbronie(playerid, params[])
{
	if(Vip[playerid] == false)
		return SCM(playerid, -1, "Kup konto VIP! Wiêcej na: {FF0000}/vip");

    GivePlayerWeapon(playerid, 30, 1000);
    GivePlayerWeapon(playerid, 43, 1000);
    GivePlayerWeapon(playerid, 7, 1000);
    GivePlayerWeapon(playerid, 10, 1000);
    GivePlayerWeapon(playerid, 16, 5);
	SCM(playerid, -1, ""C_O"Otrzyma³eœ bronie "C_B"VIP-a");
	return 1;
}
CMD:telemap(playerid, params[]) return cmd_vtele(playerid, params);
CMD:vtele(playerid, params[])
{
	if(Vip[playerid] == false && Administrator[playerid] < 1)
		return SCM(playerid, -1, "Kup konto VIP! Wiêcej na: {FF0000}/vip");

	if(GetPVarInt(playerid, "vTeleMap") != 1)
	{
	    SetPVarInt(playerid, "vTeleMap", 1);
	    SCM(playerid, -1, "*{00AAFF}Wy³¹czono teleport za pomoc mapy w menu.");
	}else
	{
		SetPVarInt(playerid, "vTeleMap", 0);
		SCM(playerid, -1, "*{00AAFF}W³¹czono teleport za pomoc mapy w menu.");
	}
	return 1;
}

CMD:vjetpack(playerid, params[])
{
	if(Vip[playerid] == false)
		return SCM(playerid, -1, "Kup konto VIP! Wiêcej na: {FF0000}/vip");

	if(GetPlayerVirtualWorld(playerid) != 0 || GetPlayerInterior(playerid) != 0)
	    return SCM(playerid, -1, "Nie mo¿esz teraz lataæ jetpack'iem");

	SetPlayerSpecialAction(playerid, SPECIAL_ACTION_USEJETPACK);
	SetPlayerArmedWeapon(playerid, 0);
	return 1;
}

CMD:vczas(playerid, params[])
{
	if(Vip[playerid] == false)
		return SCM(playerid, -1, "Kup konto VIP! Wiêcej na: {FF0000}/vip");

	if(isnull(params))
	    return SCM(playerid, -1, "Wpisz: /vczas [godzina]");

	SetPlayerTime(playerid, strval(params), 00);
	return 1;
}

CMD:vkolor(playerid, params[])
{
	if(Vip[playerid] == false)
		return SCM(playerid, -1, "Kup konto VIP! Wiêcej na: {FF0000}/vip");


	new vipColor[100][] = {
		"FF8C13", "C715FF", "20B2AA", "DC143C", "6495ED", "f0e68c", "778899", "FF1493", "F4A460", "EE82EE",
		"FFD720", "8b4513", "4949A0", "148b8b", "14ff7f", "556b2f", "0FD9FA", "10DC29", "534081", "0495CD",
		"EF6CE8", "BD34DA", "247C1B", "0C8E5D", "635B03", "CB7ED3", "65ADEB", "5C1ACC", "F2F853", "11F891",
		"7B39AA", "53EB10", "54137D", "275222", "F09F5B", "3D0A4F", "22F767", "D63034", "9A6980", "DFB935",
		"3793FA", "90239D", "E9AB2F", "AF2FF3", "057F94", "B98519", "388EEA", "028151", "A55043", "0DE018",
		"93AB1C", "95BAF0", "369976", "18F71F", "4B8987", "491B9E", "829DC7", "BCE635", "CEA6DF", "20D4AD",
		"2D74FD", "3C1C0D", "12D6D4", "48C000", "2A51E2", "E3AC12", "FC42A8", "2FC827", "1A30BF", "B740C2",
		"42ACF5", "2FD9DE", "FAFB71", "05D1CD", "C471BD", "94436E", "C1F7EC", "CE79EE", "BD1EF2", "93B7E4",
		"3214AA", "184D3B", "AE4B99", "7E49D7", "4C436E", "FA24CC", "CE76BE", "A04E0A", "9F945C", "DCDE3D",
		"10C9C5", "70524D", "0BE472", "8A2CD7", "6152C2", "CF72A9", "E59338", "EEDC2D", "D8C762", "D8C762"
	};

	bstrx = "";
	new x = 1;
	for(new i; i < sizeof vipColor; i++)
	{
	    format(bstrx, sizeof bstrx, "%s{%s}Kolor %d\n", bstrx, vipColor[i], x);
		x++;
	}
	Dialog(playerid, 41, DIALOG_LIST, bstrx, "Ustaw", "Anuluj");
	return 1;
}

CMD:vpogoda(playerid, params[])
{
	if(Vip[playerid] == false)
		return SCM(playerid, -1, "Kup konto VIP! Wiêcej na: {FF0000}/vip");

	if(isnull(params) || !IsNumeric(params))
	    return SCM(playerid, -1, "Wpisz: /vpogoda [id]");

	SetPlayerWeather(playerid, strval(params));
	SCM(playerid, -1, "Pogoda zosta³a zmieniona.");
	return 1;
}

CMD:vcolor(playerid, params[])
{
	if(Vip[playerid] == false)
		return SCM(playerid, -1, "Kup konto VIP! Wiecej na: {FF0000}/vip");

	SetPlayerColor(playerid, 0xFF000033);
	SCM(playerid, -1, "Twój kolor zosta³ zmieniony.");
	return 1;
}
