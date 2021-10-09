#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <list>
#include <map>
#include <sstream>
#include "Graph.hpp"
//Author: Connor McClellan
//Date:4/30/2021

using namespace std;
int main(int argc, char* arv[])
{
	string fileName;
	string input;
	string s;
	string s1, s2;
	int airports = 0;
	int edges = 0;
	int cost;
	ifstream file;


	cout << "Enter File Name: ";
	cin >> fileName;

	file.open(fileName);
	vector <list<pair<string, int>>> adjList;
	map<string, int> airportList;
	int count = 0;

	/*while we have a line in the file add the value 
	 *to its respected vector or map*/
	while (getline(file, input))
	{
		//allows you to parse the current line
		istringstream stream(input);

		/*if number of airports is 0 then add the first
		 *string to airports as an integer*/
		if (airports == 0)
		{
			airports = stoi(input);
			continue;
		}

		/*if number of edges is zero and the map of 
		 *airports is filled then take the current 
		 *string and add it as an integer. Also,
		 *resize the adjacency list to the number
		 *of airports*/
		if (edges == 0 && count == airports)
		{
			edges = stoi(input);
			adjList.resize(airports);
		}
		/*if the airports map is not filled and the 
		 *number of airports is filled then add a 
		 *pair containing the name of the airport
		 *and an index number*/
		if (count < airports && airports != 0)
		{
			airportList.insert(make_pair(input, count));
			count++;
		}

		/*if the current string has the format of 
		 *two strings and an integer then get the 
		 *index number of both strings from the 
		 *airports map. then take each index 
		 *and add a pair containing the opposite
		 *airport and the cost to travel there
		 *to the adjacency list*/
		if (stream >> s1 >> s2 >> cost)
		{
			int key = airportList[s1];
			int key2 = airportList[s2];
			adjList[key].push_back(make_pair(s2, cost));
			adjList[key2].push_back(make_pair(s1, cost));
		}
	}

	string start;
	string end;
	Graph graph;

	//get the starting airport
	cout << "Starting Point: ";
	cin >> start;
	
	//get the ending airport
	cout << "End Point: ";
	cin >> end;

	/*find the shortest path by passing the adjacency list,
	 *the map of airports, the starting point, the ending point,
	 *and the number of airports to the function below*/ 
	graph.shortestPath(adjList, airportList, start, end, airports);
}
