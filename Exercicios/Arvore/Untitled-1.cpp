/*
Raphael Monteiro da Silva
Matheus Bittencourt Mangueira
Rodrigo Marques Pau Ferro
João Paulo Faustino Cardoso

1a) Essa função calcula o termo n da sequência de Fibonacci.
b)A ordem de complexidade e de O(n), porque ele executa somente uma vez de i=1 ate i<n;
c)A implementação iterativa e mais eficiente. A implementação recursiva tem complexidade O(2n)
*/


#include <iostream>

using namespace std;

int fib ( int n) { 
        if (n == 0 ) return 0 ; 
        else if (n == 1 ) return 1 ; 
        else return fib(n -1 ) + fib(n -2 ); }
        
        
int fibIterativo(int n)
{
    int a=0, b=1, c;
    if(n==0)
    {
        return a;
    }
    else
    {
        if(n==1)
        {
            return b;
        }
        else
        {
           for(int i = 1;i<n;i++)
            {
                c=a+b;
                a=b;
                b=c;
            }
            return c;
        }
    }
}

int Potencia ( int x, int n) 
{
    if(n==0)
    {
        return 1;
    }
    else
    {
        return x* Potencia(x,n-1);
    }         
}
        
        
int PotenciaIterativa(int x, int n)
{
    int y =1;
    int i =n;
    for(i; i>0; i--)
    {
        y= y*x;
    }
}


int binario (int x)
{
    
    if (x==0)
    {
        return 0;
    }
    else
    {
        return (x%2 +10 * binario(x/2));
    }
}


int MOD (int x, int y)
{
    if(y==0)
    {
        return -1;
    }
    if(x>y)
    {
        return MOD(x-y,y);
    }
    if(x<y)
    {
        return x;
    }
    if(x=y)
    {
        return 0;
    }
    
}


int DIV (int x, int y)
{
    if(y==0)
    {
        return -1;
    }
    if(x>y)
    {
        return  1 + DIV(x-y,y);
    }
    if(x<y)
    {
        return 0;
    }
    if(x=y)
    {
        return 1;
    }
    
}

int menu()
{
    int x;
    cout << "MENU DE OPCOES" << endl
         << "===============" << endl
         << "(1) Funcao recursiva de fibonacci" << endl
         << "(2) Funcao iterativa de fibonacci" << endl
         << "(3) Funcao calcular potencia recursiva" << endl
         << "(4) Funcao calcular potencia iterativa" << endl
         << "(5) Funcao calcular o numero binario" << endl
         << "(6) Funcao mostrar o resto da divisao" << endl
         << "(7) Funcao mostrar o quociente da divisao e" << endl
         << "(0) SAIR" << endl
         << "Sua opcao : " << endl;
        cin >> x;
        return x;
}


main()
{
    int op,n,x,y;

    while(op!=0)
    {
        op = menu();
        switch (op)
        {
        case 0:
            break;
        

        case 1:
            cout<<"\nDigite o numero : ";
            cin>> n;
            fib(n);
            break;

        case 2:
            cout<<"\nDigite o numero : ";
            cin>> n;
            fibIterativo(n);
            break;
        
        case 3:
            cout<<"\nO numero x: ";
            cin>> x;
            cout<<"\nElevado a n: ";
            cin>> n;
            cout<<"A Potencia recursiva e:\n"<<Potencia(x,n)<<endl;
            break;

        case 4:
            cout<<"\nO numero x: ";
            cin>> x;
            cout<<"\nElevado a n: ";
            cin>> n;
            cout<<"A PotenciaIterativa e:\n"<<PotenciaIterativa(x,n)<<endl;
            break;

        case 5:
            cout<<"\nDigite o numero : ";
            cin>> n;
            cout<<"O numero em binario e:\n" <<binario(n)<<endl;
           
            break;

        case 6:
            cout<<"\nO numero x: ";
            cin>> x;
            cout<<"\nDividido por y: ";
            cin>> y;
            cout<<"O resto da divisao e:\n" <<MOD(x,y)<<endl;
            break;

        case 7:
            cout<<"\nO numero x: ";
            cin>> x;
            cout<<"\nDividido por y: ";
            cin>> y;
            cout<<"O quociente da divisao e:\n" <<DIV(x,y)<<endl;
            break;
        
        
        default:
            cout << " Oção invalida" << endl;
        }
    }
    return 0;
}




