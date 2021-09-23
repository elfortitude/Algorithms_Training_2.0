#include <iostream>
#include <set>

using namespace std;

int     main(void) {
    set<int>    seen;

    int n;
    while (cin >> n)
    {
        if (seen.count(n) == 0) {
            seen.insert(n);
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
    
    return 0;
}