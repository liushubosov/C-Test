/*
* 441. 排列硬币

* 你总共有 n 枚硬币，你需要将它们摆成一个阶梯形状，第 k 行就必须正好有 k 枚硬币。
* 给定一个数字 n，找出可形成完整阶梯行的总行数。
* n 是一个非负整数，并且在32位有符号整型的范围内。
* 
* 解题思路01，
* sum = 1+2+3+...+i,当 sum > n 时，表明 最多只能摆 i-1 行
*/
int arrangeCoins01(long n)
{
    if (n < 2)
        return n;
    long sum = 0;
    int i;
    for (i = 1; i < n; ++i)
    {
        sum += i;
        if (sum > n)
            break;
    }
    return i - 1;
}

/*
* 解题思路02，
* 1+2+3+...+m, 求和公式 :(m+1)*m/2
* 利用二分法，计算 m 的位置
*/
int arrangeCoins02(long n)
{
    if (n < 2)
        return n;
    long left = 0, right = n, s = 0;
    while (left <= right)
    {
        long mid = left + (right - left) / 2;
        s = mid * (mid + 1) / 2;
        if (s == n)
            return mid;
        else if (s > n)
            right = mid - 1;
        else
            left = mid + 1;
    }

    return left > right ? right : left;
}