#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int     main(void) {
    int                     N, count, res;
    vector<pair<int, bool>> ranges;

    cin >> N;
    for (int i = 0; i < N; ++i) {
        int T, L;
        cin >> T >> L;
        ranges.push_back(make_pair(T, true));
        ranges.push_back(make_pair(T + L, false));
    }
    sort(ranges.begin(), ranges.end());

    count = 0;
    res = 0;
    for (auto range : ranges) {
        if (!range.second)
            --count;
        else
            ++count;
        if (count > res)
            res = count;
    }

    cout << res << endl;

    return 0;
}