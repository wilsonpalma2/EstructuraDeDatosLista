#include "pila.h"
#include <stdio.h>
#include <stdlib.h>
#include <QDebug>

int condicion = 0;

pila* inicializar_pila(pila *nueva_pila){

    nueva_pila = (pila *)malloc(sizeof(pila));
    nueva_pila->ultimo = NULL;
    nueva_pila->tamanio = 0;

                     QTextStream out(stdout);
                     out << QString("Se inicializo la nueva pila \n");
    return nueva_pila;
}

void push(pila *p, int id)
{
    nodo *nuevo_nodo = (nodo *)malloc(sizeof(nodo));
    nuevo_nodo->id = id;
    nuevo_nodo->siguiente = NULL;

    if(pila_vacia(p) == 1)
    {
        p->ultimo = nuevo_nodo;
        condicion = 1;
        p->tamanio++;

    }else{
        nuevo_nodo->siguiente = p->ultimo;
        p->ultimo = nuevo_nodo;
        condicion = 1;
        p->tamanio++;
    }
}

int pop(pila *p)
{
    nodo *nodo_extraer = NULL;
    if(pila_vacia(p) == 1)
    {
            QTextStream out(stdout);
            out << QString("Error: No se puede eliminar, pila vacia.");
            free(nodo_extraer);
            return NULL;
    }else{
            if(p->tamanio == 1)
            {
                nodo_extraer = p->ultimo;
                p->ultimo = NULL;
                p->tamanio--;
                return nodo_extraer->id;
            }else{
            nodo_extraer = p->ultimo;
            p->ultimo = nodo_extraer->siguiente;
            QTextStream out(stdout);
            out << QString("Se extrajo el elemento : ") << qint32(nodo_extraer->id) << QString("\n");
            p->tamanio--;
            return nodo_extraer->id;
            }
        }
 free(nodo_extraer);
 }

int obtener_top(pila *p)
{

    if(pila_vacia(p) == 1)
    {
        QTextStream out(stdout);
        out << QString("Error: La pila esta vacia.\n");
        return NULL;
    }else{
        QTextStream out(stdout);
        out << QString("Top de la pila : ") << qint32(p->ultimo->id) << QString("\n");
        return p->ultimo->id;
    }
}

int pila_vacia(pila *p)
{
    if(p->ultimo == NULL && p->tamanio == 0)
        return 1;
    else
        return 0;

}
