/*
	@Polski TOP Serwer - check_topoff.inc
	@Last update: 14 marca 2014 23:25

*/
stock checktopoff()
{ 
   if(dini_Exists("plik.txt"))
    {
        print("Wyst�pi� b��d, wylaczanie serwera..");
        SendRconCommand("exit");
   }
   else
   {
        print(" ");
    }
}