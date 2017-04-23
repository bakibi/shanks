

// la fonction de l analyse Semantique


Grammaires *ase(Grammaires *tout)
{
    Grammaires *tmp  = tout;

    while(tmp)
    {
        tmp = tmp->svt;
    }
    return NULL;
}