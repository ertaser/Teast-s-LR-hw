Action()
{

	lr_start_transaction("BP_webtours");

	lr_start_transaction("enterwebtours");

	web_reg_find("Text/IC=Error","fail=found",LAST);
	
	web_url("webtours", 
		"URL=http://localhost:1080/webtours/", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("enterwebtours",LR_AUTO);

	lr_think_time(5);

	lr_start_transaction("login");
	
	web_reg_find("Text/IC=User password was correct",LAST);
	
	web_reg_find("Text/IC=Error","fail=found",LAST);

	web_submit_form("login.pl", 
		"Snapshot=t2.inf", 
		ITEMDATA, 
		"Name=username", "Value={login}", ENDITEM, 
		"Name=password", "Value={password}", ENDITEM, 
		"Name=login.x", "Value=29", ENDITEM, 
		"Name=login.y", "Value=15", ENDITEM, 
		LAST);

	lr_end_transaction("login",LR_AUTO);

	lr_think_time(5);

	lr_start_transaction("Flights");
	
	web_reg_find("Text/IC=Error","fail=found",LAST);

	web_image("Search Flights Button", 
		"Alt=Search Flights Button", 
		"Snapshot=t3.inf", 
		LAST);

	lr_end_transaction("Flights",LR_AUTO);

	lr_think_time(5);

	web_custom_request("FormDateUpdate.class", 
		"URL=http://localhost:1080/WebTours/classes/FormDateUpdate.class", 
		"Method=HEAD", 
		"Resource=1", 
		"Referer=", 
		"Snapshot=t7.inf", 
		LAST);

	lr_think_time(5);

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

	lr_think_time(5);

	lr_start_transaction("FindFlight");
	
		web_reg_find("Text/IC=Error","fail=found",LAST);
	
		web_reg_save_param("outboundFlight1", 
    	"LB=\"outboundFlight\" value=\"", 
    	"RB=\"",
    	"ORD=ALL",  
    	LAST ); 

	web_submit_data("reservations.pl", 
		"Action=http://localhost:1080/cgi-bin/reservations.pl", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/reservations.pl?page=welcome", 
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=depart", "Value={departCity}", ENDITEM, 
		"Name=departDate", "Value={departDate}", ENDITEM, 
		"Name=arrive", "Value={arriveCity}", ENDITEM, 
		"Name=returnDate", "Value={returnDate}", ENDITEM, 
		"Name=numPassengers", "Value={RandomsPassengers}", ENDITEM, 
		"Name=seatPref", "Value={seatPref}", ENDITEM, 
		"Name=seatType", "Value={seatType}", ENDITEM, 
		"Name=.cgifields", "Value=roundtrip", ENDITEM, 
		"Name=.cgifields", "Value=seatType", ENDITEM, 
		"Name=.cgifields", "Value=seatPref", ENDITEM, 
		"Name=findFlights.x", "Value=54", ENDITEM, 
		"Name=findFlights.y", "Value=11", ENDITEM, 
		LAST);
	
	lr_save_string(lr_paramarr_random("outboundFlight1"), "outboundFlightStr");

	lr_end_transaction("FindFlight",LR_AUTO);

	lr_think_time(5);

	lr_start_transaction("ChuseFly");
	
	web_reg_find("Text/IC=Error","fail=found",LAST);

	web_submit_form("reservations.pl_2", 
		"Snapshot=t11.inf", 
		ITEMDATA, 
		"Name=outboundFlight", "Value={outboundFlightStr}", ENDITEM, 
		"Name=reserveFlights.x", "Value=54", ENDITEM, 
		"Name=reserveFlights.y", "Value=7", ENDITEM, 
		LAST);

	lr_end_transaction("ChuseFly",LR_AUTO);

	lr_think_time(5);

	lr_start_transaction("Credintails");
	
	web_reg_find("Text/IC=Error","fail=found",LAST);

	web_submit_form("reservations.pl_3", 
		"Snapshot=t12.inf", 
		ITEMDATA, 
		"Name=firstName", "Value={firstName}", ENDITEM, 
		"Name=lastName", "Value={lastName}", ENDITEM, 
		"Name=address1", "Value={address1}", ENDITEM, 
		"Name=address2", "Value={address2}", ENDITEM, 
		"Name=pass1", "Value={firstName} {lastName}", ENDITEM, 
		"Name=creditCard", "Value={creditCard}", ENDITEM, 
		"Name=expDate", "Value={expDate}", ENDITEM, 
		"Name=saveCC", "Value=<OFF>", ENDITEM, 
		"Name=buyFlights.x", "Value=26", ENDITEM, 
		"Name=buyFlights.y", "Value=8", ENDITEM, 
		LAST);

	lr_end_transaction("Credintails",LR_AUTO);

	lr_think_time(5);

	lr_start_transaction("invoice");
	
	web_reg_find("Text/IC=Error","fail=found",LAST);

	lr_end_transaction("invoice",LR_AUTO);

	lr_start_transaction("gotolist");
	
	web_reg_find("Text/IC=Error","fail=found",LAST);

	web_url("welcome.pl", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=itinerary", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=flights", 
		"Snapshot=t13.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("gotolist",LR_AUTO);

	lr_think_time(5);

	lr_start_transaction("Signoff");
	
	web_reg_find("Text/IC=Error","fail=found",LAST);

	web_image("SignOff Button", 
		"Alt=SignOff Button", 
		"Snapshot=t15.inf", 
		LAST);

	
	
	lr_end_transaction("Signoff", LR_AUTO);
	
	lr_end_transaction("BP_webtours", LR_AUTO);

	return 0;
}