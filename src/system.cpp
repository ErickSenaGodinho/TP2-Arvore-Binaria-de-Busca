#pragma once
#include "system.hpp"

#define MAX_OPTION 5

unsigned short menu()
{
    unsigned short option;
    do
    {
        show_menu();
        std::cin >> option;
        std::cin.ignore();
    } while (!option || option > MAX_OPTION);
    return option;
}

void show_menu()
{
    system("cls");
    std::cout << "(1) Cadastrar funcionário" << std::endl;
    std::cout << "(2) Buscar funcionário" << std::endl;
    std::cout << "(3) Remover funcionário" << std::endl;
    std::cout << "(4) Imprimir" << std::endl;
    std::cout << "(5) Sair" << std::endl;
}

void register_employee(Tree *employee_tree_cpf, Tree *employee_tree_name)
{
    Employee employee = create_employee();
    Node *node_cpf = add_tree_cpf(employee_tree_cpf->root, employee);
    Node *node_name = add_tree_name(employee_tree_name->root, employee);
    if (node_cpf && node_name)
    {
        employee_tree_cpf->root = node_cpf;
        employee_tree_name->root = node_name;
        std::cout << "Funcionário adicionado com sucesso" << std::endl;
        Sleep(2000);
    }
    else
    {
        std::cout << "Funcionário já cadastrado" << std::endl;
        system("pause");
    }
}

void search(Tree *employee_tree_cpf, Tree *employee_tree_name)
{
    unsigned short option;
    do
    {
        show_search_menu();
        std::cin >> option;
        std::cin.ignore();
    } while (!option || option > 2);

    switch (option)
    {
    case 1:
    {
        std::cout << "Digite o nome:" << std::endl;
        char name[50];
        std::cin.getline(name, 50);
        search_employee_by_name(employee_tree_name->root, name);
    }
    break;

    case 2:
    {
        std::cout << "Digite o cpf:" << std::endl;
        char cpf[14];
        std::cin.getline(cpf, 50);
        search_employee_by_cpf(employee_tree_cpf->root, cpf);
    }
    }
}

void show_search_menu()
{
    system("cls");
    std::cout << "(1) Buscar por nome" << std::endl;
    std::cout << "(2) Buscar por cpf" << std::endl;
}

void remove_employee(Tree *employee_tree_cpf, Tree *employee_tree_name, Employee *employee)
{
    if (!employee)
    {
        employee = new Employee();
        std::cout << "Digite o CPF do funcionário: " << std::endl;
        std::cin.getline(employee->cpf, 14);
        std::cout << "Digite o nome do funcionário: " << std::endl;
        std::cin.getline(employee->name, 50);
    }
    employee_tree_cpf->root = remove_tree_cpf(employee_tree_cpf->root, *employee);
    employee_tree_name->root = remove_tree_name(employee_tree_name->root, *employee);
    std::cout << "Removido com sucesso" << std::endl;
    system("pause");
}

void show_print_menu()
{
    system("cls");
    std::cout << "Escolha a forma de imprimir:" << std::endl;
    std::cout << "(1) Em ordem" << std::endl;
    std::cout << "(2) Pré-ordem" << std::endl;
    std::cout << "(3) Pós-ordem" << std::endl;
}

void print(Tree *employee_tree_cpf, Tree *employee_tree_name)
{
    unsigned short print_algorithm;
    do
    {
        show_print_menu();
        std::cin >> print_algorithm;
    } while (!print_algorithm || print_algorithm > 3);
    unsigned short selectet_tree;
    do
    {
        system("cls");
        std::cout << "Deseja imprimir baseado em qual critério?" << std::endl;
        std::cout << "(1) CPF" << std::endl;
        std::cout << "(2) Nome" << std::endl;
        std::cin >> selectet_tree;
        std::cin.ignore();
    } while (!selectet_tree || selectet_tree > 2);

    Tree *tree = selectet_tree == 1 ? employee_tree_cpf : employee_tree_name;

    if (tree->root != nullptr)
    {
        switch (print_algorithm)
        {
        case 1:
            print_inorder(tree->root);
            break;

        case 2:
            print_preorder(tree->root);
            break;

        case 3:
            print_postorder(tree->root);
            break;
        }
        system("pause");
    }
    else
    {
        std::cout << "Nenhum funcionário cadastrado." << std::endl;
        Sleep(2000);
    }
}

void print_inorder(Node *tree)
{
    if (tree->left)
    {
        print_inorder(tree->left);
    }
    show_employee(tree->info);
    if (tree->right)
    {
        print_inorder(tree->right);
    }
}

void print_preorder(Node *tree)
{
    show_employee(tree->info);
    if (tree->left)
    {
        print_preorder(tree->left);
    }
    if (tree->right)
    {
        print_preorder(tree->right);
    }
}

void print_postorder(Node *tree)
{
    if (tree->left)
    {
        print_postorder(tree->left);
    }
    if (tree->right)
    {
        print_postorder(tree->right);
    }
    show_employee(tree->info);
}