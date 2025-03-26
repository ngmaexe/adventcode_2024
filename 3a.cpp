#include <bits/stdc++.h>

using namespace std;


//char to int
int ctoi(const string &s, size_t &i){
	int num = 0;
	int cnt = 0;
	while(i < s.size() && isdigit(s[i]) && cnt < 3) {
		num = num * 10 + (s[i] - 48);
		i++;
		cnt++;
	}
	if(cnt > 0) return num;
	else return -1;
}


int main () {
	ifstream inputFile("data.txt"); 
    if (!inputFile) {
        cerr << "Error: Unable to open file!" << endl;
        return 1;
    }
    
    string s, line;
    
    while (getline(inputFile, line)) {
        s += line;
    }
    inputFile.close();
    
    int sum = 0;
    size_t i = 0;
    
    while (i < s.size()) {
    	if(s.substr(i, 4) == "mul("){
    		i += 4;
    		auto st = i;
    		int n1 = ctoi(s, i);
    		
    		if(n1 != -1 && i < s.size() && s[i] == ','){
    			i++;
    			int n2 = ctoi(s, i);
    			
    			if(n2 != -1 && i < s.size() && s[i] == ')')
    				sum += n1*n2;
			}
		}
		
		i++;
		
	}
	cout<<sum<<endl;
}
