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
    DisperseMatrix();                                       // Vacío --ready
    DisperseMatrix(int **matrizA, int m, int n);            // Arreglo de 2 dimensiones --revisar
    DisperseMatrix(vector<vector<int>> &vec, int m, int n); // Vector de Vectores  --ready
    DisperseMatrix(const DisperseMatrix &matriz1);          // Punto 3 --ready

    /* Modificadoras */
    vector<vector<int>> rebuild();        // Reconstruir la matriz dispersa a normal con ceros y la retonar --ready
    void assign(int i, int j, int v);     // Modificar el valor en la posición i, j --ready
    void add(DisperseMatrix &matriz2);    // Suma entre matrices --J
    void productVector(vector<int> &vec); // Multiplica el objeto actual por el vector --ready

    /* Analizadoras */
    int get(int i, int j);                                           // Obtener valor i, j --ready
    list<pair<int, int>> getRowList(int fila);                       // Retornar fila --ready
    vector<pair<int, int>> getRowVec(int fila);                      // Retornar fila --ready
    list<pair<int, int>> getColList(int columna);                    // Retornar columna --ready
    vector<pair<int, int>> getColVec(int columna);                   // Retornar columna --ready
    list<pair<int, int>> getDisperseRowLis(int fila);                // Retornar fila con ceros --ready
    vector<pair<int, int>> getDisperseRowVec(int fila);              // Retornar una fila con ceros --ready
    list<pair<int, int>> getDisperseColList(int columna);            // Retornar columna con ceros --ready
    vector<pair<int, int>> getDisperseColVec(int columna);           // --ready
    void printMatrix(string sep);                                    // Imprime la matriz con el separador --ready
    int getMax();                                                    // Retorna el mayor elemento de la matriz --ready
    DisperseMatrix getTranspose();                                   // Transpone la matriz --ready
    DisperseMatrix addMatrixList(list<DisperseMatrix> &listaMatriz); // --J

    /* Sobrecarga operadores */
    DisperseMatrix operator+(DisperseMatrix &matriz); // Suma entre 2 matrices --ready
    DisperseMatrix operator*(DisperseMatrix &matriz); // Multiplicación entre 2 matrices --J
    bool operator==(DisperseMatrix &matriz);          // Verifica si 2 matrices son iguales --ready
};

#endif
