

//      La structure de donnees Commande

typedef struct Commande
{
    char *commande;  // La Commande
    char *warnings;     //  Les Warnings rencotrer apres compilation
    char *errors;           //  Les erreurs rencontrer apres compilation
    char *output;           //  Le output est le resultat de la commande si elle est sans faute
    int etat;                   //  L'etat de la commande
    int outstat;                //  Letat de sortir // veut dire que si la commande est complete ou pas 
}Commande;



//      LEs prototypes 
Commande *new_Commande(const char *chaine);
Commande *Commande_interpreter(Commande *cmd);

//      Les implementations



//      Creation d une nouvelle commande
Commande *new_Commande(const char *chaine)
{
    Commande *cmd  = (Commande *)malloc(sizeof(Commande));
    if(!cmd) return NULL;
    cmd->commande = (char *)malloc(strlen(chaine)); strcpy(cmd->commande,chaine);
    cmd->warnings = cmd->errors = cmd->output = NULL;
    cmd->etat = cmd->outstat = 0;
    return cmd;
}//eof









//      interpreter une commande
Commande *Commande_interpreter(Commande *cmd)
{   
    if(cmd == NULL) return NULL;


     Lexemes *liste = al(cmd->commande);//analyse lexicale
      printf("-------------Analyse Lexicale\n");
     Lexemes_toString(liste);


   printf("-------------Analyse Syntaxique\n");
   Grammaires *listeS = as(liste);//analyse syntaxique
   Grammaires_toString(listeS);


    return cmd;
}




