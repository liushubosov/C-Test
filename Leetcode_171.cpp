/*
* 171. Excel表列序号
*
给定一个Excel表格中的列名称，返回其相应的列序号。
例如，

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
    ...

* 
* 解题思路： 
*   注意进位可能超出 int 的最大范围，应该用 long long 定义
*/

class Solution {
public:
    int titleToNumber(string s) {
        int sum = 0;
        long long base = 1;
        for(int i=s.length()-1;i>=0;--i){
            sum += (base * (s.at(i) - 'A' + 1));
            base *= 26;
        }
        return sum;
    }
};