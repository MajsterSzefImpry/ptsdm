/*
	@Polski TOP Serwer - user.inc
	@Last update: 17 marca 2014 23:25

*/
CMD:kolor(playerid, params[])
{
	ShowPlayerDialog(playerid, 125, DIALOG_STYLE_MSGBOX, ""DIALOG_T" {000000}| {00FF59}Zmiana koloru", "Chcesz zmieniæ swój kolor nicku?\n", "Tak", "Nie");
	return 1;
}

CMD:tak(playerid, cmdtext[])
{
	if(!mVote[vOdliczanka]) return SCM(playerid, -1, ""C_O"G³osowanie aktualnie nie trwa.");
	if(GetPVarInt(playerid, "Glosowal")) return SCM(playerid, -1, ""C_O"G³osowa³eœ ju¿ raz.");

	mVote[glos][0] ++;
	SetPVarInt(playerid, "Glosowal", 1);
	SCM(playerid, -1, ""C_O"Dziêkujemy za oddanie g³osu.");

	return 1;
}
CMD:nie(playerid, cmdtext[])
{
	if(!mVote[vOdliczanka]) return SCM(playerid, -1, ""C_O"G³osowanie aktualnie nie trwa.");
	if(GetPVarInt(playerid, "Glosowal")) return SCM(playerid, -1, ""C_O"G³osowa³eœ ju¿ raz.");

	mVote[glos][1] ++;
	SetPVarInt(playerid, "Glosowal", 1);
	SCM(playerid, -1, ""C_O"Dziêkujemy za oddanie g³osu.");

	return 1;
}
CMD:regulamin(playerid, params[]) return cmd_reg(playerid, params);
CMD:reg(playerid, params[])
{
    PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);
	format(bstrx, sizeof bstrx, "{FF0000}Regulamin Serwera"C_O"\n\n\n");
	strcat(bstrx, "1. Nie wolno uzywaæ cheatów/bugów/modów/trainerów u³atwiajcych gre.\n\n2. Nie wolno korzystac z bugów, które przeszkadzaja innym graczom.\n\n3. Nie wolno wyzywac innych graczy.\n\n");
	strcat(bstrx, "4. Nie wolno spamowaæ i reklamowaæ.\n\n5. Nie wolno podszywaæ siê pod innych graczy i administratorów.\n\n6. Administrator ma prawo kickowa/banowaæ bez PODANIA przyczyny.\n\n");
	strcat(bstrx, "7. Osoba zbanowana ma prawo do z³o¿enia wyjaœnieñ na forum.\n\n8. Zabronione jest ³amanie zasad Polskiego kodeksu karnego.\n\n9. Istnieje ca³kowity zakaz oszustwa materialnego graczy.\n\n{00BB00}");
	strcat(bstrx, "Rejestracja na serwerze oznacza akceptacjê regulaminu.\nWszelkie próby z³amania regulaminu moga byæ karane w ró¿ny sposób.\n\nStrona serwera: www.TOP.xaa.pl");
    InfoBox(playerid, bstrx);
	return 1;
}
CMD:authors(playerid, params[]) return cmd_autor(playerid, params);
CMD:autorzy(playerid, params[]) return cmd_autor(playerid, params);
CMD:autors(playerid, params[]) return cmd_autor(playerid, params);
CMD:autor(playerid, params[])
{
    new StrinG[1024];
    PlayerPlaySound(playerid, 1139, 0.0, 0.0, 0.0);
    StrinG = ""C_B"ptsDM - "C_O" "Version", "Date" "Godz"\n";
    strcat(StrinG,""C_B"Kod: "C_O"Maku, NexuS, MajsterSzefImpry\n");
    strcat(StrinG,""C_B"Mapperzy: "C_O"Lord_\n");
    strcat(StrinG,""C_B"Specjalne podziêkowania dla:\n\t");
    strcat(StrinG,""C_O"SA-MP Team, Y_Less, Strickenkid, xeeZ, Ryder, Incognito, mrdrifter oraz Game.");

	ShowPlayerDialog(playerid,31,0,"Autor skryptu",StrinG,"Cofnij","Wyjdz");
	return 1;
}
CMD:pytanie(playerid,cmdtext[]){

	new wiadomosc[128];
	if(sscanf(cmdtext,"s[128]",wiadomosc)){
	    SCM(playerid, -1, ""C_O"/pytanie [pytanie]");
		return 1;
	}

	new tmp[128];
	format(tmp, sizeof(tmp), "{ffe5a1}Wys³a³eœ/aœ pytanie do administracji. Treœæ: {eab171}%s",wiadomosc);
	SCM(playerid, 0xAA3333AA, tmp);

	format(tmp, sizeof(tmp), "{ffe5a1}Pytanie dla administracji od {eab171}%s{ffe5a1}: {eab171}%s", pName[playerid], wiadomosc);
	for(new i=0; i<MAX_PLAYERS; i++)
	{
    if(!IsPlayerConnected(i) || Administrator[i] == 0) continue;
    PlayerPlaySound(playerid, 1132, 0.0, 0.0, 0.0);
	SCM(i, 0xFF0000FF, tmp);
	}
	return 1;
}
CMD:dotacja(playerid)
{
	if(gdot[playerid] == true) return SCM(playerid, -1, ""C_O"Ju¿ otrzyma³eœ dotacjê!");

    gdot[playerid] = true;
	GivePlayerMoney(playerid, 500000);
	SCM(playerid, -1, ""C_O"Otrzyma³eœ "C_B"500 "C_O"tys $ dotacji.");
	return 1;
}
CMD:help(playerid,cmdtext[]){
	#pragma unused cmdtext
    PlayerPlaySound(playerid, 1139, 0.0, 0.0, 0.0);
	ShowPlayerDialog(playerid,30,2,"{3FBAFC}Polski TOP Serwer",""C_O"Komendy Gracza\n"C_B"Komendy Vipa\n"C_O"Komendy Admina \n"C_B"Komendy Gangu \n"C_O"Regulamin Serwera \n"C_B"Konto VIP \n{A40000}Autor GameMode","Dalej","Wyjdz");

	return 1;
}

CMD:privcar(playerid)
{
	if(MaPrivCar[playerid] == true) return SCM(playerid, -1, ""C_O"Masz ju¿ prywatny pojazd!");
	if(GetPlayerScore(playerid) < 7501) return SCM(playerid, -1, ""czat" "C_O"Musisz mieæ "C_B"7500 "C_O"expa by kupiæ prywatny pojazd!");
	PlayerPlaySound(playerid, 1139, 0.0, 0.0, 0.0);
	ShowPlayerDialog(playerid, 15, DIALOG_STYLE_LIST, "Prywatny pojazd", "Kup pojazd", "Wybierz", "Zamknij");
	return 1;
}
CMD:pojazd(playerid)
{
	if(MaPrivCar[playerid] == false) return SCM(playerid, -1, ""czat" "C_O"Nie masz prywatnego pojazdu!");
    PlayerPlaySound(playerid, 1139, 0.0, 0.0, 0.0);
	ShowPlayerDialog(playerid, 22, DIALOG_STYLE_LIST, "Twój prywatny pojazd", ""C_O"Teleportuj\n"C_B"Zmieñ model", "Wybierz", "Zamknij");
	return 1;
}
CMD:pomoc(playerid,cmdtext[]){
	cmd_help(playerid,cmdtext);
	return 1;
}
CMD:cmd(playerid,cmdtext[]){
	cmd_help(playerid,cmdtext);
	return 1;
}
CMD:nos(playerid, params[]) return cmd_nitro(playerid, params);
CMD:nitro(playerid, params[])
{
	Dialog(playerid, 1240, DIALOG_LIST, "Oszczêdne nitro\nNitro ci¹g³e\nNitro z opcj¹ ON/OFF\nWy³¹czone", "Wybierz", "Anuluj");
	return 1;
}
CMD:zalewy(playerid,cmdtext[])
{
	new ZalewyString[512];
	PlayerPlaySound(playerid, 1139, 0.0, 0.0, 0.0);
	strcat(ZalewyString,"Zalew nr: 1\nZalew nr: 2\nZalew nr: 3\nZalew nr: 4\nZalew nr: 5\nZalew nr: 6\nZalew nr: 7\nZalew nr: 8\nZalew nr: 9\n");
	ShowPlayerDialog(playerid, 111, DIALOG_STYLE_LIST,"Zalewy do lowienia ryb", ZalewyString, "Wybierz", "Wyjdz");
	return 1;
	#pragma unused cmdtext
}
CMD:pobject(playerid, params[])
{
	if(!IsPlayerInAnyVehicle(playerid)) return SCM(playerid, -1, "Musisz byæ w pojedzie!");

	new v_obj_name[13] = {560, 522, 562, 411, 470, 539, 587, 451, 540, 482, 549, 535, 431};
	format(bstrx, sizeof bstrx, ""C_O"\nNie ma doczepianych obiektów do tego pojazdu!\n\nTa opcja jest dostêpna dla:\n\n");
	for(new i; i < 13; i++)
	{
		format(bstrx, sizeof bstrx, "%s%s\n", bstrx, GetVehicleName(v_obj_name[i]));
	}
	if(TuneObjectVehicle(GetPlayerVehicleID(playerid)))
	{
	    InfoBox(playerid, ""C_O"\nObiekty zosta³y doczepione!");
	}else InfoBox(playerid, bstrx);
	return 1;
}

CMD:portfel(playerid)
{
    PlayerPlaySound(playerid, 1139, 0.0, 0.0, 0.0);
	format(bstrx, sizeof(bstrx), "{33CCFF}Us³uga chwilowo nie dostêpna!");
	InfoBox(playerid, bstrx);
	return 1;
}
CMD:przelewexp(playerid, params[])
{
	new respekt, player;
	if(sscanf(params, "dd", player, respekt))
	    return SCM(playerid, -1, "/przelewexp [ID] [exp]");

	if(!IsPlayerConnected(player))
	    return SCM(playerid, -1, "Nieprawidlowe ID gracza");

	if(respekt < 0) {
		SCM(playerid, -1, "Musisz przelaæ minimum 1 exp.");
		return 1;
	}
	GivePlayerScore(player, respekt);
	GivePlayerScore(playerid, -respekt);
	format(strx, sizeof strx, "{FFAA00}Gracz {DDDDDD}%s{FFAA00} da³ Ci {DDDDDD}%d {FFAA00}exp'a!", pName[playerid], respekt);
	SCM(player, -1, strx);
	format(strx, sizeof strx, "{FFAA00}Da³eœ {DDDDDD}%d {FFAA00}exp'a graczowi {DDDDDD}%s{FFAA00}!", respekt, pName[player]);
	SCM(playerid, -1, strx);
	return 1;
}

