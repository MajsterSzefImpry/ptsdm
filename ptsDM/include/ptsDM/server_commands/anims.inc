/*
	@Polski TOP Serwer - anims.inc
	@Last update: 14 marca 2014 23:25

*/
CMD:animacje(playerid, params[]) return cmd_anims(playerid, params);
CMD:anim(playerid, params[]) return cmd_anims(playerid, params);
CMD:anims(playerid, params[])
{
	format(bstrx, sizeof bstrx, ""C_O"/pijany  /pal  /lez  /wymiotuj\n/machaj  /klaps  /pocaluj  /siad\n");
	strcat(bstrx, "/fuck  /napad   /ranny  /podloz  /masturbacja\n/wytrysk  /smierc  /lapy  /wino  /piwo\n");
	strcat(bstrx, "/sprunk  /cygaretka  /lej  /strip1\n/strip2  /strip3  /strip4 /strip5\n/dance1  /dance2  /dance3  /dance4\n");
	strcat(bstrx, "/dance5  /dance6  /dance7  /dance8\n/dance9  /dance10  /dance11  /dance12\n/dance13  /dance14  /dance15  /dance16 /dance17");
	strcat(bstrx, "\n\n{00AAFF}Aby zatrzymaæ animacjê wpisz /stopanim");
	InfoBox(playerid, bstrx);
	return 1;
}

CMD:stopanim(playerid, params[])
{
    ClearAnimations(playerid);
    SetPlayerSpecialAction(playerid, SPECIAL_ACTION_NONE);
    return 1;
}

CMD:pijany(playerid, params[])
{
    ApplyAnimation(playerid,"PED", "WALK_DRUNK", 4.0, 1, 1, 0, 0, 0);
    SCM(playerid, 0xCC0000AA, "Aby wy³¹czyæ animcje wpisz: {F8F8FF}/stopanim");
    return 1;
}

CMD:pal(playerid, params[])
{
    ApplyAnimation(playerid, "SMOKING", "F_smklean_loop", 4.0, 0, 0, 0, 0, 0);
    SCM(playerid, 0xCC0000AA, "Aby wy³¹czyæ animcje wpisz: {F8F8FF}/stopanim");
    return 1;
}

CMD:lez(playerid, params[])
{
    ApplyAnimation(playerid, "BEACH", "bather", 4.0, 0, 0, 0, 1, 0);
    SCM(playerid, 0xCC0000AA, "Aby wy³¹czyæ animcje wpisz: {F8F8FF}/stopanim");
    return 1;
}

CMD:wymiotuj(playerid, params[])
{
    ApplyAnimation(playerid, "FOOD", "EAT_Vomit_P", 3.0, 0, 0, 0, 0, 0);
    SCM(playerid, 0xCC0000AA, "Aby wy³¹czyæ animcje wpisz: {F8F8FF}/stopanim");
    return 1;
}

CMD:machaj(playerid, params[])
{
    ApplyAnimation(playerid, "KISSING", "BD_GF_Wave", 3.0, 0, 0, 0, 0, 0);
    SCM(playerid, 0xCC0000AA, "Aby wy³¹czyæ animcje wpisz: {F8F8FF}/stopanim");
    return 1;
}

CMD:klaps(playerid, params[])
{
    ApplyAnimation(playerid, "SWEET", "sweet_ass_slap", 4.0, 0, 0, 0, 0, 0);
    SCM(playerid, 0xCC0000AA, "Aby wy³¹czyæ animcje wpisz: {F8F8FF}/stopanim");
    return 1;
}

CMD:pocaluj(playerid, params[])
{
    ApplyAnimation(playerid, "KISSING", "Playa_Kiss_02", 3.0, 0, 0, 0, 0, 0);
    SCM(playerid, 0xCC0000AA, "Aby wy³¹czyæ animcje wpisz: {F8F8FF}/stopanim");
    return 1;
}

