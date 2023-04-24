import java.util.*;
public class Main{
    public static void main(String[] args){
        int v = 5;
        int indegree[] = new int[5];
        ArrayList<ArrayList<Integer>> adj = new ArrayList<ArrayList<Integer>>(v);
        for(int i = 0; i < v; i++){
            adj.add(new ArrayList<Integer>());
        }
        addEdge(adj,0,2,indegree);
        addEdge(adj,0,3,indegree);
        addEdge(adj,2,3,indegree);
        addEdge(adj,1,3,indegree);
        addEdge(adj,1,4,indegree);
        //printGraph(adj);
        ArrayList<Integer> res = new ArrayList<>();
        //indegrees(indegree);
        topologicalSort(indegree, adj , res);
        System.out.println(res);
    }
        public static void addEdge(ArrayList<ArrayList<Integer>> adj,int u,int v,int[] indegree){
            adj.get(u).add(v);
            indegree[v]++;
        }
        public static void printGraph(ArrayList<ArrayList<Integer>> adj){
            for(int i = 0; i < adj.size(); i++){
                for(int j = 0; j < adj.get(i).size(); j++){
                    System.out.print(adj.get(i).get(j) + " ");
                }
                System.out.println();
            }
        }
        public static void indegrees(int[] indegree){
            for(int i = 0; i < indegree.length; i++){
            System.out.print(indegree[i] + " ");
            }
        }
        public static void topologicalSort(int[] indegree, ArrayList<ArrayList<Integer>> adj, ArrayList<Integer> res){
            Queue<Integer> q = new LinkedList<>();
            boolean[] visited = new boolean[5];
            for(int i = 0 ; i < 5 ; i++){
                if(indegree[i] == 0){
                    visited[i] = true;
                    
                    q.add(i);
                }
            }
            while(!q.isEmpty()) {
                int curr = q.poll();
                res.add(curr);
                for(int i : adj.get(curr)) {
                    if(!visited[i]){
                        indegree[i]--;
                        if(indegree[i] == 0) {
                            visited[i] = true;
                            q.add(i);
                        }
                    }
                }
            }
        }
}

