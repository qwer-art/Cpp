#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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

// 2. 27. 移除元素
int removeElement(vector<int>& nums, int val){
    if (0 == nums.size()){
        return 0;
    }
    int32_t slow = 0;
    int32_t size = 0;
    for(int32_t fast{0};fast < nums.size();fast++){
        if (nums[fast] != val){
            nums[slow] = nums[fast];
            size++;
            slow++;
        }
    }
    return size;
}

// 3. 344.反转字符串
void reverseString(vector<char>& s) {
    if (0 == s.size()){
        return;
    }
    int32_t start = 0;
    int32_t end = s.size() - 1;
    while (start <= end)
    {
        char keep = s[start];
        s[start] = s[end];
        s[end] = keep;
        start++;
        end--;
    }
    return;
}

// 4. 206. 反转链表
ListNode* reverseList(ListNode* head) {
    ListNode* temp;
    ListNode* cur = head;
    ListNode* pre = nullptr;
    while (cur != nullptr) {
        temp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = temp;
    }
    return pre;
}

// 5. 509. 斐波那契数
class Solution {
public:
    int fib(int n) {
        if (n <= 1){
            return n;
        }
        std::vector<int> dp(n+1);
        // 初始化
        dp[0] = 0;
        dp[1] = 1;
        // 递归
        for(int32_t i{2};i < n + 1;i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};

// 6. 70. 爬楼梯
class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2){
            return n;
        }
        std::vector<int32_t> dp(n+1);
        for(int32_t idx{0};idx <= 2;++idx){
            dp[idx] = idx;
        }
        for(int32_t idx{3};idx < n + 1;++idx){
            dp[idx] = dp[idx-1]+dp[idx-2];
        }
        return dp[n];
    }
};

// 7. 62.不同路径
class Solution {
public:
    int uniquePaths(int m, int n) {
        if (1 == m && 1 == n){
            return 1;
        }
        std::vector<std::vector<int>> dp(m,std::vector<int>(n,0));
        // 1. row_one
        for(int32_t j{1};j < n;++j) {
            dp[0][j] = 1;
        }
        // 2. col_one
        for(int32_t i{1};i < m;++i) {
            dp[i][0] = 1;
        } 
        // 3.dp
        for(int32_t i{1};i < m;++i) {
            for(int32_t j{1};j < n;++j) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};

// 8. 198. 打家劫舍
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        if (nums.size() == 1){
            return nums[0];
        }
        if (nums.size() == 2){
            return std::max(nums[0],nums[1]);
        }
        std::vector<int> max_values(nums.size(),0);
        max_values[0] = nums[0];
        max_values[1] = std::max(nums[0],nums[1]);
        for(int32_t i{2};i < nums.size();++i){
            max_values[i] = std::max(max_values[i-1],max_values[i-2]+nums[i]);
        }
        return max_values.back();
    }
};

int main() {
    // 测试 reverseString
    vector<char> s = {'H', 'a', 'n', 'n', 'a', 'h'};

    cout << "输入: s = [";
    for (size_t i = 0; i < s.size(); i++) {
        cout << "\"" << s[i] << "\"";
        if (i < s.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    reverseString(s);

    cout << "输出: [";
    for (size_t i = 0; i < s.size(); i++) {
        cout << "\"" << s[i] << "\"";
        if (i < s.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
