/*
	@Polski TOP Serwer - Licens.inc
	@Last update: 14 marca 2014 23:25

*/
stock Licens()
{
    if(dini_Exists("ptsDM/Setings/licencja.txt"))
    {
        print("Licencja wczytana pomyslnie");
    }
    else
    {
        print("Brak licencji.");
        SendRconCommand("exit");
	}
}
