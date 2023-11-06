#include "matrizDispersa.h"

int main()
{ 
   vector<vector<int>> vec = {
    {1, 1, 0, 0},
    {1, 2, 0, 5},
    {1, 0, 0, 0},
    {1, 0, 0, 4}
  };
    DisperseMatrix matriz(vec, 4, 4);
    vector<int> vec1 = { 1 , 2 , 3 ,4 };
    matriz.printMatrix("-");
    matriz.productVector(vec1);
    matriz.printMatrix("-");

    return 0;
}
