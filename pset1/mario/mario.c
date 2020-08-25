#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n = 0;
    int blanck = 0;
    int midle = 0;
    int hash = 0;

    do
    {
        n = get_int("How tall is the pyramid?\n");

    } while(n < 1 || n > 8);


    for(int i=0;i<n;i++)
    {
        for(int j = 0; j<n-i-1; j++)
        {
            printf(" ");
        }

        for(int j=0; j<i+1;j++)
        {
            printf("#");
        }

        for(int j=0; j<2;j++)
        {
            printf(" ");
        }

        for(int j=0; j<i+1;j++)
        {
            printf("#");
        }
        printf("\n");
    }



}