#include "include/include.h"

int main(int argv,char **args)
{
    printf("\t\tTEST\n");
    
    Str *s = new_Str("str13");
    Str_exists("drg");
    Str_update("str2","salut$tout$le$monde");
    Str_remove("str2");
    return 0;
}