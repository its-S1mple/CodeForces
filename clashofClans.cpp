#include <bits/stdc++.h>
  using namespace std;
  
   
//COPY THE BLACKBOX, there is no need to change anything in it.
//Check the main function at bottom for USAGE
 
//****************BLACKBOX START*****************
//START COPYING FROM HERE
 
typedef int ll;
 
class Hash {
  public:
  	static int hash(int x){
  		return hash({0,0,x});
  	}
  	static int hash(tuple<int,int>x){
  		return hash({0,get<0>(x),get<1>(x)});
  	}
  	static int hash(tuple<int,int,int>x){
  		int k=get<0>(x),u=get<1>(x),v=get<2>(x);
  		return k*1873*1873 + u*1873 + v;
  	}
};
 
class Graph {
 
	bool is_directed;
 
	public:
		vector<vector<pair<int,ll>>>adj;
    int n,N=2000000;
 
		Graph(int n_, bool is_directed_){
			n=n_; is_directed = is_directed_;
			adj.resize(N,vector<pair<int,ll>>());
		}
 
		int hash(int u, int v){
			return Hash::hash({u,v});
		}
		int hash(int u, int v, int k){
			return Hash::hash({u,v,k});
		}
 
		void add_edge(int uR, int vR, ll c=0){
		  int u=Hash::hash(uR), v=Hash::hash(vR);
		  add_edge_internal(u,v,c);
		}
		void add_edge(tuple<int,int> uR, tuple<int,int> vR, ll c=0){
		  int u=Hash::hash(uR), v=Hash::hash(vR);
		  add_edge_internal(u,v,c);
		}
			void add_edge(tuple<int,int,int> uR, tuple<int,int,int> vR, ll c=0){
		  int u=Hash::hash(uR), v=Hash::hash(vR);
		  add_edge_internal(u,v,c);
		}
 
 
	private :
 
	  void add_edge_internal(int u, int v, ll c=0){
			add_edge_weighted_undirected(u,v,c);
			if(!is_directed)
				add_edge_weighted_undirected(v,u,c);
		}
		void add_edge_weighted_undirected(int u, int v, ll c) {
			pair<int,ll>p = make_pair(v,c);
			adj[u].push_back(p);
		}
 
};
 
class BFS {
    vector<ll>min_dist_from_source;
    vector<bool> visited;
    Graph *g;
 
    public:
      BFS(Graph *g_) {
          g = g_;
          clear();
      }
 
	  	void clear() {
  			min_dist_from_source.clear();
  			min_dist_from_source.resize(g->N,-1);
  			visited.clear();
  			visited.resize(g->N, false);
  		}
 
 
      void run(int sourceR) {
        int source = Hash::hash(sourceR);
        run_internal(source);
      }
      void run(tuple<int,int> sourceR) {
        int source = Hash::hash(sourceR);
        run_internal(source);
      }
      void run(tuple<int,int,int> sourceR) {
        int source = Hash::hash(sourceR);
        run_internal(source);
      }
 
 
      int min_dist(int targetR){
      	int target = Hash::hash(targetR);
      	return min_dist_internal(target);
      }
      int min_dist(tuple<int,int> targetR){
      	int target = Hash::hash(targetR);
      	return min_dist_internal(target);
      }
      int min_dist(tuple<int,int,int> targetR){
      	int target = Hash::hash(targetR);
      	return min_dist_internal(target);
      }
 
      bool is_visited(int targetR){
      	int target = Hash::hash(targetR);
      	return is_visited_internal(target);
      }
      bool is_visited(tuple<int,int> targetR){
      	int target = Hash::hash(targetR);
      	return is_visited_internal(target);
      }
      bool is_visited(tuple<int,int,int> targetR){
      	int target = Hash::hash(targetR);
      	return is_visited_internal(target);
      }
 
  private:
    void run_internal(int source) {
			queue<int> q;
			q.push(source);
 
			visited[source] = true;
			min_dist_from_source[source] = 0;
 
			while(!q.empty()) {
				int cur_node = q.front();
				for (unsigned int i = 0; i < (g->adj[cur_node]).size(); ++i) {
					int adj_node =  (g->adj[cur_node])[i].first;
					if (visited[adj_node] == false) {
						visited[adj_node] = true;
						min_dist_from_source[adj_node] = min_dist_from_source[cur_node] + 1;
						q.push(adj_node);
					}
				}
				q.pop();
			}
 
			return;
    }
 
    int min_dist_internal(int target){
    	return min_dist_from_source[target];
    }
 
    bool is_visited_internal(int target){
    	return visited[target];
    }
 
};


  int main() {

    int n,m;
    cin>>n>>m;
    int ans=-1;
    
    // create a bidirectional graph
    Graph g(n,false);
    
    vector<int> v(n);
    
    for(int i=0;i<n;i++){
      cin>>v[i];
    }
    
    int x,y;
    
    for(int i=0;i<m;i++){
      cin>>x>>y;
      g.add_edge(x,y);
    }
    
    BFS bfs(&g);
    int k,l;
    int mini=999;
    
    
    for(int i=0; i<n;i++){
      if(v[i]==1){
        k=v[i];
        for(int j=0;j<n;j++){
           if(v[j]==2){
             l=v[j];
             
              bfs.run(k);
    
              if(bfs.is_visited(l)){
                 ans=bfs.min_dist(l);
                if(mini>ans){
                  mini=ans;
                }
                
              }
             
    
           }
        }
      }
     
    }
      
    if(ans==-1){
      cout<<-1;
    }
    else{
       cout<<mini;
    }
   

    return 0;

  }