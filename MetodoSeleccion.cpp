#include <iostream>

using namespace std;

int main()
{

    // Declarar un arreglo
    int arreglo[] = {4, 8, 9, 55, 6, 1, 3};
    // Almacenar el valor de intercambio
    int aux = 0;
    // Almacenar la posicion
    int pos = 0;

    cout << "Recorrido del arreglo sin ordenar " << endl;
    for (int i = 0; i < 7; i++)
    {
        cout << arreglo[i] << " pos " << i << endl;
    }

    // Implementar el método de selección
    // Recorrido
    for (int i = 0; i < 7; i++)
    {
        // Hipotesis, que el primer valor del arreglo es el menor
        pos = i; // 0
        // Segundo recorrido se inicia en la segunda posición
        for (int j = i + 1; j < 7; j++)
        {
            // Comparación entre elemento actual con el primer valor que se estableció como menor
            if (arreglo[j] < arreglo[pos])
            {
                // Establecer la posición del elemento actual como el menor valor
                pos = j; // 5
            }
        }
        // Intercambio de valores del arreglo
        // Se almacena el valor de cada iteración
        aux = arreglo[i]; // 4
        // Se almacena en la nueva posición el valor de resultado de la condición
        arreglo[i] = arreglo[pos]; // 1
        // Se almacena en la nueva posición al valor que estaba en aux
        arreglo[pos] = aux; // 4
        cout<< "Valor de cada iteracion " << aux << " pos " << i << " valor menor " << arreglo[i] << " nueva pos " << i <<endl;
    }

    // Imprimir resultados
    cout << " -------------------- " << endl;
    cout << " Datos ordenados " << endl;
    for (int i = 0; i < 7; i++)
    {

        cout << " Valor " << arreglo[i] << ", pos " << i << endl;
    }

    return 0;
}