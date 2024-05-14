#include "Graph.h"

bool Graph::loadCityInformation(const char* filename)
{
	ifstream gFile(filename);
	if (!gFile.is_open())
	{
		std::cerr << "Could not open file: " << filename << std::endl;
		return false;
	}
	string line;
	double x, y, z;
	string cityVal1;
	while (getline(gFile, line))
	{
		if (line.find('p') != -1) {
			istringstream cityPoint(line);
			cityPoint >> cityVal1;
			cityPoint >> x;
			cityPoint >> y;
			cityPoint >> z;
			cityCoordinates.push_back(Point3D(x, y, z));
		}
		else if (line.find('c') != -1) {
			istringstream connectCitys(line);
			connectCitys >> cityVal1;
			int val;
			for (int i = 0; i < 3; i++)
			{
				connectCitys >> val;
				cityIndices.push_back(val);
			}
		}
	}
	return true;
}

void Graph::Generate()
{
	int cityCount = 0;
	for (int i = 0; i < cityIndices.size(); i += 3)
	{

		set<int> cities = { cityIndices[i], cityIndices[i + 1], cityIndices[i + 2] };
		Connectivity[cityCount] = cities;
		cityCount++;
	}
}

void Graph::Print()
{
	for (int i = 0; i < Connectivity.size(); i++)
	{
		set<int > cities = Connectivity[i];
		cout << "[" << i << "]" << ": ";
		for (auto it = cities.begin(); it != cities.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
}

void Graph::showConnectivity(int a)
{
	if (a < 0 || a > Connectivity.size())
	{
		cout << "Invalid city num of " << a << endl;
		return;
	}
	set<int> cities = Connectivity[a];
	cout << " showing connections to [" << a << "] " << endl;
	for (auto it = cities.begin(); it != cities.end(); it++)
	{
		
		Point3D cityA = cityCoordinates[a];
		Point3D cityB = cityCoordinates[*it];
		// I googled a formula to calculate distance between two points in 3D space https://www.calculatorsoup.com/calculators/geometry-solids/distance-two-points.php
		Point3D distance = cityA.subtractPoints(cityB);
		double dis = distance.squarePoint();
		dis = sqrt(dis);
		cout <<"[" << a << "-" << *it << "] " << dis << endl;
	}
	cout << endl;
}