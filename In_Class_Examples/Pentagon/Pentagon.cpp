// Pentagon.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>    // std::cout  
#include <fstream>
#include <sstream>
#include <string>  
#include <vector>
#include "Point3D.h"

using namespace std;

vector<Point3D> vertices;
vector<int> indices;

bool readFile(const char* filename) {
	// Open the file
	std::ifstream gFile(filename);
	if (!gFile.is_open()) {
		std::cerr << "Could not open " << filename << std::endl;
		return false;
	}

	// Extract vertices and indices
	std::string line;

	double x, y, z;
	std::string val1;
	while (std::getline(gFile, line)) {

		if (line.find('p') != -1) {
			std::istringstream vertexLine(line);
			vertexLine >> val1;
			vertexLine >> x;
			vertexLine >> y;
			vertexLine >> z;
			vertices.push_back(Point3D(x, y, z));
		}
		else if (line.find("c ") != -1) {
			      istringstream faceLine(line);

			faceLine >> val1;
			int val;
			for (int n = 0; n < 3; n++) {
				faceLine >> val;
				//cout << val << endl;
				indices.push_back(val);
			}
		}
	}
	gFile.close();

	return true;
}

void printVertices() {

	for (int i = 0; i < vertices.size(); i++) {

		cout << vertices[i] << endl;
	}
}


int main(){

	bool b = readFile("Pentagon.txt");
	
	if (!b) {
		cerr << "No information available";
		return 0;
	}

	
	printVertices();


    return 0;
}

