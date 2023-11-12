Action1()
{

	lr_start_transaction("BP_webtours");

	lr_start_transaction("Enterwebtour");

	web_url("webtours", 
		"URL=http://localhost:1080/webtours", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t12.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("Enterwebtour",LR_AUTO);

	lr_think_time(71);

	lr_start_transaction("login");

	web_submit_form("login.pl", 
		"Snapshot=t13.inf", 
		ITEMDATA, 
		"Name=username", "Value=jojo", ENDITEM, 
		"Name=password", "Value=bean", ENDITEM, 
		"Name=login.x", "Value=56", ENDITEM, 
		"Name=login.y", "Value=10", ENDITEM, 
		LAST);

	lr_end_transaction("login",LR_AUTO);

	lr_think_time(127);

	lr_start_transaction("iterary");

	web_image("Itinerary Button", 
		"Alt=Itinerary Button", 
		"Snapshot=t14.inf", 
		LAST);

	lr_end_transaction("iterary",LR_AUTO);

	lr_think_time(30);

	lr_start_transaction("delete");

	web_submit_form("itinerary.pl", 
		"Snapshot=t15.inf", 
		ITEMDATA, 
		"Name=1", "Value=on", ENDITEM, 
		"Name=2", "Value=on", ENDITEM, 
		"Name=3", "Value=on", ENDITEM, 
		"Name=removeFlights.x", "Value=35", ENDITEM, 
		"Name=removeFlights.y", "Value=4", ENDITEM, 
		LAST);

	lr_end_transaction("delete",LR_AUTO);

	lr_think_time(16);

	lr_start_transaction("signoff");

	web_image("SignOff Button", 
		"Alt=SignOff Button", 
		"Snapshot=t16.inf", 
		LAST);

	lr_end_transaction("signoff",LR_AUTO);

	lr_end_transaction("BP_webtours",LR_AUTO);

	return 0;
}