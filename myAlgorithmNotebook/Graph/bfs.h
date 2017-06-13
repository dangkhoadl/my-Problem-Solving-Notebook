
//					BFS: O(V + E)
const int MAXV = 101;

int V, E;
vector<int> e[MAXV];
vector<int> wei[MAXV];

/*------------------------------------- simple BFS ---------------------------------------------------------------*/
bool visited[MAXV];
void bfs(int start) {
	memset(visited + 1, false, V);
	visited[start] = true;
	queue<int> q;
	q.push(start);

	while (!q.empty()) {
		int v = q.front();
		q.pop();

		//process v
		

		for (int i = 0; i < e[v].size(); ++i) {
			if (!visited[e[v][i]]) {
				visited[e[v][i]] = true;
				q.push(e[v][i]);
			}
		}
	}
}

/*------------------------------------- BFS to find edge dist---------------------------------------------------------------*/
int edgeDist[MAXV]; // store the number of edges from start to all other vertices
void bfs(int start) {
	memset(edgeDist + 1, -1, V * sizeof(int));
	edgeDist[start] = 0;
	queue<int> q;
	q.push(start);

	while (!q.empty()) {
		int v = q.front();
		q.pop();

		//Process
		//cout << v << endl;

		for (int i = 0; i < e[v].size(); ++i) {
			if (edgeDist[e[v][i]] == -1) {
				q.push(e[v][i]);

				//update
				edgeDist[e[v][i]] = edgeDist[v] + 1;
			}
		}
	}
}

/*------------------------------------- shortest(edge) path tree ---------------------------------------------------------------*/
int edgeDist[MAXV]; // store the number of edges from start to all other vertices
int pre[MAXV];
void bfs(int start) {
	memset(edgeDist + 1, -1, V * sizeof(int));
	memset(pre + 1, -1, V * sizeof(int));
	edgeDist[start] = 0;
	queue<int> q;
	q.push(start);

	while (!q.empty()) {
		int v = q.front();
		q.pop();

		for (int i = 0; i < e[v].size(); ++i) {
			if (edgeDist[e[v][i]] == -1) {
				q.push(e[v][i]);

				//update
				edgeDist[e[v][i]] = edgeDist[v] + 1;
				pre[e[v][i]] = v;
			}
		}
	}
}
vector<int> reconstructSPT(int start, int end) {
	vector<int> res;
	int v = end;
	while (v != start) {
		res.push_back(v);
		v = pre[v];
		
		if(v == 0)
			return vector<int>();
	}
	res.push_back(start);
	reverse(res.begin(), res.end());
	return res;
}
