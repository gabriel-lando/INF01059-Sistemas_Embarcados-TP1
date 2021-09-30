// C program to multiply two square matrices. 

#define N 4 

// This function multiplies mat1[][] and mat2[][],
// and stores the result in res[][] 

void multiply(int mat1[][N], int mat2[][N], int res[][N])
{
    int i, j, k;
    for (i = 0; i < N; i++)
        for (k = 0; k < N; k++)
            for (j = 0; j < N; j++)
                res[i][j] = res[i][j] + mat1[i][k]*mat2[k][j];
} 

int main()
{
    int mat1[N][N] = {{ 51, 87, 59, 16},
                    { 69, 94, 48, 41 },
                    { 44, 99, 90, 2},
                    { 56, 65, 23, 30 }};

    int mat2[N][N] = {{ 18, 3, 64, 48 },
                    { 28, 98, 5, 68 },
                    { 75, 44, 88, 46 },
                    { 52, 18, 63, 66 }};

    int res[N][N] = { 0 }; // To store result

    multiply(mat1, mat2, res); 

    return 0; 
}
