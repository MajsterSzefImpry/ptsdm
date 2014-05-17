/*
	@Polski TOP Serwer - header.inc
	@Last update: 14 marca 2014 23:25

*/
new Text:PW[2];
enum Glosowanie
{
	glos[2],
	Text:TDVote[2],
	vOdliczanka,
	TimerGlosowanie,
	votebuffer[3000]
};

new mVote[Glosowanie];
new Skin_User[MAX_PLAYERS];
new EventTimer;
new Text:Event;
new Text:Naprawa_TD[2]; 
new Bankomat[3];
new gunshop_lv_outside;
new gunshop_lv_inside;
new sklep_lv;
new bool:TytulChce[MAX_PLAYERS];
new ColorTranslateCD = 0;
new ColorTranslate[64] = {
0xFC0000FF, 0xFC002AFF, 0xFC0048FF, 0xFC0065FF, 0xFC0087FF, 0xFC00A0FF, 0xFC00BDFF,0xFC00DBFF, 0xFC00F8FF,
0xE300FCFF, 0xD200FCFF, 0xB900FCFF, 0xA800FCFF, 0x9C00FCFF, 0x8B00FCFF, 0x7A00FCFF, 0x6500FCFF, 0x5000FCFF,
0x3700FCFF, 0x1900FCFF, 0x0004FCFF, 0x001DFCFF, 0x003BFCFF, 0x0050FCFF, 0x006DFCFF, 0x0087FCFF, 0x009CFCFF,
0x00B5FCFF, 0x00C6FCFF, 0x00DBFCFF, 0x00ECFCFF, 0x00FCF8FF, 0x00FCDFFF, 0x00FCC6FF, 0x00FCB5FF, 0x00FCA0FF,
0x00FC87FF, 0x00FC76FF, 0x00FC61FF, 0x00FC4CFF, 0x00FC3BFF, 0x00FC1DFF, 0x00FC00FF, 0x2AFC00FF, 0x48FC00FF,
0x5DFC00FF, 0x65FC00FF, 0x7EFC00FF, 0x97FC00FF, 0xA8FC00FF, 0xB9FC00FF, 0xD7FC00FF, 0xF0FC00FF, 0xFCEC00FF,
0xFCDF00FF, 0xFCD700FF, 0xFCCA00FF, 0xFCB900FF, 0xFC9C00FF, 0xFC8700FF, 0xFC7600FF, 0xFC5800FF, 0xFC3700FF,
0xFC0000FF
};
new Float:pHealth[MAX_PLAYERS];
new Float:pArmour[MAX_PLAYERS];
new WojskoZone;
new WojskoSklep;
new Text:StrefaDM;
new EndUzycieNprawa[MAX_PLAYERS];
new Float:PrivPrzebieg[MAX_PLAYERS];
new PrivSpeed[MAX_PLAYERS];
new bool:MaPrivCar[MAX_PLAYERS];
new bool:ZespawnowanyPrivCar[MAX_PLAYERS];
new PrivCar[MAX_VEHICLES] = {-1, ...};
new Float:PrivCarPos[MAX_PLAYERS][3];
new Text3D:PrywatnyPojazdLabel[MAX_PLAYERS];
new SelectedPrivCar[MAX_PLAYERS];
new PrywatnyPojazd[MAX_PLAYERS];
new IdzDo[MAX_PLAYERS];
new TabSelectedPlayerId[MAX_PLAYERS];
new Text:TD_Teleport_;
new Text:TD_Pojazd;
new PlayerText: ID_Skin;
new buycarid[] = {400,401,402,404,405,409,410,411,412,413,414,415,418,419,420,421,422,423,424,426,428,429,
		434,436,431,437,438,439,440,442,445,451,457,458,459,466,467,474,475,477,478,479,480,482,483,489,490,491,492,
		494,495,496,498,499,500,502,503,504,505,506,507,508,516,517,518,525,526,527,529,533,534,535,536,540,541,542,
		543,545,546,547,549,550,551,552,554,555,558,559,560,561,562,565,566,567,568,573,575,576,578,579,580,582,585,
		587,588,589,600,602,603,609
};
new bool:ObliczStatus;
new ObliczWynik;
new Level[MAX_PLAYERS];
#define MAX_ZONES 12
new
bool: Spawned[MAX_PLAYERS],
bool: GetPos[MAX_PLAYERS]
;
new bool:Vip[MAX_PLAYERS];
new Text:Logo;
new Text:NazwaMapy;
new Text:StatyBox[7];
new Text:www_top;
new Text:DataDraw;
new Text:TD_Nick[MAX_PLAYERS];
new Text:TD_Exp[MAX_PLAYERS];
new Text:TD_Level[MAX_PLAYERS];
new Text:TD_Online[MAX_PLAYERS];
new Text:TD_FPS[MAX_PLAYERS];
new Text:TD_Ping[MAX_PLAYERS];
new Text:TD_Gang[MAX_PLAYERS];
new Text:Wybieralka[9];
new Text:FunDrawBox[2];
new Text:Graczy[MAX_PLAYERS];
new Text:LicznikBox;
new Text:Armor_TD[MAX_PLAYERS];
new Text:Zycie_TD[MAX_PLAYERS];
new Text:Zegar[2];
new Text:TDArenkiBox;
new Text:Stan[2][MAX_PLAYERS];
new bool:vdot[MAX_PLAYERS];
new chattext[200];
new antifakekill[MAX_PLAYERS];
#define RATE_INC (500)
#define RATE_MAX (2500)
#define THRESOLD_ACTION 1
enum LIST_ANTIFLOOD
{
        lastCheck,
        floodRate
}
new bool:Invisible[MAX_PLAYERS];
new bool:ColorAdmina[MAX_PLAYERS];
new WarnSystem[MAX_PLAYERS];
new bool:WarnBlock[MAX_PLAYERS];
new bool:gdot[MAX_PLAYERS];
new AntiFlood_Data[MAX_PLAYERS][LIST_ANTIFLOOD];
new polecamy;
new fucions;
new Text:Reklama;
new reklamaTD[2][222] =
{
	"Nasze forum ~r~TOP.xaa.pl",
	"Chcesz kupic ~r~Konto Premium ~w~wpisz ~r~/VIP"
};
new fucionstd[2][222] =
{
		"Polecamy~w~:~n~   ~r~/CMD",
        "Polecamy~w~:~n~   ~r~/Autor"
};

