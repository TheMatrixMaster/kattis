#include<iostream>
#include<queue>
#include<vector>

using namespace std;

priority_queue<int, vector<int>, greater<int>> departures;
priority_queue<int, vector<int>, greater<int>> arrivals;

int main()
{
    int n, m;
    int arrival, delta, departure;
    cin >> n >> m;

    for (int i=0; i<n; i++) {
        cin >> arrival >> delta;
        arrivals.push(arrival);
        departures.push(arrival + delta);
    }

    int out = 0;

    while (!arrivals.empty() && !departures.empty()) {
        departure = departures.top();

        while (!arrivals.empty()) {
            arrival = arrivals.top();
            if (arrival > departure + m) break;
            else if (arrival < departure) arrivals.pop();
            else {
                out += 1;
                arrivals.pop();
                break;
            }
        }

        departures.pop();
    }

    cout << out << endl;

    return 0;
}