#include <iostream>
using namespace std;

struct no{
    int info;
   // struct no *ant;
    struct no *prox;
};

typedef struct no *noPtr;


int inserir (noPtr* , int*);
//void retirar (noPtr* );
void listar (noPtr, int);
bool listaVazia(noPtr);




int main()
{
  //noPtr fim=NULL;
  noPtr topo=NULL;

  int op, qtde=0;
  

  do{
    cin>>op;
    switch(op)
      {
        case 1:
        inserir(&topo,&qtde);
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

int inserir(noPtr *i, int* q)
{
  noPtr p =new no;
  cout<<"Digite o numero: \n";
  cin>>p->info;

  if (listaVazia(*i))
  {

    
    p->prox=p;
    *i=p;
   
    
  }

  else{
    p->prox=(*i)->prox;
    
    
    (*i)->prox=p;
   *i=p;
      
  }
}



void listar(noPtr i, int q)
{
    
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