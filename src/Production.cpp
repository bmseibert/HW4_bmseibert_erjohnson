/*
 * Production.cpp
 *
 *  Created on: Feb 7, 2019
 *      Author: Everett Johnson and Ben Seibert
 */
#include <iostream>
#include "Production.h"

int timestepsLeft=100;


Production::Production(int argc, char* argv[]) {

	// Makes sure that there are enough inputs
	if (argc < 5){
		printf("Not enough inputs");
		done = true;
	}
	// Not sure about this Statement here
	if (argc >= 6) {
		pause = argv[6];
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
		long ng_l = strtol(argv[4], &ptr, 10); //get the number of generations
		timeStepsLeft = (int)ng_l;

		if (timeStepsLeft < 0) {
			printf("Usage: timeStepsLeft should not be less than 0, received %d.\n", timeStepsLeft);
			done = true;
		}

		// Get the number of the seed
		long ng_l = strtol(argv[5], &ptr, 10); //get the number of generations
		seed = (int)ng_l;

		if (seed < 0) {
			printf("Usage: Seed should not be less than 0, received %d.\n", seed);
			done = true;
		}

	}
}

bool Production::runProduction()
{
	bool result = true;

	while(timestepsLeft-- > 0)
	{
		//dbs.step;
		//ants.step;
	}
	return result;
}

Production::~Production() {
	// TODO Auto-generated destructor stub
}

