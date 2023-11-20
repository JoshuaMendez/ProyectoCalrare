#include "dispersematrix.h"
int main()
{
    vector<vector<int>> vec = {{1, 3, 0, 0, 0, 7}, {2, 4, 0, 0, 0, 5}};
    DisperseMatrix matriz(vec);
    matriz.assign(0, 0, 0);

    return 0;
}