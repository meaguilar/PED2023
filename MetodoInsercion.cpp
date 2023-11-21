#include <iostream>

using namespace std;

int main()
{

    // Declarar un arreglo
    int arreglo[] = {4, 1, 65, 12, 10};

    cout << "Recorrido del arreglo sin ordenar " << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << arreglo[i] << " pos " << i << endl;
    }
    cout << "------------------------------------------------------------" << endl;

    // Almacenar la posición
    int pos = 0;
    // Almacenar el elemento de intercambio
    int aux = 0;
    // Método de inserción
    // Recorrido del arreglo
    for (int i = 0; i < 5; i++)
    {
        // Posición actual
        pos = i; // 0
        // Valor del arreglo
        aux = arreglo[i]; // 4
        // Comparación con el número de la izquierda
        while ((pos > 0) && (arreglo[pos - 1] > aux))
        {
            // Cambio con el número de la izquierda
            arreglo[pos] = arreglo[pos - 1];
            // Iteraciones hacia atras
            pos--;
        }
        // Refrescar cada iteración
        arreglo[pos] = aux;
    }

    // Imprimir resultados
    cout << " -------------------- " << endl;
    cout << " Datos ordenados " << endl;
    for (int i = 0; i < 5; i++)
    {

        cout << " Valor " << arreglo[i] << ", pos " << i << endl;
    }

    return 0;
}