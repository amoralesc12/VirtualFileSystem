#include <iostream>
using namespace std;
#include "operaciones.h"

void menu() {

    cout << "\n                --(AVL)--";
    cout << "\n__________________________________________";
    cout << "\n\n1. Insertar elementos en el arbol";
    cout << "\n2. Obtener altura del arbol";
    cout << "\n3. PRE-ORDER";
    cout << "\n4. POST-ORDER.";
    cout << "\n5. IN-ORDER.";
    cout << "\n6. Remover elemento del arbol";
    cout << "\n7. Busqueda del elemento";
    cout << "\n8. SALIR.";
    cout << "\n__________________________________________";
    cout << "\nOpcion Elegida -- ";
}

int main() 
{
    operaciones avl;
    int info, in, n;
    menu();
    cin >> info;
    while (info != 8) {
        switch (info) {
        case 1: cout << "\nCantidad de elementos para el arbol -- ";
            cin >> n;
            for (int i = 0; i < n; i++)
            {
                cout << "Insertar Elemento: ";
                cin >> in; avl.Insertar(in);
            }
            break;

        case 2: cout << "Altura del arbol -> ";
            cout << avl.GetAltura(avl.GetRaiz()) + 1 << endl;
            break;

        case 3: cout << "Pre-Order:\n";
            avl.PreoOrder(avl.GetRaiz());
            cout << endl;
            break;

        case 4: cout << "Post-Order:\n";
            avl.PostOrder(avl.GetRaiz());
            cout << endl;
            break;

        case 5:cout << "In-Order:\n";
            avl.InOrder(avl.GetRaiz());
            cout << endl;
            break;
        case 6: cout << "\n elemento que desea eliminar? -- ";
            cin >> in;
            avl.Remover_Prin(in);
            break;

        case 7: cout<< "\nElemento a buscar.. ";
            cin >> in;
            if (avl.Busqueda_Arbol(in)) { cout << "Elemento econtrado!\n"; }
            else { cout << "Elemento no econtrado.\n"; }
            break;

        case 8: cout << "Opcion Incorrecta.\n";
            break;
        }
        cout << "\nOtra opcion?";
        cin >> info;
    }
    cout << "\nCerrando.... ";
    return 0;
    }