#include <stdio.h>
#include <time.h>
/*
customer login    -> register and use it

Manager login     -> user name = Mstaff
                     password  = ABC123
Cashier login     -> user name = Cstaff
                     Password  = ABC567
Distributor login -> user name = Dstaff
                     password  = ABC987
*/
struct customerRegistration
{
    char firstName[20];
    char lastName[20];
    char nic[13];
    char mobileNo[11];
    char address1[20];
    char address2[20];
    char address3[20];
    char username[10];
    char password[10];
};

struct itemList
{
    char itemCode[10];
    char itemName[20];
    float unitPrice;
};
void welcomepage();
void printDate();
void loadingBar();
int readLoginType(int loginType);
int readCustomerLoginType(int customerLoginType);
void readCustomerRegistration(struct customerRegistration[], char *conpassword);
void customerLogin(char *cusername, char *cpassword);
int validateCustomerLogin(char *cusername, char *cpassword, int verifyCLogin, struct customerRegistration customer[]);
int displayCustomerMenu(struct customerRegistration customer[], int mainMenu, char *cusername);
int displaySeachItem(int searchItem);
int myCart(struct itemList sport[], struct itemList gift[], struct itemList luxury[], struct itemList school[], int removeItem, struct customerRegistration customer[], char *cusername);
int removeItemfromCart(struct itemList sport[], struct customerRegistration customer[], char *cusername);
float calucateTotal(struct itemList sport[], float total, float totalAmount, int quantity, char *cusername, struct customerRegistration customer[]);
float calculateDiscount(float totalAmount, float discount);
float calculateNetTotal(float totalAmount, float discount, float netTotal);
int printMyBill(struct itemList sport[], float total, float totalAmount, int quantity, float discount, float netTotal, char *cusername, struct customerRegistration customer[]);
void endOfCustomer();
void displaySportItem(struct itemList sport[], struct itemList gift[], struct itemList luxury[], struct itemList school[], int searchItem);
int displayAddToCart(int addToCart);
int readAddToCart(struct itemList sport[], struct itemList gift[], struct itemList luxury[], struct itemList school[], int exit, char *cusername, struct customerRegistration customer[], int mainMenu, int searchItem);
int displayManagerMenu(int mainMenu2);
void updateItem(struct itemList sport[], struct itemList gift[], struct itemList luxury[], struct itemList school[]);
void addItem(struct itemList sport[], struct itemList gift[], struct itemList luxury[], struct itemList school[]);
void deleteItem(struct itemList sport[], struct itemList gift[], struct itemList luxury[], struct itemList school[]);
int displayCashierMenu(int mainMenu3);
void orderList(struct itemList sport[], struct customerRegistration customer[]);
int displayDistributorrMenu(int mainMenu4);
void deliveryList(struct itemList sport[], struct customerRegistration customer[]);
void readCustomerDetails(struct customerRegistration customer[]);
int readFinish(int finish);
void readLogout();
int validateStaffLogin(char *username, char *password, int verifyStaffLogin);
int main()
{
    int loginType = 0;
    int customerLoginType = 0;
    struct customerRegistration customer[100];
    char cusername[12];
    char cpassword[10];
    int verifyCLogin = 0;
    int mainMenu = 0;
    int searchItem = 0;
    struct itemList sport[100];
    struct itemList gift[100];
    struct itemList luxury[100];
    struct itemList school[100];
    int removeItem = 0;
    int addToCart = 0;
    int addToCartAgain = 0;
    int exit = 0;
    int exit2 = 0;
    int confirmBill = 0;
    int staffLoginType = 0;
    int mainMenu2 = 0;
    int mainMenu3 = 0;
    int mainMenu4 = 0;
    int choice = 0;
    int end = 0;
    int finish = 0;
    int verifyStaffLogin = 0;
    char conpassword[10];
    int quantity = 0;
    int b = 0;
    int p = 0;

    char username[10];
    char password[10];

    float total = 0.0;
    float netTotal = 0.0;
    float discount = 0.0;
    float totalAmount = 0.0;

    system("COLOR 0B");
    welcomepage();
    printDate();
    system("cls");
    loadingBar();

    do
    {

        p = 0;
        system("cls");
        loginType = readLoginType(loginType);

        if (loginType == 2)
        {
            system("COLOR 0E");
            do
            {
                system("cls");
                customerLoginType = readCustomerLoginType(customerLoginType);
                if (customerLoginType == 1)
                {
                    do
                    {
                        system("cls");
                        customerLogin(&cusername, &cpassword);
                        verifyCLogin = validateCustomerLogin(&cusername, &cpassword, verifyCLogin, customer);
                        if (verifyCLogin == 1)
                        {
                            do
                            {
                                b = 0;
                                system("cls");
                                mainMenu = displayCustomerMenu(customer, mainMenu, &cusername);
                                switch (mainMenu)
                                {
                                case 1:

                                    do
                                    {
                                        system("cls");
                                        searchItem = displaySeachItem(searchItem);
                                        system("cls");
                                        displaySportItem(sport, gift, luxury, school, searchItem);
                                        addToCart = displayAddToCart(addToCart);
                                        if (addToCart == 1)
                                        {
                                            exit = readAddToCart(sport, gift, luxury, school, exit, &cusername, customer, mainMenu, searchItem);
                                            if (exit == 2)
                                            {
                                                b = 1;
                                            }
                                        }
                                        else if (addToCart == 2)
                                        {
                                            b = 1;
                                            exit = 2;
                                        }
                                        else
                                        {
                                            system("cls");
                                            printf("\n\n----------------------------------------------------\n\n");
                                            printf("                  Warning!!\n");
                                            printf("                Invalid Input!...\n");
                                            printf("\n\n----------------------------------------------------\n");
                                            printf("Enter any key to return..");
                                            getch();
                                        }
                                    } while (exit != 2);
                                    break;

                                case 2:
                                    system("cls");
                                    removeItem = myCart(sport, gift, luxury, school, removeItem, customer, &cusername);
                                    if (removeItem == 1)
                                    {
                                        choice = removeItemfromCart(sport, customer, &cusername);
                                        if (choice == 2)
                                        {
                                            b = 1;
                                        }
                                    }
                                    else
                                    {
                                        b = 1;
                                    }
                                    break;

                                case 3:
                                    system("cls");
                                    totalAmount = calucateTotal(sport, total, totalAmount, quantity, &cusername, customer);
                                    discount = calculateDiscount(totalAmount, discount);
                                    netTotal = calculateNetTotal(totalAmount, discount, netTotal);
                                    confirmBill = printMyBill(sport, total, totalAmount, quantity, discount, netTotal, &cusername, customer);
                                    if (confirmBill == 1)
                                    {
                                        b = 0;
                                        system("cls");
                                        endOfCustomer();
                                    }
                                    else
                                    {
                                        b = 1;
                                    }
                                    break;

                                case 4:
                                    b = 0;
                                    system("cls");
                                    endOfCustomer();
                                    break;

                                default:
                                    b = 1;
                                    system("cls");
                                    printf("\n\n----------------------------------------------------\n\n");
                                    printf("                  Warning!!\n");
                                    printf("                Invalid Input!...\n");
                                    printf("\n\n----------------------------------------------------\n");
                                    printf("Enter any key to return..");
                                    getch();
                                    break;
                                }
                            } while (b != 0);
                        }
                        else
                        {
                            system("cls");
                            printf("\n\n----------------------------------------------------\n\n");
                            printf("\t               Warning!!\n");
                            printf("\tUser name and Password mismatched..\n");
                            printf("\n\n----------------------------------------------------\n");
                            printf("Enter any key to return..");
                            getch();
                        }
                    } while (verifyCLogin != 1);
                }
                else if (customerLoginType == 2)
                {
                    system("cls");
                    readCustomerRegistration(customer, &conpassword);
                }
                else
                {
                    system("cls");
                    printf("\n\n----------------------------------------------------\n\n");
                    printf("\t               Warning!!\n");
                    printf("\t             Invalid Input!...\n");
                    printf("\n\n----------------------------------------------------\n");
                    printf("Enter any key to return..\n");
                    getch();
                }
            } while (customerLoginType != 1);
        }

        else if (loginType == 1)
        {

            int k = 0;
            do
            {
                system("cls");
                staffLogin(&username, &password);
                verifyStaffLogin = validateStaffLogin(&username, &password, verifyStaffLogin);
                if (verifyStaffLogin == 1)
                {
                    system("COLOR 0A");

                    do
                    {
                        system("cls");
                        mainMenu2 = displayManagerMenu(mainMenu2);

                        k = 0;
                        if (mainMenu2 == 1)
                        {
                            k = 1;
                            system("cls");
                            searchItem = displaySeachItem(searchItem);
                            system("cls");
                            displaySportItem(sport, gift, luxury, school, searchItem);
                            finish = readFinish(finish);
                        }
                        else if (mainMenu2 == 2)
                        {
                            k = 1;
                            system("cls");
                            updateItem(sport, gift, luxury, school);
                            finish = readFinish(finish);
                        }
                        else if (mainMenu2 == 3)
                        {
                            k = 1;
                            system("cls");
                            addItem(sport, gift, luxury, school);
                            finish = readFinish(finish);
                        }
                        else if (mainMenu2 == 4)
                        {
                            k = 1;
                            system("cls");
                            deleteItem(sport, gift, luxury, school);
                            finish = readFinish(finish);
                        }
                        else if (mainMenu2 == 5)
                        {
                            k = 0;
                        }
                        else
                        {
                            k = 1;
                            system("cls");
                            printf("\n\n----------------------------------------------------\n\n");
                            printf("\t               Warning!!\n");
                            printf("\t             Invalid Input!...\n");
                            printf("\n\n----------------------------------------------------\n");
                            printf("Enter any key to return..\n");
                            getch();
                        }
                    } while (k != 0);

                    system("cls");
                    readLogout();
                }

                else if (verifyStaffLogin == 2)
                {
                    system("COLOR 0C");
                    do
                    {
                        system("cls");
                        mainMenu3 = displayCashierMenu(mainMenu3);

                        if (mainMenu3 == 1)
                        {
                            system("cls");
                            searchItem = displaySeachItem(searchItem);
                            system("cls");
                            displaySportItem(sport, gift, luxury, school, searchItem);
                            finish = readFinish(finish);
                        }

                        else if (mainMenu3 == 2)
                        {
                            system("cls");
                            orderList(sport, customer);
                            finish = readFinish(finish);
                        }
                        else if (mainMenu3 == 3)
                        {
                            finish = 2;
                        }
                        else
                        {
                            finish = 1;
                            system("cls");
                            printf("\n\n----------------------------------------------------\n\n");
                            printf("\t               Warning!!\n");
                            printf("\t            Invalid Choice..\n");
                            printf("\n\n----------------------------------------------------\n");
                            printf("Enter any key to return..");
                            getch();
                        }
                    } while (finish == 1);

                    system("cls");
                    readLogout();
                }

                else if (verifyStaffLogin == 3)
                {
                    system("COLOR 0D");
                    do
                    {
                        system("cls");
                        mainMenu4 = displayDistributorrMenu(mainMenu4);
                        if (mainMenu4 == 1)
                        {
                            system("cls");
                            searchItem = displaySeachItem(searchItem);
                            system("cls");
                            displaySportItem(sport, gift, luxury, school, searchItem);
                            finish = readFinish(finish);
                        }
                        else if (mainMenu4 == 2)
                        {
                            system("cls");
                            deliveryList(sport, customer);
                            finish = readFinish(finish);
                        }
                        else if (mainMenu4 == 3)
                        {
                            system("cls");
                            readCustomerDetails(customer);
                            finish = readFinish(finish);
                        }
                        else if (mainMenu4 == 4)
                        {
                            finish = 2;
                        }
                        else
                        {
                            finish = 1;
                            system("cls");
                            printf("\n\n----------------------------------------------------\n\n");
                            printf("\t               Warning!!\n");
                            printf("\t             Invalid Choice..\n");
                            printf("\n\n----------------------------------------------------\n");
                            printf("Enter any key to return..");
                            getch();
                        }

                    } while (finish == 1);

                    system("cls");
                    readLogout();
                }
                else if (verifyStaffLogin == 4)
                {
                    system("COLOR 0B");
                    system("cls");
                    printf("\n\n----------------------------------------------------\n\n");
                    printf("\t                    Warning!!\n");
                    printf("\t            Invalid Username or Password..\n");
                    printf("\n\n----------------------------------------------------\n");
                    printf("Enter any key to return..");

                    getch();
                }
            } while (verifyStaffLogin == 4);
        }

        else
        {
            p = 1;
            system("cls");
            printf("\n\n----------------------------------------------------\n\n");
            printf("\t                 Warning!!\n");
            printf("\t              Invalid Choice..\n");
            printf("\n\n----------------------------------------------------\n");
            printf("Enter any key to return..");
            getch();
        }
    } while (p != 0);

    return 0;
}

