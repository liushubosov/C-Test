/*
* 506. 相对名次
*
给出 N 名运动员的成绩，找出他们的相对名次并授予前三名对应的奖牌。前三名运动员将会被分别授予 “金牌”，“银牌” 和“ 铜牌”（"Gold Medal", "Silver Medal", "Bronze Medal"）。

(注：分数越高的选手，排名越靠前。)
示例 1:

输入: [5, 4, 3, 2, 1]
输出: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
解释: 前三名运动员的成绩为前三高的，因此将会分别被授予 “金牌”，“银牌”和“铜牌” ("Gold Medal", "Silver Medal" and "Bronze Medal").
余下的两名运动员，我们只需要通过他们的成绩计算将其相对名次即可。

1.N 是一个正整数并且不会超过 10000。
2.所有运动员的成绩都不相同。
* 
* 解题思路： 
*   利用Node记录成绩和位置
*   
*   
*/

class Solution
{
public:
    struct Node
    {
        int index;
        int score;
        Node(int i, int s) : index(i), score(s){};
        bool operator<(const Node &other) const
        {
            return score > other.score;
        }
    };
    string trans(int i)
    {
        if (i == 0)
            return "Gold Medal";
        if (i == 1)
            return "Silver Medal";
        if (i == 2)
            return "Bronze Medal";
        return to_string(i + 1);
    }
    vector<string> findRelativeRanks(vector<int> &nums)
    {
        int N = nums.size();
        vector<Node> nodes;
        for (int i = 0; i < N; ++i)
        {
            nodes.push_back(Node(i, nums[i]));
        }
        sort(nodes.begin(), nodes.end());
        vector<string> res(N);
        for (int i = 0; i < N; ++i)
        {
            res[nodes[i].index] = trans(i);
        }
        return res;
    }
};