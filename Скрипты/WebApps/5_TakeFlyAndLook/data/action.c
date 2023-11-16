Action()
{

	lr_start_transaction("BP_webtours");

	lr_start_transaction("enterwebtours");

	web_url("webtours", 
		"URL=http://localhost:1080/webtours/", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("enterwebtours",LR_AUTO);

	lr_think_time(18);

	lr_start_transaction("login");

	web_submit_form("login.pl", 
		"Snapshot=t2.inf", 
		ITEMDATA, 
		"Name=username", "Value=jojo", ENDITEM, 
		"Name=password", "Value=bean", ENDITEM, 
		"Name=login.x", "Value=29", ENDITEM, 
		"Name=login.y", "Value=15", ENDITEM, 
		LAST);

	lr_end_transaction("login",LR_AUTO);

	lr_think_time(24);

	lr_start_transaction("Flights");

	web_image("Search Flights Button", 
		"Alt=Search Flights Button", 
		"Snapshot=t3.inf", 
		LAST);

	lr_end_transaction("Flights",LR_AUTO);

	lr_think_time(4);

	web_custom_request("FormDateUpdate.class", 
		"URL=http://localhost:1080/WebTours/classes/FormDateUpdate.class", 
		"Method=HEAD", 
		"Resource=1", 
		"Referer=", 
		"Snapshot=t7.inf", 
		LAST);

	lr_think_time(6);

	web_custom_request("CalSelect.class", 
		"URL=http://localhost:1080/WebTours/classes/CalSelect.class", 
		"Method=HEAD", 
		"Resource=1", 
		"Referer=", 
		"Snapshot=t8.inf", 
		LAST);

	web_custom_request("Calendar.class", 
		"URL=http://localhost:1080/WebTours/classes/Calendar.class", 
		"Method=HEAD", 
		"Resource=1", 
		"Referer=", 
		"Snapshot=t9.inf", 
		LAST);

	lr_think_time(35);

	lr_start_transaction("FindFlight");

	web_submit_data("reservations.pl", 
		"Action=http://localhost:1080/cgi-bin/reservations.pl", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/reservations.pl?page=welcome", 
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=depart", "Value=Denver", ENDITEM, 
		"Name=departDate", "Value=11/08/2023", ENDITEM, 
		"Name=arrive", "Value=London", ENDITEM, 
		"Name=returnDate", "Value=11/09/2023", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=seatPref", "Value=Window", ENDITEM, 
		"Name=seatType", "Value=First", ENDITEM, 
		"Name=.cgifields", "Value=roundtrip", ENDITEM, 
		"Name=.cgifields", "Value=seatType", ENDITEM, 
		"Name=.cgifields", "Value=seatPref", ENDITEM, 
		"Name=findFlights.x", "Value=54", ENDITEM, 
		"Name=findFlights.y", "Value=11", ENDITEM, 
		LAST);

	lr_end_transaction("FindFlight",LR_AUTO);

	lr_think_time(27);

	lr_start_transaction("ChuseFly");

	web_submit_form("reservations.pl_2", 
		"Snapshot=t11.inf", 
		ITEMDATA, 
		"Name=outboundFlight", "Value=022;600;11/08/2023", ENDITEM, 
		"Name=reserveFlights.x", "Value=54", ENDITEM, 
		"Name=reserveFlights.y", "Value=7", ENDITEM, 
		LAST);

	lr_end_transaction("ChuseFly",LR_AUTO);

	lr_think_time(58);

	lr_start_transaction("Credintails");

	web_submit_form("reservations.pl_3", 
		"Snapshot=t12.inf", 
		ITEMDATA, 
		"Name=firstName", "Value=Jojo", ENDITEM, 
		"Name=lastName", "Value=Bean", ENDITEM, 
		"Name=address1", "Value=qwerty", ENDITEM, 
		"Name=address2", "Value=asdf/asdf/asdf", ENDITEM, 
		"Name=pass1", "Value=Jojo Bean", ENDITEM, 
		"Name=creditCard", "Value=12345", ENDITEM, 
		"Name=expDate", "Value=123", ENDITEM, 
		"Name=saveCC", "Value=<OFF>", ENDITEM, 
		"Name=buyFlights.x", "Value=26", ENDITEM, 
		"Name=buyFlights.y", "Value=8", ENDITEM, 
		LAST);

	lr_end_transaction("Credintails",LR_AUTO);

	lr_think_time(37);

	lr_start_transaction("invoice");

	lr_end_transaction("invoice",LR_AUTO);

	lr_start_transaction("gotolist");

	web_url("welcome.pl", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=itinerary", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=flights", 
		"Snapshot=t13.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("gotolist",LR_AUTO);

	lr_think_time(45);

	lr_start_transaction("Deletefromlist");

	web_submit_form("itinerary.pl", 
		"Snapshot=t14.inf", 
		ITEMDATA, 
		"Name=1", "Value=on", ENDITEM, 
		"Name=removeFlights.x", "Value=35", ENDITEM, 
		"Name=removeFlights.y", "Value=8", ENDITEM, 
		LAST);

	lr_end_transaction("Deletefromlist",LR_AUTO);

	lr_think_time(14);

	lr_start_transaction("Signoff");

	web_image("SignOff Button", 
		"Alt=SignOff Button", 
		"Snapshot=t15.inf", 
		LAST);

	return 0;
}