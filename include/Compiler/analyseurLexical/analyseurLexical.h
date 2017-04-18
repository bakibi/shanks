

#include "lexeme.h"
#include "lexemes.h"


Lexemes *Analyseur_Lexcial(const char *phrase)
{
    Lexemes *liste = new_Lexemes();
    
    int taille = strlen(phrase);
    int esp_debut = 1;
    char mot[2000];
    int j = 0;
    
    for(int i=0;i<taille;i++)
    {
        if(phrase[i] == ' ' || phrase[i] == '\t' || phrase[i] == '\n' )
            {
                if(esp_debut == 1)
                    continue;
                mot[j] = '\0';                    
                Lexeme *nn = new_Lexeme(mot);
                liste = Lexemes_add(liste,nn);
                strcpy(mot,"");
                esp_debut = 1;
                j = 0;
            }
            
            else 
            {
              mot[j] = phrase[i];
               j++;
                esp_debut = 0;
            }
    }//e of for

    if(esp_debut == 0)  
        {
            mot[j] = '\0';  
             Lexeme *nn = new_Lexeme(mot);
                liste = Lexemes_add(liste,nn);

        }
    return liste;
}



// cette fonction et plus devlopper par rapport   à la premiere fonction 
Lexemes *Analyseur_LexcialV1(const char *phrase)
{
    Lexemes *liste = NULL;
    int taille  = strlen(phrase);
    char mot[2000];
    int j = 0;
    int est_valide = 0;

    // partie analyse 
    for(int i=0;i<taille;i++)
    {
           
    }
    return liste ;
}//eof