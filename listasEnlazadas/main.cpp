#include "matrizDispersa.cpp"

int main()
{
    vector<vector<int>> matriz1 = {{5, 3, -4, -2},
                                   {8, -1, 0, -3}};

    DisperseMatrix matriz_1(matriz1, 2, 4);

    vector<vector<int>> matriz2 = {{1, 4, 0},
                                   {-5, 3, 7},
                                   {0, -9, 5},
                                   {5, 1, 4}};

    DisperseMatrix matriz_2(matriz2, 4, 3);

    cout << "in" << endl;
    
    matriz_1 * matriz_2;

    return 0;
}

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

//     DisperseMatrix matriz1(vec1, 8, 7);

//     vector<DisperseMatrix> l;
//     l.push_back(matriz1);
//     l.push_back(matriz2);
//     l.push_back(matriz3);
//     l.push_back(matriz4);
//     l.push_back(matriz5);
//     l.push_back(matriz6);

//     DisperseMatrix a;
//     a = a.addMatrixList(l);
//     cout << "matriz a" << endl;
//     a.printMatrix(",");

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
