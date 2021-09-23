#include <iostream>
#include <set>
#include <vector>

using namespace std;

int                 main(void) {
    int             N, res;
    multiset<int>   numbers;

    cin >> N;
    for (int i = 0; i < N; ++i) {
        int n;
        cin >> n;
        numbers.insert(n);
    }

    res = 0;
    vector<int> numbers_arr(numbers.begin(), numbers.end());
    for (int i = 0; i < numbers_arr.size(); ++i) {
        if (i != numbers_arr.size() - 1)
            res += numbers_arr[i];
    }
    cout << res;

    return 0;
}