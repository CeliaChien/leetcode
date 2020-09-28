//Search Insert Position
//解法一
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int i=0,site=0;
        while(i<nums.size()){
            if(nums[i]<target) site++;
            i++;
        }
        return site;
    }
};

//解法二
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int min=0;
        int max=nums.size()-1;
        
        if (target<nums[min]) {return min;}
        else if(target>nums[max]) {return max+1;}
        else{
            while(min<=max){
                int mid=min + (max-min)/2;
                if(target<=nums[mid]) {max=mid-1; }
                else {min=mid+1;}
            }
            return min;
        }
    }
};