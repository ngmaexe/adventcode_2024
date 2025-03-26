#include <bits/stdc++.h>

using namespace std;

const string xmas = "XMAS";
const int l = xmas.size();

int main() {
    ifstream inputFile("data.txt"); 
    if (!inputFile) {
        cerr << "Error: File not found!" << endl;
        return 1;
    }

    vector<string> grid;
    string line;
    
    while (getline(inputFile, line)) {
        grid.push_back(line);
    }

    inputFile.close();

    int rows = grid.size();
    int cols = grid[0].size();
    int cnt = 0;
    
    for (int x = 1; x < rows - 1; ++x) {
        for (int y = 1; y < cols - 1; ++y) {
            if (grid[x][y] == 'A' && grid[x - 1][y - 1] == 'M' && grid[x - 1][y + 1] == 'M' && grid[x + 1][y - 1] == 'S' && grid[x + 1][y + 1] == 'S') cnt++;
            if (grid[x][y] == 'A' && grid[x - 1][y - 1] == 'S' && grid[x - 1][y + 1] == 'M' && grid[x + 1][y - 1] == 'S' && grid[x + 1][y + 1] == 'M') cnt++;
            if (grid[x][y] == 'A' && grid[x - 1][y - 1] == 'M' && grid[x - 1][y + 1] == 'S' && grid[x + 1][y - 1] == 'M' && grid[x + 1][y + 1] == 'S') cnt++;
            if (grid[x][y] == 'A' && grid[x - 1][y - 1] == 'S' && grid[x - 1][y + 1] == 'S' && grid[x + 1][y - 1] == 'M' && grid[x + 1][y + 1] == 'M') cnt++;
        }
    }
/* 
M M         S M           M S          S S
 A           A             A            A
S S         S M           M S          M M
*/
    
    cout<<cnt<<endl;

    return 0;
}


