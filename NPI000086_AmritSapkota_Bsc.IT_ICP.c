#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<math.h>

void welcome(); //function to show welcome window.
void sub_menu();  // function to show menu for existing and new users.
void admin_pw(); // function to authenticate admin part.
void claim(int);  // function to claim insurance amount for registered subscribers.
void view_profile(int); // function to see subscriber profile.
int id_generate(); // function to assign auto ID to users.
void view_andregister_plans(); // function to view plans and choose plans and limits.
void main_menu(); // function to show first menu of the program.
void admin_menu(); // function to show admin menu.
void lifetime_120(); //function to register Plan 120 Lifetime claim subscribers.
void annual_150();  //function to register Plan 150 Annual claim subscribers
void lifetime_150();  //function to register Plan 150 Lifetime claim subscribers.
void annual_200();  //function to register Plan 200 Annnual claim subscribers.
void lifetime_200(); //function to register Plan 200 Lifetime claim subscribers.
void annual_120();  //function to register Plan 120 Annual claim subscribers
void customer_menu(int); // function to show menu after user logins to system.
void view_list(); // function in admin part to show personal details along with subscribers limit and monthly premium.
void del_details(); // function to delete profile of subscriber.
void signup(); // function to assign username and password to subscribers. 
void login(); // function to read username and password from file and login.
void update(int,int); //function to update claim limit.
void trans(int,int); //function to update transaction along with date.
void s_name(); //function to search subscriber profile by name.
void s_id();  //function to search subscriber profile by ID.

void fordelay(int c)
{   int a,b;
    for(a=0;a<c;a++)
         b=a;
}

void main() 
{
	welcome();
	system("cls");	
    main_menu();
}

void welcome()
{
	printf("\t\t\t*********************************************************");
    printf("\n\t\t\t***** WELCOME TO HEALTH INSURANCE MANAGEMENT SYSTEM *****");
    printf("\n\t\t\t*********************************************************");
    printf("\n\n\n\n\n\tPress any key to continue...");
	getch();
}

void main_menu() // function to show main menu
{
	int option;
	system("cls");
    printf("\n------------------------------------\nZeeMediLife Insurance Company\n------------------------------------\n");
    printf("\n1.Admin Menu");
    printf("\n2.Customer Menu");
    printf("\n3.Exit");
    printf("\n\nSelect your choice:\n"); scanf("%d",&option);
    switch(option)
    {
        case 1: admin_pw();break;
        case 2: sub_menu(); break;
        case 3: printf("\nThanks for using this application!Bye!bye!");getch(); return;
        default: printf("\n\nInvalid option!. Enter [1-3]!\n\n");
    }
    getch();
}
	
void admin_menu() // function to show admin menu
{
	int option;
	system("cls");
    printf("\n1.View Subscriber list");
    printf("\n2.Delete Subscriber Profile");
    printf("\n3.Search By Name");
    printf("\n4.Search By ID");
    printf("\n5.Go Back To Main Menu");
    printf("\n6.Exit");
    printf("\n\nSelect your choice:\n"); scanf("%d",&option);
    system("cls");
    switch(option)
    {
        case 1: view_list();break;
        case 2: del_details(); break;
        case 3: s_name(); break;
        case 4: s_id(); break;
        case 5: main_menu();break;
        case 6: printf("\nThanks for using this application!Bye!Bye!");getch(); return;
        default: printf("\n\nInvalid option!. Enter [1-6]!\n\n");
    }
    getch();
		
}

void customer_menu(int id) // function to show menu after user logins to system
{
	int option;
	
	system("cls");
	//maxID = id;
	printf("\n1.Register");
    printf("\n2.Claim");
    printf("\n3.view your profile");
    printf("\n4.Go back to main menu!");
    printf("\n5.Exit");
    printf("\n\nSelect your choice:\n"); scanf("%d",&option);
    system("cls");
    switch(option)
    {
        case 1: view_andregister_plans();break;
		case 2: claim(id); return;
        case 3: view_profile(id); return;
        case 4: main_menu(); break;
        case 5: printf("\nThanks for using this application!Bye!bye!");getch(); return;
        default: printf("\n\nInvalid option!. Enter [1-5]!\n\n");
    }
    getch();	
}

