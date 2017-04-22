


 Grammaires *as(Lexemes *all)
 {
     Grammaires *liste  = new_Grammaires();
     if(all == NULL) return NULL;
    Lexemes *tmp = all;

    // Lanalyse commence ici
    
     while(tmp)
     {
         if(tmp->lex->type == 21) ;

         else if(tmp->svt == NULL || tmp->svt->lex->type==21)
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
        }//fin else
        if(tmp)
            tmp = tmp->svt;
                    
     }//end of while
     return liste;
 }
