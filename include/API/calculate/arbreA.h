/*      Ici se trouce toutes les fonctionnalie d un arbre arithetique */

typedef struct ArbreA
{
    float val;  // la valeur
    char op;        // l operation
    struct ArbreA *fg,*fd;  //le fils gauche et le fils droit
}ArbreA;

//      Prototypes

ArbreA *new_ArbreA();
ArbreA *ArbreA_addV(ArbreA *a,float v);
ArbreA  *ArbreA_addO(ArbreA *a,char op);

//      Implementation

