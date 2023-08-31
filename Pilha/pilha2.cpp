#include <iostream>
#define N 10

using namespace std;

int contadorNo;

struct no
{
    int info;
    struct no*prox;
};

typedef struct no * noPtr;

noPtr topo = NULL;

bool listaVazia()
{
    if(topo!=NULL)
    {
        return false;
    }
    else
    {
        return true;
    }
}

void push()
{
    noPtr p ;
    int valor;
    if(contadorNo!=N)
    {
        p = new no;
        cout<<"Digite um valor: ";
        cin>>valor;
        p->info = valor;
        p->prox = topo;
        topo = p;
        contadorNo++;
    }
    else
    {
        cout<<"Limite maximo"<<endl;
    }

}

void pop()
{
    noPtr p=topo;
    if (listaVazia()==false)
    {   
        topo = topo -> prox;
       
        cout<<"\nO elemento " << p->info <<" foi retirado da pilha "<<endl;
        delete (p);

    }
    
    else
    {
        cout<<"Lista Vazia "<<endl;
    }
    
}

void listar()
{
    if (listaVazia()==false) 
    
    {
        noPtr p = topo;  
        do
        {
            cout<< p->info<<"\t";
            p=p->prox;
        }
        while(p!=NULL);
        cout<<endl;
  
    } 
    else 
    {
        cout <<"Lista Vazia"<<endl;           
    }
}


int main()
{
    int op;
    do{
        cout << "MENU DE OPCOES" << endl;
        cout << "=======================" << endl;
        cout << "(1) Empilhar elementos" << endl;
        cout << "(2) Desenpilhar elementos" << endl;
        cout << "(3) Listar os elemnetos" << endl;
        cout << "(0) Sair do programa" << endl;
        cout << "Sua opcao : " << endl;
        cin >> op;
        switch(op)
        {
            case 0:
                break;

            case 1:
                push();
                break;

            case 2:
                pop();
                break;

            case 3:
                listar();
                break;

            default:
                cout << " Oção invalida" << endl;
        }
    }
    while(op!=0);
    return 0;
}