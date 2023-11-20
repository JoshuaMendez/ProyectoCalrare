/*
 * Autores: Sebastian Izquierdo S. y Joshua Mendez
 * Archivo encabezado libreria TAD matriz Dispersa
 * Representación Estructuras Matriz Dispersa con listas
 */
#ifndef __MATRIZDISPERSA_H
#define __MATRIZDISPERSA_H

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>

using namespace std;

/************************
 * ESTRUCTURAS DE DATOS *
 ************************/

class DisperseMatrix
{
private:
    // public:
    vector<list<pair<int, int>>> matriz;
    int nFilas; // Equivalente a tamaño del vector
    int nColumnas;

public:
    /************************
     * OPERACIONES DEL TAD *
     ************************/
    /* Constructoras */
    DisperseMatrix();                       // Vacío
    DisperseMatrix(int **, int, int);       // Arreglo de 2 dimensiones
    DisperseMatrix(vector<vector<int>> &);  // Vector de Vectores
    DisperseMatrix(const DisperseMatrix &); // Recibe una matriz dispersa

    /* Modificadoras */
    vector<vector<int>> rebuild();     // Reconstruir la matriz dispersa a normal con ceros y la retonar
    void assign(int, int, int);        // Modificar el valor en la posición i, j
    void add(DisperseMatrix &);        // Suma entre matrices
    void productVector(vector<int> &); // Multiplica el objeto actual por el vector

    /* Analizadoras */
    int get(int, int);                                    // Obtener valor i, j
    list<pair<int, int>> getRowList(int);                 // Retornar fila
    vector<pair<int, int>> getRowVec(int);                // Retornar fila
    list<pair<int, int>> getColList(int);                 // Retornar columna
    vector<pair<int, int>> getColVec(int);                // Retornar columna
    list<pair<int, int>> getDisperseRowList(int);         // Retornar fila con ceros
    vector<pair<int, int>> getDisperseRowVec(int);        // Retornar una fila con ceros
    list<pair<int, int>> getDisperseColList(int);         // Retornar columna con ceros
    vector<pair<int, int>> getDisperseColVec(int);        // Retornar columna con ceros
    void printMatrix(string);                             // Imprime la matriz con el separador
    int getMax();                                         // Retorna el mayor elemento de la matriz
    DisperseMatrix getTranspose();                        // Transpone la matriz
    static DisperseMatrix addMatrixList(list<DisperseMatrix> &); // Suma todas las matrices dispersas de una lista

    /* Sobrecarga operadores */
    DisperseMatrix operator+(DisperseMatrix &); // Suma entre 2 matrices
    DisperseMatrix operator*(DisperseMatrix &); // Multiplicación entre 2 matrices
    bool operator==(DisperseMatrix &);          // Verifica si 2 matrices son iguales
};

#endif
