#include <iostream>
using namespace std;

struct no{
    int info;
    struct no *ant;
    struct no *prox;
};

typedef struct no *noPtr;


int inserir (noPtr* , noPtr*);
void retirar (noPtr* );
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
        inserir(&topo,&fim);
        qtde++;
        break;

        case 2:
        listar(topo,qtde);
        break;


        case 3:
        retirar(&topo);
        qtde--;
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

int inserir(noPtr *i, noPtr *h)
{
  noPtr p =new no;
  cout<<"Digite o numero: \n";
  cin>>p->info;

  if (listaVazia(*i))
  {
    *i=p;
    //*h=p;
    p->ant=*i;
    p->prox=*i;
  }

  else{
    p->ant=(*i)->ant;
    p->prox=*i;
    (*i)->ant=p;
    p->ant->prox=p;
    
   // (*h)->prox=p;
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



void retirar(noPtr *i)
{

    
    noPtr p ;
    p=*i;

    if(p->prox==p)
    {
        *i=NULL;
    }
    else
    {
    *i=p->ant;
    (*i)->prox=p->prox;
    p->prox->ant=*i;
    delete(p);
    }


}