#include "include/include.h"

int main(int argv,char **args)
{
    printf("\t\tTEST\n");
    
    ArbreA *a = new_ArbreA();
    a = ArbreA_addO(a,'-'); 
    a = ArbreA_addV(a,10);
    a = ArbreA_addO(a,'*'); 
    a = ArbreA_addV(a,1);
    a = ArbreA_addO(a,'+');
    a = ArbreA_addV(a,10);
    a = ArbreA_addO(a,'*');
    a = ArbreA_addV(a,5);

   

    ArbreA_toString(a);
    printf(" \n val :%f\n",ArbreA_evaluer(a));
    return 0;
}