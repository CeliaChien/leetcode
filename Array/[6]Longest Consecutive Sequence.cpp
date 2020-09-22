//解法一
class Solution {
private:
    bool arrayContains(const vector<int>& nums, int num){
        for(auto n: nums){
            if(n==num)return true;
        }
        return false;
    }
public:
    int longestConsecutive(vector<int>& nums) {
        int longestLen=0;
        for(int n : nums){
            int currNum=n;
            int currLen=1;
            while(arrayContains(nums, currNum+1)){
                currNum++;
                currLen++;
            }
            longestLen=max(longestLen, currLen);
        }
        return longestLen;
    }
};

//解法二

class Solution {
private:
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0)return 0;
        sort(nums.begin(),nums.end());
        int longestLen=1;
        int currLen=1;
        for(int i=1; i<nums.size(); i++){
            if(nums[i]!=nums[i-1]){
                if(nums[i] == nums[i-1]+1){
                    currLen++;
                }else{
                    longestLen = max(longestLen, currLen);
                    currLen=1;
                }
            }
        }
        return max(longestLen, currLen);
    }
};

//解法三
//使用set
class Solution {
private:
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0)return 0;
        unordered_set<int> seen;
        for(int n:nums){
            seen.insert(n);
        }
        int longestLen=0;
        
        for(int n:nums){
            if(!seen.count(n-1)){
                int currNum=n;
                int currLen=1;
                while(seen.count(currNum+1)){
                    currNum++;
                    currLen++;
                }
                longestLen = max(longestLen, currLen);
            }
        }
        return longestLen;
    }
};

//使用map
class Solution {
    public:
    int longestConsecutive(const vector<int> &nums) { 
        unordered_map<int, bool> used;                                             
        for (auto i : nums) used[i] = false;
        int longest = 0;
        for (auto i : nums) {
            if (used[i]) continue;
            int length = 1;
            used[i] = true;
            for (int j = i + 1; used.find(j) != used.end(); ++j) { 
                used[j] = true;
                ++length; 
            }
            for (int j = i - 1; used.find(j) != used.end(); --j) { 
                used[j] = true;
                ++length; 
            }
            longest = max(longest, length); 
        }
        return longest;
      }
};