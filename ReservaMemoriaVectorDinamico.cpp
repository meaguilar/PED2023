#include <iostream>

using namespace std;

int main()
{
    string *categoria = nullptr;
    string *producto = nullptr;
    int tamanio;

    cout << "Cuantas categorias registrara?";
    cin >> tamanio;

    categoria = new string[tamanio];
    producto = new string[tamanio];

    for (int i = 0; i < tamanio; i++)
    {

        cout << "Categoria: ";
        cin >> categoria[i];
        cout << "Producto: ";
        cin >> producto[i];
    }

    delete[] categoria;
    delete[] producto;

    return 0;
}