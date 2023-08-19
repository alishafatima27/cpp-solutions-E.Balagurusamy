/*  Create a class MAT of size m x n.
    Define all possible matrix operations for MAT type objects.
*/

/*Approach : creating array of size for e.g 
                array[100][100] 
             would lead to memory wastage, and not initializing it can lead to memory leak.
             So we use double pointer to dynamically allocate the memory while dealing with arrays of
             various size.
*/


#include <iostream>
using namespace std;

class MAT 
{
private:
    int rows;
    int cols;
    int **data;  // Dynamic memory allocation 

public:
    MAT(int m, int n);  // Constructor
    ~MAT();  // Destructor to free allocated memory
    void inputMatrix();
    void displayMatrix();
    bool checkAS(const MAT &other);  // Check condition for Addition and Subtraction
    bool check(const MAT &other);     // Check condition for multiplication
    MAT operator+(const MAT &other);  // Matrix addition
    MAT operator-(const MAT &other);  // Matrix subtraction
    MAT operator*(const MAT &other);  // Matrix multiplication
};

// Constructor
MAT::MAT(int m, int n) 
{
    rows = m;
    cols = n;
    data = new int*[rows];
    for (int i = 0; i < rows; ++i) 
    {
        data[i] = new int[cols];
    }
}

// Destructor
MAT::~MAT() {
    for (int i = 0; i < rows; ++i) 
    {
        delete[] data[i];
    }
    delete[] data;
}

// Input matrix elements
void MAT::inputMatrix() {
    cout << "\nEnter matrix elements:\n";
    for (int i = 0; i < rows; ++i) 
    {
        for (int j = 0; j < cols; ++j) 
        {
            cout << "Enter matrix[" << i + 1 << "][" << j + 1 << "] : ";
            cin >> data[i][j];
        }
    }
}

// Display matrix elements
void MAT::displayMatrix() 
{
    for (int i = 0; i < rows; ++i) 
    {
        for (int j = 0; j < cols; ++j) 
        {
            cout << data[i][j] << "    ";
        }
        cout << endl;
    }
}

// Check condition for valid Addition and Subtraction
bool MAT::checkAS(const MAT &other) 
{
    if (rows == other.rows && cols == other.cols) 
    {
        return true;
    } else 
    {
        return false;
    }
}

// Matrix addition
MAT MAT::operator+(const MAT &other) 
{
    MAT result(rows, cols);
    for (int i = 0; i < rows; ++i) 
    {
        for (int j = 0; j < cols; ++j) 
        {
            result.data[i][j] = data[i][j] + other.data[i][j];
        }
    }
    return result;
}

// Matrix subtraction
MAT MAT::operator-(const MAT &other) 
{
    MAT result(rows, cols);
    for (int i = 0; i < rows; ++i) 
    {
        for (int j = 0; j < cols; ++j) 
        {
            result.data[i][j] = data[i][j] - other.data[i][j];
        }
    }
    return result;
}

// Check condition for valid multiplication
bool MAT::check(const MAT &mat2) 
{
    if (cols != mat2.rows) 
    {
        return false;
    } else 
    {
        return true;
    }
}

// Matrix multiplication
MAT MAT::operator*(const MAT &other) 
{
    MAT result(rows, other.cols);
    for (int i = 0; i < rows; ++i) 
    {
        for (int j = 0; j < other.cols; ++j) 
        {
            result.data[i][j] = 0;
            for (int k = 0; k < cols; ++k) 
            {
                result.data[i][j] += data[i][k] * other.data[k][j];
            }
        }
    }
    return result;
}

int main() {
    int m, n, x, y;
    cout << "Enter number of rows of matrix 1 : ";
    cin >> m;

    cout << "Enter number of columns of matrix 1 : ";
    cin >> n;

    MAT mat1(m, n);
    
    cout << "\nEnter elements for matrix 1:\n";
    mat1.inputMatrix();

    cout << "\nEnter number of rows of matrix 2 : ";
    cin >> x;

    cout << "Enter number of columns of matrix 2 : ";
    cin >> y;
    MAT mat2(x, y);
    
    cout << "\nEnter elements for matrix 2:\n";
    mat2.inputMatrix();

    cout << "\nMatrix 1 :\n";
    mat1.displayMatrix();

    cout << "\nMatrix 2 :\n";
    mat2.displayMatrix();

    if (mat1.checkAS(mat2) == true) 
    {
        // Matrix addition and subtraction
        MAT sum = mat1 + mat2;
        MAT diff = mat1 - mat2;

        cout << "\nSum:\n";
        sum.displayMatrix();

        cout << "\nDifference:\n";
        diff.displayMatrix();
    } else {
        cout << "\nMatrix Addition and Subtraction not possible!\n";
    }

    if (mat1.check(mat2)==true) 
    {
        // Matrix multiplication
        MAT product = mat1 * mat2;

        cout << "\nProduct:\n";
        product.displayMatrix();
    } else 
    {
        cout << "\nMatrix multiplication not possible!\n";
    }

    return 0;
}
