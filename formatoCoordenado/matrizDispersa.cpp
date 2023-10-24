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

void DisperseMatrix::assign(int i, int j, int v)
{
    int cont = 0;
    bool flag = true;

    // Se verifica que la posición no exista.
    while (flag && cont < valores.size())
    {
        if (filas[cont] == i && columnas[cont] == j)
        {
            cout << "if" << endl;
            valores[cont] = v;
            flag = false;
        }
        cont++;
    }

    if (flag)
    {
        valores.push_back(v);
        filas.push_back(i);
        columnas.push_back(j);
    }
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

DisperseMatrix DisperseMatrix::operator+(DisperseMatrix &matrix2)
{
    DisperseMatrix result;

    int size1 = valores.size();
    int size2 = matrix2.valores.size();

    int i = 0, j = 0;

    // Realiza la suma mientras haya elementos en ambas matrices
    while (i < size1 && j < size2)
    {
        if (filas[i] == matrix2.filas[j] && columnas[i] == matrix2.columnas[j])
        {
            result.valores.push_back(valores[i] + matrix2.valores[j]);
            result.filas.push_back(filas[i]);
            result.columnas.push_back(columnas[i]);
            i++;
            j++;
        }
        else if (filas[i] < matrix2.filas[j] || (filas[i] == matrix2.filas[j] && columnas[i] < matrix2.columnas[j]))
        {
            result.valores.push_back(valores[i]);
            result.filas.push_back(filas[i]);
            result.columnas.push_back(columnas[i]);
            i++;
        }
        else
        {
            result.valores.push_back(matrix2.valores[j]);
            result.filas.push_back(matrix2.filas[j]);
            result.columnas.push_back(matrix2.columnas[j]);
            j++;
        }
    }

    // Agrega los elementos restantes de la primera matriz, si los hay
    while (i < size1)
    {
        result.valores.push_back(valores[i]);
        result.filas.push_back(filas[i]);
        result.columnas.push_back(columnas[i]);
        i++;
    }

    // Agrega los elementos restantes de la segunda matriz, si los hay
    while (j < size2)
    {
        result.valores.push_back(matrix2.valores[j]);
        result.filas.push_back(matrix2.filas[j]);
        result.columnas.push_back(matrix2.columnas[j]);
        j++;
    }

    return result;
}

DisperseMatrix DisperseMatrix::operator*(DisperseMatrix &matrix2)
{
    DisperseMatrix result;

    int size1 = valores.size();
    int size2 = matrix2.valores.size();

    int numRows1 = 0;
    int numCols1 = 0;
    int numCols2 = 0;

    // Determinar el número de filas y columnas de la matriz resultante
    for (int i = 0; i < size1; i++)
    {
        if (filas[i] > numRows1)
        {
            numRows1 = filas[i];
        }
        if (columnas[i] > numCols1)
        {
            numCols1 = columnas[i];
        }
    }

    for (int i = 0; i < size2; i++)
    {
        if (matrix2.filas[i] > numRows1)
        {
            numRows1 = matrix2.filas[i];
        }
        if (matrix2.columnas[i] > numCols2)
        {
            numCols2 = matrix2.columnas[i];
        }
    }

    // Realizar la multiplicación
    for (int i = 0; i <= numRows1; i++)
    {
        for (int j = 0; j <= numCols2; j++)
        {
            int product = 0;
            for (int k = 0; k < size1; k++)
            {
                for (int l = 0; l < size2; l++)
                {
                    if (filas[k] == i && matrix2.columnas[l] == j && columnas[k] == matrix2.filas[l])
                    {
                        product += (valores[k] * matrix2.valores[l]);
                    }
                }
            }
            if (product != 0)
            {
                result.valores.push_back(product);
                result.filas.push_back(i);
                result.columnas.push_back(j);
            }
        }
    }

    return result;
}

bool DisperseMatrix::operator==(DisperseMatrix &matrix2)
{
    bool ans = true;
    if (valores.size() != matrix2.valores.size())
    {
        ans = false; // Tienen diferentes números de elementos
    }

    for (int i = 0; i < valores.size(); i++)
    {
        if (valores[i] != matrix2.valores[i] ||
            filas[i] != matrix2.filas[i] ||
            columnas[i] != matrix2.columnas[i])
        {
            ans = false; // Elementos diferentes en alguna posición
        }
    }

    return ans; // Todas las posiciones coinciden
}

/* -- Sobrecarga operadores -- */