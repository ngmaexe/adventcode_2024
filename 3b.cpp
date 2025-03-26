#include <bits/stdc++.h>

using namespace std;

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
    int check;
    
    while (i < s.size()) {
    	if (i + 4 <= s.size() && s.substr(i, 4) == "do()") {
    		check = 1;
    		i += 4;
    	}
    	else if (i + 6 <= s.size() && s.substr(i, 6) == "don't(") {
    		check = 0;
    		i += 6;
    	}
    	else i++;
    	if(s.substr(i, 4) == "mul("){
    		if(check) {
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
		}
	}
	cout<<sum<<endl;
}

