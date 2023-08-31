#include <iostream>


using namespace std;

struct no{
    int info;
    struct no *esq, *dir;
};


typedef struct no * noPtr;

int menu();
int listaNos();
void inserir(noPtr*, int);
void remover(noPtr*, int);
bool buscar(noPtr, int);
noPtr maior(noPtr*);
void listarEmOrdem(noPtr);
void listarPreOrdem(noPtr);
void listarPosOrdem(noPtr);
bool enderecoVazio(noPtr);

int main ()
{
    int op1, op2, x;
    bool achei;
    noPtr raiz = NULL;

    do
    {
        op1 = menu();
        switch(op1)
        {
            case 1: cout<<"\nElemento a inserir: ";
                    cin>> x;
                    inserir(&raiz,x);
                    break;

            case 2: cout<<"\nElemento para remover: ";
                    cin>>x;
                    remover(&raiz,x);
                    break;

            case 3: op2 = listaNos();
                    if(op2 == 1) listarEmOrdem(raiz);
                    if(op2 == 2) listarPreOrdem(raiz);
                    if(op2 == 3) listarPosOrdem(raiz);
                    break;

            case 4: cout<<"\nElemento para buscar: ";
                    cin>>x;
                    achei = buscar(raiz,x);
                    if(achei==false)
                    {
                        cout<<"Elemento nao encontrado";
                    }
                    /*else 
                    {
                        cout<<"Elemento nao encontrado";
                    }*/
                    
                    break;

        }
    } while (op1 != 0);
    
}


int menu()
{
    int opcao;

    cout<<"\n\n\n------Menu Principal------"
        <<"\n. Inserir no na arvore"
        <<"\n. Remover no na arvore"
        <<"\n. Listar todos os nos da arvore"
        <<"\n. Buscar no"
        <<"\n. Sair"
        <<"\nDigite uma opcao: ";

    cin>> opcao;
    return opcao;
}

int listaNos()
{
    int opcao;
    cout<<"\n\nTipos de listagem:"
        <<"\n.Em Ordem"
        <<"\n.Pre Ordem"
        <<"\n.Pos Ordem"
        <<"\n\nEscolha o tipo de listagem";
    
    cin>>opcao;
    return opcao;
}

bool enderecoVazio(noPtr p)
{
    if(p)
    {
        return false;
    }
    else
    {
        return true;
    }
}



void inserir(noPtr * p, int x)
{
    if(enderecoVazio(*p))
    {
        *p = new no;
        (*p)->info = x;
        (*p)->esq= NULL;
        (*p)->dir= NULL;
    }
    else
    {
        if(x<((*p)->info))
        {
            inserir(&((*p)->esq),x);
        }
        else
        {
            inserir(&((*p)->dir),x);
        }
    }
}


void listarEmOrdem(noPtr p)
{
    if(!enderecoVazio(p))
    {
        listarEmOrdem(p->esq);
        cout<<"\t"<<p->info;
        listarEmOrdem(p->dir);
    }
}


void listarPreOrdem(noPtr p)
{
    if(!enderecoVazio(p))
    {
        cout<<"\t"<< p->info;
        listarPreOrdem(p->esq);
        listarPreOrdem(p->dir);
    }
}


void listarPosOrdem(noPtr p)
{
    if(!enderecoVazio(p))
    {
        listarPosOrdem(p->esq);
        listarPosOrdem(p->dir);
        cout<<"\t"<<p->info;
    }
}


bool buscar(noPtr  p, int x)
{
    bool achei = false;

    if(p == NULL)
    {
        
        return achei;
    }

    else
    {
        if(x==(p->info))
        {
            cout<<"\n O elemento:"<<p->info<<" foi encontrado.\n";
            achei = true;
        }
        else
        {
            if(x<(p->info))
            {
               return buscar((p->esq),x);
            }
            else
            {
                
              return  buscar((p->dir),x);
            }

        }
    }
    return achei;
}


void remover (noPtr *p, int x)
{
    noPtr aux;
    if(!enderecoVazio(*p))
    {
        if(x==((*p)->info))
        {
            aux = *p;
            if (((*p)->esq)==NULL)
            {
                *p=(*p)->dir;
            }
            else
            {
                if (((*p)->dir)==NULL)
                {
                    *p=(*p)->esq;
                }
                else
                {
                    aux = maior(&((*p)->esq));
                    (*p)->info=aux->info;

                }
            delete(aux);
            cout<<"\nO elemento foi removido\n";

                
            }
        }
        else
        {
            if((x<((*p)->info)))
            {
                remover(&((*p)->esq),x);
            }
            else
            {
                remover(&((*p)->dir),x);
            }
        }
    }
    
}



noPtr maior(noPtr *p)
{
    noPtr t;
    t=*p;

    if((t->dir)==NULL)
    {
        *p=(*p)->esq;
        return(t);
    }
    else
    {
        return(maior(&((*p)->dir)));
    }
    
}