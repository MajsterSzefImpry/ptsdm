/*
	@Polski TOP Serwer - cfg.inc
	@Last update: 14 marca 2014 23:25

*/
stock konfiguracja()
{
    if(GetMaxPlayers() != MAX_PLAYERS)
	{
	      print("[TOP] Konfiguracja serwera nie zgodna z plikiem konfiguracyjnym.");
	      print("[TOP] wylaczenie serwera.");
	      SendRconCommand("exit");
	}
	else
	{
	      print("[TOP] Konfiguracja serwera zgodna z plikiem konfiguracyjnym.");
	      print("[TOP] uruchomienie gamemode przebieglo pomyslnie.");
	}
	for ( new playerid; playerid < MAX_PLAYERS; playerid++ )
    {
          if ( IsPlayerConnected( playerid ) )
               AntiFlood_InitPlayer( playerid );
    }
}
