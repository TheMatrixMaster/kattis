#include<iostream>
#include<string>

using namespace std;
    
    
int main()
{   
    int count = 0;
    string agent;
    
    for (int i=1; i<=5; i++) {
        cin >> agent;
        
        if (agent.find("FBI") != string::npos) {
            count += 1;
            cout << i << ' ';
        }
    } 
    
    if (count == 0)
        cout << "HE GOT AWAY!" << '\n';
    else
        cout << endl;
    
    return 0;
}