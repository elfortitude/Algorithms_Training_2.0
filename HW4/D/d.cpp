#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <math.h>

using namespace std;

bool    comparator(const tuple<double, string, double, double> &left, const tuple<double, string, double, double> &right) {
    if (get<2>(left) == get<2>(right))
        return get<3>(left) < get<3>(right);
    return get<2>(left) < get<2>(right);
}

int     main(void) {
    map<string, double>                             parties;
    vector<tuple<double, string, double, double>>   fract_places;
    vector<string>                                  vector_parties;
    double                                          sum;

    sum = 0;
    string line;
    while (getline(cin, line)) {
        istringstream iss(line);

        vector<string> parts;
        string part;
        string name = "";
        double votes;

        while (iss >> part)
            parts.push_back(part);
        
        votes = stoi(parts[parts.size() - 1]);
        parts.pop_back();

        for (auto item : parts)
            name += item + " ";
        name.pop_back();
        
        sum += votes;
        vector_parties.push_back(name);
        parties[name] = votes;
    }
    sum /= 450;
    
    double counter = 450;
    for (auto& item : parties) {
        fract_places.push_back(make_tuple(floor(item.second / sum), item.first, item.second - floor(item.second / sum) * sum, item.second));
        counter -= floor(item.second / sum);
        item.second = floor(item.second / sum);
    }

    sort(fract_places.rbegin(), fract_places.rend(), comparator);

    for (int i = 0; i < counter; ++i) {
        ++get<0>(fract_places[i % fract_places.size()]);
        ++parties[get<1>(fract_places[i % fract_places.size()])];
    }

    for (auto party : vector_parties) {
        cout << party << " " << parties[party] << endl;
    }

    return 0;
}