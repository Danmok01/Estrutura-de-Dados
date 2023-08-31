#include <iostream>
#define N 6

using namespace std;


void intercala (int V[], int inicio, int fim ,int meio)
{
    int i, aux [N], posLivre = inicio, inicioA1 = inicio, inicioA2= meio+1;
    while (inicioA1 <= meio && inicioA2 <= fim)
    {
        if(V[inicioA1]> V[inicioA2])
        {
            aux[posLivre] = V[inicioA2];
            inicioA2 ++;
        }
        else 
        {
            aux[posLivre]=V[inicioA1];
            inicioA1 ++;
        }
        posLivre ++;
    }
    for(i=inicioA1;i<=meio;i++)
    {
        aux[posLivre]=V[i];
        posLivre ++;
    }
    for(i=inicioA2;i<=fim;i++)
    {
        aux[posLivre]=V[i];
        posLivre ++;
    }
    for(i=inicio;i<=fim;i++)
    {
        V[i]=aux[i];
    }
}


void mergeSort (int V[], int inicio, int fim)
{
    int meio;
    if (inicio < fim)
    {
        meio =(inicio +fim)/2;
        mergeSort(V, inicio, meio);
        mergeSort(V,meio + 1,fim);
        intercala(V,inicio, fim ,meio);
    }
}






int main ()
{
    int i, V[N]={5,81,10,50,40,39};
    mergeSort(V,0,N-1);

    for( i = 0; i < N; i++)
    {
        cout<< V[i]<<"\t";
    }
    
    return 0;

}