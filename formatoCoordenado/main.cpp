#include <cstdio>
#include <vector>
#include <list>
#include <deque>
#include "matrizDispersa.h"

int main()
{
    int **mat1;
    int n, m, i, j, q, r, c, v, casos;
    DisperseMatrix d, d2, d3, d4, d5, d6, d7;
    vector<vector<int>> mat2;
    vector<int> vec;
    list<DisperseMatrix> l;
    vector<pair<int, int>> vp;
    list<pair<int, int>> lp;
    // deque<pair<int, int>> lp;
    list<pair<int, int>>::iterator it;
    // deque<pair<int, int>>::iterator it;

    scanf("%d", &casos);
    while (casos > 0)
    {
        mat2.clear();
        vec.clear();
        scanf("%d %d", &n, &m);
        mat1 = new int *[n];
        for (i = 0; i < n; ++i)
        {
            mat1[i] = new int[m];
        }

        for (i = 0; i < n; ++i)
        {
            mat2.push_back(vector<int>());
            for (j = 0; j < m; ++j)
            {
                scanf("%d", &mat1[i][j]);
                mat2[i].push_back(mat1[i][j]);
            }
        }

        d = DisperseMatrix(mat1, n, m);
        printf("Matriz 1:\n");
        d.printMatrix(", ");

        d2 = DisperseMatrix(mat2);
        printf("Matriz 2:\n");
        d2.printMatrix(", ");

        printf("Max: %d\n", d.getMax());

        scanf("%d", &q);
        for (i = 0; i < q; ++i)
        {
            scanf("%d %d", &r, &c);
            printf("%d\n", d.get(r, c));
        }

        scanf("%d", &q);
        for (i = 0; i < q; ++i)
        {
            scanf("%d %d %d", &r, &c, &v);
            d2.assign(r, c, v);
        }

        d2.printMatrix("---");
        printf("Max: %d\n", d2.getMax());

        for (i = 0; i < m; ++i)
        {
            scanf("%d", &v);
            vec.push_back(v);
        }

        d.productVector(vec);
        d.printMatrix(" ");

        d3 = d.getTranspose();
        d3.printMatrix(",");

        d4 = DisperseMatrix(d);
        d4.printMatrix("  ");

        if (d == d4)
            cout << "d y d4 son iguales" << endl;
        else
            cout << "d y d4 son diferentes" << endl;

        if (d == d2)
            cout << "d y d2 son iguales" << endl;
        else
            cout << "d y d2 son diferentes" << endl;

        scanf("%d", &q);
        for (i = 0; i < q; ++i)
        {
            scanf("%d %d %d", &r, &c, &v);
            d4.assign(r, c, v);
        }

        d4.printMatrix(", ");

        printf("Result:\n");
        d.add(d4);
        d.printMatrix(" . ");

        d3 = d.getTranspose();
        d3.printMatrix(",");

        d5 = d * d3;
        d5.printMatrix(" * ");

        d6 = d3 * d;
        d6.printMatrix(", ");

        d6 = d + d5;
        d6.printMatrix("---");
        d5.printMatrix("*");

        vector<vector<int>> vec2 = d5.rebuild();

        printf("Vector:\n");
        for (i = 0; i < vec2.size(); ++i)
        {
            for (j = 0; j < vec2[i].size(); ++j)
                printf("%d ", vec2[i][j]);
            printf("\n");
        }

        d6 = DisperseMatrix(vec2);
        d6.printMatrix("...");

        scanf("%d %d", &n, &m);
        mat1 = new int *[n];
        for (i = 0; i < n; ++i)
        {
            mat1[i] = new int[m];
        }

        for (i = 0; i < n; ++i)
        {
            for (j = 0; j < m; ++j)
                scanf("%d", &mat1[i][j]);
        }

        d7 = DisperseMatrix(mat1, n, m);
        d7.printMatrix("---[]---");

        l.clear();
        l.push_back(d);
        l.push_back(d2);
        l.push_back(d3);
        l.push_back(d4);
        l.push_back(d5);
        l.push_back(d6);
        l.push_back(d7);

        d6 = d6.DisperseMatrix::addMatrixList(l);
        d6.printMatrix("-.-");

        printf("Max: %d\n", d6.getMax());

        scanf("%d", &q);
        for (i = 0; i < q; ++i)
        {
            scanf("%d", &r);
            vp = d6.getRowVec(r);
            printf("--------------------------------------\n");
            printf("Row Vec %d:\n", r);
            for (j = 0; j < vp.size(); ++j)
            {
                printf("(%d, %d)\n", vp[j].first, vp[j].second);
            }

            vp = d6.getDisperseRowVec(r);
            printf("--------------------------------------\n");
            printf("DisperseRow Vec %d:\n", r);
            for (j = 0; j < vp.size(); ++j)
            {
                printf("(%d, %d)\n", vp[j].first, vp[j].second);
            }

            list<pair<int, int>> lp = d6.getRowList(r);
            printf("--------------------------------------\n");
            printf("Row List %d:\n", r);
            for (it = lp.begin(); it != lp.end(); ++it)
            {
                printf("(%d, %d)\n", it->first, it->second);
            }

            lp = d6.getDisperseRowList(r);
            printf("--------------------------------------\n");
            printf("DisperseRow List %d:\n", r);
            for (it = lp.begin(); it != lp.end(); ++it)
            {
                printf("(%d, %d)\n", it->first, it->second);
            }

            vp = d6.getColVec(r);
            printf("--------------------------------------\n");
            printf("Col Vec %d:\n", r);
            for (j = 0; j < vp.size(); ++j)
            {
                printf("(%d, %d)\n", vp[j].first, vp[j].second);
            }

            vp = d6.getDisperseColVec(r);
            printf("--------------------------------------\n");
            printf("DisperseCol Vec %d:\n", r);
            for (j = 0; j < vp.size(); ++j)
            {
                printf("(%d, %d)\n", vp[j].first, vp[j].second);
            }

            lp = d6.getColList(r);
            printf("--------------------------------------\n");
            printf("Col List %d:\n", r);
            for (it = lp.begin(); it != lp.end(); ++it)
            {
                printf("(%d, %d)\n", it->first, it->second);
            }

            lp = d6.getDisperseColList(r);
            printf("--------------------------------------\n");
            printf("DisperseCol List %d:\n", r);
            for (it = lp.begin(); it != lp.end(); ++it)
            {
                printf("(%d, %d)\n", it->first, it->second);
            }
        }

        --casos;
        if (casos)
            printf("\n");
        for (i = 0; i < n; ++i)
            delete mat1[i];
        delete mat1;
    }

    return 0;
}
