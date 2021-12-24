#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

int     main(void) {
    int                                             n, m;
    vector<tuple<long long, long long, int>>        cats;
    vector<tuple<long long, int, int>>              ranges;

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        long long a;
        cin >> a;
        ranges.push_back(make_tuple(a, 0, 0));
    }
    for (int i = 0; i < m; ++i) {
        long long l, r;
        cin >> l >> r;
        ranges.push_back(make_tuple(l, -1, i));
        ranges.push_back(make_tuple(r, 1, i));
        cats.push_back(make_tuple(l, r, 0));
    }
    sort(ranges.begin(), ranges.end());

    int count_cats = 0;
    for (int i = 0; i < ranges.size(); ++i) {
        if (get<1>(ranges[i]) == -1)
            get<2>(cats[get<2>(ranges[i])]) = count_cats;
        else if (get<1>(ranges[i]) == 1)
            get<2>(cats[get<2>(ranges[i])]) = count_cats - get<2>(cats[get<2>(ranges[i])]);
        else
            ++count_cats;
    }

    for (auto cat : cats)
        cout << get<2>(cat) <<  " ";
    cout << endl;

    return 0;
}