/*
	@Polski TOP Serwer - 3d_spawn.inc
	@Last update: 14 marca 2014 23:25

*/
stock Napisy3D(){
	for( new o; o != sizeof SpawnGracza; o ++ )
	{
	    new
		Float:change = 1.5,
		model = 1239,
		type = 1;
		
		CreatePickup(1318, 1, SpawnGracza[ o ][ 0 ], SpawnGracza[ o ][ 1 ], SpawnGracza[ o ][ 2 ]);
		Create3DTextLabel(""C_O"Witaj na "C_B"Polskim TOP Serwerze"C_O"!",0x000000FF, SpawnGracza[ o ][ 0 ], SpawnGracza[ o ][ 1 ], SpawnGracza[ o ][ 2 ],15.0,0);

		CreatePickup(model, type, SpawnGracza[ o ][ 0 ]+change,SpawnGracza[ o ][ 1 ],SpawnGracza[ o ][ 2 ]);
		CreatePickup(model, type, SpawnGracza[ o ][ 0 ]-change,SpawnGracza[ o ][ 1 ],SpawnGracza[ o ][ 2 ]);
		CreatePickup(model, type, SpawnGracza[ o ][ 0 ],SpawnGracza[ o ][ 1 ]+change,SpawnGracza[ o ][ 2 ]);
		CreatePickup(model, type, SpawnGracza[ o ][ 0 ],SpawnGracza[ o ][ 1 ]-change,SpawnGracza[ o ][ 2 ]);

		Create3DTextLabel(""C_O"Nie znasz komend?\nWpisz "C_B"/CMD "C_O"a poznasz wszystkie!",0x000000FF, SpawnGracza[ o ][ 0 ]+change,SpawnGracza[ o ][ 1 ],SpawnGracza[ o ][ 2 ],15.0,0);
	    Create3DTextLabel(""C_O"Chcesz zakupiæ "C_B"prywatny pojazd"C_O"?\nWpisz "C_B"/Privcar"C_O"!",0x000000FF, SpawnGracza[ o ][ 0 ]-change,SpawnGracza[ o ][ 1 ],SpawnGracza[ o ][ 2 ],15.0,0);
	    Create3DTextLabel(""C_O"Masz pytanie do "C_B"administracji"C_O"?\nWpisz "C_B"/pytanie "C_O"i je zadaj!",0x000000FF, SpawnGracza[ o ][ 0 ],SpawnGracza[ o ][ 1 ]+change,SpawnGracza[ o ][ 2 ],15.0,0);
	    Create3DTextLabel(""C_O"Nasze forum znajdziesz\npod adresem "C_B"TOP.xaa.pl"C_O"!",0x000000FF, SpawnGracza[ o ][ 0 ],SpawnGracza[ o ][ 1 ]-change,SpawnGracza[ o ][ 2 ],15.0,0);
	}
}