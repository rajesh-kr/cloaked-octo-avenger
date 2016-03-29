import java.util.*;

class ShortestPath {
    private int V;
    private int[] shortestPath;
    private boolean[] sptSet;
    private int[][] graph;

    ShortestPath(int v) {
        V = v;
        shortestPath = new int[v];
        sptSet = new boolean[v];
        graph = new int[v][v];
        for(int i = 0; i < v; i++) {
            shortestPath[i] = Integer.MAX_VALUE;
            sptSet[i] = false;
            for(int j = 0; j < v; j++) {
                graph[i][j] = 0;
            }
        }
    }

    void addEdge(int src, int dest, int distance) {
        graph[src][dest] = distance;
        graph[dest][src] = distance;
    }

    int minDist() {
        int min = Integer.MAX_VALUE;
        int min_index = 0;
        for(int v = 0; v < V; v++) {
            if(sptSet[v] == false && shortestPath[v] < min) {
                min = shortestPath[v];
                min_index = v;
            }
        }

        return min_index;
    }

    void dijkstra(int start) {
        shortestPath[start] = 0;

        for(int i = 0; i < V; i++) {
            int u = minDist();

            sptSet[u] = true;
            for(int v = 0; v < V; v++) {
                if(sptSet[v] == false && graph[u][v] != 0 && (shortestPath[u] + graph[u][v] < shortestPath[v])) {
                    shortestPath[v] = shortestPath[u] + graph[u][v];
                }
            }
        }
    }

    void print() {
        System.out.println("Vertex\tDistance from Source");
        for(int i = 0; i < V; i++) {
            System.out.println(i + "\t\t" + shortestPath[i]);
        }
    }
}

public class Dijkstra {
    public static void main(String[] args) {
        ShortestPath g = new ShortestPath(9);
        g.addEdge(0, 1, 4);
        g.addEdge(0, 7, 8);
        g.addEdge(1, 7, 11);
        g.addEdge(1, 2, 8);
        g.addEdge(7, 8, 7);
        g.addEdge(7, 6, 1);
        g.addEdge(2, 8, 2);
        g.addEdge(8, 6, 6);
        g.addEdge(2, 3, 7);
        g.addEdge(2, 5, 4);
        g.addEdge(6, 5, 2);
        g.addEdge(3, 5, 14);
        g.addEdge(3, 4, 9);
        g.addEdge(5, 4, 10);

        g.dijkstra(0);
        g.print();
    }
}
