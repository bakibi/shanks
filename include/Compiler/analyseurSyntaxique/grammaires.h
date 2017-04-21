

/*ce fichier contient tout le gramaire possible */



//  La declaration des variables
typedef struct decl_var
{
    char *type;
    char *name;
    char *value;
}decl_var;



// la structre de donnees exp_arithmetique 
typedef struct exp_arith 
{
    char *gauche;
    char *op;
    char *droite;

} exp_arith;







//  La structure de donnees predicat
typedef struct Predicat
{
    char *gauche; // le delimiteur gauche 
    char *op; //l operation     
    char *droite;// le delimiteur droit
}Predicat;








//  La structure de donnees IF
typedef struct IF_ELSE
{
    char *type;
    char *dg;//delimiteur gauche
    Predicat *predicat; // le predicat 
    char *dd;//delimiteur droite
    char *exp;

}IF_ELSE;




/* FIN */