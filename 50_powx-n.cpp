/*
 * [50] Pow(x, n)
 *
 * https://leetcode.com/problems/powx-n/
 *
 * Example 1:
 * Input: x = 2.00000, n = 10
 * Output: 1024.00000
 *
 * Example 2:
 * Input: x = 2.10000, n = 3
 * Output: 9.26100
 *
 * Example 3:
 * Input: x = 2.00000, n = -2
 * Output: 0.25000
 * Explanation: 2^-2 = 1/2^2 = 1/4 = 0.25
 *
 * Constraints:
 * -100.0 < x < 100.0
 * -2^31 <= n <= 2^31-1
 * -10^4 <= xn <= 10^4
 */
 
/***** 迭代 *****/
class Solution {
public:
    double myPow(double x, int n) {
        double res = 1.0;
        for (int i = n; i != 0 ; i /= 2) {
            if (i % 2 != 0) { // same as i & 1
                res *= x;
            }
            x *= x;
        }
        return (n < 0) ? 1 / res : res;
    }
};

/***** 遞迴快速冪 *****/
class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1;
        if (n == 1) return x;
        if (n == -1) return 1 / x;
        double temp = myPow(x, n >> 1);
        if (n & 1) return temp * temp * x;
        return temp * temp;
    }
};

/***** 迭代快速冪 *****/
class Solution { 
public:
    double myPow(double x, int n) { 
        double res = 1, base = x;
        bool positive = (n >= 0);
        while (n) {
            if (n & 1) res *= base;
            base *= base;
            n /= 2;
        }
        return positive ? res : 1 / res;
    }
};
