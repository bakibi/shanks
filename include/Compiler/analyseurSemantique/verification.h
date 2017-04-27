
//                                                          Analyse semantique
/*      Ce fichier contient tout les fonction qui vont permetre de verifier pendant l'analyse semantique */

//      les prototypes 
int verifier_arrithmetique(Grammaire *gr);


//      les implentations



int verifier_arrithmetique(Grammaire *gr)
{
    Lexemes *tmp = gr->content;

    int e = 0;
    //      0       ->      debut
    //      1       ->      +   or  -
    //      2       ->      *   /   or  %
    //      3       ->      nbr
    //      4       ->      var
    //      5       ->      (
    //      6       ->      )
    while(tmp)
    {

        
        //  le changement d'etat
        if(tmp->lex->type == 1 && (strcmp(tmp->lex->value,"+") == 0 || strcmp(tmp->lex->value,"-") == 0 ))    e = 1;
        else if(tmp->lex->type == 1)    e = 2;
        else if(tmp->lex->type == 0)    e = 3;
        else if(tmp->lex->type == -1)   e = 4;
        else if(tmp->lex->type == 4)    e = 5;
        else if(tmp->lex->type == 5)    e = 6;
        tmp = tmp->svt;//suivant
    }

    return 1;//true   
}