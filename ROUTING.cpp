#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>
using namespace std;
int n, m;
vector<vector<pair<int, double>>> graph;
vector<double> dijkstra(int src){
	vector<double> dist(n, 1.79769e+308/ 2);
	dist[src] = 1;
	priority_queue<pair<double, int > > q;
	q.push(make_pair(-1, src));
	while (!q.empty()){
		int now = q.top().second;
		double cost = -q.top().first;
		q.pop();
		if (dist[now] < cost){
			continue;
		}
		int len = graph[now].size();
		for (int i = 0; i < len; i++){
			int next = graph[now][i].first;
			double nextcost = graph[now][i].second * cost;
			if (nextcost < dist[next]){
				dist[next] = nextcost;
				q.push(make_pair(-nextcost, next));
			}
		}
	}
	return dist;
}
int main(void){
	int T;
	cin >> T;
	while (T--){
		cin >> n >> m;
		graph.clear();
		graph.resize(n);
		while (m--){
			int u, v;
			double x;
			cin >> u >> v >> x;
			graph[u].push_back(make_pair(v, x));
			graph[v].push_back(make_pair(u, x));
		}
		vector<double> ans = dijkstra(0);
		printf("%.10lf\n", ans[n - 1]);
	}
}
