#include <iostream>
#include <string.h>

#define N 1000


using namespace std;


struct Contato
{
    string nome;
    string email;
    string telefone;
};


Contato agenda[N];
int qt = 0;

void cadastrarContato()
{
    Contato novoContato;

    if(qt<N)
    {
            cout << "Cadastrar Contato  : "<<endl;
            cout << "Nome  : ";
            cin >> novoContato.nome;
            cout << "Email : ";
            cin >> novoContato.email;
            cout << "Telefone : ";
            cin >> novoContato.telefone;

            agenda[qt] = novoContato;
            qt++;
    }
    else
    {
        cout << "Memoria cheia" << endl;
    }
    
}

void alterarContato()
{
    cout << "Alterar Contato" << endl;
}

void listarContato()
{
    cout << "Listar Contatos" << endl;
    if(qt ==0)
    {
        cout<< "Lista vazia"<< endl;
    }
    else
    {
    
        for(int i=0; i<qt; i++)
        {
        cout<< i << " ";
        cout<< agenda[i].nome << " ";
        cout<< agenda[i].telefone << " ";
        cout<< agenda[i].email << endl;
        }
    }
}

void deletarContato()
{
    int d;

    cout << "Deletar Contato" << endl;
    cout << "Qual indice?" << endl;
    cin >> d;
    if(d>=0 && d<qt){
        for (int i=d+1; i<qt; i++)
        {
            agenda[i-1]=agenda[i];
        }
        qt--;
    }
    else
    {
        cout<< "Indice nao existe" << endl;
    }
}

void ordenarContato()
{


// int i;
// int j;
//     int n=qt;
//     string v;
//      for(int j=0; j<n-1; j++)
//      {
//          string aux;
//          int menorIndice =j;
//          for(int i=j+1; i<n;i++)
//          {
//              if(agenda[i].nome < v[menorIndice])
//              {
//                  menorIndice = i;
//              }
//          }
//          aux = v[menorIndice];
//          v[menorIndice]=agenda[j].nome;
//          agenda[j].nome=aux;
//         cout << agenda[j].nome << endl; 
//      }
     



      /*  int i;  

       for(int j=0; j<qt-1; j++)
    {
        
        int min=i;
        string aux;
        
        string v;
        
        
        for(int i=j+1; i<qt; i++) 
        {
            if(agenda[i].nome < v)
            {
                v = i;
            }
        }
        aux = v;
         v= agenda[i].nome;
        agenda[i].nome = aux;

        
    }
  cout <<":fdodofodfolfd " << agenda[i].nome << endl;*/
}



void buscarNome()
{
    string nome;
    int g=0;
    cout << "Qual e o nome ?" << endl;
    cin >> nome;

    for (int i = 0; i < qt; i++)
    {   
        if (agenda[i].nome == nome)
        {

            cout<< i << " ";
            cout<< agenda[i].nome << " ";
            cout<< agenda[i].telefone << " ";
            cout<< agenda[i].email << endl;
       g++;
        }
    }
     
    
    if(g==0)
        {
            cout<< "O nome nao foi encontrado "<< endl;
        }
}

void listarInicial()
{
    char letra;
    int c=0;
    cout<< "Digite o caractere inicial "<< endl;
    cin >> letra;

    for (int i = 0; i < qt; i++)
    {
        if (agenda[i].nome[0] == letra)
        {
            cout<< i << " ";
            cout<< agenda[i].nome << " ";
            cout<< agenda[i].telefone << " ";
            cout<< agenda[i].email << endl;
        c++;
        }
    }

    if(c==0)
        {
            cout<< "O nome com inicial do caractere digitado nao foi encontrado "<< endl;
        }

}


int main()
{
    cout<< "\033[2J\033[3J\033[1;1H";
    int opcao = 1 ;
    while(opcao != 0 )
    {

    cout << "MENU DE OPCOES" << endl;
    cout << "===============" << endl;
    cout << "(1) Cadastrar Contato" << endl;
    cout << "(2) Alterar Contato" << endl;
    cout << "(3) Listar Contatos" << endl;
    cout << "(4) Deletar Contato" << endl;
    cout << "(5) Ordenar Contatos" << endl;
    cout << "(6) Buscar por nome" << endl;
    cout << "(7) Listar por inicial do nome" << endl;
    cout << "(0) Sair do programa" << endl;
    cout << "Sua opcao : " << endl;
    cin >> opcao;

    switch (opcao)
    {
    case 0:
        break;
    case 1:
        cadastrarContato();
        break;
    case 2:
        alterarContato();
        break;
    case 3:
        listarContato();
        break;   
    case 4:
        deletarContato();
        break;
    case 5:
        ordenarContato();
        break;
    case 6:
        buscarNome();
        break;
    case 7:
        listarInicial();
        break;
    default:
        cout << " Oção invalida" << endl;
    }

    }

    return 0;
}