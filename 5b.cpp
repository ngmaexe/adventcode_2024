#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

// Function to check if an v is valid based on the rule
bool check(const vector<int>& v, const unordered_map<int, unordered_set<int>>& rule) {
    unordered_map<int, int> pos;
    for (int i = 0; i < v.size(); ++i) {
        pos[v[i]] = i; // Store positions of pages in the v
    }
    for (const auto& s : rule) {
        int x = s.first; // s's "before" page
        const unordered_set<int>& ySet = s.second; // Pages that must come after
        if (pos.find(x) != pos.end()) { // Check if x is in the v
            for (int y : ySet) { // Iterate over all y values
                if (pos.find(y) != pos.end() && pos[x] > pos[y]) {
                    return false; // s violated
                }
            }
        }
    }
    return true;
}
//sort use cmp
void sortUpdate(vector<int>& v, const unordered_map<int, unordered_set<int>>& rule) {
    sort(v.begin(), v.end(), [&rule](int a, int b) {
        if (rule.find(a) != rule.end() && rule.at(a).count(b)) {
            return true; // a must come before b
        }
        if (rule.find(b) != rule.end() && rule.at(b).count(a)) {
            return false; // b must come before a
        }
        return a < b; // Default to ascending order if no explicit s
    });
}

int main() {
    ifstream inputFile("data.txt");
    if (!inputFile) {
        cerr << "Error: Cannot open input file." << endl;
        return 1;
    }

    string line;
    unordered_map<int, unordered_set<int>> rule;
    vector<vector<int>> updates;

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
        updates.push_back(v); 
    }

    inputFile.close();

    int sum = 0;

    for (auto& v : updates) {
        if (!check(v, rule)) {
            sortUpdate(v, rule);
            int middle = v.size() / 2; // Find the middle index
            sum += v[middle]; 
        }
    }

    cout<< sum << endl;

    return 0;
}
