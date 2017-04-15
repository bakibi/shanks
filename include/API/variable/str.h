

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
    Str *s = (Str *)malloc(sizeof(Str));
    if(!s) return NULL;
    s->name = (char *)malloc(strlen(name));
    s->value = (char *)malloc(sizeof(char)*2);
    strcpy(s->name,name);
    strcpy(s->value,"");

    FILE *f = fopen("strvalues.tmp","a+");
    fprintf(f,"%s _%s_\n",s->name,s->value);
    fclose(f);

    return (Str *)s;
}//eof





