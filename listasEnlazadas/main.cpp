#include "matrizDispersa.h"

int main()
{
    // vector<vector<int>> vec1 = {
    //     {0, 2, 0, 0, 0, 0, 4},
    //     {0, 8, 9, 0, 0, 1, 0},
    //     {0, 0, 0, 3, 0, 0, 0},
    //     {0, 0, 0, 0, 0, 0, 0},
    //     {5, 0, 0, 0, 0, 6, 0},
    //     {1, 2, 0, 0, 0, 0, 0},
    //     {4, 0, 0, 0, 0, 0, 0},
    //     {0, 0, 7, 0, 0, 11, 0}};

    // vector<vector<int>> vec6 = {
    //     {3, 8, 0, 12, 0},
    //     {0, 6, 15, 0, 7},
    //     {9, 0, 0, 14, 2},
    //     {5, 10, 0, 0, 18},
    //     {0, 4, 11, 0, 1}};

    vector<vector<int>> vec1 = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 1, 2, 3},
        {4, 5, 6, 7}};

    vector<vector<int>> vec6 = {
        {2, 2},
        {2, 2},
        {2, 2},
        {2, 0},
        {2, 2}};

    DisperseMatrix matriz1(vec1, 4, 4);
    DisperseMatrix matriz6(vec6, 5, 2);

    matriz1.add(matriz6);

<<<<<<< HEAD
  DisperseMatrix matriz1(vec1, 8, 7);
  DisperseMatrix matriz2(vec2, 8, 7);
    DisperseMatrix matriz3(vec3, 8, 7);
  DisperseMatrix matriz4(vec4, 8, 7);
 DisperseMatrix matriz5(vec5, 8, 7);
  DisperseMatrix matriz6(vec6, 5, 5);


 
 /* l.push_back(matriz1);
  l.push_back(matriz2);
  l.push_back(matriz3);
  l.push_back(matriz4);
  l.push_back(matriz5);
  l.push_back(matriz6);

  DisperseMatrix a;
  a = a.addMatrixList(l);
  cout << "matriz a" << endl;
  a.printMatrix(",");
    */
  // Resultado
  // 23 12 55 17 69 25 29
  // 20 39 32 18 33 36 14
  // 20 63 37 52 7 40 10
  // 31 27 47 27 14 65 2
  // 10 27 38 14 21 31 29
  // 51 25 31 5 35 58 8
  // 12 15 10 18 43 56 0
  // 16 7 29 7 33 64 3

  return 0;
=======
    matriz1.printMatrix(", ");

    return 0;
>>>>>>> ac9f986032890cb88e94439a2ff044edb1cb7d97
}

// int main()
// {
//     vector<vector<int>> matriz1 = {{5, 3, -4, -2},
//                                    {8, -1, 0, -3}};

//     DisperseMatrix matriz_1(matriz1, 2, 4);

//     vector<vector<int>> matriz2 = {{1, 4, 0},
//                                    {-5, 3, 7},
//                                    {0, -9, 5},
//                                    {5, 1, 4}};

//     DisperseMatrix matriz_2(matriz2, 4, 3);
//     // get(fila1, i) * matrix2.get(i, col2);
//     matriz_1 *matriz_2;

//     return 0;
// }

// int main()
// {
//     vector<vector<int>> vec1 = {
//         {0, 2, 0, 0, 0, 0, 4},
//         {0, 8, 9, 0, 0, 1, 0},
//         {0, 0, 0, 3, 0, 0, 0},
//         {0, 0, 0, 0, 0, 0, 0},
//         {5, 0, 0, 0, 0, 6, 0},
//         {1, 2, 0, 0, 0, 0, 0},
//         {4, 0, 0, 0, 0, 0, 0},
//         {0, 0, 7, 0, 0, 11, 0}};

//     vector<vector<int>> vec2 = {
//         {9, 2, 12, 17, 8, 5, 4},
//         {3, 8, 9, 14, 21, 1, 6},
//         {11, 15, 6, 3, 2, 9, 10},
//         {5, 13, 19, 1, 4, 6, 2},
//         {5, 7, 8, 9, 7, 6, 1},
//         {1, 2, 14, 5, 12, 3, 7},
//         {4, 16, 3, 18, 8, 20, 8},
//         {10, 2, 7, 16, 22, 11, 3}};

//     vector<vector<int>> vec3 = {
//         {6, 18, 9, 0, 14, 0, 7},
//         {23, 0, 8, 4, 12, 0, 5},
//         {0, 11, 0, 3, 0, 19, 0},
//         {10, 0, 0, 0, 0, 13, 0},
//         {0, 16, 2, 0, 0, 0, 21},
//         {0, 0, 17, 0, 20, 0, 8},
//         {1, 15, 0, 0, 0, 0, 0}};

//     vector<vector<int>> vec4 = {
//         {10, 0, 18, 0, 25, 0, 7},
//         {6, 12, 0, 0, 0, 19, 8},
//         {0, 21, 17, 9, 0, 4, 0},
//         {13, 0, 0, 5, 0, 16, 0},
//         {0, 0, 11, 14, 3, 0, 0},
//         {23, 0, 0, 0, 1, 22, 0},
//         {2, 0, 0, 0, 15, 20, 0}};

//     vector<vector<int>> vec5 = {
//         {8, 0, 17, 0, 22, 0, 3},
//         {11, 5, 0, 0, 0, 19, 0},
//         {0, 9, 14, 6, 0, 1, 0},
//         {13, 0, 0, 7, 0, 20, 0},
//         {0, 0, 12, 4, 10, 0, 0},
//         {25, 0, 0, 0, 2, 16, 0},
//         {1, 0, 0, 0, 18, 15, 0}};

//     vector<vector<int>> vec6 = {
//         {3, 8, 0, 12, 0},
//         {0, 6, 15, 0, 7},
//         {9, 0, 0, 14, 2},
//         {5, 10, 0, 0, 18},
//         {0, 4, 11, 0, 1}};

//     DisperseMatrix matriz1(vec1, 8, 7);
//     DisperseMatrix matriz2(vec2, 8, 7);
//     DisperseMatrix matriz3(vec3, 7, 7);
//     DisperseMatrix matriz4(vec4, 7, 7);
//     DisperseMatrix matriz5(vec5, 7, 7);
//     DisperseMatrix matriz6(vec6, 5, 5);

//     list<DisperseMatrix> l;
//     l.push_back(matriz1);
//     l.push_back(matriz2);
//     l.push_back(matriz3);
//     l.push_back(matriz4);
//     l.push_back(matriz5);
//     l.push_back(matriz6);

//     DisperseMatrix a;
//     a = a.addMatrixList(l);

//     // Resultado
//     // 23 12 55 17 69 25 29
//     // 20 39 32 18 33 36 14
//     // 20 63 37 52 7 40 10
//     // 31 27 47 27 14 65 2
//     // 10 27 38 14 21 31 29
//     // 51 25 31 5 35 58 8
//     // 12 15 10 18 43 56 0
//     // 16 7 29 7 33 64 3

//     return 0;
// }