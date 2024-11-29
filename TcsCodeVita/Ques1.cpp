#include<bits/stdc++.h>
using namespace std;

string getMatrix(const vector<string> &lines, int startCol) {
    string result;
    for (int i = 0; i < 3; i++) {
        result += lines[i].substr(startCol, 3);
    }
    return result;
}

vector<string> getToggledMatrices(const string &matrix) {
    vector<string> toggledMatrices;
    for (int i = 0; i < 9; i++) {
        string toggled = matrix;
        toggled[i] = (matrix[i] == '1') ? '0' : '1';
        toggledMatrices.push_back(toggled);
    }
    return toggledMatrices;
}

bool findValidNumbers(const vector<string> &inputDigits,
                      const vector<string> &digitMap,
                      set<int> &allNumbers,
                      int currentNumber,
                      size_t pos = 0) {  // Change pos to size_t
    if (pos == inputDigits.size()) {
        allNumbers.insert(currentNumber);
        return true;
    }

    const string &digit = inputDigits[pos];
    bool isValid = false;

    for (int i = 0; i < 10; i++) {
        if (digit == digitMap[i]) {
            isValid |= findValidNumbers(inputDigits, digitMap, allNumbers,
                                        currentNumber * 10 + i, pos + 1);
        }
    }

    for (const string &toggled : getToggledMatrices(digit)) {
        for (int i = 0; i < 10; i++) {
            if (toggled == digitMap[i]) {
                isValid |= findValidNumbers(inputDigits, digitMap, allNumbers,
                                            currentNumber * 10 + i, pos + 1);
            }
        }
    }

    return isValid;
}

int main() {
    vector<string> digitLines(3);
    for (int i = 0; i < 3; i++) {
        cin >> digitLines[i];
    }

    vector<string> digitMap(10);
    for (int i = 0; i < 10; i++) {
        digitMap[i] = getMatrix(digitLines, i * 3);
    }

    vector<string> inputLines(3);
    for (int i = 0; i < 3; i++) {
        cin >> inputLines[i];
    }

    int numDigits = inputLines[0].size() / 3;
    vector<string> inputDigits(numDigits);
    for (int i = 0; i < numDigits; i++) {
        inputDigits[i] = getMatrix(inputLines, i * 3);
    }

    set<int> allNumbers;
    if (!findValidNumbers(inputDigits, digitMap, allNumbers, 0)) {
        cout << "Invalid" << endl;
        return 0;
    }

    long long sum = 0;
    for (int number : allNumbers) {
        sum += number;
    }

    cout << sum << endl;
    return 0;
}
