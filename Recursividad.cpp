#include <iostream>

using namespace std;

int factorial(int n);
int suma(int n);
int fibonacci(int n);
int mcd(int n, int m);
int mcm(int n, int m);
int potencia(int base, int exp);
void cuentaRegresiva(int x);

int main()
{
    // cout << factorial(2);
    // cout << suma(5);
    cout << mcd(15, 5);
    // cout << mcm(0, 39);
    // cout << fibonacci(7);
    // cout<< potencia(2,3);
    return 0;
}

// Recursividad directa
int factorial(int n)
{
    // Condicion de salida - Caso base
    if (n == 1) 
    {
        return 1;
    }
    // Llamada a la funcion
    return n * factorial(n - 1);
}

int suma(int n)
{
    // Caso base
    if (n == 0)
    {
        return 0;
    }
    // Llamada a la función
    return n + suma(n - 1);
}

int fibonacci(int n)
{
    // Caso base
    if (n < 2)
    {
        return n;
    }
    // Llamada a la función
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int potencia(int base, int exp)
{
    // Caso base
    if (exp == 0)
        return 1;
    return base * potencia(base, exp - 1);
}

void cuentaRegresiva(int x)
{
    // Caso base
    if (x == 0)
    {
        return;
    }
    else
    {
        cout << x;
        cuentaRegresiva(x - 1);
    }
}

int mcd(int n, int m)
{
    // Caso base
    if (m == 0)
    {
        return n;
    }
    // Llamada a la función
    return mcd(m, n % m);
}

// Recursividad indirecta
int mcm(int n, int m)
{
    if ((n == 0) || (m == 0))
    {
        return 0;
    }
    // Llamada indirecta a la función
    return (n * m) / mcd(n, m);
}
