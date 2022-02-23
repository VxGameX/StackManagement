#include <iostream>

struct nodo;
void Push(nodo*& pila, std::string dato);
void Pop(nodo*& pila);
void DisplayStack(nodo*& pila);
std::string DisplayNode(nodo*& pila);
bool isStackEmpty(nodo*& pila);
void DebugMemory(nodo* pila);