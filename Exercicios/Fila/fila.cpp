#include <iostream>

using namespace std;


struct no {
    int info;
    struct no * prox;
};

typedef struct no * noPtr;

noPtr topo = NULL;
noPtr ult = NULL;


bool listaVazia()
{
    
    if(topo == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }

}



void enqueue()
{
    noPtr aux, p=new no;
    
    cout << "Digite o elemento: ";
  
    cin>>p->info;
    
    p->prox=NULL;
    
    if(!listaVazia())
    {
        topo=p;
        
    }
    else
    {
        aux=topo;
        while(aux->prox!=NULL)
        {
            aux=aux->prox;
        }
        aux->prox=p;
    }

}
main()
{
    int op;
       

    while(op!=0)
    {
        cout << "MENU DE OPCOES" << endl;
        cout << "===============" << endl;
        cout << "(1) Efileirar elementos" << endl;
        cout << "(2) Desenfileirar elementos" << endl;
        cout << "(3) Listar os elemnetos" << endl;
        cout << "(0) Sair do programa" << endl;
        cout << "Sua opcao : " << endl;
        cin >> op;
        switch(op)
        {
            case 0:
                break;

            case 1:
                enqueue();
                break;

            /*case 2:
                dequeue();
                break;*/

            /*case 3:
                listar();
                break;*/

            default:
                cout << " Oção invalida" << endl;
        }
    }
    return 0;
}

