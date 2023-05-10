#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>

typedef struct Date
{
    int day;
    int month;
    int year;
};

typedef struct Address
{
    char street[30];
    int number;
    char neighborhood[20];
    char city[20];
    char state[2];
    char zip_code[10];
};

typedef struct Employee
{
    int registration;
    char cpf[14];
    char name[50];
    char position[30];
    char phone[15];
    Date birth_date;
    Address address;
};

Address create_address();
void show_address(const Address &address);
Employee create_employee();
void show_employee(const Employee &employee);

#endif