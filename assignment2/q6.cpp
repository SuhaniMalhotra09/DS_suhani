Q6.//Write a program to implement the following operations on a Sparse Matrix, assuming the
//matrix is represented using a triplet.
//(a) Transpose of a matrix.
//(b) Addition of two matrices.
//(c) Multiplication of two matrices.

  #include <iostream>
using namespace std;

#define MAX 50   // define maximum size

// ---------- Transpose ----------
void transpose(int mat[MAX][3], int trans[MAX][3]) {
    int k = mat[0][2]; 
    trans[0][0] = mat[0][1];
    trans[0][1] = mat[0][0];
    trans[0][2] = k;

    int q = 1;
    for (int col = 0; col < mat[0][1]; col++) {
        for (int p = 1; p <= k; p++) {
            if (mat[p][1] == col) {
                trans[q][0] = mat[p][1];
                trans[q][1] = mat[p][0];
                trans[q][2] = mat[p][2];
                q++;
            }
        }
    }
}

// ---------- Addition ----------
void addSparse(int a[MAX][3], int b[MAX][3], int c[MAX][3]) {
    if (a[0][0] != b[0][0] || a[0][1] != b[0][1]) {
        cout << "Addition not possible\n";
        return;
    }

    int i = 1, j = 1, k = 1;
    while (i <= a[0][2] && j <= b[0][2]) {
        if (a[i][0] < b[j][0] || (a[i][0] == b[j][0] && a[i][1] < b[j][1])) {
            c[k][0] = a[i][0]; c[k][1] = a[i][1]; c[k][2] = a[i][2];
            i++; k++;
        }
        else if (b[j][0] < a[i][0] || (a[i][0] == b[j][0] && b[j][1] < a[i][1])) {
            c[k][0] = b[j][0]; c[k][1] = b[j][1]; c[k][2] = b[j][2];
            j++; k++;
        }
        else {
            int sum = a[i][2] + b[j][2];
            if (sum != 0) {
                c[k][0] = a[i][0]; c[k][1] = a[i][1]; c[k][2] = sum;
                k++;
            }
            i++; j++;
        }
    }
    while (i <= a[0][2]) {
        c[k][0] = a[i][0]; c[k][1] = a[i][1]; c[k][2] = a[i][2];
        i++; k++;
    }
    while (j <= b[0][2]) {
        c[k][0] = b[j][0]; c[k][1] = b[j][1]; c[k][2] = b[j][2];
        j++; k++;
    }

    c[0][0] = a[0][0];
    c[0][1] = a[0][1];
    c[0][2] = k - 1;
}

// ---------- Multiplication ----------
void multiply(int a[MAX][3], int b[MAX][3], int c[MAX][3]) {
    if (a[0][1] != b[0][0]) {
        cout << "Multiplication not possible\n";
        return;
    }

    int r = a[0][0], ccols = b[0][1];
    int temp[MAX][MAX] = {0};

    for (int i = 1; i <= a[0][2]; i++) {
        for (int j = 1; j <= b[0][2]; j++) {
            if (a[i][1] == b[j][0]) {
                temp[a[i][0]][b[j][1]] += a[i][2] * b[j][2];
            }
        }
    }

    c[0][0] = r;
    c[0][1] = ccols;
    int k = 1;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < ccols; j++) {
            if (temp[i][j] != 0) {
                c[k][0] = i;
                c[k][1] = j;
                c[k][2] = temp[i][j];
                k++;
            }
        }
    }
    c[0][2] = k - 1;
}

// ---------- Utility to print matrix ----------
void printMatrix(int mat[MAX][3]) {
    for (int i = 0; i <= mat[0][2]; i++)
        cout << mat[i][0] << " " << mat[i][1] << " " << mat[i][2] << endl;
}

// ---------- Main Menu ----------
int main() {
    int choice;
    cout << "Choose operation:\n1. Transpose\n2. Addition\n3. Multiplication\nEnter choice: ";
    cin >> choice;

    if (choice == 1) {
        int mat[MAX][3], trans[MAX][3];
        int rows, cols, num;
        cout << "Enter rows, cols and non-zero elements: ";
        cin >> rows >> cols >> num;
        mat[0][0] = rows; mat[0][1] = cols; mat[0][2] = num;
        cout << "Enter triplets:\n";
        for (int i = 1; i <= num; i++) cin >> mat[i][0] >> mat[i][1] >> mat[i][2];
        transpose(mat, trans);
        cout << "Transpose:\n";
        printMatrix(trans);
    }
    else if (choice == 2) {
        int a[MAX][3], b[MAX][3], c[MAX][3];
        int num1, num2;
        cout << "Enter rows cols and non-zero for A: ";
        cin >> a[0][0] >> a[0][1] >> num1;
        a[0][2] = num1;
        cout << "Enter triplets for A:\n";
        for (int i = 1; i <= num1; i++) cin >> a[i][0] >> a[i][1] >> a[i][2];

        cout << "Enter rows cols and non-zero for B: ";
        cin >> b[0][0] >> b[0][1] >> num2;
        b[0][2] = num2;
        cout << "Enter triplets for B:\n";
        for (int i = 1; i <= num2; i++) cin >> b[i][0] >> b[i][1] >> b[i][2];

        addSparse(a, b, c);
        cout << "Result of addition:\n";
        printMatrix(c);
    }
    else if (choice == 3) {
        int a[MAX][3], b[MAX][3], c[MAX][3];
        int num1, num2;
        cout << "Enter rows cols and non-zero for A: ";
        cin >> a[0][0] >> a[0][1] >> num1;
        a[0][2] = num1;
        cout << "Enter triplets for A:\n";
        for (int i = 1; i <= num1; i++) cin >> a[i][0] >> a[i][1] >> a[i][2];

        cout << "Enter rows cols and non-zero for B: ";
        cin >> b[0][0] >> b[0][1] >> num2;
        b[0][2] = num2;
        cout << "Enter triplets for B:\n";
        for (int i = 1; i <= num2; i++) cin >> b[i][0] >> b[i][1] >> b[i][2];

        multiply(a, b, c);
        cout << "Result of multiplication:\n";
        printMatrix(c);
    }
    else {
        cout << "Invalid choice!";
    }

    return 0;
}
