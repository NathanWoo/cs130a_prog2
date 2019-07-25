#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;



int minKey(vector<int> &key, vector<bool> &mstSet, int V){  
    int min = INT_MAX, min_index;  
    for (int v = 0; v < V; v++)  
        if (mstSet[v] == false && key[v] < min)  
            min = key[v], min_index = v;    
    return min_index;  
}  

void printMST(vector<int> &parent, vector<int> &path, std::vector< std::vector<int> > &graph)  {  
    cout<<"Edge \tWeight\n";  
    // for (int i = 1; i < V; i++)  
    //     cout<<parent[i]<<" - "<<i<<" \t"<<graph[i][parent[i]]<<" \n";  
    for (int i = 1; i < path.size(); i++){
        int currentlyon = path[i];
        cout<< parent[currentlyon] <<" - "<<currentlyon<<" \t"<<graph[parent[currentlyon]][currentlyon]<<" \n";
    }
}  

void primMST(std::vector< std::vector<int> > &graph, std::vector< std::vector<int> > &graph1, int V){  
    vector<int> key(V);
    vector<bool> mstSet(V);
    vector<int> parent(V);
    vector<int> path;

    for (int i = 0; i < V; i++){
        key[i] = INT_MAX, mstSet[i] = false; 
    }   
  

    key[0] = 0;  
    parent[0] = -1; // First node is always root of MST  
  
    for (int count = 0; count < V; count++) 
    {  
        int u = minKey(key, mstSet, V);
         cout << "pushing this u " << u << endl;
        path.push_back(u);
        // std::cout << "and the u is" << u << std::endl;
  
        mstSet[u] = true;  
  
        for (int v = 0; v < V; v++){
        //     if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]){
        //         parent[v] = u, key[v] = graph[u][v]; 
        //     }  
        // }  


            if (v < V && path.size() < V/2){
                if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]){
                    parent[v] = u, key[v] = graph[u][v]; 
                    // std::cout<< " the parent of " << v <<" is " << u <<std::endl; 
                } 
                if (path.size() == V/2){
                    printMST(parent, path, graph);
                }    
            }
            else{
                 if (graph1[u][v] && mstSet[v] == false && graph1[u][v] < key[v]){
                    parent[v] = u, key[v] = graph1[u][v]; 
                    // std::cout<< " the parent of " << v <<" is " << u <<std::endl; 
                } 
            }
        }         

    }  

    printMST(parent, path, graph1);  
}


int main(int argc, char* argv[]) {
  // parse the expected input
  // first, the number of nodes for the complete graph part
  int num_nodes;
  std::cin >> num_nodes;

  // second, read in the complete graph
  std::vector< std::vector<int> > graph;
  for(int i=0; i<num_nodes; ++i) {
    std::vector<int> row;
    for (int j=0; j<num_nodes; ++j) {
      int cost;
      std::cin >> cost;
      row.push_back(cost);
    }
    graph.push_back(row);
  }


  int V = num_nodes;

  std::vector< std::vector<int> > graph1 = graph;

  // ...

  // last bit until newline from last cin followed by a blank line
  std::string skip;
  std::getline(std::cin, skip);
  std::getline(std::cin, skip);

  // read in the new edges
  // parse input lines until I find newline
  for(std::string line; std::getline(std::cin, line) && line.compare(""); ) {
    std::stringstream ss(line);
    int from;
    int to;
    int cost;
    ss >> from;
    ss >> to;
    ss >> cost;

    graph1[to][from] = graph1[from][to] = cost;
  }

  // ...
    primMST(graph, graph1,V);
    return 0;
}