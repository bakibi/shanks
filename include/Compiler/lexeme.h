

//      la structure de donnees Lexeme
typedef struct Lexeme
{
    int taille;
    int type;
    /*
        -1  Value
        0   Nombre
        1   Operation
        2   Chaine de caractère
        3   Mot clées
        4   (
        5   )
        6   [
        7   ]
        8   ==
        9   !=
        10  <
        11  <=
        12  >
        13  >=
        14  !
        15  =
        16  &&
        17  ||   
        18  @
        19 "

    */

    char *value;
}Lexeme;

//      Les prototypes des fonctions

Lexeme *new_Lexeme(char const *l);


//      Les implementations des fonctions 











Lexeme *new_Lexeme(char const *l)
{
    Lexeme *lem = (Lexeme *) malloc(sizeof(Lexeme));
    if(!lem) return NULL;
    
    int taille = sizeof(l);
    lem->taille = taille;
    lem->value =(char *) malloc(taille);
    strcpy(lem->value,l);

    if(taille == 1)
    {
    
        if( (strcmp(l,"+") == 0) || (strcmp(l,"-") == 0) || (strcmp(l,"*") == 0) || (strcmp(l,"/") == 0) || (strcmp(l,"%") == 0)   )
            lem->type = 1;
        if(strcmp(l,"(") == 0 )//
            lem->type = 4;            
        if(strcmp(l,")") == 0 )//
            lem->type = 5;
        if(strcmp(l,"[") == 0 )//
            lem->type = 6;
        if(strcmp(l,"]") == 0 )//
            lem->type = 7;       
        if(strcmp(l,"<") == 0 )
            lem->type = 10; 
        if(strcmp(l,">") == 0 )
            lem->type = 12;   
        if(strcmp(l,"!") == 0 )
            lem->type = 14;
        if(strcmp(l,"=") == 0 )
            lem->type = 15;     
        if(strcmp(l,"@") == 0 )
            lem->type = 18;
        if(strcmp(l,"\"") == 0 )
            lem->type = 19;        
    }//si la taille de la lexeme == 1
    if(taille == 2)
    {
        
    }//si la taille de la lexem == 2

    return (Lexeme *) lem;
}//eod
