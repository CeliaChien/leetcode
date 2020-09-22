//解法一
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int i=0;
        while(i<nums.size()){
            if(nums[i]==target)return true;
            i++;
        }
        return false;
    }
};
//解法二
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int first = 0, last = nums.size();
        while (first != last) {
            const int mid = first + (last - first) / 2; 
            if (nums[mid] == target)
                  return true;
            if (nums[first] < nums[mid]) {
                if (nums[first] <= target && target < nums[mid]) 
                    last = mid;
                else
                    first = mid + 1;
            } else if (nums[first] > nums[mid]) {
                if (nums[mid] < target && target <= nums[last-1])
                    first = mid + 1; else
                        last = mid; 
            } else
                  //skip duplicate one
                  first++;
        }
        return false;
    }
};