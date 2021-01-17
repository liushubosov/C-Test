/*
* 748. 最短补全词
*
给定一个字符串牌照 licensePlate 和一个字符串数组 words ，请你找出并返回 words 中的 最短补全词 。
如果单词列表（words）中的一个单词包含牌照（licensePlate）中所有的字母，那么我们称之为 补全词 。在所有完整词中，最短的单词我们称之为 最短补全词 。
单词在匹配牌照中的字母时要：
忽略牌照中的数字和空格。
不区分大小写，比如牌照中的 "P" 依然可以匹配单词中的 "p" 字母。
如果某个字母在牌照中出现不止一次，那么该字母在补全词中的出现次数应当一致或者更多。
例如：licensePlate = "aBc 12c"，那么它由字母 'a'、'b' （忽略大写）和两个 'c' 。
可能的 补全词 是 "abccdef"、"caaacab" 以及 "cbca" 。
题目数据保证一定存在一个最短补全词。当有多个单词都符合最短补全词的匹配条件时取单词列表中最靠前的一个。

示例 1：
输入：licensePlate = "1s3 PSt", words = ["step", "steps", "stripe", "stepple"]
输出："steps"
说明：最短补全词应该包括 "s"、"p"、"s" 以及 "t"。在匹配过程中我们忽略牌照中的大小写。
"step" 包含 "t"、"p"，但只包含一个 "s"，所以它不符合条件。
"steps" 包含 "t"、"p" 和两个 "s"。
"stripe" 缺一个 "s"。
"stepple" 缺一个 "s"。
因此，"steps" 是唯一一个包含所有字母的单词，也是本样例的答案。

示例 2：
输入：licensePlate = "1s3 456", words = ["looks", "pest", "stew", "show"]
输出："pest"
说明：存在 3 个包含字母 "s" 且有着最短长度的补全词，"pest"、"stew"、和 "show" 三者长度相同，但我们返回最先出现的补全词 "pest" 。

注意：
    1 <= licensePlate.length <= 7
    licensePlate 由数字、大小写字母或空格 ' ' 组成
    1 <= words.length <= 1000
    1 <= words[i].length <= 15
    words[i] 由小写英文字母组成

* 
* 解题思路： 
*   略
*/

class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        int mylist[26]={0};
        for(const auto &c : licensePlate){
            if(c > '9')
                ++mylist[(c|32)-'a'];
        }
        string res;
        for(const auto &s : words){
            int curList[26]={0};
            for(const auto &c : s){
                ++curList[c - 'a'];
            }
            int i=0;
            for(;i < 26;++i){
                if(curList[i] < mylist[i])
                    break;
            }
            if(i == 26 && (res.empty() || res.length() > s.length()))
                res = s;
        }
        return res;
    }
};