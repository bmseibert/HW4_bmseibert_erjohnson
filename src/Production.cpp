/*
 * Production.cpp
 *
 *  Created on: Feb 7, 2019
 *      Author: Everett Johnson and Ben Seibert
 */
#include <iostream>
#include "Production.h"
#include "Grid.h"

int timestepsLeft=100;


Production::Production(int argc, char* argv[]) {

	// Makes sure that there are enough inputs
	if (argc < 5){
		printf("Not enough inputs");
		done = true;
	}
	// Not sure about this Statement here
	if (argc >= 6) {
		char* ptr1 = 0;
		long nb_l = strtol(argv[1], &ptr1, 10);
		pause = (char) nb_l;

	}
	if (!done){

		// Get the gridSize
		char* ptr = 0;
		long nr_l = strtol(argv[1], &ptr, 10);
		gridSize = (int) nr_l;

		if (gridSize < 1) {
			printf("Usage: GridSize should be greater than 0, received %d.\n", gridSize);
			done = true;
		}

		// Get the number of Doodlebugs
		long nc_l = strtol(argv[2], &ptr, 10);
		doodlebugs = (int)nc_l;

		if (doodlebugs < 0) {
			printf("Usage: Doodlebugs should not be less than 0, received %d.\n", doodlebugs);
			done = true;
		}

		// Get the number of Ants
		long ng_l = strtol(argv[3], &ptr, 10); //get the number of generations
		ants = (int)ng_l;

		if (ants < 0) {
			printf("Usage: Ants should not be less than 0, received %d.\n", ants);
			done = true;
		}

		// Get the number of TimeSteps Remaining
		long nh_l = strtol(argv[4], &ptr, 10); //get the number of generations
		timeStepsLeft = (int)nh_l;

		if (timeStepsLeft < 0) {
			printf("Usage: timeStepsLeft should not be less than 0, received %d.\n", timeStepsLeft);
			done = true;
		}

		// Get the number of the seed
		long nj_l = strtol(argv[5], &ptr, 10); //get the number of generations
		seed = (int)nj_l;

		if (seed < 0) {
			printf("Usage: Seed should not be less than 0, received %d.\n", seed);
			done = true;
		}
		// Initialize the Grid
		Grid g = Grid(gridSize);

		// Initialize all of the doodlebugs and the ants
		for(int i = 0; i<doodlebugs; i++){
			g.setCellOccupant(rand()%gridSize, rand()%gridSize, doodlebug);
		}
		// Initialize all of the ants
		for(int j= 0; j<ants; j++){
			int f1 = rand()%gridSize;
			int f2 = rand()%gridSize;
			if(g.getCellOccupant(f1, f2) == empty){
				g.setCellOccupant(f1, f2, ant);
			}
			else{

			}
		}

	}
}

bool Production::runProduction()
{
	bool result = true;

	while(timeStepsLeft-- > 0)
	{

		//dbs.step;
		//ants.step;
	}
	return result;
}

Production::~Production() {
	// TODO Auto-generated destructor stub
}