void welcomepage()
{
    printf("############################################################################\n");
    printf("############            ONLINE SHOPPING SYSTEM                  ############\n");
    printf("############           C Programming project 01                 ############\n");
    printf("############################################################################\n\n\n");
    printf("\t\t");
    printf("\n\t\t\xDA");
    for (int i = 0; i < 50; i++)
    {
        printf("\xC4");
    }
    printf("\xBF");

    printf("\n\t\t\xB3                                                  \xB3");
    printf("\n\t\t\xB3                     WELCOME                      \xB3");
    printf("\n\t\t\xB3                        TO                        \xB3");
    printf("\n\t\t\xB3      **      ONLINE SHOPPING SYSTEM        **    \xB3");
    printf("\n\t\t\xB3                        OF                        \xB3");
    printf("\n\t\t\xB3                  DOLLAR DEALS                    \xB3");
    printf("\n\t\t\xB3                                                  \xB3");
    printf("\t\t");
    printf("\n\t\t\xC0");
    for (int i = 0; i < 50; i++)
    {
        printf("\xC4");
    }
    printf("\xD9");
}

void loadingBar()
{
    char a = 177, b = 219;
    printf("\n\n\t\t Loading...\n\n");
    printf("\t\t");

    for (int i = 0; i < 26; i++)
        printf("%c", a);

    printf("\r");
    printf("\t\t");

    for (int i = 0; i < 26; i++)
    {
        printf("%c", b);

        Sleep(20);
    }
}

int readLoginType(int loginType)
{
    printf("\t*********************************************************************\n");
    printf("                       **   DOLLAR DEALS SUPERMARKET   **\n");
    printf("\t*********************************************************************\n");
    printf("\n\t\t====================================================\n");
    printf("\t\t            1. Staff Login\n");
    printf("\t\t            2. Customer Login\n");
    printf("\t\t====================================================\n");
    printf("\t\tEnter your Choice (1/2) :");
    scanf("%d", &loginType);
    printf("\n\n");

    return loginType;
}

void printDate()
{
    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);
    int m;
    printf("\n\t\t%d ", tm.tm_mday);
    m = tm.tm_mon + 1;
    switch (m)
    {
    case 1:
        printf("Jan, ");
        break;
    case 2:
        printf("Feb, ");
        break;
    case 3:
        printf("Mar, ");
        break;
    case 4:
        printf("Apr, ");
        break;
    case 5:
        printf("May, ");
        break;
    case 6:
        printf("June, ");
        break;
    case 7:
        printf("July, ");
        break;
    case 8:
        printf("Aug, ");
        break;
    case 9:
        printf("Sep, ");
        break;
    case 10:
        printf("Oct, ");
        break;
    case 11:
        printf("Nov, ");
        break;
    case 12:
        printf("Dec, ");
        break;
    }
    printf("%d", tm.tm_year + 1900);
    printf(" ");
    if (tm.tm_hour >= 12)
    {
        if (tm.tm_hour == 12)
            printf("12");
        else
            printf("%d", tm.tm_hour - 12);
        printf(":%d:%d PM", tm.tm_min, tm.tm_sec);
    }
    else
        printf("%d:%d:%d AM", tm.tm_hour, tm.tm_min, tm.tm_sec);
    printf("\n\t\tEnter any key to continue...");
    getch();
}

int readCustomerLoginType(int customerLoginType)
{
    printf("\t*********************************************************************\n");
    printf("                       **   DOLLAR DEALS SUPERMARKET   **\n");
    printf("\t*********************************************************************\n");
    printf("\n\t\t====================================================\n");
    printf("\t\t            1. Registered Customer\n");
    printf("\t\t            2. Not registered Customer\n");
    printf("\t\t====================================================\n");
    printf("\t\tEnter your Choice (1/2) :");
    scanf("%d", &customerLoginType);

    return customerLoginType;
}

void readCustomerRegistration(struct customerRegistration customer[], char *conpassword)
{
    int lenght = 0;
    int a = 0;

    FILE *filewrite;

    printf("\t*********************************************************************\n");
    printf("                       **   DOLLAR DEALS SUPERMARKET   **\n");
    printf("\t*********************************************************************\n");

    filewrite = fopen("custmerdetails.txt", "a");
    printf("\n\t\t----------------------------------------------------\n");
    printf("\t\t");
    for (int i = 0; i < 15; i++)
    {
        printf("\xB2");
    }
    printf(" Customer Registration ");
    for (int i = 0; i < 14; i++)
    {
        printf("\xB2");
    }
    printf("\n\t\t----------------------------------------------------\n");
    printf("\t\tIntroduction:\n");
    printf("\t\t             * Enter your details without using spaces..\n");
    printf("\t\t             * Use (_) for spaces..\n");
    printf("\t\t----------------------------------------------------\n");
    printf("\t\tEnter your First Name       : ");
    scanf("%s", &customer[0].firstName);
    printf("\t\tEnter your Last Name        : ");
    scanf("%s", &customer[0].lastName);
    printf("\n");
    do
    {
        a = 0;
        printf("\t\tEnter your NIC number       : ");
        scanf("%s", &customer[0].nic);

        lenght = strlen(customer[0].nic);
        if (lenght != 10 && lenght != 12)
        {
            printf("\n\t\tInvalid NIC number!!..\n");
            a = 1;
        }
        else if (lenght == 10)
        {
            if (customer[0].nic[9] == 'V' || customer[0].nic[9] == 'v')
            {
                a = 2;
            }
            else
            {
                printf("\n\t\tInvalid NIC number!!..\n");
                a = 1;
            }
        }
        else if (lenght == 12)
        {
            if ((customer[0].nic[0] == '1' && customer[0].nic[1] == '9') || (customer[0].nic[0] == '2' && customer[0].nic[1] == '0'))
            {
                a = 2;
            }
            else
            {
                printf("\n\t\tInvalid NIC number!!..\n");
                a = 1;
            }
        }
        else
        {
            a = 2;
        }

    } while (a != 2);

    printf("\n");
    do
    {
        a = 0;
        printf("\t\tEnter your Mobile number    : ");
        scanf("%s", &customer[0].mobileNo);

        lenght = strlen(customer[0].mobileNo);
        if (lenght != 10)
        {
            printf("\n\t\tInvalid Mobile number!!..\n");
            a = 1;
        }
        else
        {
            if (customer[0].mobileNo[0] == '0' && customer[0].mobileNo[1] == '7')
            {
                a = 2;
            }

            else
            {
                printf("\n\t\tInvalid Mobile number!!..\n");
                a = 1;
            }
        }

    } while (a != 2);

    printf("\n");
    printf("\t\t----------------------------------------------------\n");
    printf("\t\tAddress should be written in 3 lines...\n");
    printf("\t\t----------------------------------------------------\n");
    printf("\t\tEnter your Address(line 1)  : ");
    scanf("%s", &customer[0].address1);
    printf("\t\tEnter your Address(line 2)  : ");
    scanf("%s", &customer[0].address2);
    printf("\t\tEnter your Address(line 3)  : ");
    scanf("%s", &customer[0].address3);
    printf("\t\t----------------------------------------------------\n");
    printf("\t\tDetails Recorded SUCCESSFULLY!!\n");
    printf("\t\t----------------------------------------------------\n");
    printf("\t\tEnter any key to continue..");
    getch();

    system("cls");
    printf("\t\t----------------------------------------------------\n");
    printf("\t\t\t          Create Account...\n");
    printf("\t\t----------------------------------------------------\n");
    printf("\t\t*Username and password both should have minimum four \n\t\t characters and maximum eight characters..\n\n");

    do
    {
        printf("\t\tEnter a username : ");
        scanf("%s", &customer[0].username);

        lenght = strlen(customer[0].username);
        if (lenght > 8 || lenght < 4)
        {
            printf("\n\t\tInvalid Username format!!..\n");
            a = 1;
        }
        else
            a = 2;
    } while (a != 2);

    printf("\n");

    do
    {
        printf("\t\tEnter a Password : ");
        scanf("%s", &customer[0].password);

        lenght = strlen(customer[0].password);
        if (lenght > 8 || lenght < 4)
        {
            printf("\n\t\tInvalid Password format!!..\n");
            a = 1;
        }
        else
            a = 2;
    } while (a != 2);
    printf("\n");
    do
    {
        printf("\t\tConfirm password : ");
        scanf("%s", conpassword);
        if (strcmp(conpassword, customer[0].password) == 0)
        {
            a = 2;
        }
        else
        {
            printf("\n\t\tPasswords Mismatched!!..\n");
            a = 1;
        }
    } while (a != 2);

    printf("\n");
    printf("\t\t----------------------------------------------------\n");
    printf("\t\tAccount Created SUCCESSFULLY!!\n");
    printf("\t\t----------------------------------------------------\n");
    fprintf(filewrite, "%s %s %s %s %s %s %s %s %s\n", customer[0].firstName, customer[0].lastName, customer[0].nic, customer[0].mobileNo, customer[0].address1, customer[0].address2, customer[0].address3, customer[0].username, customer[0].password);
    fclose(filewrite);

    printf("\t\tEnter any key to Login..");
    getch();
}

