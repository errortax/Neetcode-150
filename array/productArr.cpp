#include <iostream>
#include <vector>

using namespace std;
//time complexity of below approach is O(n^2) and space complexity is O(n)

// vector<int> productExceptSelf(vector<int> &nums)
// {
//     vector<int> res;
//     for (int i = 0; i < nums.size(); i++)
//     {
//         int product = 1;
//         for (int j = 0; j < nums.size(); j++)
//         {
//             if (i != j)
//             {
//                 product *= nums[j];
//             }
//         }
//         res.push_back(product);
//     }

//     for (int i = 0; i < res.size(); i++)
//     {
//         cout << res[i] << " ";
//     }
// }



//time complexity now O(n) and space complexity is O(n)
vector<int> productExceptSelf(vector<int> &nums)
{
    vector<int> res;
    int n = nums.size();
    vector<int> left(n);
    vector<int> right(n);
    left[0] = 1;
    right[n - 1] = 1;
    for (int i = 1; i < n; i++)
    {
        left[i] = left[i - 1] * nums[i - 1];
    }
    for (int i = n - 2; i >= 0; i--)
    {
        right[i] = right[i + 1] * nums[i + 1];
    }
    for (int i = 0; i < n; i++)
    {
        res.push_back(left[i] * right[i]);
    }
   return res;
}

int main()
{
    vector<int> nums = {1, 2, 4, 6};
    vector<int> res = productExceptSelf(nums);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }



    return 0;
}