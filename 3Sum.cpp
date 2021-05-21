class Solution {
public:

    vector<vector<int>> threeSum(vector<int>& a)
    {
        vector<vector<int>> res;

        if (a.size() < 3)   // If vector has less than 3 elements, no use of finding the answer
            return res;

        sort(a.begin(), a.end());   // Sorting the vector

        for(int i = 0; i < a.size()-1; i++)     // Iterating from 0th element to n-2. Reason being, we have a low variable, which starts from i+1
        {
            if(i == 0 || ( i > 0 && a[i-1] != a[i] ) )    // Ensures that the previous element isn't a duplicate
            {
                for(int low = i+1, high = a.size()-1, sum = -a[i]; low < high; )    // Applying twoSum, low to high | 2 pointer technique
                {
                    if(a[low] + a[high] == sum)     // Sum over here is negative of third element
                    {
                        vector<int> temp {a[i], a[low], a[high] };    // Once found
                        res.push_back(temp);                        // Push it into the vector

                        while(low < high && a[low] == a[low + 1])   // If next element from low is duplicate, we need to skip it
                            low++;

                        while(low < high && a[high - 1] == a[high])   // If previous element from high is duplicate, we need to skip it
                            high--;

                        low++;    // Final increase in low
                        high--;   // Final decrease in high
                    }

                    else if(a[low] + a[high] > sum)   // When sum is greater, we know that we need to decrease high
                        high--;

                    else        // When sum is smaller, we know we need to increase low
                        low++;
                }
            }
        }

        return res;   // Returning the result
    }
};
