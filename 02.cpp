// WAP for creating a sparse matrix -->> non - sparse matrix

#include <iostream>
#include <time.h>
using namespace std;

int main()
{
    int m = 5, n = 5;
    int mat[m][n], nz = 0;
    srand((unsigned)time(NULL));

    // generation of sparse matrix
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            mat[i][j] = rand() % 3;
            if (mat[i][j] != 0)
            {
                nz += 1;
            }
        }
    }

    int row[nz + 1], col[nz + 1], val[nz + 1], count = 0;

    // display sparse matrix
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << mat[i][j] << ", ";
        }
        cout << endl;
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] != 0)
            {
                row[count] = i;
                col[count] = j;
                val[count] = mat[i][j];
                ++count;
            }
        }
    }

    int sm[nz + 1][3];

    cout << "Simple Representation" << endl;

    // Representation
    for (int i = 0; i < nz + 1; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i == 0 && j == 0)
            {
                sm[i][j] = m;
            }
            else if (i == 0 && j == 1)
            {
                sm[i][j] = n;
            }
            else if (i == 0 && j == 2)
            {
                sm[i][j] = nz;
            }
            else
            {
                if (j == 0)
                {
                    sm[i][j] = row[i - 1];
                }
                else if (j == 1)
                {
                    sm[i][j] = col[i - 1];
                }
                else if (j == 2)
                {
                    sm[i][j] = val[i - 1];
                }
            }
        }
    }
    for (int i = 0; i < nz + 1; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << sm[i][j] << ", ";
        }
        cout << endl;
    }

    return 0;
}