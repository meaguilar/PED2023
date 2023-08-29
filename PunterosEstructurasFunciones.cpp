#include <iostream>
#include <windows.h>

using namespace std;

struct temperatura
{
    float alta;
    float baja;
} temp;

void leertempactual(float &actual);
void registrotemp(struct temperatura &t);

int main()
{

    // Inicializamos la estructura para que funcione bien la lógica
    temp.alta = 0;
    temp.baja = 100;
    while (true)
    {
        registrotemp(temp);
        cout << "Temperaturas: " << temp.baja << " - " << temp.alta << "\n";
        Sleep(2000);
    }

    return 0;
}

// Devolver varios valores desde el uso de referencias
void leertempactual(float &actual)
{
    int t = time(NULL);
    srand(t);
    cout << " - tiempo: " << t;
    actual = rand() % (48 + 1);
}

void registrotemp(struct temperatura &t)
{
    float actual = 0;
    leertempactual(actual);
    cout << " -> Lectura actual: " << actual << "\n";
    if (actual > t.alta)
    {
        t.alta = actual;
    }
    if (actual < t.baja)
    {
        t.baja = actual;
    }
}