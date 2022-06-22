
#include <iostream>
using namespace std;
struct node
{
    int element;
    struct node* left, * right;
    int ht;

};

//node* insert(node*, int);
//node* Delete(node*, int);
//void preorder(node*);
//void inorder(node*);
//int height(node*);
//node* rotateright(node*);
//node* rotateleft(node*);
//node* RR(node*);
//node* LL(node*);
//node* LR(node*);
//node* RL(node*);
//int balanceFactor(node*);
int main()
{
    node* root = NULL;
    int x, n, i, option;
    do {
        cout << "1.Create AVL Tree\n";
        cout << "2.Delete Element\n";
        cout << "3.End Program\n";
        cout << "Enter your choice ";
        cin >> option;
        switch (option)
        {
        case 1: cout << "\nEnter no.of elements : ";
            cin >> n;
            root = NULL;
            for (i = 0; i < n; i++) {

                cout << "Enter element of tree ";
                cin >> x;
                root = insert(root, x);
            }
            cout << "\nPreorder sequence : \n";
            preorder(root);
            cout << "\n\nInorder sequence : \n";
            inorder(root);
            break;

        case 2: cout << "Enter a element to be deleted : ";
            cin >> x;
            root = Delete(root, x);
            cout << "Preorder sequence : \n";
            preorder(root);
            cout << "\nInorder sequence : \n";
            inorder(root);
            break;
        }
    } while (option != 3);

    return 0;

}

node* insert(node* T, int x)
{

    if (T == NULL) {

        T = (node*)malloc(sizeof(node));
        T->element = x;
        T->left = NULL;
        T->right = NULL;
    }
    else

        if (x > T->element)
        {

            T->right = insert(T->right, x);
            if (balanceFactor(T) == -2)
                if (x > T->right->element)
                    T = RR(T);
                else
                    T = RL(T);

        }
        else
            if (x < T->element)
            {
                T->left = insert(T->left, x);
                if (balanceFactor(T) == 2)
                    if (x < T->left->element)
                        T = LL(T);
                    else
                        T = LR(T);

            }

    T->ht = height(T);

    return(T);
}
node* Delete(node* T, int x)
{
    node* p;

    if (T == NULL)
    {
        return NULL;
    }
    else
        if (x > T->element)
        {
            T->right = Delete(T->right, x);
            if (balanceFactor(T) == 2)
                if (balanceFactor(T->left) >= 0)
                    T = LL(T);
                else
                    T = LR(T);
        }
        else
            if (x < T->element)
            {
                T->left = Delete(T->left, x);
                if (balanceFactor(T) == -2)
                    if (balanceFactor(T->right) <= 0)
                        T = RR(T);
                    else
                        T = RL(T);
            }
            else
            {
                if (T->right != NULL)
                {
                    p = T->right;

                    while (p->left != NULL)
                        p = p->left;

                    T->element = p->element;
                    T->right = Delete(T->right, p->element);

                    if (balanceFactor(T) == 2)
                        if (balanceFactor(T->left) >= 0)
                            T = LL(T);
                        else
                            T = LR(T); \
                }
                else
                    return(T->left);
            }
    T->ht = height(T);
    return(T);
}
int height(node* T)
{

    int lh, rh;
    if (T == NULL)
        return(0);
    if (T->left == NULL)
        lh = 0;
    else
        lh = 1 + T->left->ht;

    if (T->right == NULL)
        rh = 0;
    else
        rh = 1 + T->right->ht;

    if (lh > rh)
        return(lh);

    return(rh);
}

node* rotateright(node* x)
{

    node* y;
    y = x->left;
    x->left = y->right;
    y->right = x;
    x->ht = height(x);
    y->ht = height(y);
    return(y);
}

node* rotateleft(node* x)
{
    node* y;
    y = x->right;
    x->right = y->left;
    y->left = x;
    x->ht = height(x);
    y->ht = height(y);
    return(y);
}

node* RR(node* T)
{

    T = rotateleft(T);
    return(T);
}

node* LL(node* T)
{
    T = rotateright(T);
    return(T);
}

node* LR(node* T)
{

    T->left = rotateleft(T->left);
    T = rotateright(T);
    return(T);
}

node* RL(node* T)
{
    T->right = rotateright(T->right);
    T = rotateleft(T);
    return(T);
}
int balanceFactor(node* T)
{
    int lh, rh;
    if (T == NULL)
        return(0);
    if (T->left == NULL)
        lh = 0;
    else
        lh = 1 + T->left->ht;
    if (T->right == NULL)
        rh = 0;
    else
        rh = 1 + T->right->ht;
    return(lh - rh);
}

void preorder(node* T)
{
    if (T != NULL)
    {
        cout << "Balance factor" << T->element << " " << balanceFactor(T) << endl;
        preorder(T->left);
        preorder(T->right);
    }
}
void inorder(node* T)
{

    if (T != NULL)
    {
        inorder(T->left);
        cout << "Balance Factor" << T->element << " " << balanceFactor(T) << endl;
        inorder(T->right);
    }
}

