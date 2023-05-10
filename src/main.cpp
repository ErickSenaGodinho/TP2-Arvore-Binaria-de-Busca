#include "system.cpp"

int main()
{

    UINT64 UTF8 = 65001;
    SetConsoleOutputCP(UTF8);

    Tree *employee_tree_cpf = new Tree;
    Tree *employee_tree_name = new Tree;

    unsigned short option;
    do
    {
        option = menu();
        switch (option)
        {
        case 1:
            register_employee(employee_tree_cpf, employee_tree_name);
            break;
        case 2:
            search(employee_tree_cpf, employee_tree_name);
            break;
        case 3:
            remove_employee(employee_tree_cpf, employee_tree_name);
            break;
        case 4:
            print(employee_tree_cpf, employee_tree_name);
            break;
        }
    } while (option != MAX_OPTION);

    return 0;
}