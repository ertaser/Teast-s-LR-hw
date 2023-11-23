Action1()
{
	

	lr_start_transaction("4_LookAtListAndDelete");

	lr_start_transaction("Enter_webtours");

	web_reg_find("Text/IC=Web Tours",LAST);
	
	web_url("webtours", 
		"URL=http://localhost:1080/webtours", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t12.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("Enter_webtours",LR_AUTO);

	lr_think_time(5);

	lr_start_transaction("login");
	
	web_reg_find("Text/IC=User password was correct",LAST);

	web_submit_form("login.pl", 
		"Snapshot=t13.inf", 
		ITEMDATA, 
		"Name=username", "Value={login}", ENDITEM, 
		"Name=password", "Value={password}", ENDITEM, 
		"Name=login.x", "Value=56", ENDITEM, 
		"Name=login.y", "Value=10", ENDITEM, 
		LAST);

	lr_end_transaction("login",LR_AUTO);

	lr_think_time(5);

	lr_start_transaction("iterary");
	
	web_reg_find("Text/IC=Flights List",LAST);
	
/*	web_reg_save_param("before",
		"LB/IC=A total of ",
		"RB/IC= scheduled flights.",
		"Notfound=warning",
		LAST);*/
	
	web_reg_save_param("flightID1",
		"LB=name=\"flightID\" value=",
		"RB=  />",
		"Ord=all",
		LAST);
	
	web_image("Itinerary Button", 
		"Alt=Itinerary Button", 
		"Snapshot=t14.inf", 
		LAST);

	

	lr_end_transaction("iterary",LR_AUTO);

	lr_think_time(5);

	lr_start_transaction("delete");
	
/*		web_reg_save_param("after",
		"LB/IC=A total of ",
		"RB/IC= scheduled flights.",
		"Notfound=warning",
		LAST);*/
	web_reg_find("Text/IC=name=\"flightID\" value={flightID1_1}",
             "fail=Found",
             LAST);
	
	web_submit_form("itinerary.pl", 
		"Snapshot=t15.inf", 
		ITEMDATA, 
		"Name=1", "Value=on", ENDITEM, 
		"Name=removeFlights.x", "Value=35", ENDITEM, 
		"Name=removeFlights.y", "Value=4", ENDITEM, 
		LAST);
		
/*	web_image("Itinerary Button", 
		"Alt=Itinerary Button", 
		"Snapshot=t14.inf", 
		LAST);*/
	

	lr_end_transaction("delete",LR_AUTO);

	lr_think_time(5);

	lr_start_transaction("Logout");
	
	web_reg_find("Text/IC=Web Tours",LAST);

	web_image("SignOff Button", 
		"Alt=SignOff Button", 
		"Snapshot=t16.inf", 
		LAST);

	lr_end_transaction("Logout",LR_AUTO);

	lr_end_transaction("4_LookAtListAndDelete",LR_AUTO);

	return 0;
}