#include <iostream>
using namespace std;

int main()
{
    // Arreglos y punteros
    //  Declaración de punteros
    int arreglo[] = {1, 2, 4};
    // Direccion de memoria
    cout << arreglo;
    // Todo array es un puntero
    int *ptr = arreglo;
    // Direccion de memoria
    cout << ptr;
    // Accediendo a la posición con punteros
    cout << *(ptr + 0) << endl;
    cout << *(ptr + 1) << endl;
    cout << *(ptr + 2) << endl;

    for (int i = 0; i < 3; i++)
    {
        cout << "Elemento del arreglo " << *(ptr + i) << " Direccion " << (ptr + i) << endl;
    }

    // Resta - Distancia entre punteros
    cout << "Distancia entre punteros ptr2 - ptr0 " << *(ptr + 3) - *(ptr + 0) << endl;

    // Comparación
    cout << "ptr0 > ptr2: " << (*(ptr + 0) > *(ptr + 1)) << endl;
    cout << "ptr0 == ptr0: " << (*(ptr + 0) == *(ptr + 0)) << endl;
    cout << "ptr0 < ptr1: " << (*(ptr + 0) < *(ptr + 1)) << endl;

    return 0;
}