CMD:siad(playerid, params[])
{
    ApplyAnimation(playerid,"BEACH", "ParkSit_M_loop", 4.0, 0, 0, 0, 1, 0);
    SCM(playerid, 0xCC0000AA, "Aby wy³¹czyæ animcje wpisz: {F8F8FF}/stopanim");
    return 1;
}

CMD:fuck(playerid, params[])
{
    ApplyAnimation( playerid,"ped", "fucku", 4.1, 0, 1, 1, 1, 1 );
    SCM(playerid, 0xCC0000AA, "Aby wy³¹czyæ animcje wpisz: {F8F8FF}/stopanim");
    return 1;
}

CMD:napad(playerid, params[])
{
    ApplyAnimation(playerid, "SHOP", "ROB_Loop_Threat", 4.0, 1, 0, 0, 0, -1);
    SCM(playerid, 0xCC0000AA, "Aby wy³¹czyæ animcje wpisz: {F8F8FF}/stopanim");
    return 1;
}

CMD:ranny(playerid, params[])
{
    ApplyAnimation(playerid, "SWEET", "Sweet_injuredloop", 4.0, 1, 0, 0, 1, 0);
    SCM(playerid, 0xCC0000AA, "Aby wy³¹czyæ animcje wpisz: {F8F8FF}/stopanim");
    return 1;
}

CMD:podloz(playerid, params[])
{
    ApplyAnimation(playerid, "BOMBER", "BOM_Plant", 4.0, 0, 0, 0, 0, 0);
    SCM(playerid, 0xCC0000AA, "Aby wy³¹czyæ animcje wpisz: {F8F8FF}/stopanim");
    return 1;
}

CMD:masturbacja(playerid, params[])
{
    ApplyAnimation(playerid, "PAULNMAC", "wank_loop", 4.0, 1, 0, 0, 0, 0);
    SCM(playerid, 0xCC0000AA, "Aby wy³¹czyæ animcje wpisz: {F8F8FF}/stopanim");
    return 1;
}

CMD:wytrysk(playerid, params[])
{
    ApplyAnimation(playerid, "PAULNMAC", "wank_out", 4.0, 0, 0, 0, 0, 0);
    SCM(playerid, 0xCC0000AA, "Aby wy³¹czyæ animcje wpisz: {F8F8FF}/stopanim");
    return 1;
}

CMD:smierc(playerid, params[])
{
    ApplyAnimation(playerid, "WUZI", "CS_Dead_Guy", 4.0, 0, 1, 1, 1, -1);
    SCM(playerid, 0xCC0000AA, "Aby wy³¹czyæ animcje wpisz: {F8F8FF}/stopanim");
    return 1;
}

CMD:lapy(playerid, params[])
{
    ApplyAnimation(playerid, "PED", "handsup", 4.0, 0, 1, 1, 1, 0);
    SCM(playerid, 0xCC0000AA, "Aby wy³¹czyæ animcje wpisz: {F8F8FF}/stopanim");
    return 1;
}

CMD:wino(playerid, params[])
{
    SetPlayerSpecialAction(playerid, SPECIAL_ACTION_DRINK_WINE);
    SCM(playerid, 0xCC0000AA, "Aby wy³¹czyæ animcje wpisz: {F8F8FF}/stopanim");
    return 1;
}

CMD:piwo(playerid, params[])
{
    SetPlayerSpecialAction(playerid, SPECIAL_ACTION_DRINK_BEER);
    SCM(playerid, 0xCC0000AA, "Aby wy³¹czyæ animcje wpisz: {F8F8FF}/stopanim");
    return 1;
}

CMD:sprunk(playerid, params[])
{
    SetPlayerSpecialAction(playerid, SPECIAL_ACTION_DRINK_SPRUNK);
    SCM(playerid, 0xCC0000AA, "Aby wy³¹czyæ animcje wpisz: {F8F8FF}/stopanim");
    return 1;
}

CMD:cygaretka(playerid, params[])
{
    SetPlayerSpecialAction(playerid, SPECIAL_ACTION_SMOKE_CIGGY);
    SCM(playerid, 0xCC0000AA, "Aby wy³¹czyæ animcje wpisz: {F8F8FF}/stopanim");
    return 1;
}

