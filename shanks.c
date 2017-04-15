#include "include/include.h"

int main(int argv,char **args)
{
    printf("\t\tTEST\n");
    
    Var *v1 = new_Var("v1",1);
    Var *v2 = new_Var("x1",1);
    Var *v13 = new_Var("r1",1);
    Var *v134 = new_Var("e1",1);

    printf("\n %d",Var_exists("e"));
    Var_update("r1",14,2);
    Var_update("x1",-32000,1);
    Var_remove("vdfgd");
    return 0;
}