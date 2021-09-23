#include <iostream>
#include <set>
#include <string>
#include <sstream>

using namespace std;

int     main(void) {
    set<int>    A;
    set<int>    B;

    string line;
    int count = 0;
    while (getline(cin, line)) {
        istringstream iss(line);
        int n;
        while (iss >> n) {
            if (count == 0)
                A.insert(n);
            else
                B.insert(n);
        }
        ++count;
    }
    
    count = 0;
    for (auto i : A) {
        if (B.count(i) != 0)
            ++count;
    }
    cout << count << endl;

    return 0;
}