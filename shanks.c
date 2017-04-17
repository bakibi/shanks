#include "include/include.h"

int main(int argv,char **args)
{
    printf("\t\tTEST\n");
     char s[30];
     strcpy(s,"var x str 10.5 + - * < >=");
     Lexemes *liste = Analyseur_Lexcial(s);

   //printf("%s",Str_formate(s));

   Lexemes *tmp = liste;
   while(tmp)
   {
       printf("%s\n",Lexeme_toString(tmp->lex));
       tmp = tmp->svt;
   }

    return 0;
}