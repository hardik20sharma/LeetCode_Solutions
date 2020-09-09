class Solution {
public:
    int removeDuplicates(vector<int>& a)
    {
        int j = 0, n = a.size();
        
        if(n==0 || n==1)
            return n;
        
        for(int i = 0; i < n-1; i++)
            if(a[i] != a[i+1])
                a[j++] = a[i];
        a[j++]=a[n-1];
        
        return j;
    }
};
