#include <ctime>
#include <iostream>
#include <cstdlib>
#define N 7

using namespace std;


int binario(int V[], int x, int inicio, int fim)
{
  if(inicio == fim)
    
  {
      return 0;
  
  }
  
  int meio =(inicio+fim)/2;

  if(x==V[meio])
    {
        return meio+1;
    }

    else
    {
        if(x<V[meio])
        {
            binario(V,x,inicio,meio);
        }
        else
        {
            binario(V,x,meio+1,fim);

        }
    }

}


int main ()
{
  int k,n,V[N]={9,15,25,32,44,50,90};
  
  
  cout<<"Achar o numero : ";
  cin >>n;
  
  k=binario(V,n,0,N);

  if(k)
  {
      cout<<"Numero encontrado na posicao "<< k;

  }
  else {
      cout<<"Numero nao encontrado ";
  }

  
}