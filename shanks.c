#include "include/include.h"

int main(int argc,char *argv[])
{
     char s[9000];
 
     FILE *f = fopen(argv[1],"r");

     if(f == NULL)
     {
         printf("\n\t Probleme :Le fichier et introuvable ou il est utilises par un autre programme !\t");
         
         return 0;
     }

     char c ;
     int i=0;
     while((c = fgetc(f))!=EOF)
     {
         s[i] = c;
         i++;
     }
     s[i] = '\0';
     printf("%d",i);
     fclose(f);
     Lexemes *liste = al(s);//analyse lexicale

     printf("-------------Analyse Lexicale\n");
     Lexemes_toString(liste);
  
   printf("-------------Analyse Syntaxique\n");
   Grammaires *listeS = as(liste);//analyse syntaxique
   Grammaires_toString(listeS);
   
   

    return 0;
}