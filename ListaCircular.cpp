#include <iostream>

using namespace std;

struct Nodo
{
    int elemento;
    struct Nodo *siguiente;
};

struct Nodo *lista = nullptr;

void InsertarInicio(int);
void InsertarFinal(int);
void InsertarIntermedio(int, int);
void EliminarInicio();
void EliminarFinal();
void EliminarIntermedio(int);
void Imprimir();

int main()
{
    InsertarInicio(45);
    InsertarInicio(4);
    InsertarFinal(78);
    InsertarFinal(7);
    Imprimir();
    cout << "------------------------------" << endl;
   

    return 0;
}

void InsertarInicio(int n)
{
    struct Nodo *nuevoNodo = new Nodo;
    struct Nodo *temporal;
    nuevoNodo->elemento = n;
    if (lista == nullptr)
    {
        lista = nuevoNodo;
        //Circularidad
        lista->siguiente = lista;
        temporal = lista;
        
    }
    else 
    {   
        nuevoNodo->siguiente = lista;
         //Circularidad
        lista = nuevoNodo;
        temporal->siguiente = lista;
    }
}

void InsertarFinal(int n)
{
    struct Nodo *nuevoNodo = new Nodo();
    struct Nodo *temporal;
    nuevoNodo->elemento = n;
    if (lista == nullptr)
    {
        lista = nuevoNodo;
        lista->siguiente = lista;  
        temporal = lista;
    }
    else
    {
        temporal->siguiente = nuevoNodo;
        nuevoNodo->siguiente = lista;
        temporal = nuevoNodo;
    }
}

void InsertarIntermedio(int n, int posicion)
{
    struct Nodo *nuevoNodo = new Nodo();
    struct Nodo *temporal = lista;
    nuevoNodo->elemento = n;
    nuevoNodo->siguiente = nullptr;
    posicion--;
    while (posicion != 1)
    {
        temporal = temporal->siguiente;
        posicion--;
    }
    nuevoNodo->siguiente = temporal->siguiente;
    temporal->siguiente = nuevoNodo;
}

void EliminarInicio()
{
    struct Nodo *temporal = lista;

    if (lista != nullptr)
    {
        while (temporal->siguiente != lista)
        {
            temporal = temporal->siguiente;
        }
        temporal->siguiente = lista->siguiente;
        delete lista;
        lista = temporal->siguiente;

    } // SI SOLO HAY UN ELEMENTO
    else if (lista->siguiente == lista)
    {
        delete lista;
        lista = nullptr;
    }
    else
    {
        cout << "Lista Vacia";
    }
}
void EliminarFinal()
{
    struct Nodo *temporal = lista;
    struct Nodo *temporal2;

    if (lista != nullptr)
    {
        while (temporal->siguiente != lista)
        {
            temporal2 = temporal;
            temporal = temporal->siguiente;
        }

        temporal2->siguiente = temporal->siguiente;
        delete temporal;

    } // SI SOLO HAY UN ELEMENTO
    else if (lista->siguiente == lista)
    {
        delete lista;
        lista = nullptr;
    }
    else
    {
        cout << "Lista vacia";
    }
}

void EliminarIntermedio(int posicion)
{
    struct Nodo *temporal = lista;
    struct Nodo *temporal2;
    while (posicion != 1)
    {
        temporal2 = temporal;
        temporal = temporal->siguiente;
        posicion--;
    }
    // conexion del nuevoNodo con el resto de nodos de la lista
    temporal2->siguiente = temporal->siguiente;
    delete temporal;
    temporal = nullptr;
}

void Imprimir()
{
    struct Nodo *temporal = lista;
    if (lista != nullptr)
    {
        do
        {
            cout << "Lista " << temporal->elemento << " Direccion " << temporal << " Dir siguiente " << temporal->siguiente << endl;
            temporal = temporal->siguiente;
        } while (temporal != lista);
    }
    else
    {
        cout << "Lista vacia";
    }
}
