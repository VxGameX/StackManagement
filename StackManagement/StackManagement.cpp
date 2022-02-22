// IDS344 - 2022-01 - Grupo 1 - StackManagement
// Nikita Kravchenko - 1101607
// Omar Núñez - 1101587
// Óliver Infante - 1100292
// Lervis Pinales - 1096323

#include <iostream>
#include <stack>
#include <Windows.h>
#include "ControlFlow.h"

using namespace std;

stack<string> values;

int main()
{
    cout << "-- Stack Management --\n\n";
    cout << "Welcome!\n";
    cout << "This program uses data typee string to store given values.\n\n";
    
    while (true)
    {
        DisplayMenu();
    }
}

/// <summary>
/// Displays program menu.
/// </summary>
void DisplayMenu()
{
    int menuOption;

    cout << "Select an option. (1 - 4)\n";
    cout << "1. Add\n";
    cout << "2. Remove\n";
    cout << "3. Deploy\n";
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
            DeployStack();
            break;
        case 4:
            ExitProgram();
            break;
        default:
            cout << "Please, enter a valid option. (1 - 4)";
            break;
    }

    void ClearConsole();
}

/// <summary>
/// Add value to stack.
/// </summary>
void AddToStack()
{
    void ClearConsole();

    string value;
    cout << "Enter the value: ";
    cin >> value;

    values.push(value);
}

/// <summary>
/// Removes stack top value.
/// </summary>
void RemoveFromStack()
{
    if (values.empty())
    {
        cout << "Stack is currently empty.\n";
        Sleep(2000);
    }
    else
    {
        cout << values.top() << " removed.";
        Sleep(2000);
        values.pop();
    }
}

/// <summary>
/// Shows all the stack values.
/// </summary>
void DeployStack()
{
    while (!values.empty())
    {
        cout << values.top() << "\n";
        values.pop();
    }
}

/// <summary>
/// Closes program.
/// </summary>
void ExitProgram()
{
    exit(EXIT_SUCCESS);
}

/// <summary>
/// Clears console.
/// </summary>
void ClearConsole()
{
    system("cls");
}
