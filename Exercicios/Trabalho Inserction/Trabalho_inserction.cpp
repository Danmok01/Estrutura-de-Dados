#include <iostream>

#define n 10

using namespace std;

// Crescente 
int main ()
{
    int i,j,V[n],aux;

    //int V [5]={35,21,90,88,10};
  
    for(i=0; i<n ;i++)
    {
        
        V[i] = rand () %100+1;
        cout<<V[i]<<"\t";
        // cout<<"Digite o numero : ";
        // cin>>V[i];
    }
  //cout << V[n]<<"\t";
    cout<<endl;
  
    for(i=1; i<n ;i++) //1
    {
      aux=V[i];
      j=i-1;

      while ((j>=0) && (V[j]>aux)) //0
        {
          V[j+1]=V[j];
          j=j-1;
            
        }
      V[j+1]=aux;
    }

    for(i=0; i<n ;i++)
    {
        cout<<V[i]<<"\t";
    }

    return 0;
}