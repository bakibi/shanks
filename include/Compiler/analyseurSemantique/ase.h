

// la fonction de l analyse Semantique


Grammaires *ase(Grammaires *tout,char *errors,char *warnings)
{
    Grammaires *tmp  = tout;
    Finale *f = new_Finale();
    while(tmp)
    {
        
        if(tmp->this->type == 0)//  la cas si on a une affichage
            {
                if(Finale_varExists(f,tmp->this->content->lex->value) == 0 || Finale_strExists(f,tmp->this->content->lex->value) == 0)
                    {
                        strcat(errors,"Erreur Semantique : la variable ");
                        strcat(errors,tmp->this->content->lex->value);
                        strcat(errors," n'est pas encore declare .\n");
                    }
            }// fin cas de declaration

            else if (tmp->this->type == 2) //le cas d une declaration
            {
                
            }
        tmp = tmp->svt;
    }
    return NULL;
}