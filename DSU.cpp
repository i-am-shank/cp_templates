// Disjoint set Union

class DSU {
private:
	vector<int> parent; // Parents of nodes
	vector<int> size; // Size of component-parents
	vector<int> rank;

public:
	DSU(int n) {
		for(int i=1; i<=n; i++) {
			parent.push_back(i);
			size.push_back(1);
			rank.push_back(0);
		}
	}

	// Time : O(logn) .. If only path-compression is used
	// Time : O(4 * alpha) .. If both path & size-compression are used
	// ........ alpha is very-very small (approx. 1)
	// .. What is Alpha ? (mathematical logic - very long proof)
	int findParent(int node) {
		if(parent[node] == node) {
			return node;
		}
		int par = findParent(parent[node]);
		parent[node] = par; // Path-Compression
		return par;
	}

	// Union by size (following)
	void unionBySize(int u, int v) {
		int par_u = findParent(u);
		int par_v = findParent(v);
		if(par_u == par_v) {
			// Already in same-component !
			return;
		}
		else if(size[par_u] < size[par_v]) {
			parent[par_u] = par_v;
			// Join small-component to big-component
			size[par_v] += size[par_u];
			// Append size of small-component to big-component
		}
		else {
			// vice versa
			parent[par_v] = par_u;
			size[par_u] += size[par_v];
		}
		return;
	}

	// Union by rank (similar .. read about from old playlist - Striver)
	//   --> If path-compression happens in between
	//       , rank doesn't give appropriate idea of component
	void unionByRank(int u, int v) {
		int par_u = findParent(u);
		int par_v = findParent(v);
		if(par_u == par_v) {
			// Already in same-component !
			return;
		}
		else if(rank[par_u] < rank[par_v]) {
			parent[par_u] = par_v;
			// Join small-component to big-component
		}
		else if(rank[par_u] > rank[par_v]) {
			// vice versa
			parent[par_v] = par_u;
		}
		else { // Equal ranks
			parent[par_u] = par_v;
			rank[par_v]++;
		}
		return;
	}
}

void solve() {
	int n;
	cin >> n;
	DSU dsu(n);
	return 0;
}