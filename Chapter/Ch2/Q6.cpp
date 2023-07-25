#include <iostream>
using namespace std ; 
class temp
{
    float cel , f; 
    public : 
        void getdata()
        {
           cout << "Enter temp : ";
           cin >> cel ; 
        }

        float convert()
        {
            
            f = ((cel * 9) / 5) + 32;
            return f ; 
        }
        void displaydata()
        {
            cout << "The temperature in c scale is " << cel << " and the tem in f scale is "<< f ;
        }
};

int main()
{
    temp t ; 
    t.getdata();
    t.convert();
    t.displaydata();
    
}
