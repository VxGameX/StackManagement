// IDS344 - 2022-01 - Grupo 1 - StackManagement
// Nikita Kravchenko - 1101607
// Omar Núñez - 1101587
// Óliver Infante - 1100292
// Lervis Pinales - 1096323

#include <iostream>
#include <stack>
#include <Windows.h>
#include "ControlFlow.h"
/*Otra libreria que es muy importante en nuestro programa, es el uso del "ControlFlow"
Ya que como estamos manejando estructuras de control, esto nos permite modificar
El flujo de ejecucion de las instrucciones de nuestro programa */


using namespace std;


stack<string> values;



int top = -1; // Inicializa el stack. No hay ningun nodo

struct stacj {
    int dato;
    stacj* next;
};

void DebugMemory(stacj* pila);

// se agrega un nodo
void Push(stacj*& pila, int dato)
{
    stacj* newNode = new stacj();

    newNode->dato = dato;
    newNode->next = pila;

    pila = newNode;
    top++;

    DebugMemory(pila);
}

void Pop(stacj*& pila, int& dato)
{
    stacj* aux = pila;

    dato = aux->dato;
    pila = aux->next;

    delete aux;
    top--;
}


void DisplayStack(stacj*& pila)
{
    int dato;

    while (pila != NULL) {
        DebugMemory(pila);

        Pop(pila, dato);

        if (pila != NULL) cout << dato << ", ";
        else cout << dato << ".";
        top--;
    }
}

void DebugMemory(stacj* pila) {
    cout << *&pila << " is *&; " << &pila << " is &; " << pila << " is pila" << endl;
    cout << *&pila->dato << " is a data *&; " << &pila->dato << " is data &; " << pila->dato << " is data" << endl;
    cout << *&pila->next << " is next *&; " << &pila->next << " is next &; " << pila->next << " is next \n" << endl;
}

int main()
{
    stacj* pila = NULL;

    int dato = 1;

    Push(pila, 12);
    Push(pila, 23);
    Push(pila, 2);
    Push(pila, 5);
    Push(pila, 8);

    DisplayStack(pila);
}

/*
    cout << "-- Stack Management --\n\n";
    cout << "- NOTE:\n";
    cout << "This program uses string data type to store given values.\n";
    cout << "This program follows general stacks general rules.\n";
    cout << "For help type 0. -\n\n";

    Pause();
    ClearConsole();

    cout << "Welcome!\n\n";
    

    while (true)
    {
        DisplayMenu();
    }
}
/*Nuestra primera funcion main, unicamente hacemos aviso al usuario que esta ejecutando este programa
Y mas que nada aclarando que este programa utiliza datos recibidos por parte del usuario en cuestion
si mismo despues de estos mensajes, habilitamos un while con la funcion de nuestro Menu de manera Grafica
Con la funcion "DisplayMenu", es importante destacar que se hicieron estas funciones para no entorpeser 
El programa con un codigo de manera lineal. */

/*
//<summary>
// Displays program menu.
// </summary>
void DisplayMenu()
{
    int menuOption;

    cout << "Select an option. (1 - 5)\n";
    cout << "1. Add\n";
    cout << "2. Remove\n";
    cout << "3. Display\n";
    cout << "4. Clear\n";
    cout << "5. Exit\n\n";
    cout << ">> ";

    cin >> menuOption;

    switch (menuOption)
    {
    case 1:
        AddToStack();
        break;
    case 2:
        RemoveFromStack();
        break;
    case 3:
        DisplayStack();
        break;
    case 4:
        ClearStack();
        break;
    case 5:
        ExitProgram();
        break;
    default:
        cout << "Please, enter a valid option. (1 - 5)\n";
        Pause();
        break;
    }

    ClearConsole();
}
/*Hacemos un desglose general de nuestro menu de una manera grafica con las opciones del 1 al 5
Asi mismo capturamos el valor con la variable "menuOption" y este tambien declarado en
La parte de nuestro inicio de la funcion, y como sabemos que dependiendo de
El numero ingresado sera su funcion, y como lo explicaba en el menu, se hicieron funciones
Para que el programa no fuera tan lineal, esto ayuda para agilizar.
Y al ultimo agregamos un "ClearConsole", esto para que cuando tengamos la opcion deseada
Se quite el menu anterior y muestre las siguiente funciones*/

