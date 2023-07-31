// Write a program to read a matrix of size m x n from the keyboard and display the same on the screen using functions.

#include <iostream>
#include <iomanip>
using namespace std;

// Function to read the matrix from the user
void matrix_read(int row, int col, int matrix[][10])
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << "Enter the Matrix[" << i + 1 << "][" << j + 1 << "] : ";
            cin >> matrix[i][j];
        }
    }
}

// Function to display the matrix on the screen
void matrix_display(int row, int col, int matrix[][10])
{
    cout << "\n\n\t-----------The matrix is-------------\n\n";
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << "\t" << matrix[i][j] << setw(5);
        }
        cout << endl;
    }
}

int main()
{
    int m, n;

    // input the number of rows and columns for the matrix
    cout << "Enter the number of rows in the matrix: ";
    cin >> m;
    cout << "Enter the number of columns in the matrix: ";
    cin >> n;

    int matrix[10][10]; // Assuming a maximum size of 10x10 for the matrix
 /*
  Note: We are assuming a maximum size of 10x10 for the matrix to simplify the code.As it will give error if size of array is not know 
      at the time of compilation. 
*/ 

    // Check if user input exceeds the assumed maximum size
    if (m > 10 || n > 10)
    {
        cout << "Error: Maximum size exceeded. Please enter a size up to 10x10." << endl;
        return 1; // Exit the program with an error code
    }

    // function call to read the matrix from the user
    matrix_read(m, n, matrix);

    // function call to display the matrix on the screen
    matrix_display(m, n, matrix);

    return 0;
}
