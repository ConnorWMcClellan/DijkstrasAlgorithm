#include "Graph.hpp"
#include <map>
#include <queue>
#include <set>
//Author: Connor McClellan
//Date:4/30/2021

//method to find the shortest path using dijkstras algorithm
void 
Graph::shortestPath(vector<list<pair<string, int>>> adjList, map<string,int> vertexList,
	string start, string end, int vertices)
{
	//a map containing the shortest cost to each airport
	map<string, int> cost;

	//a set containing the vertices that have been visited
	set <pair<string, int>> visited;

	/*set each cost of a flight from the adjacncey list to infinity
	 *in the cost map*/ 
	for (unsigned int i = 0; i < adjList.size(); i++)
	{
		
		for (auto j = adjList[i].begin(); j != adjList[i].end(); j++)
		{
			cost[j->first] = 1000000;
		}
	}

	/*set the cost of the starting point to 0
	 *and add it to visited set*/
	cost[start] = 0;
	visited.insert(make_pair(start, 0));

	while (!visited.empty())
	{
		//keeps track of the beginning pair in visited
		pair<string, int> min = *(visited.begin());

		string vertex = min.first;
		int price = min.second;

		visited.erase(visited.begin());

		//gets the index number of the passed in vertex
		int i = vertexList[vertex];

		/*loop through each adjacent vertex of the 
		 *current vertex thats in the adjacency list*/
		for (auto adjacent : adjList[i])
		{
			string v = adjacent.first;

			//if the cost of this path is less then update the cost
			if (cost[adjacent.first] > price + adjacent.second)
			{
				string target = adjacent.first;

				auto j = visited.find(make_pair(target, cost[target]));

				//remove the old pair with the old cost
				if (j != visited.end())
				{
					visited.erase(j);
				}
				//update the cost and insert it into the visited map
				cost[target] = price + adjacent.second;
				visited.insert(make_pair(target, cost[target]));
			}
		}
		
	}

	bool startFound = false;
	bool endFound = false;
	int totalCost = 0;

	/*loop throught each element in cost and find 
	 *the matching airports and print its cost*/
	for (auto i : cost)
	{
		if (i.first == start)
		{
			startFound = true;
		}
		if (i.first == end)
		{
			endFound = true;
			totalCost = i.second;
		}
	}

	/*if the starting point and the ending point are found
	 *the print out the cost*/
	if (startFound == true && endFound == true)
	{
		cout << start << " to " << end << " costs: $" << totalCost << endl;	
 	}
}
