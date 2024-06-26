// link- https://leetcode.com/problems/power-of-two/

// Given an integer n, return true if it is a power of two. Otherwise, return false.

// An integer n is a power of two, if there exists an integer x such that n == 2x.

 

// Example 1:

// Input: n = 1
// Output: true
// Explanation: 20 = 1
// Example 2:

// Input: n = 16
// Output: true
// Explanation: 24 = 16
// Example 3:

// Input: n = 3
// Output: false
 

// Constraints:

// -231 <= n <= 231 - 1
 

// Follow up: Could you solve it without loops/recursion?

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPowerOfTwo(int n) {
    int num=0;
    for(int i=0;i<=30;i++)
    {
        num=pow(2,i);
        if(n==num)
        {
            return true;
        }
    }
    return false;
    }
};

// or

class Solution {
public:
    bool isPowerOfTwo(int n) {
      return n > 0 && (n & (n - 1)) == 0;
    }
};

// ### Explanation:

// 1. **Positive Check (`n > 0`):**
//    - The condition `n > 0` ensures that the number is positive. This is important because powers of two are positive numbers (1, 2, 4, 8, 16, etc.).
//    - Negative numbers or zero cannot be powers of two, so this check filters out those cases immediately.

// 2. **Bitwise AND Operation (`n & (n - 1)`):**
//    - The expression `(n & (n - 1))` utilizes a property of numbers that are powers of two.
//    - A power of two in binary representation has exactly one bit set to `1` and all other bits set to `0`. For example:
//      - 1 (2^0) in binary is `0001`
//      - 2 (2^1) in binary is `0010`
//      - 4 (2^2) in binary is `0100`
//      - 8 (2^3) in binary is `1000`
//    - When you subtract `1` from a power of two, all the bits after the single `1` become `1`s, and the single `1` becomes `0`. For example:
//      - For 4 (binary `0100`), `4 - 1` is 3 (binary `0011`)
//      - For 8 (binary `1000`), `8 - 1` is 7 (binary `0111`)

//    - Now, when you perform the bitwise AND operation between `n` and `n - 1`:
//      - If `n` is a power of two, there will be no common `1` bits between `n` and `n - 1`. This results in `0`.
//      - If `n` is not a power of two, the AND operation will produce a non-zero value because there will be overlapping `1` bits.

// 3. **Combining the Checks:**
//    - The condition `n > 0` ensures the number is positive.
//    - The condition `(n & (n - 1)) == 0` checks if `n` is a power of two.
//    - Both conditions combined ensure that the function correctly identifies powers of two.

// ### Example Walkthrough:

// - For `n = 4`:
//   - Binary representation: `0100`
//   - `n - 1` is `3` (binary `0011`)
//   - `0100 & 0011` results in `0000`
//   - Since `4 > 0` and `4 & 3 == 0`, the function returns `true`.

// - For `n = 5`:
//   - Binary representation: `0101`
//   - `n - 1` is `4` (binary `0100`)
//   - `0101 & 0100` results in `0100`
//   - Since `5 > 0` but `5 & 4 != 0`, the function returns `false`.


