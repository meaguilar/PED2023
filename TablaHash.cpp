#include <iostream>

using namespace std;

#define dimension 7

struct Registro
{
    int dato;
};

struct Nodo
{
    struct Registro registro;
    struct Nodo *anterior;
    struct Nodo *siguiente;
};

struct Nodo *lista = nullptr;
struct Nodo *tabla[dimension] = {nullptr};

void Agregar(int);
int F_Hash(int);
struct Nodo *Buscar(int, int);
void BuscarR(int);
void EliminarR(int);
void Imprimir();

int main(void)
{

    Agregar(12);
    Agregar(40);
    Agregar(33);
    Agregar(50);
    Agregar(75);
    EliminarR(33);
    Imprimir();
}

void Agregar(int _dato)
{
    struct Nodo *nuevoNodo = new Nodo();
    struct Registro r;
    r.dato = _dato;
    int clave = F_Hash(_dato);
    nuevoNodo->registro = r;
    nuevoNodo->anterior = nullptr;
    nuevoNodo->siguiente = tabla[clave];
    if (tabla[clave])
        tabla[clave]->anterior = nuevoNodo;
    tabla[clave] = nuevoNodo;

    cout << " Dir. nodo " << tabla[clave] << " Indice donde se almacena " << clave << " Dato almacenado " << r.dato << endl;
}

int F_Hash(int _dato)
{
    return _dato % dimension;
}

struct Nodo *Buscar(int _dato, int _clave)
{
    struct Nodo *nuevoNodo = tabla[_clave];
    while (nuevoNodo)
    {
        if (nuevoNodo->registro.dato == _dato)
        {
            return nuevoNodo;
        }
        nuevoNodo = nuevoNodo->siguiente;
    }
    return nullptr;
}

void BuscarR(int _dato)
{
    int clave = F_Hash(_dato);
    struct Nodo *nuevoNodo = Buscar(_dato, clave);
    if (nuevoNodo)
    {
        cout << "Registro encontrado ... Posicion: " << clave << " Valor: " << nuevoNodo->registro.dato << endl;
    }
    else
    {
        cout << "Registro no encontrado" << endl;
    }
}

void EliminarR(int _dato)
{
    int clave = F_Hash(_dato);
    struct Nodo *nuevoNodo = Buscar(_dato, clave);
    if (nuevoNodo)
    {
        cout << "Registro eliminado " << nuevoNodo->registro.dato << endl;
        if (nuevoNodo->siguiente)
        {
            nuevoNodo->siguiente->anterior = nuevoNodo->anterior;
        }
        if (nuevoNodo->anterior)
        {
            nuevoNodo->anterior->siguiente = nuevoNodo->siguiente;
        }
        else
        {
            tabla[clave] = nuevoNodo->siguiente;
        }

        if (nuevoNodo->anterior)
        {
            nuevoNodo->anterior->siguiente = nuevoNodo->siguiente;
        }

        delete nuevoNodo;
    }
    else
    {
        cout << "Registro no encontrado" << endl;
    }
}

void Imprimir()
{
    struct Nodo *temporal;
    for (int i = 0; i < dimension; i++)
    {
        temporal = tabla[i];

        while (temporal != nullptr)
        {
            cout << "Indice de almacenamiento " << i << " direccion del indice del arreglo " << tabla[i] << " dir. nodo " << temporal << " dir. nodo anterior" << temporal->anterior << " - " << temporal->registro.dato << endl;
            temporal = temporal->siguiente;
        }
    }
}
