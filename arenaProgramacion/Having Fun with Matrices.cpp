#include "../listasEnlazadas/matrizDispersa.h"

int main()
{
    int cases;
    cin >> cases;
    int iteration = 1;
    while (iteration <= cases)
    {
        int sizeMat;
        cin >> sizeMat;
        vector<vector<int>> mat;

        for (int i = 0; i < sizeMat; i++)
        {
            string line;
            cin >> line;
            vector<int> newLine;
            for (int j = 0; j < sizeMat; j++)
            {
                newLine.push_back(line[j] - 48);
            }
            mat.push_back(newLine);
        }

        DisperseMatrix matrizDispersa(mat, sizeMat, sizeMat);

        int trCases;
        cin >> trCases;
        while (trCases--)
        {
            string tr;
            cin >> tr;
            if (tr == "row")
            {
                int a, b;
                cin >> a >> b;
                vector<pair<int, int>> rowA, rowB;
                // rowA = matrizDispersa.getRowVec(a);
                // for (int i = 0; i < rowA.size(); i++)
                // {
                //     cout << rowA[i].first << " ";
                // }
                // cout << endl;
                // rowB = matrizDispersa.getRowVec(b);
                // matrizDispersa.getRowVec(a) = rowB;
                // matrizDispersa.getRowVec(b) = rowA;
                // cambio la fila a por la b CONTANDO DESDE 1

            }
        }



        cout << "mat" << endl;
        for (int i = 0; i < sizeMat; i++)
        {
            for (int j = 0; j < sizeMat; j++)
            {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
        iteration++;
    }
}