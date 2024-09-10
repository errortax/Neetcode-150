//encode and decode string leetcode problem
//time complexity of below approach is O(nk) and space complexity is O(nk)
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

string encode(vector<string>& strs) {
    string res = "";
    for(string s: strs){
        res += to_string(s.size()) + "@" + s;
    }
    return res;
}

vector<string> decode(string s) {
    vector<string> res;
    int i = 0;
    while(i < s.size()){
        int at = s.find('@', i);
        int len = stoi(s.substr(i, at - i));
        res.push_back(s.substr(at + 1, len));
        i = at + len + 1;
    }
    return res;
}

int main(){
    vector<string> strs = {"hello", "world", "this", "is", "a", "test"};
    string encoded = encode(strs);
    cout << "Encoded string: " << encoded << endl;
    vector<string> decoded = decode(encoded);
    cout << "Decoded string: ";
    for(string s: decoded){
        cout << s << " ";
    }
    return 0;
}   

