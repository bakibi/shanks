#include "include/include.h"

int main(int argv,char **args)
{
    printf("\t\tTEST\n");
     char s[300];
     printf("---> ");
     gets(s);
     Lexemes *liste = al(s);//analyse lexicale
     
   //printf("%s",Str_formate(s));

   printf("\n");
   Lexemes *tmp = liste;
   while(tmp)
   {
       printf("%s\n",Lexeme_toString(tmp->lex));
       tmp = tmp->svt;
   }
   
   Grammaires *listeS = as(liste);//analyse syntaxique
   
   

    return 0;
}