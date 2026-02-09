/*
  Name: Arjun parameswaran
  You are given an 8-bit register represented as an unsigned char. 
  Write a function to: 
    ● Set the 3rd bit (bit index 2). 
    ● Clear the 6th bit (bit index 5). 
    ● Toggle the 1st bit (bit index 0). 
  Return the modified register value.
  Note: Use bitwise operators only. Avoid loops or conditionals.*/

#include <stdio.h>
//function call for clearing 1st bit
void set_third_bit(unsigned char *reg)
{
    *reg |= (1 << 2); 
}
//function for clearing 6th bit
void clear_sixth_bit(unsigned char *reg)
{
    *reg &= ~(1 << 5); 
}
//function for toggling 1st bit
void Toggle_first_bit(unsigned char *reg)
{
    *reg ^= (1 << 0); 
}

int main()
{
    unsigned char reg = 'a';
    //function calls for setting, clearing and toggling 
    set_third_bit(&reg);
    clear_sixth_bit(&reg);
    Toggle_first_bit(&reg);
    
    printf("The modified register value is: %u (%c).\n",reg, reg);

    return 0;
}