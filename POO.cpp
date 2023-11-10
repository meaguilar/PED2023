#include <iostream>
using namespace std;

class Atleta
{
public:
    string nombre;
    int anioNac;
    int edad;
    float altura;
    float peso;
    float IMC;
    string deporte;
    
    // Declaración de las funciones
    int CalcularEdad(int);
    float CalcularIMC(float, float);
};

//Definición de las funciones
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
    // Declaración de los objeto atleta 1 y atleta 2
    Atleta atleta1; 
    Atleta atleta2;

    //Definiendo objeto atleta1
    atleta1.nombre = "Violeta";
    atleta1.anioNac = 1997;
    atleta1.deporte = "Basketball";
    atleta1.peso = 160;
    atleta1.altura = 1.73;
    atleta1.edad = atleta1.CalcularEdad(atleta1.anioNac);
    atleta1.IMC = atleta1.CalcularIMC(atleta1.peso, atleta1.altura);

    //Definiendo objeto atleta2
    atleta2.nombre = "Javier";
    atleta2.anioNac = 2005;
    atleta2.deporte = "Tiro";
    atleta2.peso = 150;
    atleta2.altura = 1.70;
    atleta2.edad = atleta2.CalcularEdad(atleta2.anioNac);
    atleta2.IMC = atleta2.CalcularIMC(atleta2.peso, atleta2.altura);

    //Mostrar información de los objetos atleta 1 y atleta 2
    cout << "Atleta: " << atleta1.nombre << ", deporte: " << atleta1.deporte << ", edad: " << atleta1.edad << ", IMC: " << atleta1.IMC << "\n";
    cout << "Atleta: " << atleta2.nombre << ", deporte: " << atleta2.deporte << ", edad: " << atleta2.edad << ", IMC: " << atleta2.IMC;

    return 0;
}