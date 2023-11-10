#include "matrizDispersa.h"

int main()
{
    vector<vector<int>> matriz1 = {{5, 3, -4, -2},
                                   {8, -1, 0, -3}};

    DisperseMatrix matriz_1(matriz1);

    vector<vector<int>> matriz2 = {{0, 4, 0},
                                   {-5, 3, 7},
                                   {0, -9, 5},
                                   {5, 0, 4}};

    DisperseMatrix matriz_2(matriz2);

    list<pair<int, int>> lista;
    lista = matriz_2.getDisperseRowLis(0);

    for (pair<int, int> it : lista)
    {
        cout << it.first << " " << it.second << endl;
    }
    cout << endl;

    return 0;
}