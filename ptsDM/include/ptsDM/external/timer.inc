/*
	@Polski TOP Serwer - timer.inc
	@Last update: 14 marca 2014 23:25

*/
stock TimersInit() {
    SetTimer("CheckOnline", 1000, true);
    SetTimer("Staty",1000,true);
    SetTimer("MinutaFunc",1000,true);
    SetTimer("cmd_ObliczDzialanie", 420000, 1);
    SetTimer("playersarena", 1000, true);
    SetTimer("dwieminuty", 20000, true);
    SetTimer("SpedycjaCPUpdate", 1400, 1);
    SetTimer("Premia", 1500000, true);
    SetTimer("zmiananazyserwera",2000,1);
    SetTimer("LogoColor", 500, true);
    SetTimer("piecmin", 500000, true);
	SetTimer("UpdateHealth", 1000, true);
	SetTimer("Update", 60000, 1);
	SetTimer("UpdateSec", 500, 1);
	SetTimer("god", 1000, 1);
	SetTimer("reklama", 10000, 1);
	TimerReaction = SetTimer("ReactionTest", 600000, 0);
	SetTimer("UpdateHealth", 1000, true);
	SetTimer("UpdateData", 1000, true);
}
