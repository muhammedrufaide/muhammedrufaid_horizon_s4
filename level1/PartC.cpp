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
        cout << "Invalid origin input";
        return 0;
    }
    cout << "Enter destination coordinates (x2 y2): ";
    if(!(cin >> x2 >> y2))
    {
        cout << "Invalid destination input";
        return 0;
    }
    double distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
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
    if(vmax < u)
    {
        cout << "Max speed must be >= initial velocity";
        return 0;
    }
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
    cout << "\nDistance to destination: " << distance << " m";
    cout << "\nTime required: " << total_time << " seconds";
    return 0;
}