void customerLogin(char *cusername, char *cpassword)
{
    printf("\t*********************************************************************\n");
    printf("                       **   DOLLAR DEALS SUPERMARKET   **\n");
    printf("\t*********************************************************************\n");
    printf("\t\t");
    for (int i = 0; i < 15; i++)
    {
        printf("\xB2");
    }
    printf(" Customer Login ");
    for (int i = 0; i < 14; i++)
    {
        printf("\xB2");
    }
    printf("\n\n                Username  :");
    scanf("%s", cusername);
    printf("                Password  :");
    scanf("%s", cpassword);
}

int validateCustomerLogin(char *cusername, char *cpassword, int verifyCLogin, struct customerRegistration customer[])
{
    FILE *filereader;

    filereader = fopen("custmerdetails.txt", "r");

    int i = 0;
    while (fscanf(filereader, "%s %s %s %s %s %s %s %s %s", &customer[i].firstName, &customer[i].lastName, &customer[i].nic, &customer[i].mobileNo, &customer[i].address1, &customer[i].address2, &customer[i].address3, &customer[i].username, &customer[i].password) != EOF)
    {
        if ((strcmp(cusername, customer[i].username) == 0) && (strcmp(cpassword, customer[i].password) == 0))
        {
            verifyCLogin = 1;
            system("cls");
            printf("\t\t******************************************************\n");
            printf("\t\t                **   DOLLAR DEALS SUPERMARKET   **\n");
            printf("\t\t******************************************************\n");
            printf("\n\n\t\t----------------------------------------------------\n\n");
            printf("\t\t                      Customer Login..\n");
            printf("\t\t            SUCCESSFULLY LOGIN TO THE SYSTEM!!\n");
            printf("\n\n\t\t----------------------------------------------------\n");
            printf("\t\tEnter any key to continue..");
            getch();
        }
        i++;
    }

    fclose(filereader);

    return verifyCLogin;
}

int displayCustomerMenu(struct customerRegistration customer[], int mainMenu, char *cusername)
{
    FILE *filereader;

    filereader = fopen("custmerdetails.txt", "r");

    printf("\t\t******************************************************\n");
    printf("\t\t                **   DOLLAR DEALS SUPERMARKET   **\n");
    printf("\t\t******************************************************\n");
    printf("\n\t\t====================================================\n");
    printf("\n\t\t\xDA");
    for (int i = 0; i < 50; i++)
    {
        printf("\xC4");
    }
    printf("\xBF");

    int i = 0;
    while (fscanf(filereader, "%s %s %s %s %s %s %s %s %s", &customer[i].firstName, &customer[i].lastName, &customer[i].nic, &customer[i].mobileNo, &customer[i].address1, &customer[i].address2, &customer[i].address3, &customer[i].username, &customer[i].password) != EOF)
    {
        if (strcmp(cusername, customer[i].username) == 0)
        {
            printf("\n\t\t\xB3            Hi %10s %10s..            \xB3\n", customer[i].firstName, customer[i].lastName);
        }
        i++;
    }

    fclose(filereader);

    printf("\t\t\xB3     WELCOME TO OUR ONLINE SHOPPING CENTRE..      \xB3\n");
    printf("\t\t");
    printf("\xC0");
    for (int i = 0; i < 50; i++)
    {
        printf("\xC4");
    }
    printf("\xD9");
    printf("\n\t\t====================================================\n");
    printf("\t\t\t\t1 - Search Item\n");
    printf("\t\t\t\t2 - My Cart\n");
    printf("\t\t\t\t3 - My Bill\n");
    printf("\t\t\t\t4 - Exit\n");
    printf("\t\t====================================================\n");
    printf("\t\tWhat are you looking for?\n");
    printf("\t\tEnter your choice(1/2/3) :");
    scanf("%d", &mainMenu);

    return mainMenu;
}

int displaySeachItem(int searchItem)
{
    int ch = 176;
    printf("\t\t******************************************************\n");
    printf("\t\t                **   DOLLAR DEALS SUPERMARKET   **\n");
    printf("\t\t******************************************************\n\n");
    printf("\t\t");
    for (int i = 0; i < 20; i++)
    {
        printf("%c", ch);
    }
    printf(" SEARCH ITEM ");
    for (int i = 0; i < 21; i++)
    {
        printf("%c", ch);
    }
    printf("\n\n\t\t----------------------------------------------------\n");
    printf("\t\t\t\t[1] - Sport Item\n");
    printf("\t\t\t\t[2] - Gift Item\n");
    printf("\t\t\t\t[3] - Luxury Item\n");
    printf("\t\t\t\t[4] - School Item\n");
    printf("\t\t----------------------------------------------------\n");
    printf("\t\tWhat are you looking for?\n");
    printf("\t\tEnter your choice(1/2/3/4) :");
    scanf("%d", &searchItem);

    return searchItem;
}

int myCart(struct itemList sport[], struct itemList gift[], struct itemList luxury[], struct itemList school[], int removeItem, struct customerRegistration customer[], char *cusername)
{
    FILE *filecart;

    int ch = 219;
    int i = 0;
    int quantity = 0;
    float total = 0.0;

    printf("********************************************************************************\n");
    printf("                         **   DOLLAR DEALS SUPERMARKET   **\n");
    printf("********************************************************************************\n");

    for (int i = 0; i < 35; i++)
    {
        printf("%c", ch);
    }
    printf(" MY CART ");
    for (int i = 0; i < 35; i++)
    {
        printf("%c", ch);
    }

    printf("\n\n===============================================================================\n");
    printf("  Item Code      |         Item Name      |   Quantity    |    Unit Price\n");
    printf("===============================================================================\n");

    filecart = fopen("mycart.txt", "r");

    while (fscanf(filecart, "%s %s %s %f %d %f\n", &customer[i].username, &sport[i].itemCode, &sport[i].itemName, &sport[i].unitPrice, &quantity, &total) != EOF)
    {
        if (strcmp(cusername, customer[i].username) == 0)
        {
            printf("  %5s          |%20s    |     %3d       |      %.2f\n", sport[i].itemCode, sport[i].itemName, quantity, sport[i].unitPrice);
        }
        i++;
    }

    fclose(filecart);

    printf("===============================================================================\n");
    printf("Do you want to remove any item?\n");
    printf("    [1] -> Yes\n");
    printf("    [2] -> No\n");
    printf("Enter your choice(1/2) : ");
    scanf("%d", &removeItem);

    return removeItem;
}

int removeItemfromCart(struct itemList sport[], struct customerRegistration customer[], char *cusername)
{
    FILE *fileremove;
    FILE *tempfile;

    char code[10];
    int a = 0;
    int choice = 0;
    int i = 0;
    int quantity = 0;
    float total = 0.0;

    do
    {
        system("cls");
        printf("\t*********************************************************************\n");
        printf("                       **   DOLLAR DEALS SUPERMARKET   **\n");
        printf("\t*********************************************************************\n");
        printf("\n\t\t----------------------------------------------------\n");
        printf("\t\t\t\tRemove Item..\n");
        printf("\t\t----------------------------------------------------\n");

        fileremove = fopen("mycart.txt", "r");
        tempfile = fopen("tempfile.txt", "a");

        printf("\n\t\t******************************************************\n");
        printf("\t\tEnter item code : ");
        scanf("%s", &code);
        a = 0;
        while (fscanf(fileremove, "%s %s %s %f %d %f\n", &customer[i].username, &sport[i].itemCode, &sport[i].itemName, &sport[i].unitPrice, &quantity, &total) != EOF)
        {
            if (strcmp(cusername, customer[i].username) == 0)
            {
                if (strcmp(code, sport[i].itemCode) == 0)
                {
                    a = 1;
                }
                else
                {
                    fprintf(tempfile, "%s %s %s %.2f %d %.2f\n", customer[i].username, sport[i].itemCode, sport[i].itemName, sport[i].unitPrice, quantity, total);
                }
            }
            else
            {
                fprintf(tempfile, "%s %s %s %.2f %d %.2f\n", customer[i].username, sport[i].itemCode, sport[i].itemName, sport[i].unitPrice, quantity, total);
            }
            i++;
        }
        printf("\t\t-----------------------\n");
        fclose(fileremove);
        fclose(tempfile);
        remove("mycart.txt");
        rename("tempfile.txt", "mycart.txt");
        if (a == 1)
        {
            printf("\n\t\t******************************************************\n");
            printf("\t\tItem removed SUCCESSFULLY!!\n");
            printf("\t\t******************************************************\n");
            printf("\t\tEnter any key to continue...");
            getch();
        }
        else
        {
            printf("\n\t\t******************************************************\n");
            printf("\t\tRecord not found!!..\n");
            printf("\t\t******************************************************\n");
            printf("\t\tEnter any key to return..");
            getch();
        }

        printf("\n\n\t\tDo you want to remove another item from your cart?\n");
        printf("\t\t    [1] -> Yes\n");
        printf("\t\t    [2] -> No\n");
        printf("\t\tEnter your choice(1/2) :");
        scanf("%d", &choice);
    } while (choice != 2);

    return choice;
}

