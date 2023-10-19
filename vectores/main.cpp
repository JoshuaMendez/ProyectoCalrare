#include "matrizDispersa.h"

using namespace std;
int main(){
    vector<vector<int>> matriz = {{0,3,0,0,2},
                                  {1,0,0,5,7} };

    DisperseMatrix matriz_1(matriz,2 ,5);
    vector<int> vec = matriz_1.getColVec(1);
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    
    return 0;
}   