void sub_menu() // function to show menu for existing and new users.
{
	int option;
	system("cls");
    printf("\n1.Login");
    printf("\n2.Sign-Up");
    printf("\n3.Go Back To Main Menu");
    printf("\n4.Exit");
    printf("\n\nSelect your choice:\n"); scanf("%d",&option);
    system("cls");
    switch(option)
    {
        case 1: login();break;
        case 2: signup(); break;
        case 3: main_menu();break;
        case 4: printf("\nThanks for using this application!Bye!bye!");getch(); return;
        default: printf("\n\nInvalid option!. Enter [1-4]!\n\n");
    }
    getch();
}

void view_list() // function to view personal details along with limit and monthly premium of subscribers.
{
	FILE *ptr;
	char name[50],address[50],history[50];
	int contact,maxID,ch,claim,mp;
    ptr=(fopen("detailss.txt","r"));
	system("cls");
    printf("\nID\t\tNAME\t\tCONTACT NUMBER\t\tADDRESS\t\tHEALTH HISTORY\t\tCLAIM\t\tMONTHLY PREMIUM\n");
	while(fscanf(ptr,"%d\t\t%s\t\t%d\t\t%s\t\t%s\t\t%d\t\t%d\n",&maxID,&name,&contact,&address,&history,&claim,&mp)==7)
    {
        printf("%d\t\t%s\t\t%d\t\t%s\t\t%s\t\t\t%d\t\t%d\n",maxID,name,contact,address,history,claim,mp);
           
    }
	fclose(ptr);
    try_2:
	printf("\n\n press 1 to go back to admin menu and 0 to exit:");
	scanf("%d",&ch);
	if (ch==1)
		admin_menu();
	else if(ch==0)
    {
        return;
    }
    else
    {
        printf("invalid option");
        goto try_2;
	}
}
 
