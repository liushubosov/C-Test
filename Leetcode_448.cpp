/*
* 448. 找到所有数组中消失的数字

* 给定一个范围在  1 ≤ a[i] ≤ n ( n = 数组大小 ) 的 整型数组，数组中的元素一些出现了两次，另一些只出现一次。
* 找到所有在 [1, n] 范围之间没有出现在数组中的数字。
* 您能在不使用额外空间且时间复杂度为O(n)的情况下完成这个任务吗? 你可以假定返回的数组不算在额外空间内。
* 
* 解题思路，
* 第一次遍历， 以数组的 value 作为下标，把下标处的值变为负数
* 第二次遍历， 找出值为正数的下标，说明该下标未在数组中出现过
*/
vector<int> findDisappearedNumbers(vector<int> &nums)
{
    vector<int> vtr;
    for (int i = 0; i < nums.size(); ++i)
    {
        int newIndex = abs(nums[i]) - 1;
        if (nums[newIndex] > 0)
            nums[newIndex] *= -1;
    }

    for (int j = 0; j < nums.size(); ++j)
    {
        if (nums[j] > 0)
            vtr.push_back(j + 1);
    }

    return vtr;
}