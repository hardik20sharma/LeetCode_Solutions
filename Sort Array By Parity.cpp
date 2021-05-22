class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& a)
    {
        for(int i = 0, j = 0; i < a.size(); i++)
            if(a[i] % 2 == 0)
                swap(a[j++], a[i]);

        return a;
    }
};

/*
    Basically we need to put all even numbers first in array, and all odd numbers after.
    
    We use two pointer technique in this
*/
