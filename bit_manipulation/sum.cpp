#include <iostream>

using namespace std;

 int getSum(int a, int b) {
        int carr = (a&b)<<1;
        int res=a^b;
        if(carr == 0){
            return res;
        }else{
            getSum(carr,res);
        }
    }

    int main(){
        int a = 1;
        int b = 2;
        cout << getSum(a,b);
        return 0;
    }