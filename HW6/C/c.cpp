#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

double f_bin_search_negative_a(double a, double b, double c, double d) {
    double l = -1000000;
    double r = 1000000;
    double m, eps;

    eps = 0.0000001;

    while (l + eps < r)
    {   
        m = (l + r) / 2.0;

        if ((a * pow(m, 3) + b * pow(m, 2) + c * m + d) < 0)
            r = m;
        else
            l = m;
    }

    return l;
} 

double f_bin_search_positive_a(double a, double b, double c, double d) {
    double l = -1000000;
    double r = 1000000;
    double m, eps;

    eps = 0.0000001;

    while (l + eps < r)
    {   
        m = (l + r) / 2.0;

        if ((a * pow(m, 3) + b * pow(m, 2) + c * m + d) > 0)
            r = m;
        else
            l = m;
    }

    return l;
}

int         main(void) {
    double     a, b, c, d;

    cin >> a >> b >> c >> d;

    cout << setprecision(10);
    if (a > 0)
        cout << f_bin_search_positive_a(a, b, c, d) << endl;
    else
        cout << f_bin_search_negative_a(a, b, c, d) << endl;

    return 0;
}