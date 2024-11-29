#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
    Point(int _x, int _y) : x(_x), y(_y) {}
    bool operator<(const Point& p) const {
        return x == p.x ? y < p.y : x < p.x;
    }
};

double calculateArea(vector<Point>& polygon) {
    int n = polygon.size();
    double area = 0;
    for (int i = 0; i < n; ++i) {
        int x1 = polygon[i].x, y1 = polygon[i].y;
        int x2 = polygon[(i + 1) % n].x, y2 = polygon[(i + 1) % n].y;
        area += (x1 * y2) - (y1 * x2);
    }
    return abs(area) / 2.0;
}

bool isValidPolygon(const vector<pair<Point, Point>>& segments) {
    set<Point> points;
    for (const auto& seg : segments) {
        points.insert(seg.first);
        points.insert(seg.second);
    }
    return points.size() == segments.size();
}

int maxPolygonArea(int N, vector<pair<Point, Point>>& segments) {
    int maxArea = 0;
    for (int mask = 1; mask < (1 << N); ++mask) {
        vector<pair<Point, Point>> selectedSegments;
        for (int i = 0; i < N; ++i) {
            if (mask & (1 << i)) {
                selectedSegments.push_back(segments[i]);
            }
        }
        if (selectedSegments.size() >= 3 && isValidPolygon(selectedSegments)) {
            set<Point> points;
            for (const auto& seg : selectedSegments) {
                points.insert(seg.first);
                points.insert(seg.second);
            }
            vector<Point> polygon(points.begin(), points.end());
            double area = calculateArea(polygon);
            maxArea = max(maxArea, (int)area);
        }
    }
    return maxArea;
}

int main() {
    int N;
    cin >> N;
    vector<pair<Point, Point>> segments;
    for (int i = 0; i < N; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        segments.push_back({Point(x1, y1), Point(x2, y2)});
    }
    cout << maxPolygonArea(N, segments) << endl;
    return 0;
}
