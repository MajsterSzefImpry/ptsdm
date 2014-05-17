/*
	@Polski TOP Serwer - MySQL.inc
	@Last update: 14 marca 2014 23:25

*/
stock connect_mysql() {
 	mysql_init();
	mysql_connect("host", "nazwauzytkownika", "pass", "bazadanych", MySQL:0, 1);
	if(mysql_ping() != 0)
	{
		printf("Nie udalo sie wczytac konfiguracji bazy danych. Wylaczanie gamemode");
		SendRconCommand("exit");
	}
	printf("Inicjacja i laczenie z baza MySQL...");
}
