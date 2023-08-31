#include <iostream>

using namespace std;

struct no {
    int info;
    struct no * ant;
    struct no * prox;
};

typedef struct no * noPtr;


void inserir(noPtr*);
//void retirar(noPtr*);
void listar(noPtr);
bool listaVazia(noPtr);

int menu()
{
    int x;
    cout << "MENU DE OPCOES" << endl
         << "===============" << endl
         << "(1) Inserir Elementos" << endl
         << "(2) Retirar elementos" << endl
         << "(3) Listar os elemnetos" << endl
         << "(0) Sair do programa" << endl
         << "Sua opcao : " << endl;
        cin >> x;
        return x;
}


main()
{
    noPtr topo = NULL;
    //noPtr fim = NULL;
    int op;

    while(op!=0)
    {
        op = menu();
        switch (op)
        {
        case 0:
            break;
        

        case 1:
            inserir(&topo);
            break;

        /*case 2:
            retirar(&topo);
            break;*/
        
        case 3:
            listar(topo);
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

void inserir(noPtr*i)
{
    noPtr p =new no;

    cout<<"Digite o valor: "<<endl;
    cin>> p->info;
    p->ant=NULL;

    if(listaVazia(*i))
    {
        p->prox = NULL;

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
        cout<<"-->NULL";
    }
    else
    {
        cout<<"Lista  Vazia";
    }
}