#include <stdio.h>

int main()
{
    int i,j,quantity_1=0,quantity_2=0,quantity_3=0,quantity_4=0,quantity_5=0;
    int menu_1,member,money,amount,icoin;
    float sum1=0,sum2=0,coin=0;

    for(i=1;i<=25;i++)
    {
        printf("=");
    }
    printf(" Doi Fah ");
    for(i=1;i<=17;i++)
    {    
        printf("=");
    }
    printf("By: Krit Leetrakul");
    for(i=1;i<=3;i++)
    {
        printf("=");
    }
    printf("\n");
    printf("Please select item of prices\n");
    printf("[1] Coffee (35.00 B)    [2] Rice (150.00 B)    [3] Tea (135.00 B)\n");
    printf("[4] Milk (45.00 B)    [5] Orange juice (150.00 B)    [0] Quit \n");
    for(i=1;i<=72;i++)
    {
        printf("=");
    }

    printf("\n");
    printf("\nEnter item of menu : ");
    scanf("%d",&menu_1);
    for (menu_1;menu_1>=0;menu_1)
    {   
        switch(menu_1)
        {
            case 1 : printf("Enter of quantity : ");
                     scanf("%d",&quantity_1);
                     printf("Enter item of menu : ");
                     scanf("%d",&menu_1);
                break;
            case 2 : printf("Enter of quantity : ");
                     scanf("%d",&quantity_2);
                     printf("Enter item of menu : ");
                     scanf("%d",&menu_1);
                break;
            case 3 : printf("Enter of quantity : ");
                     scanf("%d",&quantity_3);
                     printf("Enter item of menu : ");
                     scanf("%d",&menu_1);
                break;
            case 4 : printf("Enter of quantity : ");
                     scanf("%d",&quantity_4);
                     printf("Enter item of menu : ");
                     scanf("%d",&menu_1);
                break;
            case 5 : printf("Enter of quantity : ");
                     scanf("%d",&quantity_5);
                     printf("Enter item of menu : ");
                     scanf("%d",&menu_1);
                break;
            case 0 : menu_1 = -1;
                break;
        }
    }
    sum1 = (quantity_1*35)+(quantity_2*150)+(quantity_3*135)+(quantity_4*45)+(quantity_5*150);
    if (sum1==0)
        printf("Bye bye\n");
    else
    {
        printf("total price = %.2f\n",sum1);
        if (sum1>=1000)
        {
            printf("Surprise! You get promotion 10% (If you buy over than 1,000B)\n");
            printf("Amount price = %.2f\n",sum1 = sum1-((sum1*10)/100));
        }
        printf("You are member Doi Fah Shop (1/0) : ");
        scanf("%d",&member);
        if (member==1)
        {
            if (sum1<1000)
                printf("Amount price = %.2f\n",sum1 = sum1-((sum1*5)/100));
            else if (sum1>=1000)
                printf("Amount price = %.2f\n",sum1 = sum1-((sum1*5)/100));
        }
        else if (member==0)
        {
            if (sum1<1000)
                printf("Amount price = %.2f\n",sum1);
            else if (sum1>=1000)
                printf("Amount price = %.2f\n",sum1);
        }
    
        printf("\nPlease paying (More than amount price) => ");
        scanf("%d",&money);
        if (sum1>money)
            printf("Sorry try again!\n");
        else 
            printf("Change = %.2f\n",coin = money-sum1);
         
        icoin = (int)coin;
        if(icoin >= 1000)
        {
            amount = icoin / 1000;
            printf("Bank(1000) : %d\n",amount);
            icoin = icoin % 1000;
        }
        if (icoin >= 500)
        {
            amount = icoin / 500;
            printf("Bank(500) : %d\n",amount);
            icoin = icoin % 500;
        }
        if (icoin >= 100)
        {
            amount = icoin / 100;
            printf("Bank(100) : %d\n",amount);
            icoin = icoin % 100;
        }
        if (icoin >= 50)
        {
            amount = icoin / 50;
            printf("Bank(50) : %d\n",amount);
            icoin = icoin % 50;
        }
        if (icoin >= 20)
        {
            amount = icoin / 20;
            printf("Bank(20) : %d\n",amount);
            icoin = icoin % 20;
        }
        if (icoin >= 10)
        {
            amount = icoin / 10;
            printf("Coin(20) : %d\n",amount);
            icoin = icoin % 10;
        }
        if (icoin >= 5)
        {
            amount = icoin / 5;
            printf("Coin(5) : %d\n",amount);
            icoin = icoin % 5;
        }
        if (icoin >= 2)
        {
            amount = icoin / 2;
            printf("Coin(2) : %d\n",amount);
            icoin = icoin % 2;
        }
        if (icoin >= 1)
        {
            amount = icoin / 1;
            printf("Coin(1) : %d\n",amount);
            icoin = icoin % 1;
        }    
    }
    printf("\n");
    printf("\n");
    printf("Thank you... See you again.");
}