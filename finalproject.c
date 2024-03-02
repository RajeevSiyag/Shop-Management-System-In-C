#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>


struct date1
{
    int day;
    int month;
    char year[4];
};

struct account
{
    int number;
    char name[100];
    long acct_no;
    char mobile_no[14];
    char street[100];
    char city[100];
    char acct_type;
    float oldbalance;
    float newbalance;
    float payment;
    char payment_status[100];
    struct date1 lastpayment;
} customer;
int tl, sl, ts;

struct item
{
    int productno;
    char productname[10];
    int quantity;
    int price;
    int price2;
} item;
struct customer1
{
    int productno;
    char productname[10];
    int quantity;
    int price;
    int price2;
} customer1;
int n = 0;
int m = 0;
int o = 0;
long number11;

void additemtoadimn()
{
    int i = 0;
    FILE *fp;
    printf("\n------------------------------------------------------------------\n");
    fp = fopen("iteamlist.txt", "a");
    printf("Enter the Number of Records:");
    printf("\n------------------------------------------------------------------\n");
    scanf("%d", &n);
    printf("\n");
    while (i < n)
    {
        printf("\n------------------------------------------------------------------\n");
        printf("\t");
        printf("Enter Product Code:");
        scanf("%d", &item.productno);
        printf("\t");
        printf("Enter Product Name:");
        scanf("%s", &item.productname);
        printf("\t");
        printf("Enter Quantity:");
        scanf("%d", &item.quantity);
        printf("\t");
        printf("Enter Price:");
        scanf("%d", &item.price);
        printf("\n");
        i++;
        fprintf(fp, "%d\t%s\t%d\t%d\t \n", item.productno, item.productname, item.quantity, item.price);
        printf("\n------------------------------------------------------------------\n");
    }
    fclose(fp);
    printf("\t");
    printf("Records are Created");
    printf("\n------------------------------------------------------------------\n");
    printf("\n");
}

void displayiteamlist()
{
    // Probleam : Can not show list after closing program.
    //  int nk=0;
    FILE *fp;
    fp = fopen("iteamlist.txt", "r");
    printf("\t");
    printf(" = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = \n");
    printf("\t");
    printf("|Product Code\t|Product Name\t|Quantity\t|Price\t\n");
    printf("\t");
    printf(" = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = \n");
    while (!feof(fp))
    {
        fscanf(fp, "%d", &item.productno);
        fscanf(fp, "%s", item.productname);
        fscanf(fp, "%d", &item.quantity);
        fscanf(fp, "%d", &item.price);
        printf("\n\t  %14d|\t%8s|\t%8d|\t%d|\n", item.productno, item.productname, item.quantity, item.price);
        printf("\n");
    }
    fclose(fp);
}

void creatbill()
{
    int i = 0;
    int j = 0;
    FILE *fp1;
    fp1 = fopen("customerlist.txt", "a");
    printf("\n------------------------------------------------------------------\n");
    printf("Enter the Number of Customer : ");
    scanf("%d", &m);
    printf("\n");
    while (i < m)
    {
        printf("\n------------------------------------------------------------------\n");
        printf("\ncustomer no:%d\n", ++customer.number);
        printf("         Account number:");
        scanf("%ld", &customer.acct_no);
        printf("\n       Name:");
        scanf("%s", &customer.name);
        printf("\n       Mobile no:");
        scanf("%s", &customer.mobile_no);
        printf("\n       Street:");
        scanf("%s", &customer.street);
        printf("\n       City:");
        scanf("%s", &customer.city);
        printf("\n       Previous balance:");
        scanf("%f", &customer.oldbalance);
        // See here
        printf("\n------------------------------------------------------------------\n");
        printf("Number Of Iteam : ");
        scanf("%d", &o);
        j = 0;
        while (j < o)
        {
            // int number14;
            printf("\t");
            printf("\n------------------------------------------------------------------\n");
            /* FILE *fp;
             fp = fopen("iteamlist.txt", "r");
             printf("Enter Product Number : ");
             scanf("%d", &number14);
             while(fscanf(fp, "%d", &item.productno) == number14)
             {
                 fscanf(fp, "%s", &item.productname);
                 printf("%s", item.productname);
                 printf("\n");
             }
             fclose(fp);*/

            printf("Enter Product Number : ");
            scanf("%d", &item.productno);
            printf("Enter Product Name : ");
            scanf("%s", &customer1.productname);
            printf("Enter Quantity : ");
            scanf("%d", &customer1.quantity);
            printf("Enter Price : ");
            scanf("%d", &customer1.price2);
            printf("\n------------------------------------------------------------------\n");
            j++;
            customer1.price = customer1.price + (customer1.price2 * customer1.quantity);
        }

        printf("\n       Current payment: %.2f ", customer.payment = customer1.price);
        // scanf("%f", &customer.payment);
        printf("\n       New balance    :%.2f\n", customer.oldbalance + customer.payment);
        printf("\n       Payment date(DD/MM/YYYY):");
        scanf("%d%d%s", &customer.lastpayment.day, &customer.lastpayment.month, &customer.lastpayment.year);
        printf("\n       Account status : ");
        scanf("%s", &customer.payment_status);
        i++;
        printf("\n------------------------------------------------------------------\n");
  if (fp1 != NULL)
        {
            fprintf(fp1, "\n %ld \n %s \n %s \n %s \n %s \n %f \n %f \n %d/%d/%s \n %s ", customer.acct_no, customer.name, customer.mobile_no, customer.street, customer.city, customer.oldbalance, customer.payment, customer.lastpayment.day, customer.lastpayment.month, customer.lastpayment.year, customer.payment_status);
        }
    }
    fclose(fp1);
    printf("\t");

    printf("Wait Bill is Genrating.............");
    printf("\n");
    printf("\n------------------------------------------------------------------\n");
    printf("Date : %d/%d/%s", customer.lastpayment.day, customer.lastpayment.month, customer.lastpayment.year);
    printf("\n------------------------------------------------------------------\n");
    printf("Account Number : %ld ||", customer.acct_no);
    printf("Name : %s || \n", customer.name);
    printf("Mobile No. : %s ||", customer.mobile_no);
    printf("City : %s ||", customer.city);
    printf("\n------------------------------------------------------------------\n");
    printf("|Product Code\t|Product Name\t|Quantity\t|Price\t\n");
    printf("\t  %6d|\t%8s|\t%8d|\t%d|\n", item.productno, item.productname, customer1.quantity, customer1.price2 * customer1.quantity);
    printf("\n------------------------------------------------------------------\n");
    printf("Total : %f ||", customer.oldbalance + customer.payment);
    printf("\n------------------------------------------------------------------\n");
    printf("Account status : %s \n \n", customer.payment_status);
}

