/*
 * Autores: Sebastian Izquierdo S. y Joshua Mendez
 * Archivo encabezado libreria TAD matriz Dispersa
 * Realización de Ejercicio de Arena de Programación
 */

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>

using namespace std;

/************************
 * ESTRUCTURAS DE DATOS *
 ************************/

class DisperseMatrix
{
private:
    vector<int> valores;
    vector<int> filas;
    vector<int> columnas;
    int nFilas, nColumnas;

public:
    /************************
     * OPERACIONES DEL TAD USADAS EN EL EJERCICIO *
     ************************/
    /* Constructoras */
    DisperseMatrix();                      // Vacío
    DisperseMatrix(vector<vector<int>> &); // Vector de Vectores

    /* Modificadoras */
    void assign(int, int, int); // Modificar el valor en la posición i, j

    /* Analizadoras */
    int get(int, int);                             // Obtener valor i, j
    vector<pair<int, int>> getDisperseRowVec(int); // Retornar una fila con ceros
    vector<pair<int, int>> getDisperseColVec(int); // Retornar columna con ceros
    void printMatrix(string);                      // Imprime la matriz con el separador
    DisperseMatrix getTranspose();                 // Transpone la matriz
};

DisperseMatrix::DisperseMatrix() // Inicializa una matriz dispersa vacía con tamaño 0 x 0
{
    valores;
    filas;
    columnas;
    nFilas = 0, nColumnas = 0;
}

DisperseMatrix::DisperseMatrix(vector<vector<int>> &matriz) // Recibe un vector de vectores y lo vuelve una matriz dispersa
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

void DisperseMatrix::assign(int i, int j, int v) // Ingresa un valor en la posicion i, j dada
{
    int cont = 0;
    bool flag = true;
    while (flag && cont < valores.size()) // Se verifica que la posición no exista.
    {
        if (filas[cont] == i && columnas[cont] == j)
        {
            if (v != 0)
            {
                valores[cont] = v;
            }
            else
            {
                valores.erase(valores.begin() + cont);
                filas.erase(filas.begin() + cont);
                columnas.erase(columnas.begin() + cont);
            }

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

int main()
{
    int cases;
    cin >> cases;
    int iteration = 1;
    while (iteration <= cases)
    {
        int sizeMat;
        cin >> sizeMat;
        vector<vector<int>> mat;

        for (int i = 0; i < sizeMat; i++)
        {
            string line;
            cin >> line;
            vector<int> newLine;
            for (int j = 0; j < sizeMat; j++)
            {
                newLine.push_back(line[j] - 48);
            }
            mat.push_back(newLine);
        }

        DisperseMatrix matrizDispersa(mat);

        int trCases;
        cin >> trCases;
        while (trCases--)
        {
            string tr;
            cin >> tr;

            if (tr == "row")
            {
                int a, b;
                cin >> a >> b;
                vector<pair<int, int>> rowA, rowB;
                rowA = matrizDispersa.getDisperseRowVec(a - 1);
                rowB = matrizDispersa.getDisperseRowVec(b - 1);

                for (int i = 0; i < rowB.size(); i++)
                {
                    matrizDispersa.assign(a - 1, i, rowB[i].first);
                }

                for (int i = 0; i < rowA.size(); i++)
                {
                    matrizDispersa.assign(b - 1, i, rowA[i].first);
                }
            }
            else if (tr == "col")
            {
                int a, b;
                cin >> a >> b;
                vector<pair<int, int>> colA, colB;
                colA = matrizDispersa.getDisperseColVec(a - 1);
                colB = matrizDispersa.getDisperseColVec(b - 1);

                for (int i = 0; i < colB.size(); i++)
                {
                    matrizDispersa.assign(i, a - 1, colB[i].first);
                }

                for (int i = 0; i < colA.size(); i++)
                {
                    matrizDispersa.assign(i, b - 1, colA[i].first);
                }
            }
            else if (tr == "inc")
            {
                for (int i = 0; i < sizeMat; i++)
                {
                    for (int j = 0; j < sizeMat; j++)
                    {
                        if (matrizDispersa.get(i, j) == 0)
                        {
                            matrizDispersa.assign(i, j, 1);
                        }
                        else
                        {
                            int valor = matrizDispersa.get(i, j);
                            valor = ((valor + 1) % 10);
                            matrizDispersa.assign(i, j, valor);
                        }
                    }
                }
            }
            else if (tr == "dec")
            {
                for (int i = 0; i < sizeMat; i++)
                {
                    for (int j = 0; j < sizeMat; j++)
                    {
                        if (matrizDispersa.get(i, j) == 0)
                        {
                            matrizDispersa.assign(i, j, 9);
                        }
                        else
                        {
                            int valor = matrizDispersa.get(i, j);
                            valor = ((valor - 1) % 10);
                            matrizDispersa.assign(i, j, valor);
                        }
                    }
                }
            }
            else if (tr == "transpose")
            {
                matrizDispersa = matrizDispersa.getTranspose();
            }
        }
        if (iteration != 1)
            cout << endl;
        cout << "Case #" << iteration << endl;
        matrizDispersa.printMatrix("");

        iteration++;
    }
}