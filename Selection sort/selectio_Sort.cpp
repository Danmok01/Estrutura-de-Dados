#include <iostream>
#include <cstdlib>
#include <ctime>
#define n 10

using namespace std;

int main ()
{
    int aux,V[n],i,j,menor;
    time_t seed = time(0);
    srand (seed);
  
    for(i=0; i<n ;i++)
    {
        
        V[i] = 1+rand () %100;
        cout<<V[i]<<"\t";
        // cout<<"Digite o numero : ";
        // cin>>V[i];
    }
  
    cout<<endl;
  
    for(i=0; i<n-1 ;i++)
    {
        menor = i;
        for(j=i+1; j<n ;j++)
        {
            if(V[menor]>V[j])
            {
                menor = j;
            }

        
        }
      aux=V[i];
        V[i]=V[menor];
        V[menor]=aux;
    }

    for(i=0; i<n ;i++)
    {
        cout<<V[i]<<"\t";
    }

    return 0;
}