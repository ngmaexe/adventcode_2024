#include<bits/stdc++.h>
using namespace std;

bool isSafe(const vector<int>& l) {
    bool increasing = true, decreasing = true;

    for (size_t i = 0; i < l.size() - 1; i++) {
        int diff = l[i + 1] - l[i];
        if (abs(diff) < 1 || abs(diff) > 3) {
            return false;
        }
        if (diff < 0) {
            increasing = false;
        }
        if (diff > 0) {
            decreasing = false;
        }
    }

    return increasing || decreasing;
}


bool isSafe2(const vector<int>& l) {
    if(isSafe(l)) return true;
    
    for (auto i = 0; i < l.size(); i++) {
        vector<int> check = l;
        check.erase(check.begin() + i);

        if (isSafe(check)) {
            return true;
		}
    }

    return false;
}

int main() {
	ifstream inputFile("data.txt"); // Open the file
    if (!inputFile) {
        cerr << "Error: Unable to open file!" << endl;
        return 1;
    }

    vector<vector<int>> v;
    string line;
    
    while (getline(inputFile, line)) {
        istringstream iss(line);
        vector<int> v1;
        int level;

        while (iss >> level) {
            v1.push_back(level);
        }
        v.push_back(v1);
    }

    inputFile.close();

    int safe = 0;
    for (const auto& i : v) {
        if (isSafe2(i)) {
            safe++;
        }
    }

    cout << safe << endl;

    return 0;
}

