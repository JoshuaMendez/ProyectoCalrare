/*
 * Autores: Sebastian Izquierdo S. y Joshua Mendez
 * Archivo CPP libreria TAD matriz Dispersa
 * Representación Estructuras Matriz Dispersa de la forma de listas enlazadas
 */
#include "matrizDispersa.h"

bool comparador(pair<int, int> &a, pair<int, int> &b)
{
    return a.second < b.second;
}

/* Constructoras */

DisperseMatrix::DisperseMatrix() // Inicializa una matriz dispersa vacía con tamaño 0 x 0
{
    matriz = {};
    nFilas = 0;
    nColumnas = 0;
}
// Complejidad O(1)
DisperseMatrix::DisperseMatrix(int **matrizA, int m, int n) // Recibe un arreglo de dos dimensiones y lo vuelve una matriz dispersa
{
    nFilas = m;
    nColumnas = n;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrizA[i][j] != 0)
            {
                pair<int, int> par;
                par.first = matrizA[i][j];
                par.second = j;
                matriz[i].push_back(par);
            }
        }
    }
}
// Siendo m = el numero de filas y n = el numero de columnas
// Siendo lo mas costoso n*m. Complejidad O(n*m)
DisperseMatrix::DisperseMatrix(vector<vector<int>> &vec) // Recibe un vector de vectores y lo vuelve una matriz dispersa
{
    matriz.resize(vec.size());
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec[0].size(); j++)
        {
            if (vec[i][j] != 0)
            {
                pair<int, int> par;
                par.first = vec[i][j];
                par.second = j;
                matriz[i].push_back(par);
            }
        }
    }
    nFilas = vec.size();
    nColumnas = vec[0].size();
}
// Siendo n = el numero de filas y m = el numero de columnas
// Siendo lo mas costoso n*m. Complejidad O(n*m)

DisperseMatrix::DisperseMatrix(const DisperseMatrix &matriz1) // Copia una matriz dispersa
{
    matriz = matriz1.matriz;
    nFilas = matriz1.nFilas;
    nColumnas = matriz1.nColumnas;
}
// Siendo n = el tamaño del vector de listas
// Complejidad O(n)

/* Modificadoras */

vector<vector<int>> DisperseMatrix::rebuild() // Convierte una matriz dispersa en un vector de vectores
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
    return vec;
}
// Siendo n el tamaño del vector, y m el tamaño de la lista
// Siendo lo más costoso n*m. Complejidad O(n*m)
void DisperseMatrix::assign(int i, int j, int v) // Ingresa un valor en la posicion i, j dada
{
    if (i <= nFilas && j <= nColumnas)
    {
        bool flag = false;
        for (list<pair<int, int>>::iterator it = matriz[i].begin(); it != matriz[i].end() && !flag; ++it)
        {
            if (it->second == j)
            {
                it->first = v;
                flag = true;
            }
        }
        if (flag == false)
        {
            pair<int, int> par;
            par.first = v;
            par.second = j;
            matriz[i].push_back(par);
        }
    }
}
// Siendo n el tamaño de la lista
// Complejidad O(n)

void DisperseMatrix::add(DisperseMatrix &sum) // Suma dos matrices dispersas
{
    DisperseMatrix result;
    result.nFilas = max(nFilas, sum.nFilas);
    result.nColumnas = max(nColumnas, sum.nColumnas);
    result.matriz.resize(result.nFilas);
    int i = 0;
    pair<int, int> par;
    int valor;

    while (i < result.nFilas)
    {
        if (i < nFilas)
        {
            for (list<pair<int, int>>::iterator it = matriz[i].begin(); it != matriz[i].end(); it++)
            {
                bool sumado = false;
                if (i < sum.nFilas)
                {
                    for (list<pair<int, int>>::iterator it1 = sum.matriz[i].begin(); it1 != sum.matriz[i].end(); it1++)
                    {
                        if (it->second == it1->second)
                        {
                            valor = it->first + it1->first;
                            par.first = valor;
                            par.second = it->second;
                            result.matriz[i].push_back(par);
                            sumado = true;
                        }
                    }
                }
                if (!sumado)
                {
                    par.first = it->first;
                    par.second = it->second;
                    result.matriz[i].push_back(par);
                }
            }
        }
        if (i < sum.nFilas)
        {
            pair<int, int> par;
            for (list<pair<int, int>>::iterator it = sum.matriz[i].begin(); it != sum.matriz[i].end(); it++)
            {
                bool found = false;
                list<pair<int, int>>::iterator it1 = result.matriz[i].begin();

                while (it1 != result.matriz[i].end() && !found)
                {
                    if (it->second == it1->second)
                    {
                        found = true;
                    }
                    else
                    {
                        ++it1;
                    }
                }

                if (!found)
                {
                    par.first = it->first;
                    par.second = it->second;
                    result.matriz[i].push_front(par);
                }
            }
            result.matriz[i].sort(comparador);
        }

        i++;
    }
    *this = result;
}
// Siendo n el tamaño de las filas de la matriz 1, m el tamaño de la lista de la matriz 1, x el tamaño de la lista de la matriz 2
// Siendo lo más costoso n*m*x. Complejidad O(n*m*x)

