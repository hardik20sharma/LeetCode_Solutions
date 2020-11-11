# define point vector<int>

class Solution {
public:
    
    float distance_cal(point p1, point p2)
    {
        return sqrt( pow((p1[0] - p2[0]), 2) + pow((p1[1] - p2[1]), 2) );
    }
    
    bool validSquare(point p1, point p2, point p3, point p4)
    {
        vector<float> distances;
        
        distances.push_back(distance_cal(p1, p2));   // 0
        distances.push_back(distance_cal(p2, p3));   // 1
        distances.push_back(distance_cal(p3, p4));   // 2
        distances.push_back(distance_cal(p4, p1));   // 3
        distances.push_back(distance_cal(p1, p3));   // 4
        distances.push_back(distance_cal(p2, p4));   // 5

        set<float> s(distances.begin(), distances.end());
        if(s.size() != 2)
            return false;

        sort(distances.begin(), distances.end());

        if(distances[0] != distances[1] || distances[1] != distances[2] || distances[2] != distances[3] || distances[4] != distances[5])
            return false;

        return true;
    }
};
