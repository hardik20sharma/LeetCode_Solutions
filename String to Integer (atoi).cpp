class Solution {
public:
    int myAtoi(string s)
    {
        int res = 0, n = s.size(), i = 0;

        bool negative = false;


        while( i < n && s[i] == ' ' )   // Trim all extra spaces in front
            i++;



        if( i < n && s[i] == '-' )    // If found a minus sign first, its negative, else positive
        {
            negative = true;
            i++;
        }
        else if( i < n && s[i] == '+' )
            i++;



        while( i < n && '0' <= s[i] && s[i] <= '9' )  // Ensuring char is between 0 to 9
        {
            int digit = s[i] - '0';   // Finding the digit

            if(res > INT_MAX/10 || (res == INT_MAX/10 && digit > 7) )       // If its an overflow, we need to return accordingly
                return (negative) ? INT_MIN : INT_MAX;

            res  = res * 10 + digit;    // Adding the char to the resulting number
            i++;
        }   

        return (negative) ? -1 * res : res;   // Return the result

    }
};
