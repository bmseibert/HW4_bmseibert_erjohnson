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

public:
	Grid *g = nullptr;        // Grid pointer
	int timeStepsLeft = 100;  // Initialized Number of Time Steps Left
	Production(int argc, char* argv[]);
	bool runProduction();
	virtual ~Production();
	Grid* getGrid();
};

#endif /* PRODUCTION_H_ */
