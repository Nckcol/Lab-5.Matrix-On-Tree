// MatrixOnTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Matrix.h"

int main()
{
    Matrix<int> m(10, 10);

    m[5][3] = 2;
    m[1][0] = 1;
    m[9][9] = 1;

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
            cout << m[i][j] << " ";
        cout << endl;
    }

    return 0;
}

