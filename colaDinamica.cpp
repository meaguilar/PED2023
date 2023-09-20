#include <iostream>

using namespace std;

struct Nodo
{
    int elemento;
    struct Nodo *siguiente;
};

// Variable global
struct Nodo *frenteCola = nullptr;
struct Nodo *finalCola = nullptr;

// Declaracion de funciones / creacion de prototipo
bool Vacia();
void Insertar(int);
void Eliminar();
void Imprimir();
void ImprimirFrente();
void ImprimirFinal();

int main()
{
    int valor;

    for (int i = 0; i < 5; i++)
    {
       cout<<"Ingrese el valor";
       cin>> valor;
       Insertar(valor);
    }
    cout << " -------------------- " << endl;
    //ImprimirFrente();
    Eliminar();
    ImprimirFrente();
    ImprimirFinal();
    

    return 0;
}

// Operación vacia
bool Vacia()
{
    if (frenteCola == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Encolar -- final de la lista
void Insertar(int n)
{
    // Reserva de memoria
    struct Nodo *nuevoNodo = new Nodo();
    //Asignacion del valor que ingresa el usuario 
    nuevoNodo->elemento = n;
    nuevoNodo->siguiente = nullptr;
    if (Vacia())
    {//No hay nadie en el frente de cola, elemento queda al frente
        frenteCola = nuevoNodo;
    }
    else
    {  
        //si habian elementos en la cola y por lo tanto 
        //se posiciona despues del elemento que estan en cola 
        finalCola->siguiente = nuevoNodo;
    }
    //Se establece el final de la cola con el nuevo nodo agregado
    finalCola = nuevoNodo;
}

void Imprimir(){
    struct Nodo *temporal = frenteCola;

    while (temporal != nullptr)
    {
        cout<<"Elementos de la cola " << temporal->elemento << endl;
        temporal = temporal->siguiente;
    }
}

void ImprimirFrente(){
    struct Nodo *temporal = frenteCola;
    if (temporal == nullptr) {
       cout << "La cola está vacía. No hay elemento en el frente." << endl;
    }
    cout<<frenteCola->elemento;
}

void ImprimirFinal(){
    struct Nodo *temporal = finalCola;
    if (temporal == nullptr) {
       cout << "La cola está vacía. No hay elemento." << endl;
    }
    cout<<finalCola->elemento;
}


// Desencolar -- inicio de la lista
void Eliminar()
{
    if (!Vacia())
    {
        struct Nodo *temporal = frenteCola;
        //Si hay un elemento
        if (frenteCola == finalCola)
        {
            frenteCola = nullptr;
            finalCola = nullptr;
        }
        else //si hay mas de un elemento
        {   
            frenteCola = temporal->siguiente;
        }
        delete temporal;
    }
}

