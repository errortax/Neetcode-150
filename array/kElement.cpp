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
    for(int x: nums){
        umap[x]++;
    }
    vector<vector<int>> bucket(nums.size() + 1);
    for(auto x: umap){
        bucket[x.second].push_back(x.first);
    }
    vector<int> res;
    for(int i = bucket.size() - 1; i >= 0; i--){
        for(int j = 0; j < bucket[i].size(); j++){
            res.push_back(bucket[i][j]);
            if(res.size() == k){
                return res;
            }
        }
    }
    return res;
    //time complexity of above approach is O(n) and space complexity is O(n)
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