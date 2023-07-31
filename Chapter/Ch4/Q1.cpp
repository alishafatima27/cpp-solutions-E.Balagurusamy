//Write a function to read a matrix of size m x n from the keyboard.

/* Appraoch to solve the problem : 
  Let's say we want 2 rows and 3 columns. So, we draw a 2x3 matrix on the paper.
  We write the first number in first row of first column. 
  Then second number,in the second column of first row and so on, until all rows are filled.
  We do this for each column, row by row, until we have written all the numbers in the matrix.

  We use outer loop for the iteration of rows and inside that loop we create another loop for iteration of columns.
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int m, n;

    // Input the size of the row of the matrix
    cout << "Enter the size of the row of the matrix: ";
    cin >> m;

    // Input the size of the column of the matrix
    cout << "Enter the size of the column of the matrix: ";
    cin >> n;

    // Declaring the matrix with given row and column size as a 2-d array 
    int matrix[m][n];

    // Input elements into the matrix
    for (int i = 0; i < m; i++) // Outer loop will iterate the number of rows 
    {
        for (int j = 0; j < n; j++) // Inner loop will iterate the number of columns 
        {
            cout << "Enter the Matrix[" << i + 1 << "][" << j + 1 << "]: ";
            cin >> matrix[i][j];
        }
    }

    // Displaying the input matrix
    cout << "\n\n\t-----------The matrix is-------------\n\n";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "\t" << matrix[i][j] << setw(5); // setw sets the width and is defined in iomanip library 
        }
        cout << endl;
    }

    return 0;
}

