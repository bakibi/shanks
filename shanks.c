#include "include/include.h"

int main(int argv,char **args)
{
    printf("\t\tTEST\n");
     char s[30];
     strcpy(s,"var x str 10.5 + - * < >=");
     
   printf("%s",Str_formate(s));

    return 0;
}