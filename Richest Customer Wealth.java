class Solution {
    public int maximumWealth(int[][] acc)
    {
        int max = 0;
        for(int i=0; i<acc.length; i++)
        {
            int sum = 0;
            for(int j=0; j<acc[i].length; j++)
                sum += acc[i][j];
            
            if(max < sum)
                max = sum;
        }
        return max;
    }
}
