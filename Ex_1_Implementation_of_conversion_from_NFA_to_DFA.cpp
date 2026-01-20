#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;

int main() {
    int nfaStates, symbols, finalCount;
    
    cout << "Enter number of NFA states: ";
    cin >> nfaStates;
    
    cout << "Enter number of input symbols: ";
    cin >> symbols;
    
    cout << "Enter number of NFA final states: ";
    cin >> finalCount;
    
    vector<int> finalStates(finalCount);
    cout << "Enter NFA final states: ";
    for (int i = 0; i < finalCount; i++) {
        cin >> finalStates[i];
    }
    
    vector<vector<set<int>>> nfaTable(nfaStates, vector<set<int>>(symbols));
    
    cout << "Enter NFA transition table:\n";
    for (int i = 0; i < nfaStates; i++) {
        for (int j = 0; j < symbols; j++) {
            int transCount;
            cout << "From state " << i << " on symbol " << j 
                 << ", number of transitions: ";
            cin >> transCount;
            
            for (int k = 0; k < transCount; k++) {
                int dest;
                cin >> dest;
                nfaTable[i][j].insert(dest);
            }
        }
    }
    
    map<set<int>, int> dfaMap;
    vector<set<int>> dfaStates;
    vector<vector<int>> dfaTable;
    vector<bool> isFinal;
    
    set<int> start;
    start.insert(0);
    dfaStates.push_back(start);
    dfaMap[start] = 0;
    
    queue<int> q;
    q.push(0);
    
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        
        set<int> currentSet = dfaStates[curr];
        vector<int> trans(symbols, -1);
        
        for (int sym = 0; sym < symbols; sym++) {
            set<int> nextSet;
            
            for (int state : currentSet) {
                nextSet.insert(nfaTable[state][sym].begin(), 
                              nfaTable[state][sym].end());
            }
            
            if (nextSet.empty()) {
                nextSet.clear();
            }
            
            if (dfaMap.find(nextSet) == dfaMap.end()) {
                int newState = dfaStates.size();
                dfaMap[nextSet] = newState;
                dfaStates.push_back(nextSet);
                trans[sym] = newState;
                q.push(newState);
            } else {
                trans[sym] = dfaMap[nextSet];
            }
        }
        
        dfaTable.push_back(trans);
        
        bool final = false;
        for (int state : currentSet) {
            for (int f : finalStates) {
                if (state == f) {
                    final = true;
                    break;
                }
            }
            if (final) break;
        }
        isFinal.push_back(final);
    }
    
    cout << "\nDFA Transition Table:\n";
    for (int i = 0; i < dfaStates.size(); i++) {
        cout << "State " << i << ": ";
        for (int sym = 0; sym < symbols; sym++) {
            cout << dfaTable[i][sym] << " ";
        }
        if (isFinal[i]) {
            cout << "(Final)";
        }
        cout << endl;
    }
    
    return 0;
}