/*

// <summary>
// Add value to stack.
// <summary>
void AddToStack()
{
    string value;

    while (GetAsyncKeyState(VK_ESCAPE) == 0)
    {
        ClearConsole();

        cout << "Enter the value (Press ESC enter last value): ";
        cin >> value;

        values.push(value);
    }
}
/*La funcion GetAsyncKeyState, detecta directamente la interrupcion de hardware del teclado
Algunas personas dicen que es una especie de detencion en "tiempo real", esto para agregar el valor
Este tipo de acciones no se suelen ver seguido, pero es una manera de implementarlo*/ 

/*

// <summary>
//Removes stack top value.
// <summary>
void RemoveFromStack()
{
    ClearConsole();

    if (values.empty())
    {
        cout << "Stack is currently empty.\n";
        Pause();
    }
    else
    {
        cout << values.top() << " removed.\n";
        values.pop();
        Pause();
    }
}
/*Como lo dice su funcion, consta de remover el valir del stack, como en la condicional nos hace mencion
Si el valor esta vacio, nos dira que el stack esta vacio, donde elegimos la posicion
De lo contrario, el valir es removido y agregamos la funcion .top, que nos regresa el ultimo elemento en el stack*/

/*

// <summary>
// Shows all the stack values.
// <summary>
void ClearStack()
{
    ClearConsole();

    if (values.empty())
    {
        cout << "Stack is currently empty.\n";
    }
    else
    {
        while (!values.empty())
        {
            // cout << values.top() << "\n";
            values.pop();
        }
        cout << "Stack cleared.\n";
    }
    Pause();
}
/*Esta funcion es sencilla, basicamente es una condicion que analiza el stack, si el stack esta vacio
Nos lanza un mensaje de que esta vacio, valgame la redundancia de las palabras, de lo contrario, entra en una
Condicionante que nos dice que mientras el valor este existente, lo borre y nos mande el mensaje de limpio.*/

/*

// <summary>
// Shows all the stack values.
// <summary>
void DisplayStack()
{
    ClearConsole();

    stack<string> aux;

    if (values.empty())
    {
        cout << "Stack is currently empty.\n";
    }
    else
    {
        cout << "- TOP -\n";

        while (!values.empty())
        {
            cout << values.top() << "\n";
            aux.push(values.top());
            values.pop();
        }
        cout << "- BOTTOM -\n";

        while (!aux.empty())
        {
            values.push(aux.top());
            aux.pop();
        }
    }
    Pause();
}
/*En esta funcion ponemos varias conficionantes, esto mas que nada poder mostrar nuestro stack de manera grafica
Si una posicion esta vacia, dira que esta vacia, de lo contrario nos va a mostrar el stack, y como lo graficamos
Nos va dar el ordenamiento de los elementos del stack con las funciones .empty "true si el stack esta vacio"
 "push" es que agregara un elemento en el tope del stack y "top" que regresara el ulitmo elemento del stack*/

/*

//<summary>
// Closes program.
// <summary>
void ExitProgram()
{
    exit(EXIT_SUCCESS);
}
//Esta funcion finaliza el programa.

//<summary>
// Closes program.
// <summary>
void ClearConsole()
{
    system("cls");
    cout << "-- Stack Management --\n\n";
}


void Pause()
{
    cout << "\n";
    system("pause");
}

void Pause(float seconds)
{
    Sleep(seconds * 1000);
}

void DisplayHelp()      //Funcion que mostrara para que sirven las opciones del menu de interaccion 
{
    ClearConsole();

    cout << "- Add -- Adds the given value to the top of the stack.\n";
    cout << "- Remove -- Removes the top value of the stack.\n";
    cout << "- Display -- Displays all the elements of the stack, from top to bottom.\n";
    cout << "- Clear -- Clears the entire stack.\n";
    cout << "- Exit -- Exits the program.\n\n";

    Pause();
}
*/