//The Project Begin
//New updated verion with login


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>
#include<time.h>
#include<windows.h>

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
    char gender;
    char DOB[10];
    char pass1[20];
};

void divider()
{
	int i=0;
    for (i=0;i<50;i++)
    {
        printf("-");
    }
}


int main()
{
	
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
/*
        case 4:
            change_password();
            break;

        case 5:
            delete_account();
            break;
*/
        	case 4:
           		exit(0);

        	default:
            	printf("Invalid Choice!\n");
        }
    

	//int menu();
	
	/*if
	{*/
		
	//}
	
	/*else
	{
		printf("\nProvided information doesn't match. Please try again.");
		getch();
		//delay(1000);
		goto login;
	}
	*/
	return 0;
}
//function for generating bill
void generatebill(char variant[50],long int price_car)
{
	title();
	char customer_name[50];
	printf("Please provide us your information: \n");
	fflush(stdin);
	printf("\nEnter your full name: ");
	gets(customer_name);
	
	
	title();
	printf("\n........................................");
	//printf("\nDate:%s",date);
	printf("\nInvoice to:%s",customer_name);
	printf("\n");
	printf("..........................................\n");
	printf("Model\t\t\t");
	printf("Color\t\t");
	printf("Total\t\t");
	printf("\n........................................\n\n");
}

//function for generating bill body
void generatebillbody(char variant[50],char car_color[10],long int price)
{
	printf("%s\t\t",variant);
	printf("%s\t\t",car_color);
	printf("%.2f\t\t",price);
	printf("\n\n");
}


//function for generating bill footer
void generatebillfooter(long int total)
{
	printf("\n");
	float discount=0.1*total;
	float nettotal=total-discount;
	float gst=0.09*nettotal,grandtotal=nettotal+2*gst;
	printf("..........................................\n");
	printf("Sub Total\t\t\t%.2f""%",total);
	printf("\nDiscount @10%s\t\t\t%.2f","%",discount);
	printf("\n\t\t\t\t---------");
	printf("\nNet Total\t\t\t%.2f",nettotal);
	printf("\nGST @9%s\t\t\t\t%.2f","%",gst);
	printf("\nSGST @9%s\t\t\t%.2f","%",gst);
    printf("\n........................................");
    printf("\nGrand Total\t\t\t%.2f",grandtotal);
    printf("\n........................................\n");
}

void employee_option()
{
	printf("\n1. Obtainable Car");
	printf("\n2. Employee Login\n\n");
}