//#include <iostream>
//using namespace std;
////ARREGLAR POSORDEN Y PREORDEN 
////AGREGAR INORDEN
//struct node {
//    int elemento{};
//    node* izquierda = nullptr;
//    node* derecha = nullptr;
//    node* padre = nullptr;
//    int altura;
//};
//
//class AVL {
//
//    node* raiz;
//
//public:
//    AVL() : raiz(nullptr) {}
//
//    node* GetRaiz() { return raiz; }
//
//    int max(int a, int b) { return (a > b ? a : b); }
//
//    void Insertar(int _elemento) {
//        if (raiz == nullptr) {
//            raiz = new node();
//            raiz->elemento = _elemento;
//            cout << "Elemento agregado!.\n";
//            raiz->altura = 0;
//            raiz->padre = nullptr;
//        }
//        else {
//            auto aux = GetRaiz();
//            node* nuevo = new node();
//            nuevo->elemento = _elemento;
//
//            while (aux != nullptr) {
//                if (aux->elemento > _elemento) {
//                    if (aux->izquierda == nullptr) {
//                        aux->izquierda = nuevo;
//                        nuevo->altura = 0;
//                        nuevo->padre = aux;
//                        cout << "Elemento agregado!.\n"; break;
//                    }
//                    else { aux = aux->izquierda; }
//                }
//                else {
//                    if (aux->derecha == nullptr) {
//                        aux->derecha = nuevo;
//                        nuevo->altura = 0;
//                        nuevo->padre = aux;
//                        cout << "Elemento agregado!.\n"; break;
//                    }
//                    else { aux = aux->derecha; }
//                }
//            }
//            Rebalancer(nuevo);
//        }
//    }
//
//    int GetAltura(node* temp)
//    {
//        return ((temp == nullptr) ? -1 : temp->altura);
//    }
//
//    int Factor_equilibrio(node* temp)
//    {
//
//        return (GetAltura(temp->derecha) - GetAltura(temp->izquierda));
//    }
//
//    void Altura_eq(node* temp) {
//        int l = -1, r = -1;
//        if (temp->izquierda) { l = temp->izquierda->altura; }
//        if (temp->derecha) { r = temp->derecha->altura; }
//        temp->altura = max(l, r) + 1;
//    }
//
//    void Arreglar_Arbol(node* temp) {
//        if (Factor_equilibrio(temp) == 2) {
//            if (Factor_equilibrio(temp->derecha) < 0) { Rotacion_derecha(temp->derecha); }
//            Rotacion_izquierda(temp);
//            Altura_eq(temp);
//        }
//        else if (Factor_equilibrio(temp) == -2) {
//            if (Factor_equilibrio(temp->izquierda) > 0) { Rotacion_izquierda(temp->izquierda); }
//            Rotacion_derecha(temp);
//            Altura_eq(temp);
//        }
//    }
//
//    void Rebalancer(node* temp) {
//        if (temp == raiz) { Arreglar_Arbol(raiz); }
//        else {
//            while (temp != nullptr) {
//                Altura_eq(temp);
//                temp = temp->padre;
//                if (temp) { Arreglar_Arbol(temp); }
//            }
//        }
//    }
//
//    void Rotacion_izquierda(node* nodo) {
//        node* nuevo = new node();
//        if (nodo->derecha->izquierda) { nuevo->derecha = nodo->derecha->izquierda; }
//        nuevo->izquierda = nodo->izquierda;
//        nuevo->elemento = nodo->elemento;
//        nodo->elemento = nodo->derecha->elemento;
//
//        nodo->izquierda = nuevo;
//        if (nuevo->izquierda) { nuevo->izquierda->padre = nuevo; }
//        if (nuevo->derecha) { nuevo->derecha->padre = nuevo; }
//        nuevo->padre = nodo;
//
//        if (nodo->derecha->derecha) { nodo->derecha = nodo->derecha->derecha; }
//        else { nodo->derecha = nullptr; }
//
//        if (nodo->derecha) { nodo->derecha->padre = nodo; }
//
//        Altura_eq(nodo->izquierda);
//        if (nodo->derecha) { Altura_eq(nodo->derecha); }
//        Altura_eq(nodo);
//    }
//
//    void Rotacion_derecha(node* nodo) {
//        node* nuevo = new node();
//        if (nodo->izquierda->derecha) { nuevo->izquierda = nodo->izquierda->derecha; }
//        nuevo->derecha = nodo->derecha;
//        nuevo->elemento = nodo->elemento;
//        nodo->elemento = nodo->izquierda->elemento;
//
//        nodo->derecha = nuevo;
//        if (nuevo->izquierda) { nuevo->izquierda->padre = nuevo; }
//        if (nuevo->derecha) { nuevo->derecha->padre = nuevo; }
//        nuevo->padre = nodo;
//
//        if (nodo->izquierda->izquierda) { nodo->izquierda = nodo->izquierda->izquierda; }
//        else { nodo->izquierda = nullptr; }
//
//        if (nodo->izquierda) { nodo->izquierda->padre = nodo; }
//
//        Altura_eq(nodo->derecha);
//        if (nodo->izquierda) { Altura_eq(nodo->izquierda); }
//        Altura_eq(nodo);
//    }
//
//
//    void PreoOrder(node* temp) {
//        if (temp == nullptr) { return; }
//        cout << "->" << temp->elemento;
//        PreoOrder(temp->izquierda);
//        PreoOrder(temp->derecha);
//    }
//
//    void PostOrder(node* temp) {
//        if (temp == nullptr) { return; }
//        PostOrder(temp->izquierda);
//        PostOrder(temp->derecha);
//        cout << "->" << temp;
//    }
//
//    void RemoverNodo(node* _Parent, node* nodo, int _elemento) {
//        if (nodo == nullptr) { return; }
//        if (nodo->elemento == _elemento) {
//            //CASE -- 1
//            if (nodo->izquierda == nullptr && nodo->derecha == nullptr) {
//                if (_Parent->elemento == nodo->elemento) { raiz = nullptr; }
//                else if (_Parent->derecha == nodo) { _Parent->derecha = nullptr; }
//                else { _Parent->izquierda = nullptr; }
//                Rebalancer(_Parent);
//            }
//            //CASE -- 2
//            else if (nodo->izquierda != nullptr && nodo->derecha == nullptr) {
//                int sp = nodo->elemento;
//                nodo->elemento = nodo->izquierda->elemento;
//                nodo->izquierda->elemento = sp;
//                RemoverNodo(nodo, nodo->izquierda, _elemento);
//            }
//            else if (nodo->izquierda == nullptr && nodo->derecha != nullptr) {
//                int sp = nodo->elemento;
//                nodo->elemento = nodo->derecha->elemento;
//                nodo->derecha->elemento = sp;
//                RemoverNodo(nodo, nodo->derecha, _elemento);
//            }
//            //CASE -- 3
//            else {
//                node* temp = nodo->derecha;
//                int flag = 0;
//                while (temp->izquierda) { flag = 1; _Parent = temp; temp = temp->izquierda; }
//                if (!flag) { _Parent = nodo; }
//                int sp = nodo->elemento;
//                nodo->elemento = temp->elemento;
//                temp->elemento = sp;
//                RemoverNodo(_Parent, temp, temp->elemento);
//            }
//        }
//    }
//
//    void Remover_Prin(int _elemento) {
//        auto temp = raiz;
//        auto _Parent = temp;
//        bool flag = false;
//        if (temp == nullptr) { RemoverNodo(nullptr, nullptr, _elemento); }
//
//        while (temp) {
//            if (_elemento == temp->elemento) { flag = true; RemoverNodo(_Parent, temp, _elemento); break; }
//            else if (_elemento < temp->elemento) { _Parent = temp; temp = temp->izquierda; }
//            else { _Parent = temp; temp = temp->derecha; }
//        }
//
//        if (!flag) { cout << "Elemento no existe!\n"; }
//        else { cout << "Element eliminado!\n"; }
//    }
//};
//
//void menu() {
//
//    cout << "\n                --(AVL)--";
//    cout << "\n__________________________________________";
//    cout << "\n\n1. Insertar elementos en el arbol";
//    cout << "\n2. Obtener altura del arbol";
//    cout << "\n3. PRE-ORDER";
//    cout << "\n4. POST-ORDER.";
//    cout << "\n5. Remover elemento del arbol";
//    cout << "\n6. SALIR.";
//    cout << "\n__________________________________________";
//    cout << "\nOpcion Elegida -- ";
//}
//
//int main()
//{
//    AVL demo;
//    int info, input, n;
//    menu();
//    cin >> info;
//    while (info != 7) {
//        switch (info) {
//        case 1: cout << "\nCantidad de elementos para el arbol -- ";
//            cin >> n;
//            for (int i = 0; i < n; i++)
//            {
//                cout << "Insertar Elemento: ";
//                cin >> input; demo.Insertar(input);
//            }
//            break;
//
//        case 2: cout << "Altura del arbol -> ";
//            cout << demo.GetAltura(demo.GetRaiz()) + 1 << endl;
//            break;
//
//        case 3: cout << "Pre-Order";
//            demo.PreoOrder(demo.GetRaiz());
//            cout << endl;
//            break;
//
//        case 4: cout << "Post-Order";
//            demo.PostOrder(demo.GetRaiz());
//            cout << endl;
//            break;
//
//        case 5: cout << "\n elemento que desea eliminar? -- ";
//            cin >> input;
//            demo.Remover_Prin(input);
//            break;
//
//        default: cout << "Opcion Incorrecta.\n";
//        }
//        cout << "\nOtra opcion?";
//        cin >> info;
//    }
//    cout << "\nCerrando.... ";
//    return 0;
//}