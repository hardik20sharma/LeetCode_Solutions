class OrderedStream
{
    vector <string> stream;
    int next;

public:

    OrderedStream(int n)
    {
        stream = vector <string> (n);
        next = 0;
    }

    vector <string> insert(int idKey, string value)
    {
        vector <string> chunk;

        stream[ idKey - 1 ] = value;

        if(idKey - 1 == next)
            while(next < stream.size() && stream[next] != "")
            {
                chunk.push_back( stream[next] );
                next++;
            }

        return chunk;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */
