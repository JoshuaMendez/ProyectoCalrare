#include "matrizDispersa.h"

using namespace std;

DisperseMatrix::DisperseMatrix()
{
    vector<int> valores;
    vector<int> filas;
    vector<int> columnas;
};
void MatrizDispersa() {}

void DisperseMatrix::MatrizDispersa(int **&matriz, int fil, int col) // Arreglo de 2 dimensiones
{
    for (int i = 0; i < fil; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (matriz[i][j] != 0)
            {
                valores.push_back(matriz[i][j]);
                filas.push_back(i);
                columnas.push_back(j);
            }
        }
    }

    // Debugging Zone
    cout << "Valores" << endl;
    for (int h = 0; h < valores.size(); h++)
    {
        cout << valores[h] << " ";
    }
    cout << endl;

    cout << "Filas" << endl;
    for (int h = 0; h < filas.size(); h++)
    {
        cout << filas[h] << " ";
    }
    cout << endl;

    cout << "Columnas" << endl;
    for (int h = 0; h < columnas.size(); h++)
    {
        cout << columnas[h] << " ";
    }
    cout << endl;

}

void DisperseMatrix::MatrizDispersa(vector<vector<int>> &matriz)
{ // vector de vectores
    int fila, columna;
    for (fila = 0; fila < matriz.size(); fila++)
    {
        for (columna = 0; columna < matriz[fila].size(); columna++)
        {
            if (matriz[fila][columna] != 0)
            {
                valores.push_back(matriz[fila][columna]);
                filas.push_back(fila);
                columnas.push_back(columna);
            }
        }
    }
}
