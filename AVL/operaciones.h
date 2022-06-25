#pragma once
#include <iostream>
using namespace std;
#ifndef _operaciones
#define _operaciones
struct node {
    int elemento{};
    node* izquierda = nullptr;
    node* derecha = nullptr;
    node* padre = nullptr;
    int altura;
};
class operaciones
{
    node* raiz;

public:
    operaciones();

    node* GetRaiz();

    int max(int a, int b);

    void Insertar(int _elemento);
    int GetAltura(node* temp);

    int Factor_equilibrio(node* temp);

    void Altura_eq(node* temp);

   // void Balance1(node* temp);
    node* Busqueda_Arbol(int temp);
    void Balance2(node* temp);

    void Rotacion_izquierda(node* nodo);

    void Rotacion_derecha(node* nodo);


    void PreoOrder(node* temp);

    void PostOrder(node* temp);

    void InOrder(node* temp);


    void Remover_Prin(int _elemento);
private: 
    void Balance1 (node*);
    void RemoverNodo(node* _Parent, node* nodo, int _elemento);
};

#endif // !_operaciones



