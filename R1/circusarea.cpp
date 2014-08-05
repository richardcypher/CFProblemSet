#include<iostream>
#include<cmath>

using namespace std;

#define PI 3.14159265358979323846 
#define eps 1e-4
//calculate the area of the circumradius 

double getS(int n, double r) {
    return 0.5 * n * sin(2*PI/n)* r * r;
}

double gcd(double x, double y) {
    while(fabs(y) > eps) {
        double tmp = y;
        int times = (int) (x / y);
        y = x - y * times;
        x = tmp;
    }
    return x;
}

int main()
{
    double x1,y1,x2,y2,x3,y3;
    cin>>x1>>y1>>x2>>y2>>x3>>y3;
    double a = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2) * (y1 - y2));
    double b = sqrt((x1 - x3)*(x1 - x3) + (y1 - y3) * (y1 - y3));	
    double c = sqrt((x3 - x2)*(x3 - x2) + (y3 - y2) * (y3 - y2));
    double p = (a + b + c ) / 2;
    double St = sqrt(p * (p - a) * (p - b) * (p - c));//triangle area
    double r = a * b * c / (4 * St);

    double angle_a = acos((b * b + c * c -  a * a) / (2 * b * c));
    double angle_b = acos((a * a + c * c -  b * b) / (2 * a * c));
    double angle_c = acos((b * b + a * a -  c * c) / (2 * b * a));

    double angle_polygon = gcd(gcd(angle_a, angle_b), angle_c);
    int n = static_cast<int>(PI / angle_polygon);
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(6);
    cout<<getS(n, r)<<endl;
}
