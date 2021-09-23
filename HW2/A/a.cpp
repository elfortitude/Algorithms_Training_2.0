#include <iostream>

using namespace std;

int     main(void) {
    int     res, max;

    res = 0;
    max = 0;
    for (int i = 0; i < 10000; ++i) {
        int numb;
        cin >> numb;
        if (numb == 0)
            break;
        if (numb > max) {
            res = 1;
            max = numb;
        } else if (numb == max) {
            ++res;
        }
    }
    cout << res << endl;

    return 0;
}