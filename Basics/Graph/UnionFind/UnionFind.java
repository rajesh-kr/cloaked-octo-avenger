import java.util.*;

class Graph {
    private int V;
    private int E;
    private int[] parent;
    private Edge[] edge;

    private class Edge {
        int src;
        int dest;
    }

    Graph(int v, int e) {
        V = v;
        E = e;
        edge = new Edge[e];
        for(int i = 0; i < e; i++) {
            edge[i] = new Edge();
        }

        parent = new int[v];
        for(int i = 0; i < v; i++) {
            parent[i] = -1;
        }
    }

    void addEdge(int index, int src, int dest) {
        edge[index].src = src;
        edge[index].dest = dest;
    }

    int Find(int n) {
        int p = parent[n];
        while(p != -1) {
            n = p;
            p = parent[n];
        }

        return n;
    }

    void Union(int x, int y) {
        parent[x] = y;
    }

    boolean isCycle() {
        for(int i = 0; i < E; i++) {
            int x = Find(edge[i].src);
            int y = Find(edge[i].dest);

            if(x == y) {
                return true;
            }

            Union(x, y);
        }

        return false;
    }
}

public class UnionFind {
    public static void main(String[] args) {
        /* 0
         * |\
         * | \
         * |  \
         * 1---2
         */
        Graph g = new Graph(3, 3);
        
        // TODO: add a better way to add edge
        g.addEdge(0, 0, 1);
        g.addEdge(1, 1, 2);
        g.addEdge(2, 0, 2);

        if(g.isCycle()) {
            System.out.println("Graph contains cycle");
        }
        else {
            System.out.println("Graph does not contains cycle");
        }
    }
}