CMD:alogin(playerid, cmdtext[])
{
	new ahaslo[22],
	    string2[330];
    GetPlayerName(playerid, pName[playerid], MAX_PLAYER_NAME);
	if(sscanf(cmdtext, "s[20]", ahaslo)) return SCM(playerid, -1, ""C_O"/alogin "C_B"<has³o>");

	if(Administrator[playerid] > 0) return SCM(playerid, -1, ""C_O"Ju¿ jesteœ zalogowany jako "C_B"Administrator!");
	if(!AdministratorLevel[playerid]) return SCM(playerid, -1, ""C_O"Nie ma ciê na liœcie "C_B"administratorów!");
	if(strcmp(ahaslo, ADMIN_PASSWORD, false) !=0)  return SCM(playerid, -1, ""C_O"Nieprawid³owe "C_B"has³o.");

    Administrator[playerid] = AdministratorLevel[playerid];
	Admins_Online++;
	SoundForAll(1133);
	format(string2, sizeof(string2), ""C_B"%s "C_O"zalogowa³(a) siê jako administrator poziom: "C_B"%d", pName[playerid], AdministratorLevel[playerid]);
	SCMToAll(0xE10000FF, string2);
	return 1;
}

CMD:cb(playerid, params[])
{
	if(!IsPlayerInAnyVehicle(playerid))
	    return SCM(playerid, -1, ""C_O"Musisz byæ w pojeŸdzie!");

	if(isnull(params))
	    return SCM(playerid, -1, ""C_B"/cb "C_O"[text]");

	new mstr[130];
	format(mstr, 130, "> %s"C_B": %s", pName[playerid], params);
	pLoop(i)
	{
	    if(IsPlayerConnected(i) && IsPlayerInAnyVehicle(i))
	    {
	        SCM(i, -1, mstr);
	    }
	}
	return 1;
}

CMD:serwer(playerid, params[])
{
	new sec = floatround(GetTickCount()/1000), m, h;
	while (sec >= 60*60)
	{
		h++;
		sec -= 60*60;
	}
	while (sec >= 60)
	{
		m++;
		sec -= 60;
	}
	new bans,kicks,rekord,privatemsg, vips,visit,players,los,walizek,figurka,
		winrace,reaction,mathematics,rWG,rCH,rSS,rTW,rDD,rHY,cWG,cCH,cSS,cHY,cTW,cDD,pvp;

	new resc[32];
	mysql_query("SELECT `value` FROM `stats");
	mysql_store_result();
	new i;
	while(mysql_fetch_row(resc, "|"))
	{
		switch(i)
		{
			case 0: bans = strval(resc);
			case 1: kicks = strval(resc);
			case 2: rekord = strval(resc);
			case 3: privatemsg = strval(resc);
			case 4: vips = strval(resc);
			case 5: visit = strval(resc);
			case 6: players = strval(resc);
			case 7: los = strval(resc);
			case 8: walizek = strval(resc);
			case 9: figurka = strval(resc);
			case 10: winrace = strval(resc);
			case 11: reaction = strval(resc);
			case 12 : mathematics = strval(resc);
			case 13: rWG = strval(resc);
			case 14: rCH = strval(resc);
			case 15: rSS = strval(resc);
			case 16: rTW = strval(resc);
			case 17: rDD = strval(resc);
			case 18: rHY = strval(resc);
			case 19: cWG = strval(resc);
			case 20: cCH = strval(resc);
			case 21: cSS = strval(resc);
			case 22: cHY = strval(resc);
			case 23: cTW = strval(resc);
			case 24: cDD = strval(resc);
			case 25: pvp = strval(resc);
		}
		i++;
	}
	mysql_fetch_row(resc, "|");
	mysql_free_result();
	sscanf(resc, "p<|>iiiiiiiiiiiiiiiiiiiiiiiii", bans,kicks,rekord,privatemsg,vips,visit,players,los,walizek,figurka,winrace,reaction,
							mathematics,rWG,rCH,rSS,rTW,rDD,rHY,cWG,cCH,cSS,cHY,cTW,cDD,pvp);
	bstrx = "{00AAFF}Statystyki serwera:\n\n";
    format(bstrx, sizeof bstrx, "%s"C_O"Uptime: "C_B"%d:%02d:%02d\n",bstrx, h,m,sec);
    format(bstrx, sizeof bstrx, "%s"C_O"£¹cznie banów: "C_B"%d\n",bstrx,bans);
	format(bstrx, sizeof bstrx, "%s"C_O"£¹cznie kicków: "C_B"%d\n",bstrx,kicks);
	format(bstrx, sizeof bstrx, "%s"C_O"Rekord graczy: "C_B"%d\n",bstrx,rekord);
	format(bstrx, sizeof bstrx, "%s"C_O"Wys³anych PM'ów: "C_B"%d\n\n",bstrx,privatemsg);
	format(bstrx, sizeof bstrx, "%s"C_O"Kupionych kont VIP ogó³em: "C_B"%d\n\n",bstrx,vips);
	format(bstrx, sizeof bstrx, "%s"C_O"£¹cznie wizyt: "C_B"%d\n",bstrx,visit);
	format(bstrx, sizeof bstrx, "%s"C_O"Zarejestrowanych graczy: "C_B"%d\n\n",bstrx,players);
	format(bstrx, sizeof bstrx, "%s"C_O"Losowañ: "C_B"%d\n\n",bstrx,los);
	format(bstrx, sizeof bstrx, "%s"C_O"Znalezionych walizek: "C_B"%d\n",bstrx,walizek);
	format(bstrx, sizeof bstrx, "%s"C_O"Znalezionych figurek: "C_B"%d\n\n",bstrx,figurka);
	format(bstrx, sizeof bstrx, "%s"C_O"Wygranych wyœcigów: "C_B"%d\n",bstrx,winrace);
	format(bstrx, sizeof bstrx, "%s"C_O"Wygrane testy reakcji: "C_B"%d\n\n",bstrx,reaction);
	format(bstrx, sizeof bstrx, "%s"C_O"Wygrane testy matematyczne: "C_B"%d\n\n",bstrx,mathematics);
	format(bstrx, sizeof bstrx, "%s"C_O"Rekord graczy na WG: "C_B"%d\n",bstrx,rWG);
	format(bstrx, sizeof bstrx, "%s"C_O"Rekord graczy na Chowanym: "C_B"%d\n",bstrx,rCH);
	format(bstrx, sizeof bstrx, "%s"C_O"Rekord graczy na Skokach: "C_B"%d\n",bstrx,rSS);
	format(bstrx, sizeof bstrx, "%s"C_O"Rekord graczy na Tower: "C_B"%d\n",bstrx,rTW);
	format(bstrx, sizeof bstrx, "%s"C_O"Rekord graczy na Derbach: "C_B"%d\n",bstrx,rDD);
	format(bstrx, sizeof bstrx, "%s"C_O"Rekord graczy na Hay: "C_B"%d\n",bstrx,rHY);
	format(bstrx, sizeof bstrx, "%s"C_O"£¹cznie zabaw 'Wojny Gangów': "C_B"%d\n",bstrx,cWG);
	format(bstrx, sizeof bstrx, "%s"C_O"£¹cznie zabaw 'Chowany': "C_B"%d\n",bstrx,cCH);
	format(bstrx, sizeof bstrx, "%s"C_O"£¹cznie zabaw 'Skoki Spadochronowe': "C_B"%d\n",bstrx,cSS);
	format(bstrx, sizeof bstrx, "%s"C_O"£¹cznie zabaw 'Hay': "C_B"%d\n",bstrx,cHY);
	format(bstrx, sizeof bstrx, "%s"C_O"£¹cznie zabaw 'Tower': "C_B"%d\n",bstrx,cTW);
	format(bstrx, sizeof bstrx, "%s"C_O"£¹cznie zabaw 'Derby': "C_B"%d\n",bstrx,cDD);
	format(bstrx, sizeof bstrx, "%s"C_O"Rozegranych PvP: "C_B"%d\n",bstrx,pvp);
	InfoBox(playerid, bstrx);

	return 1;
}

CMD:solo(playerid, params[]) return cmd_duel(playerid, params);
CMD:duel(playerid, params[])
{
    if(GetPlayerVirtualWorld(playerid) != 0)
	    return SCM(playerid, -1, ""C_O"Nie mo¿esz teraz stan¹æ do walki.");

	if(GetPVarInt(playerid, "pWalka") != -1)
	    return SCM(playerid, -1, ""C_O"Poczekaj poprzednie potwierdzenie walki.");

	new player, weapon1, weapon2, exp;
	if(sscanf(params, "dddd", player, weapon1, weapon2, exp))
		return SCM(playerid, -1, ""C_O"/duel "C_B"[Gracz] [ID Broni 1] [ID Broni 2] [Exp]");

	if(player == playerid)
		return SCM(playerid, -1, ""C_O"Nie mo¿esz wyzwaæ sam siebie!");

	if(GetPlayerScore(playerid) < exp && exp != 0)
	    return SCM(playerid, -1, ""C_O"Nie masz tyle "C_B"exp!");

	if(exp < 0 || exp > 50)
        return SCM(playerid, -1, ""C_O"Exp w granicach "C_B"0-50");

	if(!IsPlayerConnected(player))
	    return SCM(playerid, -1, ""C_O"Ten gracz nie jest po³¹czony!");

	if(IsAllowWeapon(weapon1) == 0 || IsAllowWeapon(weapon2) == 0)
	    return SCM(playerid, -1, ""C_O"Nieprawidlowa bron!");

	if(GetPlayerVirtualWorld(player) != 0 || GetPVarInt(player, "pWalka") != -1)
	    return SCM(playerid, -1, ""C_O"Ten gracz nie moze teraz stan¹æ do walki.");

	format(strx, sizeof strx, ""C_O"Gracz "C_B"%s "C_O"wyzwa³ Cie na pojedynek o "C_B"%dexp", pName[playerid], exp);
	SCM(player, -1, strx);
	new wname[2][30];
	GetWeaponName(weapon1, wname[0], 30);
	GetWeaponName(weapon2, wname[1], 30);
	format(strx, sizeof strx,""C_O"Bronie: "C_B"%s i %s "C_O"Wpisz "C_B"/accept"C_O", aby zaakceptowaæ wyzwanie!",wname[0],wname[1]);
	SCM(player, -1, strx);

	SetPVarInt(player, "pWalka", playerid);
	SetPVarInt(playerid, "pDWeap1", weapon1);
	SetPVarInt(playerid, "pDWeap2", weapon2);
	SetPVarInt(playerid, "pDExp", exp);
	SetPVarInt(playerid, "pWalka", player);

	SetTimerEx("DualTimeout", 15000, 0, "dd", playerid, player);
	format(strx, sizeof strx, ""C_O"Wyzwa³eœ "C_B"%s "C_O"na pojedynek!", pName[player]);
	SCM(playerid, -1, strx);
	return 1;
}

