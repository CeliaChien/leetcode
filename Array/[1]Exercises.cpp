//Remove Element
//原题链接：https://leetcode.com/problems/remove-element/
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.empty())return 0;
        int index=0;
        for(int n:nums)
         if(n!=val) nums[index++]=n; 
        return index;
    } 
};

//Move Zeroes
//https://leetcode.com/problems/move-zeroes/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int index=0, count=0;
        for(int n:nums)
            if(n!=0){nums[index++]=n;count++;}
        while(count!=nums.size()){
            nums[count]=0;
            count++;
        }
    }
};

//Shortest Subarray to be Removed to Make Array Sorted
//原题链接：https://leetcode.com/problems/shortest-subarray-to-be-removed-to-make-array-sorted/
class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& A) {
        int N = A.size(), left = 0, right = N - 1;
        while (left + 1 < N && A[left] <= A[left + 1]) ++left;
        if (left == A.size() - 1) return 0;
        while (right > left && A[right - 1] <= A[right]) --right;
        int ans = min(N - left - 1, right), i = 0, j = right;
        while (i <= left && j < N) {
            if (A[j] >= A[i]) {
                ans = min(ans, j - i - 1);
                ++i;
            } else ++j;
        }
        return ans;
    }
};

//Remove Covered Intervals
//原题链接：https://leetcode.com/problems/remove-covered-intervals/
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& A) {
        int res = 0, left = -1, right = -1;
        sort(A.begin(), A.end());
        for (auto& v: A) {
            if (v[0] > left && v[1] > right) {
                left = v[0];
                ++res;
            }
            right = max(right, v[1]);
        }
        return res;
    }
};