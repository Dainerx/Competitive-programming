import java.util.Arrays;
import java.util.HashMap;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.Map;
import java.util.Queue;
import java.util.TreeMap;
import java.util.Comparator;
import java.util.Objects;
import java.util.Scanner;

/**
 *
 * @author dainer
 */
class Graph {

    private int V;
    public LinkedList<Integer> adj[];
    public boolean visited[];
    public int sizeCC = 1;

    public Graph(int v) {
        V = v;
        adj = new LinkedList[V];
        visited = new boolean[V];
        for (int i = 0; i < V; i++) {
            adj[i] = new LinkedList<>();
        }
    }

    public void addEdge(int v, int w) {
        adj[v].add(w);
        adj[w].add(v);
    }

    public int DFS(int s) {
        visited[s] = true;
        Iterator<Integer> i = adj[s].listIterator();
        while (i.hasNext()) {
            int n = i.next();
            if (!visited[n]) {
                sizeCC++;
                DFS(n);
            }
        }
        return sizeCC;
    }

}

public class Solution {

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int p = sc.nextInt();
        Graph g = new Graph(n);
        while (p > 0) {
            p--;
            int u = sc.nextInt();
            int v = sc.nextInt();
            g.addEdge(u, v);
        }

        int cc[] = new int[n];
        for (int i = 0; i < n; i++) {
            if (g.visited[i] == false) {
                g.DFS(i);
                cc[i] = g.sizeCC;
                g.sizeCC = 1;
            }
        }

        long result = 0;
        for (int i = 0; i < n; i++) {
            int r = cc[i];
            for (int j = i + 1; j < n; j++) {
                result += r * cc[j];
            }
        }

        System.out.println(result);
    }

}
