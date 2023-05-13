// WAP for creating a sparse matrix -->> yale representation
// using Yale's method for sparse matrix representation.

#include <iostream>
#include <time.h>
using namespace std;

int main()
{
    int m = 5, n = 5;
    int mat[m][n];
    srand((unsigned)time(NULL));

    // generation of sparse matrix
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            mat[i][j] = rand() % 3;
        }
    }

    // display sparse matrix
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << mat[i][j] << ", ";
        }
        cout << endl;
    }

    cout << "Yale's Representation" << endl;
    int vals[m * n], rows[n + 1], columns[m * n], count = 0;

    // values set
    cout << "Values: ";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] != 0)
            {
                vals[i] = mat[i][j];
                cout << vals[i] << ", ";
            }
        }
    }

    // columns set
    cout << "\nColumns: ";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] != 0)
            {
                columns[i] = j;
                cout << columns[i] << ", ";
            }
        }
    }

    // rows set
    cout << "\nRows: ";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] != 0)
            {
                count = count + 1;
            }
        }
        rows[i] = count;
        cout << rows[i] << ", ";
    }

    return 0;
}