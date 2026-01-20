#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

int main() {
    int dfaStates, symbols, finalCount;
    
    cout << "Enter number of DFA states: ";
    cin >> dfaStates;
    
    cout << "Enter number of input symbols: ";
    cin >> symbols;
    
    cout << "Enter number of final states: ";
    cin >> finalCount;
    
    vector<int> finalStates(finalCount);
    cout << "Enter final states: ";
    for (int i = 0; i < finalCount; i++) {
        cin >> finalStates[i];
    }
    
    vector<vector<int>> dfaTable(dfaStates, vector<int>(symbols));
    
    cout << "Enter DFA transition table:\n";
    for (int i = 0; i < dfaStates; i++) {
        for (int j = 0; j < symbols; j++) {
            cin >> dfaTable[i][j];
        }
    }
    
    vector<int> group(dfaStates);
    set<int> finalSet(finalStates.begin(), finalStates.end());
    
    for (int i = 0; i < dfaStates; i++) {
        group[i] = finalSet.find(i) != finalSet.end() ? 1 : 0;
    }
    
    bool changed;
    do {
        changed = false;
        map<vector<int>, int> sigToGroup;
        vector<int> newGroup(dfaStates);
        int newGroupCount = 0;
        
        for (int i = 0; i < dfaStates; i++) {
            vector<int> sig;
            sig.push_back(group[i]);
            for (int sym = 0; sym < symbols; sym++) {
                sig.push_back(group[dfaTable[i][sym]]);
            }
            
            if (sigToGroup.find(sig) == sigToGroup.end()) {
                sigToGroup[sig] = newGroupCount;
                newGroup[i] = newGroupCount;
                newGroupCount++;
            } else {
                newGroup[i] = sigToGroup[sig];
            }
        }
        
        if (newGroup != group) {
            changed = true;
            group = newGroup;
        }
    } while (changed);
    
    set<int> uniqueGroups(group.begin(), group.end());
    int minStates = uniqueGroups.size();
    vector<vector<int>> minTable(minStates, vector<int>(symbols));
    
    for (int i = 0; i < dfaStates; i++) {
        int fromGroup = group[i];
        for (int sym = 0; sym < symbols; sym++) {
            int toState = dfaTable[i][sym];
            minTable[fromGroup][sym] = group[toState];
        }
    }
    
    cout << "\nMinimized DFA State Groups:\n";
    for (int i = 0; i < dfaStates; i++) {
        cout << "State " << i << " -> Group " << group[i] << endl;
    }
    
    cout << "\nMinimized DFA Transition Table:\n";
    for (int i = 0; i < minStates; i++) {
        cout << "Group " << i << ": ";
        for (int sym = 0; sym < symbols; sym++) {
            cout << minTable[i][sym] << " ";
        }
        cout << endl;
    }
    
    return 0;
}