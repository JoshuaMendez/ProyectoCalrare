#include "matrizDispersa.h"

using namespace std;
int main()
{
    vector<vector<int>> matriz1 = {{1, 2, 3},
                                   {4, 5, 6},
                                   {7, 8, 9}};

    vector<vector<int>> matriz2 = {{9, 8, 7},
                                   {6, 5, 4},
                                   {3, 2, 1}};

    vector<vector<int>> matriz3 = {{5, 5, 5},
                                   {5, 5, 5},
                                   {5, 5, 5}};

    vector<vector<int>> matriz4 = {{3, 3, 3},
                                   {3, 3, 3},
                                   {3, 3, 3}};

    vector<vector<int>> matriz5 = {{2, 2, 2},
                                   {2, 2, 2},
                                   {2, 2, 2}};

    DisperseMatrix matriz_1(matriz1, 3, 3);
    DisperseMatrix matriz_2(matriz2, 3, 3);
    DisperseMatrix matriz_3(matriz3, 3, 3);
    DisperseMatrix matriz_4(matriz4, 3, 3);
    DisperseMatrix matriz_5(matriz5, 3, 3);

    list<DisperseMatrix> lista;
    lista.push_back(matriz_2);
    lista.push_back(matriz_3);
    lista.push_back(matriz_4);
    lista.push_back(matriz_5);

    DisperseMatrix a;
    a = a.addMatrixList(lista);

    for (int i = 0; i < a.valores.size(); i++)
    {
        cout << a.valores[i] << " valores";
    }
    cout << endl;

    return 0;
}