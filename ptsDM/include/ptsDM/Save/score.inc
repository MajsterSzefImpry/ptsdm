/*
	@Polski TOP Serwer - score.inc
	@Last update: 14 marca 2014 23:25

*/
/*------------------*/
/*    Zapis score   */
/*------------------*/
SetPlayerExp(playerid, exp)
{
    new mstr[128];
	format(mstr, sizeof mstr, "UPDATE `players` SET `score` = '%d' WHERE `nick` = '%s'", exp, pName[playerid]);
	mysql_query(mstr);
	SetPlayerScore(playerid, exp);
	valstr(mstr, exp);
	return 1;
}
GetPlayerExp(playerid)
{
	new mstr[128];
	format(mstr, sizeof mstr, "SELECT `score` FROM `players` WHERE `nick` = '%s'", pName[playerid]);
	mysql_query(mstr);
	mysql_store_result();

	new exp[12];
	mysql_fetch_field("score", exp);
	mysql_free_result();
	return strval(exp);
}

GivePlayerScore(playerid, exp)
{
	SetPlayerExp(playerid, exp + GetPlayerExp(playerid));
	return 1;
}
#define SetPlayerScore(%0,%1) SetPlayerExp(%0,%1)
#define GetPlayerScore(%0) GetPlayerExp(%0)

