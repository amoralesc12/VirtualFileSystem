#include <iostream>
using namespace std;
//ARREGLAR POSORDEN Y PREORDEN 
//AGREGAR INORDEN
struct node {
    int elemento{};
    node* izquierda = nullptr;
    node* derecha = nullptr;
    node* padre = nullptr;
    int altura;
};

class AVL {

    node* raiz;

public:
    AVL() : raiz(nullptr) {}

    node* GetRaiz() { return raiz; }

    int max(int a, int b) { return (a > b ? a : b); }

    void Insertar(int _elemento) {
        if (raiz == nullptr) {
            raiz = new node();
            raiz->elemento = _elemento;
            cout << "Elemento agregado!.\n";
            raiz->altura = 0;
            raiz->padre = nullptr;
        }
        else {
            auto aux = GetRaiz();
            node* nuevo = new node();
            nuevo->elemento = _elemento;

            while (aux != nullptr) {
                if (aux->elemento > _elemento) {
                    if (aux->izquierda == nullptr) {
                        aux->izquierda = nuevo;
                        nuevo->altura = 0;
                        nuevo->padre = aux;
                        cout << "Elemento agregado!.\n"; break;
                    }
                    else { aux = aux->izquierda; }
                }
                else {
                    if (aux->derecha == nullptr) {
                        aux->derecha = nuevo;
                        nuevo->altura = 0;
                        nuevo->padre = aux;
                        cout << "Elemento agregado!.\n"; break;
                    }
                    else { aux = aux->derecha; }
                }
            }
            Balance2(nuevo);
        }
    }
    int GetAltura(node* temp) { return ((temp == nullptr) ? -1 : temp->altura); }

    int Factor_equilibrio(node* temp)
    { 
        int left, right;
        if (temp == nullptr)
            return (0);
        if (temp->izquierda == nullptr)
            left = 0;
        else
            left = 1 + temp->izquierda->altura;
        if (temp->derecha == nullptr)

            right = 0;
        else
            right = 1 + temp->derecha->altura;
        return (left - right);
    }

    void Altura_eq(node* temp) {
        int l = -1, r = -1;
        if (temp->izquierda) { l = temp->izquierda->altura; }
        if (temp->derecha) { r = temp->derecha->altura; }
        temp->altura = max(l, r) + 1;
    }

    void Balance1(node* temp) { // Balance 1 Arreglar Arbol funcion donde se realizan las rotaciones
        if (Factor_equilibrio(temp) == 2) {
            if (Factor_equilibrio(temp->derecha) < 0) { Rotacion_derecha(temp->derecha); }
            Rotacion_izquierda(temp);
            Altura_eq(temp);
        }
        else if (Factor_equilibrio(temp) == -2) {
            if (Factor_equilibrio(temp->izquierda) > 0) { Rotacion_izquierda(temp->izquierda); }
            Rotacion_derecha(temp);
            Altura_eq(temp);
        }
    }

    void Balance2(node* temp) { // funcion que llama balance 1 para usar en las funciones
        if (temp == raiz) { Balance1(raiz); }
        else {
            while (temp != nullptr) {
                Altura_eq(temp);
                temp = temp->padre;
                if (temp) { Balance1(temp); }
            }
        }
    }

    void Rotacion_izquierda(node* nodo) {
        node* nuevo = new node();
        if (nodo->derecha->izquierda) { nuevo->derecha = nodo->derecha->izquierda; }
        nuevo->izquierda = nodo->izquierda;
        nuevo->elemento = nodo->elemento;
        nodo->elemento = nodo->derecha->elemento;

        nodo->izquierda = nuevo;
        if (nuevo->izquierda) { nuevo->izquierda->padre = nuevo; }
        if (nuevo->derecha) { nuevo->derecha->padre = nuevo; }
        nuevo->padre = nodo;

        if (nodo->derecha->derecha) { nodo->derecha = nodo->derecha->derecha; }
        else { nodo->derecha = nullptr; }

        if (nodo->derecha) { nodo->derecha->padre = nodo; }

        Altura_eq(nodo->izquierda);
        if (nodo->derecha) { Altura_eq(nodo->derecha); }
        Altura_eq(nodo);
    }

    void Rotacion_derecha(node* nodo) {
        node* nuevo = new node();
        if (nodo->izquierda->derecha) { nuevo->izquierda = nodo->izquierda->derecha; }
        nuevo->derecha = nodo->derecha;
        nuevo->elemento = nodo->elemento;
        nodo->elemento = nodo->izquierda->elemento;

        nodo->derecha = nuevo;
        if (nuevo->izquierda) { nuevo->izquierda->padre = nuevo; }
        if (nuevo->derecha) { nuevo->derecha->padre = nuevo; }
        nuevo->padre = nodo;

        if (nodo->izquierda->izquierda) { nodo->izquierda = nodo->izquierda->izquierda; }
        else { nodo->izquierda = nullptr; }

        if (nodo->izquierda) { nodo->izquierda->padre = nodo; }

        Altura_eq(nodo->derecha);
        if (nodo->izquierda) { Altura_eq(nodo->izquierda); }
        Altura_eq(nodo);
    }

  
    void PreoOrder(node* temp) {
        if (temp == nullptr) { return; }
        cout   << temp->elemento << "  " << Factor_equilibrio(temp) << "\n";
        PreoOrder(temp->izquierda);
        PreoOrder(temp->derecha);
    }

