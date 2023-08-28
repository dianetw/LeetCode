/*
 * [20] Valid Parentheses
 *
 * https://leetcode.com/problems/valid-parentheses/
 *
 * Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 * An input string is valid if:
 * 1. Open brackets must be closed by the same type of brackets.
 * 2. Open brackets must be closed in the correct order.
 * 3. Every close bracket has a corresponding open bracket of the same type.
 *
 * Example 1:
 * Input: s = "()"
 * Output: true
 *
 * Example 2:
 * Input: s = "()[]{}"
 * Output: true
 *
 * Example 3:
 * Input: s = "(]"
 * Output: false
 *
 * Constraints:
 * 1 <= s.length <= 10^4
 * s consists of parentheses only '()[]{}'.
 */

class Solution {
public:
    bool isValid(string s) {
        stack<char> temp;
        int i;

        for (i = 0; i < s.length(); i++) {
            if (temp.empty()) {
                temp.push(s[i]);
            } else if ((temp.top() == '(' && s[i] == ')') ||
                       (temp.top() == '{' && s[i] == '}') ||
                       (temp.top() == '[' && s[i] == ']')) {
                temp.pop();
            } else {
                temp.push(s[i]);
            }
        }

        if (temp.empty()) {
            return true;
        }

        return false;
    }
};
