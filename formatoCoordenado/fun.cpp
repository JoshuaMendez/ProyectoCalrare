#include "dispersematrix.h"

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

        DisperseMatrix matrizDispersa(mat);

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
            }
            else if (tr == "inc")
            {
                for (int i = 0; i < sizeMat; i++)
                {
                    for (int j = 0; j < sizeMat; j++)
                    {
                        if (matrizDispersa.get(i, j) == 0)
                        {
                            matrizDispersa.assign(i, j, 1);
                        }
                        else
                        {
                            int valor = matrizDispersa.get(i, j);
                            valor = ((valor + 1) % 10);
                            matrizDispersa.assign(i, j, valor);
                        }
                    }
                }
            }
            else if (tr == "dec")
            {
                for (int i = 0; i < sizeMat; i++)
                {
                    for (int j = 0; j < sizeMat; j++)
                    {
                        if (matrizDispersa.get(i, j) == 0)
                        {
                            matrizDispersa.assign(i, j, 9);
                        }
                        else
                        {
                            int valor = matrizDispersa.get(i, j);
                            valor = ((valor - 1) % 10);
                            matrizDispersa.assign(i, j, valor);
                        }
                    }
                }
            }
            else if (tr == "transpose")
            {
                matrizDispersa = matrizDispersa.getTranspose();
            }
        }
        if (iteration != 1)
            cout << endl;
        cout << "Case #" << iteration << endl;
        matrizDispersa.printMatrix("");

        iteration++;
    }
}