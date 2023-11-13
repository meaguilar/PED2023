#include <iostream>
using namespace std;

class Atleta
{
private:
    string nombre;
    int anioNac;
    int edad;
    float altura;
    float peso;
    float IMC;
    string deporte;

public:
    // Declaración de las funciones
    int CalcularEdad(int);
    float CalcularIMC(float, float);
    Atleta();
    Atleta(string _nombre, int _anioNac, float _altura, float _peso, string _deporte);
    void setNombre(string _nombre);
    string getNombre();
    void setanioNac(int _anioNac);
    int getanioNac();
    void setEdad(int _edad);
    int getEdad();
    void setAltura(float _altura);
    float getAltura();
    void setPeso(float _peso);
    float getPeso();
    void setDeporte(string deporte);
    string getDeporte();
};

// Definición de las funciones

Atleta ::Atleta(){};
Atleta ::Atleta(string _nombre, int _anioNac, float _altura, float _peso, string _deporte)
{
    nombre = _nombre;
    anioNac = _anioNac;
    altura = _altura;
    peso = _peso;
    deporte = _deporte;
}

void Atleta ::setNombre(string _nombre)
{
    nombre = _nombre;
}

string Atleta ::getNombre()
{
    return nombre;
}

void Atleta ::setanioNac(int _anioNac)
{
    anioNac = _anioNac;
}

int Atleta ::getanioNac()
{
    return anioNac;
}

void Atleta::setEdad(int _edad)
{
    edad = _edad;
}

int Atleta ::getEdad()
{
    return edad;
}

void Atleta ::setAltura(float _altura)
{
    altura = _altura;
}

float Atleta ::getAltura()
{
    return altura;
}

void Atleta ::setPeso(float _peso)
{
    peso = _peso;
}
float Atleta ::getPeso()
{
    return peso;
}

int Atleta::CalcularEdad(int anioNac)
{
    return 2023 - anioNac;
}

float Atleta ::CalcularIMC(float peso, float altura)
{
    return (peso / 2.2) / (altura * altura);
}

int main()
{
    // Creacion e inicializacion del objeto a tráves del constructor
    Atleta atleta1 = Atleta("Genesis", 2005, 1.57, 112, "basketball");

    // Accediendo desde el método set
    //  atleta1.setNombre("Walter");

    // Llamando al método y almacenando el resultado a traves del método set
    atleta1.setEdad(atleta1.CalcularEdad(atleta1.getanioNac()));

    // Mostrar información de los objetos atleta 1 desde el método get
    cout << atleta1.getNombre() << " - edad " << atleta1.getEdad();

    return 0;
}