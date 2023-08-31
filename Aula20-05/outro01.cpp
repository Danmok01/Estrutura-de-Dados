#include <iostream>
#include <cstdlib>
#define n 5

using namespace std;


void busca(int V[], int k)
{
  bool achei = false;
  int j = 0;

  
  while(j<n && achei == false)
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
    
  }
  else
  {
    cout<<"Nao achei";
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