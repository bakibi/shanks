

/* La structure de données */
typedef struct Str
{
     char *name; // le nom 
     char *value; // la valeur
}Str;


//  les prototypes

Str *new_Str(const char *name);
int Str_exists(const char *name);
int Str_update(const char *name,const char *value);
int Str_remove(const char *name);


//  les implementation des fonction












//  creation d une nouvelle instance de Str
Str *new_Str(const char *name)
{
    Str *s = (Str *)malloc(sozeof(Str));
    if(!s) return NULL;
    s->name = (char *)malloc(strlen(name));
    s->value = (char *)malloc(sierof(char)*2);
    strcpy(s->name,name);
    strcpy(s->value,"");


    return (Str *)s;
}//eof





