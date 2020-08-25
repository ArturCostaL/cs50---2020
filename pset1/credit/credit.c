#include <stdio.h>
#include <cs50.h>

int main(void){

    int aux = 0;
    long sum = 0;
    long sumprod = 0;
    int digits = 0;
    int firstnumber = 0;

    long num = get_long("Insert your credit card number:\n");

    while(num!=0)
    {
        digits++;
        if(aux==0)
        {
            sum += num % 10;
            aux++;
        }
        else
        {
            if(2*(num%10)<10)
            {
            sumprod += 2*(num % 10);
            }
            else
            {
            sumprod+=(2*(num % 10))/10;
            sumprod+=(2*(num % 10))%10;
            }
            aux--;
        }
        num = num/10;

        if(num < 100 && num >10)
        {
            firstnumber = num;
        }
    }


    if((sum+sumprod)%10==0)
    {

        if(firstnumber/10==4 && (digits == 13 || digits==16))
        {
            printf("VISA\n");
        }
        else if ((firstnumber == 51 || firstnumber == 52||firstnumber == 53||firstnumber == 54 || firstnumber == 55 ) && digits == 16)
        {
            printf("MASTERCARD\n");
        }
        else if ((firstnumber == 34 ||firstnumber == 37) && digits == 15)
        {
            printf("AMEX\n");
        }
        else
        {
            printf("INVALID\n");
        }


    }
    else
    {
        printf("INVALID\n");
    }


    /*printf("sum: %li   sumprod %li digits %i first: %i" , sum, sumprod, digits, firstnumber);*/


}
