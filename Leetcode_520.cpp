/*
* 520. 检测大写字母
*
给定一个单词，你需要判断单词的大写使用是否正确。

我们定义，在以下情况时，单词的大写用法是正确的：

全部字母都是大写，比如"USA"。
单词中所有字母都不是大写，比如"leetcode"。
如果单词不只含有一个字母，只有首字母大写， 比如 "Google"。
否则，我们定义这个单词没有正确使用大写字母。

示例 1：
输入: "USA"
输出: True

输入: "FlaG"
输出: False
*/
/* 
* 解题思路： 
*   长度等于1， 直接返回 true ;
*   判断第一个字符和第二个字符的情况，如果出现 aB ， 直接返回 false;
*   然后 以第二个字符的大小写为基准，二位以后的字符大小写情况需要跟第二个字符情况保持一致.
* 
*/

bool detectCapitalUse(string word)
{
    int length = word.length();
    if (length < 2)
        return true;
    bool bUpper = false;
    if (word[1] < 'a')
        bUpper = true;
    if (word[0] >= 'a' && bUpper)
        return false;
    for (int i = 2; i < length; ++i)
    {
        if (!bUpper && word[i] < 'a')
            return false;
        else if (bUpper && word[i] >= 'a')
            return false;
    }
    return true;
}