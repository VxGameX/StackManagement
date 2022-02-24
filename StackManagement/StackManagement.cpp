// IDS344 - 2022-01 - Grupo 1 - StackManagement
// Nikita Kravchenko - 1101607
// Omar Núñez - 1101587
// Oliver Infante - 1100292
// Lervis Pinales - 1096323
// Daniel Báez - 1073597

#include <iostream>
#include <Windows.h>
#include "ControlFlow.h" //nos permite modificar el flujo de ejecucion de las instrucciones de nuestro programa 
#include "Stack.h" //nos permite modificar el flujo de ejecucion de las instrucciones de nuestro programa 

using namespace std;

nodo* pila = NULL;

int main()
{    
    cout << "-- Stack Management --\n\n";
    cout << "- NOTE:\n";
    cout << "This program uses string data type to store given values.\n";
    cout << "This program follows general stacks general rules.\n\n";

    Pause();
    ClearConsole();

    cout << "Welcome!\n\n";

    while (true)
    {
        DisplayMenu();
    }
}

//<summary>
// Displays program menu.
// </summary>
void DisplayMenu()
{
    int menuOption;

    cout << "Select an option. (1 - 4)\n";
    cout << "1. Add\n";
    cout << "2. Remove\n";
    cout << "3. Display all\n";
    cout << "4. Exit\n\n";
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
        ExitProgram();
        break;
    default:
        cout << "Please, enter a valid option. (1 - 4)\n";
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

    ClearConsole();

    cout << "Enter the value: ";
    cin >> value;

    Push(pila, value);    
}


// <summary>
//Removes stack top value.
// <summary>
void RemoveFromStack()
{
    ClearConsole();

    if (IsStackEmpty(pila))
    {
        cout << "Stack is currently empty.\n";
        Pause();
    }

    else
    {
        cout << DisplayNode(pila) << " removed.\n";
        Pop(pila);
        Pause();
    }
}


// <summary>
// Shows all the stack values.
// <summary>
void DisplayStack()
{
    ClearConsole();

    if (IsStackEmpty(pila))
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