float calucateTotal(struct itemList sport[], float total, float totalAmount, int quantity, char *cusername, struct customerRegistration customer[])
{
    totalAmount = 0.0;

    FILE *filebill;

    filebill = fopen("mycart.txt", "r");

    int i = 0;
    while (fscanf(filebill, "%s %s %s %f %d %f\n", &customer[i].username, &sport[i].itemCode, &sport[i].itemName, &sport[i].unitPrice, &quantity, &total) != EOF)
    {
        if (strcmp(cusername, customer[i].username) == 0)
        {
            totalAmount += total;
        }
        i++;
    }
    fclose(filebill);

    return totalAmount;
}

float calculateDiscount(float totalAmount, float discount)
{
    if (totalAmount >= 5000)
    {
        discount = totalAmount * 0.2;
    }
    else
    {
        discount = 0;
    }

    return discount;
}

float calculateNetTotal(float totalAmount, float discount, float netTotal)
{
    netTotal = totalAmount - discount;

    return netTotal;
}

int printMyBill(struct itemList sport[], float total, float totalAmount, int quantity, float discount, float netTotal, char *cusername, struct customerRegistration customer[])
{
    FILE *filebill;

    int confirmBill = 0;

    filebill = fopen("mycart.txt", "r");

    int ch = 219;

    printf("****************************************************************************\n");
    printf("                **   DOLLAR DEALS SUPERMARKET   **\n");
    printf("****************************************************************************\n");
    printf("\n");
    for (int i = 0; i < 33; i++)
    {
        printf("%c", ch);
    }
    printf(" MY BILL ");
    for (int i = 0; i < 34; i++)
    {
        printf("%c", ch);
    }
    printf("\n\n============================================================================\n");
    printf("Item Code |         Item Name       |  Unit Price  | Quantity  |   Total\n");
    printf("============================================================================\n");

    int i = 0;
    while (fscanf(filebill, "%s %s %s %f %d %f\n", &customer[i].username, &sport[i].itemCode, &sport[i].itemName, &sport[i].unitPrice, &quantity, &total) != EOF)
    {
        if (strcmp(cusername, customer[i].username) == 0)
        {
            printf("  %5s   |%15s          |   %.2f     |     %d     |   %.2f\n", sport[i].itemCode, sport[i].itemName, sport[i].unitPrice, quantity, total);
        }
        i++;
    }

    fclose(filebill);

    printf("============================================================================\n");
    printf("Total \t\t\t\t\t\t\t          %.2f\n", totalAmount);
    printf("Discount Recieved\t\t\t\t\t\t   %.2f\n", discount);
    printf("============================================================================\n");
    printf("Total Amount to be paid \t\t\t\t          %.2f\n", netTotal);
    printf("============================================================================\n");
    printf("Are you confirm your payment?\n");
    printf("    [1] -> Yes\n");
    printf("    [2] -> No\n");
    printf("Enter your choice(1/2) : ");
    scanf("%d", &confirmBill);

    return confirmBill;
}

int myBill(struct itemList sport[], struct itemList gift[], struct itemList luxury[], struct itemList school[], float netTotal, float discount, float totalAmount, int confirmBill)
{
    int ch = 219;

    printf("\n");
    for (int i = 0; i < 33; i++)
    {
        printf("%c", ch);
    }
    printf(" MY BILL ");
    for (int i = 0; i < 34; i++)
    {
        printf("%c", ch);
    }
    printf("\n\n============================================================================\n");
    printf("Item Code |    Item Name       |  Unit Price  | Quantity  |   Total\n");
    printf("============================================================================\n");
    printf(" %4d     |  %10s  |   %.2f     |    2      |  %.2f\n", sport[0].itemCode, sport[0].itemName, sport[0].unitPrice, sport[0].unitPrice);
    printf(" %4d     |  %10s        |  %.2f     |    1      |  %.2f\n", gift[0].itemCode, gift[0].itemName, gift[0].unitPrice, gift[0].unitPrice);
    printf(" %4d     |  %10s      |  %.2f     |    1      |  %.2f\n", luxury[0].itemCode, luxury[0].itemName, luxury[0].unitPrice, luxury[0].unitPrice);
    printf(" %4d     |  %10s        |  %.2f     |    1      |  %.2f\n", school[0].itemCode, school[0].itemName, school[0].unitPrice, school[0].unitPrice);
    printf("============================================================================\n");
    printf("Total \t\t\t\t\t\t\t      %.2f\n", netTotal);
    printf("Discount Recieved\t\t\t\t\t      %.2f\n", discount);
    printf("============================================================================\n");
    printf("Total Amount to be paid \t\t\t\t      %.2f\n", totalAmount);
    printf("============================================================================\n");
    printf("Are you confirm your payment?\n");
    printf("    [1] -> Yes\n");
    printf("    [2] -> No\n");
    printf("Enter your choice(1/2) :");
    scanf("%d", &confirmBill);

    return confirmBill;
}

void endOfCustomer()
{
    printf("\t\t******************************************************\n");
    printf("\t\t                **   DOLLAR DEALS SUPERMARKET   **\n");
    printf("\t\t******************************************************\n\n");
    printf("\t\tThank you for choosing DOLLAR DEALS SUPERMARKET\n");
    printf("\t\t------------------------------------------------------\n\n");
    printf("\t\tYour Order will deliver soon...\n");
    printf("\t\tCome Back again!\n");
    printf("\t\t------------------------------------------------------\n\n");
    printf("\t\tEnter to Logout...\n\n");
    getch();
}

void displaySportItem(struct itemList sport[], struct itemList gift[], struct itemList luxury[], struct itemList school[], int searchItem)
{
    FILE *itemlist;

    int a = 0;

    do
    {
        a = 0;
        system("cls");
        printf("****************************************************************************\n");
        printf("                **   DOLLAR DEALS SUPERMARKET   **\n");
        printf("****************************************************************************\n");

        if (searchItem == 1)
        {
            a = 0;
            itemlist = fopen("sportitem.txt", "r");

            int ch = 219;

            printf("\n");
            for (int i = 0; i < 32; i++)
            {
                printf("%c", ch);
            }
            printf(" SPORT ITEM ");
            for (int i = 0; i < 32; i++)
            {
                printf("%c", ch);
            }

            printf("\n\n============================================================================\n");
            printf("  Item Code      |     Item Name              |    Unit Price\n");
            printf("============================================================================\n");

            int i = 0;
            while (fscanf(itemlist, "%s %s %f\n", &sport[i].itemCode, sport[i].itemName, &sport[i].unitPrice) != EOF)
            {
                printf("  %5s          |%20s        |       %.2f\n", sport[i].itemCode, sport[i].itemName, sport[i].unitPrice);
                i++;
            }
            printf("============================================================================\n");
            printf("Every Item above Rs.5000 will receive a 20%% discount.\n\n");
            printf("============================================================================\n");

            fclose(itemlist);
        }

        else if (searchItem == 2)
        {
            a = 0;
            itemlist = fopen("giftitem.txt", "r");

            int ch = 219;

            printf("\n");
            for (int i = 0; i < 32; i++)
            {
                printf("%c", ch);
            }
            printf(" GIFT ITEM ");
            for (int i = 0; i < 32; i++)
            {
                printf("%c", ch);
            }

            printf("\n\n============================================================================\n");
            printf("  Item Code      |     Item Name              |    Unit Price\n");
            printf("============================================================================\n");

            int i = 0;
            while (fscanf(itemlist, "%s %s %f\n", &gift[i].itemCode, gift[i].itemName, &gift[i].unitPrice) != EOF)
            {
                printf("  %5s          |%20s        |       %.2f\n", gift[i].itemCode, gift[i].itemName, gift[i].unitPrice);
                i++;
            }
            printf("============================================================================\n");
            printf("Every Item above Rs.5000 will receive a 20%% discount.\n\n");
            printf("============================================================================\n");

            fclose(itemlist);
        }

        else if (searchItem == 3)
        {
            a = 0;
            itemlist = fopen("luxuryitem.txt", "r");

            int ch = 219;

            printf("\n");
            for (int i = 0; i < 32; i++)
            {
                printf("%c", ch);
            }
            printf(" LUXURY ITEM ");
            for (int i = 0; i < 32; i++)
            {
                printf("%c", ch);
            }

            printf("\n\n============================================================================\n");
            printf("  Item Code      |     Item Name              |    Unit Price\n");
            printf("============================================================================\n");

            int i = 0;
            while (fscanf(itemlist, "%s %s %f\n", &luxury[i].itemCode, luxury[i].itemName, &luxury[i].unitPrice) != EOF)
            {
                printf("  %5s          |%20s        |       %.2f\n", luxury[i].itemCode, luxury[i].itemName, luxury[i].unitPrice);
                i++;
            }
            printf("============================================================================\n");
            printf("Every Item above Rs.5000 will receive a 20%% discount.\n\n");
            printf("============================================================================\n");

            fclose(itemlist);
        }

        else if (searchItem == 4)
        {
            a = 0;
            itemlist = fopen("schoolitem.txt", "r");

            int ch = 219;

            printf("\n");
            for (int i = 0; i < 32; i++)
            {
                printf("%c", ch);
            }
            printf(" SCHOOL ITEM ");
            for (int i = 0; i < 32; i++)
            {
                printf("%c", ch);
            }

            printf("\n\n============================================================================\n");
            printf("  Item Code      |     Item Name              |    Unit Price\n");
            printf("============================================================================\n");

            int i = 0;
            while (fscanf(itemlist, "%s %s %f\n", &school[i].itemCode, school[i].itemName, &school[i].unitPrice) != EOF)
            {
                printf("  %5s          |%20s        |       %.2f\n", school[i].itemCode, school[i].itemName, school[i].unitPrice);
                i++;
            }
            printf("============================================================================\n");
            printf("Every Item above Rs.5000 will receive a 20%% discount.\n\n");
            printf("============================================================================\n");

            fclose(itemlist);
        }
        else
        {
            a = 1;
            system("cls");
            printf("\n\n----------------------------------------------------\n\n");
            printf("                     Warning!!\n");
            printf("                  Invalid Input..\n");
            printf("\n\n----------------------------------------------------\n");
            printf("Enter any key to return..");
            getch();
            system("cls");
            searchItem = displaySeachItem(searchItem);
        }
    } while (a != 0);
}
int displayAddToCart(int addToCart)
{
    printf("Do you want to add any item to cart?\n");
    printf("    1 -> Yes\n");
    printf("    2 -> No\n");
    printf("Enter your choice(1/2) :");
    scanf("%d", &addToCart);

    return addToCart;
}

