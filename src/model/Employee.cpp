#pragma once
#include "Employee.hpp"

Date create_date()
{
    Date date;
    std::cout << "Enter day:" << std::endl;
    std::cin >> date.day;
    std::cout << "Enter month:" << std::endl;
    std::cin >> date.month;
    std::cout << "Enter year:" << std::endl;
    std::cin >> date.year;
    std::cin.ignore();
    return date;
}

void show_date(const Date date)
{
    std::cout << "Day:" << date.day << std::endl;
    std::cout << "Month:" << date.month << std::endl;
    std::cout << "Year:" << date.year << std::endl;
    std::cout << "\n";
}

Address create_address()
{
    Address address;
    std::cout << "Enter street:" << std::endl;
    std::cin.getline(address.street, 30);
    std::cout << "Enter number:" << std::endl;
    std::cin >> address.number;
    std::cin.ignore();
    std::cout << "Enter neighborhood:" << std::endl;
    std::cin.getline(address.neighborhood, 20);
    std::cout << "Enter city:" << std::endl;
    std::cin.getline(address.city, 20);
    std::cout << "Enter state:" << std::endl;
    std::cin.getline(address.state, 3);
    std::cout << "Enter zip_code:" << std::endl;
    std::cin.getline(address.zip_code, 10);
    return address;
}

void show_address(const Address &address)
{
    std::cout << "Street:" << address.street << std::endl;
    std::cout << "Number:" << address.number << std::endl;
    std::cout << "Neighborhood:" << address.neighborhood << std::endl;
    std::cout << "City:" << address.city << std::endl;
    std::cout << "State:" << address.state << std::endl;
    std::cout << "Zip_code:" << address.zip_code << std::endl;
    std::cout << "\n";
}

Employee create_employee()
{
    Employee employee;
    std::cout << "Enter registration:" << std::endl;
    std::cin >> employee.registration;
    std::cin.ignore();
    std::cout << "Enter cpf:" << std::endl;
    std::cin.getline(employee.cpf, 14);
    std::cout << "Enter name:" << std::endl;
    std::cin.getline(employee.name, 50);
    std::cout << "Enter position:" << std::endl;
    std::cin.getline(employee.position, 30);
    std::cout << "Enter phone:" << std::endl;
    std::cin.getline(employee.phone, 15);
    employee.birth_date = create_date();
    employee.address = create_address();
    return employee;
}

void show_employee(const Employee &employee)
{
    std::cout << "Registration:" << employee.registration << std::endl;
    std::cout << "Cpf:" << employee.cpf << std::endl;
    std::cout << "Name:" << employee.name << std::endl;
    std::cout << "Position:" << employee.position << std::endl;
    std::cout << "Phone:" << employee.phone << std::endl;
    show_date(employee.birth_date);
    show_address(employee.address);
    std::cout << "\n";
}
