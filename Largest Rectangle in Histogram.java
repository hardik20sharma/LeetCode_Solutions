class Solution
{
    public int largestRectangleArea(int[] heights)
    {
        Stack<Integer> s = new Stack<>();    
        int max_area = 0, tp, area_with_top, i = 0;
        
        while(i < heights.length)
        {
            if(s.empty() || heights[s.peek()] <= heights[i])
                s.push(i++);
            else
            {
                tp = s.peek();
                s.pop();
                
                area_with_top = heights[tp] * (s.empty() ? i : i - s.peek() - 1);
                
                if(max_area < area_with_top)
                    max_area = area_with_top;
            }
        }
        
        while(s.empty() == false)
        {
            tp = s.peek();
            s.pop();

            area_with_top = heights[tp] * (s.empty() ? i : i - s.peek() - 1);

            if(max_area < area_with_top)
                max_area = area_with_top;
        }
        
        return max_area;
    }
}
