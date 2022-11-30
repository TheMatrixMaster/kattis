#include<iostream>
#include<sstream>
#include<map>
#include<string>
#include<unordered_map>

using namespace std;

unordered_map<string, string> fast_dictionary;

int main()
{
    string key, value, line;
    string input;
    
    while (getline(cin, line)) {
        if (line.empty()) break;
        istringstream iss(line);
        iss >> value >> key;
        fast_dictionary.insert(make_pair(key, value));
    }

    while (cin >> input) {
        if (fast_dictionary.find(input) == fast_dictionary.end()) {
            cout << "eh" << endl;
        } else {
            cout << fast_dictionary.at(input) << endl;
        }
    }
    
    return 0;
}