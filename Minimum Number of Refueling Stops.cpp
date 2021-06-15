#define station vector<int>
class Solution {
public:

    int minRefuelStops(int target, int start_fuel, vector<station>& stations)
    {
        int curr_pos = start_fuel, res = 0;

        priority_queue<int> pq;                 // Stores the fuel value

        for(station s : stations)
        {
            int s_pos = s[0], s_fuel = s[1];    // Storing station position and fuel

            while(curr_pos < s_pos)             // Exhausting all the fuel
            {
                if(pq.empty())                  // If priority_queue is empty, we can't reach
                    return -1;

                curr_pos += pq.top();           // Adding the highest fuel in priority queue
                pq.pop();                       // Removing the element from the priority queue
                res++;
            }

            pq.push(s_fuel);                    // If fuel is there at station, add it
        }

        while(curr_pos < target)
        {
            if(pq.empty())                      // If priority_queue is empty, we can't reach
                return -1;
                
            curr_pos += pq.top();               // Adding the highest fuel in priority queue
            pq.pop();                           // Removing the element from the priority queue
            res++;
        }

        return res;
    }
};
