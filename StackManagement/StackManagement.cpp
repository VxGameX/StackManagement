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
    cout << "Welcome!\n\n";
    cout << "- NOTE: This program uses string data type to store given values. -\n\n";
    
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

    cout << "Select an option. (1 - 5)\n";
    cout << "1. Add\n";
    cout << "2. Remove\n";
    cout << "3. Display\n";
    cout << "4. Deploy\n";
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
            DeployStack();
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

/// <summary>
/// Add value to stack.
/// </summary>
void AddToStack()
{
    ClearConsole();

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
    cout << "Stack deployed.";
    Pause();
}

/// <summary>
/// Shows all the stack values.
/// </summary>
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
        int i = 1;
        while (!values.empty())
        {
            cout << i << "-- " << values.top() << "\n";
            aux.push(values.top());
            values.pop();

            i++;
        }

        while (!aux.empty())
        {
            values.push(aux.top());
            aux.pop();
        }
    }
    Pause();
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
