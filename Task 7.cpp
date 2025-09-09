#include <bits/stdc++.h>
using namespace std;

const int MAX = 8;

void naiveMultiply(int n, int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX]) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
}

void add(int n, int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX]) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
}

void subtract(int n, int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX]) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
}

void strassen(int n, int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX]) {
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int k = n / 2;
    int A11[MAX][MAX], A12[MAX][MAX], A21[MAX][MAX], A22[MAX][MAX];
    int B11[MAX][MAX], B12[MAX][MAX], B21[MAX][MAX], B22[MAX][MAX];
    int M1[MAX][MAX], M2[MAX][MAX], M3[MAX][MAX], M4[MAX][MAX];
    int M5[MAX][MAX], M6[MAX][MAX], M7[MAX][MAX];
    int T1[MAX][MAX], T2[MAX][MAX];

    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + k];
            A21[i][j] = A[i + k][j];
            A22[i][j] = A[i + k][j + k];
            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + k];
            B21[i][j] = B[i + k][j];
            B22[i][j] = B[i + k][j + k];
        }

    add(k, A11, A22, T1); add(k, B11, B22, T2); strassen(k, T1, T2, M1);
    add(k, A21, A22, T1); strassen(k, T1, B11, M2);
    subtract(k, B12, B22, T1); strassen(k, A11, T1, M3);
    subtract(k, B21, B11, T1); strassen(k, A22, T1, M4);
    add(k, A11, A12, T1); strassen(k, T1, B22, M5);
    subtract(k, A21, A11, T1); add(k, B11, B12, T2); strassen(k, T1, T2, M6);
    subtract(k, A12, A22, T1); add(k, B21, B22, T2); strassen(k, T1, T2, M7);

    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++)
            C[i][j] = M1[i][j] + M4[i][j] - M5[i][j] + M7[i][j];

    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++)
            C[i][j + k] = M3[i][j] + M5[i][j];

    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++)
            C[i + k][j] = M2[i][j] + M4[i][j];

    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++)
            C[i + k][j + k] = M1[i][j] + M3[i][j] - M2[i][j] + M6[i][j];
}

void printMatrix(int n, int M[MAX][MAX]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << M[i][j] << " ";
        cout << "\n";
    }
}

int main() {
    int C[MAX][MAX];

    int A2[2][2] = {{1, 2}, {3, 4}};
    int B2[2][2] = {{5, 6}, {7, 8}};
    cout << "Naive 2x2:\n";
    naiveMultiply(2, A2, B2, C);
    printMatrix(2, C);
    cout << "Strassen 2x2:\n";
    strassen(2, A2, B2, C);
    printMatrix(2, C);

    int A4[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}};
    int B4[4][4] = {
        {16, 15, 14, 13},
        {12, 11, 10, 9},
        {8, 7, 6, 5},
        {4, 3, 2, 1}};
    cout << "\nNaive 4x4:\n";
    naiveMultiply(4, A4, B4, C);
    printMatrix(4, C);
    cout << "Strassen 4x4:\n";
    strassen(4, A4, B4, C);
    printMatrix(4, C);

    return 0;
}
