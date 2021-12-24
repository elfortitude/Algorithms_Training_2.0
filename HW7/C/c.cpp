#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int     main(void) {
    int                     M;
    vector<pair<int, int>> ranges, res;

    cin >> M;

    int L, R;
    cin >> L >> R;
    while (!(L == 0 && R == 0)) {
        if (L < M && R > 0)
            ranges.push_back(make_pair(L, R));
        cin >> L >> R;
    }
    sort(ranges.begin(), ranges.end());

    int max_right_border = 0;
    int now_right_border = 0;
    pair<int, int> best_range = make_pair(0, 0);
    for (auto &range : ranges) {
        if (range.first > max_right_border) {
            res.push_back(best_range);
            max_right_border = best_range.second;
            if (max_right_border >= M)
                break;
        }
        if (range.first <= max_right_border && range.second > now_right_border) {
            now_right_border = range.second;
            best_range = make_pair(range.first, range.second);
        }
    }

    if (max_right_border < M) {
        res.push_back(best_range);
        max_right_border = best_range.second;
    }
    if (max_right_border < M)
        cout << "No solution" << endl;
    else {
        cout << res.size() << endl;
        for (auto i : res)
            cout << i.first << " " << i.second << endl;
    }
    
    return 0;
}