/*Write a program to evaluate the following investment equation
            V = P (1 + r)^n
and print the tables which would give the value of V for various combination of the following values of P, r and n:
       P: 1000, 2000, 3000, ...., 10,000
       r: 0.10, 0.11, 0.12, ...., 0.20
       n: 1, 2, 3, ...., 10

Hint: P is the principal amount and V is the value of money at the end of n years. This equation can be recursively written as
       V = P (1 + r)
       P = V
In other words, the value of money at the end of the first year becomes the principal amount for the next year, and so on.*/

#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int main()
{
    int V[10];
    const int P[10] = {1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000};
    const float r[10] = {0.10, 0.11, 0.12, 0.13, 0.14, 0.15, 0.16, 0.17, 0.18, 0.19};
    const int n[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    cout << setw(150) << "---------------------------------------------------------------------" << endl;
    cout << "Principle";
    for (int i = 0; i < 10; i++)
    {
        cout << setw(5) << "|" << "\t" << P[i] << "\t";
    }
    cout << "\n\n" << "Rate     ";
    for (int i = 0; i < 10; i++)
    {
        cout << setw(5) << "|" << "\t" << r[i] << "\t";
    }
    cout << "\n\n" << "Years    ";
    for (int i = 0; i < 10; i++)
    {
        cout << setw(5) << "|" << "\t" << n[i] << "\t";
    }
    cout << "\n\n" << "Value     ";
    for (int i = 0; i < 10; i++)
    {
        V[i] = P[i] * pow((1 + r[i]), n[i]);
        cout << setw(5) << "|" << "\t" << V[i] << "\t";
    }

    return 0;
}

/*    ------------------------------------------ Output will look something like this ------------------------------------------------
  
Principle    |  1000        |   2000        |   3000        |   4000        |   5000        |   6000        |   7000        |   8000        |   9000        |   10000

Rate         |  0.1         |   0.11        |   0.12        |   0.13        |   0.14        |   0.15        |   0.16        |   0.17        |   0.18        |   0.19

Years        |  1           |   2           |   3           |   4           |   5           |   6           |   7           |   8           |   9           |   10

Value        |  1100        |   2464        |   4214        |   6521        |   9627        |   13878       |   19783       |   28091       |   39919       |   56946

*/
