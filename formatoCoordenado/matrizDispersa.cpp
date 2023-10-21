#include "matrizDispersa.h"

using namespace std;

/* Constructoras */

DisperseMatrix::DisperseMatrix()
{
    valores;
    filas;
    columnas;
    nFilas = 0, nColumnas = 0;
}

DisperseMatrix::DisperseMatrix(int **&matriz, int fil, int col) // Arreglo de 2 dimensiones
{
    vector<int> valores;
    vector<int> filas;
    vector<int> columnas;
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

    // // Debugging Zone
    // cout << "Valores" << endl;
    // for (int h = 0; h < valores.size(); h++)
    // {
    //     cout << valores[h] << " ";
    // }
    // cout << endl;

    // cout << "Filas" << endl;
    // for (int h = 0; h < filas.size(); h++)
    // {
    //     cout << filas[h] << " ";
    // }
    // cout << endl;

    // cout << "Columnas" << endl;
    // for (int h = 0; h < columnas.size(); h++)
    // {
    //     cout << columnas[h] << " ";
    // }
    // cout << endl;
}

DisperseMatrix::DisperseMatrix(const vector<vector<int>> &matriz, int m, int n) // constructor funcional
{                                                                               // vector de vectores
    valores;
    filas;
    columnas;
    nFilas = m;
    nColumnas = n;
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

DisperseMatrix::DisperseMatrix(DisperseMatrix &matriz)
{
    vector<int> valores = matriz.valores;
    vector<int> filas = matriz.filas;
    vector<int> columnas = matriz.columnas;
}

/* -- Constructoras -- */

/* Modificadoras */

vector<vector<int>> DisperseMatrix::rebuild()
{
    vector<vector<int>> result(nFilas, vector<int>(nColumnas, 0)); // crea un matriz de 0 del tamaño original
    for (int i = 0; i < valores.size(); i++)
    {
        int valor = valores[i];
        int fila = filas[i];
        int columna = columnas[i];
        result[fila][columna] = valor; // agrega los valores en las posicion original
    }

    return result;
}

/* -- Modificadoras -- */

/* Analizadoras */

int DisperseMatrix::get(int i, int j)
{
    bool flag = false;
    int e, ans;
    for (e = 0; e < valores.size() && !flag; e++)
    { // busca si las cordenadas tienen un valor diferente de 0
        if (filas[e] == i)
        {
            if (columnas[e] == j)
            {
                flag = true;
            }
        }
    }
    if (flag == false)
    { // si no es un valor diferente de 0 retorna 0 y si la posicion no existe imprime posicion invalida
        if (i < nFilas && j < nColumnas)
        {
            ans = 0;
        }
        else
        {
            cout << "Posicion invalida" << endl;
        }
    }
    else
    {
        ans = valores[e - 1]; // imprime el valor correspondiente a la posicion encontrada
    }
    return ans;
}
vector<int> DisperseMatrix::getRowVec(int fila)
{
    vector<int> result;
    if (fila >= nFilas)
    {
        cout << "fila invalido" << endl;
    }
    int i;
    for (i = 0; i < valores.size(); i++) // agrega en la posicion respectiva el valor diferente a 0
    {
        if (fila == filas[i])
        {
            result.push_back(valores[i]);
        }
    }
    return result;
}
vector<int> DisperseMatrix::getColVec(int columna)
{
    vector<int> result;
    int i;
    if (columna >= nColumnas)
    {
        cout << "columna invalido" << endl;
    }
    for (i = 0; i < valores.size(); i++) // agrega en la posicion respectiva el valor diferente a 0
    {
        if (columnas[i] == columna)
        {
            result.push_back(valores[i]);
        }
    }
    return result;
}

/* -- Analizadoras -- */

/* Sobrecarga operadores */

DisperseMatrix DisperseMatrix::operator+(DisperseMatrix &matriz)
{
    DisperseMatrix ans;
    int m1FilTam = -2147483647, m1ColTam = -2147483647, m2FilTam = -2147483647, m2ColTam = -2147483647;

    // Se verifica el tamaño de la matriz para saber si se puede sumar
    for (int i = 0; i < filas.size(); i++)
    {
        if (filas[i] > m1FilTam)
            m1FilTam = filas[i];

        if (columnas[i] > m1ColTam)
            m1ColTam = columnas[i];
    }

    for (int i = 0; i < matriz.filas.size(); i++)
    {
        if (matriz.filas[i] > m2FilTam)
            m2FilTam = matriz.filas[i];

        if (matriz.columnas[i] > m2ColTam)
            m2ColTam = matriz.columnas[i];
    }

    if (m1FilTam == m2FilTam && m1ColTam == m2ColTam)
    {
        int temp;
        for (int i = 0; i < valores.size(); i++)
        {
            temp = valores[i] + matriz.valores[i];
            ans.valores.push_back(temp);
        }
        ans.filas = filas;
        ans.columnas = columnas;
    }
    else
    {
        cout << "La matrices son de diferente tamanio. No se pueden sumar." << endl;
    }

    return ans;
}

/* -- Sobrecarga operadores -- */