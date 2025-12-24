#include <iostream>
#include <vector>
#include <climits>

using namespace std;


// 1. 209.长度最小的子数组
// int main() {
//     // 测试用例
//     int s = 7;
//     vector<int> nums = {2, 3, 1, 2, 4, 3};

//     cout << "输入: s = " << s << ", nums = [";
//     for (size_t i = 0; i < nums.size(); i++) {
//         cout << nums[i];
//         if (i < nums.size() - 1) cout << ", ";
//     }
//     cout << "]" << endl;

//     int result = minSubArrayLen(s, nums);

//     cout << "输出: " << result << endl;
//     return 0;
// }
int32_t minSubArrayLen(int32_t s,std::vector<int32_t> const& nums){
    if (0 == nums.size() && s > 0){
        return INT32_MAX;
    }
    int32_t min_length = INT32_MAX;
    int32_t i = 0; // 虫头
    int32_t j = 0; // 虫尾
    int32_t sum = 0; // 总和

    for(int32_t j{0};j < nums.size();++j){
        sum = sum + nums[j];
        while (sum >= s)
        {
            // 1. 先记录
            int32_t length = (j - i + 1);
            // 2. 比大小
            if (length < min_length){
                min_length = length;
            }
            // 3. 虫子往前
            sum = sum - nums[i];
            i = i + 1;
        }
    }
    return min_length;
}

int main() {
    // 测试用例
    int s = 7;
    vector<int> nums = {2, 3, 1, 2, 4, 3};

    cout << "输入: s = " << s << ", nums = [";
    for (size_t i = 0; i < nums.size(); i++) {
        cout << nums[i];
        if (i < nums.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    int result = minSubArrayLen(s, nums);

    cout << "输出: " << result << endl;
    return 0;
}
