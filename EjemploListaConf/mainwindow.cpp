#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "pila.h"
#include <QDebug>
#include <stdio.h>
#include <QInputDialog>
#include <QMessageBox>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include "malloc.h"


pila *p1;

void iniciar_estructuras()
{
    p1 = inicializar_pila(p1);
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void inicioDOT()
{
    char *nombre = "EjemploPila.dot";
    FILE *archivo1 = fopen(nombre, "w");
    char *inicio= "digraph{ \n rankdir = LR; \n node [shape = record, color = lightblue]; \n";
    fprintf(archivo1, "%s \n", inicio);
    fclose(archivo1);
}


void finDOT()
{
    char *nombre = "EjemploPila.dot";
    FILE *archivo = fopen(nombre, "a");
    char *fin= "\n}";
    fprintf(archivo, "%s \n", fin);
    fclose(archivo);
}


void todoCodigo()
{
    inicioDOT();
    recorrer_pila_dot(p1,1);
    finDOT();
}

void recorrer_pila_dot(pila *p, int num)
{
    nodo *nodo_aux = p->ultimo;
    int contador = p->tamanio;
    int a = 0;


    char *nombre1 = "EjemploPila.dot";
    FILE *archivo1 = fopen(nombre1, "a");

    char *c1 = "subgraph clusterpila";
    fprintf(archivo1, "%s", c1);
    fprintf(archivo1, "%d", num);

    char *c2 = "{ \n label = ""\"PILA DE EJEMPLO ";
    fprintf(archivo1, "%s", c2);

    char *c3 = """\"; \n color=blue; \nPila";
    fprintf(archivo1, "%s", c3);
    fprintf(archivo1, "%d", num);

    char *c4 = "[color = red, label = ""\" <top> TOP | <Tam> ";
    fprintf(archivo1, "%s", c4);
    if(nodo_aux != NULL)
    fprintf(archivo1, "%d", nodo_aux->id);
    else{

    }

    char *c444 = """\"]; \n ""\"Pila";
    fprintf(archivo1, "%s", c444);
    fprintf(archivo1, "%d", num);

    char *c5 = """\":top->""\"ListaPila";
    fprintf(archivo1, "%s", c5);
    fprintf(archivo1, "%d", num);

    char *c6 = """\":f0  \nListaPila";
    fprintf(archivo1, "%s", c6);
    fprintf(archivo1, "%d", num);

    char *c7 = "[label = ""\" ";
    fprintf(archivo1, "%s", c7);



    if(pila_vacia(p) == 1)
    {

    }else{
        while(contador >= 1)
        {

            char *c9 = "<f";
            fprintf(archivo1, "%s", c9);
            fprintf(archivo1, "%d", a);
            a++;
            char *c10 = "> ";
            fprintf(archivo1, "%s", c10);
            fprintf(archivo1, "%d", nodo_aux->id);
            if(nodo_aux->siguiente == NULL)
            {

            }else{
                char *c11 = "| ";
                fprintf(archivo1, "%s", c11);
            }
            nodo_aux = nodo_aux->siguiente;
            contador--;
        }
    }


    char *c12 = """\"];  \n }";
    fprintf(archivo1, "%s", c12);
    fclose(archivo1);

}



void MainWindow::on_pushButton_clicked()
{
    iniciar_estructuras();
}

int i = 0;



void MainWindow::on_pushButton_2_clicked()
{
    push(p1,i);
    i++;
}



void MainWindow::on_pushButton_3_clicked()
{
    pop(p1);
}



void MainWindow::on_pushButton_4_clicked()
{
    todoCodigo();
    system("dot -Tjpg EjemploPila.dot -o EjemploPila.jpg");

    QGraphicsScene *scene = new QGraphicsScene();
    QPixmap m ("EjemploPila.jpg");
    scene->addPixmap(m);
    ui->graphicsView->setScene(scene);

}
