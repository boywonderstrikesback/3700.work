
#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;




void copyMatrix1  (float dest[N][N], 
             const float original[N][N])
{
int row, col;
for (row = 0;  row < N; row++)
    for (col = 0; col < N; col++)
          dest [row][col] = original[row][col];
}


void copyMatrix2  (float dest[N][N], 
                const float original[N][N])
{
int row, col;
for (col = 0;  col < N; col++)
    for (row = 0; row < N; row++)
          dest [row][col] = original[row][col];
}