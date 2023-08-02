/* The effect of a default argument can be alternativcvely achieved by function overloading.Discuss with example */
/*  Ans : 
    By using function overloading,we can define different versions of the function with varying parameter lists, 
    where some parameters have default values. 
*/

#include <iostream>
#include <iomanip>
using namespace std;

// Function to read the matrix elements from the user
void matrix_read(int row, int col, int matrix[10][10])
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << "Enter the matrix[" << i + 1 << "][" << j + 1 << "] : ";
            cin >> matrix[i][j];
        }
    }
}

// Function to display the matrix on the screen
void matrix_display(int row, int col, int matrix[10][10])
{
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
    cout << "\t-----Note: Enter the row and column size greater than 2 to see the effect of function overloading------\n"
         << endl;
    cout << "Enter the size of Row: ";
    cin >> m;
    cout << "Enter the size of Column: ";
    cin >> n;

    // Check for valid row and column sizes
    if (m <= 0 || n <= 0 || m > 10 || n > 10)
    {
        cout << "Invalid row or column size. Setting row and column size to default (2x2)." << endl;
        m = 2;
        n = 2;
    }

    int matrix[10][10]; // Assuming max matrix size since it cannot be passed into a function if size is not declared
    matrix_read(m, n, matrix);

    cout << "\t-------------Original matrix entered by the user-------------\n\n";
    matrix_display(m, n, matrix);

    cout << "\t-------------Matrix displayed through function overloading to show only up to the second column of each row-------------\n\n";
    matrix_display(m, 2, matrix); // Function overloading to display only up to the second column of each row
    return 0;
}
