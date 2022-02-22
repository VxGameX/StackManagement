#include <iostream>
#include<stdlib.h>
using namespace std;

struct Nodo
{
    int dato;
    Nodo* proxima;
};

void PUSH(Nodo*&, int);/* Se agregan los voids PUSH que se encargara de agregar y POP que se encargara de quitar datos de la pila*/
void POP(Nodo*&, int&);

void PUSH(Nodo*& stack, int n)

{
    Nodo* NewNodo = new Nodo();

    NewNodo->dato = n;

    NewNodo->proxima = stack;

    stack = NewNodo;

    cout << "\nElemento " << n << " agregado." << endl;
}

void POP(Nodo*& stack, int& n)
{
    Nodo* aux = stack;
    n = aux->dato;

    stack = aux->proxima;

    delete aux;
}

int main()
{
    Nodo* pila = NULL;
    int dato;
    int ndatos;

    cout << "Ingrese el numero de datos que desea insertar...\n";
    cin >> ndatos;

    cout << "Digite sus numeros: \n";
    for (int i = 0; i < ndatos; i++)
    {
        cin >> dato;
        PUSH(pila, dato);
    }

    cout << "\nSacando elementos de la pila: \n";


    if (pila != NULL)
    {
        cout << dato << " \n ";
        //cout << "Sacando elementos de la pila: " << dato << " \n";
    }
    else
    {
        cout << dato << "\nNo existe mas datos";
    }

    return 0;
}