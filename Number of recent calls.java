class RecentCounter
{
    LinkedList<Integer> calls;

    public RecentCounter()
    {
        calls = new LinkedList<Integer>();
    }

    public int ping(int t) 
    {
        calls.addLast(t);
        while (calls.getFirst() < t - 3000)
            calls.removeFirst();
        return calls.size();
    }
}
