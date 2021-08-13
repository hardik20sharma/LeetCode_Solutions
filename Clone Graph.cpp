/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    
    void dfs(Node* node, Node *copy, map<int, Node*> &m)
    {
        m[node->val] = copy;

        for(Node *c : node->neighbors)
        {
            if(m.find(c->val) == m.end())
            {
                Node *temp = new Node(c->val);
                dfs(c, temp, m);
            }

            m[c->val]->neighbors.push_back(copy);
        }
    }

public:
    Node* cloneGraph(Node* node)
    {
        if(node == NULL)
            return NULL;

        map<int, Node*> m;

        Node *copy = new Node(node->val);

        dfs(node, copy, m);

        return copy;
    }
};
