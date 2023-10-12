/*
 * Autores: Sebastian Izquierdo S. y Jhosua Mendez
 * Fecha de creación: 12 de Octubre
 * Fecha última modificación: 12 de Octubre
 * Versión: 1.0
 *
 * Archivo encabezado libreria TAD matriz Dispersa
 * Representación Estructuras Matriz Dispersa con listas Encadenadas Dobles
 */
#ifndef __MATRIZDISPERSA_H
#define __MATRIZDISPERSA_H

#include <iostream>
#include <vector>
#include "lista.h"
#include <string>

using namespace std;

/************************
 * ESTRUCTURAS DE DATOS *
 ************************/
typedef int Elemento;

class Nodo
{
public:
    Elemento fila;
    Elemento columna;
    Elemento dato;
    Nodo *sig;
    Nodo *ant;
    Nodo *lista;
};

class DisperseMatrix
{
private:
    Nodo *act;

public:
    /************************
     * OPERACIONES DEL TAD *
     ************************/

    /* Constructoras */
    void MatrizDispersa();
    void MatrizDispersa(int **&matriz, int m, int n); // Arreglo de 2 dimensiones
    void MatrizDispersa(vector<vector<int>> &matriz); // Vector de Vectores
    void MatrizDispersa(DisperseMatrix &matriz);      // Punto 3

    /* Modificadoras */
    void rebuild(DisperseMatrix &matriz); // Reconstruir la matriz dispersa a normal con ceros
    void assign(int i, int j, int v);     // Modificar el valor en la posición i, j
    void add(DisperseMatrix &matriz);     // Suma entre matrices
    void productVector(vector<int> vec);  // Multiplica el objeto actual por el vector

    /* Analizadoras */
    void get(int i, int j);            // Obtener valor i, j
    Lista getRow(int fila);            // Retornar fila
    Lista getCol(int columna);         // Retornar columna
    Lista getDisperseRow(int fila);    // Retornar fila con ceros
    Lista getDisperseCol(int columna); // Retornar columna con ceros
    void printMatrix(string sep);      // Imprime la matriz con el separador
    int getMax();                      // Retorna el mayor elemento de la matriz
    DisperseMatrix getTranspose();     // Transpone la matriz
    Lista addMatrixList(DisperseMatrix matriz);

    /* Sobrecarga operadores */
    DisperseMatrix operator+(DisperseMatrix &matriz); // Suma entre 2 matrices
    DisperseMatrix operator*(DisperseMatrix &matriz); // Multiplicación entre 2 matrices
    bool operator==(DisperseMatrix &matriz);          // Verifica si 2 matrices son iguales
};

#endif
