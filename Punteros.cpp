#include <iostream>
using namespace std;

int main()
{
    int num1, num2;
    int *ptr1, *ptr2;

    ptr1 = &num1;
    ptr2 = &num2;

    num1 = 100;
    num2 = 200;

    // Asignacion de una direccion a un puntero
    ptr1 = ptr2;
    ptr2 = nullptr;

    cout << ptr1 << " - " << ptr2;

    // Cambiando valor a traves de punteros
    *ptr1 = 25;
    *ptr2 = 15;

    *ptr2 = *ptr1;

    cout << *ptr1 << " - " << *ptr2;

    // Expresion correcta pero siempre falsa
    if (&ptr1 == &ptr2)
    {
        return false;
    }
    else
    {
        return true;
    }

    return 0;
}