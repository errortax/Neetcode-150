//longest consecutive sequence leetcode problem
//time complexity of below approach is O(n) and space complexity is O(n)
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int longestConsecutive(vector<int>& nums) {
    unordered_map<int, int> umap;
    int res = 0;
    for(int x: nums){
        if(umap.find(x) == umap.end()){
            int left = umap.find(x - 1) != umap.end() ? umap[x - 1] : 0;
            int right = umap.find(x + 1) != umap.end() ? umap[x + 1] : 0;
            int sum = left + right + 1;
            umap[x] = sum;
            res = max(res, sum);
            umap[x - left] = sum;
            umap[x + right] = sum;
        }
    }
    //time complexity of above approach is O(n) and space complexity is O(n)
    return res;

}

int main(){
vector<int> nums = {0,3,2,5,4,6,1,1};
cout << longestConsecutive(nums);


}