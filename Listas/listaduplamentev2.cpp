#include <iostream>

using namespace std;

struct no {
    int info;
    struct no * ant;
    struct no * prox;
};

typedef struct no * noPtr;


void inserir(noPtr*,noPtr*);
void retirarinicio(noPtr*,noPtr*);
void retirarfim(noPtr*);
void listar(noPtr);
void listar2(noPtr);
bool listaVazia(noPtr);

int menu()
{
    int x;
    cout << "\n\nMENU DE OPCOES" << endl
         << "===============" << endl
         << "(1) Inserir Elementos" << endl
         << "(2) Retirar elementos" << endl
        << "(5)"<< endl
         << "(3) Listar os elemnetos" << endl
         << "(4) Listar os elemnetos" << endl//tirar depois
         << "(0) Sair do programa" << endl
         << "Sua opcao : " << endl;
        cin >> x;
        return x;
}


main()
{
    noPtr topo = NULL;
    noPtr fim = NULL;
    int op;

    while(op!=0)
    {
        op = menu();
        switch (op)
        {
        case 0:
            break;
        

        case 1:
            inserir(&topo,&fim);
            break;

        case 2:
            retirarinicio(&topo,&fim);
            break;

        case 5:
            retirarfim(&fim);
            break;
        
        case 3:
            listar(topo);
            break;

        case 4:
            listar2(fim);
            break;

                
        default:
            cout << " Oção invalida" << endl;
        }
    }
    return 0;
}


bool listaVazia(noPtr p)
{
    if(p==NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void inserir(noPtr*i,noPtr*h)
{
    noPtr p =new no;

    cout<<"Digite o valor: "<<endl;
    cin>> p->info;
    p->ant=NULL;
    

    if(listaVazia(*i))
    {
        p->prox = NULL;
        *h=p;

    }
    else
    {
        p->prox=*i;
        (*i)->ant=p;
    }
    *i=p;
}


void listar (noPtr p)
{
    if(!listaVazia(p))
    {
        cout<<"elemento da lista: "<<endl;
        cout<<"INICIO";
        while(p!=NULL)
        {
            cout<<"-->"<<p->info;
            p=p->prox;
        }
        cout<<"-->NULL"<<endl;
    }
    else
    {
        cout<<"Lista  Vazia";
    }
}

void listar2 (noPtr p)
{
    if(!listaVazia(p))
    {
        cout<<"elemento da lista: "<<endl;
        cout<<"INICIO";
        while(p!=NULL)
        {
            cout<<"-->"<<p->info;
            p=p->ant;
        }
        cout<<"-->NULL"<<endl;
    }
    else
    {
        cout<<"Lista  Vazia"<<endl;
    }
}


void retirarinicio(noPtr*i,noPtr*h)
{
    noPtr p =*i;
    if(!listaVazia(*i))
    {
        if(p->prox==NULL)
        {
            *i=NULL;
        }
        else
        {
            *i=p->prox;
            (*i)->ant=NULL;

        }
        delete(p); 
    }
    else{
        cout<<"Vazia"<<endl;
    }
}


void retirarfim(noPtr*h)
{
    noPtr p =*h;
    if(!listaVazia(*h))
    {
        if(p->ant==NULL)
        {
            *h=NULL;
        }
        else
        {
            *h=p->ant;
            (*h)->prox=NULL;

        }
        delete(p); 
    }
    else{
        cout<<"Vazia"<<endl;
    }
}