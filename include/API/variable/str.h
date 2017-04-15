

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
char *Str_spaceTosc(char *str);
char *Str_scToSpace(char *str);







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
    fprintf(f,"%s _\n",s->name);
    fclose(f);

    return (Str *)s;
}//eof






















//Cette fonction verifie si un Str existe dans le fichier strvalues.tmp
int Str_exists(const char *name1)
{
    FILE *f = fopen("strvalues.tmp","r");
    if(!f) return 0;
    char name[30];
    char value[1000];
    while(!feof(f))
    {
        fscanf(f,"%s %s\n",name,value);
        if(strcmp(name1,name) == 0)
            return 1;
    }
    fclose(f);
    return 0;
}//eof















//  changer la valeur d'un str 
int Str_update(const char *name1,const char *value1)
{
    if(Str_exists(name1))
    {
        char name[30];
        char value[1000];
        FILE *f = fopen("strvalues.tmp","r");
        FILE *wppstr =  fopen("wppstr","w+");
        //copier les donnees dans une wordpaper
        while(!feof(f))
        {
            fscanf(f,"%s %s\n",name,value);
            if(strcmp(name1,name) == 0)
                fprintf(wppstr,"%s %s\n",name,value1);
            else
                fprintf(wppstr,"%s %s\n",name,value);
        }//eow
        fclose(f);
        fclose(wppstr);
        f = fopen("strvalues.tmp","w+");
        wppstr =  fopen("wppstr","r");
        while(!feof(wppstr))
        {
            fscanf(wppstr,"%s %s\n",name,value);
            fprintf(f,"%s %s\n",name,value);
       
        }//eow
         fclose(f);
        fclose(wppstr);
        remove("wppstr");
        return 1;
    }
    return 0;
}//eof























int Str_remove(const char *name1)
{
    if(Str_exists(name1))
    {
        char name[30];
        char value[1000];
        FILE *f = fopen("strvalues.tmp","r");
        FILE *wppstr =  fopen("wppstr","w+");
        //copier les donnees dans une wordpaper
        while(!feof(f))
        {
            fscanf(f,"%s %s\n",name,value);
            if(strcmp(name1,name) != 0)
                fprintf(wppstr,"%s %s\n",name,value);
        }//eow
        fclose(f);
        fclose(wppstr);
        f = fopen("strvalues.tmp","w+");
        wppstr =  fopen("wppstr","r");
        while(!feof(wppstr))
        {
            fscanf(wppstr,"%s %s\n",name,value);
            fprintf(f,"%s %s\n",name,value);
       
        }//eow
         fclose(f);
        fclose(wppstr);
        remove("wppstr");
        return 1;
    }
    return 0;
}//eof