#include <iostream>
#include <cstdlib>
#include <ctime>
#define N 10
#define J N*2
//Nao esta rodando no replit, so no vscode
using namespace std;

int criar(int D[])
{
    int i;
    
    for(i=0; i<N ;i++)
    {
        D[i] = 1+rand () %100;
      
    }

    return 0;
}

int intercala(int A1[], int A2[],int C1[])
{
    int t=0;
    for(int i=0; i<N; i++)
    {
        C1[t]=A1[i];
        t=t+2;

    }

    t=1;
    for(int i=0; i<N; i++)
    {
        C1[t]=A2[i];
        t=t+2;

    }
    return 0;
}

int exibe(int E[], int k)
{
    int i;
    for(i=0; i<k ;i++)
    {
        cout<<E[i]<<"\t";
    }
    cout<< endl;
}


void busca(int V[], int k)
{
  bool achei = false;
  int j = 0;

  
  while(j<J && achei == false)
  {
    if(V[j]==k)
    {
      achei = true;
            
    }
    else 
    {
      j++;
    }
  }
  if(achei==true)
  {
    cout<<"Achei ";
    cout<< "O numero esta na posicao "<< j+1<<endl;
    
  }
  else
  {
    cout<<"Nao achei"<<endl;
  }
}

int deletar(int A[])
{
int i1,j1,g;
int del=2;
for(g=0;g<del;g++)
{
    for(i1=0;i1<N;i1++)
    {
            
        A[i1]=A[i1+1];
    }
}

   
    int i;
    for(i=0; i<8 ;i++)
    {
        cout<<A[i]<<"\t";
    }
    cout<< endl;
}


int main ()
{
    int A[N],B[N],C[J],i,num;
    time_t seed = time(0);
    srand (seed);

    criar(A);
    criar(B);
   
    intercala(A,B,C);
   
    exibe(A, N);
    exibe(B, N);
    exibe(C, J);
    cout<<"Achar o numero : ";
    cin >>num;
  
  busca(C, num);
  deletar(A);
  //exibe(A, N);
}