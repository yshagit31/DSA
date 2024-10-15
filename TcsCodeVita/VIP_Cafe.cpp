#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> priorities(N);
    for (int i = 0; i < N; i++) {
        cin >> priorities[i];
    }
    
    int K;
    cin >> K;
    K--; 

    deque<pair<int, int>> queue;
    
    for (int i = 0; i < N; i++) {
        queue.push_back({priorities[i], i});
    }
    
    int serve_count = 0;
    
    while (!queue.empty()) {
        int max_priority = -1;
        for (const auto& p : queue) {
            max_priority = max(max_priority, p.first);
        }
        
        int size = queue.size();
        for (int i = 0; i < size; i++) {
            if (queue[i].first == max_priority) {
                serve_count++;
                if (queue[i].second == K) {
                    cout << serve_count;
                    return 0;
                }
                queue.erase(queue.begin() + i);
                for (int j = 0; j < i; j++) {
                    queue[j].first++;
                }
                break;
            }
        }
    }
    
    return 0;
}
