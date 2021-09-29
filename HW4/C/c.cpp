#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

int     main(void) {
    map<string, int>    words;

    string line;
    while (getline(cin, line)) {
        istringstream iss(line);
        string word;

        while (iss >> word) {
            ++words[word];
        } 
    }

    vector<pair<int, string>> counts;
    for (auto word : words) {
        pair<int, string> count(word.second, word.first);
        counts.push_back(count);
    }
    sort(counts.begin(), counts.end());

    map<int, vector<string>> result;
    for (auto word : counts)
        result[word.first].push_back(word.second);

    for (auto i = result.rbegin(); i != result.rend(); ++i) {
        for (auto word : i->second) {
            cout << word << endl;
        }
    }

    return 0;
}