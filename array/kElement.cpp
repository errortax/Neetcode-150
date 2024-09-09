//top k element

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

// vector<int> topKFrequent(vector<int>& nums, int k) {
//     unordered_map<int, int> umap;
//     for(int x: nums){
//         umap[x]++;
//     }
//     priority_queue<pair<int, int>, vector<pair<int, int>>, 
//     greater<pair<int, int>>> pq;

//     for(auto x: umap){
//         pq.push({x.second, x.first});
//         if(pq.size() > k){
//             pq.pop();
//         }
//     }
//     vector<int> res;
//     while(!pq.empty()){
//         res.push_back(pq.top().second);
//         pq.pop();
//     }
//     return res;
//     //time complexity of above approach is O(nlogk) and space complexity is O(n)
// }


//using bucket sort and size of bucket is equal to the size of input array
vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> umap;
    for (size_t i = 0; i < nums.size(); ++i) {
        int x = nums[i];
        umap[x]++;
    }
    /*   for(int x: nums){
        umap[x]++;
    }*/

    vector<vector<int>> bucket(nums.size() + 1);
    for (auto it = umap.begin(); it != umap.end(); ++it) {
        int frequency = it->second;
        int num = it->first;
        bucket[frequency].push_back(num);
    }
    
    /* for(auto it: umap){
        bucket[it.second].push_back(it.first);
    }*/


    vector<int> res;
    for (int i = bucket.size() - 1; i >= 0; --i) {
        for (size_t j = 0; j < bucket[i].size(); ++j) {
            res.push_back(bucket[i][j]);
            if (res.size() == k) {
                return res;
            }
        }
    }


    return res; // Add this line to ensure the function returns a value in all cases
}


int main(){
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;
    vector<int> res = topKFrequent(nums, k);
    for(int x: res){
        cout << x << " ";
    }
    return 0;
}