#include <iostream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int main(){
    //brute force approach for finiding a duplicate element in an array
    // int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 1};
    // int n = sizeof(arr)/sizeof(arr[0]);
    // for(int i = 0; i < n; i++){
    //     for(int j = i+1; j < n; j++){
    //         if(arr[i] == arr[j]){
    //             cout << "Duplicate element is: " << arr[i] << endl;
    //             break;
    //         }
    //     }
    // }

    // time complexity of above approach is O(n^2) and space complexity is O(1)

  //using unordered_map
    // int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 1};
    // int n = sizeof(arr)/sizeof(arr[0]);
    // unordered_map<int, int> umap;
    // for(int i = 0; i < n; i++){
    //     umap[arr[i]]++;
    // }
    // for(auto x: umap){
    //     if(x.second > 1){
    //         cout << "Duplicate element is: " << x.first << endl;
    //     }
    // }

    //time complexity of above approach is O(n) and space complexity is O(n)    

    //using set
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    unordered_set<int> uset;
    for(int i = 0; i < n; i++){
        if(uset.find(arr[i]) != uset.end()){
            cout << "Duplicate element is: " << arr[i] << endl;
        }
        else{
            uset.insert(arr[i]);
        }
    }

    //time complexity of above approach is O(n) and space complexity is O(n)
    
    return 0;
}