#include <iostream>
#include <vector>
#include <set>

using namespace std;

int                 main(void) {
    vector<int>     numbers;
    multiset<int>   set_numbers;

    int n;
    while (cin >> n) {
        numbers.push_back(n);
        set_numbers.insert(n);
    }
    
    for (auto i : numbers) {
        if (set_numbers.count(i) == 1)
            cout << i << " ";
    }

    return 0;
}