/*   Write a function that recieves two matrix objects as arguments and 
     returns new matrix object containing their multiplication result.
*/

#include <iostream>
using namespace std;
class matrix
{
    int m[3][3] ;
    public :
    void read()
    {
        for (int i = 0 ; i < 3 ; i++)
        {
            for(int j=0;j<3;j++)
            {
                cout << "Enter the matrix["<<i<<"]["<<j<<"] : ";
                cin>>m[i][j];
            }
        }
    }
    void display()
    {
        for (int i = 0 ; i < 3 ; i++)
        {
            for(int j=0;j<3;j++)
            {
                cout << "\t**************** The matrix is ****************\n";
                cout << "\t"<< m[i][j] ;
            }
            cout << "\n" ; 
        }
    }
    friend class multiplyMatrix ;
};
