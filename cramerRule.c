#include <stdio.h>
#include <math.h>

#define MAX 100

double M[MAX][MAX];  // matrix
bool DR[MAX];        // row that has been deleted
int row, col;        // maxrow, maxcol
int sub;             // col to be substituted

double _det(double A[MAX][MAX], int c)
{
    if (c == col) return 1;
    double sum = 0;
    for(int i=0, t=1;i<row;++i) if (!DR[i]) {
        DR[i] = true;
        sum += t * A[i][(c==sub)?col:c] * _det(A, c+1);
        DR[i] = false;
        t*=-1;
    }
    return sum;
}

int main()
{
    FILE *fp = fopen("input.txt", "r");
    fscanf(fp, "%d%d", &row, &col);
    for(int i=0;i<row;++i) {
        for(int j=0;j<col;++j) {
            fscanf(fp, "%lf", &M[i][j]);
        }
    }
    fclose(fp);

    col--;
    sub = col;
    double denominator = _det(M, 0);

    fp = fopen("output.txt", "w");
    for(sub=0;sub<row;++sub)
        fprintf(fp, "%.2lf\n", floor(_det(M, 0)/denominator*100+0.5)/100);
    fclose(fp);
    return 0;
}
