class Solution {
public:
    string countAndSay(int n)
    {
        string result = "1";
        
        for(int nn=1; nn<n; nn++)
        {
            string new_result;

            for(int i=0; i<result.size(); )
            {
                int cnt = 1, j = i+1;

                while(j < result.size() && result[i] == result[j])
                {
                    cnt++;
                    j++;
                }

                new_result += to_string(cnt) + result[i];

                i = j;
            }

            result = new_result;
        }

        return result;
    }
};
