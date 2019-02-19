/*
 * Production.h
 *
 *  Created on: Feb 7, 2019
 *      Author: Everett Johnson and Ben Seibert
 */

#ifndef PRODUCTION_H_
#define PRODUCTION_H_
#include "Grid.h"

class Production {
private:

	bool done = false;    // true when the program is done running
	int gridSize = -1;    // Grid Size
	int doodlebugs = -1;  // Number of doodlebugs on our grid
	int ants = -1;        // Number of ants on our grid
	int seed = -1;        // Seed for the Random Number Generator
	char pause = 'n';     // Whether the user prefers to pause or not
	Grid *g = nullptr;              // Grid pointer

public:
	int timeStepsLeft = 100;  // Initialized Number of Time Steps Left
	Production(int argc, char* argv[]);
	bool runProduction();
	virtual ~Production();
	Grid* getGrid();
};

#endif /* PRODUCTION_H_ */
