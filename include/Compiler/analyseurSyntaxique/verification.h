

//      Les prototypes des fonction en bas
int verifier_parentheses(Lexemes *lex);
int verifier_quotation(Lexemes *lex);
int verifier_brackets(Lexemes *lex);
int verifier_squares(Lexemes *lex);
int verifier_declaration(Lexeme *lex);
Lexeme *verifier_arithmetique(Lexemes *lex);




//      verifier les parentheses
int verifier_parentheses(Lexemes *lex)
{
    Lexemes *tmp = lex;
    PileSyn *pile = new_PileSyn();
    int v = 0;
    int v_chaine = 0;
    int v_avant = 0;
    while(tmp)
    {
        v=tmp->lex->type;
            if(v == 19 && v_avant!=20)
                v_chaine = 1-v_chaine;
        if(v==4  || v==5)
        {
            if(v_chaine==0)
            {
                if(pile == NULL) pile = PileSyn_empiler(pile,v);
                 else if(v==5 && pile->v==4) pile = PileSyn_depiler(pile);
                 else pile = pile = PileSyn_empiler(pile,v);
            }
        }//fin if
        tmp = tmp->svt;
        v_avant = v;
    }//fin while
    if(pile==NULL)
        return 1;
    return 0;        
}//eof






//          Verifier les quotes
int verifier_quotation(Lexemes *lex)
{
    Lexemes *tmp = lex;
    PileSyn *pile = new_PileSyn();
    int v = 0;
    int c = 0;
    int v_avant = 0;
    while(tmp)
    {
        v=tmp->lex->type;
        if(v==19)
        {
            if(v_avant!=20)
            c++;
        }//fin if
        tmp = tmp->svt;
        v_avant = v;
    }//fin while
    if(c%2 ==0 && c!=1  )
        return 1;
    return 0;        
}//eof












//      verifier les brackets
int verifier_brackets(Lexemes *lex)
{
    Lexemes *tmp = lex;
    PileSyn *pile = new_PileSyn();
    int v = 0;
     int v_chaine = 0;
    int v_avant = 0;
    while(tmp)
    {
        v=tmp->lex->type;
          if(v == 19 && v_avant!=20)
                v_chaine = 1-v_chaine;
        if(v==23  || v==24)
        {
            if(v_chaine==0)
            {
                if(pile == NULL) pile = PileSyn_empiler(pile,v);
                else if(v==23 && pile->v==24) pile = PileSyn_depiler(pile);
                else pile = pile = PileSyn_empiler(pile,v);
            }
        }//fin if
        tmp = tmp->svt;
        v_avant = v;
    }//fin while
    if(pile==NULL)
        return 1;
    return 0;        
}//eof






//      verifier les squares
int verifier_squares(Lexemes *lex)
{
    Lexemes *tmp = lex;
    PileSyn *pile = new_PileSyn();
    int v = 0;
   int v_chaine = 0;
    int v_avant = 0;
    while(tmp)
    {
        v=tmp->lex->type;
       if(v == 19 && v_avant!=20)
                v_chaine = 1-v_chaine;
        if(v==6  || v==7)
        {
             if(v_chaine==0)
            {
            if(pile == NULL) pile = PileSyn_empiler(pile,v);
            else if(v==6 && pile->v==7) pile = PileSyn_depiler(pile);
            else pile = pile = PileSyn_empiler(pile,v);
            }
        }//fin if
        tmp = tmp->svt;
         v_avant = v;
    }//fin while
    if(pile==NULL)
        return 1;
    return 0;        
}//eof







//  verifier si un lexemes est pour la declaration
int verifier_declaration(Lexeme *lex)
{
    if(strcmp(lex->value,"str")==0 || strcmp(lex->value,"var")==0)
        return 1;

    return 0;
}







  Lexeme *verifier_arithmetique(Lexemes *lex)
  {


      Lexemes *tmp = lex;
      int v = -5;
      int e = 0; // debut
                    // + - ---> 1
                    // * / % ----> 2
                    // var / nmbre ----> 3
      while(tmp)
      {
          v = tmp->lex->type;
          if(v == -1 || v == 0 || v == 1 || v == 4 || v == 5)
             { 
                 if(e == 0 && v == 1 && ( strcmp(tmp->lex->value,"*") == 0 || strcmp(tmp->lex->value,"/") == 0 || strcmp(tmp->lex->value,"%") == 0))
                    return tmp->lex;//cas d erreur debut avec 
                if(e == 1 && v == 1 && ( strcmp(tmp->lex->value,"*") == 0 || strcmp(tmp->lex->value,"/") == 0 || strcmp(tmp->lex->value,"%") == 0))
                    return tmp->lex;//cas de 4+*5
                if(e == 2 && v == 1 && ( strcmp(tmp->lex->value,"*") == 0 || strcmp(tmp->lex->value,"/") == 0 || strcmp(tmp->lex->value,"%") == 0))
                    return tmp->lex; // cas de 4**5

                 if(v == 1 && ( strcmp(tmp->lex->value,"*") == 0 || strcmp(tmp->lex->value,"/") == 0 || strcmp(tmp->lex->value,"%") == 0))
                    e = 2;
                else if(v == 1)
                    e = 1;
                else e  = 3;   

                 tmp = tmp->svt;
             }
          else 
             return tmp->lex;
      }// fin while

      return NULL;
  }