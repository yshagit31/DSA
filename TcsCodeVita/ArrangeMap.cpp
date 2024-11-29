#include <iostream>
#include <vector>
#include <deque>
#include <climits>
#include <algorithm>
#include <bitset>

using namespace std;

// give TLE

int get_shortest_path(vector<vector<char>>& grid, int N) {
    pair<int, int> start, end;
    bool foundStart = false, foundEnd = false;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] == 'S' && !foundStart) {
                start = {i, j};
                foundStart = true;
            } else if (grid[i][j] == 'D' && !foundEnd) {
                end = {i, j};
                foundEnd = true;
            }
        }
    }

    deque<pair<pair<int, int>, int>> queue;
    queue.push_back({start, 0});
    vector<vector<bool>> visited(N, vector<bool>(N, false));
    visited[start.first][start.second] = true;

    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    while (!queue.empty()) {
        auto front = queue.front();
        queue.pop_front();
        pair<int, int> pos = front.first;
        int dist = front.second;
        int x = pos.first, y = pos.second;

        if (grid[x][y] == 'D') {
            return dist;
        }

        for (auto& dir : directions) {
            int nx = x + dir[0], ny = y + dir[1];
            if (nx >= 0 && nx < N && ny >= 0 && ny < N && !visited[nx][ny] && grid[nx][ny] != 'T') {
                visited[nx][ny] = true;
                queue.push_back({{nx, ny}, dist + 1});
            }
        }
    }
    return INT_MAX;
}

vector<vector<vector<char>>> get_sheets(vector<vector<char>>& grid, int N, int M) {
    vector<vector<vector<char>>> sheets;
    for (int i = 0; i < N; i += M) {
        for (int j = 0; j < N; j += M) {
            vector<vector<char>> sheet(M, vector<char>(M));
            for (int x = 0; x < M; x++) {
                for (int y = 0; y < M; y++) {
                    sheet[x][y] = grid[i + x][j + y];
                }
            }
            sheets.push_back(sheet);
        }
    }
    return sheets;
}

vector<vector<char>> make_grid(vector<int>& arrangement, vector<vector<vector<char>>>& sheets, int N, int M) {
    vector<vector<char>> grid(N, vector<char>(N, ' '));
    int num_sheets = N / M;

    // Changed from int to size_t for idx
    for (size_t idx = 0; idx < arrangement.size(); idx++) { 
        int sheet_idx = arrangement[idx];
        auto& sheet = sheets[sheet_idx];
        int base_i = (idx / num_sheets) * M;
        int base_j = (idx % num_sheets) * M;

        for (int i = 0; i < M; i++) {
            for (int j = 0; j < M; j++) {
                grid[base_i + i][base_j + j] = sheet[i][j];
            }
        }
    }
    return grid;
}

int solve() {
    int N, M;
    cin >> N >> M;
    vector<vector<char>> original_grid(N, vector<char>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> original_grid[i][j];
        }
    }

    vector<vector<vector<char>>> sheets = get_sheets(original_grid, N, M);
    int num_sheets = (N / M) * (N / M);

    int s_sheet = -1, d_sheet = -1;
    for (size_t i = 0; i < sheets.size(); i++) {  // Changed from int to size_t for i
        for (int x = 0; x < M; x++) {
            for (int y = 0; y < M; y++) {
                if (sheets[i][x][y] == 'S') {
                    s_sheet = i;
                }
                if (sheets[i][x][y] == 'D') {
                    d_sheet = i;
                }
            }
        }
    }

    int min_dist = INT_MAX;
    vector<int> nums;
    for (int i = 0; i < num_sheets; i++) {
        if (i != s_sheet && i != d_sheet) {
            nums.push_back(i);
        }
    }

    sort(nums.begin(), nums.end());
    do {
        vector<int> arrangement = {s_sheet};
        arrangement.insert(arrangement.end(), nums.begin(), nums.end());
        arrangement.push_back(d_sheet);

        vector<vector<char>> grid = make_grid(arrangement, sheets, N, M);
        min_dist = min(min_dist, get_shortest_path(grid, N));
    } while (next_permutation(nums.begin(), nums.end()));

    return min_dist;
}

int main() {
    cout << solve() << endl;
    return 0;
}
