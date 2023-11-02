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
     vector<vector<int>> vec1 = {
     {1, 1, 0, 0},
    {1, 2, 0, 5},
    {1, 0, 0, 0},
    {1, 0, 0, 4}
  };
    DisperseMatrix matriz1(vec1, 4, 4);
    matriz==matriz1;
    return 0;
}
