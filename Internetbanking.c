//Internet Banking using C


#include<stdio.h>
#include<stdlib.h>
struct node
{
    int account;
    int data;
    int data1;
   // char a[10];
    struct node *link;
};
long int acc;
int pin=1234;
int balance=5000;
struct node *root;
void create();
void details(long acc);
void deposit();
void withdraw();
void enquiry();
void pretran();
void main()
{
    int ch,atm,c=1,ch1,d;
    
    printf("            **********************************************************\n");
    printf("            *******               WELCOME TO                   *******\n");
    printf("            *******           INTERNET  BANKING                *******\n");
    printf("            **********************************************************\n\n\n");
    printf("1.Create New Account\t 2.Use Existing Account\n");
    scanf("%d",&ch1);
    switch(ch1)
    {
        case 1:create();
               printf("\n\nDo you want to make any transaction\n");
               printf("If YES  Press 1\nor else press 0\n");
               scanf("%d",&d);
               if(d==1)
               break;
               else
               exit(0);
               
        case 2: break;
    }
    printf("ENTER YOUR ACCOUNT NUMBER\n");
    scanf("%ld",&acc);
   
    
    printf("ENTER YOUR PIN NUMBER..\n");
    scanf("%d",&atm);
    while(atm!=pin && c<3)
    {
        
            
            printf("PIN NOT FOUND.....ENTER PIN AGAIN\n");
            scanf("%d",&atm);
            if(atm!=pin)
                c++;
        
        
        /*if(c==3)
        {
            printf("YOUR  LIMIT EXCEEDED....\nTRY AFTER AN HOUR ");
            return ;
        }*/
    }
    if(c==3)
        {
            printf("YOUR  LIMIT EXCEEDED....\nTRY AFTER AN HOUR ");
            return ;
        }
    if(atm==pin)
    {
        root=(struct node*)malloc(sizeof(struct node));
        root->data=balance;
        root->link=NULL;
        while(1)
        {
            printf("\n1.deposit\n2.withdraw\n3.balance enquiry\n4.previous transactions\n5.exit\n");
            printf("enter choice\n");
            scanf("%d",&ch);
            switch(ch)
            {
                case 1: deposit();
	                    break;
                case 2:	withdraw();
	                    break;
                case 3: enquiry();
	                    break;
                case 4:	pretran();
	                    break;
                case 5:	details(acc);
                        printf("\n**THANK YOU FOR USING OUR BANKING SERVICES**\n");
                        printf("**HAVE A NICE DAY**");
                        exit(1);
                default:printf("INVALID CHOICE\n");
		                break;
            }
        }
//details(acc);
    }
return;
}
void deposit()
{
    int x;
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("enter amount to deposit\n");
    scanf("%d",&x);
    balance=x+balance;
    temp->data1=x;
    temp->data=(balance);
    //temp->a="Deposited";
    temp->link=root;
    root=temp;
}
void withdraw()
{
    int x;
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("enter amount to withdraw:\n");
    scanf("%d",&x);
    balance=balance-x;
    temp->data1=x;
    temp->data=(balance);
    //temp->a="Withdrawn";
    temp->link=root;
    root=temp;
}
void enquiry()
{
    printf("BALANCE = %d",root->data);
}
void pretran()
{
    struct node *temp;
    temp=root;
    printf("PREVIOUS TRANSACTIONS ARE..:\n");
    while(temp->link!=NULL)
    {
        //printf("previous transactions are:\n");
        printf("%d\t",temp->data1);
        if(temp->data<temp->link->data)
        {
            printf("Withdrawn\n");
        }
        else
        {
            printf("Deposited\n");
        }
//printf("Current Balance:%d\n",temp->data);
        temp=temp->link;
    }
}
void details(long acc)
{
    printf("DETAILS OF ACCOUNT HOLDER ..::\n");
    printf("Account number  : %ld\n",acc);
    printf("Current Balance : %d\n",root->data);
    return;
}
void create()
{
    int opt,pin1;
    long int a;
    printf("Enter details of valid proof from the following\n");
    printf("1.AAdhar Number\n2.Driving Liscence\n3.Voter ID\n");
    scanf("%d",&opt);
    switch(opt)
    {
        case 1: printf("Enter your Aadhar number\n");
                scanf("%ld",&a);
                 break;
        case 2:printf("Enter your Driving Liscence\n");
               scanf("%ld",&a);
               break;
        case 3: printf("Enter your Voter ID\n");
                scanf("%ld",&a);
                break;
    }
    printf("\nYour account has been validated\nSet your PIN NUMBER\n");
    scanf("%d",&pin1);
    pin=pin1;
    printf("\n\nYour account has been successfully created..\nNow you are eligible to make transcation online\n");
    
}

