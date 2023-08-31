#include <iostream>
#define N 6

using namespace std;

void troca (int*a, int*b)
{
    int aux = *a;
    *a = *b;
    *b =aux;
}


int partition (int V[], int inicio, int fim)
{
    int k = V[fim];
    int i = (inicio -1);
    for (int j = inicio; j<= fim -1; j++)
    {
        if (V[j]<= k)
        {
            i++;
            troca(&V[i], &V[j]);

        }
    }
    troca (&V[i+1], &V[fim]);
    return (i+1);
}




void quickSort(int V[], int inicio, int fim)
{
    if (inicio <fim)
    {
        int k = partition (V, inicio , fim);
        quickSort(V, inicio , k-1);
        quickSort(V, k+1 , fim);
    }
}





int main ()
{
    int i, V[N]={5,10,80,50,40,39};
    quickSort(V,0,N-1);

    for( i = 0; i < N; i++)
    {
        cout<< V[i]<<"\t";
    }
    return 0;

}