// Leetcode ques

// link - https://leetcode.com/problems/apply-discount-to-prices/description/

//2288. Apply Discount to Prices
// A sentence is a string of single-space separated words where each word can contain digits, lowercase letters, and the dollar sign '$'. A word represents a price if it is a sequence of digits preceded by a dollar sign.

// For example, "$100", "$23", and "$6" represent prices while "100", "$", and "$1e5" do not.
// You are given a string sentence representing a sentence and an integer discount. For each word representing a price, apply a discount of discount% on the price and update the word in the sentence. All updated prices should be represented with exactly two decimal places.

// Return a string representing the modified sentence.

// Note that all prices will contain at most 10 digits.

// Example 1:

// Input: sentence = "there are $1 $2 and 5$ candies in the shop", discount = 50
// Output: "there are $0.50 $1.00 and 5$ candies in the shop"
// Explanation: 
// The words which represent prices are "$1" and "$2". 
// - A 50% discount on "$1" yields "$0.50", so "$1" is replaced by "$0.50".
// - A 50% discount on "$2" yields "$1". Since we need to have exactly 2 decimal places after a price, we replace "$2" with "$1.00".
// Example 2:

// Input: sentence = "1 2 $3 4 $5 $6 7 8$ $9 $10$", discount = 100
// Output: "1 2 $0.00 4 $0.00 $0.00 7 8$ $0.00 $10$"
// Explanation: 
// Applying a 100% discount on any price will result in 0.
// The words representing prices are "$3", "$5", "$6", and "$9".
// Each of them is replaced by "$0.00".
 
// Constraints:

// 1 <= sentence.length <= 105
// sentence consists of lowercase English letters, digits, ' ', and '$'.
// sentence does not have leading or trailing spaces.
// All words in sentence are separated by a single space.
// All prices will be positive numbers without leading zeros.
// All prices will have at most 10 digits.
// 0 <= discount <= 100

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string discountPrices(string sentence, int discount)
    {
        string s, temp;
        string res;
        double fp;
        double num;
        ostringstream os;

        for (size_t i = 0; i < sentence.length(); i++)
        {
            if (sentence[i] == '$')
            {
                if (i == 0 || sentence[i - 1] == ' ')  // works only if the price is a new word means has ' ' before $. Since 1$2 is not a valid price
                {
                    res += sentence[i];   // Adding dollar to result and moving ahead
                    s = "";  temp = "";
                    i++;
                    while (i < sentence.size() && sentence[i] != ' ' && sentence[i] >= '0' && sentence[i] <= '9' ) {
                        s += sentence[i];
                        i++;  }

                        if (!s.empty() &&
                            (sentence[i] == ' ' || i == sentence.length())) //if s has something means a digit and either after the word meaning where we stopped taking numbers. That place should be a space or end of string. Means only space of end of string can be after valid price
                        {
                            num = stod(s);
                            if (num > 0)   // since if num is 0 means read no is 0 it is to be given as 0. If after discount no is 0 it is to be given as 0.00
                            {
                                fp = (num - (discount * num) / 100);
                                os.str("");  os.clear();
                                os << fixed << setprecision(2) << fp;
                                temp = os.str();
                                res += temp;
                            }
                            else    // if no is 0 then add is to result as it is
                            {
                                res += s;
                            }
                            if (i < sentence.size() && sentence[i] != '$')  // adding the space after the valid price to the result
                            {
                                res += sentence[i];
                            }
                          }
                          else if (!s.empty())  // if s is not empty but it isnt a valid price either it has something after the digit that is not space then since its no it will be in s so adding that to result
                        {
                            res += s;
                            if (i < sentence.size())
                            {
                                res += sentence[i];
                            }
                        }
                          else   // if after dollar we dont have any number or any other case we add directly to result
                        {
                            if (i < sentence.size())
                            {
                                res += sentence[i];
                            }
                        }
                }
                else   // if the $ in price is not preceeded by space then add the thing to string
                {     
                   res += sentence[i];
                }
            }
            else   // if we encounter anything except dollar add to string
            {
                res += sentence[i];
            }
        }
        return res;
    }
};