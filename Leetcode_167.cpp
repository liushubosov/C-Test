/*
* 167. 两数之和 II - 输入有序数组
*
给定一个已按照 升序排列  的整数数组 numbers ，请你从数组中找出两个数满足相加之和等于目标数 target 。
函数应该以长度为 2 的整数数组的形式返回这两个数的下标值。numbers 的下标 从 1 开始计数 ，所以答案数组应当满足 1 <= answer[0] < answer[1] <= numbers.length 。
你可以假设每个输入只对应唯一的答案，而且你不可以重复使用相同的元素。

提示：
2 <= numbers.length <= 3 * 104
-1000 <= numbers[i] <= 1000
numbers 按 递增顺序 排列
-1000 <= target <= 1000
仅存在一个有效答案

* 
* 解题思路： 
*   双指针
*/
class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int low = 0;
        int high = numbers.length - 1;
        while(low < high)
        {     
            int sum = numbers[low] + numbers[high];
            if(sum < target)
            {
                ++low;
            }else if(sum == target)               
            {
                int[] res = new int[2];
                res[0] = ++low;
                res[1] = ++high;
                return res;
            }else
                --high;
        }
        return new int[0];
    }
}