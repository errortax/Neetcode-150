#include <iostream>
#include <vector>

using namespace std;

int singleNumber(vector<int>& nums) {
     int unique =0;
     for( int i: nums){
        unique ^= i;
     }
     return unique;

}

int main(){
    vector<int> nums = {4,1,2,1,2};
    cout << singleNumber(nums);
    return 0;
}
