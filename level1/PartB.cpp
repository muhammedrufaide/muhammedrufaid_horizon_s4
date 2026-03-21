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
    cout << "Enter initial velocity: ";
    cin >> u;
    cout << "Enter acceleration: ";
    cin >> a;
    cout << "Enter maximum speed: ";
    cin >> vmax;
    double t_acc = (vmax - u) / a;
    double d_acc = u * t_acc + 0.5 * a * pow(t_acc, 2);
    double total_time;
    if (d_acc >= distance)
    {
        double A = 0.5 * a;
        double B = u;
        double C = -distance;
        total_time = (-B + sqrt(B*B - 4*A*C)) / (2*A);
    }
    else
    {
        double remaining_distance = distance - d_acc;
        double t_const = remaining_distance / vmax;
        total_time = t_acc + t_const;
    }
    cout << "\nDistance: " << distance << " meters";
    cout << "\nTime required: " << total_time << " seconds";
    return 0;
}