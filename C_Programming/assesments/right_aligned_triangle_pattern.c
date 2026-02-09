/* Write a C program to print a pyramid of stars for a given number n.
 If n = 5, the output should be:

        *
      ***
    *****
  *******
*********
-----------------------------------------------------------------------------*/

#include <stdio.h>

int main()
{
    int num = 5;
    /* outer loop to control the row */
    for(int row = 1; row <= num; row++)
    {
    /* inner loop to control the col */
        for(int col = 1; col <= (2 * num - 1); col++)
        {
            /*condition to achieve pattern */
            if(col > 2 * (num - row))
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }   
        }
        printf("\n"); //to goto next row
    }
    return 0;
}