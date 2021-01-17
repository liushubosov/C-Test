/*
* 500. 键盘行
*
给定一个单词列表，只返回可以使用在键盘同一行的字母打印出来的单词。键盘如下图所示。

示例：
输入: ["Hello", "Alaska", "Dad", "Peace"]
输出: ["Alaska", "Dad"]

注意：
1.你可以重复使用键盘上同一字符。
2.你可以假设输入的字符串将只包含字母。
*/
/* 
* 解题思路： 
*   键盘有三行，每行用一个字符串 line 表示当前行所有的字符
*   取输入字符串的第一个字符，找出该字符在键盘的哪一行 curLine
*   遍历输入字符串， 如果所有的字符都在 curline ，那么该输入字符串符合规则
* 
*/

vector<string> findWords(vector<string> &words)
{
    vector<string> res;
    if (words.size() == 0)
        return res;
    string line1 = "qwertyuiopQWERTYUIOP", line2 = "asdfghjklASDFGHJKL", line3 = "zxcvbnmZXCVBNM";
    for (int i = 0; i < words.size(); ++i)
    {
        int length = words[i].length();
        if (length != 0)
        {
            string lineN;
            int n = 1;
            if (line1.find(words[i][0]) != string::npos)
                lineN = line1;
            else if (line2.find(words[i][0]) != string::npos)
                lineN = line2;
            else if (line3.find(words[i][0]) != string::npos)
                lineN = line3;
            for (int j = 1; j < length; ++j)
            {
                if (lineN.find(words[i][j]) != string::npos)
                    ++n;
                else
                    break;
            }
            if (n == length)
                res.push_back(words[i]);
        }
    }

    return res;
}