void view_andregister_plans(int id) // function to view plans and choose plans and limits.
{
	int ch,maxID;
	int age;
    system("cls");
    printf("\nEnter your age:"); scanf("%d", &age);
    if(age<20)
    {
    
    	printf("\n\nYou have access to Plan120,Plan150 and Plan200.(Age<20)\n------------------------------------\n");
	    printf("\t\t\tPlan120\t\tPlan150\t\tPlan200");
	    printf("\nMonthly Premium");
	    printf("\t\t120\t\t150\t\t200");
	    printf("\nAnnual Claim Limit");
	    printf("\t120,000\t\t150,000\t\t200,000");
	    printf("\nLifetime Claim Limit");
	    printf("\t600,000\t\t750,000\t\t1,000,000");
	    printf("\n\n\n");
	    printf("Hospitalisation and Surgical Benefits:\n------------------------------------\n");
		printf("Types of Claim\t\t\t\tEligibility Amount");
		printf("\n\n\t\t\tPlan120\t\tPlan150\t\tPlan200");
		printf("\n1.Room Charges");
		printf("\t\t120/day\t\t150/day\t\t200/day");
		printf("\n2.Intensive Care Unit \t250/day\t\t400/day\t\t700/day \n (ICU) Charges");
		printf("\n3.Hospital Supplies\t\tAs charged\n and services\t\t\tsubject to");
		printf("\n4.Surgical Fees\t\t\tapproval ");
		printf("\n5.Other Fees Charges\t\tby ZeeMediLife.");
		printf("\n\n");
		printf("\nYou can select following plans:");
		printf("\n1.Plan 120_annual");
		printf("\n2.Plan 120_lifetime");
    	printf("\n3.Plan 150_annual");
    	printf("\n4.Plan 150_lifetime");
    	printf("\n5.Plan 200_annual");
    	printf("\n6.Plan 200_lifetime");
    	printf("\n7. Go back to customer menu!");
    	printf("\n8. Exit");
    	printf("\n\nSelect your choice:"); scanf("%d",&ch);
    	switch (ch)
    	{
    		case 1: printf("\n*****REGISTRATION*****");annual_120(); break;
    		case 2: lifetime_120(); break;
    		case 3: annual_150(); break;
    		case 4: lifetime_150();break;
    		case 5: annual_200(); break;
    		case 6: lifetime_200(); break;
    		case 7: customer_menu(id); break;
    		case 8: printf("\nThanks for using this application!Bye!bye!");getch(); return;
        	default: printf("\n\nInvalid option!. Enter [1-8]!\n\n");
		}getch();
		
	} 
	else if(age<40)
    {
    	
    	printf("\n\nYou have access to Plan150 and Plan200. (Age<40)\n------------------------------------\n");
    	printf("\t\t\tPlan150\t\tPlan200");
	    printf("\nMonthly Premium");
	    printf("\t\t150\t\t200");
	    printf("\nAnnual Claim Limit");
	    printf("\t150,000\t\t200,000");
	    printf("\nLifetime Claim Limit");
	    printf("\t750,000\t\t1,000,000");
	    printf("\n\n\n");
	    printf("Hospitalisation and Surgical Benefits:\n------------------------------------\n");
		printf("Types of Claim\t\t\t\tEligibility amount");
		printf("\n\n\t\t\tPlan150\t\tPlan200");
		printf("\n1.Room Charges");
		printf("\t\t150/day\t\t200/day");
		printf("\n2.Intensive Care Unit \t400/day\t\t700/day \n (ICU) Charges");
		printf("\n3.Hospital Supplies\t\tAs charged\n and services\t\t\tsubject to");
		printf("\n4.Surgical Fees\t\t\tapproval ");
		printf("\n5.Other Fees Charges\t\tby ZeeMediLife.");
		printf("\n\n");
		printf("\nYou have access to following plans:");
		printf("\n1.Plan 150_annual");
    	printf("\n2.Plan 150_lifetime");
    	printf("\n3.Plan 200_annual");
    	printf("\n4.Plan 200_lifetime");
    	printf("\n5. Go back to customer menu!");
    	printf("\n6. Exit");
    	printf("\n\nSelect your choice:"); scanf("%d",&ch);
    	switch (ch)
    	{
    		case 1: printf("\n*****REGISTRATION*****");annual_150(); break;
    		case 2: lifetime_150();break;
    		case 3: annual_200(); break;
    		case 4: lifetime_200(); break;
    		case 5: customer_menu(id); break;
    		case 6: printf("\nThanks for using this application!Bye!bye!");getch(); return;
        	default: printf("\n\nInvalid option!. Enter [1-6]!\n\n");
		}getch();
    }
    else
    {
    	if(age<54)
    	{
    		
    		printf("\n\nYou only have access to Plan200.(Age<54)\n------------------------------------\n");
    		printf("\t\t\tPlan200");
		    printf("\nMonthly Premium");
		    printf("\t\t200");
		    printf("\nAnnual Claim Limit");
		    printf("\t200,000");
		    printf("\nLifetime Claim Limit");
		    printf("\t1,000,000");
		    printf("\n\n\n");
		    printf("Hospitalisation and Surgical Benefits:\n------------------------------------\n");
			printf("Types of Claim\t\t\t\tEligibility amount");
			printf("\n\n\t\t\t\tPlan200");
			printf("\n1.Room Charges");
			printf("\t\t\t200/day");
			printf("\n2.Intensive Care Unit \t\t700/day \n (ICU) Charges");
			printf("\n3.Hospital Supplies\t\tAs charged\n and services\t\t\tsubject to");
			printf("\n4.Surgical Fees\t\t\tapproval ");
			printf("\n5.Other Fees Charges\t\tby ZeeMediLife.");
			printf("\n\n");
			printf("\nYou have access to following plans:");
			printf("\n1.Plan 200_annual");
	    	printf("\n2.Plan 200_lifetime");
	    	printf("\n3. Go back to customer menu!");
	    	printf("\n4. Exit");
	    	printf("\n\nSelect your choice:"); scanf("%d",&ch);
	    	switch (ch)
	    	{
	    		case 1: printf("\n*****REGISTRATION*****");annual_200(); break;
	    		case 2: lifetime_200(); break;
	    		case 3: customer_menu(id); break;
	    		case 4: printf("\nThanks for using this application!Bye!bye!");getch(); return;
	        	default: printf("\n\nInvalid option!. Enter [1-4]!\n\n");
			}getch();
	    }
    }
}

