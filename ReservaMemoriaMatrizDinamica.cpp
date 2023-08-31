#include "iostream"

using namespace std;

int main()
{
    int columnas = 2;

    string **inventario;
    string categoria, producto;
    int tamanio;

    cout << "Ingrese el numero de productos a registrar";
    cin >> tamanio;
    
    inventario = new string *[tamanio];
    
    for (int i = 0; i < tamanio; i++)
    {
        inventario[i] = new string[columnas];

        cout << "Categoria: ";
        getline(cin, categoria);
        cout << "Producto: ";
        getline(cin, producto);
        inventario[i][0] = categoria;
        inventario[i][1] = producto;
    }

    for (int i = 0; i < tamanio; ++i)
    {
        delete[] inventario[i]; 

    }
    delete[] inventario;

    return 0;
}