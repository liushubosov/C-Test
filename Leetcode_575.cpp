/*
* 575. 分糖果
*
* 给定一个偶数长度的数组，其中不同的数字代表着不同种类的糖果，每一个数字代表一个糖果。你需要把这些糖果平均分给一个弟弟和一个妹妹。返回妹妹可以获得的最大糖果的种类数。
* 示例 1:
*
* 输入: candies = [1,1,2,2,3,3]
* 输出: 3
* 解析: 一共有三种种类的糖果，每一种都有两个。
*     最优分配方案：妹妹获得[1,2,3],弟弟也获得[1,2,3]。这样使妹妹获得糖果的种类数最多。
* 
* 解题思路： 
*   用 set 计算糖果种类
*   妹妹可以分到 n/2 个糖， 所以如果糖种类超过 n/2, 妹妹也分不到，应该立即 return n/2;
*/

string addStrings(string num1, string num2)
{
    string res;
    int i = num1.size() - 1;
    int j = num2.size() - 1;
    int add = 0;
    while (i >= 0 || j >= 0 || add != 0)
    {
        int a, b;
        a = i < 0 ? 0 : num1[i] - '0';
        b = j < 0 ? 0 : num2[j] - '0';
        int sum = a + b + add;
        res.push_back(sum % 10 + '0');
        add = sum / 10;
        i--;
        j--;
    }

    reverse(res.begin(), res.end());
    return res;
}