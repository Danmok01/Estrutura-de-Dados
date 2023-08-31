#include <iostream>
#include <cstdlib>
#include <ctime>
#define n 10

using namespace std;

int main ()
{
    int aux,V[n],i,j;
  bool troca = false;
    time_t seed = time(0);
    srand (seed);
  
    for(i=0; i<n ;i++)
    {
        
        //V[i] = rand () %100+1;
        //cout<<V[i]<<"\t";
         cout<<"Digite o numero : ";
         cin>>V[i];
    }
  
    cout<<endl;
  
    for(i=0; i<n-1 ;i++)
    {
      if(troca==false){
          bool troca = false;
        for(j=i+1; j<n ;j++)
        {
            if(V[i]>V[j])
            {
                aux=V[i];
                V[i]=V[j];
                V[j]=aux;
              troca = true;
            }
        }
        }
        
      
        
    }

    for(i=0; i<n ;i++)
    {
        cout<<V[i]<<"\t";
    }

    return 0;
}