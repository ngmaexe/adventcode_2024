#include<bits/stdc++.h>

using namespace std;

int main () {
    ifstream inputFile("data.txt"); // Replace with your actual file name
    if (!inputFile) {
        std::cerr << "Error: Unable to open file!" << std::endl;
        return 1;
    }

    vector<int> list1;
    vector<int> list2;
    int n1, n2;
    while (inputFile >> n1 >> n2) {
        list1.push_back(n1);
        list2.push_back(n2);
    }

    inputFile.close();

    // Sort
    sort(list1.begin(), list1.end());
    sort(list2.begin(), list2.end());

    //
    int sum = 0;
    for (int i = 0; i < list1.size(); i++) {
        sum += abs(list1[i] - list2[i]);
    }

    cout<<sum<<endl;
}