#ifndef TREE_H
#define TREE_H

#include <cstring>
#include "Employee.cpp"

typedef struct Node
{
    Employee info;
    Node *left = nullptr;
    Node *right = nullptr;
};

typedef struct Tree
{
    Node *root = nullptr;
};

Node *add_tree_cpf(Node *node, Employee employee);
Node *add_tree_name(Node *node, Employee employee);
Node *remove_tree_cpf(Node *node, Employee employee);
Node *remove_tree_name(Node *node, Employee employee);
Node *findMin(Node *node);
void search_employee_by_cpf(Node *node, char *cpf);
void search_employee_by_name(Node *node, char *name);

#endif