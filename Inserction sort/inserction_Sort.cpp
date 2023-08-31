#include <iostream>
#include <cstdlib>
#include <ctime>
#define n 10

using namespace std;


int main ()
{
    int V[n],i,j,K;
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
    for(i=1; i<n ;i++) //1
    {
      K=V[i];
      j=i-1;

      while ((j>=0) && (V[j]<K)) //0
        {
          V[j+1]=V[j];
          j=j-1;
            
        }
      V[j+1]=K;
    }

    for(i=0; i<n ;i++)
    {
        cout<<V[i]<<"\t";
    }

    return 0;
}