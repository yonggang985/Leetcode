/*	8	String to Integer (atoi)
Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.

Update (2015-02-10):
The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button  to reset your code definition.

spoilers alert... click to show requirements for atoi.

Requirements for atoi:
The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned. If the correct value is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.

Hide Tags Math String
Hide Similar Problems (E) Reverse Integer (H) Valid Number

*/

class Solution {
public:
    int myAtoi(string str)   // string to int  
    {
        long result = 0;
        int indicator = 1; //默认为正号
        int i = str.find_first_not_of(' ');  //找到第一个非空的
        if(str[i] == '-' || str[i] == '+') //判断正负号
        {
            indicator = (str[i++] == '-')? -1 : 1;
        }
        while('0'<= str[i] && str[i] <= '9') //循环的条件，能转化为数字。字符串最后一个为'/0'
        {
            result = result*10 + (str[i++]-'0'); //部分和
            if(result*indicator >= INT_MAX) //正溢出
            {
                return INT_MAX;
            }
            if(result*indicator <= INT_MIN) //负溢出
            {
                return INT_MIN;
            }
        }
        return result*indicator; //返回结果
    }
};