void annual_120() //function to register Plan 120 Annual claim subscribers.
{
	FILE *ptr;
	char name[50],address[50],history[50];
	int contact,id,maxID,ch,claim=120000,mp=120;
	ptr=(fopen("detailss.txt","a"));
	if(ptr==NULL) 
	{
		printf("file not found!");
		getch(); return;
	}
	id=id_generate();
	printf("\nEnter Name:"); scanf("%s",&name); fflush(stdin);
	printf("Enter Your contact number:");
	scanf("%d",&contact); fflush(stdin);  
	printf("Enter Your address:");
	scanf("%s",&address); fflush(stdin);
	printf("Please enter your health history:");
	scanf("%s",&history); fflush(stdin);
	fprintf(ptr,"%d\t\t%s\t\t%d\t\t%s\t\t%s\t\t%d\t\t%d\n",id,name,contact,address,history,claim,mp);
	fclose(ptr);
	printf("\n Your record is sucessfully registered!!");
	try_1:
	printf("\n Press 1 to go back to customer menu and 0 to exit:");
	scanf("%d",&ch);
	if (ch==1)
	{
	customer_menu(id);
	}
	else if(ch==0)
    {
        return;
    }
    else
    {
    	printf("invalid option");
    	goto try_1;
	}	
}

void lifetime_120() //function to register Plan 120 Lifetime claim subscribers.
{
	FILE *ptr;
	char name[50],address[50],history[50];
	int contact,id,maxID,ch, claim=600000, mp=120;
	ptr= fopen("detailss.txt","a");
	if(ptr==NULL) 
	{
		printf("file not found!");
		getch(); return;
	}
		id=id_generate();
		printf("\nEnter Name:"); scanf("%s",&name); fflush(stdin);
		printf("Enter Your contact number:");
		scanf("%d",&contact); fflush(stdin);  
		printf("Enter Your address:");
		scanf("%s",&address); fflush(stdin);
		//gets(address); fflush(stdin);
		printf("Please enter your health history:");
		scanf("%s",&history); fflush(stdin);
		//gets(history); fflush(stdin);
		fprintf(ptr,"%d\t\t%s\t\t%d\t\t%s\t\t%s\t\t%d\t\t%d\n",id,name,contact,address,history,claim,mp);
		printf("\n Your record is sucessfully registered!!");
		try_1:
		printf("\n Press 1 to go back to customer menu and 0 to exit:");
		scanf("%d",&ch);
		if (ch==1)
			customer_menu(id);
		else if(ch==0)
        {
            return;
        }
        else
        {
        	printf("invalid option");
        	goto try_1;
		}	
		fclose(ptr);
}

