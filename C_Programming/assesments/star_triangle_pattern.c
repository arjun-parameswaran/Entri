/*Name: Arjun parameswaran
Write a C program to print a pyramid of stars for a given number n. If n = 5, the output should be:
                  *
                 ***
                *****
               *******
              *********
*/

#include <stdio.h>

int main()
{
    int num;
    printf("enter the value: ");
      scanf("%d", &num);

    for(int i = 0; i < num; i++)
    {
        for(int j = 0; j < (2 * num) - 1; j++)
        {
            if(j >= num - 1 - i && j <= num - 1 + i)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}
