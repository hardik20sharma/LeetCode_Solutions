class Solution {
public:
    string addStrings(string num1, string num2)
    {   
        if(num1.length() > num2.length())
            swap(num1, num2);
        
        num1 = string(num1.rbegin(), num1.rend());
        num2 = string(num2.rbegin(), num2.rend());

        string result;
        int carry = 0;
        
        for(int i=0; i<num1.size(); i++)
        {
            int sum = (num1[i] - '0') + (num2[i] - '0') + carry;
            result += (sum % 10 + '0');
            carry = sum/10;
        }
        
        for(int i=num1.size(); i<num2.size(); i++)
        {
            int sum = (num2[i] - '0') + carry;
            result += (sum % 10 + '0');
            carry = sum/10;
        }
        
        if(carry)
            result += (carry + '0');
        
        return string(result.rbegin(), result.rend());
    }
};