int menu()
{
	title();
    int c;
    printf("\n******************MAIN MENU******************\n");
    divider();
    printf("\n1.SIGNUP\n");
    printf("2.LOGIN\n");
    printf("3.FORGOT PASSOWRD OR USERNAME\n");
    /*
    printf("4.CHANGE PASSWORD\n");
    printf("5.DELETE ACCOUNT\n");*/
    printf("4.EXIT\n");
    divider();
    printf("\nEnter your choice : ");
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

void signup()
{
	title();
    struct account u;
    system("cls");
    char pass2[20];
    printf("CREATING NEW ACCOUNT \n");
    divider();
    printf("\nENTER your first name : ");
    scanf("%s", u.first_name);
    printf("Enter last name : ");
    fflush(stdin);
    scanf("%s", u.last_name);
    printf("Enter your username : ");
    fflush(stdin);
    scanf("%s", u.username);
    printf("Enter your phone number : ");
    fflush(stdin);
    scanf("%s", u.phone);
    fflush(stdin);
    printf("Enter Gender : ");
    fflush(stdin);
    scanf("%c", &u.gender);
    printf("Enter your DOB : ");
    fflush(stdin);
    scanf("%s", u.DOB);

    printf("Enter password : ");
    fflush(stdin);
    takepassword(u.pass1);

conf_pass:
    printf("\nConfirm password : ");
    scanf("%s", pass2);

    if (strcmp(u.pass1, pass2))
    {
        printf("INCORRECT PASSWORD \n\n");
        goto conf_pass;
    }
    else
    {
        printf("ACCOUNT CREATED SUCCESSFULLY\n\n");
        getch();

        FILE *fp = fopen("C:\\Project 1st Sem\\Employee Modify\\account.txt", "w");
        fwrite(&u, sizeof(struct account), 1, fp);
        fclose(fp);
    }
    
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
            printf("\n************WELCOME ************\n");
            divider();
			
			printf("\nYour username and passcode matched.");
			
			getch();
			printf("\n\nWelcome !");
		
			getch();
	
			flag:
			title();
			employee_option();
	
			int choice=0;				//choice for user to interact as
			printf("\n\nPress 1 as Customer and 2 as Employee \n\nYour are interacting as: ");
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
			char car_model_color[10];
	
			switch(choice)
			{
				case 1:
				{
					car_detail:
					title();
					detail=fopen("C:\\Project 1st Sem\\File handling\\Detail.txt","r");
				
					if(detail==NULL)
					{
						printf("\nFile doesn't exit.");
						exit(0);
					}
				 
					while(fgets(car_company, sizeof(car_company),detail)){
						//puts(car_company);
						printf("%s", car_company);
					}
					
					printf("\n\n\n\n\t\tWhich company car you want to look or Go back to home page:  ");
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
							
							printf("\n\t\tBMW Model\n");
							while (fgets(car_model, sizeof(car_model), brand)) {
   								 printf("%s", car_model);  // Print the content read from the file	
							}
							
							printf("\n\n\t Provide a number: ");
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
   								 		
   								 		printf("\n\n Do you want to buy this model or you want to go back ?");
   								 		printf("\nEnter y to buy this model or n to go back to previous screen :");
   								 		fflush(stdin);
   								 		scanf("%c",&a);
   								 		if(a=='y'||a=='Y')
   								 		{
   								 				strcpy(car_company_model,"BMW Model X1");
   								 				
   								 				printf("\nEnter a car color you want: ");
   								 				fflush(stdin);
   								 				gets(car_model_color);
   								 				car_price=19000000;
   								 				again:					// If payment is wrong
   								 				printf("\n\nFirst pay Full Amount for further payment ");
   								 				printf("\nEnter your payment: ");
   								 				fflush(stdin);
   								 				scanf("%ld",&customer_pay_price);
   								 				if(car_price==customer_pay_price)
   								 				{
   								 					generatebill(car_company_model,customer_pay_price);
   								 					generatebillbody(car_company_model,car_model_color,customer_pay_price);
   								 					//generatebillfootor(customer_pay_price);
												}
   								 				else if(car_price <= customer_pay_price)
   								 				{
   								 					printf("\nSry your tranaction doesn't match. " );
														goto again;	
												}
												else
												{
													printf("\nSry your tranaction is not sufficient. " );
														goto again;
												}
										}
   								 		
   								 		
									}
									break;
								case 2:
									{
										title();
										model=fopen("C:\\Project 1st Sem\\File handling\\BMW_model_X2.txt","r");
										//printf("\nTo be updated");
										while (fgets(car_model_brand, sizeof(car_model_brand), model)) {
   								 			printf("%s", car_model_brand);
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
										break;
									}
									
							}
							
						}
						break;
						
						
						case 2:
						{
							title();
							brand=fopen("C:\\Project 1st Sem\\File handling\\Tesla.txt","r");
							
							if(brand==NULL)
							{
								printf("\nFile doesn't exit.");
								exit(0);
							}
							
							printf("\n\t\tTesla Model\n\n");
								while (fgets(car_model, sizeof(car_model), brand)) {
   								 printf("%s", car_model);  // Print the content read from the file	
							}
							
							printf("\n\n\t\t Provide a number: ");
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
									}
									break;
								case 2:
									{
										title();
										model=fopen("C:\\Project 1st Sem\\File handling\\TESLA_model_X.txt","r");
										while (fgets(car_model_brand, sizeof(car_model_brand), model)) {
   								 			printf("%s", car_model_brand);
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
										break;
									}
									
							}
							
						}
						break;
					
						
						case 3:
						{
							title();
							brand=fopen("C:\\Project 1st Sem\\File handling\\Toyota.txt","r");
							
							if(brand==NULL)
							{
								printf("\nFile doesn't exit.");
								exit(0);
							}
							printf("\n\t\tToyata Model\n");
							
							while (fgets(car_model, sizeof(car_model), brand)) {
   								 printf("%s", car_model);  // Print the content read from the file	
							}
							
							printf("\n\n\t\t Provide a number: ");
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
									}
									break;
								case 2:
									{
										title();
										model=fopen("C:\\Project 1st Sem\\File handling\\TOYOTA_model_Rush.txt","r");
										while (fgets(car_model_brand, sizeof(car_model_brand), model)) {
   								 			printf("%s", car_model_brand);
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
										break;
									}
									
							}
							
						}
						break;
					
					
						
						case 4:
						{
							title();
							brand=fopen("C:\\Project 1st Sem\\File handling\\Audi.txt","r");
							
							if(brand==NULL)
							{
								printf("\nFile doesn't exit.");
								exit(0);
							}
							printf("\n\t\tAudi Model\n");
							
							while (fgets(car_model, sizeof(car_model), brand)) {
   								 printf("%s", car_model);  // Print the content read from the file	
							}
							
							
							printf("\n\n\t Provide a number: ");
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
									}
									break;
								case 2:
									{
										title();
										model=fopen("C:\\Project 1st Sem\\File handling\\AUDI_model_A6.txt","r");
										while (fgets(car_model_brand, sizeof(car_model_brand), model)) {
   								 			printf("%s", car_model_brand);
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
									}
									break;
								case 4:
									{
										title();
										model=fopen("C:\\Project 1st Sem\\File handling\\AUDI_model_Q7.txt","r");
										while (fgets(car_model_brand, sizeof(car_model_brand), model)) {
   								 			printf("%s", car_model_brand);
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
										break;
									}
									
							}
							
						}
						break;
						
					
						case 5:
						{
							title();
							brand=fopen("C:\\Project 1st Sem\\File handling\\Nissan.txt","r");
							
							if(brand==NULL)
							{
								printf("\nFile doesn't exit.");
								exit(0);
							}
							printf("\n\t\tNissan Model\n");
							
							while (fgets(car_model, sizeof(car_model), brand)) {
   								 printf("%s", car_model);  // Print the content read from the file	
							}
							
							printf("\n\n\t Provide a number: ");
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
									}
									break;
								case 2:
									{
										title();
										model=fopen("C:\\Project 1st Sem\\File handling\\NISSAN_model_KICKS.txt","r");
										while (fgets(car_model_brand, sizeof(car_model_brand), model)) {
   								 			printf("%s", car_model_brand);
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
										break;
									}
									
							}
							
						}
						break;
						
						
						case 6:
						{
							title();
							brand=fopen("C:\\Project 1st Sem\\File handling\\Mahindra.txt","r");
							
							if(brand==NULL)
							{
								printf("\nFile doesn't exit.");
								exit(0);
							}
							printf("\n\t\tMahindra Model\n");
							
							while (fgets(car_model, sizeof(car_model), brand)) {
   								 printf("%s", car_model);  // Print the content read from the file	
							}
							
							printf("\n\n\t Provide a number: ");
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
										
									}
									break;
								case 2:
									{
										title();
										model=fopen("C:\\Project 1st Sem\\File handling\\MAHINDRA_model_MARAZZO.txt","r");
										while (fgets(car_model_brand, sizeof(car_model_brand), model)) {
   								 			printf("%s", car_model_brand);
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
										
									}
									break;
								case 4:
									{
										title();
										model=fopen("C:\\Project 1st Sem\\File handling\\MAHINDRA_model_SCORPIO.txt","r");
										while (fgets(car_model_brand, sizeof(car_model_brand), model)) {
   								 			printf("%s", car_model_brand);
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
										break;
									}
									
							}
							
						}
						break;
						
						
						case 7:
						{
							title();
							brand=fopen("C:\\Project 1st Sem\\File handling\\Hyundai.txt","r");
							
							if(brand==NULL)
							{
								printf("\nFile doesn't exit.");
								exit(0);
							}
							
							printf("\n\t\tHyundai\n");
							
							while (fgets(car_model, sizeof(car_model), brand)) {
   								 printf("%s", car_model);  // Print the content read from the file	
							}
							
							printf("\n\n\t Provide a number: ");
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
									}
									break;
								case 2:
									{
										title();
										model=fopen("C:\\Project 1st Sem\\File handling\\HYUNDAI_model_PALISADE.txt","r");
										while (fgets(car_model_brand, sizeof(car_model_brand), model)) {
   								 			printf("%s", car_model_brand);
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
									}
									break;
								case 4:
									{
										title();
										model=fopen("C:\\Project 1st Sem\\File handling\\HYUNDAI_model_VERNA.txt","r");
										while (fgets(car_model_brand, sizeof(car_model_brand), model)) {
   								 			printf("%s", car_model_brand);
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
										break;
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
							printf("\nSorry please try again");
							goto car_detail;
							// car_detail to go back to Available car
						}
				}
				
			}
			break;
			case 2:
				{
					emp_flag:
					FILE *employee;
					char employee_menu[30];
					int employee_modify_option=0;
					employee=fopen("C:\\Project 1st Sem\\Employee Modify\\Details.txt","r");
					title();
					while(fgets(employee_menu, sizeof(employee_menu),employee))
					{
						printf("%s",employee_menu);
					}
					printf("\n\n\t\tEnter your facilities: ");
					scanf("%d",&employee_modify_option);
					switch(employee_modify_option)
					{
						case 1:
							{
								printf("\nTo be continue");
							}
							break;
						case 2:
							{
								printf("\nTo be continue");
							}
							break;
						case 3:
							{
								printf("\nTo be continue");
							}
							break;
						case 4:
							{
								login_flag:
								title();
								FILE *login_pointer;
								char login_modify[30];
								int loginmodify_option=0;
								login_pointer=fopen("C:\\Project 1st Sem\\Employee Modify\\login_option.txt","r");
								while(fgets(login_modify,30,login_pointer)){
									printf("%s",login_modify);
								}
								printf("\n\n Enter your choice to modify: ");
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
											goto flag;		
										}
									default:
										{
											printf("\n\n Out of service.");
											getch();
											goto login_flag;
										}
								}
							}
							break;
						case 5:
							{
								goto flag;
							}
							break;
						default:
							{
								printf("\n You have entered wrong option.");
								getch();
								goto emp_flag;
							}
							
					}
				
				}
				break;
			default:
				{
					printf("\n \n You have entered out of provided service."); 
					getch();
					printf("\n Please try again.");
					getch();
					printf("\n Press 1 as customer and 2 as employee. ");
					getch();
					goto flag;
				}
			}
			
        }
        getch();
}

