#include "matrizDispersa.h"

using namespace std;
int main()
{
    vector<vector<int>> matriz = {{1, 0, 2, 0},
                                    {0, 9, 0, 3},
                                    {0, 4, 0, 0},
                                    {0, 0, 0, 0}};

    DisperseMatrix matriz_1(matriz, 3, 2);

    cout << "valores";
    for (int i = 0; i < matriz_1.valores.size(); i++)
    {
        cout << " " << matriz_1.valores[i];
    }
    cout << endl;

    cout << "filas";
    for (int i = 0; i < matriz_1.valores.size(); i++)
    {
        cout << " " << matriz_1.filas[i];
    }
    cout << endl;

    cout << "columnas";
    for (int i = 0; i < matriz_1.valores.size(); i++)
    {
        cout << " " << matriz_1.columnas[i];
    }
    cout << endl;

    matriz_1.assign(0, 2, 5);

    
    return 0;
}