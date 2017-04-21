
//      La Grammaire
typedef struct Grammaire
{
    char *type;
        //Arithmetique
        // Declaration
        //  Predicat
        //Affectation
        //IF_ELSE
        //FOR
        //Fonction
    char *content;
    //all the content        
}Grammaire;



//      La strucure de donnees Grammaires c est une liste chainee
typedef struct Grammaires
{
    Grammaire *grm;
    struct Grammaires *svt;
}Grammaire;



/* FIN */