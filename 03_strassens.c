#include <stdio.h>

void add(int A[2][2], int B[2][2], int C[2][2]) {
    int i, j;
    for(i=0;i<2;i++)
        for(j=0;j<2;j++)
            C[i][j] = A[i][j] + B[i][j];
}

void sub(int A[2][2], int B[2][2], int C[2][2]) {
    int i, j;
    for(i=0;i<2;i++)
        for(j=0;j<2;j++)
            C[i][j] = A[i][j] - B[i][j];
}

/* Strassen multiplication of two 2x2 matrices */
void strassen2(int A[2][2], int B[2][2], int C[2][2]) {
    int p1,p2,p3,p4,p5,p6,p7;

    p1 = (A[0][0]+A[1][1]) * (B[0][0]+B[1][1]);
    p2 = (A[1][0]+A[1][1]) * B[0][0];
    p3 = A[0][0] * (B[0][1]-B[1][1]);
    p4 = A[1][1] * (B[1][0]-B[0][0]);
    p5 = (A[0][0]+A[0][1]) * B[1][1];
    p6 = (A[1][0]-A[0][0]) * (B[0][0]+B[0][1]);
    p7 = (A[0][1]-A[1][1]) * (B[1][0]+B[1][1]);

    C[0][0] = p1+p4-p5+p7;
    C[0][1] = p3+p5;
    C[1][0] = p2+p4;
    C[1][1] = p1-p2+p3+p6;
}

/* Strassen multiplication of two 4x4 matrices */
void strassen4(int A[4][4], int B[4][4], int C[4][4]) {
    int A11[2][2], A12[2][2], A21[2][2], A22[2][2];
    int B11[2][2], B12[2][2], B21[2][2], B22[2][2];
    int P[7][2][2], X[2][2], Y[2][2];
    int i,j;

    /* Divide matrices into four blocks */
    for(i=0;i<2;i++)
        for(j=0;j<2;j++) {
            A11[i][j]=A[i][j];
            A12[i][j]=A[i][j+2];
            A21[i][j]=A[i+2][j];
            A22[i][j]=A[i+2][j+2];

            B11[i][j]=B[i][j];
            B12[i][j]=B[i][j+2];
            B21[i][j]=B[i+2][j];
            B22[i][j]=B[i+2][j+2];
        }

    /* Calculate seven products */
    add(A11,A22,X);
    add(B11,B22,Y);
    strassen2(X,Y,P[0]);

    add(A21,A22,X);
    strassen2(X,B11,P[1]);

    sub(B12,B22,Y);
    strassen2(A11,Y,P[2]);

    sub(B21,B11,Y);
    strassen2(A22,Y,P[3]);

    add(A11,A12,X);
    strassen2(X,B22,P[4]);

    sub(A21,A11,X);
    add(B11,B12,Y);
    strassen2(X,Y,P[5]);

    sub(A12,A22,X);
    add(B21,B22,Y);
    strassen2(X,Y,P[6]);

    /* Combine the seven products */
    for(i=0;i<2;i++)
        for(j=0;j<2;j++) {
            C[i][j] = P[0][i][j]+P[3][i][j]
                    -P[4][i][j]+P[6][i][j];

            C[i][j+2] = P[2][i][j]+P[4][i][j];

            C[i+2][j] = P[1][i][j]+P[3][i][j];

            C[i+2][j+2] = P[0][i][j]-P[1][i][j]
                        +P[2][i][j]+P[5][i][j];
        }
}

int main() {
    int A[4][4], B[4][4];
    int C[4][4], D[4][4];
    int i,j,k,sum;

    printf("Enter first 4x4 matrix:\n");
    for(i=0;i<4;i++)
        for(j=0;j<4;j++)
            scanf("%d",&A[i][j]);

    printf("Enter second 4x4 matrix:\n");
    for(i=0;i<4;i++)
        for(j=0;j<4;j++)
            scanf("%d",&B[i][j]);

    /* Strassen multiplication */
    strassen4(A,B,C);

    /* Traditional multiplication */
    for(i=0;i<4;i++) {
        for(j=0;j<4;j++) {
            sum=0;
            for(k=0;k<4;k++)
                sum += A[i][k]*B[k][j];
            D[i][j]=sum;
        }
    }

    printf("\nStrassen Result:\n");
    for(i=0;i<4;i++) {
        for(j=0;j<4;j++)
            printf("%d ",C[i][j]);
        printf("\n");
    }

    printf("\nTraditional Result:\n");
    for(i=0;i<4;i++) {
        for(j=0;j<4;j++)
            printf("%d ",D[i][j]);
        printf("\n");
    }

    printf("\nStrassen multiplications = 49");
    printf("\nTraditional multiplications = 64\n");

    return 0;
}