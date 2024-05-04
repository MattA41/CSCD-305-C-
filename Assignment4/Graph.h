#ifndef GRAPH_H
#define GRAPH_H
#include "Point3D/Point3D.h"
#include <vector>
#include <map>
#include <set>
using namespace std;
class Graph
{
	
public:

	// Extracts information from filename to initialize mVertices and vIndices
	bool loadCityInformation(const char* filename);

	// Generates the connectivity map among cities;
	//Calls Link function to generate connectivity information for all cities
	void Generate();

	//prints connectivity information of different cities
	void Print();

	// Displays connectivity information for a particular city “a” and finds
	//distance information of neighboring cities
	void showConnectivity(int a);

private:
	vector<Point3D>cityCoordinates;
	vector<int> cityIndices;
	map<int, set<int>> Connectivity;
};
#endif