new Float:SpawnGracza[][] = {
    {2525.27, -1667.66, 15.33},
    {2116.91, 908.07, 10.86},
    {-2034.61, 171.13, 28.94},
    {-1351.06, -287.9, 13.81},
    {402.98, 2535.56, 16.21},
    {283.3, 1425.15, 10.28},
    {1372.43, -1128.64, 24.11},
    {1384.00, -1553.54, 13.26},
    {3589.89, -1858.14, 318.25},
    {-3569.04, -284.93, 332.58},
    {2258.79, 561.29, 7.48},
    {1052.9558, 2098.7163, 11.3001},
    {1297.2101, 2087.6946, 11.8782},
    {2078.2688, 2391.6956, 62.1445},
    {2420.7444, 85.1041, 27.4837},
    {320.1945, -254.1495, 1.7928},
    {-60.2229, -1161.1866, 2.5433},
    {-1114.8076, -1643.8640, 77.2183},
    {-1544.4680, -2732.9597, 49.5561},
    {-2354.2405, -1625.9878, 485.1020},
    {-2541.5027, 584.3470, 16.1430},
    {-2160.9595, 934.6633, 80.7879},
    {-1876.7317, 1412.7522, 8.3158},
    {1206.4209, -1662.7686, 14.2529},
    {1124.5930, -2036.9486, 69.8680},
    {514.4565, -1537.4170, 16.4550}
};

new Float:CelaSpawn[11][3] = {
	{-1849.7830,1036.6741,49.0326},
	{-1849.8215,1031.6779,48.9995},
	{-1849.4756,1027.5597,48.9738},
	{-1849.5778,1023.4279,48.9462},
	{-1849.4622,1019.3947,48.9201},
	{-1850.0167,1014.3398,48.8845},
	{-1848.8113,1010.5651,48.8647},
	{-1849.4840,1004.8911,48.8245},
	{-1849.4874,1001.3494,48.8011},
	{-1849.5114,1018.5952,46.0939},
	{-1849.0236,1027.4972,46.0576}
};

