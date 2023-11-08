#include "matrizDispersa.h"

using namespace std;
int main()
{
    vector<vector<int>> matriz1 = {{5, 3 , -4 , -2},
                                   {8 , -1 , 0 , -3}};

    DisperseMatrix matriz_1(matriz1, 2, 4);
    vector<vector<int>> matriz2 = {{1 , 4 , 0},
                                   {-5 , 3 , 7},
                                   {0 , -9 , 5},
                                   {5 , 1 , 4}};
    DisperseMatrix matriz_2(matriz2, 4, 3);

    matriz_1 * matriz_2;

    return 0;
}