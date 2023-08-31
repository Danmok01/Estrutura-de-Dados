#include <iostream>

using namespace std;


struct no {
    int info;
    struct no * prox;
};

typedef struct no * noPtr;

noPtr topo = NULL;

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

void inserir()
{
    noPtr aux, anterior, p=new no;

    cout<<"Digite o valor do numero: "<<endl;
    cin>>p->info;
    
    if(listaVazia()==true)
    {
        p->prox = topo;
        topo=p;
    }
    else
    {
        aux = topo;
        while(aux!=NULL && p->info > aux->info)
        {
            anterior=aux;
            aux=aux->prox;
        }
        if(aux==topo)
        {
            p->prox=aux;
            topo=p;
        }
        else
        {
            p->prox=aux;
            anterior->prox=p;
        }
    }
}

void consultar()
{
    noPtr p=topo;
    int x;
    bool achei = false;

    if(!listaVazia())
    {
        cout<<"Digite o elemento: "<<endl;
        cin>> x;

        while(p != NULL && achei ==false)
        {
            if(p->info ==x)
            {
                cout<<"Elemento encontrado"<<endl;
                achei = true;
            }
            p = p->prox;
        }
        if(!achei)
        {
            cout<<"Elemento nao encontrado"<<endl;
        }
    }
    else
    {
        cout<< "Lista Vazia"<<endl;
    }
}

void exibe()
{
    if(!listaVazia())
    {
    noPtr p=topo;
    int soma=0;
    for(p=topo; p!=NULL ;p=p->prox)
    {
        cout<<p->info<<"\t";
        soma+=p->info;
    }
    cout<< endl;
    cout<<soma<<endl;
    }
    else
    {
        cout<< "Lista Vazia"<<endl;
    }

}

void retirar()
{
    noPtr aux,anterior=topo, p=topo;
    int x;
    bool achei = false;

    if(!listaVazia())
    {
        cout<<"Digite o elemento: "<<endl;
        cin>> x;

        while(p != NULL && achei ==false)
        {
            if(p->info ==x)
            {
                if(p==topo)
                {
                    achei = true;
                    cout<<"O elemento"<<p->info<<" foi removido"<<endl;
                    aux = p;
                    topo=aux->prox;
                }
                else
                {
                
                achei = true;
                cout<<"O elemento"<<p->info<<" foi removido"<<endl;
                aux = p;
                anterior->prox=aux->prox;
                }


            }
            anterior = p;
            p = p->prox;
            
        }
        if(!achei)
        {
            cout<<"Elemento nao encontrado"<<endl;
        }
    }
    else
    {
        cout<< "Lista Vazia"<<endl;
    }
}

void ordenarCrescente()
{
    if(!listaVazia())
    {
    noPtr aux2,anterior=topo, p=topo,q;
    
    for(p=topo; p->prox !=NULL ;p=p->prox)
    {
        for(q=p->prox; q!=NULL ;q=q->prox)
        {
            if(p->info > q->info)
            {
                
                    int aux = p->info;
                    p->info=q->info;
                    q->info=aux;
                                   
            }
        }
       
    
        
    }
     for(p=topo; p!=NULL ;p=p->prox)
    {
        cout<<p->info<<"\t";
        
    }
    cout<< endl;
    
    }
    else
    {
        cout<< "Lista Vazia"<<endl;
    }
}

void ordenarDecrescente()
{
    if(!listaVazia())
    {
    noPtr aux2,anterior=topo, p=topo,q;
    
    for(p=topo; p->prox !=NULL ;p=p->prox)
    {
        for(q=p->prox; q!=NULL ;q=q->prox)
        {
            if(p->info < q->info)
            {
                
                    int aux = p->info;
                    p->info=q->info;
                    q->info=aux;
                    
                

            }
        }
       
    
        
    }
     for(p=topo; p!=NULL ;p=p->prox)
    {
        cout<<p->info<<"\t";
        
    }
    cout<< endl;
    
    }
    else
    {
        cout<< "Lista Vazia"<<endl;
    }
}

int menu()
{
    int x;
    cout << "MENU DE OPCOES" << endl
         << "===============" << endl
         << "(1) Inserir Elementos" << endl
         << "(2) Consultar elementos" << endl
         << "(3) Exibe os elemnetos" << endl
         << "(4) Retirar os elemnetos" << endl
         << "(5) Ordem crescente" << endl
         << "(6) Ordem decrescente" << endl
         << "(0) Sair do programa" << endl
         << "Sua opcao : " << endl;
        cin >> x;
        return x;
}


main()
{
    int op;

    while(op!=0)
    {
        op = menu();
        switch (op)
        {
        case 0:
            break;
        

        case 1:
            inserir();
            break;

        case 2:
            consultar();
            break;
        
        case 3:
            exibe();
            break;

        case 4:
            retirar();
            break;

        case 5:
            ordenarCrescente();
            break;

        case 6:
            ordenarDecrescente();
            break;
        
        
        default:
            cout << " Oção invalida" << endl;
        }
    }
    return 0;
}
