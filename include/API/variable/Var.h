
/* La structure de donnees */

typedef struct Var 
{
    float value;
    char *name;
    int type;  // (0) int (1) float
}Var;

//      Les prototypes

Var *new_Var(const char *name,int type);
int Var_exists(const char *name);




//      Les implementation des fonctions














// creation d une nouvelle variable
Var *new_Var(const char *name,int type)
{
    Var  *v = (Var *)malloc(sizeof(Var));
    v->value = 0;
    v->type = type;
    v->name = (char *)malloc(strlen(name));
    strcpy(v->name,name);
    // enregistrement dans le fichier
    FILE *fichier = NULL;
    fichier = fopen("values.txt","w+");
    if(!fichier) return NULL;
    
   fseek(fichier,0,SEEK_END);
    fprintf(fichier,"%s %d %f",v->name,v->type,v->value);

    fclose(fichier);// fermer le fichier
    return v;
}//eof


