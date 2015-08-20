//#include <iostream>
//#include <fstream> 
//#include <string>
//
//using namespace std;
//
//#include "map.h"
//#include "Framework\console.h"
//#include "game.h"
//extern Console console;
//extern int score;
//extern int score2;
//extern int g_csRows;
//extern int g_csCol;
//extern const int ciOffsetX;
//extern const int ciOffsetY;
//extern const unsigned char wall;
//extern unsigned char coin;
//
//
//PMAP load_map(char* filename)
//{
//	MAP* map; 
//	
//	ifstream infile; 
//	int nrow, ncol, i; 
//
//	infile.open(filename); 	
//	if (!infile)
//	{
//		cout << "Error Opening" << filename << endl ; 
//		exit(1); 
//	}
//
//
//	if (infile.good())
//	{
//
//		// get nrow and ncol at 1st line of the file  
//		infile >> nrow >> ncol; 		
//
//		// allocate the MAP structure and memory to hold the map data 
//		map = new MAP(nrow, ncol); 
//
//		// read back the map data 
//		i= 0; 
//		while(infile.good())
//		{
//			string line; 
//			getline(infile, line); 
//			if (line.length())
//			{
//				memcpy(map->data[i],line.c_str(), sizeof(map->data[i])); 
//				i++;
//			}
//		}
//	}
//	infile.close(); 
//	
//
//	return map; 
//}
//
//void insertmap(PMAP)
//{
//    MAP* sMap;
//	console.writeToBuffer(0,2,"Player1",0x1B);
//	console.writeToBuffer(0,3,"Score: ",0x1B);
//	console.writeToBuffer(8,3,score,0x1B);
//	console.writeToBuffer(68,2,"Player2",0x46);
//	console.writeToBuffer(68,3,"Score: ",0x46);
//    console.writeToBuffer(76,3,score2,0x46);
//
//    for(int i=ciOffsetX;i<g_csCol+ciOffsetX;++i){
//        for(int j=ciOffsetY;j<g_csRows+ciOffsetY;++j){ 
//            if(sMap[j-ciOffsetY][i-ciOffsetX]==1){
//                console.writeToBuffer(i,j,wall,0x0F);
//            }
//			if(sMap[j-ciOffsetY][i-ciOffsetX]==0){
//                console.writeToBuffer(i,j,coin,0x0E);
//            }
//        }  
//    }
//}
//
//void free_map(PMAP pmap)
//{
//	delete pmap; 
//}