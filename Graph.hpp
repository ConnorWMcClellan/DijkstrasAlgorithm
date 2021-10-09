#ifndef _GRAPH_HPP_
#define _GRAPH_HPP_

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <map>
//Author: Connor McClellan
//Date:4/30/2021

using namespace std;

class Graph
{
private:

public:
	//method to find the shortest path using dijkstras algorithm
	void shortestPath(vector<list<pair<string, int>>> adjList, map<string, int> vertexList, 
		string start, string end, int vertices);
};
#endif
