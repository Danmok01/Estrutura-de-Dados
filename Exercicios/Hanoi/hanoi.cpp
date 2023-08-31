#include <iostream>

using namespace std;

void hanoi (int n, char origem , char destino, char auxiliar)
{
    if(n>0)
    {
        hanoi(n-1, origem , auxiliar, destino);
        cout<< "Mover disco " << n<< " de "<< origem << " para " << destino<<endl;
        hanoi(n-1,auxiliar,destino,origem);
    }
}

int main ()

{
    cout<< "\033[2J\033[3J\033[1;1H";
    hanoi(5,'A','B','C');
    return 0;

}