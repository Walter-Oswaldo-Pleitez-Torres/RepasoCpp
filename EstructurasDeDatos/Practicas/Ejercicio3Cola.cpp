#include <iostream>

using namespace std;

struct Nodo{
    int elemento;
    struct Nodo *siguiente;
};

void Push(Nodo *&, Nodo*&, int);
bool Vacia(Nodo *&);
void Imprimir(Nodo *&);
void Pop(Nodo *&, Nodo *&, int &);

int main(){
    Nodo *frente = nullptr;
    Nodo *final = nullptr;
    int input, continuar = 1, eleccion;

    do{
        cout<<"1)AGREGAR NODO  2)IMPRIMIR NODO  3)ELIMINAR NODOS"<<endl;
        cin>>eleccion;

        switch(eleccion){
        case 1:
        cout<<"Ingrese un valor para el Nodo: "<<endl;
        cin>>input;
        Push(frente, final, input);
        break;
        case 2:
        cout<<"---------- NODOS ----------"<<endl;
        Imprimir(frente);
        break;
        case 3:
        Pop(frente, final, input);
        break;
    }
    cout<<"1)MENU  0)SALIR"<<endl;
    cin>>continuar;

    }while(continuar == 1);

    return 0;
}

bool Vacia(Nodo *&frente){
    if(frente == nullptr){
        return true;
    }
    else{
        return false;
    }
}

void Push(Nodo *&frente, Nodo*&final, int dato){
    Nodo *nuevoNodo = new Nodo();
    nuevoNodo->elemento = dato;
    nuevoNodo->siguiente = nullptr;

    if(Vacia(frente)){
        frente = nuevoNodo;
    }
    else{
        final->siguiente = nuevoNodo;
    }
    final = nuevoNodo;

    cout<<"Nodo Agregado con valor: "<<dato<<endl;
    cout<<endl;
}

void Imprimir(Nodo *&frente){
    Nodo *printer = frente;

    while(printer != nullptr){
        cout<<"Valor: "<<printer->elemento<<" DirValor: "<<printer<<" DirValorSig: "<<printer->siguiente<<endl;

        printer = printer->siguiente;
    }
}
void Pop(Nodo *&frente, Nodo *&final, int &dato){
    Nodo *aux = frente;
    dato = aux->elemento;

    if(frente == final){
        frente = nullptr;
        final = nullptr;
    }
    else{
        frente = frente->siguiente;
    }
    delete aux;
    cout<<"Nodo con valor: "<<dato<<" Eliminado"<<endl;
}