#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;

    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }

    bool operator<(const Point& other) const {
        return x < other.x || (x == other.x && y < other.y);
    }
};

vector<Point> rotate_90(const vector<Point>& shape) {
    vector<Point> rotated(shape.size());
    for (auto i = 0u; i < shape.size(); ++i) { 
        rotated[i] = {shape[i].y, -shape[i].x}; 
    }
    return rotated;
}

vector<Point> normalize(const vector<Point>& shape) {
    vector<Point> normalized = shape;
    sort(normalized.begin(), normalized.end());
    return normalized;
}

vector<vector<Point>> generate_rotations(const vector<Point>& shape) {
    vector<vector<Point>> rotations;
    vector<Point> current_shape = shape;
    
    for (int i = 0; i < 4; i++) {
        rotations.push_back(normalize(current_shape));
        current_shape = rotate_90(current_shape);
    }

    return rotations;
}

bool is_match(const vector<Point>& earring1, const vector<Point>& earring2) {
    vector<vector<Point>> rotations1 = generate_rotations(earring1);
    vector<vector<Point>> rotations2 = generate_rotations(earring2);

    for (const auto& rotation1 : rotations1) {
        for (const auto& rotation2 : rotations2) {
            if (rotation1 == rotation2) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    int N;
    cin >> N;

    vector<vector<Point>> earrings(N);
    for (int i = 0; i < N; ++i) {
        int K;
        cin >> K;
        earrings[i].resize(K);
        for (int j = 0; j < K; ++j) {
            cin >> earrings[i][j].x >> earrings[i][j].y;
        }
    }

    vector<int> matching_pairs;
    for (int i = 0; i < N - 1; ++i) {
        for (int j = i + 1; j < N; ++j) {
            if (is_match(earrings[i], earrings[j])) {
                matching_pairs.push_back(i + 1);
                matching_pairs.push_back(j + 1);
            }
        }
    }

    sort(matching_pairs.begin(), matching_pairs.end());
    for (int pair : matching_pairs) {
        cout << pair << " ";
    }
    cout << endl;

    return 0;
}
