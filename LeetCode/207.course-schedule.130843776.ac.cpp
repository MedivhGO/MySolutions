/*
 * [207] Course Schedule
 *
 * https://leetcode.com/problems/course-schedule/description/
 *
 * algorithms
 * Medium (33.06%)
 * Total Accepted:    107K
 * Total Submissions: 323.7K
 * Testcase Example:  '2\n[[1,0]]'
 *
 * 
 * There are a total of n courses you have to take, labeled from 0 to n - 1.
 * 
 * Some courses may have prerequisites, for example to take course 0 you have
 * to first take course 1, which is expressed as a pair: [0,1]
 * 
 * 
 * Given the total number of courses and a list of prerequisite pairs, is it
 * possible for you to finish all courses?
 * 
 * 
 * For example:
 * 2, [[1,0]]
 * There are a total of 2 courses to take. To take course 1 you should have
 * finished course 0. So it is possible.
 * 
 * 2, [[1,0],[0,1]]
 * There are a total of 2 courses to take. To take course 1 you should have
 * finished course 0, and to take course 0 you should also have finished course
 * 1. So it is impossible.
 * 
 * Note:
 * 
 * The input prerequisites is a graph represented by a list of edges, not
 * adjacency matrices. Read more about how a graph is represented.
 * You may assume that there are no duplicate edges in the input
 * prerequisites.
 * 
 * 
 * 
 * click to show more hints.
 * 
 * Hints:
 * 
 * This problem is equivalent to finding if a cycle exists in a directed graph.
 * If a cycle exists, no topological ordering exists and therefore it will be
 * impossible to take all courses.
 * Topological Sort via DFS - A great video tutorial (21 minutes) on Coursera
 * explaining the basic concepts of Topological Sort.
 * Topological sort could also be done via BFS.
 * 
 * 
 */
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>>  graph;
        graph = make_graph(numCourses,prerequisites);
        vector<bool> onpath(numCourses,false),visited(numCourses,false);
        for (int i = 0; i < numCourses; i++)
            if (!visited[i] && dfs_cycle(graph, i, onpath, visited)) //如果第i个节点没有被访问过，且
                return false;
        return true;
    }
private:
    vector<unordered_set<int>> make_graph(int numCourses,vector<pair<int,int>>& prerequisites) { //使用邻接表来表示图
        vector<unordered_set<int>> graph(numCourses);
        for (auto pre : prerequisites) 
            graph[pre.second].insert(pre.first);
        return graph;
    }
    bool dfs_cycle(vector<unordered_set<int>>& graph,int node,vector<bool>& onpath,vector<bool>& visited) { 
        if (visited[node]) return false;
        onpath[node] = visited[node] = true;
        for (int neigh : graph[node]) //graph[node] 所有邻接的节点
            if (onpath[neigh] || dfs_cycle(graph,neigh,onpath,visited))//这条路径上已经遍历过了
                return true;
        return onpath[node] = false;
    }
    
};
