/*
	@Polski TOP Serwer - pickup.inc
	@Last update: 14 marca 2014 23:25

*/
stock Pickups()
{
	PickupBan = CreatePickup(1239, 1, -67.0, 86.0, 5.0, 0);
	pickupEat[0] = CreatePickup(1239, 23,369.5393, -6.6714,1001.8589, 1);
	pickupEat[1] = CreatePickup(1239, 23,380.6962, -191.6113,1000.6328, 1);
	pickupEat[2] = CreatePickup(1239, 23,377.3884, -67.9809,1001.5151, 1);
	pickupEat[3] = CreatePickup(1239, 23,374.1547, -120.2968,1001.4922, 1);
	pickupAmmu[0] = CreatePickup(1239, 23,295.9463,-78.6658,1001.5156, 1);
	pickupAmmu[1] = CreatePickup(1239, 23,296.1305,-36.7937,1001.5156, 1);
	pickupAmmu[2] = CreatePickup(1239, 23,2433.38, -1679.63, 13.60, 0);
	pickupAmmu[3] = CreatePickup(1239, 23,-1979.58, 240.01, 34.97, 0);
	sklep_lv = CreatePickup(1239, 23,295.1197, -80.4455, 1001.5156, 0);
	Bankomat[0] = CreatePickup(1212, 23, 2479.6999511719, -1686.9000244141, 13.3, 0);
    Bankomat[1] = CreatePickup(1212, 23, 2116.1999511719, 947.0, 10.7, 0);
    Bankomat[2] = CreatePickup(1212, 23, -2032.3000488281, 165.5, 28.7);
    AddStaticPickup(1318, 1, 2177.5723, 962.2811, 10.8203, 0);
	gunshop_lv_outside=CreatePickup(1318, 1, 2177.5723, 962.2811, 10.8203, 0);
	AddStaticPickup(1318, 1, 285.8655, -86.1492, 1001.5229, 0);
	gunshop_lv_inside = CreatePickup(1318, 1, 285.8655, -86.1492, 1001.5229, 0);
}