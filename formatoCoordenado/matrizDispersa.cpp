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

DisperseMatrix::DisperseMatrix(const DisperseMatrix &matriz)
{
    valores = matriz.valores;
    filas = matriz.filas;
    columnas = matriz.columnas;
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

void DisperseMatrix::add(DisperseMatrix &matriz)
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

void DisperseMatrix::productVector(vector<int> &vec)
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
    }
    else
    {
        ans = valores[e - 1]; // imprime el valor correspondiente a la posicion encontrada
    }
    return ans;
}

list<int> DisperseMatrix::getRowLis(int fila)
{
    list<int> result;
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

vector<pair<int, int>> DisperseMatrix::getRowVec(int fila)
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

list<int> DisperseMatrix::getColLis(int columna)
{
    list<int> result;
    int i;

    for (i = 0; i < valores.size(); i++) // agrega en la posicion respectiva el valor diferente a 0
    {
        if (columnas[i] == columna)
        {
            result.push_back(valores[i]);
        }
    }
    return result;
}

vector<pair<int, int>> DisperseMatrix::getColVec(int columna)
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

vector<pair<int, int>> DisperseMatrix::getDisperseRowVec(int fila)
{
    vector<pair<int, int>> result;
    pair<int, int> par;
    for (int i = 0; i < nColumnas; i++)
    {
        par.first = 0;
        par.second = i;
    }

    for (int i = 0; i < valores.size(); i++) // agrega en la posicion respectiva el valor diferente a 0
    {
        if (fila == filas[i])
        {
            result[columnas[i]].second = valores[i];
        }
    }
    return result;
}

list<int> DisperseMatrix::getDisperseRowLis(int fila)
{
    list<int> result(nColumnas, 0);
    list<int>::iterator it = result.begin();

    for (int i = 0; i < valores.size(); i++) // agrega en la posicion respectiva el valor diferente a 0
    {
        it = result.begin();
        if (fila == filas[i])
        {
            // *it = *it + columnas[i];
            advance(it, columnas[i]);
            result.insert(it, valores[i]);
            result.erase(it);
        }
    }
    return result;
}

list<int> DisperseMatrix::getDisperseColLis(int columna)
{
    list<int> result(nFilas, 0);
    list<int>::iterator it = result.begin();

    for (int i = 0; i < valores.size(); i++) // agrega en la posicion respectiva el valor diferente a 0
    {
        it = result.begin();
        if (columnas[i] == columna)
        {
            // *it = *it + filas[i];
            advance(it, filas[i]);
            result.insert(it, valores[i]);
            result.erase(it);
        }
    }
    return result;
}

vector<pair<int, int>> DisperseMatrix::getDisperseColVec(int columna)
{
    vector<pair<int, int>> result;
    pair<int, int> par;
    for (int i = 0; i < nFilas; i++)
    {
        par.first = 0;
        par.first = i;
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

void DisperseMatrix::printMatrix(string sep)
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

int DisperseMatrix::getMax()
{
    int ans = -2147483648;

    for (int i = 0; i < valores.size(); i++)
    {
        if (valores[i] > ans)
            ans = valores[i];
    }

    return ans;
}

DisperseMatrix DisperseMatrix::getTranspose()
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

DisperseMatrix DisperseMatrix::addMatrixList(list<DisperseMatrix> &l)
{
    DisperseMatrix ans;
    list<DisperseMatrix>::iterator it = l.begin();

    for (it; it != l.end(); ++it)
    {
        ans = (ans) + (*it);
    }

    return ans;
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
    int n, product;
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

    result.printMatrix("|");
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