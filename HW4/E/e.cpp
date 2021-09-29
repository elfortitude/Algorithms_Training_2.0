#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>

using namespace std;

bool comparator(const tuple<string, int, set<int>> &left, const tuple<string, int, set<int>> &right) {
    if (get<1>(left) == get<1>(right))
        return *get<2>(left).begin() > *get<2>(right).begin();
    return get<1>(left) < get<1>(right);
}

int         main(void) {
    int     N;
    vector<tuple<string, int, set<int>>>    topics;

    string line;

    getline(cin, line);
    istringstream iss(line);
    iss >> N;
    for (int i = 1; i <= N; ++i) {
        int n;
        getline(cin, line);
        istringstream iss(line);
        iss >> n;
        if (n == 0) {
            string parts, name, message;
            getline(cin, line);
            istringstream iss1(line);
            while (iss1 >> parts)
                name += parts + " ";
            name.pop_back();
            getline(cin, line);
            istringstream iss2(line);
            while (iss2 >> parts)
                message += parts + " ";
            message.pop_back();
            set<int> numbers;
            numbers.insert(i);
            topics.push_back(make_tuple(name, 1, numbers));
        } else {
            string parts, message;
            getline(cin, line);
            istringstream iss(line);
            while (iss >> parts)
                message += parts + " ";
            message.pop_back();
            for (auto& topic : topics) {
                if (get<2>(topic).count(n) != 0)
                {
                    ++get<1>(topic);
                    get<2>(topic).insert(i);
                }
            }
        }
    }

    sort(topics.rbegin(), topics.rend(), comparator);

    cout << get<0>(topics[0]) << endl;

    return 0;
}