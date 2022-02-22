// IDS344 - 2022-01 - Grupo 1 - StackManagement
// Nikita Kravchenko - 1101607
// Omar Núñez - 1101587
// Oliver Infante - 1100292
// Lervis Pinales - 1096323

#include <iostream>
#include <Windows.h>
#include "ControlFlow.h"

using namespace std;

stack* pila = NULL;
string dato = "";

int top = -1; // Inicializa el stack. No hay ningun nodo

/// <summary>
/// 
/// </summary>
struct stack
{
    string dato;
    stack* next;
};

int main()
{
    /*string dato = "aaa";

    Push(pila, "im first");
    Push(pila, "im second");
    Push(pila, "im third");

    DisplayStack(pila);*/

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

/// <summary>
/// 
/// </summary>
/// <param name="pila"></param>
/// <param name="dato"></param>
void Push(stack*& pila, string dato)
{
    stack* newNode = new stack();

    newNode->dato = dato;
    newNode->next = pila;

    pila = newNode;
    top++;

    //DebugMemory(pila);
}

/// <summary>
/// 
/// </summary>
/// <param name="pila"></param>
/// <param name="dato"></param>
void Pop(stack*& pila, string& dato)
{
    stack* aux = pila;

    dato = aux->dato;
    pila = aux->next;

    delete aux;
    top--;
}

/// <summary>
/// 
/// </summary>
/// <param name="pila"></param>
void DisplayStack(stack*& pila)
{
    string dato;

    while (pila != NULL) {
        //DebugMemory(pila);

        Pop(pila, dato);

        if (pila != NULL) cout << dato << "\n";
        else cout << dato << "\n";
        //top--;
    }
}

/// <summary>
/// 
/// </summary>
/// <returns></returns>
bool isStackEmpty()
{
    bool answer = false;
    if (top == -1) answer = true;
    return answer;
}

/// <summary>
/// 
/// </summary>
/// <param name="pila"></param>
void DebugMemory(stack* pila) {
    cout << *&pila << " is *&; " << &pila << " is &; " << pila << " is pila" << endl;
    cout << *&pila->dato << " is a data *&; " << &pila->dato << " is data &; " << pila->dato << " is data" << endl;
    cout << *&pila->next << " is next *&; " << &pila->next << " is next &; " << pila->next << " is next \n" << endl;
}

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

// <summary>
// Removes stack top value.
// <summary>
void RemoveFromStack()
{
    ClearConsole();

    /*if (values.empty())
    {
        cout << "Stack is currently empty.\n";
        Pause();
    }
    else
    {
        cout << values.top() << " removed.\n";
        values.pop();
        Pause();
    }*/

    if (isStackEmpty())
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

//// <summary>
//// Shows all the stack values.
//// <summary>
//void ClearStack()
//{
//    ClearConsole();
//
//    if (values.empty())
//    {
//        cout << "Stack is currently empty.\n";
//    }
//    else
//    {
//        while (!values.empty())
//        {
//            // cout << values.top() << "\n";
//            values.pop();
//        }
//        cout << "Stack cleared.\n";
//    }
//    Pause();
//}

// <summary>
// Shows all the stack values.
// <summary>
void DisplayStack()
{
    ClearConsole();

   // stack<string> aux;

    if (isStackEmpty())
    {
        cout << "Stack is currently empty.\n";
    }
    else
    {
        cout << "- TOP -\n";

        DisplayStack(pila);
    }

    cout << top;

    Pause();
}

// <summary>
// Closes program.
// <summary>
void ExitProgram()
{
    exit(EXIT_SUCCESS);
}

// <summary>
// Closes program.
// <summary>
void ClearConsole()
{
    system("cls");
    cout << "-- Stack Management --\n\n";
}

/// <summary>
/// 
/// </summary>
void Pause()
{
    cout << "\n";
    system("pause");
}

/// <summary>
/// Funcion que mostrara para que sirven las opciones del menu de interaccion 
/// </summary>
void DisplayHelp()
{
    ClearConsole();

    cout << "- Add -- Adds the given value to the top of the stack.\n";
    cout << "- Remove -- Removes the top value of the stack.\n";
    cout << "- Display -- Displays all the elements of the stack, from top to bottom.\n";
    cout << "- Clear -- Clears the entire stack.\n";
    cout << "- Exit -- Exits the program.\n\n";

    Pause();
}
