

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
        
    */

    char *value;
}Lexeme;

//      Les prototypes des fonctions

Lexeme *new_Lexeme(char const *l);


//      Les implementations des fonctions 
















Lexeme *new_Lexeme(char const *l)
{
    Lexeme *lem = (Lexeme *) malloc(sizeof(Lexeme));
    (if!lem) return NULL;
    
}//eod
