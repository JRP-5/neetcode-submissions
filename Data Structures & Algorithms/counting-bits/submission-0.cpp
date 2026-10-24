class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> arr(n+1);
        arr[0] = 0;
        int power = 1;
        int i = 1;
        while(i <= n){
            arr[i] = arr[i-power]+1;
            i++;
            if(i == power *2){
                power = power*2;
            }
        }
        return arr;
    }
};
