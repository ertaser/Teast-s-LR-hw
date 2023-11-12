Action()
{

	lr_start_transaction("BP_Webtours");

	lr_start_transaction("EnterWebtours");

	web_url("webtours", 
		"URL=http://localhost:1080/webtours/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("EnterWebtours",LR_AUTO);

	lr_think_time(17);

	lr_start_transaction("SignUP");

	web_url("sign up now", 
		"URL=http://localhost:1080/cgi-bin/login.pl?username=&password=&getInfo=true", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/WebTours/home.html", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		LAST);

	lr_think_time(182);

	web_submit_data("login.pl", 
		"Action=http://localhost:1080/cgi-bin/login.pl", 
		"Method=POST", 
		"TargetFrame=info", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/login.pl?username=&password=&getInfo=true", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=username", "Value=dwarf", ENDITEM, 
		"Name=password", "Value=gnom", ENDITEM, 
		"Name=passwordConfirm", "Value=gnom", ENDITEM, 
		"Name=firstName", "Value=Dwarf", ENDITEM, 
		"Name=lastName", "Value=Dwarfgone", ENDITEM, 
		"Name=address1", "Value=UnderVulcan", ENDITEM, 
		"Name=address2", "Value=Dwarfgone/UnderVulcan/Dwarf", ENDITEM, 
		"Name=register.x", "Value=58", ENDITEM, 
		"Name=register.y", "Value=6", ENDITEM, 
		LAST);

	lr_end_transaction("SignUP",LR_AUTO);

	lr_think_time(48);

	lr_start_transaction("DrimTrip");

	web_url("button_next.gif", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=menus", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/login.pl", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("DrimTrip",LR_AUTO);

	lr_think_time(15);

	lr_start_transaction("SignOFF");

	web_url("SignOff Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?signOff=1", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("SignOFF",LR_AUTO);

	return 0;
}