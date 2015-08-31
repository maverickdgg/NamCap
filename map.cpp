#include <iostream>
#include <fstream> 
#include <string>

using namespace std;

#include "map.h"
#include "game.h"

extern char* maps[];

//Done By Daniel(Leader) & Amirul
//Tips from Mr Alex Toh
PMAP load_map(int x)
{
	MAP* map; 
	
	char* filename=maps[x];
	ifstream infile; 
	int nrow, ncol, i; 

	infile.open(filename);
	if (!infile)
	{
		cout << "Error Opening" << filename << endl ; 
		exit(1); 
	}


	if (infile.good())
	{

		// get nrow and ncol at 1st line of the file  
		infile >> nrow >> ncol; 		

		// allocate the MAP structure and memory to hold the map data 
		map = new MAP(nrow, ncol); 

		// read back the map data 
		i= 0; 
		while(infile.good())
		{
			string line; 
			getline(infile, line); 
			if (line.length())
			{
				memcpy(map->data[i],line.c_str(), ncol); 
				i++;
			}
		}

    }
	infile.close(); 
	

	return map; 
}

//Done By Daniel(Leader) & Amirul
//Tips from Mr Alex Toh
void free_map(PMAP pmap)
{
	delete pmap; 
}