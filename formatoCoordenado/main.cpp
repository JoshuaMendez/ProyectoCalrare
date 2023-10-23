#include "matrizDispersa.h"

using namespace std;
int main()
{
    vector<vector<int>> matriz = {{-3, 0},
                                    {2, 5},
                                    {8, -7}};

    vector<vector<int>> matriz2 = {{7, -5},
                                    {1, -2},
                                    {1, -4}};

    DisperseMatrix matriz_1(matriz, 3, 2);
    DisperseMatrix matriz_2(matriz2, 3, 2);

    DisperseMatrix calc;

    calc = matriz_1 + matriz_2;

    for (int i = 0; i < calc.valores.size(); i++)
    {
        if (i % 2 == 0)
            cout << endl;
        cout << calc.valores[i] << " ";
    }
    cout << endl;

    return 0;
}