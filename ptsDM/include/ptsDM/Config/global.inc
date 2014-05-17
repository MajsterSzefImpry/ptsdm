/*
	@Polski TOP Serwer - global.inc
	@Last update: 15 marca 2014 00:03

*/
Nametop()
{
    SendRconCommand("hostname [TOP]•••••••••• [TOP.xaa.pl] ••••••••••[PL]");
    SendRconCommand("mapname °•Fun Andreas•°");
    SetGameModeText("°•DeathMatch "Version"•°");
    SendRconCommand("weburl www.TOP.xaa.pl");
}

forward zmiananazyserwera();
public zmiananazyserwera()
{
	new names = random(5);
	switch(names)
	{
		case 0: SendRconCommand("hostname [TOP]•••••••• Polski TOP Serwer ••••••••[PL]");
		case 1: SendRconCommand("hostname [TOP]•••••••••• [TOP.xaa.pl] ••••••••••[PL]");
		case 2: SendRconCommand("hostname [TOP]•••••••• [TOP.xaa.pl] ••••••••[PL]");
		case 3: SendRconCommand("hostname http://sa-mp.com - pobierz 0.3z juz dzis i zagraj!");
		case 4: SendRconCommand("hostname •••••••• Najlepsza rozrywka tylko u Nas! ••••••••");
	}
}
