#include "matrizDispersa.h"

/* Constructoras */

DisperseMatrix::DisperseMatrix()
{
    matriz;
    nColumnas = 0;
}

DisperseMatrix::DisperseMatrix(const vector<vector<int>> &vec, int m, int n)
{
    matriz.resize(m);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (vec[i][j] != 0)
            {
                pair<int, int> par;
                par.first = vec[i][j];
                par.second = j;
                matriz[i].push_back(par);
            }
        }
        cout << endl;
    }
    cout << endl;
    nFilas = m;
    nColumnas = n;
}

/* --- Constructoras --- */

/* Modificadoras */

vector<vector<int>> DisperseMatrix::rebuild()
{
    vector<vector<int>> vec;
    list<pair<int, int>>::iterator it;

    for (int i = 0; i < nFilas; i++)
    {
        vec.push_back(vector<int>());
        it = matriz[i].begin();

        for (int j = 0; j < nColumnas; j++)
        {
            int tmp = 0;
            if (it->second == j)
            {
                tmp = it->first;
                it++;
            }
            vec[i].push_back(tmp);
        }
    }
    // for (int i = 0; i < nFilas; i++)
    // {
    //     for (int j = 0; j < nColumnas; j++)
    //     {
    //         cout << vec[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return vec;
}

void DisperseMatrix::add(DisperseMatrix &matriz2)
{
    // Podría ir fila por fila verificando la columna y si esa fila y columna también existe en la matriz2,
    // sumarle eso, sino, sumar 0
    
    for (int fila = 0; fila < nFilas; fila++)
    {
        cout << "Fila " << fila << ": ";
        for (const pair<int, int> &elemento : matriz[fila])
        {
            cout << "(" << elemento.first << ", " << elemento.second << ") ";
        }
        cout << endl;
    }
    cout << endl;
    for (int fila = 0; fila < matriz2.nFilas; fila++)
    {
        cout << "Fila " << fila << ": ";
        for (const pair<int, int> &elemento : matriz2.matriz[fila])
        {
            cout << "(" << elemento.first << ", " << elemento.second << ") ";
        }
        cout << endl;
    }
}

/* --- Modificadoras --- */
