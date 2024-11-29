#include<bits/stdc++.h>
using namespace std;

int angleDiff(int start, int end, const string& direction) {
    if (direction == "clockwise") {
        return (end - start + 360) % 360;
    } else {
        return (start - end + 360) % 360;
    }
}

vector<int> processQuery(int h0, int m0, int theta, int A, int B, int X, int Y) {
    double minTotalCost = INT_MAX;
    int finalH1 = h0, finalM1 = m0;

    for (int dir = 1; dir <= 2; dir++) {
        string D_h = (dir == 1) ? "clockwise" : "counter-clockwise";
        string D_m = (dir == 1) ? "counter-clockwise" : "clockwise";
        int costHourDirection = (dir == 1) ? A : B;
        int costMinuteDirection = (dir == 1) ? B : A;

        for (int h1 = 0; h1 < 360; h1 += 30) {
            int delta_h = angleDiff(h0, h1, D_h);

            for (int angleOption : {theta, (360 - theta) % 360}) {
                int m1 = (h1 + angleOption) % 360;
                int delta_m = angleDiff(m0, m1, D_m);

                double costHourHand = delta_h * X * costHourDirection;
                double costMinuteHand = delta_m * Y * costMinuteDirection;
                double totalCost = costHourHand + costMinuteHand;

                if (totalCost < minTotalCost) {
                    minTotalCost = totalCost;
                    finalH1 = h1;
                    finalM1 = m1;
                }
            }
        }
    }

    return {(int)minTotalCost, finalH1, finalM1};
}

int main() {
    string initialTime;
    int Q, A, B, X, Y;

    cin >> initialTime;
    cin >> Q;
    cin >> A >> B >> X >> Y;

    vector<int> angles(Q);
    for (int i = 0; i < Q; i++) {
        cin >> angles[i];
    }

    int H = stoi(initialTime.substr(0, 2));
    int M = stoi(initialTime.substr(3, 2));

    int h0 = (H % 12) * 30;
    int m0 = M * 6;

    double totalMinCost = 0;

    for (int theta : angles) {
        vector<int> result = processQuery(h0, m0, theta, A, B, X, Y);
        totalMinCost += result[0];
        h0 = result[1];
        m0 = result[2];
    }

    cout << (int)totalMinCost << endl;

    return 0;
}
