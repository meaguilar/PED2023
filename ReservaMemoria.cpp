#include <iostream>

using namespace std;

int main()
{
    // Reserva de memoria malloc()/free()
    /*     int* ptr;
        ptr = (int*)malloc(100*sizeof(int));
        free(ptr); */

    // Reserva de memoria new/delete
    int *p;
    p = new int;

    // Test condicional
    if (p == NULL)
    {
        cout << "Error de asignación de memoria";
        exit(1);
    }
    else
    {
        cout << "Dirección de memoria" << p;
    }

    delete p;

    return 0;
}