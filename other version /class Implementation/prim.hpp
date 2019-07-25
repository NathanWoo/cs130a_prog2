// prim.h created by Nathan Wu

#ifndef PRIM_H
#define PRIM_H


#include <vector>

class MST{
public:
	MST(int V = 0);
	// void primMST(std::vector< std::vector<int> > graph);
	void primMST(std::vector< std::vector<int> > graph, std::vector< std::vector<int> > graph1);

private:
	int V;
	std::vector<int> parent; //store constructed MST
	std::vector<bool> mstSet; //store the status of vertices of whether it is in the MST or not 
	std::vector<int> key; //store the min weight edge in cut 
	std::vector<int> path;

	int minKey();
	void printMST(std::vector< std::vector<int> > graph);



};

#endif