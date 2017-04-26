

//      C'est la deuxieme etape d  une analyse syntaxique
int as1(Grammaires *all,char *errors)
{

    Grammaires *tmp = all;
    
    while(tmp)
    {
        
        if(tmp->this->type == 0) //le cas d un affichage
        {
                
            Lexemes *le = tmp->this->content;
            Lexemes *tp = le;
            if(le->lex->type == -1 && le->svt != NULL)// le cas d un affichage normal d une variable
                    strcat(errors,"Erreur Syntaxique : probleme dans l'affichage .\n");
            else if (Lexeme_estKey(le->lex->value))
                     strcat(errors,"Erreur Syntaxique : probleme dans l'affichage usage d un nom de variable incorret.\n");
            else if(le->lex->type == 19)// le cas d une affichage d une chaine de caractere ""
            {
                tp = tp->svt;
                while(tp!= NULL && tp->lex->type!=19)  tp = tp->svt;
               if(tp->svt != NULL)
                          strcat(errors,"Erreur Syntaxique : probleme dans l'affichage de la chaine de caractere . \n");
            }
        }//fin le cas d un affichage
        else if(tmp->this->type == 1) //le cas d un calcul arithmetique
        {
            Lexemes *le = tmp->this->content;
            Lexemes *tp = le;
            Lexeme *result = verifier_arithmetique(tp);
            if(result != NULL)
                strcat(errors,"Erreur Syntaxique : probleme dans le calcul arithmetique  . \n");
        }

        tmp = tmp->svt;
    }




    return 1;
}