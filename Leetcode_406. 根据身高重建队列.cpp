//406. 根据身高重建队列
/*
假设有打乱顺序的一群人站成一个队列，数组 people 表示队列中一些人的属性（不一定按顺序）。每个 people[i] = [hi, ki] 表示第 i 个人的身高为 hi ，前面 正好 有 ki 个身高大于或等于 hi 的人。

请你重新构造并返回输入数组 people 所表示的队列。返回的队列应该格式化为数组 queue ，其中 queue[j] = [hj, kj] 是队列中第 j 个人的属性（queue[0] 是排在队列前面的人）。

提示：
1 <= people.length <= 2000
0 <= hi <= 106
0 <= ki < people.length
题目数据确保队列可以被重建

*/
/*
解题思路：有两个维度，h 和 k ，必须确定一个维度，再按照另一个维度重新排列。
按照高度来，从高到低排列，高度相等的k越小越靠前。
然后再按 k 来插队，k=2就直接插到数组2的位置。
贪婪算法，局部最优即全局最优
*/


class Solution {

// private: //使用成员比较函数，感觉没必要，换成lambda表达式
//     static bool myCompare(const vector<int>& v1, const vector<int>& v2){
//         if(v1.front() > v2.front())
//             return true;
//         else if(v1.front() == v2.front())
//         {
//             if(v1.back() < v2.back())
//                 return true;
//         }
//         return false;
//     }
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        //按照高度从高到低排序，高度一致的k越小越靠前
        //std::sort(people.begin(), people.end(), myCompare);
        std::sort(people.begin(), people.end(), 
        [] (const vector<int>& v1, const vector<int>& v2) -> bool
        {
            if(v1.front() > v2.front())
                return true;
            else if(v1.front() == v2.front())
            {
                if(v1.back() < v2.back())
                    return true;
            }
            return false;
        });

        //根据k大小重新排列顺序
        //vector<vector<int>> vtr;  //使用 vector 插入操作很慢，改用list
        list<vector<int>> vtr;
        for(int i=0; i < people.size(); ++i)
        {
            //vtr.insert(vtr.begin()+people[i].back(), people[i]);
            if(people[i].back() != vtr.size())
            {
                auto iter = vtr.begin();
                for(int j=0;j < people[i].back();++j)
                {
                    ++iter;
                }
                vtr.insert(iter, people[i]);
            }
            else{
                vtr.push_back(people[i]);
            }
        }
        //return vtr;
        return vector<vector<int>>(vtr.begin(), vtr.end());
    }
};