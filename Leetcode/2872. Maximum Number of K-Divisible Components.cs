public class Solution
{
    public int MaxKDivisibleComponents(int n, int[][] edges, int[] values, int k)
    {
        var adjList = new List<int>[n];
        for (int i = 0; i < n; i++) adjList[i] = new List<int>();
        foreach (var edge in edges)
        {
            adjList[edge[0]].Add(edge[1]);
            adjList[edge[1]].Add(edge[0]);
        }

        int componentCount = 0;
        Dfs(0, -1, adjList, values, k, ref componentCount);
        return componentCount;
    }

    private int Dfs(int node, int parent, List<int>[] adj, int[] values, int k, ref int count)
    {
        int sum = 0;
        foreach (var neighbor in adj[node])
            if (neighbor != parent)
                sum = (sum + Dfs(neighbor, node, adj, values, k, ref count)) % k;

        sum = (sum + values[node]) % k;
        if (sum == 0) count++;
        return sum;
    }
}
