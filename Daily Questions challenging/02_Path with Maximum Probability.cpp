// 1514. Path with Maximum Probability
// Medium
// Topics
// Companies
// Hint
// You are given an undirected weighted graph of n nodes (0-indexed), represented by an edge list where edges[i] = [a, b] is an undirected edge connecting the nodes a and b with a probability of success of traversing that edge succProb[i].

// Given two nodes start and end, find the path with the maximum probability of success to go from start to end and return its success probability.

// If there is no path from start to end, return 0. Your answer will be accepted if it differs from the correct answer by at most 1e-5.

 

// Example 1:



// Input: n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.2], start = 0, end = 2
// Output: 0.25000
// Explanation: There are two paths from start to end, one having a probability of success = 0.2 and the other has 0.5 * 0.5 = 0.25.
// Example 2:



// Input: n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.3], start = 0, end = 2
// Output: 0.30000
// Example 3:



// Input: n = 3, edges = [[0,1]], succProb = [0.5], start = 0, end = 2
// Output: 0.00000
// Explanation: There is no path between 0 and 2.

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<double> d(n, 0.0);
        d[start_node] = 1.0;
        for (int i= 0; i < n - 1; i++) {
            bool ans= false;
            for (int j= 0; j < edges.size(); j++) {
                int u= edges[j][0];
                int v= edges[j][1];
                double prob = succProb[j];
             
                if (d[u] * prob > d[v]) {
                    d[v] = d[u] * prob;
                    ans = true;
                }
                if (d[v] * prob > d[u]) {
                    d[u] = d[v] * prob;
                    ans = true;
                }
            }
            if (!ans) break;
        }
        
        return d[end_node];  
    }
};