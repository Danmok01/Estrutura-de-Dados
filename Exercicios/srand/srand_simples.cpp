#include <iostream>
#include <cstdlib>
#include <ctime>
#define n 10

using namespace std;

int main ()
{
    int aux,V[n],i,j;
    
    srand (time(NULL));
  
    for(i=0; i<n ;i++)
    {
        
        V[i] = rand () %100+1;
        cout<<V[i]<<"\t";
        // cout<<"Digite o numero : ";
        // cin>>V[i];
    }
  
    cout<<endl;
  
    for(i=0; i<n-1 ;i++)
    {
        for(j=i+1; j<n ;j++)
        {
            if(V[i]>V[j])
            {
                aux=V[i];
                V[i]=V[j];
                V[j]=aux;
            }
        }
    }

    for(i=0; i<n ;i++)
    {
        cout<<V[i]<<"\t";
    }

    return 0;
}