void forgot()
{
    system("cls");
    title();
    struct account u;
    int choice;
    char username[20], password[20], phone[20];
    FILE *fp = fopen("account.txt", "r");
    fread(&u, sizeof(struct account), 1, fp);

    printf("\n1.Search by Username\n");
    printf("2.Search by password\n");
    printf("3.Search by Phone no.\n");
    printf("4.MAIN MENU\n");
    divider();
    printf("\nEnter your choice : ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
    	title();
        printf("Enter your Username : ");
        scanf("%s", username);
        if (strcmp(username, u.username))
        {
            printf("USERNAME NOT FOUND !!");
            getch();
        }
        else
        {
            printf("ACCOUNT FOUND!\n");
            divider();
            printf("\nUsername    : %s \n", u.username);
            printf("First name  : %s \n", u.first_name);
            printf("Last name   : %s \n", u.last_name);
            printf("Phone no.   : %s \n", u.phone);
            printf("Password    : %s \n", u.pass1);
            getch();
        }

        break;

    case 2:
        printf("Enter your Passowrd : ");
        scanf("%s", password);
        if (strcmp(password, u.pass1))
        {
            printf("ACCOUNT NOT FOUND !!");
            getch();
        }
        else
        {
            printf("ACCOUNT FOUND!\n");
            divider();
            printf("\nUsername    : %s \n", u.username);
            printf("First name  : %s \n", u.first_name);
            printf("Last name   : %s \n", u.last_name);
            printf("Phone no.   : %s \n", u.phone);
            printf("Password    : %s \n", u.pass1);
            getch();
        }

        break;

    case 3:
        printf("Enter your Phone no. : ");
        scanf("%s", phone);
        if (strcmp(phone, u.phone))
        {
            printf("ACCOUNT NOT FOUND !!");
            getch();
        }
        else
        {
            printf("ACCOUNT FOUND!\n");
            divider();

            printf("\nUsername    : %s \n", u.username);
            printf("First name  : %s \n", u.first_name);
            printf("Last name   : %s \n", u.last_name);
            printf("Phone no.   : %s \n", u.phone);
            printf("Password    : %s \n", u.pass1);
            getch();
        }

        break;
    case 4:
        return;

    default:
        printf("INVALID CHOICE\n");
        break;
    }

    fclose(fp);
}

