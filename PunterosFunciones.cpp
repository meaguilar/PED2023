#include <iostream>
using namespace std;

int incrementoPorValor(int i);
int incrementoPuntero(int *i);
int incrementoReferencia(int &i);

int main()
{
    int i = 4;
    cout << i << endl;
    cout << incrementoPorValor(i) << endl;
    cout << i << endl;
    cout << incrementoPuntero(&i) << endl;
    cout << i << endl;
    cout << incrementoReferencia(i) << endl;
    cout << i << endl;

    return 0;
}

int incrementoPorValor(int i)
{
    return i += 1;
}

int incrementoReferencia(int &i)
{
    return i += 1;
}

int incrementoPuntero(int *i)
{
    return *i += 1;
}

  

