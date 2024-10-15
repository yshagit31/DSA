#include <bits/stdc++.h>
using namespace std;

bool is_triangular_number(int n) {
    int x = (int)((-1 + sqrt(1 + 8 * n)) / 2);
    return x * (x + 1) / 2 == n;
}

int calculate_labor_charges(vector<int> boxes, int N, int K) {
    int total_charges = 0;
    vector<int> unshifted_count(boxes.size(), 0);
    int cycles = 0;

    while (true) {
        vector<int> selected_boxes(boxes.begin(), boxes.begin() + N);
        vector<int> new_order;

        for (int i = 0; i < N; i += 2) {
            if (i + 1 < N) {
                if (selected_boxes[i] < selected_boxes[i + 1]) {
                    new_order.push_back(selected_boxes[i + 1]);
                    unshifted_count[i + 1]++;
                    unshifted_count[i] = 0; // Reset count for shifted box
                } else {
                    new_order.push_back(selected_boxes[i]);
                    unshifted_count[i]++;
                    unshifted_count[i + 1] = 0; // Reset count for shifted box
                }
            } else {
                new_order.push_back(selected_boxes[i]);
            }
        }

        for (const int &weight : selected_boxes) {
            if (!is_triangular_number(weight)) {
                total_charges += weight;
            }
        }

        boxes.erase(boxes.begin(), boxes.begin() + N);
        boxes.insert(boxes.end(), new_order.begin(), new_order.end());

        cycles++;

        bool halt_process = false;
        for (int i = 0; i < N; ++i) {
            if (unshifted_count[i] >= K) {
                halt_process = true;
                break;
            }
        }

        if (halt_process) {
            return total_charges;
        }
    }
}

int main() {
    vector<int> boxes;
    int weight;

    while (cin >> weight) {
        boxes.push_back(weight);
        if (cin.peek() == '\n') break; // Stop reading after the first line
    }

    int N, K;
    cin >> N >> K;

    int result = calculate_labor_charges(boxes, N, K);
    cout << result << endl;

    return 0;
}