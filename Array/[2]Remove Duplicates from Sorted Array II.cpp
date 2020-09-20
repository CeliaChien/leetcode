//解法
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<2)return nums.size();
        int index=2;
        for(int i=2; i<nums.size(); i++){
            if(nums[i]!=nums[index-2])
                nums[index++] = nums[i];
        }
        return index;
    }
};

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size(), count = 0;
        for (int i = 2; i < n; i++)
        if (nums[i] == nums[i - 2 - count]) count++;
        else nums[i - count] = nums[i];
        return n - count;
    }
};

//改进
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int const n=nums.size();
        int index=0;
        for (int i = 0; i < n; ++i) {
            if (i > 0 && i < n - 1 && nums[i] == nums[i - 1] && nums[i] == nums[i + 1]) continue;
                nums[index++] = nums[i];
        }
        return index;
    }
};

class Solution {
public:
    
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for (int n : nums)
        if (i < 3 || n > nums[i-3])
            nums[i++] = n;
        return i;
    }
};