void seepreviousbill()
{
    long acctno;
    FILE *fp1;
    fp1 = fopen("customerlist.txt", "r");
    //printf("Enter the Account Number : ");
    //scanf("%ld", &acctno);
    while (!feof(fp1))
    {
    /*  fscanf(fp1, "%s", customer.name);
        printf("%ld ", customer.name);
        fscanf(fp1, "%s", customer.payment_status);
        printf("%s", customer.payment_status);*/
        fscanf(fp1, "%ld", &customer.acct_no);
        fscanf(fp1, "%s", &customer.name);
        fscanf(fp1, "%s", &customer.mobile_no);
        fscanf(fp1, "%s", &customer.street);
        fscanf(fp1, "%s", &customer.city);
        fscanf(fp1, "%f", &customer.oldbalance);
        fscanf(fp1, "%f", &customer.payment);
        fscanf(fp1, "%f", &customer.newbalance);
        fscanf(fp1, "%d %d %s", &customer.lastpayment.day);
        fscanf(fp1, "%d", &customer.lastpayment.month);
        fscanf(fp1, "%s", &customer.lastpayment.year);
        fscanf(fp1, "%s", &customer.payment_status);
        printf("\n------------------------------------------------------------------\n");
        printf("    Account number :%ld\n", customer.acct_no);
        printf("    Name 	   :%s\n", customer.name);
        printf("    Mobile no      :%s\n", customer.mobile_no);
        printf("    Street         :%s\n", customer.street);
        printf("    City           :%s\n", customer.city);
        printf("    Old balance    :%.2f\n", customer.oldbalance);
        printf("    Current payment:%.2f\n", customer.payment);
        printf("    New balance    :%.2f\n", customer.newbalance);
        printf("    Payment date   :%d/%d/%d\n\n", customer.lastpayment.month, customer.lastpayment.day, customer.lastpayment.year);
        printf("    Account status :%s\n", customer.payment_status);
        printf("\n------------------------------------------------------------------\n");
        return;
    } 
    fclose(fp1);
}

