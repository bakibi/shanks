

//      la structure de donnees Lexeme
typedef struct Lexeme
{
    int taille;
    int type;
    /*
        -1  Value
        0   Nombre
        1   Operation
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
int Lexeme_estKey(char const *t);
int Lexeme_estNum(char const *t);
const char  *Lexeme_toString(Lexeme *l);

//      Les implementations des fonctions 










//  Cette fonction prend en parametre une chaine de caratere et deduit de une lexeme
Lexeme *new_Lexeme(char const *l)
{
    Lexeme *lem = (Lexeme *) malloc(sizeof(Lexeme));
    if(!lem) return NULL;
    
    int taille = strlen(l);
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
        if(strcmp(l,"==") == 0 )
            lem->type = 8;
        else if(strcmp(l,"!=") == 0 )
            lem->type = 9;
        else if(strcmp(l,"<=") == 0 )
            lem->type = 11;
        else if(strcmp(l,">=") == 0 )
            lem->type = 13;
        else if(strcmp(l,"&&") == 0 )
            lem->type = 16;
        else if(strcmp(l,"||") == 0 )
            lem->type = 17;
    }//si la taille de la lexem == 2
    else
    {
        if(Lexeme_estKey(l))
            lem->type = 3;
        else if(Lexeme_estNum(l))
            lem->type = 0;
        else 
            lem->type = -1;            
        
    }//si la taille est superieur à 2
    return (Lexeme *) lem;
}//eof








//      Cette foction verifie si un str est un mots
int Lexeme_estKey(char const *t)
{
    const char *mots[8] = 
                                    {
                                      "var",
                                      "str",
                                      "for",
                                      "while",
                                      "if",
                                      "else"
                                      "switch",
                                      "case",  
                                    };
                                    
    for(int i=0;i<8;i++)
        if(strcmp(t,mots[i]) == 0)
            return 1;
    return 0;                                    
}//eof

int Lexeme_estNum(char const *t)
{
    int taille = strlen(t);
    for (int i=0;i<taille;i++)
        if( !('0'<=t[i] && t[i]<='9') && t[i] !='.' )
            return 0;
    return 1;
}//eof



const char  *Lexeme_toString(Lexeme *l)
{
    char *res = NULL;
    char tt[2];
     if(l == NULL) return NULL;
     res = (char *)malloc(l->taille + 4);
     sprintf(tt, "%d", l->type);
     strcpy(res,l->value);
     strcat(res," ");
     strcat(res,tt);
     

     return res;
}//eof