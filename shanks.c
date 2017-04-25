#include "include/include.h"

int main(int argc,char *argv[])
{
     char *commande = readFromFile(commande,argv[1]);
     
   Space *sp = new_Space("souhail");
   Commande *cmd = new_Commande(commande);
    cmd = Commande_interpreter(cmd);
   sp  = Space_delete(sp);

    return 0;
}