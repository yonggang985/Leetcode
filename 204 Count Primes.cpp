/*Count Primes 
Description:

Count the number of prime numbers less than a non-negative number, n.
*/

class Solution {
public:
    int countPrimes(int n) 
    {
        if(n<=2)
        {
            return 0;
        }
        double c = sqrt(n);
        bool *bv = new bool[n]; //new��ʼ��ÿ��Ԫ��Ϊfalse
        for(int i=3; i<=c; i +=2) //��3��ʼ������������
        { 
            if(!bv[i])//����������
            {
                for(int j=i*i,k=i<<1; j<n; j +=k) //��չ��ʽΪ������i*i+2i
                {
                    bv[j] = true;
                }
            }
        }
        int num =1;
        for(int i=3; i<n; i +=2) //����������
        {
            if(!bv[i])
            {
                num++;
            }
        }
        delete[] bv;
        return num;
    }
};