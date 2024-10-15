#include <iostream>
using namespace std;

int main() {
    long long L, K;
    cin >> L >> K;

    if (K == 0) {
        cout << L;
        return 0;
    }
    
    if (K >= L) {
        cout << 0 ;
        return 0;
    }

    long long Z = L - K;
    long long gaps = K + 1;

    long long max_zeros = (Z + gaps - 1) / gaps;

    cout << max_zeros;

    return 0;
}