new duelpos;
CMD:accept(playerid, params[])
{
	if(GetPVarInt(playerid, "pWalka") == -1)
	    return SCM(playerid, -1, ""C_O"Nie jesteœ zaproszony na walke!");

	new i = GetPVarInt(playerid, "pWalka");
	if(IsPlayerAFK(i) != 0 || pInFun[i] == 1 || GetPlayerVirtualWorld(i) != 0 || GetPlayerVirtualWorld(playerid) != 0)
	    return SCM(playerid, -1, ""C_B"Niestety, "C_O"ale zaproszenie jest nie wa¿ne."), SetPVarInt(playerid, "pWalka", -1);

	pInFun[i] = 1;
	pInFun[playerid] = 1;

	new vw = 150 + duelpos;
	duelpos++;
	if(duelpos == 10) duelpos = 0;

	SetPlayerVirtualWorld(playerid, vw);
	SetPlayerInterior(playerid, 0);
	SetPlayerPos(playerid, -225.29, 1829.26, 2025.50);
	SetPlayerFacingAngle(playerid, -90.0);
	SetCameraBehindPlayer(playerid);
	SetPVarInt(playerid, "Walczy", 1);
	ResetPlayerWeapons(playerid);
	GivePlayerWeapon(playerid, GetPVarInt(i, "pDWeap1"), 300);
    GivePlayerWeapon(playerid, GetPVarInt(i, "pDWeap2"), 300);
	SetPlayerHealth(playerid, 100.0);
	SetPlayerArmour(playerid, 100.0);
	SetPlayerTeam(playerid, NO_TEAM);
	SetPlayerVirtualWorld(i, vw);
	SetPlayerInterior(i, 0);
	SetPlayerPos(i, -156.43, 1826.91, 2025.50);
	SetPlayerFacingAngle(i, 90.0);
	SetCameraBehindPlayer(i);
	SetPVarInt(i, "Walczy", 1);
	ResetPlayerWeapons(i);
	GivePlayerWeapon(i, GetPVarInt(i, "pDWeap1"), 300);
    GivePlayerWeapon(i, GetPVarInt(i, "pDWeap2"), 300);
    SetPlayerHealth(i, 100.0);
    SetPlayerArmour(i, 100.0);
    SetPlayerTeam(i, NO_TEAM);

    SetPVarInt(playerid, "pDExp", GetPVarInt(i, "pDExp"));
	TogglePlayerControllable(i, 0);
	TogglePlayerControllable(playerid, 0);

	format(strx, sizeof strx, "~r~~h~%d", 3);
    ShowGameDraw(i, strx, 1000);
    ShowGameDraw(playerid, strx, 100);
    SetTimerEx("DualOdlicz", 1000, 0, "ddd", i, playerid, 2);

   	new Float:flo[3];
	GetPlayerPos(i, flo[0],flo[1],flo[2]);
	SetPVarFloat(i, "floX", flo[0]);
	SetPVarFloat(i, "floY", flo[1]);
	SetPVarFloat(i, "floZ", flo[2]);
	SetPVarInt(i, "floInt", GetPlayerInterior(i));
	SetPVarInt(i, "floVW", 0);

	GetPlayerPos(playerid, flo[0],flo[1],flo[2]);
	SetPVarFloat(playerid, "floX", flo[0]);
	SetPVarFloat(playerid, "floY", flo[1]);
	SetPVarFloat(playerid, "floZ", flo[2]);
	SetPVarInt(playerid, "floInt", GetPlayerInterior(playerid));
	SetPVarInt(playerid, "floVW", 0);

	mysql_query("UPDATE `stats` SET `value` = `value` + 1 WHERE `name` = 'pvp'");
	return 1;
}

