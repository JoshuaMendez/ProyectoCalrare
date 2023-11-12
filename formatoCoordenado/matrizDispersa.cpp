/*
 * Autores: Sebastian Izquierdo S. y Joshua Mendez
 * Archivo CPP libreria TAD matriz Dispersa
 * Representación Estructuras Matriz Dispersa de la forma de coordenadas con vectores
 */
#include "matrizDispersa.h"

using namespace std;

/* Constructoras */

DisperseMatrix::DisperseMatrix() // Inicializa una matriz dispersa vacía con tamaño 0 x 0
{
    valores;
    filas;
    columnas;
    nFilas = 0, nColumnas = 0;
}
// Complejidad O(1)
DisperseMatrix::DisperseMatrix(int **&matriz, int fil, int col) // Recibe un arreglo de dos dimensiones y lo vuelve una matriz dispersa
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
}
// Siendo n = el numero de filas y m = el numero de columnas
// Siendo lo mas costoso n*m. Complejidad O(n*m)
DisperseMatrix::DisperseMatrix( vector<vector<int>> &matriz) // Recibe un vector de vectores y lo vuelve una matriz dispersa
{
    valores;
    filas;
    columnas;
    nFilas = matriz.size();
    nColumnas = matriz[0].size();
    int fila, columna;
    for (fila = 0; fila < nFilas; fila++)
    {
        for (columna = 0; columna < nColumnas; columna++)
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
// Siendo n = el numero de filas y m = el numero de columnas
// Siendo lo mas costoso n*m. Complejidad O(n*m)
DisperseMatrix::DisperseMatrix(const DisperseMatrix &matriz) // Copia una matriz dispersa
{
    valores = matriz.valores;
    filas = matriz.filas;
    columnas = matriz.columnas;
}
// Siendo n = el tamaño del vector
// Complejidad O(n)

/* Modificadoras */

vector<vector<int>> DisperseMatrix::rebuild() // Convierte una matriz dispersa en un vector de vectores
{
    vector<vector<int>> result(nFilas, vector<int>(nColumnas, 0)); // crea un matriz de 0 del tamaño original
    for (int i = 0; i < valores.size(); i++)
    {
        int valor = valores[i];
        int fila = filas[i];
        int columna = columnas[i];
        result[fila][columna] = valor; // agrega los valores en las posición original
    }

    return result;
}
// Siendo n el tamaño del vector
// Complejidad O(n)
void DisperseMatrix::assign(int i, int j, int v) // Ingresa un valor en la posicion i, j dada
{
    int cont = 0;
    bool flag = true;
    while (flag && cont < valores.size()) // Se verifica que la posición no exista.
    {
        if (filas[cont] == i && columnas[cont] == j)
        {
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
// Siendo n el tamaño del vector
// Complejidad O(n)
void DisperseMatrix::add(DisperseMatrix &matriz) // Suma dos matrices dispersas
{
    cout << valores.size() << endl;
    for (int i = 0; i < matriz.valores.size(); i++)
    {
        bool flag = false;
        for (int j = 0; j < valores.size() && !flag; j++)
        {
            if (matriz.filas[i] == filas[j] && matriz.columnas[i] == columnas[j])
            {
                valores[j] += matriz.valores[i];
                flag = true;
            }
        }
        if (flag == false)
        {
            valores.push_back(matriz.valores[i]);
            filas.push_back(matriz.filas[i]);
            columnas.push_back(matriz.columnas[i]);
        }
    }
}
// Siendo n el tamaño del vector de la matriz 1 y m el tamaño del vector de la matriz 2
// Siendo lo mas costoso n*m ,Complejidad O(n*m)
void DisperseMatrix::productVector(vector<int> &vec) // Multiplica un vector por una matriz dispersa
{
    // Cuando se multiplica un vector por una matriz cada valor del vector multiplica una de las columnas de la matriz
    // Puedes asumir que siempre los tamaños serán consistentes
    int i = 0;
    while (i < valores.size())
    {
        valores[i] *= vec[columnas[i]];
        i++;
    }
}
// Siendo n el tamaño del vector
// Complejidad O(n)

/* Analizadoras */

int DisperseMatrix::get(int i, int j) // Retorna el valor de la posicion i, j
{
    bool flag = false;
    int e, ans = 0;
    for (e = 0; e < valores.size() && !flag; e++)
    { // busca si las cordenadas tienen un valor diferente de 0
        if (filas[e] == i)
        {
            if (columnas[e] == j)
            {
                flag = true;
                ans = valores[e];
            }
        }
    }
    return ans;
}
// Siendo n el tamaño del vector
// Complejidad O(n)

list<pair<int, int>> DisperseMatrix::getRowList(int fila) // Retorna una lista de enteros con los valores de la fila solicitada
{
    list<pair<int, int>> result;
    int i;
    for (i = 0; i < valores.size(); i++) // agrega en la posicion respectiva el valor diferente a 0
    {
        if (fila == filas[i])
        {
            pair<int, int> par;
            par = make_pair(valores[i], i);
            result.push_back(par);
        }
    }
    return result;
}
// Siendo n el tamaño del vector
// Complejidad O(n)
vector<pair<int, int>> DisperseMatrix::getRowVec(int fila) // Retorna un vector de pares de enteros con los valores y la columna correspondiente
{
    vector<pair<int, int>> result;
    pair<int, int> par;
    int i;
    for (i = 0; i < valores.size(); i++) // agrega en la posicion respectiva el valor diferente a 0
    {
        if (fila == filas[i])
        {
            par.first = valores[i];
            par.second = columnas[i];
            result.push_back(par);
        }
    }
    return result;
}
// Siendo n el tamaño del vector
// Complejidad O(n)

list<pair<int, int>> DisperseMatrix::getColList(int columna) // Retorna una lista de pares de enteros con los valores y la fila correspondiente
{
    list<pair<int, int>> result;
    int i;
    for (i = 0; i < valores.size(); i++) // agrega en la posicion respectiva el valor diferente a 0
    {
        if (columnas[i] == columna)
        {
            pair<int, int> par;
            par = make_pair(valores[i], i);
            result.push_back(par);
        }
    }
    return result;
}
// Siendo n el tamaño del vector
// Complejidad O(n)
vector<pair<int, int>> DisperseMatrix::getColVec(int columna) // Retorna un vector de pares de enteros con los valores y la fila correspondiente
{
    vector<pair<int, int>> result;
    pair<int, int> par;
    int i;
    for (i = 0; i < valores.size(); i++) // agrega en la posicion respectiva el valor diferente a 0
    {
        if (columnas[i] == columna)
        {
            par.first = valores[i];
            par.second = filas[i];
            result.push_back(par);
        }
    }
    return result;
}
// Siendo n el tamaño del vector
// Complejidad O(n)
list<pair<int, int>> DisperseMatrix::getDisperseRowList(int fila) // Retorna una lista con los valores de la fila completando con 0 con su posición correspondiente en la columna
{
    list<pair<int, int>> result;
    pair<int, int> par;
    for (int i = 0; i < nColumnas; i++)
    {
        par = make_pair(0, i);
        result.push_back(par);
    }

    list<pair<int, int>>::iterator it = result.begin();
    int i = 0;
    while (i < valores.size() || it != result.end())
    {
        if (i == valores.size())
        {
            i = 0;
            it++;
        }
        if (filas[i] == fila && columnas[i] == it->second)
        {
            it->first = valores[i];
            it++;
        }
        i++;
    }

    return result;
}
// Siendo n el valor maximo entre nColumnas y el tamaño del vector de valores
// Complejidad O(n)
vector<pair<int, int>> DisperseMatrix::getDisperseRowVec(int fila) // Retorna un vector de pares de enteros con los valores y la columna correspondiente con sus 0
{
    vector<pair<int, int>> result;
    pair<int, int> par;
    for (int i = 0; i < nColumnas; i++)
    {
        par.first = 0;
        par.second = i;
        result.push_back(par);
    }

    for (int i = 0; i < valores.size(); i++) // agrega en la posicion respectiva el valor diferente a 0
    {
        if (fila == filas[i])
        {

            result[columnas[i]].first = valores[i];
        }
    }
    return result;
}
// Siendo n el valor maximo entre nColumnas y el tamaño del vector de valores
// Complejidad O(n)
list<pair<int, int>> DisperseMatrix::getDisperseColList(int columna) // Retorna una lista de pares de enteros con los valores de columna y la fila correspondiente con sus 0
{
    list<pair<int, int>> result;
    pair<int, int> par;
    for (int i = 0; i < nFilas; i++)
    {
        par = make_pair(0, i);
        result.push_back(par);
    }

    list<pair<int, int>>::iterator it = result.begin();
    int i = 0;
    while (i < valores.size() && it != result.end())
    {
        if (columnas[i] == columna && filas[i] == it->second)
        {
            it->first = valores[i];
            it++;
        }
        i++;
        if (i == valores.size() && it != result.end())
        {
            i = 0;
            it++;
        }
    }

    return result;
}
// Siendo n el valor maximo entre nFilas y el tamaño del vector de valores
// Complejidad O(n)
vector<pair<int, int>> DisperseMatrix::getDisperseColVec(int columna) // Retorna un vector de pares de enteros con los valores de columna y la fila correspondiente con sus 0
{
    vector<pair<int, int>> result;
    pair<int, int> par;
    for (int i = 0; i < nFilas; i++)
    {
        par.first = 0;
        par.first = i;
        result.push_back(par);
    }

    for (int i = 0; i < valores.size(); i++) // agrega en la posicion respectiva el valor diferente a 0
    {
        if (columnas[i] == columna)
        {
            result[filas[i]].first = valores[i];
        }
    }
    return result;
}
// siendo n = el valor maximo entre nFilas y el tamaño del vector de valores
// Complejidad O(n)
void DisperseMatrix::printMatrix(string sep) // Imprime una matriz dispersa separa por el string ingresado
{
    vector<vector<int>> matriz(nFilas, vector<int>(nColumnas, 0)); // crea un matriz de 0 del tamaño original
    for (int i = 0; i < valores.size(); i++)
    {
        int valor = valores[i];
        int fila = filas[i];
        int columna = columnas[i];
        matriz[fila][columna] = valor; // agrega los valores en las posicion original
    }
    for (int i = 0; i < matriz.size(); i++)
    {
        for (int j = 0; j < matriz[i].size() - 1; j++)
        {
            cout << matriz[i][j] << sep;
        }
        cout << matriz[i][matriz[i].size() - 1];
        cout << endl;
    }
}
// Siendo n el numero de filas y m el numero de columnas
// Siendo lo mas costoso n*m Complejidad O(n*m)
int DisperseMatrix::getMax() // Retorna el valor maximo de la matriz dispersa
{
    int ans = -2147483648;
    for (int i = 0; i < valores.size(); i++)
    {
        if (valores[i] > ans)
            ans = valores[i];
    }
    return ans;
}
// Siendo n el tamaño del vector de valores
// Complejidad O(n)
DisperseMatrix DisperseMatrix::getTranspose() // Retorna una matriz dispersa transpuesta
{
    DisperseMatrix matriz;
    matriz.nFilas = nColumnas;
    matriz.nColumnas = nFilas;
    for (int i = 0; i < valores.size(); i++)
    {
        matriz.valores.push_back(valores[i]);
        matriz.filas.push_back(columnas[i]);
        matriz.columnas.push_back(filas[i]);
    }
    return matriz;
}
// Siendo n el tamaño del vector de valores
// Complejidad O(n)
DisperseMatrix DisperseMatrix::addMatrixList(list<DisperseMatrix> &l) // Retorna una matriz dispersa la cual es la suma de toda las matrices dispersas de la lista
{
    DisperseMatrix ans;
    list<DisperseMatrix>::iterator it = l.begin();
    for (it; it != l.end(); ++it)
    {
        ans = (ans) + (*it);
    }
    return ans;
}
// Siendo n el tamaño de la lista y la sobrecarga + que tiene costo de O(n)
// Siendo lo mas costoso n*n Complejidad O(n**2)

/* Sobrecarga operadores */

DisperseMatrix DisperseMatrix::operator+(DisperseMatrix &matrix2) // Suma dos matrices dispersas
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
// siendo n = el valor maximo entre el tamaño del vector valores de la matriz1 y la matriz 2
// Complejidad O(n)
DisperseMatrix DisperseMatrix::operator*(DisperseMatrix &matrix2) // Multiplica dos matrices dispersas
{
    DisperseMatrix result;
    int n = max(nColumnas, matrix2.nFilas), product;
    result.nFilas = nFilas;
    result.nColumnas = matrix2.nColumnas;
    for (int fila1 = 0; fila1 < nFilas; fila1++)
    {
        for (int col2 = 0; col2 < matrix2.nColumnas; col2++)
        {
            product = 0;
            for (int i = 0; i < n; i++)
            {
                product += get(fila1, i) * matrix2.get(i, col2);

                if (product != 0)
                {
                    result.valores.push_back(product);
                    result.filas.push_back(fila1);
                    result.columnas.push_back(col2);
                }
            }
        }
    }
    return result;
}
// n = es el máximo entre nColumnas y matrix2.nFilas, m = nFilas, v = matriz2.nColumnas y get() que vale O(n)
// Siendo la operacion mas costosa m*v*n*n , Complejidad O(m*v*n**2)
bool DisperseMatrix::operator==(DisperseMatrix &matrix2) // Compara si dos matrices dispersas son iguales
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
// n = tamaño del vector valores
// Complejidad O(n)
