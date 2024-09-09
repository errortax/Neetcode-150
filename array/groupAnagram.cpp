//group all anagrams together into sublists
//time complexity of below approach is O(nklogk) and space complexity is O(nk)
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> umap;
    for(string s: strs){
        string temp = s;
        sort(temp.begin(), temp.end());
        umap[temp].push_back(s);
    }
    vector<vector<string>> res;
    for(auto x: umap){
        res.push_back(x.second);
    }
    return res;
}

int main(){
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> res = groupAnagrams(strs);
    for(auto x: res){
        for(auto y: x){
            cout << y << " ";
        }
        cout << endl;
    }
    return 0;
}
