#include <stdio.h>
#include <limits.h>
#include <iostream>

#include "prim.hpp"
 
using namespace std;
 

MST::MST (int V){
    this->V = V;
    this->parent.resize(V);
    this->mstSet.resize(V);
    this->key.resize(V);

}

int MST::minKey(){
    int min = INT_MAX, min_index;  
  
    for (int v = 0; v < this->V; v++)  
        if (this->mstSet[v] == false && this->key[v] < min)  
            min = this->key[v], min_index = v;  
  
    return min_index; 
}


void MST::printMST(std::vector< std::vector<int> > graph){  
    cout<<"Edge \tWeight\n";  
    for (int i = 1; i < this->path.size(); i++){
        int currentlyon = path[i];
        cout<< parent[currentlyon] <<" - "<<currentlyon<<" \t"<<graph[parent[currentlyon]][currentlyon]<<" \n";
    }
}  



void MST::primMST(std::vector< std::vector<int> > graph, std::vector< std::vector<int> > graph1){  
    for (int i = 0; i < this->V; i++){
        this->key[i] = INT_MAX, this->mstSet[i] = false; 
    }   
  

    this->key[0] = 0;  
    this->parent[0] = -1; // First node is always root of MST  
  
    for (int count = 0; count < this->V - 1; count++) 
    {  
        int u = minKey();
        path.push_back(u);
        // std::cout << "and the u is" << u << std::endl;
  
        this->mstSet[u] = true;  
  
        for (int v = 0; v < V; v++){
        //     if (graph[u][v] && this->mstSet[v] == false && graph[u][v] < this->key[v]){
        //         this->parent[v] = u, this->key[v] = graph[u][v]; 
        //     }  
        // }  


            if (v < V/2 - 1){
                if (graph[u][v] && this->mstSet[v] == false && graph[u][v] < this->key[v]){
                    this->parent[v] = u, this->key[v] = graph[u][v]; 
                    // std::cout<< " the parent of " << v <<" is " << u <<std::endl; 
                }     
            }
            else{
                 if (graph1[u][v] && this->mstSet[v] == false && graph1[u][v] < this->key[v]){
                    this->parent[v] = u, this->key[v] = graph1[u][v]; 
                    std::cout<< " the parent of " << v <<" is " << u <<std::endl; 
                } 
            }
        }         

    }  
    std::cout << "Before Printing" <<std::endl;

    printMST(graph1);  
}