void annual_150() //function to register Plan 150 Annual claim subscribers
{
	FILE *ptr;
	char name[50],address[50],history[50];
	int contact,id,maxID,ch, claim=150000,mp=150;
	ptr=(fopen("detailss.txt","a"));
	if(ptr==NULL) 
	{
		printf("file not found!");
		getch(); return;
	}
		id=id_generate();
		printf("\nEnter Name:"); scanf("%s",&name); fflush(stdin);
		printf("Enter Your contact number:");
		scanf("%d",&contact); fflush(stdin);  
		printf("Enter Your address:");
		scanf("%s",&address); fflush(stdin);
		printf("Please enter your health history:");
		scanf("%s",&history); fflush(stdin);
		fprintf(ptr,"%d\t\t%s\t\t%d\t\t%s\t\t%s\t\t%d\t\t%d\n",id,name,contact,address,history,claim,mp);
		fclose(ptr);
		printf("\n Your record is sucessfully registered!!");
		try_1:
		printf("\n Press 1 to go back to customer menu and 0 to exit:");
		scanf("%d",&ch);
		if (ch==1)
			customer_menu(id);
		else if(ch==0)
        {
            return;
        }
        else
        {
        	printf("invalid option");
        	goto try_1;
		}	
}

void lifetime_150() //function to register Plan 150 Lifetime claim subscribers.
{
	FILE *ptr;
	char name[50],address[50],history[50];
	int contact,id,maxID,ch, claim=200000,mp=150;
	ptr=(fopen("detailss.txt","a"));
	if(ptr==NULL) 
	{
		printf("file not found!");
		getch(); return;
	}
		id=id_generate();
		printf("\nEnter Name:"); scanf("%s",&name); fflush(stdin);
		printf("Enter Your contact number:");
		scanf("%d",&contact); fflush(stdin);  
		printf("Enter Your address:");
		scanf("%s",&address); fflush(stdin);
		printf("Please enter your health history:");
		scanf("%s",&history); fflush(stdin);
		fprintf(ptr,"%d\t\t%s\t\t%d\t\t%s\t\t%s\t\t%d\t\t%d\n",id,name,contact,address,history,claim,mp);
		fclose(ptr);
		printf("\n Your record is sucessfully registered!!");
		try_1:
		printf("\n Press 1 to go back to customer menu and 0 to exit:");
		scanf("%d",&ch);
		if (ch==1)
			customer_menu(id);
		else if(ch==0)
        {
            return;
        }
        else
        {
        	printf("invalid option");
        	goto try_1;
		}	
}

void annual_200() //function to register Plan 200 Annual claim subscribers.
{
	FILE *ptr;
	char name[50],address[50],history[50];
	int contact,id,maxID,ch, claim=200000,mp=200;
	ptr=(fopen("detailss.txt","a"));
	if(ptr==NULL) 
	{
		printf("file not found!");
		getch(); return;
	}
		id=id_generate();
		printf("\nEnter Name:"); scanf("%s",&name); fflush(stdin);
		printf("Enter Your contact number:");
		scanf("%d",&contact); fflush(stdin);  
		printf("Enter Your address:");
		scanf("%s",&address); fflush(stdin);
		printf("Please enter your health history:");
		scanf("%s",&history); fflush(stdin);
		fprintf(ptr,"%d\t\t%s\t\t%d\t\t%s\t\t%s\t\t%d\t\t%d\n",id,name,contact,address,history,claim,mp);
		fclose(ptr);
		printf("\n Your record is sucessfully registered!!");
		try_1:
		printf("\n Press 1 to go back to customer menu and 0 to exit:");
		scanf("%d",&ch);
		if (ch==1)
			customer_menu(id);
		else if(ch==0)
        {
            return;
        }
        else
        {
        	printf("invalid option");
        	goto try_1;
		}	
}

void lifetime_200() //function to register Plan 200 Lifetime claim subscribers.
{
	FILE *ptr;
	char name[50],address[50],history[50];
	int contact,id,ch, claim=1000000,mp=200;
	ptr=(fopen("detailss.txt","a"));
	if(ptr==NULL) 
	{
		printf("file not found!");
		getch(); return;
	}
		id=id_generate();
		printf("\n\nEnter Name"); scanf("%s",&name); fflush(stdin);
		printf("Enter Your contact number:");
		scanf("%d",&contact); fflush(stdin);  
		printf("Enter Your address:");
		scanf("%s",&address); fflush(stdin);
		printf("Please enter your health history");
		scanf("%s",&history); fflush(stdin);
		fprintf(ptr,"%d\t\t%s\t\t%d\t\t%s\t\t%s\t\t%d\t\t%d\n",id,name,contact,address,history,claim,mp);
		fclose(ptr);
		printf("\n Your record is sucessfully registered!!");
		try_1:
		printf("\n Press 1 to go back to customer menu and 0 to exit:");
		scanf("%d",&ch);
		if (ch==1)
			customer_menu(id);
		else if(ch==0)
        {
            return;
        }
        else
        {
        	printf("invalid option");
        	goto try_1;
		}	
}

