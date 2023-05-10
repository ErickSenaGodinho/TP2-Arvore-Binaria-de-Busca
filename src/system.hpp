#include <iostream>
#include <windows.h>
#include "./model/Tree.cpp"
#include "./model/Employee.cpp"

unsigned short menu();
void show_menu();
void register_employee(Tree *employee_tree_cpf, Tree *employee_tree_name);
void search(Tree *employee_tree_cpf, Tree *employee_tree_name);
void show_search_menu();
void remove_employee(Tree *employee_tree_cpf, Tree *employee_tree_name, Employee *employee = NULL);
void show_print_menu();
void print(Tree *employee_tree_cpf, Tree *employee_tree_name);
void print_inorder(Node *tree);
void print_preorder(Node *tree);
void print_postorder(Node *tree);