/*
 * Doodlebug.h
 *
 *  Created on: Feb 10, 2019
 *      Author: Everett Johnson and Ben Seibert
 */

#ifndef DOODLEBUG_H_
#define DOODLEBUG_H_

#include "Organism.h"

class Doodlebug: public Organism {
private:
	int row = 0;
	int col = 0;
	int starveCnt = 0; //starving counter
	int breedCnt = 0; //breeding counter

public:
	Doodlebug();
	Doodlebug(int r, int c);
	bool move();
	bool breed();
	bool eat();
	int getStarveCnt();
	virtual ~Doodlebug();

};

#endif /* DOODLEBUG_H_ */
