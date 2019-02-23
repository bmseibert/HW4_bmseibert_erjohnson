/*
 * Doodlebug.h
 *
 *  Created on: Feb 10, 2019
 *      Author: Everett Johnson and Ben Seibert
 */

#ifndef DOODLEBUG_H_
#define DOODLEBUG_H_

#include "Organism.h"
#include <stdio.h>

class Doodlebug: public Organism {
private:
	int row = 0;
	int col = 0;
	int starveCnt = 0; //starving counter
	int breedCnt = 0; //breeding counter
	Grid* g = nullptr;

public:

	Doodlebug();
	Doodlebug(int r, int c);
	bool move();
	bool breed();
	bool eat();
	int getStarveCnt();
	~Doodlebug();
	bool step();
	bool increm();
	bool setBreedCnt(int i);
	int howManyNeighbors(int row, int col, Grid* g);
	int* getRandCell(int row, int col, Grid* g);

};

#endif /* DOODLEBUG_H_ */
