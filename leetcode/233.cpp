class Solution {
public:
    int countDigitOne(int n) {
        long long sum = 0;
        long long temp = n;
        long long ans = 1;
        while(temp) {
            if(temp % 10 == 0) {
                sum += (temp / 10) * ans; 
            }
            if(temp % 10 == 1) {
                sum += (temp / 10) * ans + 1 + n % ans;
            }
            if(temp % 10 > 1) {
                sum += (temp / 10 + 1) * ans;
            }
            temp /= 10;
            ans *= 10;
        }
        return sum;
    }
};