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
     
   Space *sp = new_Space("souhail");
   Commande *cmd = new_Commande(s);
    cmd = Commande_interpreter(cmd);
   sp  = Space_delete(sp);

    return 0;
}