#define box vector<int>

class Solution {

    static bool cmp(box b1, box b2)
    {
        return b1[1] > b2[1];
    }
    
public:

    int maximumUnits(vector<box>& boxTypes, int truckSize)
    {
        sort(boxTypes.begin(), boxTypes.end(), cmp);
        
        int res = 0;
        
        for(int i = 0; i < boxTypes.size(); i++)
            cout << boxTypes[i][0] << " " << boxTypes[i][1] << "\n";

        for(int i = 0; i < boxTypes.size() && truckSize; i++)
            
            if(0 <= truckSize - boxTypes[i][0])
            {
                res += boxTypes[i][0] * boxTypes[i][1];
                truckSize -= boxTypes[i][0];
            }
            
            else
            {
                res += truckSize * boxTypes[i][1];
                truckSize = 0;
            }
            
            
        return res;
    }
};