void change_password()
{
	number:
    system("cls");
	title();
    struct account change, copy_change;
    char pre_passwoed[30], pre_username[30];				//This string is made to grab value form Account.txt detail in it
    char again_passcode[30], test_passcode[30];				// This string is used to take passcode and to check new passcode
    FILE *password, *fp;
    int check_incorrect_passcode=0;
    password=fopen("C:\\Project 1st Sem\\Employee Modify\\account.txt","r");
    if(password==NULL)
    {
    	printf("\n File doesn't exist");
	}
    while(fread(&change, sizeof(change),1,password))
    {
    	printf("\nUsername : ");
    	fflush(stdin);
    	gets(pre_username);
    	printf("\nPasscode : ");
    	fflush(stdin);
    	gets(pre_username);
		if(strcmp(change.pass1,pre_username)==0 && strcmp(change.username,pre_username)==0)
		{
        	printf("Enter new password : ");
       	 	takepassword(again_passcode);
       	 	pas:
        	printf("\nConfirm new password :");
        	fflush(stdin);
        	gets(test_passcode);
        	if (strcmp(again_passcode,test_passcode)==0)
        	{
        		strcpy(change.pass1,again_passcode);
            	printf("*********PASSWORD CHANGE SUCCESSFULLY*********");
            	copy_change = change;
            	fp = fopen("C:\\Project 1st Sem\\Employee Modify\\change.txt", "w+");
            	
            	fwrite(&copy_change,sizeof(struct account),1,fp);
            	//rename()
            	getch();
            	
            	
            	char change_back;
            	
            	
            	//printf("\%s %s %s %s %s",copy_change.first_name,copy_change.last_name,copy_change.username,copy_change.pass1);
            	
            	change_flag:
        		printf("\n Do you want to continue and move to home screen or end the program: "); 
				printf("\n Press y as continue and n to exit: ");
        		scanf("%c",&change_back);
        		switch(change_back)
        		{
        			case 'y':
        				{
        					//goto flag;
        					login();
						}
						break;
					case 'n':
						{
							exit(0);
						}
						break;
					default:
						{
							printf("\nInvalid option. Please try again.");
							goto change_flag;
							//login();
						}
				}
        	}
        	else
        	{
            	printf("*******INCORRECT PASSWORD******\nPlease try again.....\n");
            	check_incorrect_passcode++;
            	if(check_incorrect_passcode==5)
            	{
            		printf("\nYou have tried maximum number of times. Please try again after sometimes.");
            		getch();
            		exit(0);
				}
            	goto pas;
            	
        	}
        	fclose(fp);
    	}

    	else
    	{
        	printf("The Provided information doesn't match. Please try gain.\n");
        	getch();
        	goto number;
    	}
	}
}

