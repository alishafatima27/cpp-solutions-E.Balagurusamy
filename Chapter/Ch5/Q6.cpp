/*   Write a function that recieves two matrix objects as arguments and 
     returns new matrix object containing their multiplication result.
*/

/* Approach for the question : 

   Let's say we have two matrices, A and B:
| 1  2  3 |      
| 4  5  6 |
| 7  8  9 |
     and 
| 9  8  7 |
| 6  5  4 |
| 3  2  1 |
We analyse that when we multiply A*B :
C[i][j] = A[i][0]*B[0][j] + A[i][1]*B[1][j] + A[i][2]*B[2][j]

 So For each element in the resulting matrix:
    - Loop through the rows of the first matrix.
    - Loop through the columns of the second matrix.
    - Within each combination of row and column, use another loop to go through elements for multiplication and addition.
    The code uses three nested loops (i, j, and k) to iterate through the matrices and calculate the resulting matrix element.
*/ 


#include <iostream>
using namespace std;

class matrix
{
    int m[3][3];

public:
    matrix()
    {
         for(int i = 0 ; i < 3 ; i++)
              {
                  for(int j = 0 ; j < 3 ; j++)
                       {
                            m[i][j]=0;
                       }
              }
    }
     
    void read()
    {
        cout << "Enter the matrix:" << endl;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << "Enter element [" << i << "][" << j << "]: ";
                cin >> m[i][j];
            }
        }
    }

    void display()
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << "\t" << m[i][j];
            }
            cout << endl;
        }
    }

    friend matrix multiplyMatrix(const matrix &m1, const matrix &m2);
};

/*
     Using reference variables in the program allows the multiplication function 
     to work directly with the original matrices, avoiding errors, 
     unintended behavior, and performance issues associated with passing by value.
     Not using it would give us garbage value as the changes brought would not be 
     reflected in the main function 
*/ 
matrix multiplyMatrix(const matrix &m1, const matrix &m2) 
{
    matrix result;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                result.m[i][j] += m1.m[i][k] * m2.m[k][j];
            }
        }
    }
    return result;
}

int main()
{
    matrix m1, m2; // object creation of the matrix 
    cout << "Enter values for the first matrix:" << endl;
    m1.read();
    cout << "Enter values for the second matrix:" << endl;
    m2.read();

    cout << "\nFirst Matrix:" << endl;
    m1.display();

    cout << "\nSecond Matrix:" << endl;
    m2.display();

    matrix result = multiplyMatrix(m1, m2);

    cout << "\nMatrix Multiplication Result:" << endl;
    result.display();

    return 0;
}
