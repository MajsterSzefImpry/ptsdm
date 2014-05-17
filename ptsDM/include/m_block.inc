#define CommandUseBlock(%0,%1,%2); \
			if(IsBlockCommand(%0,%1,%2)==1)\
			    return 1;


stock IsBlockCommand(playerid, nameblock[54] = "", milisecound)
{
	new b_str[64];
    format(b_str, 64, "blocktime_%s", nameblock);
    if(GetTickCount() < GetPVarInt(playerid, b_str))
	{
	    new ibc_str[80];
		format(ibc_str, 80, "Tej komendy mo¿esz u¿yæ dopiero za {FFFFFF}%d{00AAFF} sekund.",
			((GetPVarInt(playerid, b_str) - GetTickCount()) / 1000) + 1);
			
        SendClientMessage(playerid, 0x00AAFFFF,ibc_str);
	    return 1;
	}
    SetPVarInt(playerid, b_str, GetTickCount() + milisecound);
	return 0;
}
stock UnBlockCommandForPlayer(playerid, nameblock[54] = "")
{
	new b_str[64];
    format(b_str, 64, "blocktime_%s", nameblock);
    DeletePVar(playerid, b_str);
	return 1;
}