new OnlineRekord;
new strx[2000], bstrx[1900];
new day, month, year, hour, minute;
new namemonth[][] = {"Styczen", "Luty", "Marzec", "Kwiecien", "Maj", "Czerwiec", "Lipiec", "Sierpien", "Wrzesien", "Pazdziernik", "Listopad", "Grudzien"};
#define MAX_MISSLES 300
#define MISSLE_SPEED 225.0
#define BLAST_RADIUS 25.0
new W_Pociski[MAX_MISSLES];
new Float:Wyrzutnie[4][3] = {//X, Y, Z
	{15.6185,1721.6699,23.8750},
	{237.4360,1698.6774,23.8673},
	{353.6885,2031.6732,22.6406},
	{187.3830,2084.9536,22.6468}
};
#define MAX_FIGUREK 50
#define FIGURKI_KASA 80000
#define FIGURKI_PUNKTY 25
new Figurki_ID[MAX_FIGUREK] = {-1, -1, -1, ...};
new Figurki_PICKUP[MAX_FIGUREK] = {-1, -1, -1, ...};
new walizka[3];
new Text:WalizkaDraw[2];
new Text:ReactionDraw;
new Text:Matematyka;
new Letters[61] = {'q','w','e','r','t','y','u','i','o','p','a','s','d','f','g','h','j','k','l','z','x','c',
	'v','b','n','m','Q','W','E','R','T','Y','U','I','O','P','A','S','D','F','G','J','K','L','Z','X','C','V','B','N','M','1','2','3','4','5','6','7','8','9','0'};
new TestReaction;
new TimerReaction;
new STRReaction[10];

