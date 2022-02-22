// IDS344 - 2022-01 - Grupo 1 - StackManagement
// Nikita Kravchenko - 1101607
// Omar Núñez - 1101587
// Oliver Infante - 1100292
// Lervis Pinales - 1096323

#include <iostream>
#include <iostream>
#include <Windows.h>
#include "ControlFlow.h" //nos permite modificar el flujo de ejecucion de las instrucciones de nuestro programa 



using namespace std;


struct nodo {
    string dato;
    nodo* next;
};

void DebugMemory(nodo* pila);

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
void Pop(nodo*& pila, string& dato)
{
    nodo* aux = pila;

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
        Pop(pila, dato);

        if (pila != NULL) cout << dato << "\n";
        else cout << dato << "\n";
    }
}

bool isStackEmpty(nodo*& pila)
{
    bool answer = false;

    if (pila == NULL) answer = true;
    return answer;
}

// ayuda a aprender la vinculacion de nodos por puntero
void DebugMemory(nodo* pila) {
    cout << *&pila << " is *&; " << &pila << " is &; " << pila << " is pila" << endl;
    cout << *&pila->dato << " is a data *&; " << &pila->dato << " is data &; " << pila->dato << " is data" << endl;
    cout << *&pila->next << " is next *&; " << &pila->next << " is next &; " << pila->next << " is next \n" << endl;
}

nodo* pila = NULL;
string dato = "";

int main()
{    
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

        Push(pila, value);
       // values.push(value);
    }
}
/*La funcion GetAsyncKeyState, detecta directamente la interrupcion de hardware del teclado
Algunas personas dicen que es una especie de detencion en "tiempo real", esto para agregar el valor
Este tipo de acciones no se suelen ver seguido, pero es una manera de implementarlo*/ 


// <summary>
//Removes stack top value.
// <summary>
void RemoveFromStack()
{
    ClearConsole();

    /*
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
    */

    if (isStackEmpty(pila))
    {
        cout << "Stack is currently empty.\n";
        Pause();
    }
    else
    {
        cout << pila->dato << " removed.\n";
        Pop(pila, dato);
        Pause();
    }
}

// <summary>
// Shows all the stack values.
// <summary>
void ClearStack()
{
    ClearConsole();

    /*
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
    */
}

// <summary>
// Shows all the stack values.
// <summary>
void DisplayStack()
{
    ClearConsole();

   // stack<string> aux;

    if (isStackEmpty(pila))
    {
        cout << "Stack is currently empty.\n";
    }
    else
    {
        cout << "- TOP -\n";

        DisplayStack(pila);

        cout << "- BOTTOM -\n";
    }

    Pause();
}



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
