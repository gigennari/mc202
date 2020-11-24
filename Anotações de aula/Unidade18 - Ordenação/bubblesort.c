void troca(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void bubblesort(int *v, int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {

        for (j = n - 1; j > 1; j--)
        {
            if (v[j] < v[i])
            {
                troca(&v[j - 1], &v[j]);
            }
        }
    }
}

//um pouquinho mais rápido
void bubblesort(int *v, int n)
{
    int i, j, trocou = 1;
    for (i = 0; i < n - 1 && trocou; i++)
    {
        trocou = 0;
        for (j = n - 1; j > 1; j--)
        {
            if (v[j] < v[i])
            {
                troca(&v[j - 1], &v[j]);
                trocou = 1;
            }
        }
    }
}