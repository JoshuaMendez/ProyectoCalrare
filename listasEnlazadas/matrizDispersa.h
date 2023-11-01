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
#include <list>
#include <string>

using namespace std;

/************************
 * ESTRUCTURAS DE DATOS *
 ************************/

class DisperseMatrix
{
    // private:
public:
    vector<list<pair<int, int>>> matriz;
    int nFilas; // Equivalente a tamaño del vector
    int nColumnas;
    // public:
    /************************
     * OPERACIONES DEL TAD *
     ************************/
    /* Constructoras */
    DisperseMatrix();                                             // Vacío --ready
    DisperseMatrix(int **&matrizA, int m, int n);                  // Arreglo de 2 dimensiones --ready
    DisperseMatrix(const vector<vector<int>> &vec, int m, int n); // Vector de Vectores  --ready
    DisperseMatrix(DisperseMatrix &matriz1);                       // Punto 3 --ready

    /* Modificadoras */
    vector<vector<int>> rebuild();        // Reconstruir la matriz dispersa a normal con ceros y la retonar --ready
    void assign(int i, int j, int v);     // Modificar el valor en la posición i, j --S
    void add(DisperseMatrix &matriz2);    // Suma entre matrices --J
    void productVector(vector<int> &vec); // Multiplica el objeto actual por el vector --S

    /* Analizadoras */
    int get(int i, int j);                                      // Obtener valor i, j --J
    list<int> getRowLis(int fila);                              // Retornar fila --S
    vector<int> getRowVec(int fila);                            // Retornar fila --J
    list<int> getColLis(int columna);                           // Retornar columna --S
    vector<int> getColVec(int columna);                         //  Retornar columna --J
    list<int> getDisperseRowLis(int fila);                      // Retornar fila con ceros --S
    vector<int> getDisperseRowVec(int fila);                    // Retornar una fila con ceros --J
    list<int> getDisperseColLis(int columna);                   // Retornar columna con ceros --S
    vector<int> getDisperseColVec(int columna);                 // --J
    void printMatrix(string sep);                               // Imprime la matriz con el separador --S
    int getMax();                                               // Retorna el mayor elemento de la matriz --J
    DisperseMatrix getTranspose();                              // Transpone la matriz --S
    DisperseMatrix addMatrixList(list<DisperseMatrix> &matriz); // --J

    /* Sobrecarga operadores */
    DisperseMatrix operator+(DisperseMatrix &matriz); // Suma entre 2 matrices --S
    DisperseMatrix operator*(DisperseMatrix &matriz); // Multiplicación entre 2 matrices --J
    bool operator==(DisperseMatrix &matriz);          // Verifica si 2 matrices son iguales --S
};

#endif
