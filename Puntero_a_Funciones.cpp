#include <iostream>

using namespace std;

int *buscarNumero(int arr[], int n);
void buscarElemento(int lista[], int n);

int main()
{

    int lista[] = {1, 2, 3, 4, 5};
    int num = 3;

    cout << buscarNumero(lista, num) << endl;
    buscarElemento(lista, num);
    return 0;
}

int *buscarNumero(int arr[], int n)
{
    for (int i = 0; i < 4; i++)
    {
        /*         if(arr[i] == n){
                    return &arr[i];
                }  */
        if (*(arr + i) == n)
        {
            return (arr + i);
        }
    }
    return nullptr;
}

void buscarElemento(int lista[], int n)
{
    for (int i = 0; i < 4; i++)
    {
        if (n == lista[i])
        {
            cout << *(lista + i) << " - " << i << " - " << (lista + i) << endl;
        }
    }
    return;
}