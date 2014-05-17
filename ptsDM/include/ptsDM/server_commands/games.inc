/*
	@Polski TOP Serwer - games.inc
	@Last update: 14 marca 2014 23:25

*/
enum ServerMain
{
	minigunPlayers,
	rpgPlayers,
	oneshootPlayers,
	jetpackPlayers,
	sniperPlayers
};
new Server[ServerMain];
enum PlayerMain
{
	bool:minigun,
	bool:oneshoot,
	bool:rpg,
	bool:sniper,
	bool:jetpack,
	bool:Arena
};
new Player[MAX_PLAYERS][PlayerMain];

CMD:exitdm(playerid, params[])
{
	ExitDM(playerid);
    if(Player[playerid][rpg])
	{
	    Server[rpgPlayers]--;
	    Player[playerid][rpg] = false;
	}
	if(Player[playerid][minigun])
	{
	    Server[minigunPlayers]--;
	    Player[playerid][minigun] = false;
	}
	if(Player[playerid][oneshoot])
	{
	    Server[oneshootPlayers]--;
	    Player[playerid][oneshoot] = false;
	}
    if(Player[playerid][jetpack])
	{
 	   Server[jetpackPlayers]--;
 	   Player[playerid][jetpack] = false;
	}
	if(Player[playerid][sniper])
	{
 	   Server[sniperPlayers]--;
 	   Player[playerid][sniper] = false;
	}
	if(Player[playerid][jetpack])
	{
 	   Server[jetpackPlayers]--;
 	   Player[playerid][jetpack] = false;
	}
	Player[playerid][Arena] = false;
	return 1;
}
CMD:rpg(playerid, params[])
{
	DeathMatch(playerid, DM_RPG);
	Server[rpgPlayers]++;
    Player[playerid][rpg] = true;
    Player[playerid][Arena] = true;
	format(strx, sizeof strx, ""C_B"%s "C_O"do³¹czy³ do "C_B"/RPG, "C_O"do³¹cz i Ty!", pName[playerid]);
	SCMToAll(-1, strx);
	return 1;
}
CMD:minigun(playerid, params[])
{
	DeathMatch(playerid, DM_MINI);
    Server[minigunPlayers]++;
    Player[playerid][minigun] = true;
    Player[playerid][Arena] = true;
	format(strx, sizeof strx, ""C_B"%s "C_O"do³¹czy³ do "C_B"/Minigun, "C_O"do³¹cz i Ty!", pName[playerid]);
	SCMToAll(-1, strx);
	return 1;
}
CMD:oneshoot(playerid, params[])
{
	DeathMatch(playerid, DM_OS);
    Server[oneshootPlayers]++;
	Player[playerid][oneshoot] = true;
    Player[playerid][Arena] = true;
	format(strx, sizeof strx, ""C_B"%s "C_O"do³¹czy³ do "C_B"/OneShoot, "C_O"do³¹cz i Ty!", pName[playerid]);
	SCMToAll(-1, strx);
	return 1;
}
CMD:jetpack(playerid, params[])
{
	DeathMatch(playerid, DM_JP);
    Server[jetpackPlayers]++;
    Player[playerid][jetpack] = true;
    Player[playerid][Arena] = true;
	format(strx, sizeof strx, ""C_B"%s "C_O"do³¹czy³ do "C_B"/Jetpack, "C_O"do³¹cz i Ty!", pName[playerid]);
	SCMToAll(-1, strx);
	return 1;
}
CMD:snajper(playerid, params[])
{
	DeathMatch(playerid, DM_SNP);
	Server[sniperPlayers]++;
	Player[playerid][sniper] = true;
	Player[playerid][Arena] = true;
	format(strx, sizeof strx, ""C_B"%s "C_O"do³¹czy³ do "C_B"/Snajper, "C_O"do³¹cz i Ty!", pName[playerid]);
	SCMToAll(-1, strx);
	return 1;
}