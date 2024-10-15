#include <iostream>
#include <string>

using namespace std;
int count_valid_triplets(const string &s) {
    int n = s.length();
    int count = 0;
    int last_m = -1, last_l = -1;

    for (int i = 0; i < n; i++) {
        if (s[i] == 'M') {
            if (last_l != -1) {
                count += i - last_l - 1;
            }
            last_m = i;
        } else {
            if (last_m != -1) {
                count += i - last_m - 1;
            }
            last_l = i;
        }
    }

    return count;
}

bool is_valid_input(const string &s) {
    for (char c : s) {
        if (c != 'M' && c != 'L') {
            return false;
        }
    }
    return true;
}

string find_winner(const string &ashok_row, const string &anand_row) {
    if (!is_valid_input(ashok_row) || !is_valid_input(anand_row)) {
        return "Invalid input";
    }

    int ashok_count = count_valid_triplets(ashok_row);
    int anand_count = count_valid_triplets(anand_row);

    if (ashok_count > anand_count) {
        return "Ashok";
    } else if (anand_count > ashok_count) {
        return "Anand";
    } else {
        return "Draw";
    }
}

int main() {
    string ashok_row, anand_row;
    cin >> ashok_row >> anand_row;
    cout << find_winner(ashok_row, anand_row);
    return 0;
}
