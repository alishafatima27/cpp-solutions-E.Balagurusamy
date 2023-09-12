// Write a program that illustrates the application of multiple catch statements.


#include <iostream>
using namespace std;

void test(int x)
{
    try
    {
        if (x == 1)
            throw x;
        else
        {
            if (x == 0)
                throw 'x';
        }
        cout << "End of try block\n";
    }
    catch (char c)
    {
        cout << "Caught a character!\n";
    }
    catch (int m)
    {
        cout << "Caught an Integer!\n";
    }
    catch (double d)
    {
        cout << "Caught a Double!\n";
    }
    catch (...)
    {
        cout << "Caught an unknown exception!\n";
    }
    cout << "End of try-catch system \n\n";
}

int main()
{
    cout << "Testing multiple catches \n";
    cout << "x==1\n";
    test(1);
    cout << "x==0\n";
    test(0);
    cout << "x==-1\n";
    test(-1);
    cout << "x==2\n";
    test(2);
    return 0;
}
