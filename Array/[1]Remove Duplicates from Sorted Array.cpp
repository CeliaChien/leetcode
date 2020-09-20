//解法一
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int index = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[index] != nums[i]) nums[++index] = nums[i];
        }
          return index + 1;
    }
};

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int index = 0;
        int n=nums.size();
        for(int i = 1; i < n; i++){
            if(nums[i] == nums[i-1]) index++;
            else nums[i-index] = nums[i];
        }
        return n-index;
    }
};

//解法二
class Solution {
    public:
    int removeDuplicates(vector<int>& nums) {
        return distance(nums.begin(), unique(nums.begin(), nums.end()));
    } 
};

//解法三
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        return distance(nums.begin(), removeDuplicates(nums.begin(),nums.end(), nums.begin()));
    }
    template<typename InIt, typename OutIt>OutIt removeDuplicates(InIt first, InIt last, OutIt output) {
        while (first != last) {
            *output++ = *first;
            first = upper_bound(first, last, *first);
        }
        return output;
    }
};


