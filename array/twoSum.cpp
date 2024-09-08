#include <iostream>
#include <unordered_map>

using namespace std;
//check if the sum of two numbers in an array is equal to a given target

// //brute force approach
// int* twoSum(int arr[], int n, int target){
//     int* res = new int[2];
//     for(int i = 0; i < n; i++){  
//         for(int j = i+1; j < n; j++){
//             if(arr[i] + arr[j] == target){
//                 res[0] = i;
//                 res[1] = j;
//                 return res;
//             }
//         }
//     }
//     return res;
//     //time complexity of above approach is O(n^2) and space complexity is O(1)
// }


//using unordered_map and one pass
int* twoSum(int arr[], int n, int target){
    int* res = new int[2];
    unordered_map<int, int> umap;
    for(int i = 0; i < n; i++){
        int diff = target - arr[i];
        if(umap.find(diff) != umap.end()){
            res[0] = umap[diff];
            res[1] = i;
            return res;
        }
        umap[arr[i]] = i;
    }
    return res;
    //time complexity of above approach is O(n) and space complexity is O(n)
}

int main(){
    int arr[] = {2, 7, 11, 15};
    int n = sizeof(arr)/sizeof(arr[0]);
    int target = 9;
    int* res = twoSum(arr, n, target);
    cout << "The indices are: " << res[0] << " " << res[1] << endl;
    return 0;
}