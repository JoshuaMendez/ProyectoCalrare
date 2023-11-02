#include "matrizDispersa.h"

int main()
{ 
   vector<vector<int>> vec = {
    {0, 1, 0, 0},
    {0, 2, 0, 5},
    {0, 0, 0, 0},
    {0, 0, 0, 4}
  };
    DisperseMatrix matriz(vec, 4, 4);
    list<int> lis = matriz.getDisperseColLis(3);
    return 0;
}
