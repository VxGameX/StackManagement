#include <iostream>
#include "Stack.h" 

using namespace std;

struct nodo {
    string dato;
    nodo* next;
};

// se agrega un nodo
void Push(nodo*& pila, string dato)
{
    nodo* newNode = new nodo();

    newNode->dato = dato;
    newNode->next = pila;

    pila = newNode;

    /*
    DebugMemory(pila);
    system("pause");
    */
}

// se elimina un nodo
void Pop(nodo*& pila)
{
    nodo* aux = pila;
    string dato;

    if (aux != NULL) {
        dato = aux->dato;
        pila = aux->next;

        delete aux;
    }
}

void DisplayStack(nodo*& pila)
{
    string dato;

    while (pila != NULL) {
        dato = pila->dato;

        Pop(pila);

        if (pila != NULL) cout << dato << "\n";
        else cout << dato << "\n";
    }
}


string DisplayNode(nodo*& pila)
{
    string dato;

    dato = pila->dato;

    return dato;
    Pop(pila);        
}


bool isStackEmpty(nodo*& pila)
{
    bool answer = false;

    if (pila == NULL) answer = true;
    return answer;
}

// ayuda a aprender la vinculacion de nodos por puntero
void DebugMemory(nodo* pila)
{
    cout << *&pila << " is *&; " << &pila << " is &; " << pila << " is pila" << endl;
    cout << *&pila->dato << " is a data *&; " << &pila->dato << " is data &; " << pila->dato << " is data" << endl;
    cout << *&pila->next << " is next *&; " << &pila->next << " is next &; " << pila->next << " is next \n" << endl;
}


