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
/// Displays program menu.
/// </summary>
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
        case 0:
            DisplayHelp();
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
    string value;

    while (GetAsyncKeyState(VK_ESCAPE) == 0)
    {
        ClearConsole();

        cout << "Enter the value (Press ESC enter last value): ";
        cin >> value;

        values.push(value);
    }
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
            //cout << values.top() << "\n";
            values.pop();
        }
        cout << "Stack cleared.\n";
    }
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
        cout << "* TOP *\n\n";

        while (!values.empty())
        {
            cout << "- " << values.top() << "\n";
            aux.push(values.top());
            values.pop();
        }
        cout << "\n* BOTTOM *\n";

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
