class Solution {
public:
    
    bool sol(vector<int> &gas, vector<int> &cost, int start_index)  // Checks if its possible to traverse the array and come back
    {
        int i = start_index, gas_in_tank = 0;

        while(i < gas.size())       // Going from starting index to end
        {
            gas_in_tank += gas[i];
            gas_in_tank -= cost[i];
            
            i++;
            
            if(gas_in_tank < 0)   // Gas tank is less than 0, so we can't reach the final position
                return false;
        }

        if(i == gas.size())   // Once we have reached the end, we set i at 0th position
            i = 0;

        while(i < start_index)    // Moving the pointer i till it reaches starting index
        {
            gas_in_tank += gas[i];
            gas_in_tank -= cost[i];
            
            i++;
            
            if(gas_in_tank < 0)   // Gas tank is less than 0, so we can't reach the final position
                return false;
        }

        return true;    // Return true, since we have reached the starting index
    }
    
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
    {
        for(int i = 0; i < gas.size(); i++)   // For each index we check if its possible to traverse the circular route from that point
            if( sol(gas, cost, i) )
                return i;
        return -1;
    }
};
