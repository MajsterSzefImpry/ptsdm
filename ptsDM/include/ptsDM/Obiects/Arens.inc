/*
	@Polski TOP Serwer - Arens.inc
	@Last update: 14 marca 2014 23:25

*/
stock Create_Objects_Arens()
{
    new duelvw[30] = {150, 151, 152, 153, ...};
    CreateDynamicObjectEx(8485, -239.93, 1785.52, 1992.12,   0.00, 90.00, 0.00, 200.0, 200.0, duelvw, {0});
	CreateDynamicObjectEx(8485, -205.92, 1806.55, 1992.12,   0.00, 90.00, -269.46, 200.0, 200.0, duelvw, {0});
	CreateDynamicObjectEx(8485, -199.63, 1848.11, 1992.12,   0.00, 90.00, -449.94, 200.0, 200.0, duelvw, {0});
	CreateDynamicObjectEx(8485, -143.90, 1829.51, 1992.12,   0.00, 90.00, -540.72, 200.0, 200.0, duelvw, {0});
	CreateDynamicObjectEx(8485, -212.80, 1766.47, 2055.87,   0.00, 180.00, 0.00, 200.0, 200.0, duelvw, {0});
	CreateDynamicObjectEx(18652, -195.76, 1845.06, 2034.68,   0.00, 0.00, 90.00, 200.0, 200.0, duelvw, {0});
	CreateDynamicObjectEx(18652, -191.42, 1809.75, 2034.37,   0.00, 0.00, 90.00, 200.0, 200.0, duelvw, {0});
	CreateDynamicObjectEx(18652, -236.82, 1830.60, 2036.66,   0.00, 0.00, 0.00, 200.0, 200.0, duelvw, {0});
	CreateDynamicObjectEx(18652, -146.98, 1827.57, 2036.02,   0.00, 0.00, 0.00, 200.0, 200.0, duelvw, {0});
	CreateDynamicObjectEx(18652, -190.30, 1828.41, 2025.27,   0.00, 0.00, 0.00, 200.0, 200.0, duelvw, {0});
	CreateDynamicObjectEx(4238, -203.66, 1809.65, 2038.07,   0.00, 0.00, 210.80, 200.0, 200.0, duelvw, {0});
	CreateDynamicObjectEx(4238, -178.04, 1809.91, 2038.07,   0.00, 0.00, 210.75, 200.0, 200.0, duelvw, {0});
	CreateDynamicObjectEx(4988, -215.81, 1845.02, 2039.78,   0.00, 0.00, -169.92, 200.0, 200.0, duelvw, {0});
	CreateDynamicObjectEx(4988, -171.39, 1845.07, 2039.78,   0.00, 0.00, -169.92, 200.0, 200.0, duelvw, {0});
	CreateDynamicObjectEx(7900, -146.99, 1826.40, 2042.24,   0.00, 0.00, -89.28, 200.0, 200.0, duelvw, {0});
	CreateDynamicObjectEx(7901, -146.99, 1826.40, 2031.56,   0.00, 0.00, -89.28, 200.0, 200.0, duelvw, {0});
	CreateDynamicObjectEx(7903, -242.74, 1830.92, 2043.12,   0.00, 0.00, -67.08, 200.0, 200.0, duelvw, {0});
	CreateDynamicObjectEx(18830, -155.38, 1827.83, 2050.83,   0.00, 0.00, 90.00, 200.0, 200.0, duelvw, {0});
	CreateDynamicObjectEx(18830, -165.93, 1827.96, 2050.83,   0.00, 0.00, 90.00, 200.0, 200.0, duelvw, {0});
	CreateDynamicObjectEx(18830, -177.31, 1828.06, 2050.83,   0.00, 0.00, 90.00, 200.0, 200.0, duelvw, {0});
	CreateDynamicObjectEx(18830, -188.80, 1828.17, 2050.83,   0.00, 0.00, 90.00, 200.0, 200.0, duelvw, {0});
	CreateDynamicObjectEx(18830, -200.56, 1828.34, 2050.83,   0.00, 0.00, 90.00, 200.0, 200.0, duelvw, {0});
	CreateDynamicObjectEx(18830, -211.84, 1828.40, 2050.83,   0.00, 0.00, 90.00, 200.0, 200.0, duelvw, {0});
	CreateDynamicObjectEx(18830, -223.49, 1828.46, 2050.83,   0.00, 0.00, 90.00, 200.0, 200.0, duelvw, {0});
	CreateDynamicObjectEx(18830, -235.41, 1828.28, 2050.83,   0.00, 0.00, 90.00, 200.0, 200.0, duelvw, {0});
	CreateObject(8485, -212.80, 1766.47, 2022.45,   0.00, 0.00, 0.00);


	//Labirynt
	CreateObject(18753, 2173.15, 2813.72, 1238.44,   0.00, 0.00, 0.00);
	CreateStreamObject(18753, 2173.15, 2813.72, 1246.08,   0.00, 0.00, 0.00);
	CreateStreamObject(8210, 2207.96, 2875.95, 1241.31,   0.00, 0.00, 0.00);
	CreateStreamObject(8210, 2235.07, 2848.28, 1241.31,   0.00, 0.00, -90.00);
	CreateStreamObject(8210, 2235.07, 2793.55, 1241.31,   0.00, 0.00, -90.00);
	CreateStreamObject(8210, 2235.06, 2779.05, 1241.31,   0.00, 0.00, -90.00);
	CreateStreamObject(8210, 2209.01, 2751.63, 1241.31,   0.00, 0.00, 180.00);
	CreateStreamObject(8210, 2155.29, 2751.86, 1241.31,   0.00, 0.00, 180.00);
	CreateStreamObject(8210, 2154.65, 2875.85, 1241.31,   0.00, 0.00, 0.00);
	CreateStreamObject(8210, 2111.37, 2849.21, 1241.31,   0.00, 0.00, 90.00);
	CreateStreamObject(8210, 2111.03, 2779.52, 1241.31,   0.00, 0.00, 90.00);
	CreateStreamObject(8210, 2138.87, 2751.89, 1241.31,   0.00, 0.00, 180.00);
	CreateStreamObject(8210, 2138.53, 2876.08, 1241.31,   0.00, 0.00, 0.00);
	CreateStreamObject(8171, 2043.56, 2814.17, 1238.92,   0.00, 0.00, 90.00);
	CreateStreamObject(8171, 2043.59, 2815.05, 1238.92,   0.00, 180.00, 90.00);
	CreateStreamObject(3749, 2112.42, 2814.32, 1244.28,   0.00, 0.00, 90.60);
	CreateStreamObject(18780, 1988.91, 2816.67, 1240.28,   0.00, 15.00, 180.00);
	CreateStreamObject(18780, 1988.92, 2826.57, 1240.28,   0.00, 15.00, 180.00);
	CreateStreamObject(18780, 1988.97, 2806.89, 1240.28,   0.00, 15.00, 180.00);
	CreateStreamObject(18780, 1988.98, 2798.98, 1240.28,   0.00, 15.00, 180.00);
	CreateStreamObject(18780, 1988.94, 2828.78, 1240.28,   0.00, 15.00, 180.00);
	CreateVehicle(522, 2105.9641, 2818.3940, 1241.9, 90.0, -1, -1, 5);
	CreateVehicle(522, 2106.2048, 2810.7922, 1241.9, 90.0, -1, -1, 5);
	CreateLabitynt();
	SetTimer("Labirynt", 5 * 60 * 1000, 1);

	//ObjectMaterial
	new objectid = CreateObject(8515, 2212.37, 1083.23, 7.88,   0.00, 0.00, 0.00);
	SetObjectMaterial(objectid,10,18886,"ElectroMagnet1","hazardtile13-128x128");
	SetObjectMaterial(objectid,11,18886,"ElectroMagnet1","hazardtile13-128x128");
	SetObjectMaterial(objectid,12,18886,"ElectroMagnet1","hazardtile13-128x128");
	SetObjectMaterial(objectid,9,18886,"ElectroMagnet1","hazardtile13-128x128");
	objectid = CreateObject(8498, 2231.80, 1035.72, 46.82,   0.00, 0.00, 0.00);
	SetObjectMaterial(objectid,10,19054,"XmasBoxes","wrappingpaper28");
	SetObjectMaterial(objectid,12,19054,"XmasBoxes","wrappingpaper28");
	SetObjectMaterial(objectid,11,19054,"XmasBoxes","wrappingpaper28");
	SetObjectMaterial(objectid,9,19054,"XmasBoxes","wrappingpaper28");

	//Bankomaty
	CreateStreamObject(2754, 2479.5, -1687.9000244141, 13.39999961853, 0, 0, 262.25);
	CreateStreamObject(2754, 2114.8994140625, 947.099609375, 10.699999809265, 0, 0, 179.99450683594);
	CreateStreamObject(2754, -2033.3000488281, 165.5, 28.700000762939, 0, 0, 180);

	Create3DTextLabel("{FF0000}Wpisz:\n{FFFFFF}/bank", -1, 2479.6999511719, -1686.9000244141, 13.3, 20.0, 0, 1);
	Create3DTextLabel("{FF0000}Wpisz:\n{FFFFFF}/bank", -1, 2116.1999511719, 947.0, 10.7, 20.0, 0, 1);
	Create3DTextLabel("{FF0000}Wpisz:\n{FFFFFF}/bank", -1, -2032.3000488281, 165.5, 28.7, 20.0, 0, 1);

	//Skoki - FUN

	TW_Checkpoint = CreateDynamicCP(-2810.68, 128.02, 6.29, 5.0, 27, 0, -1, 9999.0);

	//LS Firework
	CreateStreamObject(18728, 2505.01, -1691.62, 15.0, 0.0, 0.0, 0.0);

	//RaceObj NRG
	CreateStreamObject(1503, 1930.85, 1286.27, 10.15,   0.00, 0.00, 88.08);
	CreateStreamObject(1503, 1930.86, 1288.70, 10.15,   0.00, 0.00, 88.08);

	//Tower - Fun
	CreateDynamicObject(18751, -3100.22, 80.42, 8.22,   0.00, 0.00, 0.00, 27, 0);
	CreateDynamicObject(18754, -3096.93, 95.85, 31.62,   0.00, 90.00, 90.00, 27, 0);
	CreateDynamicObject(18754, -3096.36, 60.46, 31.63,   0.00, 90.00, 90.00, 27, 0);
	CreateDynamicObject(18754, -3122.45, 73.15, 31.55,   0.00, 90.00, 180.00, 27, 0);
	CreateDynamicObject(18754, -3088.62, 70.95, 14.98,   0.00, 90.00, 180.00, 27, 0);
	CreateDynamicObject(3095, -3118.84, 66.39, 21.00,   0.00, 0.00, 0.00, 27, 0);
	CreateDynamicObject(3095, -3119.13, 79.64, 21.00,   0.00, 0.00, 0.00, 27, 0);
	CreateDynamicObject(3095, -3106.24, 67.25, 23.49,   0.00, 0.00, 0.00, 27, 0);
	CreateDynamicObject(3095, -3118.71, 89.18, 17.97,   0.00, 0.00, 0.00, 27, 0);
	CreateDynamicObject(3095, -3109.43, 80.23, 15.83,   0.00, 0.00, 0.00, 27, 0);
	CreateDynamicObject(3095, -3104.27, 77.69, 26.25,   0.00, 0.00, 0.00, 27, 0);
	CreateDynamicObject(3095, -3103.16, 86.70, 28.29,   0.00, 0.00, 0.00, 27, 0);
	CreateDynamicObject(3095, -3111.50, 90.52, 31.34,   0.00, 0.00, 0.00, 27, 0);
	CreateDynamicObject(3095, -3111.07, 80.18, 34.27,   0.00, 0.00, 0.00, 27, 0);
	CreateDynamicObject(3095, -3116.30, 84.14, 37.73,   0.00, 0.00, 0.00, 27, 0);
	CreateDynamicObject(3095, -3106.43, 89.62, 39.87,   0.00, 0.00, 0.00, 27, 0);
	CreateDynamicObject(3095, -3103.30, 79.34, 42.62,   -20.00, 0.00, 0.00, 27, 0);
	CreateDynamicObject(3095, -3108.83, 72.92, 44.77,   0.00, 0.00, 0.00, 27, 0);
	CreateDynamicObject(3095, -3114.36, 77.59, 46.96,   0.00, 0.00, 0.00, 27, 0);
	CreateDynamicObject(3095, -3103.93, 77.87, 48.58,   0.00, 0.00, 0.00, 27, 0);
	CreateDynamicObject(3095, -3110.80, 69.83, 50.90,   0.00, 0.00, 0.00, 27, 0);
	CreateDynamicObject(3095, -3103.42, 65.25, 53.91,   0.00, 0.00, 0.00, 27, 0);
	CreateDynamicObject(3095, -3101.47, 74.40, 56.37,   0.00, 0.00, 0.00, 27, 0);
	CreateDynamicObject(3095, -3100.37, 81.84, 58.96,   0.00, 0.00, -57.24, 27, 0);
	CreateDynamicObject(3095, -3106.45, 82.57, 61.42,   0.00, 0.00, -57.24, 27, 0);
	CreateDynamicObject(3095, -3102.63, 73.77, 64.29,   0.00, 0.00, -57.24, 27, 0);
	CreateDynamicObject(3095, -3109.27, 77.80, 67.65,   0.00, 0.00, -57.24, 27, 0);
	CreateDynamicObject(3095, -3119.16, 78.23, 70.56,   0.00, 0.00, -57.24, 27, 0);
	CreateDynamicObject(3095, -3116.60, 89.09, 73.18,   0.00, 0.00, -57.24, 27, 0);
	CreateDynamicObject(3095, -3108.10, 93.63, 76.65,   0.00, 0.00, -57.24, 27, 0);
	CreateDynamicObject(3095, -3098.95, 91.69, 79.42,   0.00, 0.00, -57.24, 27, 0);
	CreateDynamicObject(3095, -3100.67, 82.89, 81.99,   0.00, 0.00, -57.24, 27, 0);
	CreateDynamicObject(3095, -3109.71, 75.17, 83.84,   0.00, 0.00, -109.74, 27, 0);
	CreateDynamicObject(3095, -3119.30, 84.11, 83.84,   0.00, 0.00, -109.74, 27, 0);
	CreateDynamicObject(3095, -3115.81, 95.04, 85.93,   0.00, 0.00, -109.74, 27, 0);
	CreateDynamicObject(3095, -3106.85, 93.74, 89.16,   10.00, 0.00, -87.48, 27, 0);
	CreateDynamicObject(3095, -3096.03, 90.89, 92.52,   0.00, 0.00, -142.74, 27, 0);
	CreateDynamicObject(3095, -3091.06, 82.98, 93.97,   0.00, 0.00, -142.74, 27, 0);
	CreateDynamicObject(3095, -3104.01, 80.74, 93.97,   0.00, 0.00, -142.74, 27, 0);
	CreateDynamicObject(3095, -3099.44, 71.83, 96.92,   0.00, 0.00, -142.74, 27, 0);
	CreateDynamicObject(3095, -3110.77, 76.11, 101.06,   0.00, -19.00, -206.70, 27, 0);
	CreateDynamicObject(3095, -3115.30, 87.11, 104.32,   0.00, 0.00, -257.82, 27, 0);
	CreateDynamicObject(3095, -3107.51, 93.35, 107.49,   0.00, 0.00, -257.82, 27, 0);
	CreateDynamicObject(3095, -3100.54, 91.53, 111.73,   -15.00, 0.00, -257.82, 27, 0);
	CreateDynamicObject(3095, -3091.04, 87.66, 114.81,   0.00, 0.00, -257.82, 27, 0);
	CreateDynamicObject(3095, -3091.64, 76.95, 117.09,   0.00, 0.00, -257.82, 27, 0);
	CreateDynamicObject(3095, -3102.09, 74.31, 117.09,   0.00, 20.00, -348.72, 27, 0);
	CreateDynamicObject(3095, -3111.69, 71.21, 120.77,   0.00, 20.00, -348.72, 27, 0);
	CreateDynamicObject(3095, -3119.23, 78.58, 123.83,   0.00, 10.00, -348.72, 27, 0);
	CreateDynamicObject(3095, -3111.49, 80.21, 124.41,   0.00, 10.00, -348.72, 27, 0);
	CreateDynamicObject(3095, -3104.29, 83.34, 126.39,   0.00, 10.00, -437.64, 27, 0);
	CreateDynamicObject(3095, -3098.51, 81.48, 129.34,   0.00, 10.00, -564.12, 27, 0);
	CreateDynamicObject(3095, -3094.09, 75.01, 132.65,   0.00, 0.00, -777.84, 27, 0);
	CreateDynamicObject(3095, -3094.03, 65.29, 134.98,   0.00, 0.00, -777.84, 27, 0);
	CreateDynamicObject(3095, -3090.03, 71.69, 137.62,   0.00, 0.00, -807.66, 27, 0);
	CreateDynamicObject(16685, -2932.85, 71.19, 139.22,   0.00, 0.00, 0.00, 27, 0);
	CreateDynamicObject(18754, -2964.69, 66.93, 31.63,   0.00, 90.00, 90.00, 27, 0);
	CreateDynamicObject(18754, -2964.53, 76.87, 31.64,   0.00, 90.00, 90.00, 27, 0);
	CreateDynamicObject(18754, -3015.82, 73.91, 155.27,   0.00, 0.00, 90.00, 27, 0);
	CreateDynamicObject(18754, -2948.12, 74.43, 155.27,   0.00, 0.00, 90.00, 27, 0);
	CreateDynamicObject(18825, -2815.67, 86.20, 138.21,   -60.00, 0.00, -177.90, 27, 0);
	CreateDynamicObject(18754, -3088.54, 201.14, 31.58,   0.00, 90.00, 180.00, 27, 0);
	CreateDynamicObject(18754, -3088.34, -57.15, 31.58,   0.00, 90.00, 180.00, 27, 0);
	CreateDynamicObject(980, -2824.57, 67.01, 137.21,   0.00, 90.00, -89.58, 27, 0);
	CreateDynamicObject(980, -2824.74, 77.88, 137.21,   0.00, 90.00, -89.58, 27, 0);
	CreateDynamicObject(18825, -2835.76, 85.00, 122.21,   -60.00, 0.00, -355.14, 27, 0);
	CreateDynamicObject(18825, -2815.67, 86.20, 106.40,   -60.00, 0.00, -177.90, 27, 0);
	CreateDynamicObject(18825, -2835.76, 85.00, 90.54,   -60.00, 0.00, -355.14, 27, 0);
	CreateDynamicObject(18825, -2815.67, 86.20, 74.70,   -60.00, 0.00, -177.90, 27, 0);
	CreateDynamicObject(18825, -2835.76, 85.00, 58.88,   -60.00, 0.00, -355.14, 27, 0);
	CreateDynamicObject(18825, -2815.69, 86.19, 43.07,   -60.00, 0.00, -177.90, 27, 0);
	CreateDynamicObject(18825, -2836.46, 113.27, 27.32,   60.00, 0.00, 0.00, 27, 0);
	CreateDynamicObject(980, -2824.63, 72.44, 135.25,   0.00, 90.00, -86.22, 27, 0);
	CreateDynamicObject(13593, -2827.93, 72.25, 139.90,   0.00, 0.00, -91.38, 27, 0);
	CreateDynamicObject(4718, -2840.61, 18.23, 140.77,   0.00, 0.00, 89.76, 27, 0);
	CreateDynamicObject(4718, -2858.53, 125.96, 151.49,   0.00, 0.00, -89.76, 27, 0);
	CreateDynamicObject(2780, -2826.64, 97.02, 131.38,   0.00, 0.00, 0.00, 27, 0);
	//Hay - Fun
	CreateDynamicObject(3374, -575.43, 801.22, 86.44,   0.00, 0.00, 0.00,24, 0);
	CreateDynamicObject(3374, -571.55, 801.23, 86.44,   0.00, 0.00, 0.00,24, 0);
	CreateDynamicObject(3374, -567.55, 801.23, 86.44,   0.00, 0.00, 0.00,24, 0);
	CreateDynamicObject(3374, -563.55, 801.23, 86.44,   0.00, 0.00, 0.00,24, 0);
	CreateDynamicObject(3374, -559.55, 801.23, 86.44,   0.00, 0.00, 0.00,24, 0);
	CreateDynamicObject(3374, -559.55, 797.23, 86.44,   0.00, 0.00, 0.00,24, 0);
	CreateDynamicObject(3374, -563.55, 797.23, 86.44,   0.00, 0.00, 0.00,24, 0);
	CreateDynamicObject(3374, -567.55, 797.23, 86.44,   0.00, 0.00, 0.00,24, 0);
	CreateDynamicObject(3374, -571.55, 797.23, 86.44,   0.00, 0.00, 0.00,24, 0);
	CreateDynamicObject(3374, -575.55, 797.23, 86.44,   0.00, 0.00, 0.00,24, 0);
	CreateDynamicObject(3374, -579.55, 797.23, 86.44,   0.00, 0.00, 0.00,24, 0);
	CreateDynamicObject(3374, -583.55, 797.23, 86.44,   0.00, 0.00, 0.00,24, 0);
	CreateDynamicObject(3374, -579.43, 801.22, 86.44,   0.00, 0.00, 0.00,24, 0);
	CreateDynamicObject(3374, -583.43, 801.22, 86.44,   0.00, 0.00, 0.00,24, 0);
	CreateDynamicObject(3374, -583.55, 793.23, 86.44,   0.00, 0.00, 0.00,24, 0);
	CreateDynamicObject(3374, -579.55, 793.23, 86.44,   0.00, 0.00, 0.00,24, 0);
	CreateDynamicObject(3374, -575.55, 793.23, 86.44,   0.00, 0.00, 0.00,24, 0);
	CreateDynamicObject(3374, -571.55, 793.23, 86.44,   0.00, 0.00, 0.00,24, 0);
	CreateDynamicObject(3374, -567.55, 793.23, 86.44,   0.00, 0.00, 0.00,24, 0);
	CreateDynamicObject(3374, -563.55, 793.23, 86.44,   0.00, 0.00, 0.00,24, 0);
	CreateDynamicObject(3374, -559.55, 793.23, 86.44,   0.00, 0.00, 0.00,24, 0);
	CreateDynamicObject(3374, -559.55, 789.23, 86.44,   0.00, 0.00, 0.00,24, 0);
	CreateDynamicObject(3374, -563.55, 789.23, 86.44,   0.00, 0.00, 0.00,24, 0);
	CreateDynamicObject(3374, -567.55, 789.23, 86.44,   0.00, 0.00, 0.00,24, 0);
	CreateDynamicObject(3374, -571.55, 789.23, 86.44,   0.00, 0.00, 0.00,24, 0);
	CreateDynamicObject(3374, -575.55, 789.23, 86.44,   0.00, 0.00, 0.00,24, 0);
	CreateDynamicObject(3374, -579.55, 789.23, 86.44,   0.00, 0.00, 0.00,24, 0);
	CreateDynamicObject(3374, -583.55, 789.23, 86.44,   0.00, 0.00, 0.00,24, 0);
	CreateDynamicObject(3374, -583.55, 785.23, 86.44,   0.00, 0.00, 0.00,24, 0);
	CreateDynamicObject(3374, -579.55, 785.23, 86.44,   0.00, 0.00, 0.00,24, 0);
	CreateDynamicObject(3374, -575.55, 785.23, 86.44,   0.00, 0.00, 0.00,24, 0);
	CreateDynamicObject(3374, -571.55, 785.23, 86.44,   0.00, 0.00, 0.00,24, 0);
	CreateDynamicObject(3374, -567.55, 785.23, 86.44,   0.00, 0.00, 0.00,24, 0);
	CreateDynamicObject(3374, -563.55, 785.23, 86.44,   0.00, 0.00, 0.00,24, 0);
	CreateDynamicObject(3374, -559.55, 785.23, 86.44,   0.00, 0.00, 0.00,24, 0);
	CreateDynamicObject(3374, -559.55, 781.23, 86.44,   0.00, 0.00, 0.00,24, 0);
	CreateDynamicObject(3374, -563.55, 781.23, 86.44,   0.00, 0.00, 0.00,24, 0);
	CreateDynamicObject(3374, -567.55, 781.23, 86.44,   0.00, 0.00, 0.00,24, 0);
	CreateDynamicObject(3374, -571.55, 781.23, 86.44,   0.00, 0.00, 0.00,24, 0);
	CreateDynamicObject(3374, -575.55, 781.23, 86.44,   0.00, 0.00, 0.00,24, 0);
	CreateDynamicObject(3374, -579.55, 781.23, 86.44,   0.00, 0.00, 0.00,24, 0);
	CreateDynamicObject(3374, -583.55, 781.23, 86.44,   0.00, 0.00, 0.00,24, 0);
	CreateDynamicObject(3374, -583.55, 777.23, 86.44,   0.00, 0.00, 0.00,24, 0);
	CreateDynamicObject(3374, -579.55, 777.23, 86.44,   0.00, 0.00, 0.00,24, 0);
	CreateDynamicObject(3374, -575.55, 777.23, 86.44,   0.00, 0.00, 0.00,24, 0);
	CreateDynamicObject(3374, -571.55, 777.23, 86.44,   0.00, 0.00, 0.00,24, 0);
	CreateDynamicObject(3374, -567.55, 777.23, 86.44,   0.00, 0.00, 0.00,24, 0);
	CreateDynamicObject(3374, -563.55, 777.23, 86.44,   0.00, 0.00, 0.00,24, 0);
	CreateDynamicObject(3374, -559.55, 777.23, 86.44,   0.00, 0.00, 0.00,24, 0);
	//Derby - Fun
	CreateDynamicObject(3458, -1041.52, 564.97, 134.52,   -0.02, 0.00, 0.00,23,0);
	CreateDynamicObject(3458, -1019.13, 564.97, 134.52,   -0.02, 0.00, 90.00,23,0);
	CreateDynamicObject(3458, -1063.22, 566.16, 134.52,   -0.02, 0.00, 90.00,23,0);
	CreateDynamicObject(3458, -1042.08, 562.76, 134.52,   -0.02, 0.00, 90.00,23,0);
	CreateDynamicObject(3458, -1042.12, 606.69, 134.52,   -0.02, 0.00, 90.00,23,0);
	CreateDynamicObject(3458, -1020.32, 584.90, 134.52,   -0.02, 0.00, 0.00,23,0);
	CreateDynamicObject(3458, -1064.01, 584.68, 134.52,   -0.02, 0.00, 0.00,23,0);
	CreateDynamicObject(3458, -1019.08, 606.85, 134.52,   -0.02, 0.00, 90.00,23,0);
	CreateDynamicObject(3458, -1063.00, 605.92, 134.52,   -0.02, 0.00, 90.00,23,0);
	CreateDynamicObject(3458, -1064.81, 602.99, 134.52,   -0.02, 0.00, 0.00,23,0);
	CreateDynamicObject(3458, -1019.91, 602.95, 134.52,   -0.02, 0.00, 0.00,23,0);
	CreateDynamicObject(3458, -1063.02, 626.13, 134.52,   -0.02, 0.00, 0.00,23,0);
	CreateDynamicObject(3458, -1020.20, 626.16, 134.52,   -0.02, 0.00, 0.00,23,0);
	CreateDynamicObject(3458, -1063.12, 645.79, 134.52,   -0.02, 0.00, 90.00,23,0);
	CreateDynamicObject(3458, -1019.21, 645.38, 134.52,   -0.02, 0.00, 90.00,23,0);
	CreateDynamicObject(3458, -1020.22, 667.80, 134.52,   -0.02, 0.00, 0.00,23,0);
	CreateDynamicObject(3458, -1062.51, 667.67, 134.52,   -0.02, 0.00, 0.00,23,0);
	CreateDynamicObject(3458, -1041.93, 666.50, 134.52,   -0.02, 0.00, 90.00,23,0);
	CreateDynamicObject(3458, -1064.60, 644.49, 134.52,   -0.02, 0.00, 0.00,23,0);
	CreateDynamicObject(3458, -1041.91, 622.39, 134.52,   -0.02, 0.00, 90.00,23,0);
	CreateDynamicObject(3458, -1019.30, 644.31, 134.52,   -0.02, 0.00, 0.00,23,0);
	CreateDynamicObject(1632, -1042.03, 637.44, 136.03,   0.00, 0.00, 0.00,23,0);
	CreateDynamicObject(1632, -1042.01, 592.69, 136.03,   0.00, 0.00, 180.00,23,0);
	CreateDynamicObject(1632, -1034.05, 585.11, 136.03,   0.00, 0.00, 90.00,23,0);
	CreateDynamicObject(1632, -1050.54, 584.74, 136.03,   0.00, 0.00, -90.00,23,0);
	CreateDynamicObject(1632, -1042.05, 577.37, 136.03,   0.00, 0.00, 0.00,23,0);
	CreateDynamicObject(1225, -1060.53, 586.93, 136.36,   0.00, 0.00, 0.00,23,0);
	CreateDynamicObject(1225, -1045.38, 584.75, 136.36,   0.00, 0.00, 0.00,23,0);
	CreateDynamicObject(1225, -1039.65, 584.80, 136.36,   0.00, 0.00, 0.00,23,0);
	CreateDynamicObject(1225, -1041.63, 581.96, 136.36,   0.00, 0.00, 0.00,23,0);
	CreateDynamicObject(1225, -1041.98, 588.01, 136.36,   0.00, 0.00, 0.00,23,0);
	CreateDynamicObject(1225, -1052.37, 586.92, 136.36,   0.00, 0.00, 0.00,23,0);
	CreateDynamicObject(1225, -1052.19, 582.99, 136.36,   0.00, 0.00, 0.00,23,0);
	CreateDynamicObject(1225, -1044.28, 594.28, 136.36,   0.00, 0.00, 0.00,23,0);
	CreateDynamicObject(1225, -1040.07, 594.12, 136.36,   0.00, 0.00, 0.00,23,0);
	CreateDynamicObject(1632, -1041.99, 651.39, 136.03,   0.00, 0.00, 180.00,23,0);
	CreateDynamicObject(1632, -1034.80, 644.50, 136.03,   0.00, 0.00, 90.00,23,0);
	CreateDynamicObject(1632, -1049.51, 644.46, 136.03,   0.00, 0.00, -90.00,23,0);
	CreateDynamicObject(1225, -1038.70, 643.90, 136.04,   0.00, 0.00, 0.00,23,0);
	CreateDynamicObject(1225, -1041.90, 641.66, 136.04,   0.00, 0.00, 0.00,23,0);
	CreateDynamicObject(1225, -1045.40, 644.55, 136.04,   0.00, 0.00, 0.00,23,0);
	CreateDynamicObject(1225, -1041.93, 647.24, 136.04,   0.00, 0.00, 0.00,23,0);
	CreateDynamicObject(1225, -1043.53, 653.32, 136.33,   0.00, 0.00, 0.00,23,0);
	CreateDynamicObject(1225, -1040.18, 653.00, 136.33,   0.00, 0.00, 0.00,23,0);
	CreateDynamicObject(1225, -1033.36, 646.59, 136.33,   0.00, 0.00, 0.00,23,0);
	CreateDynamicObject(1225, -1033.38, 642.63, 136.33,   0.00, 0.00, 0.00,23,0);
	CreateDynamicObject(1225, -1039.61, 635.80, 136.33,   0.00, 0.00, 0.00,23,0);
	CreateDynamicObject(1225, -1044.09, 635.66, 136.33,   0.00, 0.00, 0.00,23,0);
	//
	//Minigun + RPG
	CreateDynamicObjectEx(4247, 2159.10, -5591.10, 3.00,   0.00, 0.00, 0.00, 200.0,200.0, {10,11});
	CreateDynamicObjectEx(16685, 2068.90, -5549.50, 26.60,   90.00, 0.00, 90.00, 200.0,200.0, {10,11});
	CreateDynamicObjectEx(16685, 2151.70, -5687.90, 26.60,   90.00, 0.00, 179.99, 200.0,200.0, {10,11});
	CreateDynamicObjectEx(16685, 2198.40, -5520.20, 26.60,   90.00, 0.00, 0.00, 200.0,200.0, {10,11});
	CreateDynamicObjectEx(16685, 2278.00, -5607.10, 26.60,   90.00, 0.00, 270.00, 200.0,200.0, {10,11});
	CreateDynamicObjectEx(4247, 2159.30, -5597.70, 52.00,   180.00, 0.00, 0.00, 200.0,200.0, {10,11});
	CreateDynamicObjectEx(3279, 2086.60, -5540.00, 3.00,   0.00, 0.00, 0.00, 200.0,200.0, {10,11});
	CreateDynamicObjectEx(3279, 2084.70, -5537.50, 19.10,   0.00, 0.00, 0.00, 200.0,200.0, {10,11});
	CreateDynamicObjectEx(3279, 2261.80, -5541.90, 3.00,   0.00, 0.00, 0.00, 200.0,200.0, {10,11});
	CreateDynamicObjectEx(3279, 2259.50, -5540.10, 19.10,   0.00, 0.00, 0.00, 200.0,200.0, {10,11});
	CreateDynamicObjectEx(3279, 2080.10, -5672.60, 3.00,   0.00, 0.00, 0.00, 200.0,200.0, {10,11});
	CreateDynamicObjectEx(3279, 2078.70, -5670.80, 19.10,   0.00, 0.00, 0.00, 200.0,200.0, {10,11});
	CreateDynamicObjectEx(3279, 2264.60, -5671.70, 3.00,   0.00, 0.00, 0.00, 200.0,200.0, {10,11});
	CreateDynamicObjectEx(3279, 2261.90, -5669.70, 19.10,   0.00, 0.00, 0.00, 200.0,200.0, {10,11});
	CreateDynamicObjectEx(3271, 2100.00, -5574.00, 2.90,   0.00, 0.00, 313.99, 200.0,200.0, {10,11});
	CreateDynamicObjectEx(16093, 2079.40, -5614.20, 7.30,   0.00, 0.00, 0.00, 200.0,200.0, {10,11});
	CreateDynamicObjectEx(12911, 2274.60, -5602.60, 3.00,   0.00, 0.00, 191.00, 200.0,200.0, {10,11});
	CreateDynamicObjectEx(3887, 2169.90, -5616.90, 11.20,   0.00, 0.00, 44.00, 200.0,200.0, {10,11});
	CreateDynamicObjectEx(11425, 2177.20, -5558.30, 4.80,   0.00, 0.00, 0.00, 200.0,200.0, {10,11});
	CreateDynamicObjectEx(11426, 2174.30, -5540.50, 3.00,   0.00, 0.00, 0.00, 200.0,200.0, {10,11});
	CreateDynamicObjectEx(11427, 2199.50, -5541.50, 10.20,   0.00, 0.00, 0.00, 200.0,200.0, {10,11});
	CreateDynamicObjectEx(11428, 2224.20, -5595.40, 8.90,   0.00, 0.00, 116.00, 200.0,200.0, {10,11});
	CreateDynamicObjectEx(11440, 2119.50, -5637.80, 3.00,   0.00, 0.00, 20.00, 200.0,200.0, {10,11});
	CreateDynamicObjectEx(11442, 2217.70, -5644.50, 3.00,   0.00, 0.00, 0.00, 200.0,200.0, {10,11});
	CreateDynamicObjectEx(11443, 2214.90, -5632.60, 3.00,   0.00, 0.00, 220.00, 200.0,200.0, {10,11});
	CreateDynamicObjectEx(11444, 2268.10, -5640.30, 3.00,   0.00, 0.00, 0.00, 200.0,200.0, {10,11});
	CreateDynamicObjectEx(11445, 2265.40, -5633.70, 3.00,   0.00, 0.00, 0.00, 200.0,200.0, {10,11});
	CreateDynamicObjectEx(11446, 2199.00, -5555.70, 3.00,   0.00, 0.00, 0.00, 200.0,200.0, {10,11});
	CreateDynamicObjectEx(11445, 2184.50, -5590.70, 3.00,   0.00, 0.00, 86.00, 200.0,200.0, {10,11});
	CreateDynamicObjectEx(11458, 2139.80, -5647.20, 3.00,   0.00, 0.00, 312.00, 200.0,200.0, {10,11});
	CreateDynamicObjectEx(11459, 2122.60, -5554.90, 3.00,   0.00, 0.00, 0.00, 200.0,200.0, {10,11});
	CreateDynamicObjectEx(16095, 2250.50, -5529.00, 3.00,   0.00, 0.00, 156.00, 200.0,200.0, {10,11});
	CreateDynamicObjectEx(11492, 2260.20, -5602.50, 3.00,   0.00, 0.00, 90.00, 200.0,200.0, {10,11});
	CreateDynamicObjectEx(4174, 2176.20, -5561.00, 5.30,   0.00, 0.00, 0.00, 200.0,200.0, {10,11});
	CreateDynamicObjectEx(6204, 2261.40, -5625.60, 5.00,   0.00, 0.00, 0.00, 200.0,200.0, {10,11});
	CreateDynamicObjectEx(8679, 2164.30, -5638.20, 3.80,   0.00, 0.00, 0.00, 200.0,200.0, {10,11});
	CreateDynamicObjectEx(8836, 2212.90, -5532.90, 5.10,   0.00, 0.00, 0.00, 200.0,200.0, {10,11});
	CreateDynamicObjectEx(8990, 2090.90, -5685.30, 3.70,   0.00, 0.00, 0.00, 200.0,200.0, {10,11});
	CreateDynamicObjectEx(9034, 2215.30, -5603.50, 5.20,   0.00, 0.00, 0.00, 200.0,200.0, {10,11});
	CreateDynamicObjectEx(11413, 2096.90, -5572.60, 4.80,   0.00, 0.00, 0.00, 200.0,200.0, {10,11});
	CreateDynamicObjectEx(14402, 2181.30, -5679.20, 3.80,   0.00, 0.00, 12.00, 200.0,200.0, {10,11});
	CreateDynamicObjectEx(14468, 2173.30, -5683.40, 3.80,   0.00, 0.00, 354.00, 200.0,200.0, {10,11});
	CreateDynamicObjectEx(14468, 2165.60, -5674.80, 3.80,   0.00, 0.00, 66.00, 200.0,200.0, {10,11});
	CreateDynamicObjectEx(14469, 2158.30, -5678.70, 3.80,   0.00, 0.00, 318.00, 200.0,200.0, {10,11});
	CreateDynamicObjectEx(680, 2122.20, -5622.40, 3.00,   0.00, 0.00, 0.00, 200.0,200.0, {10,11});
	CreateDynamicObjectEx(681, 2142.30, -5655.30, 3.00,   0.00, 0.00, 0.00, 200.0,200.0, {10,11});
	CreateDynamicObjectEx(729, 2082.20, -5633.40, 3.00,   0.00, 0.00, 0.00, 200.0,200.0, {10,11});
	CreateDynamicObjectEx(727, 2181.50, -5548.00, 3.00,   0.00, 0.00, 0.00, 200.0,200.0, {10,11});
	CreateDynamicObjectEx(726, 2222.80, -5613.70, 3.00,   0.00, 0.00, 0.00, 200.0,200.0, {10,11});
	CreateDynamicObjectEx(733, 2231.50, -5567.30, 3.00,   0.00, 0.00, 0.00, 200.0,200.0, {10,11});
	CreateDynamicObjectEx(734, 2118.40, -5599.90, 3.00,   0.00, 0.00, 0.00, 200.0,200.0, {10,11});
	CreateDynamicObjectEx(736, 2173.20, -5647.70, 14.20,   0.00, 0.00, 0.00, 200.0,200.0, {10,11});
	CreateDynamicObjectEx(764, 2123.60, -5678.90, 3.00,   0.00, 0.00, 0.00, 200.0,200.0, {10,11});
	CreateDynamicObjectEx(765, 2209.90, -5549.80, 3.00,   0.00, 0.00, 0.00, 200.0,200.0, {10,11});
	CreateDynamicObjectEx(769, 2119.80, -5544.10, 3.00,   0.00, 0.00, 0.00, 200.0,200.0, {10,11});
	CreateDynamicObjectEx(3279, 2202.00, -5584.20, 3.00,   0.00, 0.00, 326.00, 200.0,200.0, {10,11});
	CreateDynamicObjectEx(3279, 2146.80, -5630.90, 3.00,   0.00, 0.00, 0.00, 200.0,200.0, {10,11});
	CreateDynamicObjectEx(3279, 2145.00, -5628.80, 19.10,   0.00, 0.00, 0.00, 200.0,200.0, {10,11});
	CreateDynamicObjectEx(3279, 2135.00, -5557.60, 3.00,   0.00, 0.00, 0.00, 200.0,200.0, {10,11});
	CreateDynamicObjectEx(3279, 2230.70, -5632.50, 3.00,   0.00, 0.00, 332.00, 200.0,200.0, {10,11});
	CreateDynamicObjectEx(18844, 2166.31, -5594.10, 91.33,   80.04, 19.56, 0.00, 200.0,200.0, {10,11});
	DM_Zone[DM_RPG] = CreateDynamicRectangle(2035.31,  -5690.00, 2282.88, -5492.23, 10);
	DM_Zone[DM_MINI] = CreateDynamicRectangle(2035.31,  -5690.00, 2282.88, -5492.23, 11);
	//Oneshoot + Jetpack
	CreateDynamicObjectEx(7996, 1631.59, 1585.81, 17.96,   0.00, -90.00, 0.00, 200.0,200.0, {12,13});
	CreateDynamicObjectEx(7996, 1585.06, 1646.40, 17.96,   0.00, -90.00, 90.00, 200.0,200.0, {12,13});
	CreateDynamicObjectEx(7996, 1522.02, 1598.85, 17.96,   0.00, -90.00, 180.00, 200.0,200.0, {12,13});
	CreateDynamicObjectEx(7996, 1567.05, 1544.83, 17.96,   0.00, -90.00, -90.00, 200.0,200.0, {12,13});
	CreateDynamicObjectEx(8171, 1539.53, 1587.02, 81.70,   180.00, 0.00, 0.00, 200.0,200.0, {12,13});
	CreateDynamicObjectEx(8171, 1579.33, 1583.46, 81.70,   180.00, 0.00, 0.00, 200.0,200.0, {12,13});
	CreateDynamicObjectEx(8171, 1618.48, 1579.57, 81.70,   180.00, 0.00, 0.00, 200.0,200.0, {12,13});
	CreateDynamicObjectEx(3095, 1587.46, 1626.02, 9.80,   0.00, 90.00, 0.00, 200.0,200.0, {12,13});
	CreateDynamicObjectEx(3095, 1572.52, 1618.07, 9.80,   0.00, 90.00, 0.00, 200.0,200.0, {12,13});
	CreateDynamicObjectEx(3095, 1584.97, 1595.16, 9.80,   0.00, 90.00, 0.00, 200.0,200.0, {12,13});
	CreateDynamicObjectEx(3095, 1603.48, 1613.23, 9.80,   0.00, 90.00, 180.00, 200.0,200.0, {12,13});
	CreateDynamicObjectEx(3095, 1583.89, 1611.29, 9.80,   0.00, 90.00, 180.00, 200.0,200.0, {12,13});
	CreateDynamicObjectEx(3095, 1572.15, 1594.99, 9.80,   0.00, 90.00, 90.00, 200.0,200.0, {12,13});
	CreateDynamicObjectEx(3095, 1563.26, 1586.57, 9.80,   0.00, 90.00, 0.00, 200.0,200.0, {12,13});
	CreateDynamicObjectEx(3095, 1538.26, 1619.31, 9.80,   0.00, 90.00, 0.00, 200.0,200.0, {12,13});
	CreateDynamicObjectEx(3095, 1564.67, 1564.66, 9.80,   0.00, 90.00, 0.00, 200.0,200.0, {12,13});
	CreateDynamicObjectEx(3095, 1564.73, 1606.36, 9.80,   0.00, 90.00, 0.00, 200.0,200.0, {12,13});
	CreateDynamicObjectEx(3095, 1543.45, 1602.11, 9.80,   0.00, 90.00, 0.00, 200.0,200.0, {12,13});
	CreateDynamicObjectEx(3095, 1553.82, 1619.54, 9.80,   0.00, 90.00, 180.00, 200.0,200.0, {12,13});
	CreateDynamicObjectEx(3095, 1558.69, 1640.57, 9.80,   0.00, 90.00, 0.00, 200.0,200.0, {12,13});
	CreateDynamicObjectEx(3095, 1535.43, 1586.02, 9.80,   0.00, 90.00, 0.00, 200.0,200.0, {12,13});
	CreateDynamicObjectEx(3095, 1545.89, 1573.28, 9.80,   0.00, 90.00, 180.00, 200.0,200.0, {12,13});
	CreateDynamicObjectEx(3095, 1601.86, 1583.15, 9.80,   0.00, 90.00, 180.00, 200.0,200.0, {12,13});
	CreateDynamicObjectEx(3095, 1587.12, 1571.49, 9.80,   0.00, 90.00, 180.00, 200.0,200.0, {12,13});
	CreateDynamicObjectEx(3095, 1618.54, 1596.38, 9.80,   0.00, 90.00, 180.00, 200.0,200.0, {12,13});
	CreateDynamicObjectEx(3095, 1584.36, 1557.21, 9.80,   0.00, 90.00, 180.00, 200.0,200.0, {12,13});
	CreateDynamicObjectEx(3095, 1614.09, 1562.39, 9.80,   0.00, 90.00, 180.00, 200.0,200.0, {12,13});
	CreateDynamicObjectEx(3095, 1616.85, 1577.36, 9.80,   0.00, 90.00, 0.00, 200.0,200.0, {12,13});
	CreateDynamicObjectEx(3095, 1616.32, 1632.04, 9.80,   0.00, 90.00, 0.00, 200.0,200.0, {12,13});
	CreateDynamicObjectEx(3095, 1594.90, 1564.83, 9.80,   0.00, 90.00, 0.00, 200.0,200.0, {12,13});
	CreateDynamicObjectEx(3095, 1578.58, 1565.90, 9.80,   0.00, 90.00, 90.00, 200.0,200.0, {12,13});
	CreateDynamicObjectEx(3095, 1597.93, 1599.41, 9.80,   0.00, 90.00, 90.00, 200.0,200.0, {12,13});
	CreateDynamicObjectEx(3095, 1621.99, 1622.29, 9.80,   0.00, 90.00, 90.00, 200.0,200.0, {12,13});
	CreateDynamicObjectEx(3095, 1583.40, 1621.52, 9.80,   0.00, 90.00, 90.00, 200.0,200.0, {12,13});
	CreateDynamicObjectEx(3095, 1560.80, 1610.26, 9.80,   0.00, 90.00, 90.00, 200.0,200.0, {12,13});
	CreateDynamicObjectEx(3095, 1573.96, 1583.45, 9.80,   0.00, 90.00, 90.00, 200.0,200.0, {12,13});
	CreateDynamicObjectEx(3095, 1550.21, 1573.03, 9.80,   0.00, 90.00, 90.00, 200.0,200.0, {12,13});
	CreateDynamicObjectEx(3095, 1540.36, 1585.76, 9.80,   0.00, 90.00, 90.00, 200.0,200.0, {12,13});
	CreateDynamicObjectEx(3095, 1543.08, 1619.22, 9.80,   0.00, 90.00, 90.00, 200.0,200.0, {12,13});
	CreateDynamicObjectEx(3095, 1613.83, 1592.41, 9.80,   0.00, 90.00, 270.00, 200.0,200.0, {12,13});
	CreateDynamicObjectEx(3095, 1563.40, 1636.81, 9.80,   0.00, 90.00, 270.00, 200.0,200.0, {12,13});
	CreateDynamicObjectEx(3095, 1599.49, 1569.26, 9.80,   0.00, 90.00, 270.00, 200.0,200.0, {12,13});
	CreateDynamicObjectEx(3095, 1582.49, 1576.09, 9.80,   0.00, 90.00, 270.00, 200.0,200.0, {12,13});
	CreateDynamicObjectEx(18825, 1537.02, 1555.44, 9.79,   0.00, 0.00, 0.00, 200.0,200.0, {12,13});
	CreateDynamicObjectEx(18825, 1533.42, 1637.47, 9.79,   0.00, 0.00, 0.00, 200.0,200.0, {12,13});
	CreateDynamicObjectEx(18825, 1618.15, 1553.58, 9.79,   0.00, 0.00, -182.70, 200.0,200.0, {12,13});
	CreateDynamicObjectEx(18825, 1618.66, 1638.28, 9.79,   0.00, 0.00, -182.70, 200.0,200.0, {12,13});
	CreateDynamicObjectEx(18825, 1619.70, 1597.64, 46.00,   90.00, 0.00, -182.70, 200.0,200.0, {12,13});
	CreateDynamicObjectEx(18825, 1543.84, 1597.51, 46.00,   90.00, 0.00, -359.70, 200.0,200.0, {12,13});
	CreateDynamicObjectEx(18825, 1573.01, 1602.09, 68.61,   90.00, 0.00, -447.72, 200.0,200.0, {12,13});
	CreateDynamicObjectEx(18825, 1581.08, 1597.87, 23.49,   90.00, 0.00, -265.74, 200.0,200.0, {12,13});
	CreateDynamicObjectEx(8339, 1641.13, 1629.41, 13.82,   356.86, 0.00, 180.26, 200.0,200.0, {12,13});
	CreateDynamicObjectEx(8339, 1641.37, 1548.52, 13.82,   356.86, 0.00, 180.56, 200.0,200.0, {12,13});
	DM_Zone[DM_OS] = CreateDynamicRectangle(1510.32, 1538.50, 1636.08, 1651.43, 12);
	DM_Zone[DM_JP] = CreateDynamicRectangle(1510.32, 1538.50, 1636.08, 1651.43, 13);
	//Snajper
	CreateDynamicObject(8357, 1477.39, 1411.05, 34.48,   0.00, 0.00, 0.00, 14, 0);
	CreateDynamicObject(8357, 1437.41, 1409.12, 34.48,   0.00, 0.00, 0.00, 14, 0);
	CreateDynamicObject(8357, 1397.86, 1408.65, 34.48,   0.00, 0.00, 0.00, 14, 0);
	CreateDynamicObject(8357, 1495.52, 1410.72, 51.81,   0.00, -90.00, 0.00, 14, 0);
	CreateDynamicObject(8357, 1495.56, 1410.53, 88.05,   0.00, -90.00, 0.00, 14, 0);
	CreateDynamicObject(8357, 1400.69, 1407.33, 51.81,   0.00, 90.00, 0.00, 14, 0);
	CreateDynamicObject(8357, 1400.76, 1411.41, 90.42,   0.00, 90.00, 0.00, 14, 0);
	CreateDynamicObject(8357, 1404.47, 1314.95, 51.81,   0.00, 90.00, 90.00, 14, 0);
	CreateDynamicObject(8357, 1405.32, 1315.11, 90.43,   0.00, 90.00, 90.00, 14, 0);
	CreateDynamicObject(8357, 1404.71, 1513.50, 51.81,   0.00, 90.00, -90.00, 14, 0);
	CreateDynamicObject(8357, 1404.71, 1513.50, 89.16,   0.00, 90.00, -90.00, 14, 0);
	CreateDynamicObject(18852, 1447.64, 1315.76, 104.36,   0.00, 90.00, 0.00, 14, 0);
	CreateDynamicObject(18852, 1449.04, 1326.20, 104.36,   0.00, 90.00, 0.00, 14, 0);
	CreateDynamicObject(18852, 1449.23, 1336.78, 104.36,   0.00, 90.00, 0.00, 14, 0);
	CreateDynamicObject(18852, 1447.42, 1347.23, 104.36,   0.00, 90.00, 0.00, 14, 0);
	CreateDynamicObject(18852, 1447.42, 1357.51, 104.36,   0.00, 90.00, 0.00, 14, 0);
	CreateDynamicObject(18852, 1446.72, 1368.31, 104.36,   0.00, 90.00, 0.00, 14, 0);
	CreateDynamicObject(18852, 1447.45, 1378.94, 104.36,   0.00, 90.00, 0.00, 14, 0);
	CreateDynamicObject(18852, 1446.99, 1389.57, 104.36,   0.00, 90.00, 0.00, 14, 0);
	CreateDynamicObject(18852, 1447.12, 1399.88, 104.36,   0.00, 90.00, 0.00, 14, 0);
	CreateDynamicObject(18852, 1447.21, 1410.11, 104.36,   0.00, 90.00, 0.00, 14, 0);
	CreateDynamicObject(18852, 1447.21, 1420.29, 104.36,   0.00, 90.00, 0.00, 14, 0);
	CreateDynamicObject(18852, 1447.45, 1430.28, 104.36,   0.00, 90.00, 0.00, 14, 0);
	CreateDynamicObject(18852, 1447.38, 1440.56, 104.36,   0.00, 90.00, 0.00, 14, 0);
	CreateDynamicObject(18852, 1447.37, 1451.09, 104.36,   0.00, 90.00, 0.00, 14, 0);
	CreateDynamicObject(18852, 1447.30, 1461.57, 104.36,   0.00, 90.00, 0.00, 14, 0);
	CreateDynamicObject(18852, 1447.27, 1471.95, 104.36,   0.00, 90.00, 0.00, 14, 0);
	CreateDynamicObject(18852, 1447.30, 1482.11, 104.36,   0.00, 90.00, 0.00, 14, 0);
	CreateDynamicObject(18852, 1447.41, 1492.60, 104.36,   0.00, 90.00, 0.00, 14, 0);
	CreateDynamicObject(18852, 1447.55, 1502.75, 104.36,   0.00, 90.00, 0.00, 14, 0);
	CreateDynamicObject(18852, 1447.34, 1511.37, 104.36,   0.00, 90.00, 0.00, 14, 0);
	CreateDynamicObject(3279, 1449.73, 1456.10, 34.43,   0.00, 0.00, -85.68, 14, 0);
	CreateDynamicObject(3279, 1476.93, 1503.01, 34.43,   0.00, 0.00, -19.44, 14, 0);
	CreateDynamicObject(3279, 1415.22, 1503.20, 34.43,   0.00, 0.00, 44.76, 14, 0);
	CreateDynamicObject(3279, 1418.36, 1445.39, 34.43,   0.00, 0.00, 87.48, 14, 0);
	CreateDynamicObject(3279, 1475.05, 1443.51, 34.43,   0.00, 0.00, 95.58, 14, 0);
	CreateDynamicObject(3279, 1464.88, 1397.05, 34.43,   0.00, 0.00, 0.00, 14, 0);
	CreateDynamicObject(3279, 1429.78, 1354.17, 34.43,   0.00, 0.00, -183.60, 14, 0);
	CreateDynamicObject(3279, 1469.84, 1344.66, 34.43,   0.00, 0.00, -93.90, 14, 0);
	CreateDynamicObject(3279, 1418.30, 1384.68, 34.43,   0.00, 0.00, -39.78, 14, 0);
	CreateDynamicObject(3279, 1442.02, 1414.87, 34.43,   0.00, 0.00, -260.64, 14, 0);
	CreateDynamicObject(3279, 1444.77, 1497.97, 34.43,   0.00, 0.00, 0.00, 14, 0);
	CreateDynamicObject(3279, 1442.65, 1384.92, 34.43,   0.00, 0.00, 43.08, 14, 0);
	CreateDynamicObject(3279, 1459.33, 1374.31, 34.43,   0.00, 0.00, -166.92, 14, 0);
	DM_Zone[DM_SNP] = CreateDynamicRectangle(1383.55, 1301.73, 1505.78, 1536.39, 14);
}