#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

// bool isAnagram(string s, string t) {
//     if (s.length() != t.length()) return false;

//     unordered_map<char, int> count;
//     for (char c : s) {
//         count[c]++;
//     }
//     for (char c : t) {
//         if (count.find(c) == count.end() || count[c] == 0) {
//             return false;
//         }
//         count[c]--;
//     }

//     //time complexity of above approach is O(n) and space complexity is O(n)
//     return true;
// }


//using sorting
bool isAnagram(string s, string t) {
    if (s.length() != t.length()) return false;

    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    //time complexity of above approach is O(nlogn) and space complexity is O(1)
    return s == t;
}

int main() {
    string s = "anagram";
    string t = "nagaram";

    if (isAnagram(s, t)) {
        cout << "The strings are anagrams." << endl;
    } else {
        cout << "The strings are not anagrams." << endl;
    }

    return 0;
}