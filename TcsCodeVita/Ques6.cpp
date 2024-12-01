#include <iostream>
#include <vector>
#include <algorithm>

struct Segment {
    int start, end;
};

bool compare(Segment a, Segment b) {
    return a.start < b.start;
}

int main() {
    std::vector<Segment> segments = {
        {1, 5}, {3, 7}, {2, 6}, {8, 10}, {4, 9}
    };

    std::sort(segments.begin(), segments.end(), compare);

    std::vector<Segment> merged;
    merged.push_back(segments[0]);

    for (size_t i = 1; i < segments.size(); ++i) {
        if (merged.back().end >= segments[i].start) {
            merged.back().end = std::max(merged.back().end, segments[i].end);
        } else {
            merged.push_back(segments[i]);
        }
    }

    int totalLength = 0;
    for (const auto& seg : merged) {
        totalLength += (seg.end - seg.start);
    }

    std::cout << "Total length of merged segments: " << totalLength << "\n";
    
    return 0;
}