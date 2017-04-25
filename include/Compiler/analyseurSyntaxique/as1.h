

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
            if(le->lex->type == -1 && le->svt != NULL)
                    strcat(errors,"Erreur Syntaxique : probleme dans l'affichage \n");
            else if(le->lex->type == 19)
            {

            }
        }//fin le cas d un affichage

        tmp = tmp->svt;
    }




    return 1;
}