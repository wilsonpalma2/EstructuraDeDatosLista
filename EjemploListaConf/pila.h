#ifndef PILA_H
#define PILA_H


typedef struct nodoo
{
    int id;
    struct nodoo *siguiente;
}nodo;

typedef struct pilaa
{
    int tamanio;
    struct nodoo *ultimo;
}pila;


pila* inicializar_pila(pila *nueva_pila);

void push(pila *p, int id);

int pop(pila *p);

int pila_vacia(pila *p);

void recorrer_pila_dot(pila *p, int num);

#endif // PILA_H
