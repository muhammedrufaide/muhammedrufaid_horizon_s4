#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    double x1, y1, x2, y2;
    double u, a, vmax;
    cout << "Enter origin coordinates (x1 y1): ";
    if(!(cin >> x1 >> y1))
    {
        cout << "Invalid input for origin";
        return 0;
    }
    cout << "Enter destination coordinates (x2 y2): ";
    if(!(cin >> x2 >> y2))
    {
        cout << "Invalid input for destination";
        return 0;
    }
    double distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    cout << "Distance the rover must travel: " << distance << " meters\n";
    cout << "Enter initial velocity: ";
    cin >> u;
    cout << "Enter acceleration: ";
    cin >> a;
    cout << "Enter maximum speed: ";
    cin >> vmax;
    if(a <= 0)
    {
        cout << "Acceleration must be greater than 0";
        return 0;
    }
    double A = 0.5 * a;
    double B = u;
    double C = -distance;
    double discriminant = B*B - 4*A*C;
    if(discriminant < 0)
    {
        cout << "No real solution for time";
        return 0;
    }
    double time = (-B + sqrt(discriminant)) / (2*A);
    cout << "Time required: " << time << " seconds";
    return 0;
}