void admin_pw() // function to autheticate admin.
{
	system("cls");	
    char password0[20],password1[20]="admin123";
    int a=0;
    try:
    printf("\n\nEnter Password:");
    
    scanf("%s",password0);
	
    if (strcmp(password0,password1)==0)
        {
		printf("\n\nPassword Matched!\nLOADING");
        for(a=0;a<=8;a++)
        {
            fordelay(100000000);
            printf(".");
        }
                system("cls");
            admin_menu();
        }
    else
        { 
			printf("\nIncorrect passsword!"); getch();
			goto try;
        }
        getch();
        
}

void signup() // function to assign username and password to new users.
{
	system("cls");
	FILE *ptr;
	char name[50];
	char pw[50],pw1[50];
	int ch;
	ptr=(fopen("signup.txt","a"));
	if(ptr==NULL) 
	{
		printf("file not found!");
		getch(); return;
	}
		printf("Enter Username:"); scanf("%s",&name); fflush(stdin);
		printf("Enter password:");
		scanf("%s",&pw); fflush(stdin);  
		printf("Re-enter paswword:");
		scanf("%s",&pw1); fflush(stdin);
		fprintf(ptr,"%s\t\t%s\n\n",name,pw);
		fclose(ptr);
		printf("\nUsername and password created sucessfully!");
		try_1:
		printf("\n\n press 1 to go back to menu and 0 to exit:");
		scanf("%d",&ch);
		if (ch==1)
			sub_menu();
		else if(ch==0)
        {
            return;
        }
        else
        {
        	printf("invalid option");
        	goto try_1;
		}	
}

void login(int id) // function to read username and password from file and login to system.
{
	char name[25], pw[25], un1[25], pw1[25], ch;
	int a;
	FILE *as;
	try_again:
	system("cls");
    printf("\nEnter your username: "); scanf("%s",&name); fflush(stdin);
	printf("\nEnter your password: "); scanf("%s",&pw); fflush(stdin);
	as= fopen("signup.txt", "r");
	if(as==NULL)
	{ 
		printf("\nCannot open file!!"); 
		getch();
    }
    while(fscanf(as,"%s %s",un1, pw1)==2)
	{
	    if(strcmp(name,un1)==0 && strcmp(pw,pw1)==0)
	    {
	    	fclose(as);
			printf("\nYou have successfully logged in!!\nLOADING");
			for(a=0;a<=8;a++)
        	{
            	fordelay(100000000);
            	printf(".");
        	}
            system("cls");
            customer_menu(id); return;
        }
    }
	printf("\nIncorrect passsword!");
	try_1:
	printf("\nEnter 1 to try again or 0 to go to subscriber menu:");
	scanf("%d",&ch);
	if (ch==1)
	{
		goto try_again;
	}
	else if(ch==0)
    {
        sub_menu();
    }
    else
    {
        printf("Invalid option! Enter valid input!");
        goto try_1;
	}
        getch();
}

int id_generate() //function to assign unique Id to registered customer.
{
	FILE *ptr;
	char name[50],address[50],history[50];
	int contact,maxid=0,claim,id,mp;
	ptr=fopen("detailss.txt","r");
	if(ptr==NULL)
	{
		printf("\nFile not found!"); getch(); return;
	}
	while(fscanf(ptr,"%d %s %d %s %s %d %d", &id, &name, &contact, &address, &history, &claim,&mp)==7)
	{
		if(id>=maxid)
 		{
 			maxid= id;
 		}
	}
	return (maxid+5);
	fclose(ptr);
	getch();
}

