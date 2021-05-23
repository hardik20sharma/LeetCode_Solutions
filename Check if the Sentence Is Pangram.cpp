class Solution {
public:
    bool checkIfPangram(string sentence) {
        
        vector<bool> letters(26, false);
        
        for(char c : sentence)
            letters[c-'a'] = true;
        
        for(bool letter : letters)
            if(!letter)
                return false;
        
        return true;
    }
};
