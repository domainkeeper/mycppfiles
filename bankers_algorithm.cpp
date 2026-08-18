#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cout << "Enter number of processes: ";
    cin >> n;
    cout << "Enter number of resources: ";
    cin >> m;

    vector<vector<int>> allocation(n, vector<int>(m));
    vector<vector<int>> max(n, vector<int>(m));
    vector<int> available(m);
    
    cout << "\nEnter Allocation Matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> allocation[i][j];

    cout << "\nEnter Max Matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> max[i][j];

    cout << "\nEnter Available Resources:\n";
    for (int i = 0; i < m; i++)
        cin >> available[i];

    vector<vector<int>> need(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            need[i][j] = max[i][j] - allocation[i][j];

    vector<bool> finished(n, false);
    vector<int> safeSequence;
    vector<int> work = available;

    for (int count = 0; count < n; count++) {
        bool found = false;
        for (int i = 0; i < n; i++) {
            if (!finished[i]) {
                bool canAllocate = true;
                for (int j = 0; j < m; j++) {
                    if (need[i][j] > work[j]) {
                        canAllocate = false;
                        break;
                    }
                }
                if (canAllocate) {
                    for (int j = 0; j < m; j++)
                        work[j] += allocation[i][j];
                    safeSequence.push_back(i);
                    finished[i] = true;
                    found = true;
                    break;
                }
            }
        }
        if (!found) {
            cout << "\nSystem is in UNSAFE state!\n";
            return 0;
        }
    }

    cout << "\nSystem is in SAFE state.\nSafe Sequence: ";
    for (int i : safeSequence)
        cout << "P" << i << " ";
    cout << "\n";

    return 0;
}
