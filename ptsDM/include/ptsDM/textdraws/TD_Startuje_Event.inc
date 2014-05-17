/*
	@Polski TOP Serwer - TD_Startuje_Event.inc
	@Last update: 14 marca 2014 23:25

*/
new Event_S[1000];

forward TD_Startuje_Event(times, event_td_show);
public TD_Startuje_Event(times, event_td_show)
{
	if(times > 0)
	{
		if(event_td_show == 1) 
		{
			format(Event_S, sizeof(Event_S),"~r~Chowany ~w~startuje za ~r~%d ~w~sek~n~wpisz ~r~/CH ~w~, aby sie zapisac~r~!", times);
			TextDrawSetString(Event, Event_S);
		}
		else if(event_td_show == 2)
		{
		    format(Event_S, sizeof(Event_S),"~r~Derby ~w~startuja za ~r~%d ~w~sek~n~wpisz ~r~/DD ~w~, aby sie zapisac~r~!", times);
			TextDrawSetString(Event, Event_S);
		}
 		else if(event_td_show == 3)
		{
		    format(Event_S, sizeof(Event_S),"~r~Siano ~w~startuje za ~r~%d ~w~sek~n~wpisz ~r~/SN ~w~, aby sie zapisac~r~!", times);
			TextDrawSetString(Event, Event_S);
		}
  		else if(event_td_show == 4)
		{
		    format(Event_S, sizeof(Event_S),"~r~Skoki ~w~startuja za ~r~%d ~w~sek~n~wpisz ~r~/SS ~w~, aby sie zapisac~r~!", times);
			TextDrawSetString(Event, Event_S);
		}
   		else if(event_td_show == 5)
		{
		    format(Event_S, sizeof(Event_S),"~r~Tower ~w~startuje za ~r~%d ~w~sek~n~wpisz ~r~/TW ~w~, aby sie zapisac~r~!", times);
			TextDrawSetString(Event, Event_S);
		}
   		else if(event_td_show == 6)
		{
		    format(Event_S, sizeof(Event_S),"~r~Wojna Gagnow ~w~startuje za ~r~%d ~w~sek~n~wpisz ~r~/WG ~w~, aby sie zapisac~r~!", times);
			TextDrawSetString(Event, Event_S);
		}
		SetTimerEx("TD_Startuje_Event", 999, 0, "dd", times-1, event_td_show);
		return;
	}
	EventTimer = 0;
	TextDrawHideForAll(Event);
}
