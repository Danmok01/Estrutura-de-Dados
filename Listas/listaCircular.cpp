#include <iostream>
using namespace std;

struct no{
    int info;
    struct no *ant;
    struct no *prox;
};

typedef struct no *noPtr;


int inserir (noPtr* , noPtr*, int*);
//void retirar (noPtr* );
void listar (noPtr, int);
bool listaVazia(noPtr);




int main()
{
  noPtr fim=NULL;
  noPtr topo=NULL;

  int op, qtde=0;
  

  do{
    cin>>op;
    switch(op)
      {
        case 1:
        inserir(&topo,&fim,&qtde);
        qtde++;
        break;

        case 2:
        listar(topo,qtde);
        break;
      }
  }while(op!=0);
  
}


bool listaVazia(noPtr p)
{
    
    if(p == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }

}

int inserir(noPtr *i, noPtr *h,int* q)
{
  noPtr p =new no;
  cout<<"Digite o numero: \n";
  cin>>p->info;

  if (listaVazia(*i))
  {
    *i=p;
    *h=p;
    p->prox=*i;
  }

  else{
    p->prox=*i;
    
    (*h)->prox=p;
    *i=p;
      
  }
}



void listar(noPtr i, int q)
{

  //i!=NULL
  //listaVazia(i)
    
    if(i!=NULL)
    {
        for (int j=0; j<q ;j++)
        {
        cout << i->info << "\t";
        i = i->prox;
        }
    }
    else
    {
        cout<< "\n Lista vazia!";
    }
        
}