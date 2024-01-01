typedef long long ll;

class Solution {
public:


    int lcm(ll a, ll b) {
        
        ll temp = (a*b) / __gcd(a, b) ;
        return temp > INT_MAX ? INT_MAX : temp;
    }

    int minimizeSet(int divisor1, int divisor2, int uc1, int uc2) {

        int s = 1, e = INT_MAX, LCM = lcm(divisor1, divisor2);

        while (s <= e) {

            int mid = s + (e - s) / 2;


            //Multiples of divisor1 jo A ko nhi de skte
            int A_ = mid / divisor1;

            //Toh A ko kya de skte hai
            int A=mid-A_;

            //Multiples of divisor2 jo B ko nhi de skte
            int  B_ = mid / divisor2;

            //Toh B ko kya de skte ha
             int B=mid-B_;


            //Common Multiples of divisor 1 and divisor 2 jo hmne A and B ko de diya hoga

            int common=LCM;


            if (A >=uc1 && B >=uc2 && uc1 + uc2 <= (mid - (mid / common))) {
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return s;
    }
};
