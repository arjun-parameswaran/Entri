/*nested structure*/
#include <stdio.h>
#include <string.h>



typedef struct
{
    int house_no;
    int pincode;
}address_t;

typedef struct
{
    char name[20];
    int age;
    address_t address;
}person_t;

person_t read_details(person_t p5);

int main()
{
    /*METHOD - I */
    person_t p1 = {"Arjun parameswaran", 27};
    p1.address.house_no = 101;
    p1.address.pincode = 679578;
    printf("Name     : %s\n", p1.name);
    printf("Age      : %d\n", p1.age);
    printf("House No : %d\n", p1.address.house_no);
    printf("Pincode  : %d\n", p1.address.pincode);
    /*METHOD II*/
    person_t p2 = {"Sangeeth Kumar", 26, p2.address.house_no = 112, p2.address.pincode = 679578};

    printf("Name     : %s\n", p2.name);
    printf("Age      : %d\n", p2.age);
    printf("House No : %d\n", p2.address.house_no);
    printf("Pincode  : %d\n", p2.address.pincode);
    /*METHOD III */
    person_t p3 = {"Vishnu Omanakuttan", 27,{345, 679677}};
    printf("Name     : %s\n", p3.name);
    printf("Age      : %d\n", p3.age);
    printf("House No : %d\n", p3.address.house_no);
    printf("Pincode  : %d\n", p3.address.pincode);
    /*METHOD IV*/
    person_t p4 = {"Sangeeth Kumar", 26, p2.address.house_no = 112, p2.address.pincode = 679578};

    
    person_t p5 = read_details(p5);
    
    printf("Name     : %s\n", p5.name);
    printf("Age      : %d\n", p5.age);
    printf("House No : %d\n", p5.address.house_no);
    printf("Pincode  : %d\n", p5.address.pincode);

    return 0;

}

person_t read_details(person_t p5)
{
    strcpy(p5.name,"vishal vishwanath");
    p5.age = 24;
    p5.address.house_no = 12;
    p5.address.pincode = 606434;

    return p5;
}