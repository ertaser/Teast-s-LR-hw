#include "globals.h"

Action()
{

	lr_start_transaction("BP_Webtours");

/*Correlation comment - Do not change!  Original value='137653.993843661HAiAfHHpDAiDDDDDtctiDptzDif' Name ='userSession' Type ='ResponseBased'
	web_reg_save_param_attrib(
		"ParamName=userSession",
		"TagName=input",
		"Extract=value",
		"Name=userSession",
		"Type=hidden",
		SEARCH_FILTERS,
		"IgnoreRedirections=No",
		"RequestUrl=nav.pl*",
		LAST);*/
		
		lr_start_transaction("Enter_Webtours");

		
		web_reg_save_param("userSession",
		"LB=userSession\" value=\"",
		"RB=\"",
		LAST);

	web_url("webtours", 
		"URL=http://localhost:1080/webtours/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);
		
		lr_end_transaction("Enter_Webtours", LR_AUTO);


	lr_think_time(5);
	
	lr_start_transaction("login");
	
	web_reg_find("Text/IC=User password was correct",LAST);
	web_reg_find("Text/IC=Error","fail=found",LAST);

	web_submit_data("login.pl",
		"Action=http://localhost:1080/cgi-bin/login.pl",
		"Method=POST",
		"TargetFrame=body",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/nav.pl?in=home",
		"Snapshot=t2.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=userSession", "Value={userSession}", ENDITEM,
		"Name=username", "Value={login}", ENDITEM,
		"Name=password", "Value={password}", ENDITEM,
		"Name=JSFormSubmit", "Value=off", ENDITEM,
		"Name=login.x", "Value=75", ENDITEM,
		"Name=login.y", "Value=6", ENDITEM,
		LAST);
	
	lr_end_transaction("login", LR_AUTO);
	lr_start_transaction("gotoFlights");

	web_reg_find("Text/IC=Error","fail=found",LAST);

	web_url("Search Flights Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=search", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);
	lr_end_transaction("gotoFlights", LR_AUTO);

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
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/reservations.pl?page=welcome", 
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=depart", "Value={departCity}", ENDITEM, 
		"Name=departDate", "Value={departDate1}", ENDITEM, 
		"Name=arrive", "Value={arriveCity}", ENDITEM, 
		"Name=returnDate", "Value={returnDate1}", ENDITEM, 
		"Name=numPassengers", "Value={RandomsPassengers}", ENDITEM, 
		"Name=seatPref", "Value={seatPref}", ENDITEM, 
		"Name=seatType", "Value={seatType}", ENDITEM, 
		"Name=.cgifields", "Value=roundtrip", ENDITEM, 
		"Name=.cgifields", "Value=seatType", ENDITEM, 
		"Name=.cgifields", "Value=seatPref", ENDITEM, 
		"Name=findFlights.x", "Value=82", ENDITEM, 
		"Name=findFlights.y", "Value=7", ENDITEM, 
		LAST);
	
	lr_save_string(lr_paramarr_random("outboundFlight1"), "outboundFlightStr");
	
	lr_end_transaction("FindFlight", LR_AUTO);
	
	lr_think_time(5);
		
	lr_start_transaction("ChuseFly");

	web_reg_find("Text/IC=Error","fail=found",LAST);
	
	web_submit_data("reservations.pl_2", 
		"Action=http://localhost:1080/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/reservations.pl", 
		"Snapshot=t11.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=outboundFlight", "Value={outboundFlightStr}", ENDITEM, 
		"Name=numPassengers", "Value={RandomsPassengers}", ENDITEM, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=seatType", "Value={seatType}", ENDITEM, 
		"Name=seatPref", "Value={seatPref}", ENDITEM, 
		"Name=reserveFlights.x", "Value=57", ENDITEM, 
		"Name=reserveFlights.y", "Value=10", ENDITEM, 
		LAST);
		
	lr_end_transaction("ChuseFly", LR_AUTO);

		
		
	lr_think_time(5);

	lr_start_transaction("Credintails");
	
	web_reg_find("Text/IC=Error","fail=found",LAST);
	
	web_submit_data("reservations.pl_3", 
		"Action=http://localhost:1080/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/reservations.pl", 
		"Snapshot=t12.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=firstName", "Value={firstName}", ENDITEM, 
		"Name=lastName", "Value={lastName}", ENDITEM, 
		"Name=address1", "Value={address1}", ENDITEM, 
		"Name=address2", "Value={address2}", ENDITEM, 
		"Name=pass1", "Value={firstName} {lastName}", ENDITEM, 
		"Name=creditCard", "Value={creditCard}", ENDITEM, 
		"Name=expDate", "Value={expDate}", ENDITEM, 
		"Name=oldCCOption", "Value=", ENDITEM, 
		"Name=numPassengers", "Value={RandomsPassengers}", ENDITEM, 
		"Name=seatType", "Value={seatType}", ENDITEM, 
		"Name=seatPref", "Value={seatPref}", ENDITEM, 
		"Name=outboundFlight", "Value={outboundFlightStr}", ENDITEM, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=returnFlight", "Value=", ENDITEM, 
		"Name=JSFormSubmit", "Value=off", ENDITEM, 
		"Name=.cgifields", "Value=saveCC", ENDITEM, 
		"Name=buyFlights.x", "Value=71", ENDITEM, 
		"Name=buyFlights.y", "Value=10", ENDITEM, 
		LAST);
	
	lr_end_transaction("Credintails", LR_AUTO);

	lr_think_time(5);
	
	lr_start_transaction("LogOFF");

	web_reg_find("Text/IC=Error","fail=found",LAST);

	web_url("welcome.pl", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?signOff=1", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=flights", 
		"Snapshot=t13.inf", 
		"Mode=HTML", 
		LAST);
	lr_end_transaction("LogOFF", LR_AUTO);


	lr_end_transaction("BP_Webtours", LR_AUTO);

	return 0;
}