class Solution {
public:
    bool bsearch(int start,int end,int num)
    {
        if(start>end)
            return false;
        long mid=(start)+(end-start)/2;
        if(mid*mid==num)
            return true;
        if(mid*mid>num)
            return bsearch(start,mid-1,num);
        return bsearch(mid+1,end,num);
    }
    bool judgeSquareSum(int c) 
    {
        for(long a=0;a*a<=c;a++)
        {
            int b=c-int(a*a);
            if(bsearch(0,b,b))
                return true;
        }
        return false;
    }
};