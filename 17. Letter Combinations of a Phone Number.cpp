/*
 * Authr: Diane
 *
 * [17] Letter Combinations of a Phone Number
 *
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/
 *
 * Given a string containing digits from 2-9 inclusive,
 * return all possible letter combinations that the number could represent.
 * Return the answer in any order.
 *
 * A mapping of digit to letters (just like on the telephone buttons) is given below.
 * Note that 1 does not map to any letters.
 *
 * +--------+--------+--------+
 * | 1      | 2 abc  | 3 def  |
 * +--------+--------+--------+
 * | 4 ghi  | 5 jkl  | 6 mno  |
 * +--------+--------+--------+
 * | 7 pqrs | 8 tuv  | 9 wxyz |
 * +--------+--------+--------+
 * | *      | 0 _    | #      |
 * +--------+--------+--------+ 
 *
 * Example 1:
 * Input: digits = "23"
 * Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
 *
 * Example 2:
 * Input: digits = ""
 * Output: []
 *
 * Example 3:
 * Input: digits = "2"
 * Output: ["a","b","c"]
 *
 * Constraints:
 *   0 <= digits.length <= 4
 *   digits[i] is a digit in the range ['2', '9'].
 */
 
 /** Iterative **/
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<string> dict = {"","", "abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> result = {""};
        for (int i = 0; i < digits.size(); ++i) {
            vector<string> temp;
            string str = dict[digits[i] - '0'];
            for (int j = 0; j < str.size(); ++j) {
                for (string s : result) {
                    temp.push_back(s + str[j]);
                }
            }
            result = temp;
        }
        return result;
    }
};


/** BFS **/
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<vector<char>> dict(10);
        dict[0] = {' '};           // space
        dict[1] = {};              // no charactor
        dict[2] = {'a', 'b', 'c'};
        dict[3] = {'d', 'e', 'f'};
        dict[4] = {'g', 'h', 'i'};
        dict[5] = {'j', 'k', 'l'};
        dict[6] = {'m', 'n', 'o'};
        dict[7] = {'p', 'q', 'r', 's'};
        dict[8] = {'t', 'u', 'v'};
        dict[9] = {'w', 'x', 'y', 'z'};
        vector<string> result =  {""};
        for (int i = 0; i < digits.size(); ++i) {
            vector<string> temp;
            for (const string &str : result) {
                for (char ch : dict[digits[i] - '0']) {
                    temp.push_back(str + ch);
                }
            }
            result.swap(temp);
        }
        return result;
    }
};