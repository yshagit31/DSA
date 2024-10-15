#include <bits/stdc++.h>
using namespace std;

int calculateDistance(char nameChar, char &prevGoodChar, const string &goodString) {
    int minDist = INT_MAX;
    char closestChar = prevGoodChar;

    for (char goodChar : goodString) {
        int dist = abs(nameChar - goodChar);
        if (dist < minDist || (dist == minDist && abs(prevGoodChar - goodChar) >= abs(prevGoodChar - closestChar))) {
            minDist = dist;
            closestChar = goodChar;
        }
    }

    // Update prevGoodChar only if the closestChar is different
    if (closestChar != prevGoodChar) {
        prevGoodChar = closestChar;
    }

    return minDist;
}

int main() {
    string goodString, name;
    getline(cin, goodString);
    getline(cin, name);
    char prevGoodChar = goodString[0];
    int totalDistance = 0;

    for (char nameChar : name) {
        if (goodString.find(nameChar) == string::npos) {
            totalDistance += calculateDistance(nameChar, prevGoodChar, goodString);
        } else {
            prevGoodChar = nameChar;
        }
    }

    cout << totalDistance << endl;
    return 0;
}