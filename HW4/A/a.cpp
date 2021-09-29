#include <iostream>
#include <map>

using namespace std;

int         main(void) {
    int     n;
    map<long long int, long long int>     packages;

    cin >> n;
    for (int i = 0; i < n; ++i) {
        long long int d, a;
        cin >> d >> a;
        packages[d] += a;
    }

    for (auto item : packages) {
        cout << item.first << " " << item.second << endl;
    }

    return 0;
}