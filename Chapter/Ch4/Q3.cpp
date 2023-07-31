// Rewrite the program of Exercise 4.2 to make the row parameter of the matrix as a default argument.
/*
Approach for the proble : 
    1) Ask for Row Size Input:
    2) Check for Valid Row Size:
          if the input operation fails (returns false) or if the value entered is not valid (e.g., negative or greater than 10 or char ).
          If either of these conditions is true, it means the user did not provide a valid row size.
    In such cases, set the row size (m) to the default value (e.g., 10).
*/ 

#include <iostream>
#include <iomanip>
using namespace std;

// Function to read the matrix from the user
void matrix_read(int col, int matrix[][10], int row = 10)
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

    // Ask the user to input the number of rows and columns for the matrix
    cout << "Enter the number of rows in the matrix (or press Enter to use default - 10): ";

    // Try reading the row size
    /* If the user inputs any other character for the row size, 
      or provides a row size greater than 10, the row size will be set to the default value of 10.
    */
    if (!(cin >> m) || m <= 0 || m > 10)
    {
        m = 10; // Set m to default value of 10 if user didn't input a valid row size
        cin.clear();                // Clear error flags from cin
    }

    cout << "Enter the number of columns in the matrix: ";
    cin >> n;

    int matrix[10][10]; // Assuming a maximum size of 10x10 for the matrix

    // Check if user input exceeds the assumed maximum size
    if (n > 10)
    {
        cout << "Error: Maximum column size exceeded. Please enter a column size up to 10." << endl;
        return 1; // Exit the program with an error code
    }

    // Call the function to read the matrix from the user
    matrix_read(n, matrix, m);

    // Call the function to display the matrix on the screen
    matrix_display(m, n, matrix);

    return 0;
}
