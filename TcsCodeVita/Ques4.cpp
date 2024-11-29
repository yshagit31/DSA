#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    unordered_map<string, vector<string>> graph;
    unordered_map<string, int> inDegree;
    unordered_map<string, int> level;
    set<string> allWords;
    
    for (int i = 0; i < N; ++i) {
        string from, to;
        cin >> from >> to;
        graph[from].push_back(to);
        inDegree[to]++;
        allWords.insert(from);
        allWords.insert(to);
    }
    
    queue<string> q;
    for (const string& word : allWords) {
        if (inDegree[word] == 0) {
            q.push(word);
            level[word] = 1;
        }
    }
    
    while (!q.empty()) {
        string current = q.front();
        q.pop();
        
        for (const string& neighbor : graph[current]) {
            if (level.find(neighbor) == level.end()) {
                level[neighbor] = level[current] + 1;
                q.push(neighbor);
            }
        }
    }
    
    string word;
    int totalValue = 0;
    while (cin >> word) {
        if (level.find(word) != level.end()) {
            totalValue += level[word];
        } else {
            totalValue += -1;
        }
    }
    
    cout << totalValue ;
    
    return 0;
}