int readAddToCart(struct itemList sport[], struct itemList gift[], struct itemList luxury[], struct itemList school[], int exit, char *cusername, struct customerRegistration customer[], int mainMenu, int searchItem)
{
    FILE *addtocart;
    FILE *filereader;
    FILE *customerreader;

    char code[10];
    int quantity = 0;
    int a = 0;
    float total = 0.0;

    do
    {
        a = 0;
        if (searchItem == 1)
        {
            printf("\n\n******************************************************\n");
            printf("Enter item code : ");
            scanf("%s", &code);

            addtocart = fopen("mycart.txt", "a");
            filereader = fopen("sportitem.txt", "r");
            customerreader = fopen("custmerdetails.txt", "r");

            int i = 0;
            while (fscanf(filereader, "%s %s %f\n", &sport[i].itemCode, &sport[i].itemName, &sport[i].unitPrice) != EOF)
            {

                if (strcmp(code, sport[i].itemCode) == 0)
                {
                    a = 1;
                    printf("Quantity        : ");
                    scanf("%d", &quantity);

                    total = sport[i].unitPrice * quantity;

                    fprintf(addtocart, "%s %s %s %.2f %d %.2f\n", cusername, sport[i].itemCode, sport[i].itemName, sport[i].unitPrice, quantity, total);
                }
                i++;
            }

            fclose(customerreader);
            fclose(filereader);
            fclose(addtocart);
        }

        if (searchItem == 2)
        {
            printf("\n\n******************************************************\n");
            printf("Enter item code : ");
            scanf("%s", &code);

            addtocart = fopen("mycart.txt", "a");
            filereader = fopen("giftitem.txt", "r");
            customerreader = fopen("custmerdetails.txt", "r");

            int i = 0;
            while (fscanf(filereader, "%s %s %f\n", &gift[i].itemCode, &gift[i].itemName, &gift[i].unitPrice) != EOF)
            {

                if (strcmp(code, gift[i].itemCode) == 0)
                {
                    a = 1;
                    printf("Quantity        : ");
                    scanf("%d", &quantity);

                    total = gift[i].unitPrice * quantity;

                    fprintf(addtocart, "%s %s %s %.2f %d %.2f\n", cusername, gift[i].itemCode, gift[i].itemName, gift[i].unitPrice, quantity, total);
                }
                i++;
            }

            fclose(customerreader);
            fclose(filereader);
            fclose(addtocart);
        }

        if (searchItem == 3)
        {
            printf("\n\n******************************************************\n");
            printf("Enter item code : ");
            scanf("%s", &code);

            addtocart = fopen("mycart.txt", "a");
            filereader = fopen("luxuryitem.txt", "r");
            customerreader = fopen("custmerdetails.txt", "r");

            int i = 0;
            while (fscanf(filereader, "%s %s %f\n", &luxury[i].itemCode, &luxury[i].itemName, &luxury[i].unitPrice) != EOF)
            {

                if (strcmp(code, luxury[i].itemCode) == 0)
                {
                    a = 1;
                    printf("Quantity        : ");
                    scanf("%d", &quantity);

                    total = luxury[i].unitPrice * quantity;

                    fprintf(addtocart, "%s %s %s %.2f %d %.2f\n", cusername, luxury[i].itemCode, luxury[i].itemName, luxury[i].unitPrice, quantity, total);
                }
                i++;
            }

            fclose(customerreader);
            fclose(filereader);
            fclose(addtocart);
        }

        if (searchItem == 4)
        {
            printf("\n\n******************************************************\n");
            printf("Enter item code : ");
            scanf("%s", &code);

            addtocart = fopen("mycart.txt", "a");
            filereader = fopen("schoolitem.txt", "r");
            customerreader = fopen("custmerdetails.txt", "r");

            int i = 0;
            while (fscanf(filereader, "%s %s %f\n", &school[i].itemCode, &school[i].itemName, &school[i].unitPrice) != EOF)
            {

                if (strcmp(code, school[i].itemCode) == 0)
                {
                    a = 1;
                    printf("Quantity        : ");
                    scanf("%d", &quantity);

                    total = school[i].unitPrice * quantity;

                    fprintf(addtocart, "%s %s %s %.2f %d %.2f\n", cusername, school[i].itemCode, school[i].itemName, school[i].unitPrice, quantity, total);
                }
                i++;
            }

            fclose(customerreader);
            fclose(filereader);
            fclose(addtocart);
        }

        if (a == 1)
        {
            printf("\n******************************************************\n");
            printf("Item add to cart SUCCESSFULLY!!\n");
            printf("******************************************************\n");
            printf("Enter any key to continue...");
            getch();
        }
        else
        {
            printf("\n******************************************************\n");
            printf("Record not found!!..\n");
            printf("******************************************************\n");
            printf("Enter any key to return...");
            getch();
        }
    } while (a != 1);

    fclose(filereader);
    fclose(addtocart);

    system("cls");
    printf("\t\t******************************************************\n");
    printf("\t\t                **   DOLLAR DEALS SUPERMARKET   **\n");
    printf("\t\t******************************************************\n\n");
    printf("\t\t------------------------------------------------------\n");
    printf("\t\tDo you want to add another item to cart?\n");
    printf("\t\t    [1] -> Yes\n");
    printf("\t\t    [2] -> No\n");
    printf("\t\t------------------------------------------------------\n");
    printf("\t\tEnter your choice(1/2) : ");
    scanf("%d", &exit);

    return exit;
}

void staffLogin(char *username, char *password)
{

    printf("------------------ Staff Login ----------------------\n");
    printf("            Username : ");
    scanf("%s", username);
    printf("            Password : ");
    scanf("%s", password);
    printf("----------------------------------------------------\n");
}

int validateStaffLogin(char *username, char *password, int verifyStaffLogin)
{
    char managerUsername[10] = "Mstaff";
    char managerPassword[10] = "ABC123";
    char cashierUsername[10] = "Cstaff";
    char cashierPassword[10] = "ABC567";
    char distributorUsername[10] = "Dstaff";
    char distributorPassword[10] = "ABC987";

    if (strcmp(username, managerUsername) == 0 && strcmp(password, managerPassword) == 0)
    {

        verifyStaffLogin = 1;
        system("cls");
        system("COLOR 0A");
        printf("\n\n----------------------------------------------------\n\n");
        printf("                      Manager Login..\n");
        printf("            SUCCESSFULLY LOGIN TO THE SYSTEM!!\n");
        printf("\n\n----------------------------------------------------\n");
        printf("Enter any key to continue..");
        getch();
    }
    else if ((strcmp(username, cashierUsername) == 0) && (strcmp(password, cashierPassword) == 0))
    {
        verifyStaffLogin = 2;
        system("cls");
        system("COLOR 0C");
        printf("\n\n----------------------------------------------------\n\n");
        printf("                     Cashier Login..\n");
        printf("            SUCCESSFULLY LOGIN TO THE SYSTEM!!\n");
        printf("\n\n----------------------------------------------------\n");
        printf("Enter any key to continue..");
        getch();
    }
    else if ((strcmp(username, distributorUsername) == 0) && (strcmp(password, distributorPassword) == 0))
    {
        verifyStaffLogin = 3;
        system("cls");
        system("COLOR 0D");
        printf("\n\n----------------------------------------------------\n\n");
        printf("                     Distributor Login..\n");
        printf("            SUCCESSFULLY LOGIN TO THE SYSTEM!!\n");
        printf("\n\n----------------------------------------------------\n");
        printf("Enter any key to continue..");
        getch();
    }
    else
    {
        verifyStaffLogin = 4;
    }

    return verifyStaffLogin;
}

int ReadStaffLoginType(int staffLoginType)
{
    printf("====================================================\n");
    printf("            1. Manager\n");
    printf("            2. Cashier\n");
    printf("            3. Distributor\n");
    printf("====================================================\n");
    printf("Enter your Choice (1/2/3) :");
    scanf("%d", &staffLoginType);

    return staffLoginType;
}

int displayManagerMenu(mainMenu2)
{
    printf("\n\t\t******************************************************\n");
    printf("\t\t                **   DOLLAR DEALS SUPERMARKET   **\n");
    printf("\t\t******************************************************\n\n");

    printf("\t\t----------------------------------------------------\n");
    printf("\t\t                      Hi Manager..  \n");
    printf("\t\t        WELCOME TO OUR ONLINE SHOPPING CENTRE..\n");
    printf("\t\t----------------------------------------------------\n");
    printf("\t\t====================================================\n");
    printf("\t\t\t\t[1] - Display Item List\n");
    printf("\t\t\t\t[2] - Update Item\n");
    printf("\t\t\t\t[3] - Add Item\n");
    printf("\t\t\t\t[4] - Delete Item\n");
    printf("\t\t\t\t[5] - Exit\n");
    printf("\t\t====================================================\n");
    printf("\t\tWhat are you looking for?\n");
    printf("\t\tEnter your choice(1/2/3) :");
    scanf("%d", &mainMenu2);

    return mainMenu2;
}