void del_details() //function to delete subscriber profile.
{
 	FILE *del, *del1;
	char name[50],address[50],history[50],nid;
	int contact,maxid=0,claim,id,mp;
	del=fopen("detailss.txt","r");
	del1 = fopen("tmp.txt","w");
	
	char oldfile[] ="tmp.txt";
	char newfile[] = "detailss.txt"; 
	if(del==NULL)
	{
		printf("\nFile not found!"); getch(); return;
	}
	printf("Enter ID you want to delete: "); scanf("%d",&nid);fflush(stdin);
	while(fscanf(del,"%d %s %d %s %s %d %d", &id, &name, &contact, &address, &history, &claim,&mp)==7)
	{
		if(id!=nid)
		{
			fprintf(del1,"%d %s %d %s %s %d %d\n", id, name, contact, address, history, claim,mp);
		}
	}
	fclose(del);
	fclose(del1);
	if(!remove(newfile))
	{
		printf("\n\nfile removed!!");getch();
	}
	if(!rename(oldfile,newfile))
	{
		printf("\n\nFile renamed!!");
	}
	printf("\n\nPress any key to return: ");
	getch();
	admin_menu();
}
 
void claim(int idd) //function to claim insurance amount.
{
 int balance,contact,mp,claimf,total,total1,idf,id;
 char name[50],address[50],history[50];
 FILE *fp, *fp1;
 fp = fopen("detailss.txt","r");
	if(fp==NULL)
	{
		printf("File not found"); return;
	}
	
	printf("\nEnter ID from file: ");scanf("%d",&id);fflush(stdin);
	while(fscanf(fp,"%d %s %d %s %s %d %d", &idf, name, &contact, address, history, &claimf,&mp)==7)
	{
		if(id==idf)
		{
			printf("Enter your Health Care Expenses: "); scanf("%d",&balance);fflush(stdin);
			if(claimf>=balance)
			{
				fclose(fp);
				printf("\n\nYou have claimed: %d",balance);
				printf("\n\nYour remaining balance has been updated!!!");
				total = claimf - balance;
				printf("\n\nREMAINING BALANCE: %d",total);getch();
				update(total,id);
				trans(balance,id);
				getch();
				customer_menu(id);
			}
			else
			{
				
				printf("\n\nTotal claim doesnot cover your expenses!!!"); getch();
				claim(id);
			}
		}
	}
}

void update(int bln, int id) //function to update remaining balance.
{
	int idf,contact,mp,claim;
	char name[50],address[50],history[50];
	FILE *fp, *fp1;
	fp = fopen("detailss.txt","r");
	fp1 = fopen("detailsstmp.txt","w");
	char oldfile[]	= "detailsstmp.txt";
	char newfile[] = "detailss.txt";
	if(fp==NULL)
	{
		printf("File not found"); return;
	}
	//printf("Enter ID: "); scanf("%d",&id);fflush(stdin)
	while(fscanf(fp,"%d %s %d %s %s %d %d", &idf, name, &contact, address, history, &claim,&mp)==7)
	{
		if(idf==id)
		{
			fprintf(fp1,"%d %s %d %s %s %d %d\n", idf, name, contact, address, history, bln,mp);
		}
		else
		{
			fprintf(fp1,"%d %s %d %s %s %d %d\n", idf, name, contact, address, history, claim,mp);
		}
	}
	fclose(fp1);
	fclose(fp);
	getch();
	
	if(!remove(newfile))
	{
		printf("\nFile removed!!");
	}
	
	if(!rename(oldfile, newfile))
	{
		printf("\nFile renamed!!");
	}

}

