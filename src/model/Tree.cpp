#pragma once
#include "tree.hpp"

Node *add_tree_cpf(Node *node, Employee employee)
{
    if (node == NULL)
    {
        node = new Node;
        node->info = employee;
        node->left = NULL;
        node->right = NULL;
    }
    else if (strcmp(employee.cpf, node->info.cpf) < 0)
    {
        node->left = add_tree_cpf(node->left, employee);
    }
    else if (strcmp(employee.cpf, node->info.cpf) > 0)
    {
        node->right = add_tree_cpf(node->right, employee);
    }
    else
    {
        return NULL;
    }
    return node;
}

Node *add_tree_name(Node *node, Employee employee)
{
    if (node == NULL)
    {
        node = new Node;
        node->info = employee;
        node->left = NULL;
        node->right = NULL;
    }
    else if (strcmp(employee.name, node->info.name) < 0)
    {
        node->left = add_tree_name(node->left, employee);
    }
    else if (strcmp(employee.name, node->info.name) > 0)
    {
        node->right = add_tree_name(node->right, employee);
    }
    else
    {
        return NULL;
    }
    return node;
}

void search_employee_by_cpf(Node *node, char *cpf)
{
    if (node == NULL)
    {
        std::cout << "Funcionário não encontrado." << std::endl;
        system("pause");
    }
    else if (strcmp(cpf, node->info.cpf) < 0)
    {
        search_employee_by_cpf(node->left, cpf);
    }
    else if (strcmp(cpf, node->info.cpf) > 0)
    {
        search_employee_by_cpf(node->right, cpf);
    }
    else
    {
        show_employee(node->info);
        system("pause");
    }
}

Node *remove_tree_cpf(Node *node, Employee employee)
{
    if (node == NULL)
        return NULL;
    else if (strcmp(employee.cpf, node->info.cpf) < 0)
        node->left = remove_tree_cpf(node->left, employee);
    else if (strcmp(employee.cpf, node->info.cpf) > 0)
        node->right = remove_tree_cpf(node->right, employee);
    else if (node->left && node->right)
    {
        Node *temp = findMin(node->right);
        node->info = temp->info;
        node->right = remove_tree_cpf(node->right, node->info);
    }
    else
    {
        Node *temp = node;
        if (node->left == NULL)
            node = node->right;
        else if (node->right == NULL)
            node = node->left;
        delete temp;
    }

    return node;
}

Node *remove_tree_name(Node *node, Employee employee)
{
    if (node == NULL)
        return NULL;
    else if (strcmp(employee.name, node->info.name) < 0)
        node->left = remove_tree_name(node->left, employee);
    else if (strcmp(employee.name, node->info.name) > 0)
        node->right = remove_tree_name(node->right, employee);
    else if (node->left && node->right)
    {
        Node *temp = findMin(node->right);
        node->info = temp->info;
        node->right = remove_tree_name(node->right, node->info);
    }
    else
    {
        Node *temp = node;
        if (node->left == NULL)
            node = node->right;
        else if (node->right == NULL)
            node = node->left;
        delete temp;
    }

    return node;
}

Node *findMin(Node *node)
{
    if (node == NULL)
        return NULL;
    else if (node->left == NULL)
        return node;
    else
        return findMin(node->left);
}

void search_employee_by_name(Node *node, char *name)
{
    if (node == NULL)
    {
        std::cout << "Funcionário não encontrado." << std::endl;
        system("pause");
    }
    else if (strcmp(name, node->info.name) < 0)
    {
        search_employee_by_name(node->left, name);
    }
    else if (strcmp(name, node->info.name) > 0)
    {
        search_employee_by_name(node->right, name);
    }
    else
    {
        show_employee(node->info);
        system("pause");
    }
}