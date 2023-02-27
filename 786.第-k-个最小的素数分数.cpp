/*
 * @lc app=leetcode.cn id=786 lang=cpp
 *
 * [786] 第 K 个最小的素数分数
 */

// @lc code=start
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        double l = 0;
        double r = 1.0;
        while(l < r){
            double mid = (l + r) / 2;
            //cal num of ele smaller than mid, record max ele smaller than mid
            int p = 0;
            int q = 0;
            double max = 0.0;
            int total = 0;
            for(int i = 0, j = 1; i < n - 1; ++i){
                while(j < n && arr[i] > mid * arr[j]){
                    ++j;
                }
                if(j == n){
                    break;
                }
                total += (n - j);
                const double f = static_cast<double>(arr[i]) / arr[j];
                if(f > max){
                    p = i;
                    q = j;
                    max = f;
                }
            }
            if(total == k){
                return {arr[p], arr[q]};
            }
            else if(total > k){
                r = mid;
            }
            else{
                l = mid;
            }
        }
        return {};
    }
};
// @lc code=end

