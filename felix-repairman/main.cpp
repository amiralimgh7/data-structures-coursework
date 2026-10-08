#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    long long int  m, sotoon, satr;
    char jahat;
    long long grid_size;
    if (!(cin >> grid_size >> m) || grid_size < 1 || m < 0) return 1;
    map<long long int, long long int> map;
    set<pair<long long int, char>> set;

    for (long long int i = 0; i < m; i++) {
        cin >> sotoon;
        cin >> satr;
        cin >> jahat;
        if (!cin || sotoon < 1 || satr < 1 || sotoon > grid_size || satr > grid_size || (jahat != 'U' && jahat != 'L')) return 1;

        auto existing = set.lower_bound({sotoon, 0});
        if (existing != set.end() && existing->first == sotoon) {
            cout << "0" << endl;
            continue;
        }

        if (jahat == 'U') {
            auto a = set.upper_bound({sotoon, 0});
            if (a != set.end()) {

                if (a->second == 'U') {
                    map.insert(pair<long long int, long long int>(sotoon, map.find(a->first)->second + a->first - sotoon));
                } else {
                    map.insert(pair<long long int, long long int>(sotoon, a->first - sotoon));
                }
            } else {
                map.insert(pair<long long int, long long int>(sotoon, satr));
            }
        }
        if (jahat == 'L') {
            set.insert({sotoon, jahat});
            auto a = set.lower_bound({sotoon, 0});
            if (a == set.begin()) {
                map.insert(pair<long long int, long long int>(sotoon, sotoon));
            } else if (a != set.begin()) {
                a--;

                if (a->second == 'L') {
                    map.insert(pair<long long int, long long int>(sotoon, map.find(a->first)->second - a->first + sotoon));
                } else {
                    map.insert(pair<long long int, long long int>(sotoon, sotoon - a->first));

                }
            }
        }
        set.insert({sotoon, jahat});
        cout << map.find(sotoon)->second << endl;
    }
}
