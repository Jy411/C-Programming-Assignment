/*-------------------------------------------------------------------
*/
/* ITS60304ý Assignment #1 */
/* C Programming */
/* Student Name: <Tan Jinyung> <Raynald Vun> */
/* Student ID: <0328895> <0324824> */
/*-------------------------------------------------------------------
*/


#include <stdio.h>
#include <string.h>

struct custDetails { // structure to contain customer info details
    char custID[5];
    char custName[20];
    int prevRead;
    int currRead;
    float charges;
};

int prevRead,currRead, newCurrRead,usageKWh,i;
char custID[5],custName[20],custID2[20],trash[999],choice[99],custID3[99];
float charges = 0, totCharges = 0, used, cost, allUsage = 0;
int a = 0, b = 0, c = 0, d = 0, e = 0;
float usage = 0;


FILE *f1; // pointer to txt file
FILE *f2;

//int storeDetails()
//{
//
//	for (i = 0; i < 5; i++)
//	{
//		struct custDetails cust[i];
//
//		while (!feof(f1)) // while file pointer is not at the end of file
//		{
//			fscanf(f1, "%[^;];%[^;];%d;%d;%f\n", cust[i].custID,custName, &prevRead, &currRead, &charges);
//			if (strcmp(editID,editID2) == 0) // if user enters first customer, it will immediately go into the if statement and print "User found!"
//			{
//
//				printf("Sucess!\n");
//				printf("What would you like to edit? 1.Customer Name 2.Charges\n");
//				scanf("%d", &editChoice);
//				if (editChoice == 1)
//				{
//					printf("You have selected Option 1 (Edit Customer Name)\n");
//					break;
//
//				}
//
//				else if (editChoice == 2)
//				{
//					printf("You have selected Option 2 (Edit Charges)\n");
//					break;
//
//				}
//
//			}
//		}
//
//	}
//
//	printf("%s\n",cust[0].custID);
//	rewind (f1); //rewind file pointer so file pointer will be at beginning of text file again when loop reoccurs.
//}


int case1() // function for case 1
{
    printf("_______________________________________________________________________________________"  // Title screen
           "\n\nYou have selected option 1\n\n"
           ">>>>>>>>>>>>>>>>>\n"
           "Record Usage\n"
           "<<<<<<<<<<<<<<<<<");


        struct custDetails cust[i];

        do // start a do...while loop for case 1
        {
            printf("\n\nEnter customer ID (Enter -1 to exit to menu)\n> ");
            scanf("%s", custID);// assigns customer ID as string to custID variable
            f1 = fopen("customer.txt", "r"); //opens customer.txt in read mode

            while (!feof(f1)) // while file pointer is not at the end of file
            {
                a = 0, b = 0, c = 0, d = 0, e = 0; // initialize variable values to 0 to reset value at the beginning of the loop
                fscanf(f1, "%[^;];%[^;];%d;%d;%f\n", custID2,custName, &prevRead, &currRead, &charges);
                // read everything that is not semicolon until it reaches a semicolon for the whole line and assign each string and integer into variables

                if (strcmp(custID,custID2) == 0) // if user enters first customer, it will immediately go into the if statement and print "User found!"
                {
                    printf("\n=============\nUser found!\n=============\n");
                    printf("\nEnter current reading : ");
                    scanf("%d", &newCurrRead); // user input here will be assigned to a newCurrRead variable which will be used to find the usage for the particular month
                    used = newCurrRead - currRead;

                    if (used > 0, used < 201)
                    {
                        a = used; // assigns a to used = newCurrRead - currRead if it is between 0 and 201

                    }
                    else if (used > 200, used < 301)
                    {
                        b = used;   // this assigns the next block of tariff usage into variable b if it is higher than 200
                        b = b-200;  // deduct 200 because exceeds first 200 of usage so when calculations happen it only be for the quota used AFTER the first 200
                        a = 200;   // if user inputted usage as higher than 200, then a will be assigned with 200
                    }
                    else if (used > 300, used < 601)
                    {
                        c = used;
                        c = c-300; // deducts 300 because exceeds first 300 kWh of usage
                        b = 100; // takes it as 100 because once this quota is exceeded it will always be 100 kWh
                        a = 200;
                    }
                    else if (used > 600, used < 901)
                    {
                        d = used;
                        d = d-600; // same principle applies here
                        c = 300;
                        b = 100;
                        a = 200;
                    }
                    else if (used > 901)
                    {
                        e = used;
                        e = e-900; // and here
                        d = 300;
                        c = 300;
                        b = 100;
                        a = 200;
                    }

                    float total = (a*0.218) + (b*0.334) + (c*0.516) + (d*0.546) + (e*0.571);  // where the calculation is done, takes each block of quota and multiplies them by the rate and sums them up.


                    printf("\n\n==============================\nCustomer ID: %s\n"
                           "Customer Name: %s\n==============================\n\n", custID2, custName);
                    printf("======================================================================\n"
                           "Blok Tarif(kWh)  Blok Prokata(kWh)  Kadar(RM)   Amaun(RM)\n"
                           "======================================================================\n");
                    printf("%-16d %-21d %-11.3f %.2f\n", 200, a, 0.218, a*0.218); // prints the values of how much of quota was used and cost
                    printf("%-18d %-19d %-12.3f %.2f\n", 100, b, 0.334, b*0.334); // repeats for each block
                    printf("%-18d %-19d %-12.3f %.2f\n", 300, c, 0.516, c*0.516);
                    printf("%-18d %-19d %-12.3f %.2f\n", 300, d, 0.546, d*0.546);
                    printf("%-18s %-19d %-12.3f %.2f\n", ">300", e, 0.571, e*0.571);

                    printf("======================================================================\n");
                    printf("%-16s %-33d %.2f\n","Total", a+b+c+d+e, total);
                    printf("======================================================================\n\n\n");



                    printf("_______________________________________________________________________________________\n\n\n");



                    printf("=================================================================\n");
                    printf("%34s\t\t|%10s\t|\n ", "Meter Reading (kWh)", "Usage");
                    printf("================================================\n");
                    printf("%20s\t|%20s\t|\t\t|\n", "Previous Reading", "Current reading");
                    printf("=================================================\n");
                    printf("%15d\t\t|%15d\t|%9d\t|\n", currRead, newCurrRead, newCurrRead - currRead);
                    printf("=================================================================\n");

                    break;
                }
            }
            rewind (f1); //rewind file pointer so file pointer will be at beginning of text file again when loop reoccurs.
        } while (strcmp(custID, "-1") != 0); // if user inputs custID as -1 when program asks for customer ID it will exit the loop and go back to the menu
}

