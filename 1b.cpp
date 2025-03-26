#include<bits/stdc++.h>

using namespace std;

int main () {
	ifstream inputFile("data.txt"); // Replace with your actual file name
  	if (!inputFile) {
    std::cerr << "Error: Unable to open file!" << std::endl;
    return 1;
  	}

  	vector <int> list1;
  	vector <int> list2;

  	int n1, n2;
  	while (inputFile >> n1 >> n2) {
    list1.push_back(n1);
    list2.push_back(n2);
  	}

  	inputFile.close();
  	
  	map<int, int> m;

    for (int num : list2) { //count number in list 2
        m[num]++;
    }
    
    int sum = 0;
    
    for (int i = 0; i < list1.size(); i++) {
    	for(auto it : m) {
    		if(list1[i] == it.first){
    			sum += list1[i] * it.second;
			}
		}
	}
	
	cout<<sum<<endl;    
    
}


