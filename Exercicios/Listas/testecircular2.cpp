#include <iostream>
using namespace std;

struct no{
    int info;
   // struct no *ant;
    struct no *prox;
};

typedef struct no *noPtr;


int inserir (noPtr* );
void remover (noPtr*,int * );
void listar (noPtr, int);
bool listaVazia(noPtr);




int main()
{
 // noPtr fim=NULL;
  noPtr topo=NULL;

  int op, qtde=0;
  

  do{
    cin>>op;
    switch(op)
      {
        case 1:
        inserir(&topo);
        qtde=qtde+1;
        break;

        case 2:
        listar(topo,qtde);
        break;

        case 3:
        remover(&topo,&qtde);
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

int inserir(noPtr *i)
{
  noPtr p =new no;
  cout<<"Digite o numero: \n";
  cin>>p->info;

  if (listaVazia(*i))
  {
    *i=p;
    //*h=p;
    p->prox=p;
  //  p->prox=*i;
  }

  else{
    p->prox=(*i)->prox;
    (*i)->prox=p;
    //(*h)->prox=p;
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



void remover(noPtr *i, int* q)
{
   noPtr p=*i;
   if(!listaVazia(*i))
   {
    if(*q==1)
    {
      *i==NULL;
    }
    else
    {
      *i=p->prox;
    }

    delete(p);
    cout<<"foi deletado";
    *q=*q-1;
   }

   else
   {
    cout<<"lista vazia0";
   }
}