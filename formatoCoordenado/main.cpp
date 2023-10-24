#include "matrizDispersa.h"

using namespace std;
int main()
{
    vector<vector<int>> matriz = {{1, 0, 2, 0},
                                    {0, 9, 0, 3},
                                    {0, 4, 0, 0},
                                    {0, 0, 0, 0}};

    DisperseMatrix matriz_1(matriz, 4, 4);

    matriz_1.printMatrix("-");
     matriz_1.getTranspose().printMatrix("-");

    
    return 0;
}