#include <iostream>
#include <string>

using namespace std;

int         main(void) {
    string  str;
    int     res;

    res = 0;
    cin >> str;
    for (int i = 0; i < str.size() / 2; ++i) {
        if (str[i] != str[str.size() - 1 - i])
            ++res;
    }
    cout << res << endl;

    return 0;
}