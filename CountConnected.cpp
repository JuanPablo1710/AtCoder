#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	
	int n, m, p1, p2, cn = 0;
	cin >> n >> m;

	vector<vector<int>> g(n+1);
	vector<bool> visited(n+1, false);

	for(int i = 0; i < m; i++){
		cin >> p1 >> p2;
		g[p1].push_back(p2);
		g[p2].push_back(p1);
	}

	int k = n;

	while(k != 0){
		int padre = 1;

		while(visited[padre] && padre <= n) padre++;

		visited[padre] = true;
		queue<int> cola;
		cola.push(padre);
		k--;

		while(!cola.empty()){
			int temp = cola.front(); cola.pop();

			for(auto hijo : g[temp]){
				if(!visited[hijo]){
					cola.push(hijo);
					visited[hijo] = true;
					k--;
				}
			}
		}

		cn++;

	}

	cout << cn;

	return 0;
}
