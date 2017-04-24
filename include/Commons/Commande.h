

//      La structure de donnees Commande

typedef struct Commande
{
    char *commande;
    char *warnings;
    char *errors;
    char *output;
    int etat;
}Commande;