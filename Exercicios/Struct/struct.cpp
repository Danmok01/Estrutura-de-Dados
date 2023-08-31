#include <iostream>


using namespace std;

struct Aluno
{
    string nome;
    float p1, p2, media;
    string situacao;
};


//struct Turma
//{
 //   string nomeProfessor;
 //   string materia;
 //   Aluno alunos[10];
//};


void leTurma( Aluno turma[], int n)
{
    for( int i=0; i<n ; i++)
    {
        cin>> turma[i].nome;
        cin>> turma[i].p1;
        cin>> turma[i].p2;
        turma[i].media=(turma[i].p1+turma[i].p2)/2;
        if(turma[i].media<7)
        {
            turma[i].situacao= "prova final";

        }
        else{
            turma[i].situacao= "Aprovado";
            
        }
    }
   
}


void imprimeTurma(Aluno turma[], int n)
{
    for(int i=0; i<n; i++)
    {
        cout<< turma[i].nome<<" ";
        cout<< turma[i].p1<<" ";
        cout<< turma[i].p2<<" ";
        cout<< turma[i].media<<" ";
        cout<< turma[i].situacao<<endl;
    }
}

int main()
{
    Aluno turma[10];
    leTurma(turma,10);
    imprimeTurma(turma,10);
    
    

    return 0;
}