int main()
{
    int option1, i;
    int password;
    char q[10] = "admin";
    printf("\n============================================================\n");
    printf("                      BILL MANAGMENT");
    printf("\n============================================================\n");
R:
    printf("\n------------------------------------------------------------------\n");
    printf("\n                       Welcome :) \n \n");
    printf("\n------------------------------------------------------------------\n");
    printf("Select option : \n");
    printf("1) ADMINISTRATOR\n");
    printf("2) CUSTOMER BILL\n");
    printf("3) EXIT\n");
    printf("\n-------------------------------------------------------------\n");
    printf("Select one of them : ");
    scanf("%d", &option1);
    printf("\n-------------------------------------------------------------\n");
    if (option1 == 1)
    {
        printf("\n------------------------------------------------------------------\n");
        printf("\n                    Welcome Admin :) \n \n");
        printf("\n------------------------------------------------------------------\n");
        printf("Login as Admin \n");
        printf("Password : ");
        scanf("%d", &password);
        if (password == 12345)
        {
            int option2;
            printf("\n------------------------------------------------------------------\n");
            printf("Access Granted\n");
        Admin:
            printf("\n-------------------------------------------------------------\n");
            printf("                  Welcome to Admin Page");
            printf("\n-------------------------------------------------------------\n");
            printf("1)Add Iteam to Store.\n");
            printf("2)Display Iteam List.\n");
            printf("3)Main Menu\n");
            printf("4)Admin Page\n");
            printf("5)Exit\n");
            printf("\n------------------------------------------------------------------\n");
            printf("Select Option : ");
            scanf("%d", &option2);
            if (option2 == 1)
            {
                printf("\n-------------------------------------------------------------\n");
                printf("Add Iteam to Store");
                printf("\n-------------------------------------------------------------\n");
                additemtoadimn();
                goto Admin;
            }
            else if (option2 == 2)
            {
                int option3;
                printf("\n-------------------------------------------------------------\n");
                printf("Display Iteam List");
                printf("\n-------------------------------------------------------------\n");
                displayiteamlist();
                printf("\n------------------------------------------------------------------\n");
                printf("Do you want to exit or go to Main Menu \n");
                printf("1) Exit \n");
                printf("2) Main Menu \n");
                printf("\n------------------------------------------------------------------\n");
                scanf("%d", &option3);
                if (option3 == 1)
                {
                    printf("\n------------------------------------------------------------------\n");
                    printf("Exiting...................");
                    printf("\n------------------------------------------------------------------\n");
                    goto S;
                }
                if (option3 == 2)
                {
                    goto R;
                }
            }

            else if (option2 == 3)
            {
                printf("\n-------------------------------------------------------------\n");
                printf("Main Menu");
                printf("\n-------------------------------------------------------------\n");
                goto R;
            }
            else if (option2 == 4)
            {
                goto Admin;
            }
            else
            {
                printf("\n-------------------------------------------------------------\n");
                printf("Exting............");
                printf("\n-------------------------------------------------------------\n");
                goto S;
            }
        }
        else
        {
            printf("\n------------------------------------------------------------------\n");
            printf("Wrong Password, try again");
            printf("\n------------------------------------------------------------------\n");
            goto R;
        }
    }
    else if (option1 == 2)
    {
        int option4;
        printf("\n------------------------------------------------------------------\n");
        printf("\n               Welcome to Customer Bill Page :) \n \n");
        printf("\n------------------------------------------------------------------\n");
        printf("1) Create Bill\n");
        printf("2) Want to see Previous Bill\n");
        printf("3) Exit\n");
        printf("Select Option :");
        scanf("%d", &option4);
        if (option4 == 1)
        {
            int option5;
            printf("\n------------------------------------------------------------------\n");
            printf("\n               Creat Bill :) \n \n");
            printf("\n------------------------------------------------------------------\n");
            creatbill();
            printf("\n------------------------------------------------------------------\n");
            printf("Do you want to exit or go to Main Menu \n");
            printf("1) Exit \n");
            printf("2) Main Menu \n");
            printf("\n------------------------------------------------------------------\n");
            scanf("%d", &option5);
            if (option5 == 1)
            {
                printf("\n------------------------------------------------------------------\n");
                printf("Exiting...................");
                printf("\n------------------------------------------------------------------\n");
                goto S;
            }
            if (option5 == 2)
            {
                goto R;
            }
        }
        else if (option4 == 2)
        {
            int option6;
            printf("\n------------------------------------------------------------------\n");
            printf("\n            Want to see Previous Bill :) \n \n");
            printf("\n------------------------------------------------------------------\n");
            seepreviousbill();
            printf("\n------------------------------------------------------------------\n");
            printf("Do you want to exit or go to Main Menu \n");
            printf("1) Exit \n");
            printf("2) Main Menu \n");
            printf("\n------------------------------------------------------------------\n");
            scanf("%d", &option6);
            if (option6 == 1)
            {
                printf("\n------------------------------------------------------------------\n");
                printf("Exiting...................");
                printf("\n------------------------------------------------------------------\n");
                goto S;
            }
            if (option6 == 2)
            {
                goto R;
            }
        }
        else
        {
            printf("\n------------------------------------------------------------------\n");
            printf("Exiting.....................");
            printf("\n------------------------------------------------------------------\n");
            goto S;
        }
    }
    else
    {
        printf("\n------------------------------------------------------------------\n");
        printf("\nExting.............................\n");
        printf("\n------------------------------------------------------------------\n");
        goto S;
    }
S:
    printf("\n*************************************************************\n");
}