void delete_account()
{
	title();
    FILE *fp = fopen("C:\\Project 1st Sem\\Employee Modify\\account.txt", "r");

    printf("ARE YOU SURE[Y/N] : ");
    char ch = getche();
    if (ch == 'Y' || ch == 'y')
    {
        fp = fopen("C:\\Project 1st Sem\\Employee Modify\\account.txt", "w");
        fprintf(fp, " ");
        printf("\nACCOUNT DELETED SUCCESSFULLY\n");
        getch();
    }

    else if (ch == 'N' || ch == 'n')
    {
        printf("\nACCOUNT DELETION STOPPED\n");
        getch();
    }
}

void title()
{
	system("cls");
	printf("\n");
	printf("\t\t\t\t\t\t   CAR-WIZ SOFTWARE\n");	
	printf("\t\t\t\t\t\t RIDE TO YOUR DREAMS\n\n");
}

int username_passcode()
{
	
	FILE *usercode, *passname;
	struct account data;
	char u_name[30], u_passcode[30];
	char real_username[30], real_passcode[30];
	usercode=fopen("C:\\Project 1st Sem\\Employee Modify\\account.txt","r");
	fread(&data, sizeof(data),1,usercode);
	
    int mistake_login_count=0;
    
	emp_login:
	
	system("cls");
	title();
	
	printf("\n\tLogin:\n\n");
	printf("Username: ");
	fflush(stdin);
	gets(u_name);
	printf("Passcode: ");
	fflush(stdin);
	takepassword(u_passcode);
	
	if(strcmp(u_name,data.username)==0 && strcmp(u_passcode,data.pass1)==0)
	{
		return 1;
	}
	
	else{
			printf("\nINCORRET PASSWORD. TRY AGAIN\n");
			getch();
            mistake_login_count++;
            if(mistake_login_count==5)
            {
            	printf("\n\nYou have tried alot of times. Please try after sometimes.\n\n");
            	exit(0);
			}
		goto emp_login;
	}
}

