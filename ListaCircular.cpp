#include <iostream>

using namespace std;

struct Nodo
{
    int elemento;
    struct Nodo *siguiente;
} nodo;

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
    InsertarInicio(60);
    InsertarInicio(15);
    InsertarFinal(52);
    InsertarIntermedio(600, 3);
    Imprimir();
    cout << "------------------------------" << endl;
    EliminarIntermedio(3);
    Imprimir();

    return 0;
}

void InsertarInicio(int n)
{
    // Se reserva la memoria
    struct Nodo *nuevoNodo = new Nodo;
    // Puntero que representara el ultimo elemento de la lista
    struct Nodo *temporal;
    // se asigna el valor que el usuario ingresa a elemento
    nuevoNodo->elemento = n;
    // Si lista esta vacia
    if (lista == nullptr)
    {
        lista = nuevoNodo;
        // Por ser el unico nodo en la lista se apunta a si mismo
        lista->siguiente = lista;
        // Se estable la circularidad entre el ultimo nodo y el primero, pero como es un unico nodo en la lista
        // Entonces el final de la lista es igual al primer nodo de la lista
        temporal = lista;
    }
    else // Si no ...  estaba vacia la lista, si existian nodos en la lista
    {
        // El nuevo nodo que se agrega se convierte en el primer nodo, se establece la conexion del nuevoNodo con la lista
        nuevoNodo->siguiente = lista;
        // Se posiciona como primer elemento de la lista
        lista = nuevoNodo;
    }
}

void InsertarFinal(int n)
{
    // Se reserva la memoria
    struct Nodo *nuevoNodo = new Nodo;
    // Puntero que representara el ultimo elemento de la lista
    struct Nodo *temporal;
    // se asigna el valor que el usuario ingresa a elemento
    nuevoNodo->elemento = n;
    // Si lista esta vacia
    if (lista == nullptr)
    {
        lista = nuevoNodo;
        lista->siguiente = lista;
        temporal = lista;
    }
    else
    {
        // El nodo que se agrega se convierte en el ultimo nodo
        temporal->siguiente = nuevoNodo;
        // Se establece la circularidad
        nuevoNodo->siguiente = lista;
    }
}

void InsertarIntermedio(int n, int posicion)
{
    struct Nodo *nuevoNodo = new Nodo;
    // Variable auxiliar almacena el nodo actual
    struct Nodo *temporal = lista;
    nuevoNodo->elemento = n;
    nuevoNodo->siguiente = nullptr;

    posicion--;
    while (posicion != 1)
    {
        temporal = temporal->siguiente;
        posicion--;
    }
    // conexion del nuevoNodo con el resto de nodos de la lista
    nuevoNodo->siguiente = temporal->siguiente;
    // asignar el nuevoNodo a la lista
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
        // Conexion
        temporal->siguiente = lista->siguiente;
        // Liberar la memoria
        delete lista;
        // Se asigna al inicio de la lista al segundo nodo
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
        // Si hay mas de un elemento en la lista
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
