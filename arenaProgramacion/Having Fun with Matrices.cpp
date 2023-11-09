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
                rowA = matrizDispersa.getDisperseRowVec(a - 1);
                rowB = matrizDispersa.getDisperseRowVec(b - 1);

                for (int i = 0; i < rowB.size(); i++)
                {
                    matrizDispersa.assign(a - 1, i, rowB[i].first);
                }

                for (int i = 0; i < rowA.size(); i++)
                {
                    matrizDispersa.assign(b - 1, i, rowA[i].first);
                }

                // matrizDispersa.printMatrix("");
            }
            else if (tr == "col")
            {
                int a, b;
                cin >> a >> b;
                vector<pair<int, int>> colA, colB;
                colA = matrizDispersa.getDisperseColVec(a - 1);
                colB = matrizDispersa.getDisperseColVec(b - 1);

                for (int i = 0; i < colB.size(); i++)
                {
                    matrizDispersa.assign(i, a - 1, colB[i].first);
                }

                for (int i = 0; i < colA.size(); i++)
                {
                    matrizDispersa.assign(i, b - 1, colA[i].first);
                }
                // matrizDispersa.printMatrix("");
            }
            else if (tr == "inc")
            {
                
            }
            else if (tr == "dec")
            {

            }
            else if (tr == "transpose")
            {
                matrizDispersa = matrizDispersa.getTranspose();
                // matrizDispersa.printMatrix("");
            }
        }
        iteration++;
    }
}