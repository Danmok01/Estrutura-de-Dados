#include <iostream>

using namespace std;

struct no {
    int info;
    struct no * ant;
    struct no * prox;
};

typedef struct no * noPtr;


void inserir(noPtr*,noPtr*);
//void retirar(noPtr*);
void listar(noPtr);
void listar2(noPtr);
bool listaVazia(noPtr);
void inserir2(noPtr*,noPtr*);

int menu()
{
    int x;
    cout << "MENU DE OPCOES" << endl
         << "===============" << endl
         << "(1) Inserir Elementos" << endl
         << "(2) Retirar elementos" << endl
         << "(3) Listar os elemnetos" << endl
         << "(4) Listar os elemnetos 2" << endl
         << "(5) Inserir teste 2" << endl
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

        /*case 2:
            retirar(&topo);
            break;*/
        
        case 3:
            listar(topo);
            break;

        case 4:
            listar2(fim);
            break;
            
        case 5:
            inserir2(&topo,&fim);
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

void inserir2 (noPtr*i,noPtr*h)
{
    noPtr aux,aux2, anterior, p=new no;

    cout<<"Digite o valor do numero: "<<endl;
    cin>>p->info;

    p->ant=NULL;

    if(listaVazia(*i))
    {
        
        p->prox = NULL;
        *h=p;
        *i=p;

    }
    else
    {
        aux=*i;
        aux2=*h;
        while(aux!=NULL && p->info > aux->info)
        {
            anterior=aux;
            aux=aux->prox;

        }
        if(aux==NULL)
        {
            p->prox=NULL;
            p->ant=*i;
            (*i)->prox=p;
            *h=p;
        }
        else
        {
            
            
            p->prox=*i;
            (*i)->ant=p;
            *i=p;


              

        
            
        }
    }

    
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
        cout<<"Lista  Vazia";
    }
}