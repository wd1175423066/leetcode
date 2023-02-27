/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 */

// @lc code=start
class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1;
        int j = b.size() - 1;
        int flag = 0;
        string res;
        int temp = 0;
        while(i >= 0 || j >= 0){
            temp += i >= 0 ? (a[i--] - '0') : 0;
            temp += j >= 0 ? (b[j--] - '0') : 0;
            temp += flag;
            res += temp % 2 + '0';
            flag = temp / 2;
            temp = 0;
        }
        if(flag == 1) res += '1';
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end

