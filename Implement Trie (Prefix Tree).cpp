struct TrieNode
{
    bool word_end;
    TrieNode * child[26];
    
    TrieNode()
    {
        word_end = false;
        for(int i=0; i<26; i++)
            child[i] = NULL;
    }
};

class Trie {
private:
    TrieNode *root;

public:
    
    
    /** Initialize your data structure here. */
    Trie()
    {
        root = new TrieNode();
    }
    
    
    
    
    
    /** Inserts a word into the trie. */
    void insert(string s)
    {
        TrieNode *temp = root;  // Creating a temp node

        for(char c : s)         // Traverse through each character in string
        {
            int character_index = c -'a';       // Get the character index

            if(temp->child[character_index] == NULL)            // If no such character found already
                temp->child[character_index] = new TrieNode();  // Create one
            
            temp = temp->child[character_index];    // Move ahead for next character
        }

        temp->word_end = true;  // Marking an end
    }
    
    
    
    
    
    /** Returns if the word is in the trie. */
    bool search(string s)
    {
        TrieNode *temp = root;  // Creating a temp node

        for(char c : s)         // Traverse through each character in string
        {
            int character_index = c - 'a';      // Get the character Index

            if(temp->child[character_index] == NULL)    // If no such character exists, return false
                return false;

            temp = temp->child[character_index];    // Moving to find next character
        }

        return temp->word_end;  // Check if the word ends or not
    }
    
    
    
    
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string s)
    {
        TrieNode *temp = root;  // Creating a temp node

        for(char c : s)         // Traverse through each character in string
        {
            int character_index = c - 'a';      // Get the character Index

            if(temp->child[character_index] == NULL)    // If no such character exists, return false
                return false;

            temp = temp->child[character_index];    // Moving to find next character
        }

        return true;    // Prefix is available
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
