/*
 * [13] Roman to Integer
 *
 * https://leetcode.com/problems/roman-to-integer/
 *
 * Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
 *  Symbol       Value
 *  I             1
 *  V             5
 *  X             10
 *  L             50
 *  C             100
 *  D             500
 *  M             1000
 *
 * For example, 2 is written as II in Roman numeral, just two ones added together. 12 is written as XII, which is simply X + II. 
 * The number 27 is written as XXVII, which is XX + V + II.
 *
 * Roman numerals are usually written largest to smallest from left to right.
 * However, the numeral for four is not IIII. Instead, the number four is written as IV.
 * Because the one is before the five we subtract it making four.
 * The same principle applies to the number nine, which is written as IX.
 * There are six instances where subtraction is used:
 *   I can be placed before V (5) and X (10) to make 4 and 9. 
 *   X can be placed before L (50) and C (100) to make 40 and 90.
 *   C can be placed before D (500) and M (1000) to make 400 and 900.
 * Given a roman numeral, convert it to an integer.
 *
 * Example 1:
 * Input: s = "III"
 * Output: 3
 * Explanation: III = 3.
 *
 * Example 2:
 * Input: s = "LVIII"
 * Output: 58
 * Explanation: L = 50, V= 5, III = 3.
 *
 * Example 3:
 * Input: s = "MCMXCIV"
 * Output: 1994
 * Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 *
 * Constraints:
 * 1 <= s.length <= 15
 * s contains only the characters ('I', 'V', 'X', 'L', 'C', 'D', 'M').
 * It is guaranteed that s is a valid roman numeral in the range [1, 3999].
 */

// Algorithm 
class Solution {
public:
    int getValue(char ch) {
        switch (ch) {
            case 'I': return 1; break;
            case 'V': return 5; break;
            case 'X': return 10; break;
            case 'L': return 50; break;
            case 'C': return 100; break;
            case 'D': return 500; break;
            case 'M': return 1000; break;
            default: break;
        }
        return -1;
    }

    int romanToInt(string s) {
        int result = 0;
        int i, v1, v2;

        for (i = 0; i < s.length(); i++) {
            v1 = getValue(s[i]);
            if (i + 1 < s.length()) {
                v2 = getValue(s[i + 1]);
                if (v1 >= v2) {
                    result = result + v1;
                } else {
                    result = result + v2 - v1;
                    i++;
                }
            } else {
                result = result + v1;
            }
        }

        return result;
    }
};

// unordered_map
class Solution {
public:
    int romanToInt(string s) {
        std::unordered_map<char, int> dict = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        int num = 0;
        int i;

        for (i = 0; i < s.size(); i++) {
            if (dict[s[i]] < dict[s[i + 1]]) {
                num -= dict[s[i]];
            } else {
                num += dict[s[i]];
            }
        }
        return num;
    }
};

// map
class Solution {
public:
    int romanToInt(string s) {
        std::map<char,int> mapTab;
        mapTab.insert(std::pair<char,int>('I', 1));
        mapTab.insert(std::pair<char,int>('V', 5));
        mapTab.insert(std::pair<char,int>('X', 10));
        mapTab.insert(std::pair<char,int>('L', 50));
        mapTab.insert(std::pair<char,int>('C', 100));
        mapTab.insert(std::pair<char,int>('D', 500));
        mapTab.insert(std::pair<char,int>('M', 1000));

        int num = 0;
        int i;

        for (i = 0; i < s.length(); i++) {
            if (mapTab[s[i]] < mapTab[s[i + 1]]) {
                num += mapTab[s[i +1]] - mapTab[s[i]];
                i++;
                continue;
            }
            num += mapTab[s[i]];
        }
        return num;
    }
};