void DisperseMatrix::productVector(vector<int> &vec) // Multiplica un vector por una matriz dispersa
{
    for (int i = 0; i < nColumnas; i++)
    {
        for (int j = 0; j < nFilas; j++)
        {
            list<pair<int, int>>::iterator it = matriz[j].begin();
            while (it != matriz[j].end())
            {
                if (it->second == i)
                {
                    it->first *= vec[i];
                }
                it++;
            }
        }
    }
}
// Siendo n el tamaño de las columnas, m el tamaño de las filas y x el tamaño de la lista
// Siendo lo más costoso n*m*x. Complejidad O(n*m*x)

/* Analizadoras */

int DisperseMatrix::get(int i, int j) // Retorna el valor de la posicion i, j
{
    int ans = 0;
    bool flag = true;
    list<pair<int, int>>::iterator it;

    for (it = matriz[i].begin(); it != matriz[i].end() && flag; it++)
    {
        if (it->second == j)
        {
            ans = it->first;
            flag = false;
        }
    }
    return ans;
}
// Siendo n el tamaño de la lista
// Complejidad O(n)

list<pair<int, int>> DisperseMatrix::getRowList(int fila) // Retorna una lista de enteros con los valores de la fila solicitada
{
    return matriz[fila]; // retorna la lista con valor y columna
}

vector<pair<int, int>> DisperseMatrix::getRowVec(int fila) // Retorna un vector de pares de enteros los valores y la columna correspondiente
{
    list<pair<int, int>>::iterator it;
    vector<pair<int, int>> ans;
    for (it = matriz[fila].begin(); it != matriz[fila].end(); it++)
    {
        pair<int, int> par;
        par = make_pair(it->first, it->second);
        ans.push_back(par);
    }
    return ans;
}
// Siendo n el tamaño de la lista
// Complejidad O(n)

list<pair<int, int>> DisperseMatrix::getColList(int columna) // Retorna una lista de pares de enteros con los valores y la fila correspondiente
{
    list<pair<int, int>> result;
    for (int i = 0; i < nFilas; i++)
    {
        for (list<pair<int, int>>::iterator it = matriz[i].begin(); it != matriz[i].end(); it++)
        {
            if (it->second == columna)
            {
                pair<int, int> par;
                par.first = it->first;
                par.second = i;
                result.push_back(par); // guarda valor y fila
            }
        }
    }
    return result;
}
// Siendo n el tamaño de la lista
// Complejidad O(n)

vector<pair<int, int>> DisperseMatrix::getColVec(int columna) // Retorna un vector de pares de enteros con los valores y la fila correspondiente
{
    vector<pair<int, int>> result;
    for (int i = 0; i < nFilas; i++)
    {
        for (list<pair<int, int>>::iterator it = matriz[i].begin(); it != matriz[i].end(); it++)
        {
            if (it->second == columna)
            {
                pair<int, int> par;
                par.first = it->first;
                par.second = i;
                result.push_back(par); // guarda valor y fila
            }
        }
    }
    return result;
}
// Siendo n el tamaño de la lista
// Complejidad O(n)

