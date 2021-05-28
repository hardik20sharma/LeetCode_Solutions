class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words)
    {
        int res = 0;

        set<char> st ( allowed.begin(), allowed.end() );        // Storing all the characters in a set

        for(string word : words)
        {
            set<char> word_st ( word.begin(), word.end() );

            if( word_st.size() > st.size() )    // If there are more distinct chars in word than allowed, continue
                continue;

            set<char> diff;     // If word belongs to st, (word - st) should be zero.
            set_difference(word_st.begin(), word_st.end(), st.begin(), st.end(), inserter(diff, diff.begin() ) );

            if( diff.empty() )
                res++;
        }

        return res;
    }
};
