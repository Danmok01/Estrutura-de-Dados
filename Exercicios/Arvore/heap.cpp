#include <iostream>

using namespace std;


void troca (int *a, int *b)
{
    int aux = *a;
    *a = *b;
    *b =aux;
}

void subir(int A[], int i)
{
    int j = i/2;
    if(j>=0)
    {
        if(A[i]>A[j])
        {
            troca (&A[i], &A[j]);
            subir(A,j);
        }
    }

}


void inserir (int A[] , int *t)
{
    int valor;
    cout<<" Digite o valor :"<<endl<<*t<<endl;
    cin>> valor;

    A[*t]=valor;
    subir (A,*t);
    *t=*t+1;
   


}


void exibe(int A[], int qtd)
{
    cout<<qtd<<endl;
    for(int i = 0; i < qtd; i++)
    {
        cout<< A[i]<<"\t";
    }
}


void descer(int A[], int i, int q)
{
    int dir= 2*i +2;
    int esq = 2*i +1;

    int maior = i;

    if(dir <= q && A[dir] > A[i])
    {
        maior = dir;
    }
    if(esq <= q && A[esq] > A[maior])
    {
        maior = esq;
    }
    if(maior != i)
    {
        troca(&A[i], &A[maior]);
        descer(A,maior, q);
    }
}


void remover(int A[], int *q)
{
    A[0]=A[*q];
    *q=*q-1;
    descer(A,0,*q);
}

int menu()
{
    int x;
    cout << "MENU DE OPCOES" << endl
         << "===============" << endl
         << "(1) Inserir Elementos" << endl
         << "(2) listar Elementos" << endl
         << "(3) remover Elementos" << endl
         << "(0) Sair do programa" << endl
         << "Sua opcao : " << endl;
        cin >> x;
        return x;
}


main()
{
    int op, qtd = 0, A[qtd], *t,*q;
    t=&qtd;
    q=&qtd;

    while(op!=0)
    {
        op = menu();
        switch (op)
        {
        case 0:
            break;
        

        case 1:
            inserir(A,&qtd);
            break;

        case 2:
            exibe(A, qtd);
            break;


         case 3:
            remover(A, &qtd);
            break;
        
                       
        default:
            cout << " Oção invalida" << endl;
        }
    }
    return 0;
}