CMD:dance13(playerid, params[])
{
	ApplyAnimation(playerid,"DANCING", "dnce_M_e", 4.0, 1, 0, 0, 0, 0);
	SCM(playerid, 0xCC0000AA, "Aby wy³¹czyæ animcje wpisz: {F8F8FF}/stopanim");
	return 1;
}
CMD:dance12(playerid, params[])
{
	ApplyAnimation(playerid,"DANCING", "dnce_M_d", 4.0, 1, 0, 0, 0, 0);
	SCM(playerid, 0xCC0000AA, "Aby wy³¹czyæ animcje wpisz: {F8F8FF}/stopanim");
	return 1;
}
CMD:dance11(playerid, params[])
{
	ApplyAnimation(playerid,"DANCING", "dnce_M_c", 4.0, 1, 0, 0, 0, 0);
	SCM(playerid, 0xCC0000AA, "Aby wy³¹czyæ animcje wpisz: {F8F8FF}/stopanim");
	return 1;
}
CMD:dance10(playerid, params[])
{
	ApplyAnimation(playerid,"DANCING", "dnce_M_b", 4.0, 1, 0, 0, 0, 0);
	SCM(playerid, 0xCC0000AA, "Aby wy³¹czyæ animcje wpisz: {F8F8FF}/stopanim");
	return 1;
}
CMD:dance9(playerid, params[])
{
	ApplyAnimation(playerid,"DANCING", "dnce_M_a", 4.0, 1, 0, 0, 0, 0);
	SCM(playerid, 0xCC0000AA, "Aby wy³¹czyæ animcje wpisz: {F8F8FF}/stopanim");
	return 1;
}
CMD:dance8(playerid, params[])
{
	ApplyAnimation(playerid,"DANCING", "DAN_Up_A", 4.0, 1, 0, 0, 0, 0);
	SCM(playerid, 0xCC0000AA, "Aby wy³¹czyæ animcje wpisz: {F8F8FF}/stopanim");
	return 1;
}
CMD:dance7(playerid, params[])
{
	ApplyAnimation(playerid,"DANCING", "DAN_Right_A", 4.0, 1, 0, 0, 0, 0);
	SCM(playerid, 0xCC0000AA, "Aby wy³¹czyæ animcje wpisz: {F8F8FF}/stopanim");
	return 1;
}
CMD:dance6(playerid, params[])
{
	ApplyAnimation(playerid,"DANCING", "DAN_Loop_A", 4.0, 1, 0, 0, 0, 0);
	SCM(playerid, 0xCC0000AA, "Aby wy³¹czyæ animcje wpisz: {F8F8FF}/stopanim");
	return 1;
}
CMD:dance5(playerid, params[])
{
	ApplyAnimation(playerid,"DANCING", "DAN_Left_A", 4.0, 1, 0, 0, 0, 0);
	SCM(playerid, 0xCC0000AA, "Aby wy³¹czyæ animcje wpisz: {F8F8FF}/stopanim");
	return 1;
}
CMD:dance4(playerid, params[])
{
	ApplyAnimation(playerid,"DANCING", "DAN_Down_A", 4.0, 1, 0, 0, 0, 0);
	SCM(playerid, 0xCC0000AA, "Aby wy³¹czyæ animcje wpisz: {F8F8FF}/stopanim");
	return 1;
}
CMD:dance3(playerid, params[])
{
	ApplyAnimation(playerid,"DANCING", "dance_loop", 4.0, 1, 0, 0, 0, 0);
	SCM(playerid, 0xCC0000AA, "Aby wy³¹czyæ animcje wpisz: {F8F8FF}/stopanim");
	return 1;
}
CMD:dance2(playerid, params[])
{
	ApplyAnimation(playerid,"DANCING", "bd_clap1", 4.0, 1, 0, 0, 0, 0);
	SCM(playerid, 0xCC0000AA, "Aby wy³¹czyæ animcje wpisz: {F8F8FF}/stopanim");
	return 1;
}
CMD:dance1(playerid, params[])
{
	ApplyAnimation(playerid,"DANCING", "bd_clap", 4.0, 1, 0, 0, 0, 0);
	SCM(playerid, 0xCC0000AA, "Aby wy³¹czyæ animcje wpisz: {F8F8FF}/stopanim");
	return 1;
}
CMD:lej(playerid, params[])
{
    SetPlayerSpecialAction(playerid, 68);
    SCM(playerid, 0xCC0000AA, "Aby wy³¹czyæ animcje wpisz: {F8F8FF}/stopanim");
	return 1;
}
CMD:strip1(playerid, params[])
{
	ApplyAnimation(playerid,"STRIP","strip_A",4.0,0,1,1,1,0);
	SCM(playerid, 0xCC0000AA, "Aby wy³¹czyæ animcje wpisz: {F8F8FF}/stopanim");
    return 1;
}
CMD:strip2(playerid, params[])
{
    ApplyAnimation(playerid,"STRIP","strip_B",4.0,0,1,1,1,0);
    SCM(playerid, 0xCC0000AA, "Aby wy³¹czyæ animcje wpisz: {F8F8FF}/stopanim");
    return 1;
}
CMD:strip3(playerid, params[])
{
    ApplyAnimation(playerid,"STRIP","strip_C",4.0,0,1,1,1,0);
	SCM(playerid, 0xCC0000AA, "Aby wy³¹czyæ animcje wpisz: {F8F8FF}/stopanim");
    return 1;
}
CMD:strip4(playerid, params[])
{
    ApplyAnimation(playerid,"STRIP","strip_D",4.0,0,1,1,1,0);
	SCM(playerid, 0xCC0000AA, "Aby wy³¹czyæ animcje wpisz: {F8F8FF}/stopanim");
    return 1;
}
CMD:strip5(playerid, params[])
{
    ApplyAnimation(playerid,"STRIP","strip_E",4.0,0,1,1,1,0);
	SCM(playerid, 0xCC0000AA, "Aby wy³¹czyæ animcje wpisz: {F8F8FF}/stopanim");
    return 1;
}
CMD:dance14(playerid, params[])
{
    SetPlayerSpecialAction(playerid, SPECIAL_ACTION_DANCE1);
    SCM(playerid, 0xCC0000AA, "Aby wy³¹czyæ animcje wpisz: {F8F8FF}/stopanim");
	return 1;
}
CMD:dance15(playerid, params[])
{
    SetPlayerSpecialAction(playerid, SPECIAL_ACTION_DANCE2);
    SCM(playerid, 0xCC0000AA, "Aby wy³¹czyæ animcje wpisz: {F8F8FF}/stopanim");
	return 1;
}
CMD:dance16(playerid, params[])
{
    SetPlayerSpecialAction(playerid, SPECIAL_ACTION_DANCE3);
    SCM(playerid, 0xCC0000AA, "Aby wy³¹czyæ animcje wpisz: {F8F8FF}/stopanim");
	return 1;
}
CMD:dance17(playerid, params[])
{
    SetPlayerSpecialAction(playerid, SPECIAL_ACTION_DANCE4);
    SCM(playerid, 0xCC0000AA, "Aby wy³¹czyæ animcje wpisz: {F8F8FF}/stopanim");
	return 1;
}
CMD:cellin(playerid, params[])
{
    SetPlayerSpecialAction(playerid, SPECIAL_ACTION_DANCE4);
    SCM(playerid, 0xCC0000AA, "Aby wy³¹czyæ animcje wpisz: {F8F8FF}/stopanim");
	return 1;
}
CMD:cellout(playerid, params[])
{
    SetPlayerSpecialAction(playerid, SPECIAL_ACTION_DANCE4);
    SCM(playerid, 0xCC0000AA, "Aby wy³¹czyæ animcje wpisz: {F8F8FF}/stopanim");
	return 1;
}