list<pair<int, int>> DisperseMatrix::getDisperseRowList(int fila) // Retorna una lista con los valores de la fila completando con 0 con su posición correspondiente en la columna
{
    list<pair<int, int>> result;
    list<pair<int, int>>::iterator it = matriz[fila].begin();
    int i = 0; // contador de columnas
    pair<int, int> par;
    while (it != matriz[fila].end() || i < nColumnas)
    {
        if (it->second == i)
        {
            par.first = it->first;
            par.second = i;
            result.push_back(par);
            it++;
        }
        else
        {
            par.first = 0;
            par.second = i;
            result.push_back(par);
        }
        i++;
    }

    return result;
}
// Siendo n el valor maximo entre nColumnas y el tamaño de la lista
// Complejidad O(n)
vector<pair<int, int>> DisperseMatrix::getDisperseRowVec(int fila) // Retorna un vector de pares de enteros con los valores y la columna correspondiente con sus 0
{
    vector<pair<int, int>> result;
    list<pair<int, int>>::iterator it = matriz[fila].begin();
    int i = 0; // contador de columnas
    pair<int, int> par;
    while (it != matriz[fila].end() || i < nColumnas)
    {
        if (it->second == i)
        {
            par.first = it->first;
            par.second = i;
            result.push_back(par);
            it++;
        }
        else
        {
            par.first = 0;
            par.second = i;
            result.push_back(par);
        }
        i++;
    }

    return result;
}
// Siendo n el valor maximo entre nColumnas y el tamaño de la lista
// Complejidad O(n)
list<pair<int, int>> DisperseMatrix::getDisperseColList(int columna) // Retorna una lista de pares de enteros con los valores de columna y la fila correspondiente con sus 0
{
    list<pair<int, int>> result;
    for (int i = 0; i < nFilas; i++)
    {
        pair<int, int> par;
        bool flag = false;
        list<pair<int, int>>::iterator it = matriz[i].begin();
        while (it != matriz[i].end())
        {
            if (it->second == columna)
            {
                par.first = it->first;
                par.second = i;
                result.push_back(par);
                flag = true;
            }
            it++;
        }
        if (!flag)
        {
            par.first = 0;
            par.second = i;
            result.push_back(par);
        }
    }
    return result;
}
// Siendo n el valor maximo entre nFilas y el tamaño de la lista
// Complejidad O(n)
vector<pair<int, int>> DisperseMatrix::getDisperseColVec(int columna) // Retorna un vector de pares de enteros con los valores de columna y la fila correspondiente con sus 0
{
    vector<pair<int, int>> result;
    for (int i = 0; i < nFilas; i++)
    {
        pair<int, int> par;
        bool flag = false;
        list<pair<int, int>>::iterator it = matriz[i].begin();
        while (it != matriz[i].end())
        {
            if (it->second == columna)
            {
                par.first = it->first;
                par.second = i;
                result.push_back(par);
                flag = true;
            }
            it++;
        }
        if (!flag)
        {
            par.first = 0;
            par.second = i;
            result.push_back(par);
        }
    }
    return result; // retorna el valor y la fila
}
// Siendo n el valor maximo entre nFilas y el tamaño de la lista
// Complejidad O(n)
void DisperseMatrix::printMatrix(string sep) // Imprime una matriz dispersa separa por el string ingresado
{
    for (int i = 0; i < nFilas; i++)
    {
        int contador = 0;
        list<pair<int, int>>::iterator it = matriz[i].begin();
        while (contador < nColumnas)
        {
            if (it->second == contador)
            {
                cout << it->first;
                it++;
            }
            else
            {
                cout << 0;
            }
            if (contador < nColumnas - 1)
            {
                cout << sep;
            }
            contador++;
        }
        if (i < nFilas)
        {
            cout << endl;
        }
    }
}
// Siendo n el numero de filas y m el numero de columnas
// Siendo lo mas costoso n*m Complejidad O(n*m)
int DisperseMatrix::getMax() // Retorna el valor maximo de la matriz dispersa
{
    int maxValue = -2147483647;
    list<pair<int, int>>::iterator it;
    for (int i = 0; i < nFilas; i++)
    {
        for (it = matriz[i].begin(); it != matriz[i].end(); it++)
        {
            if (it->first > maxValue)
            {
                maxValue = it->first;
            }
        }
    }
    return maxValue;
}
// Siendo n el tamaño del vector de filas, y m el tamaño de las listas
// Complejidad O(n*m)

DisperseMatrix DisperseMatrix::getTranspose() // Retorna una matriz dispersa transpuesta
{
    DisperseMatrix result;
    result.nFilas = nColumnas;
    result.nColumnas = nFilas;
    result.matriz.resize(nColumnas);
    int i = 0;
    while (i < nFilas)
    {
        for (list<pair<int, int>>::iterator it = matriz[i].begin(); it != matriz[i].end(); it++)
        {
            int fila, columna, valor;
            fila = it->second;
            columna = i;
            valor = it->first;
            pair<int, int> par;
            par.first = valor;
            par.second = columna;
            result.matriz[fila].push_back(par);
        }
        i++;
    }
    return result;
}
// Siendo n el tamaño del vector de filas, y m el tamaño de la listas
// Complejidad O(n*m)
DisperseMatrix DisperseMatrix::addMatrixList(list<DisperseMatrix> &listaMatriz) // Retorna una matriz dispersa la cual es la suma de toda las matrices dispersas de la lista
{
    DisperseMatrix ans;
    list<DisperseMatrix>::iterator it;
    for (it = listaMatriz.begin(); it != listaMatriz.end(); it++)
    {
        ans = ans + *it;
    }

    return ans;
}
// Siendo n el tamaño de la lista y la sobrecarga + que tiene costo de O(n*m*x)
// Siendo lo mas costoso n*n*m*x Complejidad O(n**2*m*x)

