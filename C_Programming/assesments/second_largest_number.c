/*
    Name: Arjun parameswaran
    Write a function in C that takes an array of integers and its size, and returns the second largest element. 
    Constraints:
            ● Do not sort the array. 
            ● Assume the array has at least two distinct elements.*/
            
            
#include <stdio.h>

/*function for finding the second largest element in an array*/
int secondLargestElement(int *arr, int size)
{
    int largest = arr[0] , sec_largest = -1;
    for(int i = 1; i < size; i++)
    {
        if(arr[i] > largest) //when the element is bigger then largest
        {
            sec_largest = largest; // updating both largest and sec_largest
            largest = arr[i];
        }
        else if(arr[i] < largest && arr[i] > sec_largest) // when the element is smaller than largest but greater than sec_largest
        {
            sec_largest = arr[i]; //updating sec_largest
        }
    }
    return sec_largest;
}

int main()
{
    int arr[] = {2, 6, 5, 11, 3, 8, 9, 10, 12};
    int size = (int) (sizeof(arr) / sizeof(int));
    
    /*calling function to find the second largest element*/
    int sec_largest = secondLargestElement(arr, size);

    printf("second largest element: %d\n", sec_largest);
    
    return 0;
}