void updateItem(struct itemList sport[], struct itemList gift[], struct itemList luxury[], struct itemList school[])
{
    FILE *updatefile;
    FILE *tempfile;

    int choice = 0;
    int select = 0;
    char code[10];
    int a = 0;
    int b = 0;

    do
    {
        do
        {
            b = 0;
            system("cls");
            printf("\t\t******************************************************\n");
            printf("\t\t                **   DOLLAR DEALS SUPERMARKET   **\n");
            printf("\t\t******************************************************\n\n");
            printf("\n\t\t\t\t-----------------------\n");
            printf("\t\t\t\t      Update Item..\n");
            printf("\t\t\t\t-----------------------\n");
            printf("\t\t\t\tSelect the category..\n");
            printf("\t\t\t\t1 - Sport Item\n");
            printf("\t\t\t\t2 - Gift Item\n");
            printf("\t\t\t\t3 - Luxury Item\n");
            printf("\t\t\t\t4 - School Item\n");
            printf("\t\t\t\t-----------------------\n");
            printf("\t\t\t\tEnter your choice(1/2) :");
            scanf("%d", &select);

            system("cls");
            printf("\t\t******************************************************\n");
            printf("\t\t                **   DOLLAR DEALS SUPERMARKET   **\n");
            printf("\t\t******************************************************\n\n");

            if (select == 1)
            {

                printf("\t\t\t\t-----------------------\n");
                printf("\t\t\t\tEnter item code : ");
                scanf("%s", &code);
                printf("\t\t\t\t-----------------------\n\n");

                updatefile = fopen("sportitem.txt", "r");
                tempfile = fopen("tempsport.txt", "a");

                int i = 0;
                while (fscanf(updatefile, "%s %s %f", &sport[i].itemCode, &sport[i].itemName, &sport[i].unitPrice) != EOF)
                {
                    if (strcmp(code, sport[i].itemCode) == 0)
                    {
                        printf("\t\t\t\tItem Found!!\n");
                        printf("\t\t\t\t-----------------------\n");
                        printf("\t\t\t\tName        : %s\n", sport[i].itemName);
                        printf("\t\t\t\tUnit Price  : %.2f\n", sport[i].unitPrice);
                        printf("\t\t\t\t-----------------------\n");

                        printf("\n\t\t\t\tEnter New Name      :");
                        scanf("%s", &sport[i].itemName);
                        printf("\t\t\t\tEnter New Price     :");
                        scanf("%f", &sport[i].unitPrice);
                        fprintf(tempfile, "%s %s %.2f\n", sport[i].itemCode, sport[i].itemName, sport[i].unitPrice);
                        a = 1;
                    }
                    else
                    {
                        fprintf(tempfile, "%s %s %.2f\n", sport[i].itemCode, sport[i].itemName, sport[i].unitPrice);
                    }
                    i++;
                }

                fclose(updatefile);
                fclose(tempfile);

                remove("sportitem.txt");
                rename("tempsport.txt", "sportitem.txt");
            }
            else if (select == 2)
            {
                printf("\t\t\t\t-----------------------\n");
                printf("\t\t\t\tEnter item code : ");
                scanf("%s", &code);
                printf("\t\t\t\t-----------------------\n\n");

                updatefile = fopen("giftitem.txt", "r");
                tempfile = fopen("tempsport.txt", "a");

                int i = 0;
                while (fscanf(updatefile, "%s %s %f", &gift[i].itemCode, &gift[i].itemName, &gift[i].unitPrice) != EOF)
                {
                    if (strcmp(code, gift[i].itemCode) == 0)
                    {
                        printf("\t\t\t\tItem Found!!\n");
                        printf("\t\t\t\t-----------------------\n");
                        printf("\t\t\t\tName        : %s\n", gift[i].itemName);
                        printf("\t\t\t\tUnit Price  : %.2f\n", gift[i].unitPrice);
                        printf("\t\t\t\t-----------------------\n");

                        printf("\n\t\t\t\tEnter New Name      :");
                        scanf("%s", &gift[i].itemName);
                        printf("\t\t\t\tEnter New Price     :");
                        scanf("%f", &gift[i].unitPrice);
                        fprintf(tempfile, "%s %s %.2f\n", gift[i].itemCode, gift[i].itemName, gift[i].unitPrice);
                        a = 1;
                    }
                    else
                    {
                        fprintf(tempfile, "%s %s %.2f\n", gift[i].itemCode, gift[i].itemName, gift[i].unitPrice);
                    }
                    i++;
                }

                fclose(updatefile);
                fclose(tempfile);

                remove("giftitem.txt");
                rename("tempsport.txt", "giftitem.txt");
            }
            else if (select == 3)
            {
                printf("\t\t\t\t-----------------------\n");
                printf("\t\t\t\tEnter item code : ");
                scanf("%s", &code);
                printf("\t\t\t\t-----------------------\n\n");

                updatefile = fopen("luxuryitem.txt", "r");
                tempfile = fopen("tempsport.txt", "a");

                int i = 0;
                while (fscanf(updatefile, "%s %s %f", &luxury[i].itemCode, &luxury[i].itemName, &luxury[i].unitPrice) != EOF)
                {
                    if (strcmp(code, luxury[i].itemCode) == 0)
                    {
                        printf("\t\t\t\tItem Found!!\n");
                        printf("\t\t\t\t-----------------------\n");
                        printf("\t\t\t\tName        : %s\n", luxury[i].itemName);
                        printf("\t\t\t\tUnit Price  : %.2f\n", luxury[i].unitPrice);
                        printf("\t\t\t\t-----------------------\n");

                        printf("\n\t\t\t\tEnter New Name      :");
                        scanf("%s", &luxury[i].itemName);
                        printf("\t\t\t\tEnter New Price     :");
                        scanf("%f", &luxury[i].unitPrice);
                        fprintf(tempfile, "%s %s %.2f\n", luxury[i].itemCode, luxury[i].itemName, luxury[i].unitPrice);
                        a = 1;
                    }
                    else
                    {
                        fprintf(tempfile, "%s %s %.2f\n", luxury[i].itemCode, luxury[i].itemName, luxury[i].unitPrice);
                    }
                    i++;
                }

                fclose(updatefile);
                fclose(tempfile);

                remove("luxuryitem.txt");
                rename("tempsport.txt", "luxuryitem.txt");
            }
            else if (select == 4)
            {
                printf("\t\t\t\t-----------------------\n");
                printf("\t\t\t\tEnter item code : ");
                scanf("%s", &code);
                printf("\t\t\t\t-----------------------\n\n");

                updatefile = fopen("schoolitem.txt", "r");
                tempfile = fopen("tempsport.txt", "a");

                int i = 0;
                while (fscanf(updatefile, "%s %s %f", &school[i].itemCode, &school[i].itemName, &school[i].unitPrice) != EOF)
                {
                    if (strcmp(code, school[i].itemCode) == 0)
                    {
                        printf("\t\t\t\tItem Found!!\n");
                        printf("\t\t\t\t-----------------------\n");
                        printf("\t\t\t\tName        : %s\n", school[i].itemName);
                        printf("\t\t\t\tUnit Price  : %.2f\n", school[i].unitPrice);
                        printf("\t\t\t\t-----------------------\n");

                        printf("\n\t\t\t\tEnter New Name      :");
                        scanf("%s", &school[i].itemName);
                        printf("\t\t\t\tEnter New Price     :");
                        scanf("%f", &school[i].unitPrice);
                        fprintf(tempfile, "%s %s %.2f\n", school[i].itemCode, school[i].itemName, school[i].unitPrice);
                        a = 1;
                    }
                    else
                    {
                        fprintf(tempfile, "%s %s %.2f\n", school[i].itemCode, school[i].itemName, school[i].unitPrice);
                    }
                    i++;
                }

                fclose(updatefile);
                fclose(tempfile);

                remove("schoolitem.txt");
                rename("tempsport.txt", "schoolitem.txt");
            }
            else
            {
                b = 1;
                system("cls");
                printf("\n\n----------------------------------------------------\n\n");
                printf("\t\t    Warning!!...\n");
                printf("\t\t  Invalid Input!...\n");
                printf("\n\n----------------------------------------------------\n");
                printf("Enter any key to return..\n");
                getch();
            }
        } while (b != 0);

        if (a == 1)
        {
            printf("\t\t\t\t-----------------------\n");
            printf("\n\t\t******************************************************\n");
            printf("\t\tItem Updated SUCCESSFULLY!!\n");
            printf("\t\t******************************************************\n");
        }
        else
        {
            printf("\t\t\t\t-----------------------\n");
            printf("\n\t\t******************************************************\n");
            printf("\t\tRecord not found!..\n");
            printf("\t\t******************************************************\n");
            printf("\t\tEnter any Key to continue...");
            getch();
            printf("\n");
        }
        a = 0;

        printf("\n\t\tDo you want to update another item?\n");
        printf("\t\t    [1] -> Yes\n");
        printf("\t\t    [2] -> No\n");
        printf("\t\tEnter your choice(1/2) :");
        scanf("%d", &choice);
    } while (choice != 2);
}

