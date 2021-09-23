#include <iostream>
#include <string>
#include <set>
#include <sstream>

using namespace std;

int     main(void) {
    int         max_n;
    set<int>    yes;

    string line;
    getline(cin, line);
    max_n = stoi(line);
    for (int i = 1; i <= max_n; ++i)
        yes.insert(i);
    while (getline(cin, line)) {
        if (line == "HELP")
            break;
        istringstream iss(line);
        string answer;
        getline(cin, answer);
        int n;
        if (answer == "NO") {
            while (iss >> n)
                yes.erase(n);
        } else {
            set<int> tmp;
            set<int> yes_copy = yes;
            while (iss >> n)
                tmp.insert(n);
            for (auto item : yes_copy) {
                if (tmp.count(item) == 0)
                    yes.erase(item);
            }
        }
    }

    for (auto i : yes)
        cout << i << " ";

    return 0;
}