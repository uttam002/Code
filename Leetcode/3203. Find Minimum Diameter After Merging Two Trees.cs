public class Solution {
    public int MinimumDiameterAfterMerge(int[][] edges1, int[][] edges2) {
        var adjList1 = CreateAdjacencyList(edges1);
        var adjList2 = CreateAdjacencyList(edges2);
        int diameter1 = FindDiameter(adjList1);
        int diameter2 = FindDiameter(adjList2);
        int combinedDiameter = ((diameter1 + 1) / 2) + ((diameter2 + 1) / 2) + 1;
        return Math.Max(combinedDiameter, Math.Max(diameter1, diameter2));
    }

    private int FindDiameter(List<int>[] adjList) {
        int[] farthestNode = new int[2];
        FindFarthestNode(0, adjList, new bool[adjList.Length], farthestNode, 0);
        return FindDiameterFromNode(adjList, farthestNode[0], new bool[adjList.Length]);
    }

    private void FindFarthestNode(int u, List<int>[] adjList, bool[] visited, int[] farthestNode, int length) {
        visited[u] = true;
        foreach (int v in adjList[u]) {
            if (!visited[v]) FindFarthestNode(v, adjList, visited, farthestNode, length + 1);
        }
        if (length > farthestNode[1]) { farthestNode[0] = u; farthestNode[1] = length; }
    }

    private int FindDiameterFromNode(List<int>[] adjList, int u, bool[] visited) {
        visited[u] = true;
        int maxLength = 0;
        foreach (int v in adjList[u]) {
            if (!visited[v]) maxLength = Math.Max(maxLength, FindDiameterFromNode(adjList, v, visited) + 1);
        }
        return maxLength;
    }

    private List<int>[] CreateAdjacencyList(int[][] edges) {
        var adjList = new List<int>[edges.Length + 1];
        for (int i = 0; i <= edges.Length; i++) adjList[i] = new List<int>();
        foreach (var edge in edges) {
            adjList[edge[0]].Add(edge[1]);
            adjList[edge[1]].Add(edge[0]);
        }
        return adjList;
    }
}