    void PostOrder(node* temp) {
        if (temp == nullptr) { return; }
        PostOrder(temp->izquierda);
        PostOrder(temp->derecha);
        cout << temp->elemento << "  " << Factor_equilibrio(temp) << "\n";
    }

    void InOrder(node* temp)
    {
        if (temp == nullptr) { return; }
        InOrder(temp->izquierda);
        cout << temp->elemento << "  " << Factor_equilibrio(temp) << "\n";
        InOrder(temp->derecha);

    }

    void RemoverNodo(node* _Parent, node* nodo, int _elemento) {
        if (nodo == nullptr) { return; }
        if (nodo->elemento == _elemento) {
            //CASE -- 1
            if (nodo->izquierda == nullptr && nodo->derecha == nullptr) {
                if (_Parent->elemento == nodo->elemento) { raiz = nullptr; }
                else if (_Parent->derecha == nodo) { _Parent->derecha = nullptr; }
                else { _Parent->izquierda = nullptr; }
                Balance2(_Parent);
            }
            //CASE -- 2
            else if (nodo->izquierda != nullptr && nodo->derecha == nullptr) {
                int sp = nodo->elemento;
                nodo->elemento = nodo->izquierda->elemento;
                nodo->izquierda->elemento = sp;
                RemoverNodo(nodo, nodo->izquierda, _elemento);
            }
            else if (nodo->izquierda == nullptr && nodo->derecha != nullptr) {
                int sp = nodo->elemento;
                nodo->elemento = nodo->derecha->elemento;
                nodo->derecha->elemento = sp;
                RemoverNodo(nodo, nodo->derecha, _elemento);
            }
            //CASE -- 3
            else {
                node* temp = nodo->derecha;
                int flag = 0;
                while (temp->izquierda) { flag = 1; _Parent = temp; temp = temp->izquierda; }
                if (!flag) { _Parent = nodo; }
                int sp = nodo->elemento;
                nodo->elemento = temp->elemento;
                temp->elemento = sp;
                RemoverNodo(_Parent, temp, temp->elemento);
            }
        }
    }

    void Remover_Prin(int _elemento) {
        auto temp = raiz;
        auto _Parent = temp;
        bool flag = false;
        if (temp == nullptr) { RemoverNodo(nullptr, nullptr, _elemento); }

        while (temp) {
            if (_elemento == temp->elemento) { flag = true; RemoverNodo(_Parent, temp, _elemento); break; }
            else if (_elemento < temp->elemento) { _Parent = temp; temp = temp->izquierda; }
            else { _Parent = temp; temp = temp->derecha; }
        }

        if (!flag) { cout << "Elemento no existe!\n"; }
        else { cout << "Element eliminado!\n"; }
    }
};

void menu() {

    cout << "\n                --(AVL)--";
    cout << "\n__________________________________________";
    cout << "\n\n1. Insertar elementos en el arbol";
    cout << "\n2. Obtener altura del arbol";
    cout << "\n3. PRE-ORDER";
    cout << "\n4. POST-ORDER.";
    cout << "\n5. IN-ORDER.";
    cout << "\n6. Remover elemento del arbol";
    cout << "\n7. SALIR.";
    cout << "\n__________________________________________";
    cout << "\nOpcion Elegida -- ";
}

int main() 
{
    AVL demo;
    int info, input, n;
    menu();
    cin >> info;
    while (info != 7) {
        switch (info) {
        case 1: cout << "\nCantidad de elementos para el arbol -- ";
            cin >> n;
            for (int i = 0; i < n; i++)
            {
                cout << "Insertar Elemento: ";
                cin >> input; demo.Insertar(input);
            }
            break;

        case 2: cout << "Altura del arbol -> ";
            cout << demo.GetAltura(demo.GetRaiz()) + 1 << endl;
            break;

        case 3: cout << "Pre-Order:\n";
            demo.PreoOrder(demo.GetRaiz());
            cout << endl;
            break;

        case 4: cout << "Post-Order:\n";
            demo.PostOrder(demo.GetRaiz());
            cout << endl;
            break;

        case 5:cout << "In-Order:\n";
            demo.InOrder(demo.GetRaiz());
            cout << endl;
            break;
        case 6: cout << "\n elemento que desea eliminar? -- ";
            cin >> input;
            demo.Remover_Prin(input);
            break;

        default: cout << "Opcion Incorrecta.\n";
        }
        cout << "\nOtra opcion?";
        cin >> info;
    }
    cout << "\nCerrando.... ";
    return 0;
    }