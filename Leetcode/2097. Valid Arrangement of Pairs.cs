public class Solution {
    public int[][] ValidArrangement(int[][] pairs) {
        Dictionary<int, Stack<int>> graph = new Dictionary<int, Stack<int>>();
        Dictionary<int, int> inDegree = new Dictionary<int, int>();
        Dictionary<int, int> outDegree = new Dictionary<int, int>();

        foreach (var pair in pairs) {
            int start = pair[0];
            int end = pair[1];

            if (!graph.ContainsKey(start)) {
                graph[start] = new Stack<int>();
            }
            graph[start].Push(end);

            outDegree[start] = outDegree.GetValueOrDefault(start, 0) + 1;
            inDegree[end] = inDegree.GetValueOrDefault(end, 0) + 1;
        }

        int startNode = pairs[0][0]; 
        foreach (var node in graph.Keys) {
            if (outDegree.GetValueOrDefault(node, 0) > inDegree.GetValueOrDefault(node, 0)) {
                startNode = node;
                break;
            }
        }

        List<int[]> result = new List<int[]>();
        Stack<int> stack = new Stack<int>();
        stack.Push(startNode);

        while (stack.Count > 0) {
            int node = stack.Peek();
            if (graph.ContainsKey(node) && graph[node].Count > 0) {
                stack.Push(graph[node].Pop());
            } else {
                stack.Pop();
                if (stack.Count > 0) {
                    result.Add(new int[] { stack.Peek(), node });
                }
            }
        }

        result.Reverse();
        return result.ToArray();
    }
}
