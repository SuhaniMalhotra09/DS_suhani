Q5.//Space required to store any two-dimensional array is number oƒ rows × number oƒ
//columns. Assuming array is used to store elements of the following matrices, implement an
//efficient way that reduces the space requirement.
//(a) Diagonal Matrix.
//(b) Tri-diagonal Matrix.
//(c) Lower triangular Matrix.
//(d) Upper triangular Matrix.
//(e) Symmetric Matrix

  #include <iostream>
using namespace std;

void diagonalMatrix() {
    int n;
    cout << "Enter size of matrix: ";
    cin >> n;

    int A[100];
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    cout << "\nDiagonal Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) cout << A[i] << " ";
            else cout << "0 ";
        }
        cout << endl;
    }
}

void triDiagonalMatrix() {
    int n;
    cout << "Enter size of matrix: ";
    cin >> n;

    int arr[100];
    cout << "Enter " << 3*n - 2 << " elements:\n";
    for (int i = 0; i < 3*n - 2; i++) {
        cin >> arr[i];
    }

    cout << "\nTri-diagonal Matrix:\n";
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j || i-j == 1 || j-i == 1)
                cout << arr[k++] << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
}

void lowerTriangularMatrix() {
    int n;
    cout << "Enter size of matrix: ";
    cin >> n;

    int total = n * (n + 1) / 2;
    int arr[100];
    cout << "Enter " << total << " elements:\n";
    for (int i = 0; i < total; i++) {
        cin >> arr[i];
    }

    cout << "\nLower Triangular Matrix:\n";
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j <= i) cout << arr[k++] << " ";
            else cout << "0 ";
        }
        cout << endl;
    }
}

void upperTriangularMatrix() {
    int n;
    cout << "Enter size of matrix: ";
    cin >> n;

    int total = n * (n + 1) / 2;
    int arr[100];
    cout << "Enter " << total << " elements:\n";
    for (int i = 0; i < total; i++) {
        cin >> arr[i];
    }

    cout << "\nUpper Triangular Matrix:\n";
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j >= i) cout << arr[k++] << " ";
            else cout << "0 ";
        }
        cout << endl;
    }
}

void symmetricMatrix() {
    int n;
    cout << "Enter size of matrix: ";
    cin >> n;

    int arr[100];
    cout << "Enter " << (n*(n+1))/2 << " elements:\n";
    for (int i = 0; i < n*(n+1)/2; i++) {
        cin >> arr[i];
    }

    int mat[20][20];
    int k = 0;

    // Fill upper triangle
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            mat[i][j] = arr[k++];
        }
    }

    // Copy to lower triangle
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            mat[i][j] = mat[j][i];
        }
    }

    cout << "\nSymmetric Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int choice;
    cout << "\nMatrix Representations:\n";
    cout << "1. Diagonal\n2. Tri-diagonal\n3. Lower Triangular\n4. Upper Triangular\n5. Symmetric\n";
    cout << "Enter choice: ";
    cin >> choice;

    switch(choice) {
        case 1: diagonalMatrix(); break;
        case 2: triDiagonalMatrix(); break;
        case 3: lowerTriangularMatrix(); break;
        case 4: upperTriangularMatrix(); break;
        case 5: symmetricMatrix(); break;
        default: cout << "Invalid choice!";
    }
    return 0;
}
