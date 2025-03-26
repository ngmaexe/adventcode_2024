#include <bits/stdc++.h>

using namespace std;

const string xmas = "XMAS";
const int l = xmas.size();


//count
int cnt(const vector<string>& grid) {
    int cnt = 0;
    int r = grid.size();
    int c = grid[0].size();
    
    int d[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {1, 1}, {-1, 1}, {1, -1}};
    
    for (int x = 0; x < r; ++x) {
        for (int y = 0; y < c; ++y) {
            for (int i = 0; i < 8; ++i) {
                int dx = d[i][0];
                int dy = d[i][1];
                
                //check if XMAS exist
                int check = 1;
                for (int j = 0; j < l; ++j) {
				//calculate next positions                	
                    int nx = x + j * dx;  
                    int ny = y + j * dy; 
                    
                    //cannot find
                    if (nx < 0 || ny < 0 || nx >= grid.size() || ny >= grid[0].size() || grid[nx][ny] != xmas[j]) {
                        check = 0;
                        break;
                    }
                }
                
                if (check) {
                    cnt++;
                }
            }
        }
    }
    return cnt;
}

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

    cout<<cnt(grid)<<endl;

    return 0;
}
