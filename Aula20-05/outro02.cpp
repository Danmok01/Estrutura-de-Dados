#include <iostream>
#include <cstdlib>
#define n 5

using namespace std;


void busca(int V[], int k)
{

  
  int j = 0;
  for(int i=0; i<n; i++)
  {
    if(V[i]==k)
    {
      cout<< "O numero esta na posição "<< j+1;
      
    }
    else 
    {
      j++;
    }
  }
  if(j==n)
  {
    cout<<"Nao tem esse numero ";
  }
}


int main ()
{
  int V[n],i,k;
  time_t seed = time(0);
  srand (seed);
  for(i=0; i<n ;i++)
    {
      V[i] = 1+rand () %100;
      cout<<V[i]<<"\t";
    }
  cout <<endl;
  cout<<"Achar o numero : ";
  cin >>k;
  
  busca(V, k);

  
}