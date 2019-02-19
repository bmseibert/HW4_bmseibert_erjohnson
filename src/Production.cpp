/*
 * Production.cpp
 *
 *  Created on: Feb 7, 2019
 *      Author: Everett Johnson and Ben Seibert
 */
#include <iostream>
#include <algorithm>
#include "Production.h"
#include "Grid.h"
#include "Cell.h"
#include "Organism.h"
#include "Doodlebug.h"
#include "Ant.h"

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
		int gridArray[gridSize*gridSize];

		for (int i = 0; i<doodlebugs; i++){
			gridArray[i] = 1;
		}
		for (int j = 0; j<ants; j++){
			gridArray[j+doodlebugs] = 2;
		}
		for (int z = 0; z<(gridSize*gridSize)-doodlebugs-ants; z++){
			gridArray[z+doodlebugs+ants] = 0;
		}
		for(int k = 0; k<(gridSize*gridSize); k++){
			int r = rand()%(gridSize*gridSize);
			int temp = gridArray[k];
			gridArray[k] = gridArray[r];
			gridArray[r] = temp;
		}

		// Fill the grid with correct things
		for(int i = 0; i < gridSize; i++){
			for(int c = 0; i < gridSize; c++){
				if(gridArray[i] == 0){
					g.setCellOccupant(i, c, empty);
				}
				else if(gridArray[i] == 1){
					g.setCellOccupant(i, c, doodlebug);
					Doodlebug* d = new Doodlebug(i,c);
					g.getCell(i, c).setOrganism(d);
				}
				else if(gridArray[i] == 2){
					g.setCellOccupant(i, c, ant);
					Ant *a = new Ant(i,c);
					g.getCell(i,c).setOrganism(a);
				}

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

