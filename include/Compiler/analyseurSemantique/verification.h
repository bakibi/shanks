
//                                                          Analyse semantique
/*      Ce fichier contient tout les fonction qui vont permetre de verifier pendant l'analyse semantique */

//      les prototypes 
int verifier_arrithmetique(Grammaire *gr,Finale *f,char *errors);
int verifier_decclaration(Grammaire *gr,Finale *f,char *errors,char *warnings);


//      les implentations



int verifier_arrithmetique(Grammaire *gr,Finale *f,char *errors)
{
    Lexemes *tmp = gr->content;

    int r = 0;
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

        if(e ==5 && tmp->lex->type == 5) 
            {
                strcat(errors,"Erreur semantique : Vous ne pouvez pas faire () .\n");
                r++;
            }
          if(e ==6 && tmp->lex->type !=1 &&  tmp->lex->type != 2 &&  tmp->lex->type != 5  )  
          {
              strcat(errors,"Erreur semantique : Apres ) vous devez mettre une operation .\n");
                r++;
          }
          if((e == 1 || e == 2) &&   tmp->lex->type == 5 )
          {
               strcat(errors,"Erreur semantique : Apres une operation vous ne pouvez pas fermer une pare ) .\n");
                r++;
          }
          if(  tmp->lex->type ==-1 && Finale_varExists(f,tmp->lex->value) == 0)
          {
              strcat(errors,"Erreur semantique : La variable  \"");
              strcat(errors,tmp->lex->value);
              strcat(errors,"\" n'est pas encore declarer .\n");
                r++;
          }

        
        //  le changement d'etat
        if(tmp->lex->type == 1 && (strcmp(tmp->lex->value,"+") == 0 || strcmp(tmp->lex->value,"-") == 0 ))    e = 1;
        else if(tmp->lex->type == 1)    e = 2;
        else if(tmp->lex->type == 0)    e = 3;
        else if(tmp->lex->type == -1)   e = 4;
        else if(tmp->lex->type == 4)    e = 5;
        else if(tmp->lex->type == 5)    e = 6;
        tmp = tmp->svt;//suivant
    }
    if( e == 1 || e == 2)
        {
            strcat(errors,"Erreur semantique : Le calcul arithmetique ne doit pas se terminer par une opeartion .\n");
                r++;
        }

    if(r == 0)
        return 1;//true
    return 0;//false   
}//eof

















// fonction de verification d une verifier_decclaration
int verifier_decclaration(Grammaire *gr,Finale *f,char *errors,char *warnings)
{

    Lexemes *tmp = gr->content;

    int r = 0;
    int e = 0;
    //      0       ->      debut
    //      1       ->      var
    //      2       ->      =
    //      3       ->      value
    //      4       ->      ,
    tmp = tmp->svt;
    while(tmp)
    {

        if(tmp->lex->type == -1) e = 1;
        else if(tmp->lex->type == 0) e = 3;
        else if(tmp->lex->type == 15) e = 2;
        else if(tmp->lex->type == 25) e = 4;

        tmp = tmp->svt;
    }
    return 1;//true
}//eof