int case2() // function for case 2
{
    f1 = fopen("customer.txt", "a+");
    printf("_______________________________________________________________________________________"
           "\n\nYou have selected option 2\n\n"
           ">>>>>>>>>>>>>>>\n"
           "Add Customer\n"
           "<<<<<<<<<<<<<<<\n\n");
    printf("This option allows user to add new customer\n");
    printf("Please enter customer ID(R006 to RXXX)\n> ");
    scanf("%s", custID3); // this takes the user input of customer ID into custID3 variable, though it does not care that the user might input a different format of customer ID.

    while (!feof(f1))
    {
        fscanf(f1, "%[^;];%[^;];%d;%d;%f\n", custID2,custName, &prevRead, &currRead, &charges);

        if (strcmp(custID3,custID2) == 0) // if user inputted ID is not unique then it will output an error message.
        {
            printf("User already exists! Please be unique.\n");
            break;
        }
    }


    if (strcmp(custID3,custID2) != 0) // if ID is unique then this will occur
    {
        struct custDetails newCust[i]; // newCust[i] so every time this if branch is entered the i++ at the end will increment the i by 1 and new customer details will be stored in a new newCust variable
        printf("New user detected!\n");  // basically it does scanf on every variable such as name, and readings from the user input and saves it into a struct
        printf("Enter Customer Name: ");
        scanf("%s", newCust[i].custName);
        printf("Enter Previous Reading: ");
        scanf("%d", &newCust[i].prevRead);
        printf("Enter Current Reading: ");
        scanf("%d", &newCust[i].currRead);
        printf("Enter Charges: ");
        scanf("%f", &newCust[i].charges);
        fprintf(f1, "\n%s;%s;%d;%d;%f", custID3,newCust[i].custName,newCust[i].prevRead,newCust[i].currRead,newCust[i].charges); //appends all that was inputted by the user into the next file. \n to make a new line because append does not make a new line and it would just continue from the last character in the text file
        i++;
    }





}

int case3() // function for case 3
{
    f1 = fopen("customer.txt", "a+"); // open text file for appending
    char editID[99],editID2[99];
	int editChoice;

	printf("_______________________________________________________________________________________"
		   "\n\nYou have selected option 3\n\n"
		   ">>>>>>>>>>>>>>>>>\n"
		   "Edit Customer\n"
		   "<<<<<<<<<<<<<<<<<\n\n");
	printf("This option allows user to edit customer info\n");

        do // start a do...while loop for case 3
        {
            printf("Enter Customer ID to edit\n> ");
			scanf("%s", editID);

            while (!feof(f1)) // while file pointer is not at the end of file
            {
                fscanf(f1, "%[^;];%[^;];%d;%d;%f\n", editID2,custName, &prevRead, &currRead, &charges);
                if (strcmp(editID,editID2) == 0) // if user enters matching customer ID, it will immediately go into the if statement and print "User found!"
                {
					printf("Success!\n");
					printf("What would you like to edit? 1.Customer Name 2.Charges\n");
					scanf("%d", &editChoice);
					if (editChoice == 1)
					{
						printf("You have selected Option 1 (Edit Customer Name)\n");
						break;

					}

					else if (editChoice == 2)
					{
						printf("You have selected Option 2 (Edit Charges)\n");
						break;

					}

                }


            }
            rewind (f1); //rewind file pointer so file pointer will be at beginning of text file again when loop reoccurs.
		}while(strcmp(editID,editID2) != 0); //while string editID is not equal to editID2 keep looping

}