void addItem(struct itemList sport[], struct itemList gift[], struct itemList luxury[], struct itemList school[])
{
    int choice = 0;
    int more = 0;
    int a = 0;
    int b = 0;

    FILE *fileadd;

    do
    {
        do
        {
            system("cls");
            printf("\t\t******************************************************\n");
            printf("\t\t                **   DOLLAR DEALS SUPERMARKET   **\n");
            printf("\t\t******************************************************\n\n");
            printf("\n\t\t\t\t-----------------------\n");
            printf("\t\t\t\t      Add New Item..\n");
            printf("\t\t\t\t-----------------------\n");
            printf("\t\t\t\tSelect the category..\n");
            printf("\t\t\t\t1 - Sport Item\n");
            printf("\t\t\t\t2 - Gift Item\n");
            printf("\t\t\t\t3 - Luxury Item\n");
            printf("\t\t\t\t4 - School Item\n");
            printf("\t\t\t\t-----------------------\n");
            printf("\t\t\t\tEnter your choice(1/2) :");
            scanf("%d", &choice);

            system("cls");
            printf("\t\t******************************************************\n");
            printf("\t\t                **   DOLLAR DEALS SUPERMARKET   **\n");
            printf("\t\t******************************************************\n\n");

            if (choice == 1)
            {
                printf("\t\t------------------------------------------------------\n");
                printf("\t\t*Introduction:- Item Code should be started with SP...\n");
                printf("\t\t                Use (_) for spaces..\n");
                printf("\t\t------------------------------------------------------\n");
                printf("\t\t\t\t-----------------------\n");

                a = 1;
                fileadd = fopen("sportitem.txt", "a");

                do
                {
                    printf("\t\t\t\tEnter item code :");
                    scanf("%s", &sport[0].itemCode);

                    if (sport[0].itemCode[0] == 'S' && sport[0].itemCode[1] == 'P')
                    {
                        b = 0;
                    }
                    else
                    {
                        b = 1;
                        printf("\n\t\tInvalid item code format!!..\n");
                    }
                } while (b != 0);

                printf("\t\t\t\tEnter Name      :");
                scanf("%s", &sport[0].itemName);
                printf("\t\t\t\tEnter Price     :");
                scanf("%f", &sport[0].unitPrice);

                fprintf(fileadd, "%s %s %.2f\n", sport[0].itemCode, sport[0].itemName, sport[0].unitPrice);
                fclose(fileadd);
            }
            else if (choice == 2)
            {
                printf("\t\t------------------------------------------------------\n");
                printf("\t\t*Introduction:- Item Code should be started with GI...\n");
                printf("\t\t------------------------------------------------------\n");
                printf("\t\t\t\t-----------------------\n");

                a = 1;
                fileadd = fopen("giftitem.txt", "a");

                do
                {
                    printf("\t\t\t\tEnter item code :");
                    scanf("%s", &gift[0].itemCode);

                    if (gift[0].itemCode[0] == 'G' && gift[0].itemCode[1] == 'I')
                    {
                        b = 0;
                    }
                    else
                    {
                        b = 1;
                        printf("\n\t\tInvalid item code format!!..\n");
                    }
                } while (b != 0);

                printf("\t\t\t\tEnter Name      :");
                scanf("%s", &gift[0].itemName);
                printf("\t\t\t\tEnter Price     :");
                scanf("%f", &gift[0].unitPrice);

                fprintf(fileadd, "%s %s %.2f\n", gift[0].itemCode, gift[0].itemName, gift[0].unitPrice);
                fclose(fileadd);
            }
            else if (choice == 3)
            {
                printf("\t\t------------------------------------------------------\n");
                printf("\t\t*Introduction:- Item Code should be started with LI...\n");
                printf("\t\t------------------------------------------------------\n");
                printf("\t\t\t\t-----------------------\n");

                a = 1;
                fileadd = fopen("luxuryitem.txt", "a");

                do
                {
                    printf("\t\t\t\tEnter item code :");
                    scanf("%s", &luxury[0].itemCode);

                    if (luxury[0].itemCode[0] == 'L' && luxury[0].itemCode[1] == 'I')
                    {
                        b = 0;
                    }
                    else
                    {
                        b = 1;
                        printf("\n\t\tInvalid item code format!!..\n");
                    }
                } while (b != 0);

                printf("\t\t\t\tEnter Name      :");
                scanf("%s", &luxury[0].itemName);
                printf("\t\t\t\tEnter Price     :");
                scanf("%f", &luxury[0].unitPrice);

                fprintf(fileadd, "%s %s %.2f\n", luxury[0].itemCode, luxury[0].itemName, luxury[0].unitPrice);
                fclose(fileadd);
            }
            else if (choice == 4)
            {

                printf("\t\t------------------------------------------------------\n");
                printf("\t\t*Introduction:- Item Code should be started with SI...\n");
                printf("\t\t------------------------------------------------------\n");
                printf("\t\t\t\t-----------------------\n");

                a = 1;
                fileadd = fopen("schoolitem.txt", "a");

                do
                {
                    printf("\t\t\t\tEnter item code :");
                    scanf("%s", &school[0].itemCode);

                    if (school[0].itemCode[0] == 'S' && school[0].itemCode[1] == 'I')
                    {
                        b = 0;
                    }
                    else
                    {
                        b = 1;
                        printf("\n\t\tInvalid item code format!!..\n");
                    }
                } while (b != 0);

                printf("\t\t\t\tEnter Name      :");
                scanf("%s", &school[0].itemName);
                printf("\t\t\t\tEnter Price     :");
                scanf("%f", &school[0].unitPrice);

                fprintf(fileadd, "%s %s %.2f\n", school[0].itemCode, school[0].itemName, school[0].unitPrice);
                fclose(fileadd);
            }
            else
            {
                a = 5;
                printf("\t\t\t\t    Warning!!..\n");
                printf("\t\t\t\tInvalid Choice...\n");
                printf("\t\t\t\tEnter any key to return...");
                getch();
            }
        } while (a != 1);
        printf("\t\t\t\t-----------------------\n");
        printf("\n\t\t******************************************************\n");
        printf("\t\tRecord Added SUCCESSFULLY!!\n");
        printf("\t\t******************************************************\n");
        printf("\t\tDo you want to add another item?\n");
        printf("\t\t    [1] -> Yes\n");
        printf("\t\t    [2] -> No\n");
        printf("\t\tEnter your choice(1/2) : ");
        scanf("%d", &more);
    } while (more != 2);
}

void deleteItem(struct itemList sport[], struct itemList gift[], struct itemList luxury[], struct itemList school[])
{
    FILE *filedelete;
    FILE *tempfile;

    int choice = 0;
    int select = 0;
    char code[10];
    int a = 0;
    int b = 0;

    do
    {
        do
        {
            b = 0;
            system("cls");
            printf("\t\t******************************************************\n");
            printf("\t\t                **   DOLLAR DEALS SUPERMARKET   **\n");
            printf("\t\t******************************************************\n\n");
            printf("\n\t\t\t\t-----------------------\n");
            printf("\t\t\t\t      Delete Item..\n");
            printf("\t\t\t\t-----------------------\n");
            printf("\t\t\t\tSelect the category..\n");
            printf("\t\t\t\t1 - Sport Item\n");
            printf("\t\t\t\t2 - Gift Item\n");
            printf("\t\t\t\t3 - Luxury Item\n");
            printf("\t\t\t\t4 - School Item\n");
            printf("\t\t\t\t-----------------------\n");
            printf("\t\t\t\tEnter your choice(1/2) :");
            scanf("%d", &select);

            if (select == 1)
            {
                system("cls");
                printf("\n\t\t******************************************************\n");
                printf("\t\t                **   DOLLAR DEALS SUPERMARKET   **\n");
                printf("\t\t******************************************************\n\n");
                printf("\t\t\t\t-----------------------\n");
                printf("\t\t\t\t    Delete Item..\n");
                printf("\t\t\t\t-----------------------\n");
                printf("\t\t\t\tEnter item code :");
                fflush(stdin);
                scanf("%s", &code);

                filedelete = fopen("sportitem.txt", "r");
                tempfile = fopen("tempfile.txt", "a");

                int i = 0;
                while (fscanf(filedelete, "%s %s %f\n", &sport[i].itemCode, sport[i].itemName, &sport[i].unitPrice) != EOF)
                {

                    if (strcmp(code, sport[i].itemCode) == 0)
                    {
                        a = 1;
                    }
                    else
                    {
                        fprintf(tempfile, "%s %s %.2f\n", sport[i].itemCode, sport[i].itemName, sport[i].unitPrice);
                    }
                    i++;
                }
                printf("\t\t\t\t-----------------------\n");

                fclose(filedelete);
                fclose(tempfile);

                remove("sportitem.txt");
                rename("tempfile.txt", "sportitem.txt");
            }
            else if (select == 2)
            {
                system("cls");
                printf("\n\t\t******************************************************\n");
                printf("\t\t                **   DOLLAR DEALS SUPERMARKET   **\n");
                printf("\t\t******************************************************\n\n");
                printf("\t\t\t\t-----------------------\n");
                printf("\t\t\t\t    Delete Item..\n");
                printf("\t\t\t\t-----------------------\n");
                printf("\t\t\t\tEnter item code :");
                fflush(stdin);
                scanf("%s", &code);

                filedelete = fopen("giftitem.txt", "r");
                tempfile = fopen("tempfile.txt", "a");

                int i = 0;
                while (fscanf(filedelete, "%s %s %f", &gift[i].itemCode, gift[i].itemName, &gift[i].unitPrice) != EOF)
                {

                    if (strcmp(code, gift[i].itemCode) == 0)
                    {
                        a = 1;
                    }
                    else
                    {
                        fprintf(tempfile, "%s %s %.2f\n", gift[i].itemCode, gift[i].itemName, gift[i].unitPrice);
                    }
                    i++;
                }
                printf("\t\t\t\t-----------------------\n");

                fclose(filedelete);
                fclose(tempfile);

                remove("gifttitem.txt");
                rename("tempfile.txt", "giftitem.txt");
            }
            else if (select == 3)
            {
                system("cls");
                printf("\n\t\t******************************************************\n");
                printf("\t\t                **   DOLLAR DEALS SUPERMARKET   **\n");
                printf("\t\t******************************************************\n\n");
                printf("\t\t\t\t-----------------------\n");
                printf("\t\t\t\t    Delete Item..\n");
                printf("\t\t\t\t-----------------------\n");
                printf("\t\t\t\tEnter item code :");
                fflush(stdin);
                scanf("%s", &code);

                filedelete = fopen("luxuryitem.txt", "r");
                tempfile = fopen("tempfile.txt", "a");

                int i = 0;
                while (fscanf(filedelete, "%s %s %f", &luxury[i].itemCode, luxury[i].itemName, &luxury[i].unitPrice) != EOF)
                {

                    if (strcmp(code, luxury[i].itemCode) == 0)
                    {
                        a = 1;
                    }
                    else
                    {
                        fprintf(tempfile, "%s %s %.2f\n", luxury[i].itemCode, luxury[i].itemName, luxury[i].unitPrice);
                    }
                    i++;
                }
                printf("\t\t\t\t-----------------------\n");

                fclose(filedelete);
                fclose(tempfile);

                remove("luxuryitem.txt");
                rename("tempfile.txt", "luxuryitem.txt");
            }
            else if (select == 4)
            {
                system("cls");
                printf("\n\t\t******************************************************\n");
                printf("\t\t                **   DOLLAR DEALS SUPERMARKET   **\n");
                printf("\t\t******************************************************\n\n");
                printf("\t\t\t\t-----------------------\n");
                printf("\t\t\t\t    Delete Item..\n");
                printf("\t\t\t\t-----------------------\n");
                printf("\t\t\t\tEnter item code :");
                fflush(stdin);
                scanf("%s", &code);

                filedelete = fopen("schoolitem.txt", "r");
                tempfile = fopen("tempfile.txt", "a");

                int i = 0;
                while (fscanf(filedelete, "%s %s %f", &school[i].itemCode, school[i].itemName, &school[i].unitPrice) != EOF)
                {

                    if (strcmp(code, school[i].itemCode) == 0)
                    {
                        a = 1;
                    }
                    else
                    {
                        fprintf(tempfile, "%s %s %.2f\n", school[i].itemCode, school[i].itemName, school[i].unitPrice);
                    }
                    i++;
                }
                printf("\t\t\t\t-----------------------\n");

                fclose(filedelete);
                fclose(tempfile);

                remove("schoolitem.txt");
                rename("tempfile.txt", "schoolitem.txt");
            }
            else
            {
                system("cls");
                printf("\n\t\t------------------------------------------------------\n");
                printf("\t\t\t\t    Warning!!..\n");
                printf("\t\t\t\tInvalid Choice...\n");
                printf("\n\t\t------------------------------------------------------\n");
                printf("\t\t\t\tEnter any key to return...");
                getch();
                b = 1;
            }
        } while (b != 0);

        if (a == 1)
        {
            printf("\n\t\t******************************************************\n");
            printf("\t\tItem deleted SUCCESSFULLY!!\n");
            printf("\t\t******************************************************\n");
        }
        else
        {
            printf("\n\t\t******************************************************\n");
            printf("\t\tRecord not found!..\n");
            printf("\t\t******************************************************\n");
            printf("\t\tEnter any Key to continue...");
            fflush(stdin);
            getch();
            printf("\n");
        }
        a = 0;

        printf("\n\t\tDo you want to delete another item?\n");
        printf("\t\t    [1] -> Yes\n");
        printf("\t\t    [2] -> No\n");
        printf("\t\tEnter your choice(1/2) :");
        fflush(stdin);
        scanf("%d", &choice);
    } while (choice != 2);
}

