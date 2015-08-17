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
        string result = ""; //�������
        int ia = a.size()-1; //��һ��ָ��
        int ib = b.size()-1; //�ڶ���ָ��
        int sum = 0;  //���ֺ�
        while(ia>=0 || ib>=0) //����
        {
            int va = 0; //��ʱ��������
            int vb = 0; //��ʱ��������
            if(ia>=0)
            {
                va = a[ia] - '0'; //�ַ���ת��Ϊ�������
                ia--;  //ָ���ƶ�1λ
            }
            if(ib>=0)
            {
                vb = b[ib] - '0'; 
                ib--;
            }
            sum += va+vb; //���ֺ�
            result = (sum%2 == 0 ? "0" : "1") + result; //�ж���Ӻ��λ������ַ�������
            sum /= 2; //������λ
        }
        if(sum==1) //������н�λ
        {
            result = "1" + result;
        }
        return result;
    }
};