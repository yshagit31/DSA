using System;
using System.Collections.Generic;

class Program
{
    static void Main()
    {
        int N = int.Parse(Console.ReadLine());
        var graph = new Dictionary<string, List<string>>();
        var indegrees = new Dictionary<string, int>();

        for (int i = 0; i < N; i++)
        {
            var edge = Console.ReadLine().Split();
            string from = edge[0];
            string to = edge[1];

            if (!graph.ContainsKey(from))
                graph[from] = new List<string>();
            graph[from].Add(to);

            if (!indegrees.ContainsKey(from))
                indegrees[from] = 0;
            if (!indegrees.ContainsKey(to))
                indegrees[to] = 0;
            indegrees[to]++;
        }

        var words = Console.ReadLine().Split();

        var levels = new Dictionary<string, int>();
        var queue = new Queue<string>();

        foreach (var node in graph.Keys)
        {
            if (!indegrees.ContainsKey(node))
                indegrees[node] = 0;
        }

        foreach (var node in indegrees.Keys)
        {
            if (indegrees[node] == 0)
            {
                levels[node] = 1;
                queue.Enqueue(node);
            }
        }

        while (queue.Count > 0)
        {
            var current = queue.Dequeue();
            int currentLevel = levels[current];

            if (graph.ContainsKey(current))
            {
                foreach (var neighbor in graph[current])
                {
                    indegrees[neighbor]--;
                    if (indegrees[neighbor] == 0)
                    {
                        levels[neighbor] = currentLevel + 1;
                        queue.Enqueue(neighbor);
                    }
                }
            }
        }

        int totalValue = 0;

        foreach (var word in words)
        {
            if (levels.ContainsKey(word))
            {
                totalValue += levels[word];
            }
            else
            {
                totalValue += -1;
            }
        }

        Console.Write(totalValue);
    }
}
