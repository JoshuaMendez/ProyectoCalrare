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
     DisperseMatrix( const vector<vector<int>> &matriz , int m , int n); // Vector de Vectores  --ready
     DisperseMatrix(DisperseMatrix &matriz);      // Punto 3 --J

    /* Modificadoras */
    vector<vector<int>> rebuild(); // Reconstruir la matriz dispersa a normal con ceros y la retonar --ready
    void assign(int i, int j, int v);     // Modificar el valor en la posición i, j --J
    void add(DisperseMatrix &matriz);     // Suma entre matrices de igual tamaño --ready
    void productVector(vector<int> &vec);  // Multiplica el objeto actual por el vector --J

    /* Analizadoras */
    int get(int i, int j);            // Obtener valor i, j --ready
    Lista getRowLis(int fila);            // Retornar fila -- J
    vector<int> getRowVec(int fila);    //Retornar fila --ready
    Lista getColLis(int columna);         // Retornar columna --J
    vector<int> getColVec(int columna); //  Retornar columna --ready
    Lista getDisperseRowLis(int fila);    // Retornar fila con ceros -- J
    vector<int> getDisperseRowVec(int fila); // Retornar fila con ceros -- ready
    Lista getDisperseColLis(int columna); // Retornar columna con ceros --J
    vector<int> getDisperseColVec(int columna); // --s
    void printMatrix(string sep);      // Imprime la matriz con el separador --S
    int getMax();                      // Retorna el mayor elemento de la matriz --J
    DisperseMatrix getTranspose();     // Transpone la matriz --S
    Lista addMatrixList(DisperseMatrix &matriz); // --J

    /* Sobrecarga operadores */
    DisperseMatrix operator+(DisperseMatrix &matriz); // Suma entre 2 matrices --J
    DisperseMatrix operator*(DisperseMatrix &matriz); // Multiplicación entre 2 matrices --S
    bool operator==(DisperseMatrix &matriz);          // Verifica si 2 matrices son iguales --J
};

#endif