CMD:zmiennick(playerid, params[])
{
	format(strx, sizeof strx, "SELECT `nickchange` FROM `players` WHERE `nick` = '%s'", pName[playerid]);
	mysql_query(strx);
	mysql_store_result();
	new changenick[11];
	mysql_fetch_field("nickchange", changenick);
	mysql_free_result();

	if(strval(changenick) > gettime())
	    return SCM(playerid, -1, ""C_B"Nick mo¿esz zmieniaæ tylko co tydzieñ!");

	if(isnull(params)) return SCM(playerid, -1, ""C_O"U¿yj "C_B"/zmiennick"C_O" [nick]");

	if(strlen(params) > 20) return SCM(playerid, -1, ""C_O"Podany "C_B"nick "C_O"jest zbyt d³ugi!");

	if(strlen(params) <  4) return SCM(playerid, -1, ""C_O"Podany "C_B"nick "C_O"jest zbyt krótki!");

	new validchar[] = {';', ':', ''', '"', '{', '}', '!','#','%','^','&','*','(',')','~','`','/','\\','?','+'};

	for(new i; i < sizeof validchar; i++)
	{
		if(strfind(params, validchar[i], true) != -1) return SCM(playerid, -1, ""C_O"Nick zawiera nieprawid³owe znaki!");
	}

    format(strx, sizeof strx, "SELECT * FROM `players` WHERE `nick` = '%s'", params);
	mysql_query(strx);
	mysql_store_result();

	if(!mysql_num_rows())
	{
		mysql_free_result();
       	format(strx, sizeof strx, "UPDATE `players` SET `nick` = '%s', `nickchange` = '%d' WHERE `nick` = '%s'", params, gettime() + 604800, pName[playerid]);
		mysql_query(strx);

		format(strx, sizeof strx, "UPDATE `house` SET `owner` = '%s' WHERE `owner` = '%s'", params, pName[playerid]);
		mysql_query(strx);

		format(strx, sizeof strx, "UPDATE `race_record` SET `nick` = '%s' WHERE `nick` = '%s'", params, pName[playerid]);
		mysql_query(strx);

		format(pName[playerid], MAX_PLAYER_NAME, "%s", params);
		SetPVarInt(playerid, "ChangeNick", 1);
		SetPlayerName(playerid, params);

	}else SCM(playerid, 0xFF0000FF, ""C_O"Ten "C_B"nick "C_O"jest zajêty!"), mysql_free_result();
    return 1;
}
CMD:rec(playerid, params[])
{
	if(GetPVarInt(playerid, "rec") == 0)
	{
	    for(new i; i < 2048; i++)
		{
		    if(Text:i == Text:INVALID_TEXT_DRAW) continue;
		    TD_Hide(playerid, Text:i);
		}
		pLoop(i)
		{
			ShowPlayerNameTagForPlayer(playerid, i, 0);
		}
	    SetPVarInt(playerid, "rec", 1);

	}else{
        TD_Show(playerid, Zegar[0]);
        TD_Show(playerid, Zegar[1]);
        TD_Show(playerid, TDArenkiBox);
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
        TD_Show(playerid, TDArenki[0]);
        TD_Show(playerid, TDArenki[1]);
        TD_Show(playerid, TDArenki[2]);
        TD_Show(playerid, TDArenki[3]);
        TD_Show(playerid, TDArenki[4]);
     	TD_Show(playerid, TDPolecamy);
		TD_Show(playerid, ZegarDraw);


		if(walizka[2] == 1)
		{
		    TD_Show(playerid, WalizkaDraw[0]);
		    TextDrawShowForAll(WalizkaDraw[1]);
		}

		pLoop(i)
		{
			ShowPlayerNameTagForPlayer(playerid, i, 1);
		}
	    SetPVarInt(playerid, "rec", 0);
	}
	return 1;
}

CMD:hacmd(playerid, params[])
{
	if(Administrator[playerid] < 4) return 0;

	InfoBox(playerid, "/nazwaserwera /c_ss /offwg /offhay /offdd /offch /offtw /offss\n/console /setvw /emulate /p_figurka /query /teleto\n/newtele /c_race /p_race /out_dom /tp_dom /c_dom\n");
	return 1;
}

CMD:c_ss(playerid, params[])
{
	if(Administrator[playerid] < 4)
	    return 0;

	new type = strval(params);
	if(params[0] != '0' && params[0] != '1') return SCM(playerid, -1, "/c_ss [0 = TP / 1 = CP]");

	if(type == 0)
	{
	    new Float:x,Float:y,Float:z;
	    GetPlayerPos(playerid, x,y,z);
		SetPVarFloat(playerid, "ss_x", x);
		SetPVarFloat(playerid, "ss_y", y);
		SetPVarFloat(playerid, "ss_z", z);
	}else{
	    new mstr[300];
   	    new Float:x,Float:y,Float:z;
	    GetPlayerPos(playerid, x,y,z);
	    format(mstr, 300, "INSERT INTO `ss_areny` (`x`,`y`,`z`,`cpx`,`cpy`,`cpz`) VALUES ('%f','%f','%f','%f','%f','%f')",
	    	GetPVarFloat(playerid, "ss_x"), GetPVarFloat(playerid, "ss_y"), GetPVarFloat(playerid, "ss_z"), x,y,z);
		mysql_query(mstr);
	}
	SCM(playerid, -1, "Done");
	return 1;
}
CMD:zmienhaslo(playerid, params[])
{
	if(GetPVarInt(playerid, "Logged") == 0) return 1;

	Dialog(playerid, 2, DIALOG_INPUT, ""C_O"\nWpisz swoje nowe has³o:\n", "Zmieñ", "Anuluj");
	return 1;
}

CMD:zw(playerid, params[])
{
	if(pAFK[playerid] != 0)
	    return SCM(playerid, -1, ""C_O"Wpisz "C_B"/jj"C_O", aby aktywowaæ dzia³ania na serwerze.");

	if(IsPlayerFight(playerid))
	    return SCM(playerid, -1, ""C_O"Nie mo¿esz byæ "C_B"ZW "C_O"podczas walki!");

	new mstr[40];
	if(strlen(pName[playerid]) < 15)
	{
		format(mstr, 40, "[AFK] %s", pName[playerid]);
		SetPlayerName(playerid, mstr);
	}
	TogglePlayerControllable(playerid, false);
	pAFK[playerid] = 1;
	SCM(playerid, -1, ""C_O"Jesteœ AFK. Aby ponownie móc graæ wpisz: "C_B"/jj");
	format(strx, sizeof strx, ""C_B"%s "C_O"zaraz wraca!", pName[playerid]);
	SCMToAll(-1, strx);
	return 1;
}

CMD:naj(playerid, params[])
{
    if(!CMD_Block[playerid]){
        CMD_Block[playerid] = true;
        SetTimerEx("CMD_UnLock", 5000, 0,"i",playerid);
	    format(strx, sizeof strx, ""C_B"%s "C_O"Uwa¿a, ¿e Polski TOP Serwer jest najlepszy!", pName[playerid]);
	    SCMToAll(-1, strx);
	}
	return 1;
}

CMD:witam(playerid, params[])
{

    if(!CMD_Block[playerid]){
        CMD_Block[playerid] = true;
        SetTimerEx("CMD_UnLock", 5000, 0,"i",playerid);
	    format(strx, sizeof strx, ""C_B"%s "C_O"wita siê ze wszystkimi!", pName[playerid]);
	    SCMToAll(-1, strx);
	}
	return 1;
}

CMD:siema(playerid, params[])
{
    if(!CMD_Block[playerid]){
        CMD_Block[playerid] = true;
        SetTimerEx("CMD_UnLock", 5000, 0,"i",playerid);
	    format(strx, sizeof strx, ""C_B"%s "C_O"mówi siema!", pName[playerid]);
	    SCMToAll(-1, strx);
	}
	return 1;
}

CMD:elo(playerid, params[])
{
    if(!CMD_Block[playerid]){
        CMD_Block[playerid] = true;
        SetTimerEx("CMD_UnLock", 5000, 0,"i",playerid);
	    format(strx, sizeof strx, ""C_B"%s "C_O"mówi elo!", pName[playerid]);
	    SCMToAll(-1, strx);
	}
	return 1;
}

CMD:jj(playerid, params[])
{
	if(pAFK[playerid] == 0)
		return 1;

	TogglePlayerControllable(playerid, true);
	pAFK[playerid] = 0;
	SCM(playerid, -1, ""C_O"Mo¿esz juz graæ dalej.");
	format(strx, sizeof strx, ""C_B"%s "C_O"ju¿ jest!", pName[playerid]);
	SCMToAll(-1, strx);
 	SetPlayerName(playerid, pName[playerid]);
	return 1;
}

CMD:top(playerid, params[])
{
	#define MAX_TOPS 9
	new list[MAX_TOPS][] = {"Money","Score", "Visit", "Timeplay", "Kills", "Deads", "Bank", "Truck", "Mandat"};
	new names[MAX_TOPS][] = {"Pieniêdzy", "Exp", "Wizyt", "Przegranych godzin", "Zabójstw", "Œmierci", "Kasy w banku", "Rozwiezionych towarów", "Mandatów"};

	if(isnull(params)) return SCM(playerid, -1, "/top [money/score/visit/timeplay/kills/deads/bank/truck/mandat]");

	new r = -1;
	for(new i; i < MAX_TOPS; i++)
	{
	    if(strcmp(params, list[i], true) == 0) r = i;
	}
	if(r == -1) return SCM(playerid, -1, "/top [money/score/visit/timeplay/kills/deads/bank]");

	format(bstrx, sizeof bstrx, "{00AAFF}Top %s:"C_O"\n\n", names[r]);
	new mstr[160];
	format(mstr, 160, "SELECT `nick`, `%s` FROM `players` ORDER BY `%s` DESC LIMIT 15", list[r],list[r]);
	mysql_query(mstr);
	mysql_store_result();

	new nick[30], value, pos = 1;
	while(mysql_fetch_row(mstr, "|"))
	{
	    sscanf(mstr, "p<|>s[30]d", nick, value);

	    if(r == 3) value = floatround(value / 60);

		if(r == 0 || r == 6)
	    {
		    format(bstrx, sizeof bstrx, "%s%d. %s  -  %d$\n", bstrx, pos, nick, value);
		}else format(bstrx, sizeof bstrx, "%s%d. %s  -  %d\n", bstrx, pos, nick, value);

		pos++;
	}
	mysql_free_result();
	InfoBox(playerid, bstrx);
	return 1;
}
CMD:zabawy(playerid, params[])
{
	format(bstrx, sizeof bstrx, "{33CCFF}Informacje o zabawach:\n\n"C_O"");
	strcat(bstrx, ""C_B"WG"C_O" - Wojny Gangów. Gracze s¹ podzieleni na dwie dru¿yny. Zadaniem jest zabiæ przeciwn¹ dru¿ynê.\n\n");
	strcat(bstrx, ""C_B"CH"C_O" - Chowany. Uczestnicy musz¹ siê ukryæ. Wylosowany jest jeden szukaj¹cy. Wygrywa ten który nie zostanie znaleziony\n\n");
	strcat(bstrx, ""C_B"SS"C_O" - Skoki Spadochronowe. Ka¿dy uczestnik dostaje spadochron i jest teleportowany na du¿¹ wysokoœæ.\n\tZadaniem jest dolecieæ do celu oznaczonego na mapie.\n\n");
	strcat(bstrx, ""C_B"HY"C_O" - Hay/Siano. Gracze s¹ teleportowani na siano. Losowy gracz co parê sekund dostaje broñ,\n\taby zniszczyæ siano pod innnym graczem. Wygrywa ten co nie spadnie\n\n");
    strcat(bstrx, ""C_B"TW"C_O" - Tower/Wie¿a. Pomys³ zaczerpany z gry Ice Tower. Zadaniem ka¿dego gracza jest wydostanie siê z wie¿y.\n\n");
    strcat(bstrx, ""C_B"DD"C_O" - Destruction Derby. Ka¿dy gracz jest w pojeŸdzie. Zadaniem jest zepchaæ innych uczestników do wody.\n");
	InfoBox(playerid, bstrx);
	return 1;
}
CMD:losexp(playerid, params[])
{
	CommandUseBlock(playerid, "losexp", 120000);

	if(GetPlayerMoney(playerid) < 500)
	    return SCM(playerid, -1, ""C_O"Potrzebujesz "C_B"500$, "C_O"aby wzi¹æ udzia³ w losowaniu!");

	new i = random(50) - random(50);
	GivePlayerScore(playerid, i);
	GivePlayerMoney(playerid, -500);

	format(strx, sizeof strx, ""C_O"Gracz "C_B"%s "C_O"wygra³ "C_B"%d "C_O"exp w "C_B"/losexp", pName[playerid], i);
	SCMToAll(-1, strx);
	return 1;
}

CMD:hitman(playerid, params[])
{
	new kasa, player;
	if(sscanf(params, "ud", player, kasa))
	    return SCM(playerid, -1, "U¿yj:"C_B"/hitman [ID] [KWOTA]");

	CommandUseBlock(playerid, "hitman", 15000);

	if(!IsPlayerConnected(player))
	    return SCM(playerid, -1, ""C_O"Nieprawid³owy gracz");

	if(kasa > GetPlayerMoney(playerid) || kasa < 0)
	    return SCM(playerid, -1, ""C_O"Nie masz tyle gotówki!");

	GivePlayerMoney(playerid, kasa * -1);
	SetPVarInt(player, "hitman", GetPVarInt(player, "hitman") + kasa);
	format(strx, sizeof strx, ""C_O"Za zabicie gracza "C_B"%s"C_O" jest nagroda "C_B"%d$", pName[player], GetPVarInt(player, "hitman"));
	SCMToAll(-1, strx);
	return 1;
}
CMD:idzdoon(playerid,cmdtext[])
{
	SendClientMessage(playerid,-1,""C_O"Odblokowa³eœ(aœ) prywatne wiadomoœci do ciebie");
	IdzDo[playerid] = true;
	return 1;
}

CMD:staty(playerid, params[]) return cmd_serwer(playerid, params);

CMD:idzdooff(playerid,cmdtext[])
{
	SendClientMessage(playerid,-1,""C_B"Zablokowa³eœ(aœ) prywatne wiadomoœci do ciebie");
	IdzDo[playerid] = false;
	return 1;
}
CMD:idzdo(playerid,params[])
{
	new id;
	if(isnull(params)) return SCM(playerid, -1,"|Wpisz| /idzdo [id gracza]");
	id = strval(params);
	if(id < 0 || id >= MAX_PLAYERS || !IsPlayerConnected(id)) return SCM(playerid, -1, "•• |Info| Nie ma takiego gracza!");
	if(!IdzDo[id])	return SCM(playerid, -1, "•• |Info|Ten gracz ma zablokowane proœby o teleport do niego");
	if(id == playerid)
		return SCM(playerid, -1, ""C_O"Nie mo¿esz siê teleportowaæ sam siebie!");

	new str[256],name[19];
	GetPlayerName(playerid,name,19);
	format(str,128,"Gracz: %s id: %d chce sie do ciebie teleportowaæ\nCzy zgadzasz sie na to?\nDodatkowe CMD:\n/IdzDoON - wlaczasz teleporty prywatne \n/IdzDoOFF - wylaczasz teleporty prywatne ",name,playerid);
	ShowPlayerDialog(id,566,DIALOG_STYLE_MSGBOX,"Teleport",str,"Akceptuj","Odrzuc");
	SetPVarInt(id,"tpdo",playerid);
	return 1;
}
CMD:clearme(playerid, params[])
{
    for(new i; i< 20; i++) SCM(playerid, -1, " ");

	return 1;
}

CMD:wyscigi(playerid, params[])
{
	bstrx = "";
	mysql_query("SELECT `name` FROM `race_id` ORDER BY `name` ASC");
	mysql_store_result();

	new param[128];
	while(mysql_fetch_row(param))
	{
	    format(bstrx, sizeof bstrx, "%s%s\n", bstrx, param);
	}
	mysql_free_result();

	if(strlen(bstrx) == 0) return SCM(playerid, -1, "{00FF00}B³¹d po³¹czenia z baza danych!");

	Dialog(playerid, 311, DIALOG_LIST, bstrx, "Wybierz", "Anuluj");
	return 1;
}

CMD:raport(playerid, params[]) return cmd_report(playerid, params);
CMD:report(playerid, params[])
{
	new reason[64], id;
	if(sscanf(params, "ds[64]", id, reason))
	    return SCM(playerid, -1, "U¿yj: {00AAFF}/report [ID] [POWÓD]");

	if(!IsPlayerConnected(id))
	    return SCM(playerid, -1, "{DD0000}Gracz o takim ID nie jest po³¹czony!");

	format(bstrx, sizeof bstrx, "\t"C_B"RAPORT!\n\n"C_O"Zg³aszaj¹cy: "C_B"%s [ID:%d]\n"C_O"Oskar¿ony:"C_B" %s [ID:%d]"C_O"\n\nPowód:"C_B" %s\n\n"C_O"Pamiêtaj, aby NIE udostêpniaæ publicznie informacji \"ID X CZYSTY\".",
	                                pName[playerid],playerid,pName[id],id,reason);

	craport++;
	if(craport == 5) craport = 0;

	format(lraport[craport], 128, ""C_O"%s[ID:%d] donosi na "C_B"%s"C_O" [ID:%d] Powód: "C_B"%s", pName[playerid],playerid,pName[id],id, reason);

	new admins;
	pLoop(i)
	{
	    if(Administrator[i])
	    {
			InfoBox(i, bstrx);
			admins++;
	    }
	}
	if(admins == 0)
		return SCM(playerid, -1, ""C_B"Aktualnie nie ma ¿adnego admina na serwerze!");

	SCM(playerid, -1, ""C_O"Zg³oszenie zosta³o wys³ane!");
	return 1;
}

CMD:figurki(playerid, params[])
{
	new count;
	for(new i; i < MAX_FIGUREK; i++)
		if(Figurki_ID[i] != -1)
			count++;

	if(!count)
		return InfoBox(playerid, ""C_O"Aktualnie nie ma rozmieszczonych figurek.");

	format(bstrx, sizeof bstrx, ""C_O"Na mapie ca³ego San Andreas zosta³o aktualnie rozmieszczonych "C_B"%d "C_O"figurek.\n\n", count);
	format(bstrx, sizeof bstrx, "%sZa znalezienie ka¿dej figurki jest nagroda "C_B"%dexp i %d$\n\n"C_O"Figurki mog¹ byæ ukryte w trudno dostêpnych miejscach,\n", bstrx, FIGURKI_PUNKTY, FIGURKI_KASA);
	strcat(bstrx, "tam gdzie ma³o kto zagl¹da lub tam gdzie najmniej siê spodziewacie.\n\n{FF0000}¯yczymy powodzenia!");
	InfoBox(playerid, bstrx);
	return 1;
}

CMD:weapons(playerid, params[]) return cmd_bronie(playerid, params);
CMD:weapon(playerid, params[]) return cmd_bronie(playerid, params);
CMD:bron(playerid, params[]) return cmd_bronie(playerid, params);
CMD:bronie(playerid, params[])
{
	bstrx = "";
	strcat(bstrx, ""C_O"Pancerz "C_B"[2000$]\n"C_O"Colt "C_B"[500$]\n"C_O"Deagle "C_B"[1000$]\n"C_O"Nó¿ "C_B"[500$]\n");
	strcat(bstrx, ""C_O"Granaty "C_B"[1000$]\n"C_O"SawnOff "C_B"[4000$]\n"C_O"Shotgun "C_B"[2000$]\n"C_O"");
	strcat(bstrx, "Combat "C_B"[6000$]\n"C_O"M4 "C_B"[4000$]\n"C_O"AK47 "C_B"[3000$]\n"C_O"Uzi "C_B"[6000$]\n");
	strcat(bstrx, ""C_O"Tec-9 "C_B"[6000$]\n"C_O"MP5 "C_B"[3000$]\n"C_O"Snajperka "C_B"[6000$]\n"C_O"Spadochron "C_B"[1000$]");

 	Dialog(playerid, 20, DIALOG_LIST, bstrx, "Kup", "Zamknij");
	return 1;
}

CMD:styl(playerid, params[])
{
	Dialog(playerid, 1212, DIALOG_LIST, "Normalny\nBoxing\nKungFu\nKneeHead\nGrabKick\nElbow", "Wybierz", "Anuluj");
	return 1;
}

new Odliczanie = 0;
new Float:OdliczPos[3];
CMD:countdown(playerid, params[]) return cmd_odlicz(playerid, params);
CMD:odlicz(playerid, params[])
{
	if(Odliczanie != 0)
	    return SCM(playerid, -1, ""C_O"Poczekaj do zakoñczenia jednego odliczania.");

	if(GetPlayerVirtualWorld(playerid) != 0)
	    return SCM(playerid, -1, ""C_O"Nie mo¿esz teraz rozpocz¹æ odliczania!");

	GetPlayerPos(playerid, OdliczPos[0],OdliczPos[1],OdliczPos[2]);
	format(strx, 128, ""C_O"Gracz "C_B"%s"C_O" rozpocz¹³ odliczanie!", pName[playerid]);
	TextDrawSetString(CountDraw, "~r~~h~5~w~!");
	Odliczanie = 5;
	pLoop(i)
	{
	    if(GetPlayerVirtualWorld(i) == 0 && GetPlayerInterior(i) == 0)
	    {
	        if(IsPlayerInRangeOfPoint(i, 40.0,OdliczPos[0],OdliczPos[1],OdliczPos[2]) == 1)
	        {
	        	SCM(i, -1, strx);
	        	TextDrawShowForPlayer(i, CountDraw);
	        	PlayerPlaySound(i, 1056, 0.0, 0.0, 0.0);
	        }
	    }
	}
	SetTimer("CountDown", 1000, 0);
	return 1;
}
CMD:hp(playerid, params[])
{
	new Float:hp, Float:arm;
	GetPlayerHealth(playerid, hp);
	GetPlayerArmour(playerid, arm);
	format(strx, sizeof strx, ""C_O"¯ycie:"C_B" %.2f"C_O" Pancerz:"C_B" %.2f", hp, arm);
	InfoBox(playerid, strx);
	return 1;
}
CMD:dystans(playerid, params[])
{
    if(isnull(params) || !IsNumeric(params))
	    return SCM(playerid, -1, "/dystans [GraczID]");

	if(!IsPlayerConnected(strval(params)))
	    return SCM(playerid, -1, "Niepoprawne ID gracza!");

	new Float:pos[3];
	GetPlayerPos(playerid, pos[0], pos[1], pos[2]);
	new Float:a = GetPlayerDistanceFromPoint(strval(params),pos[0], pos[1], pos[2]);
	format(bstrx, sizeof bstrx, ""C_O"Gracz "C_B"%s "C_O"jest oddalony od Ciebie o "C_B"%.2f "C_O"metrów!", pName[strval(params)], a);
	InfoBox(playerid, bstrx);
	return 1;
}
CMD:pos(playerid, params[])
{
	new Float:pos[3];
	GetPlayerPos(playerid,pos[0],pos[1],pos[2]);
	format(strx, sizeof strx, ""C_O"Twoja pozycja na mapie to:"C_B" %.2f, %.2f, %.2f",pos[0],pos[1],pos[2]);
	InfoBox(playerid, strx);
	return 1;
}
CMD:losowanie(playerid, params[]) return cmd_los(playerid, params);
CMD:los(playerid, params[])
{
	if(GetPlayerMoney(playerid) < 750)
	    return SCM(playerid, -1, ""C_O"Potrzebujesz "C_B"750$"C_O", aby wylosowaæ sobie nagrodê.");

	CommandUseBlock(playerid, "losowanie", 120000);

	GivePlayerMoney(playerid, -750);
	SCM(playerid, -1, ""C_O"Twoja nagroda zostanie wylosowana za 30 sekund!");
	SetTimerEx("Losowanko", 30000, 0, "d", playerid);
	return 1;
}
CMD:sp(playerid, params[]) return cmd_ptele(playerid, params);
CMD:ptele(playerid, params[])
{
	if(isnull(params) || !IsNumeric(params))
	{
		Dialog(playerid, 1655, DIALOG_LIST, "Wczytaj Teleport\nZapisz Teleport", "Wybierz", "Zamknij");
		return 1;
	}

	if(strval(params) == 0 || strval(params) > 3)
	    return SCM(playerid, -1, "U¿yj: "C_B"/sp [1/2/3]");

	new i = strval(params) - 1;

	if(pPrivTele[playerid][i][0] == 0.0 && pPrivTele[playerid][i][1] == 0.0)
	    return InfoBox(playerid, ""C_O"Ten Slot nie zosta³ jeszcze zapisany!");

	if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER)
	{
		SetPlayerPos(playerid, pPrivTele[playerid][i][0],pPrivTele[playerid][i][1],pPrivTele[playerid][i][2]);
		SetPlayerFacingAngle(playerid,  pPrivTele[playerid][i][3]);
	}else{
	    SetVehiclePos(GetPlayerVehicleID(playerid), pPrivTele[playerid][i][0], pPrivTele[playerid][i][1],pPrivTele[playerid][i][2] + 0.5);
		SetVehicleZAngle(GetPlayerVehicleID(playerid),  pPrivTele[playerid][i][3]);
	}
	return 1;
}
CMD:k(playerid, params[]) return cmd_katapulta(playerid, params);
CMD:katapulta(playerid, params[])
{
	if(!IsPlayerInAnyVehicle(playerid) || NoRampCar(GetPlayerVehicleID(playerid)) == 1)
	    return SCM(playerid, -1, ""C_B"Musisz byæ w samolocie!");

	new Float:vpos[3];
	GetVehiclePos(GetPlayerVehicleID(playerid), vpos[0],vpos[1],vpos[2]);
	SetPlayerPos(playerid, vpos[0],vpos[1],vpos[2] + 5.0);
	GivePlayerWeapon(playerid, 46, 1);
	return 1;
}
CMD:givecash(playerid, params[])
{
	new cash, player;
	if(sscanf(params, "dd", player, cash))
	    return SCM(playerid, -1, "/givecash [ID] [CASH]");

	if(!IsPlayerConnected(player))
	    return SCM(playerid, -1, "Nieprawidlowe ID gracza");

	if(cash < 0 || cash > GetPlayerMoney(playerid))
	    return SCM(playerid, -1, "Nieprawidlowa iloœæ gotowki");

	GivePlayerMoney(player, cash);
	GivePlayerMoney(playerid, -cash);
	format(strx, sizeof strx, "{FFAA00}Gracz {DDDDDD}%s{FFAA00} da³ Ci {DDDDDD}%d${FFAA00}!", pName[playerid], cash);
	SCM(player, -1, strx);
	format(strx, sizeof strx, "{FFAA00}Da³eœ {DDDDDD}%d${FFAA00} kasy graczowi {DDDDDD}%s{FFAA00}!", cash, pName[player]);
	SCM(playerid, -1, strx);
	return 1;
}
new Float:SaveP[3];
CMD:savepos(playerid, params[])
{
	if(GetPlayerInterior(playerid) > 0 || GetPlayerVirtualWorld(playerid) > 0)
	    return SCM(playerid, -1, "{00AAFF}Nie mo¿esz teraz ustawiæ teleportu!");

	CommandUseBlock(playerid, "savepos", 30000);

	GetPlayerPos(playerid,SaveP[0],SaveP[1],SaveP[2]);
	format(strx, sizeof strx, ""C_B"%s"C_O" ustawi³ now¹ pozycjê "C_B"/loadpos", pName[playerid]);
	SCMToAll(-1, strx);
 	return 1;
}
CMD:loadpos(playerid, params[])
{
	if(SaveP[0] == 0.0 && SaveP[0] == 0.0)
	    return SCM(playerid, -1, ""C_O"Nie ustawiono jeszcze ¿adnego miejsca teleportu!");

	SetPlayerPos(playerid,SaveP[0],SaveP[1],SaveP[2]);
	SetPlayerInterior(playerid, 0);
	SetPlayerVirtualWorld(playerid, 0);
	InfoBox(playerid, ""C_O"Teleportowa³eœ siê do zapisanej pozycji");
	return 1;
}
CMD:domek(playerid, params[])
{
	static windaup;
	if(windaup == 0)
	{
	    windaup = 1;
	    MoveDynamicObject(DomekWinda,-2043.8000,257.6000,47.0, 3.5);
	}else{
	    windaup = 0;
	    MoveDynamicObject(DomekWinda,-2043.9000,257.7000,34.7999, 3.5);
	}
	return 1;
}
CMD:lock(playerid, params[])
{
	if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER)
	    return SCM(playerid, -1, "Musisz byæ za kierownic¹ pojazdu!");
	if(vLock[GetPlayerVehicleID(playerid)][0] == 1)
	    return SCM(playerid, -1, "Pojazd jest juz zamkniêty!");

	vLock[GetPlayerVehicleID(playerid)][0] = 1;
	vLock[GetPlayerVehicleID(playerid)][1] = playerid;
	vLock[GetPlayerVehicleID(playerid)][2] = GetTickCount() + 60000;
	SCM(playerid, 0x00AAFFFF, "Pojazd zosta³ zamkniêty.");
	return 1;
}
CMD:unlock(playerid, params[])
{
	if(GetPlayerState(playerid) != PLAYER_STATE_DRIVER)
	    return SCM(playerid, -1, "Musisz byæ za kierownic¹ pojazdu!");

	if(vLock[GetPlayerVehicleID(playerid)][0] == 0)
	    return SCM(playerid, -1, "Pojazd jest juz otwarty!");

	vLock[GetPlayerVehicleID(playerid)][0] = 0;
	vLock[GetPlayerVehicleID(playerid)][1] = INVALID_PLAYER_ID;
	vLock[GetPlayerVehicleID(playerid)][2] = 0;
	SCM(playerid, 0x00AAFFFF, "Pojazd zosta³ otwarty.");
	return 1;
}

CMD:admini(playerid, params[]) return cmd_admins(playerid, params);
CMD:admins(playerid, params[])
{
	new alist[300];
	new acnt;
	for(new i=0; i<MAX_PLAYERS; i++)
	{
	    if(!IsPlayerConnected(i) || Administrator[i] == 0) continue;

	    format(alist, sizeof(alist), "%s%s (%d)\n", alist, pName[i], i);
	    acnt++;
	}
	if(acnt == 0) alist = "Brak administratorów online.\n";

	InfoBox(playerid, alist);
	return 1;
}
CMD:vipy(playerid, params[]) return cmd_vips(playerid, params);
CMD:vips(playerid, params[])
{
    new countvips;
    format(bstrx, sizeof(bstrx), " ");
	pLoop(i)
    {
        if(Vip[i])
        {
			format(bstrx, sizeof(bstrx), "%s\n{00AAFF}%s"C_O" ID: {00EE00}%d", bstrx, pName[i],i);
            countvips++;
		}
    }
    if(countvips == 0)
    {
        InfoBox(playerid, ""C_O"Aktualnie brak VIP'ów online na serwerze.\n\n");
    }else
    {
		format(bstrx, sizeof(bstrx), ""C_O"Konta VIP:\n\n"C_B"%s\n\n"C_O"Razem "C_B"%d "C_O"VIP'ów", bstrx, countvips);
		InfoBox(playerid, bstrx);
    }
	return 1;
}
CMD:skin(playerid, cmdtext[], params[])
{
   new skin;
   if(sscanf(cmdtext,"d",skin)){
        SCM(playerid, -1, "/Skin [ID skina]");
        return 1;
   }
   if(strval(params) < 0 || strval(params) == 74 || strval(params) > 299)
       return SCM(playerid, -1, "Podany skin jest nieprawid³owy!");

   SetPlayerSkin(playerid,skin);
   Skin_User[playerid] = skin;
   new tmp[1000];
   format(tmp, sizeof(tmp), ""C_O"Zmieni³eœ(aœ) sobie skina na id: "C_B"%d"C_O".\nZosta³ on zapisany na sta³e.",skin);
   ShowPlayerDialog(playerid, 78, DIALOG_STYLE_MSGBOX, "Skin", tmp, "Zamknij", "");
   format(strx, sizeof strx, "UPDATE `players` SET `skin` = %d WHERE `nick`= '%s'", Skin_User[playerid], pName[playerid]);
   mysql_query(strx);
   return 1;
}
CMD:ms(playerid, cmdtext[])
{
   format(strx, sizeof strx, "SELECT `skin` FROM `players` WHERE `nick`= '%s'", pName[playerid]);
   mysql_query(strx);
   mysql_store_result();
   Skin_User[playerid] = mysql_fetch_int();
   mysql_free_result();
   if(Skin_User[playerid] > 0) SetPlayerSkin(playerid, Skin_User[playerid]);
	else Skin_User[playerid] = GetPlayerSkin(playerid);

   if(Skin_User[playerid] > 0) SCM(playerid, -1, ""C_O"Skin przywo³any!");
   else SCM(playerid, -1, "C_O""Nie posiadasz w³asnego skina!");
   
   return 1;
}

CMD:radio(playerid,cmdtext[])
{
	PlayerPlaySound(playerid, 1139, 0.0, 0.0, 0.0);
	ShowPlayerDialog(playerid, 192, DIALOG_STYLE_LIST, "{FFFF00}-=| RADIO |=-", ""C_B"Radio Eska\n"C_O"Polski HipHop\n"C_B"HOT 100\n"C_O"Ruro zet\n"C_B"RMF MAXX\n"C_O"Polskie Radio", "Wybierz", "Anuluj");
	SCM(playerid, -1, ""C_B"W³¹czy³eœ Muzyke. "C_O"Je¿eli chcesz wylaczyc muzewpisz "C_B"/stop");
	return 1;
}
CMD:stop(playerid,cmdtext[])
{
	StopAudioStreamForPlayer(playerid);
    SCM(playerid, -1, ""C_B"Wyl¹czyleœ muzyke "C_O"je¿eli chcesz znowu pos³uchaæ dobrych nut wpisz "C_B"/radio");
	return 1;
}


CMD:parachute(playerid, params[]) return cmd_spadochron(playerid, params);
CMD:spadochron(playerid, params[])
{
	GivePlayerWeapon(playerid, 46, 1);
	return 1;
}
CMD:forum(playerid, params[]) return cmd_www(playerid, params);
CMD:strona(playerid, params[]) return cmd_www(playerid, params);
CMD:www(playerid, params[])
{
	InfoBox(playerid, ""C_O"Adres forum to {00AAFF}www.TOP.xaa.pl\n\nZarejestruj siê ju¿ dziœ!");
	return 1;
}
CMD:neon(playerid, params[])
{
	if(!IsPlayerInAnyVehicle(playerid)) return SCM(playerid, -1, "Musisz byæ w pojedzie!");

  	ShowPlayerDialog(playerid, 8131, 2, "Neon","Ciemny niebieski\nCzerwony\nZielony\nBia³y\nFioletowy\n¯ó³ty\nB³êkitny\nJasnoniebieski\nRó¿owy\nPomarañczowy\nJasnozielony\nJasno¿ó³ty\n{FF0000}Usuñ neon", "Wybierz", "Anuluj");
	return 1;
}
CMD:dzien(playerid, params[])
{
	SetPlayerTime(playerid, 13, 0);
	return 1;
}
CMD:noc(playerid, params[])
{
	SetPlayerTime(playerid, 2, 0);
	return 1;
}

CMD:l(playerid, params[])
{
	if(isnull(params))
	    return SCM(playerid, -1, ""C_B"/l "C_O"[text]");
	    
 	new max_litery = strlen(params);
	if(max_litery > 90) {
		return SCM(playerid,-1,""C_O"Tekst nie mo¿e przekraczaæ "C_B"90 "C_O"znaków!");	}

	new Float:pos[3];
	GetPlayerPos(playerid, pos[0],pos[1],pos[2]);
	format(strx, sizeof(strx), ""C_O"[LocalChat] "C_B"%s (%d): %s",pName[playerid], playerid, params);
	pLoop(i)
	{
	    if(GetPlayerVirtualWorld(playerid) == GetPlayerVirtualWorld(i) && IsPlayerInRangeOfPoint(i, 20.0,pos[0],pos[1],pos[2]))
	    {
	        SCM(i, -1, strx);
	    }
	}
	return 1;
}

CMD:rsp(playerid, params[]) return cmd_flo(playerid, params);
CMD:flo(playerid, params[])
{
	if(GetPlayerInterior(playerid) != 0) return 1;

	if(IsPlayerInAnyVehicle(playerid))
	    return SCM(playerid, -1, "{FF0000}Najpierw wyjdŸ z pojazdu!");

	new Float:flo[3];
	GetPlayerPos(playerid, flo[0],flo[1],flo[2]);
	SetPVarFloat(playerid, "floX", flo[0]);
	SetPVarFloat(playerid, "floY", flo[1]);
	SetPVarFloat(playerid, "floZ", flo[2]);
	SetPVarInt(playerid, "floInt", 2);
	SpawnPlayer(playerid);
	return 1;
}
CMD:bank(playerid, params[])
{
    PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);
	if(IsPlayerInRangeOfPoint(playerid, 5.0,2479.6999511719, -1686.9000244141,13.3) == 0
       && IsPlayerInRangeOfPoint(playerid, 5.0,2116.1999511719, 947.0, 10.7) == 0
	   && IsPlayerInRangeOfPoint(playerid, 5.0,-2032.3000488281, 165.5, 28.7) == 0 || GetPlayerInterior(playerid) != 0 || GetPlayerVirtualWorld(playerid) != 0)
		return SCM(playerid, -1, ""C_O"Musisz byæ przy "C_B"bankomacie!");

	TogglePlayerControllable(playerid, 0);
    Dialog(playerid, 232, DIALOG_LIST, "Stan konta\nWp³aæ\nWyp³aæ\nWp³aæ wszystko\nWyp³aæ wszystko\n", "Wybierz", "Zamknij");
	return 1;
}
CMD:auta(playerid, params[]) return cmd_pojazdy(playerid, params);
CMD:vehicles(playerid, params[]) return cmd_pojazdy(playerid, params);
CMD:cars(playerid, params[]) return cmd_pojazdy(playerid, params);
CMD:pojazdy(playerid,cmdtext[])
{
    PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);
	ShowPlayerDialog(playerid, 400, DIALOG_STYLE_LIST, "Wybierz typ pojazdu", "× Samochody \n× Jednoslady \n× Lodzie\n× Samoloty", "Dalej", "Anuluj");
	return 1;
}
CMD:ramp(playerid, params[]) return cmd_rampa(playerid, params);
CMD:rampy(playerid, params[]) return cmd_rampa(playerid, params);
CMD:rampa(playerid, params[])
{
    PlayerPlaySound(playerid, 1085, 0.0, 0.0, 0.0);
	Dialog(playerid, 2565, DIALOG_LIST, "Wybierz typ\nWylacz/Wlacz", "Wybierz", "Anuluj");
	return 1;
}

CMD:veh(playerid, params[]) return cmd_v(playerid, params);
CMD:spawn(playerid, params[]) return cmd_v(playerid, params);
CMD:v(playerid,params[])
{
	if(GetPlayerInterior(playerid) != 0)
	    return SCM(playerid, 0x00AAFFFF, "Aby zespawnowaæ pojazd wyjdŸ z budynku!");

	if(IsPlayerFight(playerid) == 1)
	{
	    format(strx, sizeof strx, "* "C_O"Najpierw dokoñcz walke z "C_B"%s", pName[pAntyTele[playerid][0]]);
		SCM(playerid, -1, strx);
		return 1;
	}

	if(strlen(params) < 3)
		return SCM(playerid, 0x00AAFFFF, ""C_O"Wpisz: "C_B"/spawn "C_O"[nazwa pojazdu/modelid]");

    if(!IsNumeric(params) && GetVehicleModelIdByName(params) == 0)
		return SCM(playerid, 0x00AAFFFF, ""C_O"Z³a nazwa lub model pojazdu");

	if(GetPlayerVirtualWorld(playerid) != 0)
	    return SCM(playerid, -1, ""C_B"Nie mo¿esz tutaj zespawnowaæ pojazdu!");

   	CommandUseBlock(playerid,"spawn",30000);

    new	vehicleid, Float:x,	Float:y, Float:z, Float:angle;
    GetPlayerPos(playerid, x, y, z);
    GetPlayerFacingAngle(playerid, angle);

	if(!IsNumeric(params))
	{
	    vehicleid = CreateVehicle(GetVehicleModelIdByName(params), x, y, ( z + 1 ), angle, random(200), random(200), 60);
	}else{

		if(strval(params) > 400 && strval(params) < 611)
		{
			vehicleid = CreateVehicle(strval(params), x, y, ( z + 1 ), angle, random(200), random(200), 60);
		}else{
			SCM(playerid, 0x00AAFFFF, ""C_B"Z³y model pojazdu");
		    return 1;
		}
	}

	if(GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
	{
		if(VehicleCreated[GetPlayerVehicleID(playerid)] == 1)
		{
		    DestroyVehicle(GetPlayerVehicleID(playerid));
		    VehicleCreated[GetPlayerVehicleID(playerid)] = 0;
		}else SetVehicleToRespawn(GetPlayerVehicleID(playerid));
	}
	if(Vip[playerid])
	{
	    SetVehicleHealth(vehicleid, 1150.0);
	}
    PutPlayerInVehicle(playerid, vehicleid, 0);
	VehicleCreated[vehicleid] = 1;
    GivePlayerMoney(playerid, -5000);
    pVehicle[playerid] = vehicleid;

	new namescars[300];
    format(namescars, sizeof(namescars), "~w~(~r~Pojazd~w~):~g~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
    return 1;
}

CMD:f(playerid, params[]) return cmd_flip(playerid, params);
CMD:flip(playerid, params[])
{
	if(!IsPlayerInAnyVehicle(playerid)) return 1;

    new Float:a;
    GetVehicleZAngle(GetPlayerVehicleID(playerid), a);
    SetVehicleZAngle(GetPlayerVehicleID(playerid), a);
    SetVehicleVelocity(GetPlayerVehicleID(playerid), 0.0, 0.0, 0.0);
	return 1;
}

CMD:tuning(playerid, params[]) return cmd_tune(playerid, params);
CMD:tune(playerid, params[])
{
	if(IsPlayerInAnyVehicle(playerid) == 0)
		return 1;//SCM(playerid, 0xFF0000AA, ""C_O"Musisz byæ w samochodzie!");

	if(IsCar(GetVehicleModel(GetPlayerVehicleID(playerid))) == 0 && HydraulicVehicle(GetVehicleModel(GetPlayerVehicleID(playerid))))
	    return SCM(playerid, 0xFF0000AA, ""C_O"Musisz byæ w samochodzie!");

    Dialog(playerid, 3309, DIALOG_LIST, ""C_B"Pe³ny tuning\n"C_B"Losowy tuning\nPodstawowy tuning\nPaintJob\nKolor\nFelgi\nHydraulika\nNeony\nDoczepiane obiekty", "Wybierz", "Anuluj");
    return 1;
}

CMD:pmoff(playerid, params[])
{
	SetPVarInt(playerid, "pOffPM", 1);
	SCM(playerid, -1, ""C_O"Wy³¹czy³eœ sobie "C_B"PW.");
	return 1;
}
CMD:pmon(playerid, params[])
{
	SetPVarInt(playerid, "pOffPM", 0);
	SCM(playerid, -1, ""C_O"W³¹czy³eœ sobie "C_B"PW.");
	return 1;
}
CMD:pm(playerid, params[]) return cmd_pw(playerid, params);
CMD:pw(playerid, params[])
{
	new id, wiadomosc[100];
	if(sscanf(params, "ds[100]", id, wiadomosc))
	    return SCM(playerid, -1, "/PM [id] [treœæ]");

	if(IsIP(wiadomosc) == 1
		|| strfind(wiadomosc, "www.", true) != -1  && strfind(wiadomosc, "topdm", true) == -1
		|| strfind(wiadomosc, ".pl", true) != -1  && strfind(wiadomosc, "topdm", true) == -1
		|| strfind(wiadomosc, ".com", true) != -1 )
		return SCM(playerid, -1, "Nie prawid³owa treœæ!");

   	if(!IsPlayerConnected(id)) return SCM(playerid,0xDD0000FF,""C_B"PM: Z³e ID gracza.");

	if(GetPVarInt(id, "pOffPM") == 1 && Administrator[playerid] < 1)
	    return SCM(playerid, -1, ""C_O"Ten gracz ma wy³¹czone "C_B"PW!");

	if(playerid != id)
	{
		format(strx, sizeof strx, "<< PM: %s(%d): %s", pName[id], id, wiadomosc);
 		SCM(playerid, 0xFF9D00FF, strx);

		format(strx, sizeof strx, ">> PM: %s(%d): %s", pName[playerid], playerid, wiadomosc);
		SCM(id,0xFFFF00FF,strx);

		//PlayerPlaySound(id, 1085, 0.0, 0.0, 0.0);
		Audio_PlayStreamed(id, "http://top.xaa.pl/ptsdm/private/new_pm.mp3");
		new pw_on[1000];
		format(pw_on, sizeof(pw_on), "Nowa wiadomosc~r~!");
        TextDrawSetString(PW[1], pw_on);
        TD_Show(id, PW[0]);
        TD_Show(id, PW[1]);
		SetTimerEx("PW_Hide", 5000, 0, "d", id);

		mysql_query("UPDATE `stats` SET `value` = `value` + 1 WHERE `name` = 'privatemsg'");

		if(Administrator[playerid] >= 1)
		{
        	format(strx, sizeof strx, "[PM]:{DD0000} %s:%s - %s", pName[playerid], pName[id], wiadomosc);
			pLoop(i)
			{
			    if(Administrator[i] && i != playerid && GetPVarInt(i, "pmeye") == 1 && id != i) SCM(i, 0xBB0000FF, strx);
			}
		}

	}else SCM(playerid, 0xDE0000FF, "PM: Nie mo¿esz wys³aæ PM do siebie!");

	return 1;
}
CMD:kill(playerid, params[])
{
	KillPlayer(playerid);
	return 1;
}

CMD:health(playerid, params[]) return cmd_zycie(playerid, params);
CMD:100hp(playerid, params[]) return cmd_zycie(playerid, params);
CMD:zycie(playerid, params[])
{
	if(IsPlayerFight(playerid) == 1)
	{
	    format(strx, sizeof strx, ""C_O"Najpierw dokoñcz walke z "C_B"%s", pName[pAntyTele[playerid][0]]);
		SCM(playerid, -1, strx);
		return 1;
	}

	if(GetPlayerMoney(playerid) < 5000)
	    return SCM(playerid, 0x00AAFFFF,""C_O"Nie mo¿esz kupiæ "C_B"¿ycia "C_O"Musisz mieæ "C_B"5000$");

	if(!Vip[playerid])
	{
		CommandUseBlock(playerid, "zycie", 30000);
	}else{
	    CommandUseBlock(playerid, "zycie", 15000);
	}

	SCM(playerid, 0x00AAFFFF,""C_O"Kupi³eœ "C_B"¿ycie"C_O" Zap³aci³eœ "C_B"5000$");
    SetPlayerHealth(playerid, 100.0);
	GivePlayerMoney(playerid, -5000);
	return 1;
}

CMD:armour(playerid, params[]) return cmd_armor(playerid, params);
CMD:pancerz(playerid, params[]) return cmd_armor(playerid, params);
CMD:armor(playerid, params[])
{
	if(IsPlayerFight(playerid) == 1)
	{
	    format(strx, sizeof strx, "* {00AAFF}Najpierw dokoñcz walke z {DD0000}%s", pName[pAntyTele[playerid][0]]);
		SCM(playerid, -1, strx);
		return 1;
	}

	if(GetPlayerMoney(playerid) < 5000)
	    return SCM(playerid, 0x00AAFFFF,"Nie mo¿esz kupiæ {DD0000}pancerza{00AAFF}! Musisz mieæ {DD0000}5000$");

	if(!Vip[playerid])
	{
		CommandUseBlock(playerid, "armor", 30000);
	}else{
	    CommandUseBlock(playerid, "armor", 15000);
	}

	SCM(playerid, 0x00AAFFFF,"Kupi³eœ {DD0000}pancerz{00AAFF}! Zap³aci³eœ {DD0000}2000$");
	SetPlayerArmour(playerid, 100.0);
	GivePlayerMoney(playerid, -2000);
	return 1;
}
CMD:repair(playerid, params[]) return cmd_napraw(playerid, params);
CMD:fix(playerid, params[]) return cmd_napraw(playerid, params);
CMD:napraw(playerid, params[])
{
	if(IsPlayerFight(playerid) == 1)
	{
	    format(strx, sizeof strx, ""C_O"Najpierw dokoñcz walke z "C_B"%s", pName[pAntyTele[playerid][0]]);
		SCM(playerid, -1, strx);
		return 1;
	}

	if(!IsPlayerInAnyVehicle(playerid))
	    return SCM(playerid, 0x00AAFFFF,""C_O"Musisz byæ w "C_B"pojedzie"C_O", aby go naprawiæ!");

	if(GetPlayerMoney(playerid) < 1000)
	    return SCM(playerid, 0x00AAFFFF,""C_O"Nie mo¿esz naprawiæ "C_B"pojazdu{00AAFF}! Musisz mieæ "C_B"1000$");

	CommandUseBlock(playerid,"napraw",30000);

	SCM(playerid, 0x00AAFFFF,""C_O"Naprawi³eœ "C_B"pojazd"C_O"! Zap³aci³eœ "C_B"1000$");
	RepairVehicle(GetPlayerVehicleID(playerid));
	if(Vip[playerid])
	{
	    SetVehicleHealth(GetPlayerVehicleID(playerid), 1150.0);
	}
	GivePlayerMoney(playerid, -1000);
	return 1;
}
CMD:lec(playerid, params[])
{
	new Float:bPos[3], c;
    GetDynamicObjectPos(BallonID, bPos[0],bPos[1],bPos[2]);
	if(IsPlayerInRangeOfPoint(playerid, 10.0, bPos[0],bPos[1],bPos[2]))
	{
		c = 1;
	}
	GetDynamicObjectPos(BallonID2, bPos[0],bPos[1],bPos[2]);
	if(IsPlayerInRangeOfPoint(playerid, 10.0, bPos[0],bPos[1],bPos[2]))
	{
		c = 2;
	}
	if(c == 0) return SCM(playerid, -1, ""C_O"Musisz byæ w "C_B"Balonie");

	if(c == 1)
	{
		if(BallonPos == 0)
		{
			BallonKierunek = 0;
		    BallonPos++;
			MoveDynamicObject(BallonID, PosBallon[BallonPos][0],PosBallon[BallonPos][1],PosBallon[BallonPos][2], 10.0);
		}else if(BallonPos == 3)
		{
		    BallonKierunek = 1;
		    BallonPos--;
			MoveDynamicObject(BallonID, PosBallon[BallonPos][0],PosBallon[BallonPos][1],PosBallon[BallonPos][2], 10.0);
		}else{
		    StopObject(BallonID);
		    if(BallonKierunek == 1)
		    {
		    	BallonKierunek = 0;
				BallonPos++;
			}else{
			    BallonPos--;
	            BallonKierunek = 1;
			}
			if(BallonPos == 0 || BallonPos == 3)
			{
				MoveDynamicObject(BallonID, PosBallon[BallonPos][0],PosBallon[BallonPos][1],PosBallon[BallonPos][2], 10.0);
			}else
			{
			    MoveDynamicObject(BallonID, PosBallon[BallonPos][0],PosBallon[BallonPos][1],PosBallon[BallonPos][2], 22.0);
			}
			SCM(playerid, -1, "{00AAFF} Zmieni³eœ kierunek lotu balonu!");
		}
	}else{
		if(BallonPos2 == 0)
		{
			BallonKierunek2 = 0;
		    BallonPos2++;
			MoveDynamicObject(BallonID2, PosBallon2[BallonPos2][0],PosBallon2[BallonPos2][1],PosBallon2[BallonPos2][2], 10.0);
		}else if(BallonPos2 == 3)
		{
		    BallonKierunek2 = 1;
		    BallonPos2--;
			MoveDynamicObject(BallonID2, PosBallon2[BallonPos2][0],PosBallon2[BallonPos2][1],PosBallon2[BallonPos2][2], 10.0);
		}else{
		    StopObject(BallonID2);
		    if(BallonKierunek2 == 1)
		    {
		    	BallonKierunek2 = 0;
				BallonPos2++;
			}else{
			    BallonPos2--;
	            BallonKierunek2 = 1;
			}
			if(BallonPos2 != 3)
			{
				MoveDynamicObject(BallonID2, PosBallon2[BallonPos2][0],PosBallon2[BallonPos2][1],PosBallon2[BallonPos2][2], 8.0);
			}else
			{
			    MoveDynamicObject(BallonID2, PosBallon2[BallonPos2][0],PosBallon2[BallonPos2][1],PosBallon2[BallonPos2][2], 17.0);
			}
			SCM(playerid, -1, ""C_B"Zmieni³eœ kierunek lotu balonu!");
		}
	}
	return 1;
}
CMD:exitrace(playerid, params[])
{
	if(GetPlayerVirtualWorld(playerid) != 1)
	    return SCM(playerid, -1, ""C_O"Nie jesteœ teraz w wyœæigu!");

	KillTimer(GetPVarInt(playerid, "RaceTimer"));
	ExitRace(playerid, 2);
	SCM(playerid, -1, ""C_B"Zrezygnowa³eœ z wyœcigu");
	return 1;
}
CMD:restartrace(playerid, params[]) return cmd_resrace(playerid, params);
CMD:resrace(playerid, params[])
{
	if(GetPVarInt(playerid, "LastRace") == 0 && GetPVarInt(playerid, "RacePlayer") == 0)
	    return SCM(playerid, -1, "Nie jesteœ na ¿adnym wyœcigu!");

	if(IsPlayerInAnyVehicle(playerid)) SetVehicleToRespawn(GetPlayerVehicleID(playerid));

    KillTimer(GetPVarInt(playerid, "RaceTimer"));
    SetPVarInt(playerid, "eRaceID", GetPVarInt(playerid, "LastRace") - 1);
    cmd_race(playerid, "qweqwe");
	return 1;
}
CMD:race(playerid, params[])
{
	if(strcmp(params, "qweqwe") != 0 && IsPlayerInCheckpoint(playerid) == 0
		|| GetPVarInt(playerid, "eRaceID") == -1
		|| GetPVarInt(playerid, "eRaceID") >= MAX_RACE)
	    return SCM(playerid, -1, ""C_B"Musisz byæ w punkcie startowym!");

	new i = GetPVarInt(playerid, "eRaceID");

	if(IsPlayerInAnyVehicle(playerid)) SetVehicleToRespawn(GetPlayerVehicleID(playerid));

	new v = CreateVehicle(RaceInfo[i][Rmodelid],RaceInfo[i][Rx], RaceInfo[i][Ry], RaceInfo[i][Rz] + 1, RaceInfo[i][Rr], random(255), random(255), 10);
	SetPlayerVirtualWorld(playerid, 1);
	SetVehicleVirtualWorld(v, 1);
    VehicleCreated[v] = 1;
    PutPlayerInVehicle(playerid,v,0);
	SetVehicleHealth(v, 99999.0);
	DisablePlayerRaceCheckpoint(playerid);
	TogglePlayerControllable(playerid, 0);

	SetPVarInt(playerid, "LastRace", i+1);
	SetPVarInt(playerid, "RacePlayer", 1);
	SetPVarInt(playerid, "RaceCP", 1);
	SetPVarInt(playerid, "RaceTick", GetTickCount());
	SetPVarInt(playerid, "RaceTimer", SetTimerEx("ExitRace", 30000, 0, "dd", playerid, 0));
	CountdownRace(playerid, 5);

	new mstr[120],row2[120];
	format(mstr, 120, "SELECT * FROM `race_cp` WHERE `race_id` = '%d' ORDER BY `id` ASC LIMIT 2", RaceInfo[i][Rid]);
	mysql_query(mstr);
	mysql_store_result();
	mysql_fetch_row(mstr, "|");
	mysql_fetch_row(row2, "|");
	mysql_free_result();

	new idt,race_id, Float:x,Float:y,Float:z,size,typ, Float:x2,Float:y2,Float:z2;
    sscanf(row2, "p<|>iifffii", idt,race_id, x2,y2,z2,size,typ);
	sscanf(mstr, "p<|>iifffii", idt,race_id, x,y,z,size,typ);
	SetPlayerRaceCheckpoint(playerid, typ, x,y,z,x2,y2,z2, size);
	SCM(playerid, -1, ""C_O"Odliczanie rozpoczête. Wpisz "C_B"/exitrace"C_O" aby zrezygnowaæ z wyœcigu.");
	pInFun[playerid] = 1;
	ClearAllFun(playerid);
	return 1;
}
CMD:exit(playerid, params[])
{
    if(currentInt[playerid] > -1 && GetPlayerInterior(playerid) == GetPropertyInteriorId(currentInt[playerid]))
	{
		new id = currentInt[playerid], Float:x, Float:y, Float:z, Float:a;

		GetPropertyExit(id, x, y, z);
		if(!IsPlayerInRangeOfPoint(playerid,5.0,x,y,z))
		{
		    SCM(playerid,0xDDAA55FF,""C_O"Musisz byæ obok wyjœcia aby wpisaæ "C_B"/exit");
		    return 1;
		}
		pPropertyPickup[playerid] = GetTickCount();
		a = GetPropertyEntrance(id, x, y, z);
		SetPlayerPos(playerid, x, y, z);
		SetPlayerFacingAngle(playerid, a);
		SetPlayerInterior(playerid, 0);
		SetPlayerVirtualWorld(playerid, 0);
	}
	currentInt[playerid] = -1;
	return 1;
}
CMD:gotohome(playerid, params[])
{
	if(pHouse[playerid] != -1)
	{
	    TeleportToHouse(playerid, pHouse[playerid], 1);
	}else SCM(playerid, -1, ""C_O"Musisz mieæ wykupiony dom, aby korzystaæ z tej komendy!");
	return 1;
}
CMD:gosc(playerid, params[])
{
	if(GetPVarInt(playerid, "hZapro") == -1) return SCM(playerid, -1, ""C_O"Nie jesteœ zaproszony do ¿adnego domu!");

	if(GetPVarInt(GetPVarInt(playerid, "hZapro"), "eHouseID") != pHouse[GetPVarInt(playerid, "hZapro")] || pHouse[GetPVarInt(playerid, "hZapro")] == -1)
		return SCM(playerid, -1, "Zaproszenie nieaktualne");

	new i = pHouse[GetPVarInt(playerid, "hZapro")];
	SetPlayerInterior(playerid, housesInt[HouseInfo[i][hInt]]);
	SetPlayerPos(playerid, hPos[HouseInfo[i][hInt]][0],hPos[HouseInfo[i][hInt]][1],hPos[HouseInfo[i][hInt]][2]);
	SetPlayerFacingAngle(playerid, 0.0);
	SetPlayerVirtualWorld(playerid, GetPlayerVirtualWorld(GetPVarInt(playerid, "hZapro")));
	SetPVarInt(playerid, "eHouseID", i);

	format(strx, sizeof strx, ""C_O"Gracz "C_B"%s"C_O" wszed³ do twojego domu.", pName[playerid]);
	SCM(GetPVarInt(playerid, "hZapro"), -1, strx);
	return 1;
}
CMD:wejdz(playerid, hid, owner)
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
CMD:gospodarz(playerid, params[])
{
	if(pHouse[playerid] == -1) return SCM(playerid, -1, ""C_O"Nie posiadasz swojego "C_B"domu!");
	if(GetPVarInt(playerid, "inHouse") == 0) return SCM(playerid, -1, ""C_O"Musisz byæ w "C_B"domu!");

	Dialog(playerid, 645, DIALOG_LIST, "Sprzedaj dom\nZmieñ wnêtrze\nSejf\nNazwa domu\nZaproœ gracza", "Wybierz", "Zamknij");
	return 1;
}
CMD:bug(playerid,cmdtext[])
{
        if(isnull(cmdtext))
        {
            SCM(playerid, -1, ""C_O"/"C_B"bug "C_O"["C_B"Opis bugu"C_O"]");
            return 1;
        }
        new timess[6],
		    str[1000];

	    gettime(timess[0], timess[1], timess[2]);
	    getdate(timess[3], timess[4], timess[5]);
        format(strx, 255, "INSERT INTO `zgloszenia_bug` SET `autor`='%s', `tresc`='%s', `data`='%d-%d-%d %d:%d:%d'", pName[playerid], cmdtext,
	    timess[3], timess[4], timess[5], timess[0], timess[1], timess[2]);
	    mysql_query(strx);
 		format(str, sizeof str, ""C_O"Dziêkujemy za zg³oszenie bugu!\nZg³oszenie zostanie rozpatrzone przez naszych "C_B"programistów\n"C_O"Jeœli wys³a³eœ bugu, którego nie ma, robisz 'kawa³' itp.\nLicz siê z tym, ¿e zostaniesz ukarany.\n\n\tTreœæ zg³oszenia: "C_B"%s", cmdtext);
		ShowPlayerDialog(playerid, 13124, DIALOG_STYLE_MSGBOX, "{EAB171}BUG Zg³oszony!", str, "Ok", "");
        return 1;
}

forward CMD_UnLock(playerid);
public CMD_UnLock(playerid)
{
	CMD_Block[playerid] = false;
	return 1;
}
