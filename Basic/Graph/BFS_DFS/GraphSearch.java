import java.util.*;

class Graph {
    private int V;
    private LinkedList<Integer>[] adj;

    Graph(int v) {
        V = v;
        adj = new LinkedList[v];
        for(int i = 0; i < v; i++) {
            adj[i] = new LinkedList<Integer>();
        }
    }

    void addEdge(int src, int dest) {
        adj[src].add(dest);
    }

    void bfs(int s) {
        boolean[] visited = new boolean[V];
        for(int i = 0; i < V; i++) {
            visited[i] = false;
        }

        // create a queue for bfs
        LinkedList<Integer> q = new LinkedList<Integer>();

        // mark the current node visited and push it to queue
        visited[s] = true;
        q.add(s);

        while(q.size() != 0) {
            s = q.poll();
            System.out.print(s + " ");

            Iterator<Integer> i = adj[s].listIterator();
            while(i.hasNext()) {
                int n = i.next();
                if(visited[n] == false) {
                    visited[n] = true;
                    q.add(n);
                }
            }
        }

        System.out.println();
    }

    void dfs(int s) {
        // create an array for marking the visited node
        boolean[] visited = new boolean[V];
        for (int i = 0; i < V; i++) {
            visited[i] = false;
        }

        // create a stack for the dfs
        LinkedList<Integer> st = new LinkedList<Integer>();

        // mark the current node visited and add it to the stack
        visited[s] = true;
        st.push(s);

        while(st.size() != 0) {
            s = st.pop();
            System.out.print(s + " ");

            Iterator<Integer> i = adj[s].listIterator();

            while(i.hasNext()) {
                int n = i.next();
                if(visited[n] == false) {
                    visited[n] = true;
                    st.push(n);
                }
            }
        }

        System.out.println();
    }
}

public class GraphSearch {
    public static void main(String[] args) {
        Graph g = new Graph(5);
        g.addEdge(0, 1);
        g.addEdge(0, 2);
        g.addEdge(1, 2);
        g.addEdge(2, 0);
        g.addEdge(2, 3);
        g.addEdge(3, 3);
        g.addEdge(3, 4);

        System.out.print("BFS:\n\t");
        g.bfs(2);
        System.out.print("DFS:\n\t");
        g.dfs(2);
    }
}
