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
    private LinkedList<Integer> adj[];
    private TreeMap<Integer, Integer> distances;

    public Graph(int v) {
        V = v;
        adj = new LinkedList[V];
        distances = new TreeMap<>();
        for (int i = 0; i < V; i++) {
            adj[i] = new LinkedList<>();
            distances.put(i, -1);
        }
    }

    public void addEdge(int v, int w) {
        adj[--v].add(--w);
        adj[w].add(v);
    }

    public void BFS(int s) {
        boolean visited[] = new boolean[V];
        Queue<Integer> q = new LinkedList<>();
        q.add(s);
        visited[s] = true;
        distances.put(s, 0);
        while (q.size() > 0) {
            int curr = q.element();
            q.poll();
            Iterator<Integer> it = adj[curr].iterator();
            while (it.hasNext()) {
                int v = it.next();
                if (visited[v] == false && v != s) {
                    distances.put(v, distances.get(curr) + 6);
                    q.add(v);
                    visited[v] = true;
                }
            }
        }
        distances.forEach((k, v) -> {
            if (!Objects.equals(k, s)) {
                System.out.print(v + " ");
            }

        });
    }
}

public class Solution {

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int queries = sc.nextInt();
        while (queries > 0) {
            queries--;
            int n, m;
            n = sc.nextInt();
            m = sc.nextInt();
            Graph g = new Graph(n);
            while (m > 0) {
                m--;
                int u = sc.nextInt();
                int v = sc.nextInt();
                g.addEdge(u, v);
            }
            int s = sc.nextInt();
            g.BFS(--s);
            System.out.println("");
        }
    }

}
