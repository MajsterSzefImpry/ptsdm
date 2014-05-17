/*
	@Polski TOP Serwer - moeny.inc
	@Last update: 14 marca 2014 23:25

*/
/*-----------------*/
/*   Zapis kasy    */
/*--------------- -*/
GetPlayerMoney_(playerid)
{
    new mstr[128];
	if(GetPlayerMoney(playerid) >= 99999999)
	{
		BanPlayer(playerid, "Anty Cheat", "Money Hack");
	    return 1;
	}
	format(mstr, sizeof mstr, "SELECT `money` FROM `players` WHERE `nick` = '%s'", pName[playerid]);
	mysql_query(mstr);
	mysql_store_result();

	new money[12];
	mysql_fetch_field("money", money);
	mysql_free_result();
	return strval(money);
}
SetPlayerMoney(playerid, money)
{
	if(money > 99999998) return 0;

	new mstr[150];
	ResetPlayerMoney(playerid);
	GivePlayerMoney(playerid, money);

	format(mstr, sizeof mstr, "UPDATE `players` SET `money` = '%d' WHERE `nick` = '%s'", money, pName[playerid]);
	mysql_query(mstr);
	return 1;
}
GivePlayerMoney_(playerid, money)
{
	if(money > 0)
	{
		if(money + GetPlayerMoney_(playerid) > 99999998)
		{
            SCM(playerid, 0xFFFFFFFF, ""czat" "C_O"Nie mo¿esz chodziæ z tak du¿a iloœci¹ pieniêdzy! "C_B"Zanieœ j¹ do bankomatu!");
    	    SetPlayerMoney(playerid, 99999998);
			return 1;
 		}
	}
	SetPlayerMoney(playerid, money + GetPlayerMoney_(playerid));
	return 1;
}
#define GivePlayerMoney GivePlayerMoney_
#define GetPlayerMoney GetPlayerMoney_