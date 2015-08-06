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
        bool *bv = new bool[n]; //new初始化每个元素为false
        for(int i=3; i<=c; i +=2) //从3开始，仅考虑奇数
        { 
            if(!bv[i])//仅考虑质数
            {
                for(int j=i*i,k=i<<1; j<n; j +=k) //扩展方式为奇数：i*i+2i
                {
                    bv[j] = true;
                }
            }
        }
        int num =1;
        for(int i=3; i<n; i +=2) //仅考虑奇数
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