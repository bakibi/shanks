//      La Grammaire
typedef struct Grammaire
{
    char type;
        //Arithmetique 1
        // Declaration 2
        //  Predicat 3 
        //Affectation 4
        //IF_ELSE 5
        //FOR 6
        //Fonction 7
    Lexemes *content;
    //all the content        
}Grammaire;


//      Les prototypes des fonctions
Grammaire *new_Grammaire(char type,Lexemes *content);




//      Les implementations






Grammaire *new_Grammaire(char type,Lexemes *content)
{
    Grammaire *gr = NULL;
    Lexemes *pt = content;
    if(pt == NULL) return NULL;
    
    gr = (Grammaire *)malloc(sizeof(Grammaire));
    gr->type = type;
    gr->content = content;
    
    return gr;
}//end of function