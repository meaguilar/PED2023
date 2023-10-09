//Ejercicios https://excalidraw.com/#room=2fa8267f185ea53de0aa,Sq3q34OOMR3OppUXP-Pu9A 
#include <iostream>

using namespace std;

struct Nodo
{
    int dato;
    struct Nodo *izquierdo;
    struct Nodo *derecho;
};

struct Nodo *ABB = nullptr;

struct Nodo *Crear(int n);
// Se pasa un puntero y por referencia ya que se modificara el valor
struct Nodo *Insertar(struct Nodo *ABB, int n);
void Inorden(struct Nodo *ABB);
void Preorden(struct Nodo *ABB);
void Postorden(struct Nodo *ABB);
struct Node *BuscarMenor(struct Node *ABB);

void Buscar(struct Nodo *&ABB, int n, struct Nodo *&padre);
void Borrar(Nodo *&ABB, int n);

int main()
{

    int dato;
    for (int i = 0; i < 3; i++)
    {
        cout << "Ingresa un valor";
        cin >> dato;
        ABB = Insertar(ABB, dato);
    }
    cout << " Recorrido Inorden ";
    Inorden(ABB);
    cout << " Recorrido Preorden ";
    Preorden(ABB);
    cout << " Recorrido Postorden ";
    Postorden(ABB);
    // NodoEliminar(arbol,1);

    return 0;
}

// Crear Nodo
struct Nodo *Crear(int n)
{
    // Reservar la memoria
    struct Nodo *nuevoNodo = new Nodo;
    // Asignar el valor que el usuario ingresa
    nuevoNodo->dato = n;
    /* nuevoNodo->izquierdo = nullptr;
    nuevoNodo->derecho = nullptr; */
    nuevoNodo->izquierdo = nuevoNodo->derecho = nullptr;
    return nuevoNodo;
}

// Insertar
struct Nodo *Insertar(struct Nodo *ABB, int n)
{
    // Si arbol esta vacio se crea el arbol a partir del primer valor ingresado
    if (ABB == nullptr)
        return Crear(n);
    // si el valor ingresado es menor se inserta en el subarbol de la izquierda
    if (n < ABB->dato)
        ABB->izquierdo = Insertar(ABB->izquierdo, n);
    else
        // si el valor ingresado es mayor se inserta en el subarbol de la derecha
        ABB->derecho = Insertar(ABB->derecho, n);
    return ABB;
}

// Recorrer
// Inorden: Hijo izquierdo — raíz — hijo derecho.
void Inorden(struct Nodo *ABB)
{
    if (ABB == nullptr)
    {
        return;
    }
    else
    {
        Inorden(ABB->izquierdo);
        // Raiz
        cout << ABB->dato << "-";
        Inorden(ABB->derecho);
    }
}

// Preorden: Raíz — hijo izquierdo — hijo derecho.
void Preorden(struct Nodo *ABB)
{
    if (ABB == nullptr)
    {
        return;
    }
    else
    {
        // Raiz
        cout << ABB->dato << "-";
        Preorden(ABB->izquierdo);
        Preorden(ABB->derecho);
    }
}

// PostOrden:Hijo izquierdo– hijo derecho — raíz
void Postorden(struct Nodo *ABB)
{
    if (ABB == nullptr)
    {
        return;
    }
    else
    {
        Postorden(ABB->izquierdo);
        Postorden(ABB->derecho);
        // Raiz
        cout << ABB->dato << "-";
    }
}

// Encontrar el menor
struct Nodo *BuscarMenor(struct Nodo *ABB)
{
    while (ABB->izquierdo != nullptr)
    {
        ABB = ABB->izquierdo;
    }
    return ABB;
}

void Buscar(struct Nodo *&ABB, int n, struct Nodo *&padre)
{
    while (ABB != nullptr && ABB->dato != n)
    {
        padre = ABB;
        if (n < ABB->dato)
            ABB = ABB->izquierdo;
        else
            ABB = ABB->derecho;
    }
}

// Borrar el nodo
void Borrar(Nodo *&ABB, int n)
{
    struct Nodo *padre = nullptr;
    // ABB nodo raiz
    struct Nodo *aux = ABB;
    Buscar(aux, n, padre);
    // Si el arbol no tiene nodos
    if (aux == nullptr)
    {
        return;
    }

    // Borrar un nodo hoja (sin hijos en izq y der)
    if (aux->izquierdo == nullptr && aux->derecho == nullptr)
    {
        // Si el valor a borrar es igual a la raiz se borra todo el arbol
        if (aux == ABB)
        {
            ABB = nullptr;
        }
        // Si auxiliar es diferente de la raiz
        else
        {
            if (padre->izquierdo == aux)
            {
                padre->izquierdo = nullptr;
            }
            else
            {
                padre->derecho = nullptr;
            }
        }

        // Liberar la memoria
        delete aux;
    }

    // Borrar nodo con 2 hijos (hijos en der e izq)
    else if (aux->izquierdo && aux->derecho)
    { 
        // Se busca en el subarbol derecho el nodo menor
        struct Nodo *sucesor = BuscarMenor(aux->derecho);
        int val = sucesor->dato;
        Borrar(ABB, sucesor->dato);
        aux->dato = val;
    }
    else
    { 
        // Borrar nodo con  un solo hijo (izq o der)
        struct Nodo *hijo;
        //Evalua si el hijo es nodo izquierdo o derecho 
        if (aux->izquierdo)
        {
            hijo = aux->izquierdo;
        }
        else
        {
            hijo = aux->derecho;
        }
        if (aux != ABB)
        {
            if (aux == padre->izquierdo)
                padre->izquierdo = hijo;
            else
                padre->derecho = hijo;
        }
        else
        {
            ABB = hijo;
        }

        delete aux;
    }
}