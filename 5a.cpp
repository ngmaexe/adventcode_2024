#include <bits/stdc++.h>

using namespace std;

bool check(const vector<int>& v, const unordered_map<int, unordered_set<int>>& rule) {
    unordered_map<int, int> pos;
    for (int i = 0; i < v.size(); ++i) {
        pos[v[i]] = i;
    }
    for (const auto& s : rule) {
        int x = s.first;
        const unordered_set<int>& ySet = s.second; 
        if (pos.find(x) != pos.end()) {
            for (int y : ySet) {
                if (pos.find(y) != pos.end() && pos[x] > pos[y]) //cannot find y && wrong position
				{
                    return false;
                }
            }
        }
    }
    return true;
}

int main() {
    ifstream inputFile("data.txt");
    if (!inputFile) {
        cerr << "Error: Cannot open input file." << endl;
        return 1;
    }

    string line;
    unordered_map<int, unordered_set<int>> rule;
    vector<vector<int>> update;

    // Read |
    while (getline(inputFile, line) && !line.empty()) {
        istringstream iss(line);
        string s;
        int x, y;
        if (getline(iss, s, '|')) {
            x = stoi(s);
            iss >> y;
            rule[x].insert(y);
        }
    }

    // Read ,
    while (getline(inputFile, line)) {
        istringstream iss(line);
        vector<int> v;
        string page;
        while (getline(iss, page, ',')) {
            v.push_back(stoi(page));
        }
        update.push_back(v);
    }

    inputFile.close();

    int sum = 0;

    for (const auto& v : update) {
        if (check(v, rule)) {
            int middle = v.size() / 2; 
			sum += v[middle]; 
		}
    }

    cout << sum << endl;

    return 0;
}
