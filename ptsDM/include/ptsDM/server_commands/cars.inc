/*
	@Polski TOP Serwer - cars.inc
	@Last update: 14 marca 2014 23:25

*/
CMD:rower(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "509");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:infernus(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "411");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:bmx(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "481");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:nrg(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "522");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:mountainbike(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "510");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:faggio(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "462");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:bf400(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "581");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:pcj600(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "461");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:fcr900(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "521");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:hpv1000(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "523");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:freeway(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "463");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:wayfarer(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "586");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:quad(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "471");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:comet(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "480");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:feltzer(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "533");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:stallion(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "439");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:windsor(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "555");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:benson(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "499");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:bobcat(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "422");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:burrito(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "482");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:boxville(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "498");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:cement(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "524");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:dft30(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "578");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:flatbed(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "455");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:linerunner(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "403");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:cysterna(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "514");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:packer(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "443");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:picador(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "600");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:pony(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "413");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:roadtrain(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "515");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:rumpo(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "440");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:sadler(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "543");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:tractor(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "513");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:trash(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "408");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:utility(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "552");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:walton(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "478");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:yosemite(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "554");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:blade(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "536");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:broadway(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "575");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:remington(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "534");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:savanna(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "567");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:slamvan(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "535");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:tahoma(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "566");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:tornado(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "576");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:voodoo(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "412");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:bandito(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "568");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:inject(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "424");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:dune(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "573");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:mesa(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "500");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:monster(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "557");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:patriot(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "470");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:rancher(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "489");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:sandking(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "495");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:ambulance(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "416");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:barracks(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "433");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:bus(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "431");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:taxi(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "438");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:enforcer(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "427");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:fbirancher(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "490");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:fbitruck(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "528");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:firetruck(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "407");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:lspd(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "596");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:lvpd(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "598");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:sfpd(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "597");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:swatvan(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "601");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:admiral(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "445");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:bloodranger(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "504");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:bravura(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "401");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:buccaneer(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "518");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:cadrona(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "527");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:clover(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "542");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:elegant(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "507");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:elegy(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "562");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:emperor(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "585");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:esperant(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "419");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:glendale(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "466");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:greenwood(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "492");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:hermes(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "474");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:oceanic(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "467");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:sentinel(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "405");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:sultan(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "560");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:tampa(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "549");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:washington(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "421");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:alpha(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "602");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:banshee(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "429");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:blista(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "496");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:buffalo(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "402");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:bullet(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "541");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:cheetah(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "415");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:club(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "589");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:euros(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "587");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:flash(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "565");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:hotring(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "494");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:phoenix(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "603");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:sabre(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "475");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:jester(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "559");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:supergt(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "506");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:turismo(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "451");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:zr350(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "477");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:moonbeam(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "418");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:perentiel(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "404");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:solair(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "458");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:stratum(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "561");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:camper(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "483");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:journey(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "508");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:kombajn(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "532");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:dozer(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "486");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:dumper(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "406");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:hotknife(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "434");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:hustler(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "545");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:hotdog(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "588");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:gokart(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "571");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:tower(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "572");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:icecream(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "423");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:romero(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "442");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:stretch(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "409");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:towtruck(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "525");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:vortex(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "539");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:coastguard(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "472");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:dinghy(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "473");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:jetmax(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "493");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:launch(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "595");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:marquis(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "484");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:predator(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "430");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:refeer(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "453");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:speeder(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "452");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:squalo(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "446");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:tropic(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "454");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:skimmer(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "460");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:beagle(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "511");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:stuntplane(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "513");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:shamal(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "519");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:nevada(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "553");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:doodoo(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "593");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:cargobob(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "548");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:leviathan(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "417");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:maverick(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "487");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:raindance(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "563");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}

CMD:sparrow(playerid, params[])
{
	CallRemoteFunction("cmd_v", "ds", playerid, "469");
	new namescars[300];
    format(namescars, sizeof(namescars), "(Pojazd):~r~/%s", GetVehicleName(GetVehicleModel(pVehicle[playerid])));
    TextDrawSetString(TD_Pojazd, namescars);
    TD_Show(playerid, TD_Pojazd);
    SetTimerEx("TD_Pojazd_Hide", 4000, 0, "d", playerid);
	return 1;
}
