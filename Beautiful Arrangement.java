class Solution {
    
    int cnt = 0;
    
    public int countArrangement(int n)
    {
        boolean[] visited = new boolean[n + 1];
        func(n, 1, visited);
        return cnt;
    }

    public void func(int n, int pos, boolean[] visited)
    {
        if (pos > n)
            cnt++;
        for (int i = 1; i <= n; i++)
            if ( !visited[i] && (pos % i == 0 || i % pos == 0) )
            {
                visited[i] = true;
                func(n, pos + 1, visited);
                visited[i] = false;
            }
    }
}
