#include "matrizDispersa.h"

using namespace std;
int main()
{
    vector<vector<int>> matriz5 = {{2, 0, 100},
                                   {3, 7, 2},
                                   {6, 2, 1}};

    DisperseMatrix matriz_5(matriz5, 3, 3);


    list<int> lista;

    lista = matriz_5.getDisperseRowLis(0);



    for (const int &elemento : lista) {
        cout << elemento << " ";
    }

    cout << endl;

    return 0;
}