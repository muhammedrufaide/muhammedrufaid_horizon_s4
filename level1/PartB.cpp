#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    double x1, y1, x2, y2;
    double u, a, vmax;
    cout << "Enter origin coordinates (x1 y1): ";
    cin >> x1 >> y1;
    cout << "Enter destination coordinates (x2 y2): ";
    cin >> x2 >> y2;
    double distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    cout << "Distance the rover must travel: " << distance << " meters\n";
    cout << "Enter initial velocity: ";
    cin >> u;
    cout << "Enter acceleration: ";
    cin >> a;
    cout << "Enter maximum speed: ";
    cin >> vmax;
    double A = 0.5 * a;
    double B = u;
    double C = -distance;
    double discriminant = B*B - 4*A*C;
    double time = (-B + sqrt(discriminant)) / (2*A);
    cout << "Time required: " << time << " seconds";
    return 0;
}