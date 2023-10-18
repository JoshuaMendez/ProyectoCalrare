/*
 * Autores: Sebastian Izquierdo S. y Jhosua Mendez
 * Fecha de creación: 12 de Octubre
 * Fecha última modificación: 12 de Octubre
 * Versión: 1.0
 *
 * Archivo encabezado libreria TAD matriz Dispersa
 * Representación Estructuras Matriz Dispersa de la forma de coordenadas con vectores
 */
#ifndef __MATRIZDISPERSA_H
#define __MATRIZDISPERSA_H

#include <iostream>
#include "lista.h"
#include <vector>
#include <string>

using namespace std;

/************************
 * ESTRUCTURAS DE DATOS *
 ************************/

class DisperseMatrix
{
private:
    vector<int> valores;
    vector<int> filas;
    vector<int> columnas;
    int nFilas , nColumnas ;
public:
    /************************
     * OPERACIONES DEL TAD *
     ************************/

    /* Constructoras */
     DisperseMatrix();
     DisperseMatrix(int **&matriz, int m, int n); // Arreglo de 2 dimensiones
     DisperseMatrix( const vector<vector<int>> &matriz , int m , int n); // Vector de Vectores 
     DisperseMatrix(DisperseMatrix &matriz);      // Punto 3

    /* Modificadoras */
    void rebuild(DisperseMatrix &matriz); // Reconstruir la matriz dispersa a normal con ceros
    void assign(int i, int j, int v);     // Modificar el valor en la posición i, j
    void add(DisperseMatrix &matriz);     // Suma entre matrices
    void productVector(vector<int> vec);  // Multiplica el objeto actual por el vector

    /* Analizadoras */
    void get(int i, int j);            // Obtener valor i, j
    Lista getRowLis(int fila);            // Retornar fila
    vector<int> getRowVec(int fila); 
    Lista getColLis(int columna);         // Retornar columna
    vector<int> getColVec(int columna); 
    Lista getDisperseRowLis(int fila);    // Retornar fila con ceros
    vector<int> getDisperseRowVec(int fila);
    Lista getDisperseColLis(int columna); // Retornar columna con ceros
    vector<int> getDisperseColVec(int columna);
    void printMatrix(string sep);      // Imprime la matriz con el separador
    int getMax();                      // Retorna el mayor elemento de la matriz
    DisperseMatrix getTranspose();     // Transpone la matriz
    Lista addMatrixList(DisperseMatrix matriz);
    vector<int> addMatrixListVec(DisperseMatrix matriz);

    /* Sobrecarga operadores */
    DisperseMatrix operator+(DisperseMatrix &matriz); // Suma entre 2 matrices
    DisperseMatrix operator*(DisperseMatrix &matriz); // Multiplicación entre 2 matrices
    bool operator==(DisperseMatrix &matriz);          // Verifica si 2 matrices son iguales
};

#endif
