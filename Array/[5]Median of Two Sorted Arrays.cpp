//解法一

class Solution {
public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
        int m = A.size();
        int n = B.size();
        if(m > n){
            vector<int> temp; 
            temp.assign(A.begin(),A.end());
            A.assign(B.begin(),B.end());
            B.assign(temp.begin(),temp.end());
            int tmp = m; m = n; n = tmp;
        }
        int imin = 0, imax = m, halflen = (m+n+1)/2;
        while(imin <= imax){
            int i = (imin+imax)/2;
            int j = halflen-i;
            if(i < imax && B[j-1]>A[i]){
                imin = i + 1; // i is too small
            }
            else if(i > imin && A[i-1] > B[j]){
                imax = i - 1; // i is too big
            }else{
                int maxleft = 0;
                if(i == 0){maxleft = B[j-1];}
                else if(j == 0){maxleft = A[i-1];}
                else {maxleft = max(A[i-1], B[j-1]);}
                if((m + n) % 2 == 1){return maxleft;}
                
                int minright = 0;
                if(i == m){minright = B[j];}
                else if(j == n){minright = A[i];}
                else {minright = min(A[i], B[j]);}
                
                return (maxleft + minright) / 2.0;
            }
        }
        return 0.0;
    }
};

//解法二

class Solution {
public:
    double findMedianSortedArrays(const vector<int>& A, const vector<int>& B) {
        const int m = A.size();
        const int n = B.size();
        int total = m + n;
        if (total & 0x1)
            return find_kth(A.begin(), m, B.begin(), n, total / 2 + 1);
        else
            return (find_kth(A.begin(), m, B.begin(), n, total / 2) + find_kth(A.begin(), m, B.begin(), n, total / 2 + 1)) / 2.0;
    } 
    private:
    static int find_kth(std::vector<int>::const_iterator A, int m, std::vector<int>::const_iterator B, int n, int k) {
        //always assume that m is equal or smaller than n 
        if (m > n) return find_kth(B, n, A, m, k);
        if (m == 0) return *(B + k - 1);
        if (k == 1) return min(*A, *B);
        //divide k into two parts
        int ia = min(k / 2, m), ib = k - ia; 
        if (*(A + ia - 1) < *(B + ib - 1))
            return find_kth(A + ia, m - ia, B, n, k - ia); 
        else if (*(A + ia - 1) > *(B + ib - 1))
            return find_kth(A, m, B + ib, n - ib, k - ib); 
        else
            return A[ia - 1];
        } 
};