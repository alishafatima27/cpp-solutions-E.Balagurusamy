/*  Create a class MAT of size m x n.
    Define all possible matrix operations for MAT type objects.
*/


#include <iostream>
using namespace std;

class MAT {
private:
    int rows;
    int cols;
    int data[100][100];  // Assuming a maximum matrix size of 100x100

public:
    MAT(int m, int n);
    void inputMatrix();
    void displayMatrix();
    MAT operator+(const MAT &other);
    MAT operator-(const MAT &other);
    MAT operator*(const MAT &other);
};

MAT::MAT(int m, int n) {
    rows = m;
    cols = n;
}

void MAT::inputMatrix() {
    std::cout << "Enter matrix elements:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> data[i][j];
        }
    }
}

void MAT::displayMatrix() {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << data[i][j] << " ";
        }
        cout << std::endl;
    }
}

MAT MAT::operator+(const MAT &other) {
    MAT result(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result.data[i][j] = data[i][j] + other.data[i][j];
        }
    }
    return result;
}

MAT MAT::operator-(const MAT &other) {
    MAT result(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result.data[i][j] = data[i][j] - other.data[i][j];
        }
    }
    return result;
}

MAT MAT::operator*(const MAT &other) {
    MAT result(rows, other.cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < other.cols; ++j) {
            result.data[i][j] = 0;
            for (int k = 0; k < cols; ++k) {
                result.data[i][j] += data[i][k] * other.data[k][j];
            }
        }
    }
    return result;
}

int main() {
    int m, n;
    cout << "Enter number of rows : ";
    cin >> m;

    cout << "Enter number of columns : ";
    cin >> n;

    MAT mat1(m, n);
    MAT mat2(m, n);

    cout << "Enter elements for matrix 1:\n";
    mat1.inputMatrix();

    std::cout << "Enter elements for matrix 2:\n";
    mat2.inputMatrix();

    MAT sum = mat1 + mat2;
    MAT diff = mat1 - mat2;

    cout << "Matrix 1:\n";
    mat1.displayMatrix();

    cout << "Matrix 2:\n";
    mat2.displayMatrix();

    :cout << "Sum:\n";
    sum.displayMatrix();

    cout << "Difference:\n";
    diff.displayMatrix();

    return 0;
}

