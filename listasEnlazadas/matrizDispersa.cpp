#include "matrizDispersa.h"

/* Constructoras */

DisperseMatrix::DisperseMatrix()
{
    matriz = {};
    nFilas = 0;
    nColumnas = 0;
}
DisperseMatrix::DisperseMatrix(int **matrizA, int m, int n)
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

DisperseMatrix::DisperseMatrix(vector<vector<int>> &vec, int m, int n)
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
    }
    nFilas = m;
    nColumnas = n;
}

DisperseMatrix::DisperseMatrix(const DisperseMatrix &matriz1)
{
    matriz = matriz1.matriz;
    nFilas = matriz1.nFilas;
    nColumnas = matriz1.nColumnas;
}
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
void DisperseMatrix::assign(int i, int j, int v)
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

void DisperseMatrix::add(DisperseMatrix &matriz2)
{
    int vecMax = max(matriz.size(), matriz2.matriz.size());
    for (int i = 0; i < vecMax; i++)
    {
        if (matriz.size() > matriz2.matriz.size())
        {
            while (matriz.size() != matriz2.matriz.size())
            {
                matriz2.matriz.push_back(list<pair<int, int>>());
            }
        }
        else if (matriz2.matriz.size() > matriz.size())
        {
            while (matriz.size() != matriz2.matriz.size())
            {
                matriz.push_back(list<pair<int, int>>());
            }
        }
    }
    int filMaxMat1 = 0, filMaxMat2 = 0;
    for (int i = 0; i < matriz.size(); i++)
    {
        list<pair<int, int>>::iterator it;
        it = matriz[i].begin();
        while (it != matriz[i].end())
        {
            if (it->second > filMaxMat1)
                filMaxMat1 = it->second;
            it++;
        }
    }
    for (int i = 0; i < matriz2.matriz.size(); i++)
    {
        list<pair<int, int>>::iterator it;
        it = matriz2.matriz[i].begin();
        while (it != matriz2.matriz[i].end())
        {
            if (it->second > filMaxMat2)
                filMaxMat2 = it->second;
            it++;
        }
    }
    for (int i = 0; i < vecMax; i++)
    {
        if (matriz[i].size() > matriz2.matriz[i].size())
        {
            list<pair<int, int>>::iterator it = matriz2.matriz[i].begin();
            for (int j = 0; j < filMaxMat1; j++)
            {
                if ()
                {
                    pair<int, int> par;
                    par = make_pair(0, j);
                    matriz2.matriz[i].push_back(par);
                }
            }
        }
        // else if (matriz2.matriz[i].size() > matriz[i].size())
        // {
        //     list<pair<int, int>>::iterator it = matriz[i].begin();
        //     for (int j = 0; j < filMax; j++)
        //     {
        //         if (!(it->second == j))
        //         {
        //             pair<int, int> par;
        //             par = make_pair(0, j);
        //             matriz2.matriz[i].push_back(par);
        //         }
        //     }
        // }
        cout << "m2" << endl;
    }
    for (int i = 0; i < matriz2.matriz[i].size(); i++)
    {
        for (pair<int, int> elemento : matriz2.matriz[i])
        {
            cout << elemento.first << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// bool reachLimMat2 = false;
// int maxIt = max(matriz[i].size(), matriz2.matriz[i].size());
// list<pair<int, int>>::iterator it1 = matriz[i].begin();
// list<pair<int, int>>::iterator it2 = matriz2.matriz[i].begin();
// int j = 0;
// while (j < maxIt)
// {
//     int tmp = 0;
//     cout << "fila " << i << endl;
//     cout << "rLM2 " << reachLimMat2 << endl;
//     if (it1->second == it2->second && !reachLimMat2)
//     {
//         tmp += (it1->first + it2->first);
//         cout << "it1->first " << it1->first << " it2->first " << it2->first << endl;
//         cout << "tm " << tmp << endl;
//         cout << it2->second << " " << matriz2.matriz[i].size() - 1 << endl;
//         if (it2->second == matriz2.matriz[i].size() - 1 && !reachLimMat2)
//             reachLimMat2 = true;
//         it1->first = tmp;
//     }
//     if (reachLimMat2)
//     {
//         it1->first += 0;
//     }

//     it1++;
//     it2++;

//     j++;
// }
// cout << endl;
// printMatrix(",");
// cout << endl;
// // for (int j = 0; j < maxIt; j++, it1++, it2++)
// // {
// //     int tmp = 0;
// //     if (it1->second == it2->second && !reachLimMat2)
// //     {
// //         tmp += (it1->first + it2->first);
// //         cout << "tm " << tmp << endl;
// //         if ()
// //     }
// //     it1->first = tmp;
// // }
// }
// Podría ir fila por fila verificando la columna y si esa fila y columna también existe en la matriz2,
// sumarle eso, sino, sumar 0

// for (int fila = 0; fila < nFilas; fila++)
// {
//     cout << "Fila " << fila << ": ";
//     for (const pair<int, int> &elemento : matriz[fila])
//     {
//         cout << "(" << elemento.first << ", " << elemento.second << ") ";
//     }
//     cout << endl;
// }
// cout << endl;
// for (int fila = 0; fila < matriz2.nFilas; fila++)
// {
//     cout << "Fila " << fila << ": ";
//     for (const pair<int, int> &elemento : matriz2.matriz[fila])
//     {
//         cout << "(" << elemento.first << ", " << elemento.second << ") ";
//     }
//     cout << endl;
// }

void DisperseMatrix::productVector(vector<int> &vec)
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

/* Analizadoras */

int DisperseMatrix::get(int i, int j)
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

list<pair<int, int>> DisperseMatrix::getRowList(int fila)
{
    return matriz[fila]; // retorna la lista con valor y columna
}

vector<pair<int, int>> DisperseMatrix::getRowVec(int fila)
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

list<pair<int, int>> DisperseMatrix::getColList(int columna)
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

vector<pair<int, int>> DisperseMatrix::getColVec(int columna)
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

list<pair<int, int>> DisperseMatrix::getDisperseRowLis(int fila)
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

vector<pair<int, int>> DisperseMatrix::getDisperseRowVec(int fila)
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

list<pair<int, int>> DisperseMatrix::getDisperseColList(int columna)
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
    return result; // retorna el valor y la fila
}

vector<pair<int, int>> DisperseMatrix::getDisperseColVec(int columna)
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

void DisperseMatrix::printMatrix(string sep)
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

int DisperseMatrix::getMax()
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

DisperseMatrix DisperseMatrix::getTranspose()
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

DisperseMatrix DisperseMatrix::addMatrixList(list<DisperseMatrix> &listaMatriz)
{
    DisperseMatrix ans;
    list<DisperseMatrix>::iterator it;
    for (it = listaMatriz.begin(); it != listaMatriz.end(); it++)
    {
        ans = ans + *it;
    }
    ans.printMatrix(",");

    return ans;
}

/* Sobrecarga operadores */
bool comparador(pair<int, int> &a, pair<int, int> &b)
{
    return a.second < b.second;
}
DisperseMatrix DisperseMatrix::operator+(DisperseMatrix &sum)
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
    result.printMatrix("|");
    return result;
}

DisperseMatrix DisperseMatrix::operator*(DisperseMatrix &matrix2)
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
    result.printMatrix("|");
    return result;
}

bool DisperseMatrix::operator==(DisperseMatrix &matriz1)
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
                    cout << "entro" << endl;
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
