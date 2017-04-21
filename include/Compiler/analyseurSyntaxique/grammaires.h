

/*ce fichier contient tout le gramaire possible */


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
typedef struct IF
{
    char *if;
    char *dg;//delimiteur gauche
    
    char *dd;//delimiteur droite

}IF;





/* FIN */