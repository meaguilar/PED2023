#include <iostream>
using namespace std;

// Un nodo tiene un dato, el cual es el elemento y  otro nodo al que apunta

struct Nodo
{
    int elemento;
    struct Nodo *siguiente;
};

// Variable global
struct Nodo *pila = nullptr;

// Declarando funciones
void Insertar(int);
void Eliminar();
void Imprimir();
bool Vacia();
int UltimoElemento();

int main()
{
    int valor;
    // La pila puede tener mas valores no solamente 5
    for (int i = 0; i < 5; i++)
    {
        cout << "Ingrese un valor ";
        cin >> valor;
        Insertar(valor);
    }
    Imprimir();
    Eliminar();
    return 0;
}

// Operacion Push
void Insertar(int n)
{
    // Reserva de memoria
    struct Nodo *nuevoNodo = new Nodo();
    // asignar el valor
    nuevoNodo->elemento = n;
    // Establece el nuevo nodo agregado como pila
    nuevoNodo->siguiente = pila;
    pila = nuevoNodo;
}

// Operación Pop
void Eliminar()
{
    if (pila != nullptr)
    {
        struct Nodo *temporal = pila;
        pila = temporal->siguiente;
        delete temporal;
    }
}

// Imprimir la pila
void Imprimir()
{
    struct Nodo *temporal = pila;
    while (temporal != nullptr)
    {
        cout << "Elementos de la pila" << temporal->elemento << " dir. memoria " << temporal << " dir de memoria nodo siguiente " << temporal->siguiente << endl;
        temporal = temporal->siguiente;
    }
}

// Operacion Pila vacia
bool Vacia()
{
    // Si devuelve 1 la pila esta vacia
    // Si devuelve 0 la pila no esta vacia
    return pila == nullptr;
}

// Operación Top
int UltimoElemento()
{
    if (pila == nullptr)
    {
        return -1;
    }
    else
    {
        return pila->elemento;
    }
}