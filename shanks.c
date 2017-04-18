#include "include/include.h"

int main(int argv,char **args)
{
    printf("\t\tTEST\n");
     char s[30];
     strcpy(s,"str str1 = \"reda\"");
     Lexemes *liste = Analyseur_LexcialV1(s);

   //printf("%s",Str_formate(s));

   Lexemes *tmp = liste;
   while(tmp)
   {
       printf("%s\n",Lexeme_toString(tmp->lex));
       tmp = tmp->svt;
   }
   

    return 0;
}