#include "matrizDispersa.h"

using namespace std;
int main()
{
    vector<vector<int>> matriz5 = {{2, 2, 2},
                                   {2, 2, 2},
                                   {2, 2, 2}};

    DisperseMatrix matriz_5(matriz5, 3, 3);
    vector<int> vecc;
    vecc.push_back(2);
    vecc.push_back(3);
    vecc.push_back(5);

    matriz_5.productVector(vecc);

    for (int i = 0; i < matriz_5.valores.size(); i++)
    {
        if (i % 3 == 0)
            cout << endl;
        cout << matriz_5.valores[i] << " ";
    }
    cout << endl;

    return 0;
}