/*
 * Production.cpp
 *
 *  Created on: Feb 7, 2019
 *      Author: Everett Johnson and Ben Seibert
 */
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Production.h"
#include "Grid.h"
#include "Cell.h"
#include "Organism.h"
#include "Doodlebug.h"
#include "Ant.h"


/** Production Constructor
 * @param int argc is the number of parameters for the production
 * @param char* argv[] is all of the arguments that we get from the console
 */
Production::Production(int argc, char* argv[]) {
	bool done = false;
	int gridSize = -1;    // Grid Size
	int doodlebugs = -1;  // Number of doodlebugs on our grid
	int ants = -1;        // Number of ants on our grid
	int seed = -1;        // Seed for the Random Number Generator
	char pause = 'n';     // Whether the user prefers to pause or not


	// Makes sure that there are enough inputs
	if (argc < 6){
		printf("Not enough inputs");
		done = true;
	}
	// Not sure about this Statement here
	if (argc >= 7) {
		pause = argv[7][0];

	}
	if (!done){

		// Get the gridSize
		char* ptr = 0;
		long nr_l = strtol(argv[2], &ptr, 10);
		gridSize = (int) nr_l;

		if (gridSize < 1) {
			printf("Usage: GridSize should be greater than 0, received %d.\n", gridSize);
			done = true;
		}

		// Get the number of Doodlebugs
		long nc_l = strtol(argv[3], &ptr, 10);
		doodlebugs = (int)nc_l;

		if (doodlebugs < 0) {
			printf("Usage: Doodlebugs should not be less than 0, received %d.\n", doodlebugs);
			done = true;
		}

		// Get the number of Ants
		long ng_l = strtol(argv[4], &ptr, 10); //get the number of generations
		ants = (int)ng_l;

		if (ants < 0) {
			printf("Usage: Ants should not be less than 0, received %d.\n", ants);
			done = true;
		}

		// Get the number of TimeSteps Remaining
		long nh_l = strtol(argv[5], &ptr, 10); //get the number of generations
		timeStepsLeft = (int)nh_l;

		if (timeStepsLeft < 0) {
			printf("Usage: timeStepsLeft should not be less than 0, received %d.\n", timeStepsLeft);
			done = true;
		}

		// Get the number of the seed
		long nj_l = strtol(argv[6], &ptr, 10); //get the number of generations
		seed = (int)nj_l;

		if (seed < 0) {
			printf("Usage: Seed should not be less than 0, received %d.\n", seed);
			done = true;
		}
		// Initialize the Grid, and put it in memory
		g = new Grid(gridSize);

		// set the counters for the number of ants and doodlebugs
		g->setNumAnt(ants);
		g->setNumDoodle(doodlebugs);
		g->setPause(pause);
		srand(seed);


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
		for(int r = 0; r < gridSize; r++){
			for(int c = 0; c < gridSize; c++){
				if(gridArray[c+ r*(gridSize)] == 0){
					g->setCellOccupant(r, c, empty);
				}
				else if(gridArray[c+ r*(gridSize)] == 1){
					g->setCellOccupant(r, c, doodlebug);
					Doodlebug* d = new Doodlebug(r,c,g);
					g->setCellOrganism(r, c, d);
				}
				else if(gridArray[c+ r*(gridSize)] == 2){
					g->setCellOccupant(r, c, ant);
					Ant *a = new Ant(r,c,g);
					g->setCellOrganism(r, c, a);
				}

			}
		}

	}
	g->printGrid();
}
/** Production::runProduction() runs the simulation
 * @param none
 * @return bool whether the function worked
 */
bool Production::runProduction()
{
	bool result = true;
	int timeSteps = timeStepsLeft;

	while(timeStepsLeft-- > 0 && g->getNumAnt() > 0 && g->getNumDoodle() > 0)
	{
		for(int r = 0; r < g->getNumCells(); r++){
			for(int c = 0; c < g->getNumCells(); c++){

				if (g->getCellOccupant(r, c) == empty){

				}
				// Doodlebugs step;
				if (g->getCellOccupant(r, c) == doodlebug){
					g->getCellOrganism(r, c)->step();


				}


			}


		}
		for(int r=0; r < g->getNumCells(); r++){
			for(int c = 0; c < g->getNumCells(); c++){

				if (g->getCellOccupant(r, c) == empty){

				}
				// Ant step;
				if (g->getCellOccupant(r, c) == ant){
					g->getCellOrganism(r, c)->step();
				}


			}


		}
		if (g->getPause() == 'y') {
			puts("Paused waiting for input.");
			getc(stdin);

		}

		g->printGrid();

	}
	printf("The Total Number of Doodlebugs Left: %d \n", g->getNumDoodle());
	printf("The Total Number of Ants Left: %d \n", g->getNumAnt());
	printf("The Total Number of Steps Simulated is: %d \n", timeSteps - timeStepsLeft);
	return result;
}

/** Production::getGrid() Gets the Grid from the \
 * Production Object
 * @param none
 * @returns the grid object
 */
Grid* Production::getGrid(){
	return g;
}

/** Production::~Production Destrcutor
 * @param none
 * @return none
 */
Production::~Production() {
	// TODO Auto-generated destructor stub
}

