class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        bool ans=true;
        int five=0, ten=0;
        int n = bills.size();
        for(int i=0; i<n; i++){
            if(bills[i]==5){
                ans=true;
                five++;
            }
            else if(bills[i]==10){
                if(five>=1){
                    ans=true;
                    ten++;
                    five--;
                }
                else return false;
            }
            else{
                if(five>=1&&ten>=1){
                    ans=true;
                    five--;
                    ten--;
                }
                else if(five>=3){
                    ans=true;
                    five-=3;
                }
                else return false;
            }
        }
        return ans;
    }
};