void trans(int ttl, int id) //function to update transacation.
{
	int idf,contact,mp,claim,bln;
	char name[50],address[50],history[50];
	FILE *fp, *g;
	g = fopen("detailss.txt","r");
	if(g==NULL)
	{
		printf("File not found"); getch(); return;
	}
	while(fscanf(fp,"%d %s %d %s %s %d %d", &idf, name, &contact, address, history, &bln,&mp)==7)
	{
		if (id==idf)
		{
			fp = fopen("transactionfile.txt","a");
			time_t rawtime = time(NULL);
			struct tm *ptm = localtime(&rawtime);
			fprintf(fp,"%d %s %d %d/%d/%d\n",idf,name,ttl,ptm->tm_mday,ptm->tm_mon+1,ptm->tm_year+1900);
			fclose(fp);
		}
	}
	fclose(g);	

}

void view_profile(int id) //function to view own profile
{
	FILE *fp;
	int idf,contact,mp,bln;
	char name[50],address[50],history[50];
	fp = fopen("detailss.txt","r");
	if(fp==NULL)
	{
		printf("file not found"); return;
	}
	//printf("ID : %d\n",id);
	printf("ID: ");scanf("%d",&id);fflush(stdin);
	while(fscanf(fp,"%d %s %d %s %s %d %d", &idf, name, &contact, address, history, &bln,&mp)==7)
	{
		if(idf==id)
		{
 			printf("\n\n***YOUR PERSONAL DETAILS***");
 			printf("\n\nID: %d \nNAME: %s \nCONTACT NUMBER: %d \nADDRESS: %s \nHEALTH HISTORY:%s \nREMAINING BALANCE: %d \nMONTHLY PREMIUM: %d",idf, name, contact, address, history, bln,mp);getch();
		}
	}
	fclose(fp);getch();
	customer_menu(id);
}


void s_name() //function to search by name.
{
	FILE *fp;
	int idf,contact,mp,bln;
	char name[50],address[50],history[50], name1[20],pn[50];
	fp = fopen("detailss.txt","r");
	if(fp==NULL)
	{
		printf("file not found"); return;
	}
	//printf("ID : %d\n",id);
	printf("Enter the name of subscriber: ");scanf("%s",&name1);fflush(stdin);
	while(fscanf(fp,"%d %s %d %s %s %d %d", &idf, name, &contact, address, history, &bln,&mp)==7)
	{
		if(strcmp(name1,name)==0)
		{
 			printf("\n\n***************************");
 			printf("\n***SUBSCRIBER PROFILE******");
 			printf("\n***************************");
 			printf("\n\nID: %d \nNAME: %s \nCONTACT NUMBER: %d \nADDRESS: %s \nHEALTH HISTORY:%s \nREMAINING BALANCE: %d \nMONTHLY PREMIUM: %d",idf, name, contact, address, history, bln,mp);
		}
	}
	fclose(fp); 
	printf("\n\n\nPress any key to go back to admin menu!!"); getch();
	admin_menu();
}

void s_id() //function to search by ID.
{
	FILE *fp;
	int idp,id,contact,mp,bln;
	char name[50],address[50],history[50],pn[50];
	fp = fopen("detailss.txt","r");
	if(fp==NULL)
	{
		printf("file not found"); return;
	}
	//printf("ID : %d\n",id);
	printf("Enter the ID of subscriber: ");scanf("%d",&id);fflush(stdin);
	while(fscanf(fp,"%d %s %d %s %s %d %d", &idp, name, &contact, address, history, &bln,&mp)==7)
	{
		if(id==idp)
		{
			printf("\n\n***************************");
 			printf("\n***SUBSCRIBER PROFILE******");
 			printf("\n***************************");
 			printf("\n\nID: %d \nNAME: %s \nCONTACT NUMBER: %d \nADDRESS: %s \nHEALTH HISTORY:%s \nREMAINING BALANCE: %d \nMONTHLY PREMIUM: %d",idp, name, contact, address, history, bln,mp);
		}
	}
	fclose(fp);
	printf("\n\n\nPress any key to go back to admin menu!!"); getch();
	admin_menu();
	
}
