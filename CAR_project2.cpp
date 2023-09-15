//The Project Begin
//New updated verion with login
//HERE is the almost complete code.

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>
#include<time.h>
#include<windows.h>

struct bill{
	char name[40];
	char email[40];
	char contact[10];
	char address[30];
};

//function for generating bill
void generatebill(char [],long int);

int menu();
void signup();
void login();
void forgot();
void change_password();
void delete_account();
void employee_option();
int username_passcode();
void bill_add(struct bill);
//function for generating bill body
void generatebillbody(char [],char [],long int);

void title();

//function for generating bill footer
void generatebillfooter(long int);

struct account
{
    char first_name[20];
    char last_name[20];
    char username[30];
    char phone[15];
    char gender[10];
    char DOB[10];
    char pass1[20];
};

void divider()
{
	printf("\n------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	
}


int main()
{
		here:
		int mistake_login_count=0;
        system("cls");
        switch (menu())
        {
        	case 1:
            	signup();
            	break;

        	case 2:
            	login();
            	break;

        case 3:
            	forgot();
            	break;
     	case 4:
           		exit(0);

        	default:
            	printf("\n\t\t\t\t\t\t\tInvalid Choice! Please try again. Press any key...........................\n");
            	getch();
            	goto here;
        }
    
	return 0;
}
//function for generating bill
void generatebill(char variant[50],long int price_car)
{
	title();
	struct bill customer;
	/*char customer_name[50], email[]="car_wiz_software@gmail.com";
	char contact[]="0134563", phone_no[11], Email[30], address[30];*/
	char email[]="car_wiz_software@gmail.com" , contact[]="0134563";
	
	printf("\n\t\t\t\t\t\t\t\tPlease provide us your information: \n");
	fflush(stdin);
	printf("\n\t\t\t\t\t\t\t\tEnter your full name : ");
	gets(customer.name);
	printf("\n\t\t\t\t\t\t\t\tContact Number       : ");
	gets(customer.contact);
	printf("\n\t\t\t\t\t\t\t\tEmail                : ");
	gets(customer.email);
	printf("\n\t\t\t\t\t\t\t\tAddress              : ");
	gets(customer.address);
	bill_add(customer);
	
	
	title();
	printf("\n\t\t\t\t\t\t\temail      : %s",email);
	printf("\n\t\t\t\t\t\t\tcontact no : %s\n",contact);
	divider();
	//printf("\n........................................");
	//printf("\nDate:%s",date);
	printf("\n\t\t\t\t\t\t\t\tInvoice to:%s",customer.name);
	printf("\n");
	//printf("..........................................\n");
	divider();
	printf("\t\t\t\tModel\t\t\t");
	printf("\t\t\tColor\t\t");
	printf("\t\t\tTotal\t\t");
	//printf("\n........................................\n\n");
	divider();
	printf("\n\n");
}

//function for generating bill body
void generatebillbody(char model[50],char car_color[20],long int price)
{
	printf("\t\t\t\t%s\t\t\t\t\t",model);
	printf("%s\t\t",car_color);
	printf("\t\t\t%.2ld\t\t",price);
	printf("\n\n");
}


//function for generating bill footer
void generatebillfooter(long int total)
{
	printf("\n");
	float pay_price;
	float discount=0.1*total;
	float nettotal=total-discount;
	float gst=0.13*nettotal,grandtotal=nettotal+2*gst;
	/*printf("Sub Total\t\t\t%.2ld""%",total);
	printf("\nDiscount @10%s\t\t\t%.2f","%",discount);
	printf("\n\t\t\t\t---------");
	printf("\nNet Total\t\t\t%.2f",nettotal);
	//printf("\nGST @9%s\t\t\t\t%.2f","%",gst);
	printf("\nSGST @13%s\t\t\t%.2f","%",gst);
    printf("\n........................................");
    divider();
    printf("\nGrand Total\t\t\t%.2f",grandtotal);
    //printf("\n........................................\n");
    divider();
    */
    //printf("\n @13%s\t\t\t%.2f","%",gst);
    printf("\n\t\t\t\tDashain Offer (Discount)@10%s\t\t\t\t\t\t\t\t(%.2f)","%",discount);
   	printf("\n...........................................................................................................................................................\n");

    printf("\n\t\t\t\tNet Total\t\t\t\t\t\t\t\t\t\t%.2f",nettotal);
    divider();
    discount:
    printf("\n\n\n\t\t\t\t\t\t\t\t PLease pay the bill: ");
    scanf("%f",&pay_price);
    if(pay_price == nettotal)
    {
    	title();
    	printf("\n\n\n\t\t\t\t\t\t\t\tCongratulation");
    	printf("\n\n\n\t\t\t\t\t\t\t\tYou own this car.");
    	getch();
    	exit(0);
	}
    else
    {
    	printf("\n\t\t\t\t\t\t\t\tYou have not fullfill this bill.");
		goto discount;	
	}
}

void employee_option()
{
	printf("\n\n\n\t\t\t\t\t\t\t\t1. Obtainable Car");
	printf("\n\t\t\t\t\t\t\t\t2. Modify Version\n\n");
	
}

int menu()
{
	title();
    int c;
    printf("\n\n\n");
	printf("\t\t\t*************************************************MAIN MENU*************************************************");
    divider();
    printf("\t\t\t\t\t\t\t\t1.SIGNUP\n");
    printf("\t\t\t\t\t\t\t\t2.LOGIN\n");
    printf("\t\t\t\t\t\t\t\t3.FORGOT PASSOWRD OR USERNAME\n");
    /*
    printf("4.CHANGE PASSWORD\n");
    printf("5.DELETE ACCOUNT\n");*/
    printf("\t\t\t\t\t\t\t\t4.EXIT\n");
    divider();
    printf("\n\t\t\t\t\t\t\t\tEnter your choice : ");
    scanf("%d", &c);
    return c;
}

void takepassword(char pass[30])
{
    int i=0;
    char ch;
    while (1)
    {
        ch = getch();
        if (ch == 13)
        {
            pass[i] = '\0';
            break;
        }
        else if (ch == 8)
        {
            if (i > 0)
            {
                i--;
                printf("\b \b");
            }
        }
        else if (ch == 9 || ch == 32)
        {
            continue;
        }
        else
        {
            pass[i++] = ch;
            printf("*");
        }
    }
}

void bill_add(struct bill hero)
{
	FILE *ptr ;
	ptr=fopen("C:\\Project 1st Sem\\bill add.txt","r+");
	fwrite(&hero, sizeof(struct bill),1,ptr);
}

void signup()
{
	title();
    struct account u;
    char pass2[20];
    printf("\n\n\t\t\t\t\t\t\t\tCREATING NEW ACCOUNT \n");
    divider();
    printf("\n\t\t\t\t\t\t\t\tEnter your first name         : ");
    fflush(stdin);
    gets(u.first_name);
    printf("\n\t\t\t\t\t\t\t\tEnter last name               : ");
    fflush(stdin);
    gets(u.last_name);
    printf("\n\t\t\t\t\t\t\t\tEnter your username           : ");
    fflush(stdin);
    gets(u.username);
    printf("\n\t\t\t\t\t\t\t\tEnter your phone number       : ");
    fflush(stdin);
    gets(u.phone);
    printf("\n\t\t\t\t\t\t\t\tEnter Gender                  : ");
    fflush(stdin);
    gets(u.gender);
    printf("\n\t\t\t\t\t\t\t\tEnter your DOB                : ");
    fflush(stdin);
    gets(u.DOB);
    printf("\n\t\t\t\t\t\t\t\tEnter password                : ");
    fflush(stdin);
    takepassword(u.pass1);

conf_pass:
    printf("\n\n\t\t\t\t\t\t\t\tConfirm password              : ");
    takepassword(pass2);
    if (strcmp(u.pass1, pass2))
    {
        printf("\n\n\t\t\t\t\t\t\t\tINCORRECT PASSWORD \n\n");
        goto conf_pass;
    }
    else
    {
        printf("\n\n\t\t\t\t\t\t\t\tACCOUNT CREATED SUCCESSFULLY\n\n");
        getch();

        FILE *fp = fopen("account.txt", "w");
        fwrite(&u, sizeof(struct account), 1, fp);
        fclose(fp);
    }
    login();
}

void login()
{
        int i=0;
	// variable i chai username_passcode() wala match bhaye paxi aaba ko further peocess run hunxa
	
		i=username_passcode();
		if(i==1)
        {
            system("cls");
            title();
            printf("\n\n\n");
            printf("\t\t\t*************************************************WELCOME*************************************************");
    		divider();
    
			printf("\n\n\n\t\t\t\t\t\t\tYour username and passcode matched.");
			printf("\n\t\t\t\t\t\t\t\tHave a great day !");
			printf("\n\n\n\n\t\t\t\t\t\t\tPress any key....................");
			getch();
	
			flag:
			title();
			employee_option();
	
			int choice=0;				//choice for user to interact as
			printf("\n\n\t\t\t\t\t\t\tPress 1 as Customer and 2 as Employee \n\n\t\t\t\t\t\t\t\tYour are interacting as: ");
			scanf("%d",&choice);
	
			FILE *detail;				// made to open a file pointer which contain available car company
			char car_company[200], car_model[300];		// car_company made to show available car and car_brand for available car model
			char car_model_brand[500];			// To display the content of model or specification.
			FILE *brand;
			int company_choice=0;				// To look for car of provided company 
			int model_number=0;					// car company ko model ma kun select garne bhanera
				
			char r;  							// To display from file as character by character of Car Company model only
	
			char s;								// To display from file as character by character of car model of Company respectively
	
			char a;							// this a is used for customer as yes they want to buy this car.  this a is used for back to move as previous screen
	
			FILE *model;						// To represent the model of the given car company and open the file of respected model of car 
	
			long int car_price, customer_pay_price;
			char car_company_model[30];
			char car_model_color[20];
	
			switch(choice)
			{
				case 1:
				BMW:					
				{
					car_detail:
					title();
					detail=fopen("C:\\Project 1st Sem\\File handling\\Detail.txt","r");
				
					if(detail==NULL)
					{
						printf("\nFile doesn't exit.");
						exit(0);
					}
				 	printf("\n\n\n");
					while(fgets(car_company, sizeof(car_company),detail)){
						//puts(car_company);
						printf("%s", car_company);
					}
					
					printf("\n\n\n\n\t\t\t\t\t\tWhich company car you want to look or Go back to home page:  ");
					scanf("%d",&company_choice);
					switch(company_choice)
					{
						case 1:
						{
							title();
							brand=fopen("C:\\Project 1st Sem\\File handling\\BMW.txt","r");
							
							if(brand==NULL)
							{
								printf("\nFile doesn't exit.");
								exit(0);
							}
							
							printf("\n\n\n\t\t\t\t\t\t\t\tBMW Model\n\n");
							while (fgets(car_model, sizeof(car_model), brand)) {
   								 printf("%s", car_model);  // Print the content read from the file	
							}
							
							printf("\n\n\t\t\t\t\t\t\tProvide a number: ");
							scanf("%d",&model_number);
							
							switch(model_number)
							{
								case 1:
									{
										title();
										model=fopen("C:\\Project 1st Sem\\File handling\\BMW_model_X1.txt","r");
										//printf("\nTo be updated");
										while (fgets(car_model_brand, sizeof(car_model_brand), model)) {
   								 			printf("%s", car_model_brand);
   								 		}
   								 		
   								 		printf("\n\n\n\t\t\t\t\t Do you want to buy this model or you want to go back ?");
   								 		printf("\n\t\t\t\t\tEnter y to buy this model or else for previous screen :");
   								 		fflush(stdin);
   								 		scanf("%c",&a);
   								 		if(a=='y'||a=='Y')
   								 		{
   								 				strcpy(car_company_model,"BMW Model X1");
   								 				color_option:
   								 				printf("\n\t\t\t\t\t\t\tEnter a car color you want: ");
   								 				fflush(stdin);
   								 				gets(car_model_color);
   								 				strupr(car_model_color);
   								 				if(strcmp(car_model_color,"BLACK")==0 || strcmp(car_model_color,"WHITE")==0)
   								 				{
   								 					car_price=19000000;
													generatebill(car_company_model,customer_pay_price);
   								 					generatebillbody(car_company_model,car_model_color,car_price);
   								 					generatebillfooter(car_price);
   								 				}
   								 				else
   								 				{
   								 					printf("\n\t\t\t\t\t\tYou entered worng choice in color please. Try Again.");
													getch();
													goto color_option;	
												}
										}
										else{
											goto flag;
										}
									}
									break;
								case 2:
									{
										title();
										model=fopen("C:\\Project 1st Sem\\File handling\\BMW_model_X2.txt","r");
										while (fgets(car_model_brand, sizeof(car_model_brand), model)) {
   								 			printf("%s", car_model_brand);
   								 		}
   								 		
   								 		printf("\n\n\n\t\t\t\t\t Do you want to buy this model or you want to go back ?");
   								 		printf("\n\t\t\t\t\tEnter y to buy this model or else for previous previous screen :");
   								 		
   								 		fflush(stdin);
   								 		scanf("%c",&a);
   								 		if(a=='y'||a=='Y')
   								 		{
   								 				strcpy(car_company_model,"BMW Model X2");
   								 				Model_X2:
   								 				printf("\n\t\t\t\t\t\t\tEnter a car color you want: ");
   								 				fflush(stdin);
   								 				gets(car_model_color);
   								 				strupr(car_model_color);
   								 				if(strcmp(car_model_color,"BLUE")==0)
   								 				
   								 				{
   								 					car_price=21996000;
													generatebill(car_company_model,customer_pay_price);
   								 					generatebillbody(car_company_model,car_model_color,car_price);
   								 					generatebillfooter(car_price);
   								 				}
   								 				else
   								 				{
   								 					printf("\n\t\t\t\t\t\tYou entered worng choice in color please. Try Again.");
													getch();
													goto Model_X2;	
												}
										}
										else{
											goto flag;
										}
									}
									break;
								case 3:
									{
										title();
										model=fopen("C:\\Project 1st Sem\\File handling\\BMW_model_X3.txt","r");
										//printf("\nTo be updated");
										while (fgets(car_model_brand, sizeof(car_model_brand), model)) {
   								 			printf("%s", car_model_brand);
   								 			}
   								 		
   								 			printf("\n\n\n\t\t\t\t\t Do you want to buy this model or you want to go back ?");
   								 			printf("\n\t\t\t\t\tEnter y to buy this model or else for previous previous screen :");
   								 			fflush(stdin);
   								 			scanf("%c",&a);
   								 			if(a=='y'||a=='Y')
   								 			{
   								 				strcpy(car_company_model,"BMW Model X3");
   								 				Model_X3:
   								 				printf("\n\t\t\t\t\t\t\tEnter a car color you want: ");
   								 				fflush(stdin);
   								 				gets(car_model_color);
   								 				strupr(car_model_color);
   								 				if(strcmp(car_model_color,"WHITE")==0)
   								 				{
   								 					car_price=28000000;
   								 					//color_option:
													generatebill(car_company_model,customer_pay_price);
   								 					generatebillbody(car_company_model,car_model_color,car_price);
   								 					generatebillfooter(car_price);
   								 				}
   								 				else
   								 				{
   								 					printf("\n\t\t\t\t\t\t\tYou entered worng choice in color please. Try Again.");
													getch();
													goto Model_X3;	
												}
										}
										else{
											goto flag;
										}
									}
									break;
								case 4:
									{
										title();
										model=fopen("C:\\Project 1st Sem\\File handling\\BMW_model_X5.txt","r");
										//printf("\nTo be updated");
										while (fgets(car_model_brand, sizeof(car_model_brand), model)) {
   								 			printf("%s", car_model_brand);
   								 		}
   								 		printf("\n\n\n\t\t\t\t\t Do you want to buy this model or you want to go back ?");
   								 		printf("\n\t\t\t\t\tEnter y to buy this model or else for previous previous screen :");
   								 		
   								 		fflush(stdin);
   								 		scanf("%c",&a);
   								 		if(a=='y'||a=='Y')
   								 		{
   								 				strcpy(car_company_model,"BMW Model X5");
   								 				Model_X5:
   								 				printf("\n\t\t\t\t\t\t\tEnter a car color you want: ");
   								 				fflush(stdin);
   								 				gets(car_model_color);
   								 				strupr(car_model_color);
   								 				if(strcmp(car_model_color,"BLUE")==0)
   								 				{
   								 					car_price=34996000;
   								 					//color_option:
													generatebill(car_company_model,customer_pay_price);
   								 					generatebillbody(car_company_model,car_model_color,car_price);
   								 					generatebillfooter(car_price);
   								 				}
   								 				else
   								 				{
   								 					printf("\n\t\t\t\t\t\tYou entered worng choice in color please. Try Again.");
													getch();
													goto Model_X5;	
												}
										}
   								 		else{
											goto flag;
										}
									}
									break;
								case 5:
									{
										title();
										model=fopen("C:\\Project 1st Sem\\File handling\\BMW_model_X7.txt","r");
										//printf("\nTo be updated");
										while (fgets(car_model_brand, sizeof(car_model_brand), model)) {
   								 			printf("%s", car_model_brand);
   								 		}
   								 		
   								 		printf("\n\n\n\t\t\t\t\t Do you want to buy this model or you want to go back ?");
   								 		printf("\n\t\t\t\t\tEnter y to buy this model or else for previous previous screen :");
   								 		
   								 		fflush(stdin);
   								 		scanf("%c",&a);
   								 		if(a=='y'||a=='Y')
   								 		{
   								 				strcpy(car_company_model,"BMW Model X7");
   								 				Model_X7:
   								 				printf("\n\t\t\t\t\t\t\tEnter a car color you want: ");
   								 				fflush(stdin);
   								 				gets(car_model_color);
   								 				strupr(car_model_color);
   								 				if(strcmp(car_model_color,"BLUE")==0 || strcmp(car_model_color,"WHITE")==0)
   								 				{
   								 					car_price=34996000;
   								 				//	color_option:
													generatebill(car_company_model,customer_pay_price);
   								 					generatebillbody(car_company_model,car_model_color,car_price);
   								 					generatebillfooter(car_price);
   								 				}
   								 				else
   								 				{
   								 					printf("\n\t\t\t\t\t\tYou entered worng choice in color please. Try Again.");
													getch();
													goto Model_X7;	
												}
										}
   								 		else{
											goto flag;
										}
									}
									break;
								case 6:
									{
										goto car_detail;
									}
									break;
								case 7:
									{
										goto flag;
									}
									break;
								default:
									{
										printf("\n\t\t\t\t\t\t\tInvalid Services. Please try again. Press any key.................");
										getch();
										goto BMW;
									}
									
							}
							
						}
						break;
						
						
						case 2:
						{
							Tesla:
							title();
							brand=fopen("C:\\Project 1st Sem\\File handling\\Tesla.txt","r");
							
							if(brand==NULL)
							{
								printf("\n\t\t\t\t\t\t\tFile doesn't exit.");
								exit(0);
							}
							
							printf("\n\n\t\t\t\t\t\t\t\tTesla Model\n\n");
								while (fgets(car_model, sizeof(car_model), brand)) {
   								 printf("%s", car_model);  // Print the content read from the file	
							}
							
							printf("\n\n\t\t\t\t\t\t\t Provide a number: ");
							scanf("%d",&model_number);
							
							switch(model_number)
							{
								case 1:
									{
										title();
										model=fopen("C:\\Project 1st Sem\\File handling\\TESLA_model_3.txt","r");
										while (fgets(car_model_brand, sizeof(car_model_brand), model)) {
   								 			printf("%s", car_model_brand);
   								 		}
   								 		
   								 		printf("\n\n\n\t\t\t\t\t Do you want to buy this model or you want to go back ?");
   								 		printf("\n\t\t\t\t\tEnter y to buy this model or else for previous previous screen :");
   								 		
   								 		fflush(stdin);
   								 		scanf("%c",&a);
   								 		if(a=='y'||a=='Y')
   								 		{
   								 				strcpy(car_company_model,"Tesla Model 3");
   								 				//color_option:
   								 				Model_3:
   								 				printf("\n\t\t\t\t\t\t\tEnter a car color you want: ");
   								 				fflush(stdin);
   								 				gets(car_model_color);
   								 				strupr(car_model_color);
   								 				if(strcmp(car_model_color,"WHITE")==0)
   								 				{
   								 					car_price=16700000;
   								 					//color_option:
													generatebill(car_company_model,customer_pay_price);
   								 					generatebillbody(car_company_model,car_model_color,car_price);
   								 					generatebillfooter(car_price);
   								 				}
   								 				else
   								 				{
   								 					printf("\n\t\t\t\t\t\tYou entered worng choice in color please. Try Again.");
													getch();
													goto Model_3;	
												}
										}
   								 		else{
											goto flag;
										}
									}
									break;
								case 2:
									{
										title();
										model=fopen("C:\\Project 1st Sem\\File handling\\TESLA_model_X.txt","r");
										while (fgets(car_model_brand, sizeof(car_model_brand), model)) {
   								 			printf("%s", car_model_brand);
   								 		}
   								 		
   								 		printf("\n\n\n\t\t\t\t\t Do you want to buy this model or you want to go back ?");
   								 		printf("\n\t\t\t\t\tEnter y to buy this model or else for previous previous screen :");
   								 		
   								 		fflush(stdin);
   								 		scanf("%c",&a);
   								 		if(a=='y'||a=='Y')
   								 		{
   								 				strcpy(car_company_model,"TESLA Model X");
   								 				Model_X:
   								 				printf("\n\t\t\t\t\t\t\tEnter a car color you want: ");
   								 				fflush(stdin);
   								 				gets(car_model_color);
   								 				strupr(car_model_color);
   								 				if(strcmp(car_model_color,"RED")==0 || strcmp(car_model_color,"WHITE")==0)
   								 				{
   								 					car_price=28500000;
   								 					//color_option:
													generatebill(car_company_model,customer_pay_price);
   								 					generatebillbody(car_company_model,car_model_color,car_price);
   								 					generatebillfooter(car_price);
   								 				}
   								 				else
   								 				{
   								 					printf("\n\t\t\t\t\t\tYou entered worng choice in color please. Try Again.");
													getch();
													goto Model_X;	
												}
										}
   								 		else{
											goto flag;
										}
									}
									break;
								case 3:
									{
										title();
										model=fopen("C:\\Project 1st Sem\\File handling\\TESLA_model_Y.txt","r");
										while (fgets(car_model_brand, sizeof(car_model_brand), model)) {
   								 			printf("%s", car_model_brand);
   								 		}
   								 		
   								 		printf("\n\n\n\t\t\t\t\t Do you want to buy this model or you want to go back ?");
   								 		printf("\n\t\t\t\t\tEnter y to buy this model or else for previous previous screen :");
   								 		
   								 		fflush(stdin);
   								 		scanf("%c",&a);
   								 		if(a=='y'||a=='Y')
   								 		{
   								 				strcpy(car_company_model,"TESLA Model Y");
   								 				Model_Y:
   								 				printf("\n\t\t\t\t\t\t\tEnter a car color you want: ");
   								 				fflush(stdin);
   								 				gets(car_model_color);
   								 				strupr(car_model_color);
   								 				if(strcmp(car_model_color,"BLUE")==0 || strcmp(car_model_color,"RED")==0)
   								 				{
   								 					car_price=29000000;
   								 					//color_option:
													generatebill(car_company_model,customer_pay_price);
   								 					generatebillbody(car_company_model,car_model_color,car_price);
   								 					generatebillfooter(car_price);
   								 				}
   								 				else
   								 				{
   								 					printf("\n\t\t\t\t\t\tYou entered worng choice in color please. Try Again.");
													getch();
													goto Model_Y;	
												}
										}
										else{
											goto flag;
										}
   								 		
									}
									break;
								case 4:
									{
										goto car_detail;
									}
									break;
								case 5:
									{
										goto flag;
									}
									break;
								default:
									{
										printf("\n\t\t\t\t\t\t\tInvalid Services. Please try again. Press any key.................");
										getch();
										goto Tesla;
									}
									
							}
							
						}
						break;
					
						
						case 3:
						{
							Toyata:
							title();
							brand=fopen("C:\\Project 1st Sem\\File handling\\Toyota.txt","r");
							
							if(brand==NULL)
							{
								printf("\n\t\t\t\t\t\t\tFile doesn't exit.");
								exit(0);
							}
							printf("\n\n\t\t\t\t\t\t\t\tToyata Model\n");
							
							while (fgets(car_model, sizeof(car_model), brand)) {
   								 printf("%s", car_model);  // Print the content read from the file	
							}
							
							printf("\n\n\t\t\t\t\t\t\t Provide a number: ");
							scanf("%d",&model_number);
							
							switch(model_number)
							{
								case 1:
									{
										title();
										model=fopen("C:\\Project 1st Sem\\File handling\\TOYOTA_model_Raize.txt","r");
										while (fgets(car_model_brand, sizeof(car_model_brand), model)) {
   								 			printf("%s", car_model_brand);
   								 		}
   								 		
   								 		printf("\n\n\n\t\t\t\t\t Do you want to buy this model or you want to go back ?");
   								 		printf("\n\t\t\t\t\tEnter y to buy this model or else for previous previous screen :");
   								 		
   								 		fflush(stdin);
   								 		scanf("%c",&a);
   								 		if(a=='y'||a=='Y')
   								 		{
   								 				strcpy(car_company_model,"TOYOTA Model RAIZE");
   								 				Model_Raize:
   								 				printf("\n\t\t\t\t\t\t\tEnter a car color you want: ");
   								 				fflush(stdin);
   								 				gets(car_model_color);
   								 				strupr(car_model_color);
   								 				if(strcmp(car_model_color,"BLACK")==0 || strcmp(car_model_color,"WHITE")==0)
   								 				{
   								 					car_price=7500000;
   								 					//color_option:
													generatebill(car_company_model,customer_pay_price);
   								 					generatebillbody(car_company_model,car_model_color,car_price);
   								 					generatebillfooter(car_price);
   								 				}
   								 				else
   								 				{
   								 					printf("\n\t\t\t\t\t\tYou entered worng choice in color please. Try Again.");
													getch();
													goto Model_Raize;	
												}
										}
   								 		else{
											goto flag;
										}
									}
									break;
								case 2:
									{
										title();
										model=fopen("C:\\Project 1st Sem\\File handling\\TOYOTA_model_Rush.txt","r");
										while (fgets(car_model_brand, sizeof(car_model_brand), model)) {
   								 			printf("%s", car_model_brand);
   								 		}
   								 		
   								 		printf("\n\n\n\t\t\t\t\t Do you want to buy this model or you want to go back ?");
   								 		printf("\n\t\t\t\t\tEnter y to buy this model or else for previous previous screen :");
   								 		
   								 		fflush(stdin);
   								 		scanf("%c",&a);
   								 		if(a=='y'||a=='Y')
   								 		{
   								 				strcpy(car_company_model,"TOYOTA Model RUSH");
   								 				Model_Rush:
   								 				printf("\n\t\t\t\t\t\t\tEnter a car color you want: ");
   								 				fflush(stdin);
   								 				gets(car_model_color);
   								 				strupr(car_model_color);
   								 				if(strcmp(car_model_color,"METALLIC SILVER")==0 || strcmp(car_model_color,"WHITE")==0)
   								 				{
   								 					car_price=9200000;
   								 				//	color_option:
													generatebill(car_company_model,customer_pay_price);
   								 					generatebillbody(car_company_model,car_model_color,car_price);
   								 					generatebillfooter(car_price);
   								 				}
   								 				else
   								 				{
   								 					printf("\n\t\t\t\t\t\tYou entered worng choice in color please. Try Again.");
													getch();
													goto Model_Rush;	
												}
										}
   								 		else{
											goto flag;
										}
									}
									break;
								case 3:
									{
										title();
										model=fopen("C:\\Project 1st Sem\\File handling\\TOYOTA_model_Corolla_Cross.txt","r");
										while (fgets(car_model_brand, sizeof(car_model_brand), model)) {
   								 			printf("%s", car_model_brand);
   								 		}
   								 		
   								 		printf("\n\n\n\t\t\t\t\t Do you want to buy this model or you want to go back ?");
   								 		printf("\n\t\t\t\t\tEnter y to buy this model or else for previous previous screen :");
   								 		
   								 		fflush(stdin);
   								 		scanf("%c",&a);
   								 		if(a=='y'||a=='Y')
   								 		{
   								 				strcpy(car_company_model,"TOYOTA Model COROLLA CROSS");
   								 				Model_Cross:
   								 				printf("\n\t\t\t\t\t\t\tEnter a car color you want: ");
   								 				fflush(stdin);
   								 				gets(car_model_color);
   								 				strupr(car_model_color);
   								 				if(strcmp(car_model_color,"WHITE")==0)
   								 				{
   								 					car_price=13800000;
   								 				//	color_option:
													generatebill(car_company_model,customer_pay_price);
   								 					generatebillbody(car_company_model,car_model_color,car_price);
   								 					generatebillfooter(car_price);
   								 				}
   								 				else
   								 				{
   								 					printf("\n\t\t\t\t\t\tYou entered worng choice in color please. Try Again.");
													getch();
													goto Model_Cross;	
												}
										}
   								 		else{
											goto flag;
										}
									}
									break;
								
								case 4:
									{
										goto car_detail;
									}
									break;
								case 5:
									{
										goto flag;
									}
									break;
								default:
									{
										printf("\n\t\t\t\t\t\t\tInvalid Services. Please try again. Press any key.................");
										getch();
										goto Toyata;
									}
									
							}
							
						}
						break;
					
					
						
						case 4:
						{
							Audi:
							title();
							brand=fopen("C:\\Project 1st Sem\\File handling\\Audi.txt","r");
							
							if(brand==NULL)
							{
								printf("\n\t\t\t\t\t\t\tFile doesn't exit.");
								exit(0);
							}
							printf("\n\n\n\t\t\t\t\t\t\t\tAudi Model\n");
							
							while (fgets(car_model, sizeof(car_model), brand)) {
   								 printf("%s", car_model);  // Print the content read from the file	
							}
							
							
							printf("\n\n\t\t\t\t\t\t\t Provide a number: ");
							scanf("%d",&model_number);
							
							switch(model_number)
							{
								case 1:
									{
										title();
										model=fopen("C:\\Project 1st Sem\\File handling\\AUDI_model_A4.txt","r");
										while (fgets(car_model_brand, sizeof(car_model_brand), model)) {
   								 			printf("%s", car_model_brand);
   								 		}
   								 		
   								 		printf("\n\n\n\t\t\t\t\t Do you want to buy this model or you want to go back ?");
   								 		printf("\n\t\t\t\t\tEnter y to buy this model or else for previous previous screen :");
   								 		
   								 		fflush(stdin);
   								 		scanf("%c",&a);
   								 		if(a=='y'||a=='Y')
   								 		{
   								 				strcpy(car_company_model,"AUDi Model A4");
   								 				Model_A4:
   								 				printf("\n\t\t\t\t\t\t\tEnter a car color you want: ");
   								 				fflush(stdin);
   								 				gets(car_model_color);
   								 				strupr(car_model_color);
   								 				if(strcmp(car_model_color,"WHITE")==0)
   								 				{
   								 					car_price=6213000;
   								 					//color_option:
													generatebill(car_company_model,customer_pay_price);
   								 					generatebillbody(car_company_model,car_model_color,car_price);
   								 					generatebillfooter(car_price);
   								 				}
   								 				else
   								 				{
   								 					printf("\n\t\t\t\t\t\t\tYou entered worng choice in color please. Try Again.");
													getch();
													goto Model_A4;	
												}
										}
   								 		else{
											goto flag;
										}
									}
									break;
								case 2:
									{
										title();
										model=fopen("C:\\Project 1st Sem\\File handling\\AUDI_model_A6.txt","r");
										while (fgets(car_model_brand, sizeof(car_model_brand), model)) {
   								 			printf("%s", car_model_brand);
   								 		}
   								 		
   								 		printf("\n\n\n\t\t\t\t\t Do you want to buy this model or you want to go back ?");
   								 		printf("\n\t\t\t\t\tEnter y to buy this model or else for previous previous screen :");
   								 		
   								 		fflush(stdin);
   								 		scanf("%c",&a);
   								 		if(a=='y'||a=='Y')
   								 		{
   								 				strcpy(car_company_model,"AUDI Model A6");
   								 				Model_A6:
   								 				printf("\n\t\t\t\t\t\t\tEnter a car color you want: ");
   								 				fflush(stdin);
   								 				gets(car_model_color);
   								 				strupr(car_model_color);
   								 				if(strcmp(car_model_color,"BLACK")==0)
   								 				{
   								 					car_price=7296000;
   								 					//color_option:
													generatebill(car_company_model,customer_pay_price);
   								 					generatebillbody(car_company_model,car_model_color,car_price);
   								 					generatebillfooter(car_price);
   								 				}
   								 				else
   								 				{
   								 					printf("\n\t\t\t\t\t\t\tYou entered worng choice in color please. Try Again.");
													getch();
													goto Model_A6;	
												}
										}
   								 		else{
											goto flag;
										}
									}
									break;
								case 3:
									{
										title();
										model=fopen("C:\\Project 1st Sem\\File handling\\AUDI_model_Q5.txt","r");
										while (fgets(car_model_brand, sizeof(car_model_brand), model)) {
   								 			printf("%s", car_model_brand);
   								 		}
   								 		
   								 		printf("\n\n\n\t\t\t\t\t Do you want to buy this model or you want to go back ?");
   								 		printf("\n\t\t\t\t\tEnter y to buy this model or else for previous previous screen :");
   								 		
   								 		fflush(stdin);
   								 		scanf("%c",&a);
   								 		if(a=='y'||a=='Y')
   								 		{
   								 				strcpy(car_company_model,"AUDI Model Q5");
   								 				Model_Q5:
   								 				printf("\n\t\t\t\t\t\t\tEnter a car color you want: ");
   								 				fflush(stdin);
   								 				gets(car_model_color);
   								 				strupr(car_model_color);
   								 				if(strcmp(car_model_color,"BLUE")==0)
   								 				{
   								 					car_price=7125000;
   								 					//color_option:
													generatebill(car_company_model,customer_pay_price);
   								 					generatebillbody(car_company_model,car_model_color,car_price);
   								 					generatebillfooter(car_price);
   								 				}
   								 				else
   								 				{
   								 					printf("\n\t\t\t\t\t\t\tYou entered worng choice in color please. Try Again.");
													getch();
													goto Model_Q5;	
												}
										}
   								 		else{
											goto flag;
										}
									}
									break;
								case 4:
									{
										title();
										model=fopen("C:\\Project 1st Sem\\File handling\\AUDI_model_Q7.txt","r");
										while (fgets(car_model_brand, sizeof(car_model_brand), model)) {
   								 			printf("%s", car_model_brand);
   								 		}
   								 		printf("\n\n\n\t\t\t\t\t Do you want to buy this model or you want to go back ?");
   								 		printf("\n\t\t\t\t\tEnter y to buy this model or else for previous previous screen :");
   								 		
   								 		fflush(stdin);
   								 		scanf("%c",&a);
   								 		if(a=='y'||a=='Y')
   								 		{
   								 				strcpy(car_company_model,"AUDI Model Q7");
   								 				Model_Q7:
   								 				printf("\n\t\t\t\t\t\t\tEnter a car color you want: ");
   								 				fflush(stdin);
   								 				gets(car_model_color);
   								 				strupr(car_model_color);
   								 				if(strcmp(car_model_color,"WHITE")==0)
   								 				{
   								 					car_price=5151000;
   								 				//	color_option:
													generatebill(car_company_model,customer_pay_price);
   								 					generatebillbody(car_company_model,car_model_color,car_price);
   								 					generatebillfooter(car_price);
   								 				}
   								 				else
   								 				{
   								 					printf("\n\t\t\t\t\t\t\tYou entered worng choice in color please. Try Again.");
													getch();
													goto Model_Q7;	
												}
										}
   								 		else{
											goto flag;
										}
									}
									break;
								case 5:
									{
										goto car_detail;
									}
									break;
								case 6:
									{
										goto flag;
									}
									break;
								default:
									{
										printf("\n\t\t\t\t\t\t\tInvalid Services. Please try again. Press any key.................");
										getch();
										goto Audi;
									}
									
							}
							
						}
						break;
						
					
						case 5:
						{
							Nissan:
							title();
							brand=fopen("C:\\Project 1st Sem\\File handling\\Nissan.txt","r");
							
							if(brand==NULL)
							{
								printf("\n\t\t\t\t\t\t\tFile doesn't exit.");
								exit(0);
							}
							
							printf("\n\n\n\t\t\t\t\t\t\t\tNissan Model\n");
							
							while (fgets(car_model, sizeof(car_model), brand)) {
   								 printf("%s", car_model);  // Print the content read from the file	
							}
							
							printf("\n\n\t\t\t\t\t\t\tProvide a number: ");
							scanf("%d",&model_number);
							
							switch(model_number)
							{
								case 1:
									{
										title();
										model=fopen("C:\\Project 1st Sem\\File handling\\NISSAN_model_MAGNITE.txt","r");
										while (fgets(car_model_brand, sizeof(car_model_brand), model)) {
   								 			printf("%s", car_model_brand);
   								 		}
   								 		
   								 		printf("\n\n\n\t\t\t\t\t Do you want to buy this model or you want to go back ?");
   								 		printf("\n\t\t\t\t\tEnter y to buy this model or else for previous previous screen :");
   								 		
   								 		fflush(stdin);
   								 		scanf("%c",&a);
   								 		
   								 		
										if(a=='y'||a=='Y')
   								 		{
   								 				int i=0;
   								 				strcpy(car_company_model,"NISSAN Model MAGNITE");
   								 				printf("\n\t\t\t\t\t\t\tWhich Variant you want to buy?");
   								 				printf("\n\t\t\t\t\t\t\tPress 1 as Variant Mono Turb and 2 as Variant Dual Turbo.");
   		
   								 				printf("\nVariant: ");
   								 				scanf("%d",&i);
   								 				if(i==1){
												
   								 					Model_Magnite:
   								 					printf("\n\t\t\t\t\t\t\tEnter a car color you want: ");
   								 					fflush(stdin);
   								 					gets(car_model_color);
   								 					strupr(car_model_color);
   								 					if(strcmp(car_model_color,"BLACK")==0)
   								 					{
   								 						car_price=4599000;
   								 				//	color_option:
														generatebill(car_company_model,customer_pay_price);
   								 						generatebillbody(car_company_model,car_model_color,car_price);
   								 						generatebillfooter(car_price);
   								 					}
   								 					else
   								 					{
   								 						printf("\n\t\t\t\t\t\t\tYou entered worng choice in color please. Try Again.");
														getch();
														goto Model_Magnite;	
													}
												}
												else if(i==2)
												{
														Model_Magnite1:
   								 					printf("\n\t\t\t\t\t\t\tEnter a car color you want: ");
   								 					fflush(stdin);
   								 					gets(car_model_color);
   								 					strupr(car_model_color);
   								 					if(strcmp(car_model_color,"BLACK")==0)
   								 					{
   								 						car_price=4634000;
   								 				//	color_option:
														generatebill(car_company_model,customer_pay_price);
   								 						generatebillbody(car_company_model,car_model_color,car_price);
   								 						generatebillfooter(car_price);
   								 					}
   								 					else
   								 					{
   								 						printf("\n\t\t\t\t\t\t\tYou entered worng choice in color please. Try Again.");
														getch();
														goto Model_Magnite1;	
													}
												}
										}
   								 		else{
											goto flag;
										}
									}
									break;
								case 2:
									{
										
										title();
										model=fopen("C:\\Project 1st Sem\\File handling\\NISSAN_model_KICKS.txt","r");
										while (fgets(car_model_brand, sizeof(car_model_brand), model)) {
   								 			printf("%s", car_model_brand);
   								 		}
   								 		
   								 		printf("\n\n\n\t\t\t\t\t Do you want to buy this model or you want to go back ?");
   								 		printf("\n\t\t\t\t\tEnter y to buy this model or else for previous previous screen :");
   								 		
   								 		fflush(stdin);
   								 		scanf("%c",&a);
   								 		if(a=='y'||a=='Y')
   								 		{
   								 				strcpy(car_company_model,"NISSAN Model KICKS");
   								 				Model_Kicks:
   								 				printf("\n\t\t\t\t\t\t\tWhich Variant you want to buy?");
   								 				printf("\n\t\t\t\t\t\t\tPress 1 as Variant XL and 2 as Variant XV.");
   		
   								 				printf("\n\t\t\t\t\t\t\tVariant: ");
   								 				scanf("%d",&i);
   								 				if(i==1)
												{
   								 					kick:
   								 					printf("\n\t\t\t\t\t\t\tEnter a car color you want: ");
   								 					fflush(stdin);
   								 					gets(car_model_color);
   								 					strupr(car_model_color);
   								 					if(strcmp(car_model_color,"WHITE")==0)
   								 					{
   								 						car_price=4899000;
   								 				//	color_option:
														generatebill(car_company_model,customer_pay_price);
   								 						generatebillbody(car_company_model,car_model_color,car_price);
   								 						generatebillfooter(car_price);
   								 					}
   								 					else
   								 					{
   								 						printf("\n\t\t\t\t\t\t\tYou entered worng choice in color please. Try Again.");
														getch();
														goto kick;	
													}
												}
												else if(i==2)
												{
													Model_Kicks_1:
   								 					printf("\n\t\t\t\t\t\t\tEnter a car color you want: ");
   								 					fflush(stdin);
   								 					gets(car_model_color);
   								 					strupr(car_model_color);
   								 					if(strcmp(car_model_color,"WHITE")==0)
   								 					{
   								 						car_price=5349000;
   								 				//	color_option:
														generatebill(car_company_model,customer_pay_price);
   								 						generatebillbody(car_company_model,car_model_color,car_price);
   								 						generatebillfooter(car_price);
   								 					}
   								 					else
   								 					{
   								 						printf("\n\t\t\t\t\t\t\tYou entered worng choice in color please. Try Again.");
														getch();
														goto Model_Kicks_1;	
													}
												}
										}
   								 		else{
											goto flag;
										}
									}
									break;
								case 3:
									{
										title();
										model=fopen("C:\\Project 1st Sem\\File handling\\NISSAN_model_LEAF.txt","r");
										while (fgets(car_model_brand, sizeof(car_model_brand), model)) {
   								 			printf("%s", car_model_brand);
   								 		}
   								 		
   								 		printf("\n\n\n\t\t\t\t\t Do you want to buy this model or you want to go back ?");
   								 		printf("\n\t\t\t\t\tEnter y to buy this model or else for previous previous screen :");
   								 		
   								 		fflush(stdin);
   								 		scanf("%c",&a);
   								 		if(a=='y'||a=='Y')
   								 		{
   								 				strcpy(car_company_model,"NISSAN Model LEAF");
   								 				Model_Leaf:
   								 				printf("\n\t\t\t\t\t\t\tEnter a car color you want: ");
   								 				fflush(stdin);
   								 				gets(car_model_color);
   								 				strupr(car_model_color);
   								 				if(strcmp(car_model_color,"BLACK")==0)
   								 				{
   								 					car_price=6500000;
   								 					//color_option:
													generatebill(car_company_model,customer_pay_price);
   								 					generatebillbody(car_company_model,car_model_color,car_price);
   								 					generatebillfooter(car_price);
   								 				}
   								 				else
   								 				{
   								 					printf("\n\t\t\t\t\t\t\tYou entered worng choice in color please. Try Again.");
													getch();
													goto Model_Leaf;	
												}
										}
   								 		else{
											goto flag;
										}
									}
									break;
								
								case 4:
									{
										goto car_detail;
									}
									break;
								case 5:
									{
										goto flag;
									}
									break;
								default:
									{
										printf("\n\t\t\t\t\t\t\tInvalid Services. Please try again. Press any key.................");
										getch();
										goto Nissan;
									}
									
							}
							
						}
						break;
						
						
						case 6:
						{
							Mahindra:
							title();
							brand=fopen("C:\\Project 1st Sem\\File handling\\Mahindra.txt","r");
							
							if(brand==NULL)
							{
								printf("\n\t\t\t\t\t\t\tFile doesn't exit.");
								exit(0);
							}
							printf("\n\n\n\t\t\t\t\t\t\t\tMahindra Model\n");
							
							while (fgets(car_model, sizeof(car_model), brand)) {
   								 printf("%s", car_model);  // Print the content read from the file	
							}
							
							printf("\n\n\t\t\t\t\t\t\t Provide a number: ");
							scanf("%d",&model_number);
							
							switch(model_number)
							{
								case 1:
									{
										title();
										model=fopen("C:\\Project 1st Sem\\File handling\\MAHINDRA_model_XUV.txt","r");
										while (fgets(car_model_brand, sizeof(car_model_brand), model)) {
   								 			printf("%s", car_model_brand);
   								 		}
   								 		
   								 		printf("\n\n\n\t\t\t\t\t Do you want to buy this model or you want to go back ?");
   								 		printf("\n\t\t\t\t\tEnter y to buy this model or else for previous previous screen :");
   								 		
   								 		fflush(stdin);
   								 		scanf("%c",&a);
   								 		if(a=='y'||a=='Y')
   								 		{
   								 				strcpy(car_company_model,"MAHINDRA Model XUV");
   								 				Model_XUV:
   								 				printf("\n\t\t\t\t\t\t\tWhich Variant you want to buy?");
   								 				printf("\n\t\t\t\t\t\t\tPress 1 as Variant FWD W7 and 2 as Variant AWD W11.");
   		
   								 				printf("\n\t\t\t\t\t\t\tVariant: ");
   								 				scanf("%d",&i);
   								 				if(i==1){
												
   								 					XUV:
   								 					printf("\n\t\t\t\t\t\t\tEnter a car color you want: ");
   								 					fflush(stdin);
   								 					gets(car_model_color);
   								 					strupr(car_model_color);
   								 					if(strcmp(car_model_color,"WHITE")==0)
   								 					{
   								 						car_price=6865000;
   								 				//	color_option:
														generatebill(car_company_model,customer_pay_price);
   								 						generatebillbody(car_company_model,car_model_color,car_price);
   								 						generatebillfooter(car_price);
   								 					}
   								 					else
   								 					{
   								 						printf("\n\t\t\t\t\t\t\tYou entered worng choice in color please. Try Again.");
														getch();
														goto XUV;	
													}
												}
												else if(i==2)
												{
													Model_XUV_1:
   								 					printf("\n\t\t\t\t\t\t\tEnter a car color you want: ");
   								 					fflush(stdin);
   								 					gets(car_model_color);
   								 					strupr(car_model_color);
   								 					if(strcmp(car_model_color,"WHITE")==0 || strcmp(car_model_color,"BLACK")==0 )
   								 					{
   								 						car_price=8600000;
   								 				//	color_option:
														generatebill(car_company_model,customer_pay_price);
   								 						generatebillbody(car_company_model,car_model_color,car_price);
   								 						generatebillfooter(car_price);
   								 					}
   								 					else
   								 					{
   								 						printf("\n\t\t\t\t\t\t\tYou entered worng choice in color please. Try Again.");
														getch();
														goto Model_XUV_1;	
													}
												}
										}
   								 		else{
											goto flag;
										}
										
									}
									break;
								case 2:
									{
										title();
										model=fopen("C:\\Project 1st Sem\\File handling\\MAHINDRA_model_MARAZZO.txt","r");
										while (fgets(car_model_brand, sizeof(car_model_brand), model)) {
   								 			printf("%s", car_model_brand);
   								 		}
										
   								 		printf("\n\n\n\t\t\t\t\t Do you want to buy this model or you want to go back ?");
   								 		printf("\n\t\t\t\t\tEnter y to buy this model or else for previous previous screen :");
   								 		
   								 		fflush(stdin);
   								 		scanf("%c",&a);
   								 		if(a=='y'||a=='Y')
   								 		{
   								 				strcpy(car_company_model,"MAHINDRA Model MARAZZO");
   								 				Model_Marazzo:
   								 				printf("\n\t\t\t\t\t\t\tEnter a car color you want: ");
   								 				fflush(stdin);
   								 				gets(car_model_color);
   								 				strupr(car_model_color);
   								 				if(strcmp(car_model_color,"WHITE")==0 || strcmp(car_model_color,"BLACK")==0 )
   								 				{
   								 					car_price=5820000;
   								 					//color_option:
													generatebill(car_company_model,customer_pay_price);
   								 					generatebillbody(car_company_model,car_model_color,car_price);
   								 					generatebillfooter(car_price);
   								 				}
   								 				else
   								 				{
   								 					printf("\n\t\t\t\t\t\t\tYou entered worng choice in color please. Try Again.");
													getch();
													goto Model_Marazzo;	
												}
										}
   								 		else{
											goto flag;
										}
									}
									break;
								case 3:
									{
										title();
										model=fopen("C:\\Project 1st Sem\\File handling\\MAHINDRA_model_ALTURAS.txt","r");
										while (fgets(car_model_brand, sizeof(car_model_brand), model)) {
   								 			printf("%s", car_model_brand);
   								 		}
										
   								 		printf("\n\n\n\t\t\t\t\t Do you want to buy this model or you want to go back ?");
   								 		printf("\n\t\t\t\t\tEnter y to buy this model or else for previous previous screen :");
   								 		
   								 		fflush(stdin);
   								 		scanf("%c",&a);
   								 		if(a=='y'||a=='Y')
   								 		{
   								 				strcpy(car_company_model,"MAHINDRA Model ALTURAS G4");
   								 				Model_Alturas:
   								 				printf("\n\t\t\t\t\t\t\tEnter a car color you want: ");
   								 				fflush(stdin);
   								 				gets(car_model_color);
   								 				strupr(car_model_color);
   								 				if(strcmp(car_model_color,"RED")==0)
   								 				{
   								 					car_price=4609935;
   								 					//color_option:
													generatebill(car_company_model,customer_pay_price);
   								 					generatebillbody(car_company_model,car_model_color,car_price);
   								 					generatebillfooter(car_price);
   								 				}
   								 				else
   								 				{
   								 					printf("\nYou entered worng choice in color please. Try Again.");
													getch();
													goto Model_Alturas;	
												}
										}
   								 		else{
											goto flag;
										}
									}
									break;
								case 4:
									{
										title();
										model=fopen("C:\\Project 1st Sem\\File handling\\MAHINDRA_model_SCORPIO.txt","r");
										while (fgets(car_model_brand, sizeof(car_model_brand), model)) {
   								 			printf("%s", car_model_brand);
   								 		}
										
   								 		printf("\n\n\n\t\t\t\t\t Do you want to buy this model or you want to go back ?");
   								 		printf("\n\t\t\t\t\tEnter y to buy this model or else for previous previous screen :");
   								 		
   								 		fflush(stdin);
   								 		scanf("%c",&a);
   								 		if(a=='y'||a=='Y')
   								 		{
   								 				strcpy(car_company_model,"MAHINDRA Model SCORPIO");
   								 				Model_Scorpio:
   								 				printf("\nWhich Variant you want to buy?");
   								 				printf("\nPress 1 as Variant S52WD and 2 as Variant S54WD.");
   		
   								 				printf("\nVariant: ");
   								 				scanf("%d",&i);
   								 				if(i==1){
												
   								 					Model_SCORPIO:
   								 					printf("\nEnter a car color you want: ");
   								 					fflush(stdin);
   								 					gets(car_model_color);
   								 					strupr(car_model_color);
   								 					if(strcmp(car_model_color,"WHITE")==0)
   								 					{
   								 						car_price=5550000;
   								 				//	color_option:
														generatebill(car_company_model,customer_pay_price);
   								 						generatebillbody(car_company_model,car_model_color,car_price);
   								 						generatebillfooter(car_price);
   								 					}
   								 					else
   								 					{
   								 						printf("\nYou entered worng choice in color please. Try Again.");
														getch();
														goto Model_SCORPIO;	
													}
												}
												else if(i==2)
												{
														Model_SCORPIO1:
   								 					printf("\nEnter a car color you want: ");
   								 					fflush(stdin);
   								 					gets(car_model_color);
   								 					strupr(car_model_color);
   								 					if(strcmp(car_model_color,"BLACK")==0)
   								 					{
   								 						car_price=5990000;
   								 				//	color_option:
														generatebill(car_company_model,customer_pay_price);
   								 						generatebillbody(car_company_model,car_model_color,car_price);
   								 						generatebillfooter(car_price);
   								 					}
   								 					else
   								 					{
   								 						printf("\nYou entered worng choice in color please. Try Again.");
														getch();
														goto Model_SCORPIO1;	
													}
												}
										}
   								 		else{
											goto flag;
										}
									}
									break;
								
								case 5:
									{
										goto car_detail;
									}
									break;
								case 6:
									{
										goto flag;
									}
									break;
								default:
									{
										printf("\n\t\t\t\t\t\t\tInvalid Services. Please try again. Press any key.................");
										getch();
										goto Mahindra;
									}
									
							}
							
						}
						break;
						
						
						case 7:
						{
							Hyundai:
							title();
							brand=fopen("C:\\Project 1st Sem\\File handling\\Hyundai.txt","r");
							
							if(brand==NULL)
							{
								printf("\n\t\t\t\t\t\t\tFile doesn't exit.");
								exit(0);
							}
							
							printf("\n\n\n\t\t\t\t\t\t\t\tHyundai\n");
							
							while (fgets(car_model, sizeof(car_model), brand)) {
   								 printf("%s", car_model);  // Print the content read from the file	
							}
							
							printf("\n\n\t\t\t\t\t\t\t Provide a number: ");
							scanf("%d",&model_number);
							
							switch(model_number)
							{
								case 1:
									{
										title();
										model=fopen("C:\\Project 1st Sem\\File handling\\HYUNDAI_model_AURA.txt","r");
										while (fgets(car_model_brand, sizeof(car_model_brand), model)) {
   								 			printf("%s", car_model_brand);
   								 		}
   								 		
   								 		printf("\n\n\n\t\t\t\t\t Do you want to buy this model or you want to go back ?");
   								 		printf("\n\t\t\t\t\tEnter y to buy this model or else for previous previous screen :");
   								 		
   								 		fflush(stdin);
   								 		scanf("%c",&a);
   								 		if(a=='y'||a=='Y')
   								 		{
   								 				strcpy(car_company_model,"HYUNDAI Model AURA");
   								 				Model_Aura:
   								 				printf("\n\t\t\t\t\t\t\tEnter a car color you want: ");
   								 				fflush(stdin);
   								 				gets(car_model_color);
   								 				strupr(car_model_color);
   								 				if(strcmp(car_model_color,"BLACK")==0)
   								 				{
   								 					car_price=3696000;
   								 					//color_option:
													generatebill(car_company_model,customer_pay_price);
   								 					generatebillbody(car_company_model,car_model_color,car_price);
   								 					generatebillfooter(car_price);
   								 				}
   								 				else
   								 				{
   								 					printf("\n\t\t\t\t\t\t\tYou entered worng choice in color please. Try Again.");
													getch();
													goto Model_Aura;	
												}
										}
										else{
											goto flag;
										}
									}
									break;
								case 2:
									{
										title();
										model=fopen("C:\\Project 1st Sem\\File handling\\HYUNDAI_model_PALISADE.txt","r");
										while (fgets(car_model_brand, sizeof(car_model_brand), model)) {
   								 			printf("%s", car_model_brand);
   								 		}
   								 		
   								 		printf("\n\n\n\t\t\t\t\t Do you want to buy this model or you want to go back ?");
   								 		printf("\n\t\t\t\t\tEnter y to buy this model or else for previous previous screen :");
   								 		
   								 		fflush(stdin);
   								 		scanf("%c",&a);
   								 		if(a=='y'||a=='Y')
   								 		{
   								 				strcpy(car_company_model,"HYUNDAI Model PALISADE");
   								 				Model_Palisade:
   								 				printf("\n\t\t\t\t\t\t\tEnter a car color you want: ");
   								 				fflush(stdin);
   								 				gets(car_model_color);
   								 				strupr(car_model_color);
   								 				if(strcmp(car_model_color,"RED")==0)
   								 				{
   								 					car_price=23596000;
   								 					//color_option:
													generatebill(car_company_model,customer_pay_price);
   								 					generatebillbody(car_company_model,car_model_color,car_price);
   								 					generatebillfooter(car_price);
   								 				}
   								 				else
   								 				{
   								 					printf("\n\t\t\t\t\t\t\tYou entered worng choice in color please. Try Again.");
													getch();
													goto Model_Palisade;	
												}
										}
   								 		else{
											goto flag;
										}
									}
									break;
								case 3:
									{
										title();
										model=fopen("C:\\Project 1st Sem\\File handling\\HYUNDAI_model_CRETA.txt","r");
										while (fgets(car_model_brand, sizeof(car_model_brand), model)) {
   								 			printf("%s", car_model_brand);
   								 		}
   								 		
   								 		printf("\n\n\n\t\t\t\t\t Do you want to buy this model or you want to go back ?");
   								 		printf("\n\t\t\t\t\tEnter y to buy this model or else for previous previous screen :");
   								 		
   								 		fflush(stdin);
   								 		scanf("%c",&a);
   								 		if(a=='y'||a=='Y')
   								 		{
   								 				strcpy(car_company_model,"HYUNDAI Model CRETA");
   								 				Model_Creta:
   								 				printf("\n\t\t\t\t\t\t\tWhich Variant you want to buy?");
   								 				printf("\n\t\t\t\t\t\t\tPress 1 as Variant E Diesel and 2 as Variant S Diesel.");
   		
   								 				printf("\nVariant: ");
   								 				scanf("%d",&i);
   								 				if(i==1){
												
   								 					Creta:
   								 					printf("\n\t\t\t\t\t\t\tEnter a car color you want: ");
   								 					fflush(stdin);
   								 					gets(car_model_color);
   								 					strupr(car_model_color);
   								 					if(strcmp(car_model_color,"WHITE")==0 || strcmp(car_model_color,"BLACK")==0)
   								 					{
   								 						car_price=4856000;
   								 				//	color_option:
														generatebill(car_company_model,customer_pay_price);
   								 						generatebillbody(car_company_model,car_model_color,car_price);
   								 						generatebillfooter(car_price);
   								 					}
   								 					else
   								 					{
   								 						printf("\n\t\t\t\t\t\t\tYou entered worng choice in color please. Try Again.");
														getch();
														goto Creta;	
													}
												}
												else if(i==2)
												{
														Model_Creta1:
   								 					printf("\n\t\t\t\t\t\t\tEnter a car color you want: ");
   								 					fflush(stdin);
   								 					gets(car_model_color);
   								 					strupr(car_model_color);
   								 					if(strcmp(car_model_color,"BLUE")==0 || strcmp(car_model_color,"WHITE")==0 )
   								 					{
   								 						car_price=5996000;
   								 				//	color_option:
														generatebill(car_company_model,customer_pay_price);
   								 						generatebillbody(car_company_model,car_model_color,car_price);
   								 						generatebillfooter(car_price);
   								 					}
   								 					else
   								 					{
   								 						printf("\n\t\t\t\t\t\t\tYou entered worng choice in color please. Try Again.");
														getch();
														goto Model_Creta1;	
													}
												}
										}
										else{
											goto flag;
										}
									}
									break;
								case 4:
									{
										title();
										model=fopen("C:\\Project 1st Sem\\File handling\\HYUNDAI_model_VERNA.txt","r");
										while (fgets(car_model_brand, sizeof(car_model_brand), model)) {
   								 			printf("%s", car_model_brand);
   								 		}
   								 		
   								 		printf("\n\n\n\t\t\t\t\t Do you want to buy this model or you want to go back ?");
   								 		printf("\n\t\t\t\t\tEnter y to buy this model or else for previous previous screen :");
   								 		
   								 		fflush(stdin);
   								 		scanf("%c",&a);
   								 		if(a=='y'||a=='Y')
   								 		{
   								 				strcpy(car_company_model,"HYUNDAI Model VERNA");
   								 				
   								 				Model_Verna:
   								 				printf("\n\t\t\t\t\t\t\tEnter a car color you want: ");
   								 				fflush(stdin);
   								 				gets(car_model_color);
   								 				strupr(car_model_color);
   								 				if(strcmp(car_model_color,"WHITE")==0)
   								 				{
   								 					car_price=4996000;
   								 					//color_option:
													generatebill(car_company_model,customer_pay_price);
   								 					generatebillbody(car_company_model,car_model_color,car_price);
   								 					generatebillfooter(car_price);
   								 				}
   								 				else
   								 				{
   								 					printf("\n\t\t\t\t\t\t\tYou entered worng choice in color please. Try Again.");
													getch();
													goto Model_Verna;	
												}
										}
   								 		else{
											goto flag;
										}
									}
									break;
								
								case 5:
									{
										goto car_detail;
									}
									break;
								case 6:
									{
										goto flag;
									}
									break;
								default:
									{
										printf("\n\t\t\t\t\t\t\tInvalid Services. Please try again. Press any key.................");
										getch();
										goto Hyundai;
									}
									
							}
							
						}
						break;
					
						case 8:
						{
							goto flag;
						}
						break;
						default:
						{
							printf("\n\t\t\t\t\t\t\t\tSorry please try again");
							getch();
							goto car_detail;
							// car_detail to go back to Available car
						}
				}
				
			}
			break;
			case 2:
				{
					struct bill showbill;
					emp_flag:
					FILE *employee, *show;
					char employee_menu[30];
					int employee_modify_option;
					login_flag:
					title();
					FILE *login_pointer;
					char login_modify[30];
					int loginmodify_option;
					printf("\n\n\n");
					login_pointer=fopen("C:\\Project 1st Sem\\Employee Modify\\login_option.txt","r");
					while(fgets(login_modify,30,login_pointer)){
						printf("%s",login_modify);
					}
					printf("\n\n\t\t\t\t\t\t\tEnter your choice to modify: ");
					scanf("%d",&loginmodify_option);
					switch(loginmodify_option)
					{
						case 1:
						{
							change_password();
						}
						break;
						case 2:
						{
							delete_account();
						}
						break;
						case 3:
						{
							int o=0;
							char z;
							show=fopen("C:\\Project 1st Sem\\bill add.txt","r");
							if(show==NULL)
							{
								printf("\n\t\t\t\t\tFile doesn't exit");
							}
							while(fread(&showbill, sizeof(showbill),1,show)==1)
							{
								printf("\n\n\t\t\t\t\t\t\t\tBill no. %d",o+1);
								printf("\n\t\t\t\t\t\t\t\tName       : %s",showbill.name);
								printf("\n\t\t\t\t\t\t\t\tAddress    : %s",showbill.address);
								printf("\n\t\t\t\t\t\t\t\tContact no : %s",showbill.contact);
								printf("\n\t\t\t\t\t\t\t\tEmail      : %s",showbill.email);
								o++;
								printf("\n\n");
							}
							
							printf("\n\n\t\t\t\t\t\t\t\tDo you want to go back or end the program ? ");
							printf("\n\n\t\t\t\t\t\t\t\tPress b to go back or else to end the program : ");
							fflush(stdin);
							scanf("%c",&z);
							if(z=='b' || z=='B')
							{
								goto flag;
							}
							else
							{
								exit(0);
							}
							
						}	
						break;						
						case 4:
						{
							goto flag;
						}
						break;
						default:
						{
							printf("\n\n\t\t\t\t\t\t\t Out of service.");
							getch();
							goto login_flag;
						}
					}
				}
			default:
				{
					printf("\n \n\t\t\t\t\t\t\t You have entered out of provided service."); 
					getch();
					printf("\n\t\t\t\t\t\t\t Please try again.");
					getch();
					printf("\n \t\t\t\t\t\t\tPress 1 as customer and 2 as employee. ");
					getch();
					goto flag;
				}
			}
			
        }
        getch();
}

void forgot()
{
	forgot:
    system("cls");
    title();
    struct account u;
    int choice;
    char f;
    char username[20], password[20], phone[20];
    FILE *fp = fopen("account.txt", "r");
    fread(&u, sizeof(struct account), 1, fp);

    printf("\n\n\t\t\t\t\t\t\t1.Search by Username\n");
    printf("\n\t\t\t\t\t\t\t2.Search by password\n");
    printf("\n\t\t\t\t\t\t\t3.Search by Phone no.\n");
    //printf("\n\t\t\t\t\t\t\t4.Login\n");
    divider();
    printf("\n\t\t\t\t\t\t\tEnter your choice : ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
    	forget_username:
    	title();
        printf("\n\t\t\t\t\t\t\tEnter your Username : ");
        scanf("%s", username);
        printf("\n");
        if (strcmp(username, u.username))
        {
            printf("\n\t\t\t\t\t\t\tUSERNAME NOT FOUND !!");
            printf("\n\n\t\t\t\t\t\tPlease try again. Press any key...............");
            getch();
            goto forget_username;
        }
        else
        {
            printf("\t\t\t\t\t\t\tACCOUNT FOUND!\n");
            divider();
            printf("\n\t\t\t\t\t\t\tUsername    : %s \n", u.username);
            printf("\n\t\t\t\t\t\t\tFirst name  : %s \n", u.first_name);
            printf("\n\t\t\t\t\t\t\tLast name   : %s \n", u.last_name);
            printf("\n\t\t\t\t\t\t\tPhone no.   : %s \n", u.phone);
            printf("\n\t\t\t\t\t\t\tPassword    : %s \n", u.pass1);
            printf("\n\n\t\t\t\t\t\tPress any key to continue...............");
            
            getch();
        }

        break;

    case 2:
    	forget_pass:
    	title();
        printf("\n\t\t\t\t\t\t\tEnter your Passowrd : ");
        scanf("%s", password);
        printf("\n");
        if (strcmp(password, u.pass1))
        {
			printf("\n\t\t\t\t\t\t\tUSERNAME NOT FOUND !!");
            printf("\n\n\t\t\t\t\t\tPlease try again. Press any key...............");
            getch();
            goto forget_pass;
        }
        else
        {
            printf("\n\t\t\t\t\t\t\tACCOUNT FOUND!\n");
            divider();
            printf("\n\t\t\t\t\t\t\tUsername    : %s \n", u.username);
            printf("\n\t\t\t\t\t\t\tFirst name  : %s \n", u.first_name);
            printf("\n\t\t\t\t\t\t\tLast name   : %s \n", u.last_name);
            printf("\n\t\t\t\t\t\t\tPhone no.   : %s \n", u.phone);
            printf("\n\t\t\t\t\t\t\tPassword    : %s \n", u.pass1);
            printf("\n\n\t\t\t\t\t\tPress any key to continue...............");
            
            getch();
        }

        break;

    case 3:
    	forget_num:
    	title();
        printf("\n\t\t\t\t\t\t\tEnter your Phone no. : ");
        scanf("%s", phone);
        printf("\n");
        if (strcmp(phone, u.phone))
        {
            printf("\n\t\t\t\t\t\t\tUSERNAME NOT FOUND !!");
            printf("\n\n\t\t\t\t\t\tPlease try again. Press any key...............");
            getch();
            goto forget_num;
        }
        else
        {
            printf("\n\t\t\t\t\t\t\tACCOUNT FOUND!\n");
            divider();

            printf("\n\t\t\t\t\t\t\tUsername    : %s \n", u.username);
            printf("\n\t\t\t\t\t\t\tFirst name  : %s \n", u.first_name);
            printf("\n\t\t\t\t\t\t\tLast name   : %s \n", u.last_name);
            printf("\n\t\t\t\t\t\t\tPhone no.   : %s \n", u.phone);
            printf("\n\t\t\t\t\t\t\tPassword    : %s \n", u.pass1);
            printf("\n\n\t\t\t\t\t\tPress any key to continue...............");
            getch();
        }

        break;
    /*case 4:
        login();
*/
    default:
        printf("\n\t\t\t\t\t\t\tINVALID CHOICE\n");
        getch();
        goto forgot;
    }

	printf("\n\n\n\t\t\t\t\t\t\tDo you want to login or exit the program?");
	printf("\n\n\n\t\t\t\t\t\t\tPress l for login and else for exit : ");
	fflush(stdin);
	scanf("%c",&f);
	if(f == 'l' || f=='L')
	{
		login();
	}
	else
	{
		exit(0);
	}
    fclose(fp);
}

void change_password()
{
	number:
    system("cls");
	title();
    struct account change, copy_change;
    char pre_passcode[30], pre_username[30];				//This string is made to grab value form Account.txt detail in it
    char again_passcode[30], test_passcode[30];				// This string is used to take passcode and to check new passcode
    FILE *password, *fp;
    int check_incorrect_passcode=0;
    password=fopen("account.txt","r");
    if(password==NULL)
    {
    	printf("\n\t\t\t\t\t\t\t File doesn't exist");
	}
    while(fread(&change, sizeof(change),1,password))
    {
    	printf("\n\t\t\t\t\t\t\tYou have to enter your previous passcode.\n");
    	printf("\n\t\t\t\t\t\t\tPasscode : ");
    	fflush(stdin);
    	gets(pre_passcode);
		//if(strcmp(change.pass1,pre_username)==0 && strcmp(change.username,pre_username)==0)
		if(strcmp(change.pass1,pre_passcode)==0)
		{
        	printf("\n\t\t\t\t\t\t\tEnter new password : ");
       	 	takepassword(again_passcode);
       	 	pas:
        	printf("\n\t\t\t\t\t\t\tConfirm new password :");
        	fflush(stdin);
        	gets(test_passcode);
        	if (strcmp(again_passcode,test_passcode)==0)
        	{
        		strcpy(change.pass1,again_passcode);
            	printf("*****************************PASSWORD CHANGE SUCCESSFULLY*****************************");
            	copy_change = change;
            	fp = fopen("account.txt", "w+");
            	
            	fwrite(&change,sizeof(struct account),1,fp);
            	//rename()
            	printf("\n\t\t\t\t\t\t\tYou Have to restart again. This program.\n\n\t\t\t\t Enter any key to close this program.");
            	getch();
            	exit(0);
        	}
        	else
        	{
            	//printf("*******INCORRECT PASSWORD******\nPlease try again.....\n");
            	printf("*******************************  INCORRECT PASSCODE  *******************************");
            	printf("\n\n\n\t\t\t\t\t\t\tPLEASE TRY AGAIN");
            	check_incorrect_passcode++;
            	if(check_incorrect_passcode==5)
            	{
            		printf("\n\n\t\t\t\t\t\tYou have tried maximum number of times. Please try again after sometimes.");
            		getch();
            		exit(0);
				}
            	goto pas;
            	
        	}
        	fclose(fp);
    	}

    	else
    	{
        	printf("\n\t\t\t\t\t\t\tThe Provided information doesn't match. Please try gain.\n");
        	getch();
        	goto number;
    	}
	}
}

void delete_account()
{
	title();
    FILE *fp = fopen("account.txt", "r");

    printf("\t\t\t\t\t\t\tARE YOU SURE[Y/N] : ");
    char ch = getche();
    if (ch == 'Y' || ch == 'y')
    {
        fp = fopen("account.txt", "w");
        fprintf(fp, " ");
        printf("\n\t\t\t\t\t\t\tACCOUNT DELETED SUCCESSFULLY\n");
        getch();
    }

    else if (ch == 'N' || ch == 'n')
    {
        printf("\n\t\t\t\t\t\t\tACCOUNT DELETION STOPPED\n");
        getch();
    }
}

void title()
{
	system("cls");
	printf("\n");
	printf("------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	printf("\t\t\t\t\t\t\t\t ---------------------\n");
	printf("\t\t\t\t\t\t\t\t|   CAR-WIZ SOFTWARE  |\n");	
	printf("\t\t\t\t\t\t\t\t| RIDE TO YOUR DREAMS |\n");
	printf("\t\t\t\t\t\t\t\t ---------------------\n\n");
	printf("------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
}

int username_passcode()
{
	title();	
	FILE *usercode, *passname;
	struct account data;
	char u_name[30], u_passcode[30];
	char real_username[30], real_passcode[30];
	usercode=fopen("account.txt","r");
	fread(&data, sizeof(data),1,usercode);
	
    int mistake_login_count=0;
    
	emp_login:
	
	system("cls");
	title();
	
	printf("\n\t\t\t\t\t\t\t\t\tLogin:\n\n");
	printf("\t\t\t\t\t\t\t\tUsername: ");
	fflush(stdin);
	gets(u_name);
	printf("\t\t\t\t\t\t\t\tPasscode: ");
	fflush(stdin);
	takepassword(u_passcode);
	
	if(strcmp(u_name,data.username)==0 && strcmp(u_passcode,data.pass1)==0)
	{
		return 1;
	}
	
	else{
			printf("\n\n\n\t\t\t\t\t\t\t   INCORRET PASSWORD. TRY AGAIN\n");
			getch();
            mistake_login_count++;
            if(mistake_login_count==5)
            {
            	printf("\n\n\t\t\t\t\t\tYou have tried alot of times. Please try after sometimes.\n\n");
            	exit(0);
			}
		goto emp_login;
	}
}