#define MAX_RACE 50
enum RaceEnum
{
	Rname[40],
	Rid,
	Rall_cp,
    Rcp,
	Rmodelid,
	Float:Rx,
	Float:Ry,
	Float:Rz,
	Float:Rr
}
new RaceInfo[MAX_RACE][RaceEnum];
new RacesCount;
new Ksiezyc_Zone;
#define MAX_HOUSES 900
enum HouseEnum
{
	hName[40],
	hOwner[40],
	hID,
	Text3D:hLabel,
	hInt,
	hCP,
	hCost,
	Float:hX,
	Float:hY,
	Float:hZ,
	Float:hOX,
	Float:hOY,
	Float:hOZ,
	Float:hOA
}
new HouseInfo[MAX_HOUSES][HouseEnum];
new HouseCount;
new HousePic[6];
new pHouse[MAX_PLAYERS] = {-1, ...};
new Float:hPos[6][3] = {
    {2283.1999,-1137.1999,1050.5},
    {2307.6000,-1211.1999,1048.6},
    {2365.1999,-1133.3000,1050.5},
    {2333.0000,-1074.5999,1048.6},
    {2195.1999,-1204.4000,1048.6},
    {2316.8999,-1024.5000,1049.8}
};
new housesInt[6] = {11,6,8,6,6,9};
new hWorld;
new Text:TDArenki[5];
new Text:TDPolecamy;
new Text:FunDraw[6];
new DD_Off, DD_InCar, DD_Trwa, DD_Timer, DD_Zapisanych, DD_Odliczanie = -1, DD_Vehicles[14];
new WG_Off, WG_Zapisanych, WG_Trwa, WG_Team[2], WG_Timer, WG_Odliczanie = -1;
new Float:PozycjeWG[6], Float:WG_Dystans[3];
new IntWG;
new CH_Off, CH_Trwa, CH_Timer, CH_Zapisanych, CH_Szukajacy, CH_Odliczanie = -1;
new Float:PozycjeCH[6];
new IntCH;
new TW_Off, TW_Trwa, TW_Timer, TW_Zapisanych, TW_Odliczanie = -1, TW_Checkpoint, TW_Tick;
new HAY_Off, HAY_Trwa, HAY_Timer, HAY_Zapisanych, HAY_Odliczanie = -1, Iterator:HAY_Array<25>;
new SS_Off, SS_Trwa, SS_Timer, SS_Zapisanych, SS_Odliczanie = -1;
new Float:PozycjeSS[6], SS_CP;
#define DM_RPG 0
#define DM_MINI 1
#define DM_OS 2
#define DM_JP 3
#define DM_SNP 4
new DM_Zone[5];
new Float:Spawn_SNP[7][3] = {
	{1455.71, 1494.55, 34.44},
	{1425.45, 1478.53, 34.44},
	{1476.37, 1456.07, 34.45},
	{1454.58, 1415.18, 34.45},
	{1484.23, 1378.87, 34.43},
	{1415.22, 1349.67, 34.45},
	{1441.25, 1365.25, 34.45}
};
new Float:Spawn_RPG[8][3] = {
	{2202.8660,-5583.9722,20.0781},
	{2171.2197,-5624.8550,11.0203},
	{2145.6191,-5629.2568,36.1781},
	{2078.0081,-5670.6387,36.1781},
	{2079.0212,-5612.1484,8.4250},
	{2079.7292,-5612.0659,8.4328},
	{2084.2783,-5538.6211,36.1781},
	{2182.8728,-5593.3848,4.0000}
};
new Float:Spawn_OS[10][3] = {
	{1555.48, 1562.88, 9.81},
	{1555.48, 1562.88, 9.81},
	{1607.30, 1563.24, 9.81},
	{1612.17, 1587.65, 9.81},
	{1575.17, 1604.28, 9.80},
	{1617.91, 1627.05, 9.79},
	{1548.09, 1571.66, 9.80},
	{1543.69, 1616.26, 9.81},
	{1562.71, 1631.64, 9.81},
	{1584.71, 1624.78, 9.82}
};
new Float:Spawn_JP[4][3] = {
	{1623.56, 1637.89, 9.82},
	{1528.49, 1636.75, 9.82},
	{1528.52, 1555.47, 9.83},
	{1623.65, 1552.88, 9.81}
};
#define BALLON_SPEED 20.0
new BallonID;
new BallonPos;
new BallonKierunek;
new Float:PosBallon[4][3] = {
	{2176.8604,946.8815,15.0},
	{2233.9170,708.7743,273.6292},
	{2482.7007,-1658.1559,234.0},
	{2530.1116,-1676.9552,19.3}
};
new BallonID2;
new BallonPos2;
new BallonKierunek2;
new Float:PosBallon2[9][3] = {
	{-1988.4332,303.2425,34.5},
	{-1975.7555,309.4731,81.6},
	{-1784.9650,400.3748,203.0},
	{-1131.6858,1496.2474,290.5},
	{-686.0074,1920.3247,183.3},
	{-352.9144,2077.8298,104.0},
	{205.9002,2163.6799,50.6},
	{237.3146,2317.0249,85.0},
	{364.3067,2470.4871,15.8}
};
new RampTypes[10] = {1503,1660,1245,1631,1632,1655,18778,19005,18786,18781};
new pRamp[MAX_PLAYERS][2];
new pickupAmmu[4], pickupEat[4];
new DomekWinda;
new PicSzkola[6];
#define PROP_VW    		(10000)
#define MAX_INTERIORS	(146)
#define MAX_PROPERTIES  (1000)
new pPropertyPickup[MAX_PLAYERS];
enum E_P_TYPES {
	tIcon,
	tName[32]
};
enum E_INTERIORS {
	inIntID,
	Float:inExitX,
	Float:inExitY,
	Float:inExitZ,
	Float:inExitA,
	inName[64]
};
enum E_PROPERTIES {
	eInterior,
	Float:eEntX,
	Float:eEntY,
	Float:eEntZ,
	Float:eEntA,
	eUniqIntId,
	eOwner,
	ePrice,
	ePname[64]
};
new	unid;
new interiorInfo[MAX_INTERIORS][E_INTERIORS];
new propPickups[MAX_PROPERTIES] = {-1};
new properties[MAX_PROPERTIES][E_PROPERTIES];
new currentInt[MAX_PLAYERS] = {-1};
new Administrator[MAX_PLAYERS];
new AdministratorLevel[MAX_PLAYERS];
new vObject[MAX_VEHICLES][2];
new pVehicle[MAX_PLAYERS];
enum winfo
{
    wID, wName[16]
}
new wheels_info[][winfo] =
{
    {1097, "Virtual"},
    {1098, "Acces"},
    {1096, "Ahab"},
    {1085, "Atomic"},
    {1084, "Trance"},
    {1083, "Dollar"},
    {1082, "Import"},
    {1081, "Grove"},
    {1080, "Switch"},
    {1079, "Cutter"},
    {1078, "Twist"},
    {1077, "Classic"},
    {1076, "Wires"},
    {1075, "Rimshine"},
    {1074, "Mega"},
    {1073, "Shadow"}
};
new VehicleCreated[MAX_VEHICLES];
new VehicleNames[212][] = {
	{"Landstalker"},{"Bravura"},{"Buffalo"},{"Linerunner"},{"Perrenial"},{"Sentinel"},
	{"Dumper"},{"Firetruck"},{"Trashmaster"},{"Stretch"},{"Manana"},{"Infernus"},{"Voodoo"},
	{"Pony"},{"Mule"},{"Cheetah"},{"Ambulance"},{"Leviathan"},{"Moonbeam"},{"Esperanto"},{"Taxi"},
	{"Washington"},{"Bobcat"},{"Mr. Whoopee"},{"BF. Injection"},{"Hunter"},{"Premier"},{"Enforcer"},
	{"Securicar"},{"Banshee"},{"Predator"},{"Bus"},{"Rhino"},{"Barracks"},{"Hotknife"},{"Article Trailer"},
	{"Previon"},{"Coach"},{"Cabbie"},{"Stallion"},{"Rumpo"},{"RC Bandit"},{"Romero"},{"Packer"},{"Monster"},
	{"Admiral"},{"Squalo"},{"Seasparrow"},{"Pizzaboy"},{"Tram"},{"Article Trailer 2"},{"Turismo"},{"Speeder"},
	{"Reefer"},{"Tropic"},{"Flatbed"},{"Yankee"},{"Caddy"},{"Solair"},{"RC Van"},{"Skimmer"},
	{"PCJ-600"},{"Faggio"},{"Freeway"},{"RC Baron"},{"RC Raider"},{"Glendale"},{"Oceanic"},{"Sanchez"},
	{"Sparrow"},{"Patriot"},{"Quad"},{"Coastguard"},{"Dinghy"},{"Hermes"},{"Sabre"},{"Rustler"},{"ZR-350"},
	{"Walton"},{"Regina"},{"Comet"},{"BMX"},{"Burrito"},{"Camper"},{"Marquis"},{"Baggage"},{"Dozer"},
	{"Maverick"},{"News Chopper"},{"Rancher"},{"FBI Rancher"},{"Virgo"},{"Greenwood"},{"Jetmax"},{"Hotring"},
	{"Sandking"},{"Blista Compact"},{"Police Maverick"},{"Boxville"},{"Benson"},{"Mesa"},{"RC Goblin"},
	{"Hotring Racer A"},{"Hotring Racer B"},{"Bloodring Banger"},{"Rancher"},{"Super GT"},{"Elegant"},
	{"Journey"},{"Bike"},{"Mountain Bike"},{"Beagle"},{"Cropdust"},{"Stunt"},{"Tanker"},{"Roadtrain"},
	{"Nebula"},{"Majestic"},{"Buccaneer"},{"Shamal"},{"Hydra"},{"FCR-900"},{"NRG-500"},{"HPV1000"},
	{"Cement Truck"},{"Tow Truck"},{"Fortune"},{"Cadrona"},{"FBI Truck"},{"Willard"},{"Forklift"},
	{"Tractor"},{"Combine"},{"Feltzer"},{"Remington"},{"Slamvan"},{"Blade"},{"Freight"},{"Streak"},
	{"Vortex"},{"Vincent"},{"Bullet"},{"Clover"},{"Sadler"},{"Firetruck LA"},{"Hustler"},{"Intruder"},
	{"Primo"},{"Cargobob"},{"Tampa"},{"Sunrise"},{"Merit"},{"Utility"},{"Nevada"},{"Yosemite"},{"Windsor"},
	{"Monster A"},{"Monster B"},{"Uranus"},{"Jester"},{"Sultan"},{"Stratum"},{"Elegy"},{"Raindance"},
	{"RC Tiger"},{"Flash"},{"Tahoma"},{"Savanna"},{"Bandito"},{"Freight Flat"},{"Streak Carriage"},
	{"Kart"},{"Mower"},{"Dunerider"},{"Sweeper"},{"Broadway"},{"Tornado"},{"AT-400"},{"DFT-30"},{"Huntley"},
	{"Stafford"},{"BF-400"},{"Newsvan"},{"Tug"},{"Article Trailer 3"},{"Emperor"},{"Wayfarer"},{"Euros"},{"Mobile Hotdog"},
	{"Club"},{"Freight Carriage"},{"Trailer 3"},{"Andromada"},{"Dodo"},{"RC Cam"},{"Launch"},{"Police Car (LSPD)"},
	{"Police Car (SFPD)"},{"Police Car (LVPD)"},{"Police Ranger"},{"Picador"},{"SWAT Van"},{"Alpha"},
	{"Phoenix"},{"Glendale"},{"Sadler"},{"Luggage Trailer A"},{"Luggage Trailer B"},{"Stair Trailer"},
	{"Boxville"},{"Farm Plow"},{"Utility Trailer"}
};
#define KillPlayer(%0) SetPlayerHealth(%0,0.0)
new WeaponList_Slot1[8] = {2,3,4,5,6,7,8};
new WeaponList_Slot2[3] = {22,23,24};
new WeaponList_Slot3[3] = {25,26,27};
new WeaponList_Slot4[3] = {28,29,32};
new WeaponList_Slot5[2] = {30,31};
new WeaponList_Slot6[2] = {33,34};
new pSpawnWeapon[MAX_PLAYERS][6];
new AllowWeapon[] = {
	0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38
};
new Ananas;
new PickupBan;
new max_ping = 300;
new highestID;
new pAFK[MAX_PLAYERS];
new pLastUpdate[MAX_PLAYERS];
new pAntyTele[MAX_PLAYERS][2];
new pInFun[MAX_PLAYERS];
new SpecPlayer[MAX_PLAYERS];
new pName[MAX_PLAYERS][MAX_PLAYER_NAME];
new playerColors[100] = {
	0xFF8C13FF,0xC715FFFF,0x20B2AAFF,0xDC143CFF,0x6495EDFF,0xf0e68cFF,0x778899FF,0xFF1493FF,0xF4A460FF,0xEE82EEFF,
	0xFFD720FF,0x8b4513FF,0x4949A0FF,0x148b8bFF,0x14ff7fFF,0x556b2fFF,0x0FD9FAFF,0x10DC29FF,0x534081FF,0x0495CDFF,
	0xEF6CE8FF,0xBD34DAFF,0x247C1BFF,0x0C8E5DFF,0x635B03FF,0xCB7ED3FF,0x65ADEBFF,0x5C1ACCFF,0xF2F853FF,0x11F891FF,
	0x7B39AAFF,0x53EB10FF,0x54137DFF,0x275222FF,0xF09F5BFF,0x3D0A4FFF,0x22F767FF,0xD63034FF,0x9A6980FF,0xDFB935FF,
	0x3793FAFF,0x90239DFF,0xE9AB2FFF,0xAF2FF3FF,0x057F94FF,0xB98519FF,0x388EEAFF,0x028151FF,0xA55043FF,0x0DE018FF,
	0x93AB1CFF,0x95BAF0FF,0x369976FF,0x18F71FFF,0x4B8987FF,0x491B9EFF,0x829DC7FF,0xBCE635FF,0xCEA6DFFF,0x20D4ADFF,
	0x2D74FDFF,0x3C1C0DFF,0x12D6D4FF,0x48C000FF,0x2A51E2FF,0xE3AC12FF,0xFC42A8FF,0x2FC827FF,0x1A30BFFF,0xB740C2FF,
	0x42ACF5FF,0x2FD9DEFF,0xFAFB71FF,0x05D1CDFF,0xC471BDFF,0x94436EFF,0xC1F7ECFF,0xCE79EEFF,0xBD1EF2FF,0x93B7E4FF,
	0x3214AAFF,0x184D3BFF,0xAE4B99FF,0x7E49D7FF,0x4C436EFF,0xFA24CCFF,0xCE76BEFF,0xA04E0AFF,0x9F945CFF,0xDCDE3DFF,
	0x10C9C5FF,0x70524DFF,0x0BE472FF,0x8A2CD7FF,0x6152C2FF,0xCF72A9FF,0xE59338FF,0xEEDC2DFF,0xD8C762FF,0xD8C762FF
};
new CMD_Block[MAX_PLAYERS];
new Float:pPrivTele[MAX_PLAYERS][3][4];
new Players_Online = 0, Admins_Online = 0,Vips_Online = 0;
new p_Hours[MAX_PLAYERS] = 0, p_Minutes[MAX_PLAYERS] = 0, p_Secounds[MAX_PLAYERS] = 0;
new AnnON, AnnTim;
new Text:AnnTD;
new Text:CountDraw;
new Text:ZegarDraw;
new Text:CountRace[6], Text:GameDraw[MAX_PLAYERS];
new AnnOFF;
new vLock[MAX_VEHICLES][3];
new vNeon[MAX_VEHICLES][2];
forward Limit(playerid);
forward Odciszanko(playerid);
forward Obliczanko();
