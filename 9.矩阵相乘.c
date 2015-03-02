/*
(9)代码实现两个矩阵相乘

应该不是要求的那样~~不太会矩阵 ~_~
*/


void multiply(a[m][n],b[n][p],c[m][p])
{
    int i,j,k;
    int sum;
    for(i=0; i<m; i++)
        for(j=0; j<p; j++)
        {
            c[i][j]=0;
            for(k=0; k<n; k++)
                c[i][j]+=a[i][k]*b[k][j];
        }
}
