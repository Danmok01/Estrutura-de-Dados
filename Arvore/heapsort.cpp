#include <iostream>

#define T 7

void troca(int *a, int *b)
{
    int aux;
    aux= *a;
    *a=*b;
    *b=aux;
}

void descer(int A[], int i, int q)
{
    int d= 2*i +2;
    int e= 2*i +1;
    int maior = i;

    if(d <= q && A[d]>A[i])
    {
        maior = d;
    }
    if(e <= q && A[e]>A[maior])
    {
        maior = e;
    }
    if(maior !=i)
    {
        troca(&A[i], &A[maior]);
        descer(A, maior, q);
    }

}

void heap(int A[], int t)
{
    for(int i= (t/2); i>=0; i--)
    {
        descer(A,i,t-1);
    }
}

void heapsort(int A[], int n)
{
    int i;

    heap(A,T);


    for (i=n-1; i>=1; i--)
    {
        troca(&A[0], &A[i]);
        descer(A, 0 , i-1);
    }
}



using namespace std;

main()
{
   // int V[T]={50,2,75,8,10,6,15,4,9,3};
    int V[T]={80,35,20,60,42,36,85};
   // int V[T]={85,60,80,35,42,36,20};
    int i;

    heapsort(V,T);

    for(i=0; i<T; i++)
    {
        cout<<V[i]<<"\t";
    }

}