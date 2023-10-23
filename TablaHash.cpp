#include <iostream>

using namespace std;

#define tam 7

struct Registro
{
    int dato;
};

struct Nodo
{
    struct Registro registro;
    struct Nodo *anterior, *siguiente;
};

Nodo *tabla[tam] = {NULL};
struct Nodo *lista = NULL;

void Agregar(int);
int F_Hash(int);
struct Nodo *Buscar(int, int);
void BuscarR(int);
void EliminarR(int);
void Imprimir();

int main(void)
{

    Agregar(40);
    Agregar(33);
    Agregar(50);
    Agregar(75);
    BuscarR(33);
    EliminarR(33);
    Imprimir();

    /*cout << tabla[5]->registro.dato << endl;
     cout << tabla[5]->siguiente->registro.dato << endl;
     cout << tabla[5]->siguiente->siguiente->registro.dato << endl; */
}

void Agregar(int _dato)
{
    struct Nodo *nuevoNodo = new Nodo();
    struct Registro r;
    r.dato = _dato;
    int clave = F_Hash(_dato);
    nuevoNodo->registro = r;
    nuevoNodo->anterior = NULL;
    nuevoNodo->siguiente = tabla[clave];
    if (tabla[clave])
        tabla[clave]->anterior = nuevoNodo;
    tabla[clave] = nuevoNodo;

    cout << "Direccion " << tabla[clave] << " Indice donde se almacena " << clave << " Dato almacenado " << r.dato << endl;
}

int F_Hash(int _dato)
{
    return _dato % tam;
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
    return NULL;
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

        nuevoNodo->anterior->siguiente = nuevoNodo->siguiente;
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
    for (int i = 0; i < tam; i++)
    {
        temporal = tabla[i];
        if (temporal != NULL)
        {
            while (temporal != NULL)
            {
                cout << "Indice de almacenamiento " << i << " direccion " << tabla[i] << " - " << temporal->registro.dato << endl;

                temporal = temporal->siguiente;
            }
        }
    }
}