/* Sobrecarga operadores */

DisperseMatrix DisperseMatrix::operator+(DisperseMatrix &sum) // Suma dos matrices dispersas
{
    DisperseMatrix result;
    result.nFilas = max(nFilas, sum.nFilas);
    result.nColumnas = max(nColumnas, sum.nColumnas);
    result.matriz.resize(result.nFilas);
    int i = 0;
    pair<int, int> par;
    int valor;

    while (i < result.nFilas)
    {
        if (i < nFilas)
        {
            for (list<pair<int, int>>::iterator it = matriz[i].begin(); it != matriz[i].end(); it++)
            {
                bool sumado = false;
                if (i < sum.nFilas)
                {
                    for (list<pair<int, int>>::iterator it1 = sum.matriz[i].begin(); it1 != sum.matriz[i].end(); it1++)
                    {
                        if (it->second == it1->second)
                        {
                            valor = it->first + it1->first;
                            par.first = valor;
                            par.second = it->second;
                            result.matriz[i].push_back(par);
                            sumado = true;
                        }
                    }
                }
                if (!sumado)
                {
                    par.first = it->first;
                    par.second = it->second;
                    result.matriz[i].push_back(par);
                }
            }
        }
        if (i < sum.nFilas)
        {
            pair<int, int> par;
            for (list<pair<int, int>>::iterator it = sum.matriz[i].begin(); it != sum.matriz[i].end(); it++)
            {
                bool found = false;
                list<pair<int, int>>::iterator it1 = result.matriz[i].begin();

                while (it1 != result.matriz[i].end() && !found)
                {
                    if (it->second == it1->second)
                    {
                        found = true;
                    }
                    else
                    {
                        ++it1;
                    }
                }

                if (!found)
                {
                    par.first = it->first;
                    par.second = it->second;
                    result.matriz[i].push_front(par);
                }
            }
            result.matriz[i].sort(comparador);
        }

        i++;
    }
    return result;
}
// Siendo n el tamaño de las filas de la matriz 1, m el tamaño de la lista de la matriz 1, x el tamaño de la lista de la matriz 2
// Siendo lo más costoso n*m*x. Complejidad O(n*m*x)
DisperseMatrix DisperseMatrix::operator*(DisperseMatrix &matrix2) // Multiplica dos matrices dispersas
{
    DisperseMatrix result;
    int n, product;
    pair<int, int> valCol;
    if (nColumnas >= matrix2.nFilas)
    {
        n = nColumnas;
    }
    else
    {
        n = matrix2.nFilas;
    }
    result.nFilas = nFilas;
    result.nColumnas = matrix2.nColumnas;
    result.matriz.resize(result.nFilas);

    for (int fila1 = 0; fila1 < nFilas; fila1++)
    {
        for (int col2 = 0; col2 < matrix2.nColumnas; col2++)
        {
            product = 0;
            for (int i = 0; i < n; i++)
            {
                product = (get(fila1, i) + matrix2.get(i, col2));
                if (product != 0)
                {
                    valCol = make_pair(product, col2);
                    result.matriz[fila1].push_back(valCol);
                }
            }
            cout << product << endl;
        }
    }
    return result;
}
// n = es el máximo entre nColumnas y matrix2.nFilas, m = nFilas, v = matriz2.nColumnas y get() que vale O(n)
// Siendo la operacion mas costosa m*v*n*n , Complejidad O(m*v*n**2)
bool DisperseMatrix::operator==(DisperseMatrix &matriz1) // Compara si dos matrices dispersas son iguales
{
    bool ans = false;
    if (nFilas == matriz1.nFilas && nColumnas == matriz1.nColumnas)
    {
        bool flag = true;
        for (int i = 0; i < nFilas && flag; i++)
        {
            list<pair<int, int>>::iterator it = matriz[i].begin();
            list<pair<int, int>>::iterator it1 = matriz1.matriz[i].begin();
            while (it != matriz[i].end() || it1 != matriz1.matriz[i].end())
            {
                if (it != matriz[i].end() && it1 != matriz1.matriz[i].end())
                {
                    ans = it->first == it1->first && it->second == it1->second;
                    it++;
                    it1++;
                }
                else
                {
                    flag = false;
                    if (it != matriz[i].end())
                    {
                        it++;
                        ans = false;
                    }
                    else
                    {
                        it1++;
                        ans = false;
                    }
                }
            }
        }
    }
    return ans;
}
// n = número de filas y m = al tamaño máximo de la lista en la matriz 1 o la lista de la matriz 2
// Siendo lo más costoso n*m. Complejidad O(n*m)
