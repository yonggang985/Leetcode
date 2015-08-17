/*	67	Add Binary
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".

Hide Tags Math String
Hide Similar Problems (M) Add Two Numbers (M) Multiply Strings (E) Plus One

*/


class Solution {
public:
    string addBinary(string a, string b) 
    {
        string result = ""; //保留结果
        int ia = a.size()-1; //第一个指针
        int ib = b.size()-1; //第二个指针
        int sum = 0;  //部分和
        while(ia>=0 || ib>=0) //遍历
        {
            int va = 0; //临时辅助变量
            int vb = 0; //临时辅助变量
            if(ia>=0)
            {
                va = a[ia] - '0'; //字符串转化为数字相减
                ia--;  //指针移动1位
            }
            if(ib>=0)
            {
                vb = b[ib] - '0'; 
                ib--;
            }
            sum += va+vb; //部分和
            result = (sum%2 == 0 ? "0" : "1") + result; //判断相加后个位情况，字符串连接
            sum /= 2; //保留进位
        }
        if(sum==1) //如果还有进位
        {
            result = "1" + result;
        }
        return result;
    }
};