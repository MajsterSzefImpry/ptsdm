/*
	@Polski TOP Serwer - textdraw.inc
	@Last update: 14 marca 2014 23:25

*/
TextDraw()
{
    mVote[TDVote][0] = TextDrawCreate(386.530609, 30.333343, "~g~Glosowanie!");
    TextDrawLetterSize(mVote[TDVote][0], 0.259779, 1.407498);
    TextDrawAlignment(mVote[TDVote][0], 2);
    TextDrawColor(mVote[TDVote][0], -1);
    TextDrawSetShadow(mVote[TDVote][0], 0);
    TextDrawSetOutline(mVote[TDVote][0], 1);
    TextDrawBackgroundColor(mVote[TDVote][0], 51);
    TextDrawFont(mVote[TDVote][0], 1);
    TextDrawSetProportional(mVote[TDVote][0], 1);
    TextDrawSetSelectable(mVote[TDVote][0], true);

    mVote[TDVote][1] = TextDrawCreate(295.000, 23.500, "LD_POKE:cdback");
    TextDrawFont(mVote[TDVote][1], 4);
    TextDrawTextSize(mVote[TDVote][1], 188.500, 76.000);
    TextDrawColor(mVote[TDVote][1], 799);

    Event = TextDrawCreate(360.761718, 272.416778, "~r~/HY ~w~wystartuje za ~r~20 ~w~sek~n~wpisz ~r~/HY ~w~, aby sie zapisac~r~!");
    TextDrawLetterSize(Event, 0.200745, 1.442499);
    TextDrawAlignment(Event, 2);
    TextDrawColor(Event, -1);
    TextDrawSetShadow(Event, 0);
    TextDrawSetOutline(Event, 1);
    TextDrawBackgroundColor(Event, 51);
    TextDrawFont(Event, 1);
    TextDrawSetProportional(Event, 1);
	
    Naprawa_TD[0] = TextDrawCreate(510.688781, 344.749938, "Czekaj ~r~10 sek");
    TextDrawLetterSize(Naprawa_TD[0], 0.120159, 1.652499);
    TextDrawAlignment(Naprawa_TD[0], 2);
    TextDrawColor(Naprawa_TD[0], -5963521);
    TextDrawSetShadow(Naprawa_TD[0], 0);
    TextDrawSetOutline(Naprawa_TD[0], 1);
    TextDrawBackgroundColor(Naprawa_TD[0], 51);
    TextDrawFont(Naprawa_TD[0], 2);
    TextDrawSetProportional(Naprawa_TD[0], 1);

    Naprawa_TD[1] = TextDrawCreate(479.500, 340.000, "LD_POKE:cdback");
    TextDrawFont(Naprawa_TD[1], 4);
    TextDrawTextSize(Naprawa_TD[1], 62.500, 26.500);
    TextDrawColor(Naprawa_TD[1], 799);

	TD_Teleport_ = TextDrawCreate(212.240158, 368.083251, "(Teleport): ~r~/LsLot");
	TextDrawLetterSize(TD_Teleport_, 0.241508, 1.104166);
	TextDrawAlignment(TD_Teleport_, 1);
	TextDrawColor(TD_Teleport_, -5963521);
	TextDrawSetShadow(TD_Teleport_, 0);
	TextDrawSetOutline(TD_Teleport_, 1);
	TextDrawBackgroundColor(TD_Teleport_, 51);
	TextDrawFont(TD_Teleport_, 1);
	TextDrawSetProportional(TD_Teleport_, 1);

	TD_Pojazd = TextDrawCreate(213.177230, 349.416717, "(Pojazd): ~r~/Infernus");
	TextDrawLetterSize(TD_Pojazd, 0.241508, 1.104166);
	TextDrawAlignment(TD_Pojazd, 1);
	TextDrawColor(TD_Pojazd, -5963521);
	TextDrawSetShadow(TD_Pojazd, 0);
	TextDrawSetOutline(TD_Pojazd, 1);
	TextDrawBackgroundColor(TD_Pojazd, 51);
	TextDrawFont(TD_Pojazd, 1);
	TextDrawSetProportional(TD_Pojazd, 1);

	StrefaDM = TextDrawCreate(504.128875, 95.083381, "Strefa_Smierci");
	TextDrawLetterSize(StrefaDM, 0.520278, 1.950000);
	TextDrawAlignment(StrefaDM, 1);
	TextDrawColor(StrefaDM, -16776961);
	TextDrawSetShadow(StrefaDM, 0);
	TextDrawSetOutline(StrefaDM, 1);
	TextDrawBackgroundColor(StrefaDM, 51);
	TextDrawFont(StrefaDM, 0);
	TextDrawSetProportional(StrefaDM, 1);

	www_top = TextDrawCreate(582.840820, 408.333251, "www.TOP.xaa.pl");
	TextDrawLetterSize(www_top, 0.152488, 1.308333);
	TextDrawAlignment(www_top, 1);
	TextDrawColor(www_top, -2139062017);
	TextDrawSetShadow(www_top, 0);
	TextDrawSetOutline(www_top, 1);
	TextDrawBackgroundColor(www_top, 51);
	TextDrawFont(www_top, 2);
	TextDrawSetProportional(www_top, 1);
	
	Logo = TextDrawCreate(28.111324, 416.499969, "Polski TOP Serwer");
	TextDrawLetterSize(Logo, 0.222767, 2.533334);
	TextDrawAlignment(Logo, 1);
	TextDrawColor(Logo, 65535);
	TextDrawSetShadow(Logo, 0);
	TextDrawSetOutline(Logo, 1);
	TextDrawBackgroundColor(Logo, 51);
	TextDrawFont(Logo, 2);
	TextDrawSetProportional(Logo, 1);

	NazwaMapy = TextDrawCreate(41.229919, 435.166748, "ptsDM "Version"");
	TextDrawLetterSize(NazwaMapy, 0.261185, 1.203332);
	TextDrawAlignment(NazwaMapy, 1);
	TextDrawColor(NazwaMapy, -5963521);
	TextDrawSetShadow(NazwaMapy, 0);
	TextDrawSetOutline(NazwaMapy, 1);
	TextDrawBackgroundColor(NazwaMapy, 51);
	TextDrawFont(NazwaMapy, 1);
	TextDrawSetProportional(NazwaMapy, 1);


	CountRace[5] = TextDrawCreate(321.0, 196.0, "]  5  ]");
	TextDrawAlignment(CountRace[5], 2);
	TextDrawBackgroundColor(CountRace[5], 119);
	TextDrawFont(CountRace[5], 0);
	TextDrawLetterSize(CountRace[5], 0.540000, 1.900000);
	TextDrawColor(CountRace[5], -16777046);
	TextDrawSetOutline(CountRace[5], 1);
	TextDrawSetProportional(CountRace[5], 1);

	CountRace[4] = TextDrawCreate(321.0, 196.0, "]  4  ]");
	TextDrawAlignment(CountRace[4], 2);
	TextDrawBackgroundColor(CountRace[4], 119);
	TextDrawFont(CountRace[4], 0);
	TextDrawLetterSize(CountRace[4], 0.540000, 1.900000);
	TextDrawColor(CountRace[4], -16777046);
	TextDrawSetOutline(CountRace[4], 1);
	TextDrawSetProportional(CountRace[4], 1);

	CountRace[3] = TextDrawCreate(321.0, 196.0, "]  3  ]");
	TextDrawAlignment(CountRace[3], 2);
	TextDrawBackgroundColor(CountRace[3], 119);
	TextDrawFont(CountRace[3], 0);
	TextDrawLetterSize(CountRace[3], 0.540000, 1.900000);
	TextDrawColor(CountRace[3], -16777046);
	TextDrawSetOutline(CountRace[3], 1);
	TextDrawSetProportional(CountRace[3], 1);

	CountRace[2] = TextDrawCreate(321.0, 196.0, "]  2  ]");
	TextDrawAlignment(CountRace[2], 2);
	TextDrawBackgroundColor(CountRace[2], 119);
	TextDrawFont(CountRace[2], 0);
	TextDrawLetterSize(CountRace[2], 0.540000, 1.900000);
	TextDrawColor(CountRace[2], -16777046);
	TextDrawSetOutline(CountRace[2], 1);
	TextDrawSetProportional(CountRace[2], 1);

	CountRace[1] = TextDrawCreate(321.0, 196.0, "]  1  ]");
	TextDrawAlignment(CountRace[1], 2);
	TextDrawBackgroundColor(CountRace[1], 119);
	TextDrawFont(CountRace[1], 0);
	TextDrawLetterSize(CountRace[1], 0.540000, 1.900000);
	TextDrawColor(CountRace[1], -16777046);
	TextDrawSetOutline(CountRace[1], 1);
	TextDrawSetProportional(CountRace[1], 1);

	CountRace[0] = TextDrawCreate(321.0, 196.0, "]  START!  ]");
	TextDrawAlignment(CountRace[0], 2);
	TextDrawBackgroundColor(CountRace[0], 119);
	TextDrawFont(CountRace[0], 0);
	TextDrawLetterSize(CountRace[0], 0.540000, 1.900000);
	TextDrawColor(CountRace[0], 11206570);
	TextDrawSetOutline(CountRace[0], 1);
	TextDrawSetProportional(CountRace[0], 1);

	Zegar[0]= TextDrawCreate(533.500, -15.500, "LD_POKE:cdback");
	TextDrawFont(Zegar[0], 4);
	TextDrawTextSize(Zegar[0], 91.000, 38.500);
	TextDrawColor(Zegar[0], 799);

	Zegar[1] = TextDrawCreate(535.000, 2.500, "ld_grav:timer");
	TextDrawFont(Zegar[1], 4);
	TextDrawTextSize(Zegar[1], 10.000, 11.500);
	TextDrawColor(Zegar[1], -1);

	WalizkaDraw[0] = TextDrawCreate(517.000, 295.000, "LD_POKE:cdback");//Walizka Box
	TextDrawFont(WalizkaDraw[0], 4);
	TextDrawTextSize(WalizkaDraw[0], 100.000, 44.500);
	TextDrawColor(WalizkaDraw[0], 799);

	WalizkaDraw[1] = TextDrawCreate(521.932495, 310.333282, "~g~Walizka: ~r~Gdzies w /ls :)");
	TextDrawLetterSize(WalizkaDraw[1], 0.222764, 1.045832);
	TextDrawAlignment(WalizkaDraw[1], 1);
	TextDrawColor(WalizkaDraw[1], -1);
	TextDrawSetShadow(WalizkaDraw[1], 0);
	TextDrawSetOutline(WalizkaDraw[1], 1);
	TextDrawBackgroundColor(WalizkaDraw[1], 51);
	TextDrawFont(WalizkaDraw[1], 1);
	TextDrawSetProportional(WalizkaDraw[1], 1);

	ReactionDraw = TextDrawCreate(520.058593, 261.333312, "Test reakcji~w~: ~r~SfDs98Sa");
	TextDrawLetterSize(ReactionDraw, 0.211052, 1.104166);
	TextDrawAlignment(ReactionDraw, 1);
	TextDrawColor(ReactionDraw, -5963521);
	TextDrawSetShadow(ReactionDraw, 0);
	TextDrawSetOutline(ReactionDraw, 1);
	TextDrawBackgroundColor(ReactionDraw, 51);
	TextDrawFont(ReactionDraw, 1);
	TextDrawSetProportional(ReactionDraw, 1);

	Matematyka = TextDrawCreate(519.122253, 277.083374, "Test matematyczny~w~: ~r~7x8+2");
	TextDrawLetterSize(Matematyka, 0.211052, 1.104166);
	TextDrawAlignment(Matematyka, 1);
	TextDrawColor(Matematyka, -5963521);
	TextDrawSetShadow(Matematyka, 0);
	TextDrawSetOutline(Matematyka, 1);
	TextDrawBackgroundColor(Matematyka, 51);
	TextDrawFont(Matematyka, 1);
	TextDrawSetProportional(Matematyka, 1);

	CountDraw = TextDrawCreate(318.00, 270.00, "~b~~h~START~w~!!!");
	TextDrawAlignment(CountDraw, 2);
	TextDrawBackgroundColor(CountDraw, 255);
	TextDrawFont(CountDraw, 3);
	TextDrawLetterSize(CountDraw, 0.730000, 2.800000);
	TextDrawColor(CountDraw, -1);
	TextDrawSetOutline(CountDraw, 0);
	TextDrawSetProportional(CountDraw, 1);
	TextDrawSetShadow(CountDraw, 1);

	FunDrawBox[0] = TextDrawCreate(52.000, 223.000, "LD_POKE:cdback");//Even Box
	TextDrawFont(FunDrawBox[0], 4);
	TextDrawTextSize(FunDrawBox[0], 68.500, 109.000);
	TextDrawColor(FunDrawBox[0], 799);

	FunDrawBox[1] = TextDrawCreate(58.565109, 212.333419, "Event Box");
	TextDrawLetterSize(FunDrawBox[1], 0.370350, 1.716665);
	TextDrawAlignment(FunDrawBox[1], 1);
	TextDrawColor(FunDrawBox[1], -5963521);
	TextDrawSetShadow(FunDrawBox[1], 0);
	TextDrawSetOutline(FunDrawBox[1], 1);
	TextDrawBackgroundColor(FunDrawBox[1], 51);
	TextDrawFont(FunDrawBox[1], 0);
	TextDrawSetProportional(FunDrawBox[1], 1);

	FunDraw[0] = TextDrawCreate(67.935569, 232.749862, "/WG ~r~0/4");
	TextDrawLetterSize(FunDraw[0], 0.256031, 0.987497);
	TextDrawAlignment(FunDraw[0], 1);
	TextDrawColor(FunDraw[0], -1);
	TextDrawSetShadow(FunDraw[0], 0);
	TextDrawSetOutline(FunDraw[0], 1);
	TextDrawBackgroundColor(FunDraw[0], 51);
	TextDrawFont(FunDraw[0], 1);
	TextDrawSetProportional(FunDraw[0], 1);

	FunDraw[1] = TextDrawCreate(69.341293, 246.750000, "/CH ~r~0/4");
	TextDrawLetterSize(FunDraw[1], 0.256031, 0.987497);
	TextDrawAlignment(FunDraw[1], 1);
	TextDrawColor(FunDraw[1], -1);
	TextDrawSetShadow(FunDraw[1], 0);
	TextDrawSetOutline(FunDraw[1], 1);
	TextDrawBackgroundColor(FunDraw[1], 51);
	TextDrawFont(FunDraw[1], 1);
	TextDrawSetProportional(FunDraw[1], 1);

	FunDraw[2] = TextDrawCreate(70.278228, 260.750030, "/SS ~r~0/2");
	TextDrawLetterSize(FunDraw[2], 0.256031, 0.987497);
	TextDrawAlignment(FunDraw[2], 1);
	TextDrawColor(FunDraw[2], -1);
	TextDrawSetShadow(FunDraw[2], 0);
	TextDrawSetOutline(FunDraw[2], 1);
	TextDrawBackgroundColor(FunDraw[2], 51);
	TextDrawFont(FunDraw[2], 1);
	TextDrawSetProportional(FunDraw[2], 1);

	FunDraw[3] = TextDrawCreate(69.341186, 274.749908, "/HY ~r~0/3");
	TextDrawLetterSize(FunDraw[3], 0.256031, 0.987497);
	TextDrawAlignment(FunDraw[3], 1);
	TextDrawColor(FunDraw[3], -1);
	TextDrawSetShadow(FunDraw[3], 0);
	TextDrawSetOutline(FunDraw[3], 1);
	TextDrawBackgroundColor(FunDraw[3], 51);
	TextDrawFont(FunDraw[3], 1);
	TextDrawSetProportional(FunDraw[3], 1);

	FunDraw[4] = TextDrawCreate(68.404121, 289.916595, "/TW ~r~0/4");
	TextDrawLetterSize(FunDraw[4], 0.256031, 0.987497);
	TextDrawAlignment(FunDraw[4], 1);
	TextDrawColor(FunDraw[4], -1);
	TextDrawSetShadow(FunDraw[4], 0);
	TextDrawSetOutline(FunDraw[4], 1);
	TextDrawBackgroundColor(FunDraw[4], 51);
	TextDrawFont(FunDraw[4], 1);
	TextDrawSetProportional(FunDraw[4], 1);

	FunDraw[5] = TextDrawCreate(68.403991, 303.916687, "/DD ~r~0/4");
	TextDrawLetterSize(FunDraw[5], 0.256031, 0.987497);
	TextDrawAlignment(FunDraw[5], 1);
	TextDrawColor(FunDraw[5], -1);
	TextDrawSetShadow(FunDraw[5], 0);
	TextDrawSetOutline(FunDraw[5], 1);
	TextDrawBackgroundColor(FunDraw[5], 51);
	TextDrawFont(FunDraw[5], 1);
	TextDrawSetProportional(FunDraw[5], 1);
	TDArenki[0] = TextDrawCreate(132.591613, 349.999969, "/Minigun___~w~(~r~0~w~~)");
	TextDrawLetterSize(TDArenki[0], 0.214800, 0.923330);
	TextDrawAlignment(TDArenki[0], 1);
	TextDrawColor(TDArenki[0], -5963521);
	TextDrawSetShadow(TDArenki[0], 0);
	TextDrawSetOutline(TDArenki[0], 1);
	TextDrawBackgroundColor(TDArenki[0], 51);
	TextDrawFont(TDArenki[0], 2);
	TextDrawSetProportional(TDArenki[0], 1);

	TDArenki[1] = TextDrawCreate(140.556411, 377.416595, "/OneShoot___~w~(~r~0~w~~)");
	TextDrawLetterSize(TDArenki[1] , 0.214800, 0.923330);
	TextDrawAlignment(TDArenki[1] , 1);
	TextDrawColor(TDArenki[1] , -5963521);
	TextDrawSetShadow(TDArenki[1] , 0);
	TextDrawSetOutline(TDArenki[1] , 1);
	TextDrawBackgroundColor(TDArenki[1] , 51);
	TextDrawFont(TDArenki[1] , 2);
	TextDrawSetProportional(TDArenki[1] , 1);

	TDArenki[2]  = TextDrawCreate(141.024917, 363.999969, "/RPG___~w~(~r~0~w~~)");
	TextDrawLetterSize(TDArenki[2], 0.214800, 0.923330);
	TextDrawAlignment(TDArenki[2], 1);
	TextDrawColor(TDArenki[2], -5963521);
	TextDrawSetShadow(TDArenki[2], 0);
	TextDrawSetOutline(TDArenki[2], 1);
	TextDrawBackgroundColor(TDArenki[2], 51);
	TextDrawFont(TDArenki[2], 2);
	TextDrawSetProportional(TDArenki[2], 1);

	TDArenki[3] = TextDrawCreate(139.150665, 390.833465, "/Jetpack___~w~(~r~0~w~~)");
	TextDrawLetterSize(TDArenki[3], 0.214800, 0.923330);
	TextDrawAlignment(TDArenki[3], 1);
	TextDrawColor(TDArenki[3], -5963521);
	TextDrawSetShadow(TDArenki[3], 0);
	TextDrawSetOutline(TDArenki[3], 1);
	TextDrawBackgroundColor(TDArenki[3], 51);
	TextDrawFont(TDArenki[3], 2);
	TextDrawSetProportional(TDArenki[3], 1);

	TDArenki[4] = TextDrawCreate(131.185974, 403.083343, "/Snajper___~w~(~r~0~w~~)");
	TextDrawLetterSize(TDArenki[4], 0.214800, 0.923330);
	TextDrawAlignment(TDArenki[4], 1);
	TextDrawColor(TDArenki[4], -5963521);
	TextDrawSetShadow(TDArenki[4], 0);
	TextDrawSetOutline(TDArenki[4], 1);
	TextDrawBackgroundColor(TDArenki[4], 51);
	TextDrawFont(TDArenki[4], 2);
	TextDrawSetProportional(TDArenki[4], 1);

	TDPolecamy = TextDrawCreate(109.165527, 320.833343, "Polecamy:~n~   ~r~/Serwer");
	TextDrawLetterSize(TDPolecamy, 0.239632, 1.349164);
	TextDrawAlignment(TDPolecamy, 1);
	TextDrawColor(TDPolecamy, -1);
	TextDrawSetShadow(TDPolecamy, 0);
	TextDrawSetOutline(TDPolecamy, 1);
	TextDrawBackgroundColor(TDPolecamy, 51);
	TextDrawFont(TDPolecamy, 1);
	TextDrawSetProportional(TDPolecamy, 1);

	AnnTD = TextDrawCreate(320.0, 110.0, " ");
	TextDrawAlignment(AnnTD, 2);
	TextDrawBackgroundColor(AnnTD, 31);
	TextDrawFont(AnnTD, 1);
	TextDrawLetterSize(AnnTD, 0.290000, 1.0);
	TextDrawColor(AnnTD, -1);
	TextDrawSetOutline(AnnTD, 1);
	TextDrawSetProportional(AnnTD, 1);

	ZegarDraw = TextDrawCreate(565.037231, 1.749988, "~g~00~r~:~g~00");
	TextDrawLetterSize(ZegarDraw, 0.259780, 1.174165);
	TextDrawAlignment(ZegarDraw, 1);
	TextDrawColor(ZegarDraw, -1);
	TextDrawSetShadow(ZegarDraw, 0);
	TextDrawSetOutline(ZegarDraw, 1);
	TextDrawBackgroundColor(ZegarDraw, 51);
	TextDrawFont(ZegarDraw, 1);
	TextDrawSetProportional(ZegarDraw, 1);

	DataDraw = TextDrawCreate(551.918334, 11.083314, "~g~24~r~:~g~02~r~:~g~2014");
	TextDrawLetterSize(DataDraw, 0.259779, 1.174165);
	TextDrawAlignment(DataDraw, 1);
	TextDrawColor(DataDraw, -1);
	TextDrawSetShadow(DataDraw, 0);
	TextDrawSetOutline(DataDraw, 1);
	TextDrawBackgroundColor(DataDraw, 51);
	TextDrawFont(DataDraw, 1);
	TextDrawSetProportional(DataDraw, 1);

	Wybieralka[0] = TextDrawCreate(641.531494, 381.250000, "usebox");
	TextDrawLetterSize(Wybieralka[0], 0.000000, 7.201854);
	TextDrawTextSize(Wybieralka[0], -2.000000, 0.000000);
	TextDrawAlignment(Wybieralka[0], 1);
	TextDrawColor(Wybieralka[0], 0);
	TextDrawUseBox(Wybieralka[0], true);
	TextDrawBoxColor(Wybieralka[0], 102);
	TextDrawSetShadow(Wybieralka[0], 0);
	TextDrawSetOutline(Wybieralka[0], 0);
	TextDrawFont(Wybieralka[0], 0);

	Wybieralka[1] = TextDrawCreate(756.319335, 0.916592, "usebox");
	TextDrawLetterSize(Wybieralka[1], 0.000000, 7.097224);
	TextDrawTextSize(Wybieralka[1], -9.027824, 0.000000);
	TextDrawAlignment(Wybieralka[1], 1);
	TextDrawColor(Wybieralka[1], 0);
	TextDrawUseBox(Wybieralka[1], true);
	TextDrawBoxColor(Wybieralka[1], 102);
	TextDrawSetShadow(Wybieralka[1], 0);
	TextDrawSetOutline(Wybieralka[1], 0);
	TextDrawFont(Wybieralka[1], 0);

	Wybieralka[2] = TextDrawCreate(0.000000, 375.666687, "LD_SPAC:white");
	TextDrawLetterSize(Wybieralka[2], 0.000000, 0.000000);
	TextDrawTextSize(Wybieralka[2], 640.000000, 3.500000);
	TextDrawAlignment(Wybieralka[2], 1);
	TextDrawColor(Wybieralka[2], 8388863);
	TextDrawSetShadow(Wybieralka[2], 0);
	TextDrawSetOutline(Wybieralka[2], 0);
	TextDrawFont(Wybieralka[2], 4);

	Wybieralka[3] = TextDrawCreate(0.000000, 67.666671, "LD_SPAC:white");
	TextDrawLetterSize(Wybieralka[3], 0.000000, 0.000000);
	TextDrawTextSize(Wybieralka[3], 640.000000, 3.500000);
	TextDrawAlignment(Wybieralka[3], 1);
	TextDrawColor(Wybieralka[3], 8388863);
	TextDrawSetShadow(Wybieralka[3], 0);
	TextDrawSetOutline(Wybieralka[3], 0);
	TextDrawFont(Wybieralka[3], 4);

	Wybieralka[4] = TextDrawCreate(230.980880, 378.583282, "~>~  Dziekujemy za to ze jestes z Nami!  ~<~");
	TextDrawLetterSize(Wybieralka[4], 0.262122, 1.290832);
	TextDrawAlignment(Wybieralka[4], 1);
	TextDrawColor(Wybieralka[4], 16711935);
	TextDrawSetShadow(Wybieralka[4], 0);
	TextDrawSetOutline(Wybieralka[4], 1);
	TextDrawBackgroundColor(Wybieralka[4], 51);
	TextDrawFont(Wybieralka[4], 3);
	TextDrawSetProportional(Wybieralka[4], 1);

	Wybieralka[5] = TextDrawCreate(637.783325, 392.916687, "usebox");
	TextDrawLetterSize(Wybieralka[5], 0.000000, 4.803700);
	TextDrawTextSize(Wybieralka[5], 493.695465, 0.000000);
	TextDrawAlignment(Wybieralka[5], 1);
	TextDrawColor(Wybieralka[5], 0);
	TextDrawUseBox(Wybieralka[5], true);
	TextDrawBoxColor(Wybieralka[5], 102);
	TextDrawSetShadow(Wybieralka[5], 0);
	TextDrawSetOutline(Wybieralka[5], 0);
	TextDrawFont(Wybieralka[5], 0);

	Wybieralka[6] = TextDrawCreate(547.233337, 386.749938, "informacje");
	TextDrawLetterSize(Wybieralka[6], 0.152487, 0.841665);
	TextDrawAlignment(Wybieralka[6], 1);
	TextDrawColor(Wybieralka[6], -65281);
	TextDrawSetShadow(Wybieralka[6], 0);
	TextDrawSetOutline(Wybieralka[6], 1);
	TextDrawBackgroundColor(Wybieralka[6], 51);
	TextDrawFont(Wybieralka[6], 2);
	TextDrawSetProportional(Wybieralka[6], 1);

	Wybieralka[7] = TextDrawCreate(565.505432, 394.333251, "~g~~w~Po calej mapie zostaly~n~porozstawiane figurki.~n~~n~~g~~h~GM jest w wersji beta.");
	TextDrawLetterSize(Wybieralka[7], 0.161859, 1.104166);
	TextDrawAlignment(Wybieralka[7], 2);
	TextDrawColor(Wybieralka[7], -1);
	TextDrawSetShadow(Wybieralka[7], 0);
	TextDrawSetOutline(Wybieralka[7], 1);
	TextDrawBackgroundColor(Wybieralka[7], 51);
	TextDrawFont(Wybieralka[7], 1);
	TextDrawSetProportional(Wybieralka[7], 1);

	Wybieralka[8] = TextDrawCreate(298.916870, 363.416839, "Skin ID: 5");
	TextDrawLetterSize(Wybieralka[8], 0.212927, 1.314165);
	TextDrawAlignment(Wybieralka[8], 1);
	TextDrawColor(Wybieralka[8], -2139062017);
	TextDrawSetShadow(Wybieralka[8], 0);
	TextDrawSetOutline(Wybieralka[8], 1);
	TextDrawBackgroundColor(Wybieralka[8], 51);
	TextDrawFont(Wybieralka[8], 2);
	TextDrawSetProportional(Wybieralka[8], 1);

    StatyBox[0] = TextDrawCreate(205.000, 395.500, "LD_POKE:cdback");
    TextDrawFont(StatyBox[0], 4);
    TextDrawTextSize(StatyBox[0], 367.000, 37.000);
    TextDrawColor(StatyBox[0], 799);

    StatyBox[1] = TextDrawCreate(229.575424, 388.499938, "Nick");
    TextDrawLetterSize(StatyBox[1], 0.248535, 1.191666);
    TextDrawAlignment(StatyBox[1], 2);
    TextDrawColor(StatyBox[1], -5963521);
    TextDrawSetShadow(StatyBox[1], 0);
    TextDrawSetOutline(StatyBox[1], 1);
    TextDrawBackgroundColor(StatyBox[1], 51);
    TextDrawFont(StatyBox[1], 2);
    TextDrawSetProportional(StatyBox[1], 1);

    StatyBox[2] = TextDrawCreate(272.211425, 389.083343, "Respekt");
    TextDrawLetterSize(StatyBox[2], 0.248535, 1.191666);
    TextDrawAlignment(StatyBox[2], 1);
    TextDrawColor(StatyBox[2], -5963521);
    TextDrawSetShadow(StatyBox[2], 0);
    TextDrawSetOutline(StatyBox[2], 1);
    TextDrawBackgroundColor(StatyBox[2], 51);
    TextDrawFont(StatyBox[2], 2);
    TextDrawSetProportional(StatyBox[2], 1);

    StatyBox[3] = TextDrawCreate(353.734436, 389.083465, "Level");
    TextDrawLetterSize(StatyBox[3], 0.248535, 1.191666);
    TextDrawAlignment(StatyBox[3], 2);
    TextDrawColor(StatyBox[3], -5963521);
    TextDrawSetShadow(StatyBox[3], 0);
    TextDrawSetOutline(StatyBox[3], 1);
    TextDrawBackgroundColor(StatyBox[3], 51);
    TextDrawFont(StatyBox[3], 2);
    TextDrawSetProportional(StatyBox[3], 1);

    StatyBox[4] = TextDrawCreate(401.054565, 389.083312, "Gang");
    TextDrawLetterSize(StatyBox[4], 0.248535, 1.191666);
    TextDrawAlignment(StatyBox[4], 2);
    TextDrawColor(StatyBox[4], -5963521);
    TextDrawSetShadow(StatyBox[4], 0);
    TextDrawSetOutline(StatyBox[4], 1);
    TextDrawBackgroundColor(StatyBox[4], 51);
    TextDrawFont(StatyBox[4], 2);
    TextDrawSetProportional(StatyBox[4], 1);

    StatyBox[5] = TextDrawCreate(439.942230, 389.083343, "Czas_Gry");
    TextDrawLetterSize(StatyBox[5], 0.248535, 1.191666);
    TextDrawAlignment(StatyBox[5], 1);
    TextDrawColor(StatyBox[5], -5963521);
    TextDrawSetShadow(StatyBox[5], 0);
    TextDrawSetOutline(StatyBox[5], 1);
    TextDrawBackgroundColor(StatyBox[5], 51);
    TextDrawFont(StatyBox[5], 2);
    TextDrawSetProportional(StatyBox[5], 1);

    StatyBox[6] = TextDrawCreate(536.457458, 390.250061, "Online");
    TextDrawLetterSize(StatyBox[6], 0.248535, 1.191666);
    TextDrawAlignment(StatyBox[6], 2);
    TextDrawColor(StatyBox[6], -5963521);
    TextDrawSetShadow(StatyBox[6], 0);
    TextDrawSetOutline(StatyBox[6], 1);
    TextDrawBackgroundColor(StatyBox[6], 51);
    TextDrawFont(StatyBox[6], 2);
    TextDrawSetProportional(StatyBox[6], 1);
	
	Reklama = TextDrawCreate(366.383911, 433.416687, "Adres naszego forum znajdziesz pod ~r~TOP.xaa.pl");
	TextDrawLetterSize(Reklama, 0.218081, 1.308333);
	TextDrawAlignment(Reklama, 2);
	TextDrawColor(Reklama, -1);
	TextDrawSetShadow(Reklama, 0);
	TextDrawSetOutline(Reklama, 1);
	TextDrawBackgroundColor(Reklama, 51);
	TextDrawFont(Reklama, 1);
	TextDrawSetProportional(Reklama, 1);

    LicznikBox = TextDrawCreate(541.000, 329.500, "LD_POKE:cdback");
    TextDrawFont(LicznikBox, 4);
    TextDrawTextSize(LicznikBox, 92.500, 53.500);
    TextDrawColor(LicznikBox, 799);

    PW[0] = TextDrawCreate(161.500, 305.500, "LD_POKE:cdback");
    TextDrawFont(PW[0], 4);
    TextDrawTextSize(PW[0], 110.500, 23.500);
    TextDrawColor(PW[0], 799);

    PW[1] = TextDrawCreate(215.988311, 311.499908, "Nowa Wiadomosc ~r~!");
    TextDrawLetterSize(PW[1], 0.199341, 0.987499);
    TextDrawAlignment(PW[1], 2);
    TextDrawColor(PW[1], -5963521);
    TextDrawSetShadow(PW[1], 0);
    TextDrawSetOutline(PW[1], 1);
    TextDrawBackgroundColor(PW[1], 51);
    TextDrawFont(PW[1], 2);
    TextDrawSetProportional(PW[1], 1);
	
	for(new i; i != MAX_PLAYERS; i++)
	{
		TD_Nick[i] = TextDrawCreate(240.819824, 410.666748, "~w~(~y~0~w~)MajsterSzefImpry[RW]");
		TextDrawLetterSize(TD_Nick[i], 0.175907, 0.987496);
		TextDrawAlignment(TD_Nick[i], 2);
		TextDrawColor(TD_Nick[i], -1);
		TextDrawSetShadow(TD_Nick[i], 0);
		TextDrawSetOutline(TD_Nick[i], 1);
		TextDrawBackgroundColor(TD_Nick[i], 51);
		TextDrawFont(TD_Nick[i], 1);
		TextDrawSetProportional(TD_Nick[i], 1);

		TD_Exp[i] = TextDrawCreate(294.231445, 410.083251, "123");
		TextDrawLetterSize(TD_Exp[i], 0.175907, 0.987496);
		TextDrawAlignment(TD_Exp[i], 2);
		TextDrawColor(TD_Exp[i], -1);
		TextDrawSetShadow(TD_Exp[i], 0);
		TextDrawSetOutline(TD_Exp[i], 1);
		TextDrawBackgroundColor(TD_Exp[i], 51);
		TextDrawFont(TD_Exp[i], 1);
		TextDrawSetProportional(TD_Exp[i], 1);

		TD_Level[i] = TextDrawCreate(352.328399, 409.499847, "13");
		TextDrawLetterSize(TD_Level[i], 0.175907, 0.987496);
		TextDrawAlignment(TD_Level[i], 2);
		TextDrawColor(TD_Level[i], -1);
		TextDrawSetShadow(TD_Level[i], 0);
		TextDrawSetOutline(TD_Level[i], 1);
		TextDrawBackgroundColor(TD_Level[i], 51);
		TextDrawFont(TD_Level[i], 1);
		TextDrawSetProportional(TD_Level[i], 1);

		TD_Gang[i] = TextDrawCreate(387.936187, 410.083221, "/gang");
		TextDrawLetterSize(TD_Gang[i], 0.175907, 0.987496);
		TextDrawAlignment(TD_Gang[i], 1);
		TextDrawColor(TD_Gang[i], -1);
		TextDrawSetShadow(TD_Gang[i], 0);
		TextDrawSetOutline(TD_Gang[i], 1);
		TextDrawBackgroundColor(TD_Gang[i], 51);
		TextDrawFont(TD_Gang[i], 1);
		TextDrawSetProportional(TD_Gang[i], 1);

		TD_Online[i] = TextDrawCreate(441.816040, 408.916809, "0 godz 0 min 0 sek");
		TextDrawLetterSize(TD_Online[i], 0.175907, 0.987496);
		TextDrawAlignment(TD_Online[i], 1);
		TextDrawColor(TD_Online[i], -1);
		TextDrawSetShadow(TD_Online[i], 0);
		TextDrawSetOutline(TD_Online[i], 1);
		TextDrawBackgroundColor(TD_Online[i], 51);
		TextDrawFont(TD_Online[i], 1);
		TextDrawSetProportional(TD_Online[i], 1);

		Graczy[i] = TextDrawCreate(535.988891, 410.083221, "(0/~y~0~w~/~r~0~w~)");
		TextDrawLetterSize(Graczy[i], 0.175907, 0.987496);
		TextDrawAlignment(Graczy[i], 2);
		TextDrawColor(Graczy[i], -1);
		TextDrawSetShadow(Graczy[i], 0);
		TextDrawSetOutline(Graczy[i], 1);
		TextDrawBackgroundColor(Graczy[i], 51);
		TextDrawFont(Graczy[i], 1);
		TextDrawSetProportional(Graczy[i], 1);
		//
		TD_Ping[i] = TextDrawCreate(614.231994, 22.750007, "Ping: ~w~100");
		TextDrawLetterSize(TD_Ping[i], 0.161859, 0.870832);
		TextDrawAlignment(TD_Ping[i], 1);
		TextDrawColor(TD_Ping[i], -5963521);
		TextDrawSetShadow(TD_Ping[i], 0);
		TextDrawSetOutline(TD_Ping[i], 1);
		TextDrawBackgroundColor(TD_Ping[i], 51);
		TextDrawFont(TD_Ping[i], 1);
		TextDrawSetProportional(TD_Ping[i], 1);

		TD_FPS[i] = TextDrawCreate(616.105773, 30.916620, "FPS: ~w~100");
		TextDrawLetterSize(TD_FPS[i], 0.161859, 0.870832);
		TextDrawAlignment(TD_FPS[i], 1);
		TextDrawColor(TD_FPS[i], -5963521);
		TextDrawSetShadow(TD_FPS[i], 0);
		TextDrawSetOutline(TD_FPS[i], 1);
		TextDrawBackgroundColor(TD_FPS[i], 51);
		TextDrawFont(TD_FPS[i], 1);
		TextDrawSetProportional(TD_FPS[i], 1);

		Stan[0][i] = TextDrawCreate(586.589599, 331.333404, "Infernus~n~HP: ~r~100");
		TextDrawLetterSize(Stan[0][i], 0.219953, 1.308331);
		TextDrawAlignment(Stan[0][i], 2);
		TextDrawColor(Stan[0][i], -5963521);
		TextDrawSetShadow(Stan[0][i], 0);
		TextDrawSetOutline(Stan[0][i], 1);
		TextDrawBackgroundColor(Stan[0][i], 51);
		TextDrawFont(Stan[0][i], 2);
		TextDrawSetProportional(Stan[0][i], 1);

		Stan[1][i] = TextDrawCreate(587.057617, 356.999877, "Predkosc~n~km/h: ~r~100");
		TextDrawLetterSize(Stan[1][i], 0.219953, 1.308331);
		TextDrawAlignment(Stan[1][i], 2);
		TextDrawColor(Stan[1][i], -5963521);
		TextDrawSetShadow(Stan[1][i], 0);
		TextDrawSetOutline(Stan[1][i], 1);
		TextDrawBackgroundColor(Stan[1][i], 51);
		TextDrawFont(Stan[1][i], 2);
		TextDrawSetProportional(Stan[1][i], 1);

		Zycie_TD[i] = TextDrawCreate(568.000000, 68.000000, "100%");
		TextDrawBackgroundColor(Zycie_TD[i], 255);
		TextDrawFont(Zycie_TD[i], 1);
		TextDrawLetterSize(Zycie_TD[i], 0.170000, 0.599999);
		TextDrawColor(Zycie_TD[i], -1);
		TextDrawSetOutline(Zycie_TD[i], 0);
		TextDrawSetProportional(Zycie_TD[i], 1);
		TextDrawSetShadow(Zycie_TD[i], 1);

		Armor_TD[i] = TextDrawCreate(568.000000, 46.000000, "100%");
		TextDrawBackgroundColor(Armor_TD[i], 255);
		TextDrawFont(Armor_TD[i], 1);
		TextDrawLetterSize(Armor_TD[i], 0.170000, 0.599999);
		TextDrawColor(Armor_TD[i], -1);
		TextDrawSetOutline(Armor_TD[i], 0);
		TextDrawSetProportional(Armor_TD[i], 1);
		TextDrawSetShadow(Armor_TD[i], 1);

		GameDraw[i] = TextDrawCreate(320.0, 130.0, " ");
		TextDrawAlignment(GameDraw[i], 2);
		TextDrawBackgroundColor(GameDraw[i], 51);
		TextDrawFont(GameDraw[i], 3);
		TextDrawLetterSize(GameDraw[i], 0.500000, 1.0);
		TextDrawColor(GameDraw[i], 11206638);
		TextDrawSetOutline(GameDraw[i], 1);
		TextDrawSetProportional(GameDraw[i], 1);

	}
	return 1;
}
