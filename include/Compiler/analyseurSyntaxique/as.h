


 Grammaires *as(Lexemes *all)
 {
     Grammaires *liste  = new_Grammaires();
     if(all == NULL) return NULL;
    Lexemes *tmp = all;

    // Lanalyse commence ici
    if(verifier_parentheses(all)==0)
        printf(" Erreur Syntaxique : il y a une erreur par rapport au parentheses () .\n");

     if(verifier_quotation(all)==0)
        printf(" Erreur Syntaxique : il y a une erreur par rapport au quotes \"\" .\n");

     if(verifier_brackets(all)==0)
        printf(" Erreur Syntaxique : il y a une erreur par rapport au brackets {} .\n");
    
    if(verifier_squares(all)==0)
        printf(" Erreur Syntaxique : il y a une erreur par rapport au squares [] .\n");
        

     while(tmp)
     {
         if(tmp->lex->type == 21) ;// quand ; apparait sauter a l'autre lexeme'

         else if(tmp->svt == NULL || tmp->svt->lex->type==21) // affichage
        {
            Grammaire *g = new_Grammaire(0,tmp);
            liste = Grammaires_add(liste,g);
        }
        else
        {
         
             if(tmp->lex->type == -1 && tmp->svt!=NULL && tmp->svt->lex->type == 15)//le cas d une affectation
            {
                Lexemes *l = new_Lexemes();
                while(tmp!=NULL && tmp->lex->type != 21)
                {
                    l = Lexemes_add(l,tmp->lex);
                    tmp =tmp->svt;
                }
                Grammaire *g = new_Grammaire(4,l);
                liste = Grammaires_add(liste,g);
            }//fin cas affectation

            if(tmp->lex->type == 0 || tmp->lex->type == 1) // si ça commence par une ope ou un nombre
            {
                 Lexemes *l = new_Lexemes();
                while(tmp!=NULL && tmp->lex->type != 21)// jusqu au null ou ;
                {
                    l = Lexemes_add(l,tmp->lex);
                    tmp =tmp->svt;
                }
                Grammaire *g = new_Grammaire(1,l);
                liste = Grammaires_add(liste,g);
            }//fin cas  par une ope ou un nombre

            if(tmp->lex->type == 3)// si c est pour une declaration
            {
                if(verifier_declaration(tmp->lex) == 1)
                {
                     Lexemes *l = new_Lexemes();
                while(tmp!=NULL && tmp->lex->type != 21)// jusqu au null ou ;
                {
                    l = Lexemes_add(l,tmp->lex);
                    tmp =tmp->svt;
                }
                Grammaire *g = new_Grammaire(1,l);
                liste = Grammaires_add(liste,g);
                }
            }
        }//fin else
        if(tmp)
            tmp = tmp->svt;
                    
     }//end of while
     return liste;
 }
