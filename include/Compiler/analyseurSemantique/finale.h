

// la structure de donnees 

typedef struct Finale
{
    L_S_var *l1;
    L_S_str *l2;
}Finale;

//      Les prototypes
Finale *new_Finale();
Finale *Finale_addVar(Finale *f,const char *name,const char *value);
//      les implementations



//      creation
Finale *new_Finale()
{
    Finale *tmp = (Finale *)malloc(sizeof(Finale));
    if(tmp== NULL) return NULL;
    tmp->l1 = NULL;
    tmp->l2 = NULL;
    return tmp;
}//eof


//      adding une variable
Finale *Finale_addVar(Finale *f,const char *name,const char *value)
{

    
    return f;
}