int displayCashierMenu(int mainMenu3)
{
    printf("\t\t******************************************************\n");
    printf("\t\t                **   DOLLAR DEALS SUPERMARKET   **\n");
    printf("\t\t******************************************************\n\n\n");
    printf("\t\t    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("\t\t                  CASHIER..  \n");
    printf("\t\t        WELCOME TO OUR ONLINE SHOPPING CENTRE..\n");
    printf("\t\t    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
    printf("\t\t======================================================\n");
    printf("\t\t\t\t[1] - Display Item\n");
    printf("\t\t\t\t[2] - Display Orders\n");
    printf("\t\t\t\t[3] - Exit\n");
    printf("\t\t======================================================\n");
    printf("\t\tWhat do you want to do?\n");
    printf("\t\tEnter your choice(1/2) :");
    scanf("%d", &mainMenu3);

    return mainMenu3;
}

void orderList(struct itemList sport[], struct customerRegistration customer[])
{

    FILE *fileitem;
    FILE *filecustomer;

    int ch = 219;
    int quantity = 0;
    float total = 0.0;
    float orderTotal = 0.0;

    printf("******************************************************************************\n");
    printf("                **   DOLLAR DEALS SUPERMARKET   **\n");
    printf("******************************************************************************\n");
    printf("\n");
    for (int i = 0; i < 33; i++)
    {
        printf("%c", ch);
    }
    printf(" ORDER LIST ");
    for (int i = 0; i < 33; i++)
    {
        printf("%c", ch);
    }
    printf("\n\n==============================================================================\n");
    printf("Item Code |    Customer Name       |  Contact number  | Quantity |   Total\n");
    printf("==============================================================================\n");

    fileitem = fopen("mycart.txt", "r");

    int i = 0;
    while (fscanf(fileitem, "%s %s %s %f %d %f\n", &customer[i].username, &sport[i].itemCode, &sport[i].itemName, &sport[i].unitPrice, &quantity, &total) != EOF)
    {
        filecustomer = fopen("custmerdetails.txt", "r");

        int j = 0;
        while (fscanf(filecustomer, "%s %s %s %s %s %s %s %s %s\n", &customer[j].firstName, &customer[j].lastName, &customer[j].nic, &customer[j].mobileNo, &customer[j].address1, &customer[j].address2, &customer[j].address3, &customer[j].username, &customer[j].password) != EOF)
        {
            if (strcmp(customer[i].username, customer[j].username) == 0)
            {
                orderTotal += total;
                printf(" %4s     |%10s %10s   |   %10s     |     %d    |  %4.2f\n", sport[i].itemCode, customer[j].firstName, customer[j].lastName, customer[j].mobileNo, quantity, total);
            }
            j++;
        }
        fclose(filecustomer);

        i++;
    }

    fclose(fileitem);

    printf("==============================================================================\n");
    printf("Order Total \t\t\t\t\t\t           %.2f\n", orderTotal);
    printf("==============================================================================\n");
    printf("Enter to any key to continue..");
    getch();
}

int displayDistributorrMenu(int mainMenu4)
{
    printf("\t\t******************************************************\n");
    printf("\t\t                **   DOLLAR DEALS SUPERMARKET   **\n");
    printf("\t\t******************************************************\n\n\n");
    printf("\t\t    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("\t\t                  CASHIER..  \n");
    printf("\t\t        WELCOME TO OUR ONLINE SHOPPING CENTRE..\n");
    printf("\t\t    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
    printf("\t\t======================================================\n");
    printf("\t\t\t\t[1] - Display Item\n");
    printf("\t\t\t\t[2] - Delivery List\n");
    printf("\t\t\t\t[3] - Customer Details\n");
    printf("\t\t\t\t[4] - Exit\n");
    printf("\t\t======================================================\n");
    printf("\t\tWhat do you want to do?\n");
    printf("\t\tEnter your choice(1/2) :");
    scanf("%d", &mainMenu4);

    return mainMenu4;
}

void deliveryList(struct itemList sport[], struct customerRegistration customer[])
{
    FILE *fileitem;
    FILE *filecustomer;

    int ch = 219;
    int quantity = 0;
    float total = 0.0;
    float orderTotal = 0.0;

    printf("****************************************************************************\n");
    printf("                **   DOLLAR DEALS SUPERMARKET   **\n");
    printf("****************************************************************************\n");
    printf("\n");
    for (int i = 0; i < 32; i++)
    {
        printf("%c", ch);
    }
    printf(" DELIVERY LIST ");
    for (int i = 0; i < 32; i++)
    {
        printf("%c", ch);
    }

    printf("\n\n==============================================================================\n");
    printf("Item Code |    Customer Name       |  Contact number  | Quantity |   Total\n");
    printf("==============================================================================\n");

    filecustomer = fopen("custmerdetails.txt", "r");

    int j = 0;
    while (fscanf(filecustomer, "%s %s %s %s %s %s %s %s %s\n", &customer[j].firstName, &customer[j].lastName, &customer[j].nic, &customer[j].mobileNo, &customer[j].address1, &customer[j].address2, &customer[j].address3, &customer[j].username, &customer[j].password) != EOF)
    {

        fileitem = fopen("mycart.txt", "r");

        orderTotal = 0.0;
        int i = 0;
        while (fscanf(fileitem, "%s %s %s %f %d %f\n", &customer[i].username, &sport[i].itemCode, &sport[i].itemName, &sport[i].unitPrice, &quantity, &total) != EOF)
        {

            if (strcmp(customer[i].username, customer[j].username) == 0)
            {
                orderTotal += total;
                printf(" %4s     |%10s %10s   |   %10s     |     %d    |  %4.2f\n", sport[i].itemCode, customer[j].firstName, customer[j].lastName, customer[j].mobileNo, quantity, total);
            }
            i++;
        }
        fclose(fileitem);
        printf("============================================================================\n");
        printf("Customer Total \t\t\t\t\t\t           %.2f\n", orderTotal);
        printf("============================================================================\n");

        j++;
    }
    fclose(filecustomer);

    printf("\nEnter any key to continue..");
    getch();
}

void readCustomerDetails(struct customerRegistration customer[])
{
    FILE *filereader;

    int ch = 219;
    int quantity = 0;
    float total = 0.0;
    float orderTotal = 0.0;

    printf("  ****************************************************************************\n");
    printf("                  **   DOLLAR DEALS SUPERMARKET   **\n");
    printf("  ****************************************************************************\n");
    printf("\n  ");
    for (int i = 0; i < 29; i++)
    {
        printf("%c", ch);
    }
    printf(" Customer Details ");
    for (int i = 0; i < 29; i++)
    {
        printf("%c", ch);
    }

    printf("\n\n  ============================================================================\n");
    printf("      Customer Name       |    Contact number  |           Address\n");
    printf("  ============================================================================\n");

    filereader = fopen("custmerdetails.txt", "r");

    int i = 0;
    while (fscanf(filereader, "%s %s %s %s %s %s %s %s %s\n", &customer[i].firstName, &customer[i].lastName, &customer[i].nic, &customer[i].mobileNo, &customer[i].address1, &customer[i].address2, &customer[i].address3, &customer[i].username, &customer[i].password) != EOF)
    {
        printf("  %10s %10s   |     %10s     |     %s, %s, %s   \n", customer[i].firstName, customer[i].lastName, customer[i].mobileNo, customer[i].address1, customer[i].address2, customer[i].address3);
        i++;
    }

    fclose(filereader);
    printf("  ============================================================================\n");
    printf("  Enter any key to continue..");
    getch();
}

int readFinish(int finish)
{
    printf("\n\n---------------------------------------\n");
    printf("Do you want go to main menue?\n");
    printf("    [1] -> Yes\n");
    printf("    [2] -> No\n");
    printf("Enter your choice(1/2) :");
    scanf("%d", &finish);

    return finish;
}

void readLogout()
{
    printf("****************************************************************************\n");
    printf("Enter any key to logout..\n");
    getch();
    printf("****************************************************************************\n");
    printf("Login Out SUCCESSFULLY!!..\n");
    printf("****************************************************************************\n");
    getch();
}
