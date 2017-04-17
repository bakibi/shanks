#include "include/include.h"

int main(int argv,char **args)
{
    printf("\t\tTEST\n");
     char s[30];
     strcpy(s,"salut tout le \n \n \t \t   sdkfun s  monde");
   printf("%s",Str_formate(s));

    return 0;
}