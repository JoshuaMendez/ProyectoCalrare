#include "matrizDispersa.h"

using namespace std;
int main()
{
    vector<vector<int>> matriz = {{5, 3},
                                    {-2, 9},
                                    {7, -4}};

    vector<vector<int>> matriz2 = {{5, 3},
                                    {-2, 9},
                                    {7, -4}};

    DisperseMatrix matriz_1(matriz, 3, 2);
    DisperseMatrix matriz_2(matriz2, 3, 2);

    bool calc;

    calc = matriz_1 == matriz_2;

    cout << "calc " << calc << endl;

    return 0;
}