

//          La strucutre de donnees Space 
//                  ----> c'est ici ou le tavail ce fait

typedef struct Space
{
    char *name;  //le nom de l'espace'
    Commande *all; //tout les commande sous forme d'une liste
    char *fileVar;  //le ficheir qui contient les Var
    char *fileStr; // le fichier qui contient   les Str
}Space;