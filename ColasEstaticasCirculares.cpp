#include <iostream>

using namespace std;

// Constante
#define tamano 5

struct Nodo
{
    int frenteCola;
    int finalCola;
    int elemento[tamano];
} nodo;

// Declaracion de funciones / creacion de prototipo
void Crear(struct Nodo *);
bool Vacia(struct Nodo *);
int Llena(Nodo *);
void Insertar(struct Nodo *, int);
void Eliminar(struct Nodo *);
int Dimension(Nodo *);

int main()
{
    Crear(&nodo);
    Insertar(&nodo, 100);
    Insertar(&nodo, 102);
    Insertar(&nodo, 200);
    Insertar(&nodo, 452);
    Insertar(&nodo, 5);
    cout << "Posicion " << nodo.frenteCola << " Elemento " << nodo.elemento[nodo.frenteCola] << endl;
    cout << "Posicion " << nodo.finalCola << " Elemento " << nodo.elemento[nodo.finalCola] << endl;
    Eliminar(&nodo);
    Insertar(&nodo, 500);
    cout << "Posicion " << nodo.frenteCola << " Elemento " << nodo.elemento[nodo.frenteCola] << endl;
    cout << "Posicion " << nodo.finalCola << " Elemento " << nodo.elemento[nodo.finalCola] << endl;
    Eliminar(&nodo);
    Eliminar(&nodo);
    Insertar(&nodo, 900);
    Insertar(&nodo, 300);
    cout << "Posicion " << nodo.frenteCola << " Elemento " << nodo.elemento[nodo.frenteCola] << endl;
    cout << "Posicion " << nodo.finalCola << " Elemento " << nodo.elemento[nodo.finalCola] << endl;
    return 0;
}

// Crear Cola vacía
void Crear(Nodo *p)
{
    p->frenteCola = -1;
    p->finalCola = -1;
}

// Vacia
bool Vacia(Nodo *p)
{
    if (p->finalCola == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Dimension
int Dimension(Nodo *p)
{
    if (Vacia(p))
    {
        return 0;
    }
    else
    {

        if (p->frenteCola <= p->finalCola)
        {
            return p->finalCola - p->frenteCola + 1;
        }
        else
        {

            return tamano - p->frenteCola + p->finalCola + 1;
        }
    }
}

// Llena
int Llena(Nodo *p)
{
    if (Dimension(p) == tamano)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Encolar -- final de la lista
void Insertar(Nodo *p, int n)
{
    if (!Llena(p))
    {
        if (Vacia(p))
        {
            p->frenteCola = 0;
        }
        if (p->finalCola == tamano - 1)
        {
            p->finalCola = 0;
        }
        else
        {
            p->finalCola++;
        }
        p->elemento[p->finalCola] = n;
    }
    else
    {
        cout << "Cola llena";
    }
}

// Desencolar -- inicio de la lista
void Eliminar(Nodo *p)
{
    if (!Vacia(p))
    {
        if (Dimension(p) == 1)
        {
            Crear(p);
        }
        else
        {
            p->frenteCola++;
        }
    }
    else
    {
        cout << "Cola esta vacia";
    }
}
