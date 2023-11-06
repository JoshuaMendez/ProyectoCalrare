#include "matrizDispersa.h"

int main()
<<<<<<< HEAD
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
=======
{
  vector<vector<int>> vec = {
      {1, 1, 0, 0},
      {1, 2, 0, 5},
      {1, 0, 0, 0},
      {1, 0, 0, 4}};
  DisperseMatrix matriz(vec, 4, 4);
  
  vector<vector<int>> vec1 = {
      {1, 1, 0, 0},
      {1, 2, 0, 5},
      {1, 0, 0, 0},
      {1, 0, 0, 4}};
  DisperseMatrix matriz1(vec1, 4, 4);
  
  vector<pair<int, int>> asdf = matriz.getColVec(2);


  return 0;
>>>>>>> 39b04c8d5887c1bea3064a2a9e73811f20fe9e0b
}