int case4() // function for case 4
{
    char editID[99],editID2[99];
    int editChoice;

    f1 = fopen("customer.txt", "r+");
    f2 = fopen("customer_new.txt", "w");

    printf("_______________________________________________________________________________________"
           "\n\nYou have selected option 4\n\n"
           ">>>>>>>>>>>>>>>>>\n"
           "Delete Customer\n"
           "<<<<<<<<<<<<<<<<<\n\n");
    printf("This option allows user to delete customer\n");

    do // start a do...while loop for case 4
    {
        printf("Enter Customer ID to delete\n> ");
        scanf("%s", editID);

        while (!feof(f1)) // while file pointer is not at the end of file
        {
            fscanf(f1, "%[^;];%[^;];%d;%d;%f\n", editID2,custName, &prevRead, &currRead, &charges);
            if (strcmp(editID,editID2) == 0) // if user enters matching customer ID, it will immediately go into the if statement and print "User found!"
            {
                printf("Success! Customer found!\n");
                printf("Are you sure you want to delete? 1.Yes 2.No\n");
                scanf("%d", &editChoice);
                if (editChoice == 1)
                {
                    printf("Deleting.....\n");
                    while (fscanf(f1,"%[^;];%[^;];%d;%d;%f\n", editID2,custName, &prevRead, &currRead, &charges) > 0)
                    {
                        if(strcmp(editID2, editID) == 0)
                        {
                             fprintf(f2,"%[^;];%[^;];%d;%d;%f\n", editID2, custName, prevRead, currRead, charges);
                        }
                    }

                    break;
                }

                else if (editChoice == 2)
                {
                    printf("Abort abort!\n");
                    break;

                }

            }


        }
        rewind (f1); //rewind file pointer so file pointer will be at beginning of text file again when loop reoccurs.
    }while(strcmp(editID,editID2) != 0); //while string editID is not equal to editID2 keep looping


}


int case5() // function for case 5
{
    f1 = fopen("customer.txt", "r"); //opens customer.txt in read mode

    printf("_______________________________________________________________________________________"
           "\n\nYou have selected option 5\n\n"
           ">>>>>>>>>>>>>>>>\n"
           "Show Customer\n"
           "<<<<<<<<<<<<<<<<\n\n");
    printf("This option lists customer details\n\n");
    printf("#################################################################################################\n");
    printf("%-20s%-20s%-20s%-20s%s\n","Customer ID","Customer Name","Previous Reading","Current Reading","Charges");
    printf("#################################################################################################\n");

    while (!feof(f1))   // while file pointer has not reach end of file, loops until file pointer reaches end of file
        {
        fscanf(f1, "%[^;];%[^;];%d;%d;%f", &custID2,&custName, &prevRead, &currRead, &charges); //scans the items in the text file following its format
        printf("%-21s%-20s%-20d%-20d%.2f", custID2, custName, prevRead, currRead, charges);
        }
    printf("\n#################################################################################################\n\n");
}

int case6() // function for case 6
{
    f1 = fopen("customer.txt", "r"); //opens customer.txt in read mode

    printf("_______________________________________________________________________________________"
           "\n\nYou have selected option 6\n\n"
           ">>>>>>>>>>>>>>>>>>>\n"
           "Show Total Income\n"
           "<<<<<<<<<<<<<<<<<<<\n");


           while (!feof(f1)) // while file pointer is not at end of file
           {
               fscanf(f1, "%[^;];%[^;];%d;%d;%f", custID, custName, &currRead, &newCurrRead, &charges); // will scan until file pointer end of line and does it again each times it loops
               usageKWh+= (newCurrRead - currRead);
               totCharges+= charges;
           }

           printf("\nTotal usage : %d kWh\nTotal charges : RM %.2f\n", usageKWh, totCharges);


}

int main(void) // where the main menu is located
{

    do{ // do.. while loop to stay in menu if user gives an invalid input and/or until exit is selected
        printf("\n------------------------------------\nElectricity Management System\n------------------------------------\n"); //TITLE SCREEN
        printf("1.Record Usage\n2.Add customer\n3.Edit customer\n4.Delete customer\n5.Show customer\n6.Show total monthly income\n7.Exit\n\n"); //TITLE SCREEN

		printf("\n=================================\n"
                "Please choose an option (1 - 7)\n"
                "=================================\n>"); // Prompts user to choose
		scanf("%s", &choice[0]); // Assigns user choice to choice variable
		printf("\n");


		switch(choice[0])// switch case statement for menu
		{
			case '1':
			    case1();
				break;
			case '2':
			    case2();
				break;
			case '3':
				case3();
				break;
			case '4':
			    case4();
				break;
			case '5':
                case5();
				break;
			case '6':
			    case6();
			    break;
            case '7':
				printf("Program will exit\n");
				break;
			default:
				printf("Invalid input. Please choose from 1 - 7\n");
				break;
		}
		rewind(f1);
	}while( strcmp(choice, "7") != 0 ) ; // while user choice for menu is not 7, it will stay in menu.

            fclose(f1); // closes the file.
}


