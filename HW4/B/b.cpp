#include <iostream>
#include <sstream>
#include <string>
#include <map>

using namespace std;

int     main(void) {
    map<string, int>    votes;

    string line;
    while (getline(cin, line)) {
        istringstream iss(line);
        string name;
        int n;

        iss >> name;
        iss >> n;

        votes[name] += n;
    }

    for (auto item : votes) {
        cout << item.first << " " << item.second << endl;
    }

    return 0;
}