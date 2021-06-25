class Solution {
public:
    string convertToTitle(int colNo)
    {
        string res;

        while(colNo != 0)
        {
            res = ( (char) ((--colNo % 26) + 'A' )) + res;
            colNo /= 26;
        }

        return res;
    }
};
