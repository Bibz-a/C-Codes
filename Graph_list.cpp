#include <iostream>
using namespace std;
#include <list>
#include <queue>
#include <vector>
//Graph using adj lists -> vector of lists

class Graph{
    int V;
    vector<list<int>> l;
    public:
    Graph(int vertices){
       V = vertices;
       l.resize(V);
    }


    void addedge(int u, int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void addVertex(){
        l.push_back(list<int>()); //push an empty list
        V++;
    }

    void deleteedge(int u, int v){
        l[u].remove(v);
        l[v].remove(u);
    }

    void deletevertex(int v){
        for(auto &i : l ){
            i.remove(v);
        }
        l.erase(l.begin() + v);
        for( auto &lst : l){
            for(int &x : lst){
                if(x>v){
                    x--;
                }
            }
        }
        V--;
    }
    void printlist(){
        for(int i = 0; i < l.size(); i++){
            cout<<i<<" : ";
            for(int x : l[i]){
                cout<<x<<" ";
            }
            cout<<endl;
        }
    }

    void BFS(){
        queue<int> q;
        vector<bool> visited(V, false);

        q.push(0);
        visited[0] = true;

        while(q.size() > 0){
            int u = q.front();
            q.pop();
            cout<< u << " ";

            for(int v : l[u]){
                if(!visited[v]){
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
        cout<<endl;
    }

    void DFShelper(int u, vector<bool>& vis){
        cout<<u << " ";
        vis[u] = true;

        for(auto v : l[u]){
            if(vis[v] != true){
                DFShelper(v, vis);
            }
        }
    }

    void DFS(){
        int u = 0;
        vector<bool> vis(V, false);

        DFShelper(0, vis);
    }
    bool cyclehelper(int u, vector<bool>& vis, int par){
        vis[u] = true;
        cout<< u << " ";

        for(auto v : l[u]){
            if(!vis[v]){
                cyclehelper(v, vis, u);
            }
            else{
                if(v != par){
                    return true;
                }
            }
        }

        return false;
    }
    bool cycledetection(){
        //backedge - parent ke ilawa koi or visited
        //track parent
        vector<bool> vis(V, false);
        return cyclehelper(0,vis,-1);
    }
};

int main() {
    Graph g(5);
    g.addedge(1, 0);
    g.addedge(2,0);
    g.addedge(1 , 2);
    g.addedge(0, 3);
    g.addedge(3,4);
    g.printlist();
    cout<<"BFS Traversal: ";
    g.BFS();
    g.DFS();
    if(g.cycledetection()){
        cout<<"Found cycle"<<endl;
    }
    else{
        cout<<"Not Found cycle"<<endl;
    }
    return 0;
}