/*










*/



#include <iostream>
#include <cmath>
using namespace std;

class Polar
{
private:
    float r , a , x , y  ; 
public:
    Polar();
    Polar(float rad,float deg,float x_cord,float y_cord);
    void getInput();
    void display_pol();
    void conv_rect();
    void display_rect();
    Polar operator+(Polar);
    void conv_pol();
};

Polar::Polar()
{
    r=0;
    a=0;
    x=0;
    y=0;
}

Polar::Polar(float rad,float deg,float x_cord,float y_cord)
{
    r = rad ; 
    a= deg;
    x=x_cord;
    y=y_cord;
}

void Polar::getInput()
{
    cout << "Enter radius : ";
    cin >> r ; 
}

void Polar:: display_pol()
{
    cout << "The Polar cordinates are : ( " << r << " , " << a << " )" ; 
}

void Polar:: conv_rect()
{
    x = r*cos(a); 
    y = r*sin(a); 
}

void Polar:: display_rect()
{
    cout << "The Rectangular cordinates are : ( " << x << " , " << y << " )" <<endl ; 
}

Polar Polar:: operator+(Polar p)
{
    Polar sum ; 
    sum.x = x + p.x ; 
    sum.y = y + p.y ; 
    sum.conv_pol(); // Convert the sum to polar coordinates
    return sum;
}

void Polar:: conv_pol()
{
    a = tan(y/x);
    r = sqrt(x*x + y*y);
}

int main()
{
    Polar p1 , p2 , p3 ; 
    p1.getInput();
    p1.conv_rect();
    p1.display_pol();
    p1.display_rect();
    p2.getInput();
    p2.conv_rect();
    p2.display_pol();
    p2.display_rect();
    p3 = p1 + p2 ; 
    p3.display_pol(); 
    return 0 ; 
}

