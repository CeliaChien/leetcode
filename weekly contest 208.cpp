
class Solution {
public:
    int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {
        vector<int> profit;
        int sum=0, times=1;
        for(int n:customers){
            sum=sum+n;
        }
        while(sum>0){
            if(sum>4){
                profit.push_back(boardingCost*4*times-runningCost*times);
            }else{
                profit.push_back(boardingCost*4*(times-1)+boardingCost*sum-runningCost*times);
            } 
            sum=sum-4;
            times++;
        }
        int max=0, maxSite=0;
        for(int i=0; i<profit.size(); i++){
            if(max<profit[i]) {
                max=profit[i];
                maxSite=i;
            }
        }
        return profit[maxSite]>0? maxSite+1:-1;
    }
};

class Solution {
public:
    int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {
        int maxProfit = INT_MIN;
        int min=0, i=0, remaining= customers[i];
        int totalboarded=0;
        while(true){
            int board = remaining>3? 4:remaining;
            remaining-= board;
            totalboarded+=board;
            
            if(i+1<customers.size()){
                remaining +=customers[i+1];
            }
            i++;
            int currentProfit=(totalboarded*boardingCost)-(i*runningCost);
            if(currentProfit>maxProfit){
                min=i;
            }
            maxProfit=max(maxProfit,(totalboarded*boardingCost)-(i*runningCost));
            if(remaining==0){
                break;
            }
        }
        return maxProfit<=0? -1:min;
    }
};
