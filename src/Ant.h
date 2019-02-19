/*
 * Ant.h
 *
 *  Created on: Feb 10, 2019
 *      Author: Everett Johnson and Ben Seibert
 */

#ifndef ANT_H_
#define ANT_H_

#include "Organism.h"

class Ant: public Organism {
private:
	int row = 0;
	int col = 0;
	int breedCnt = 0; // breed counter happens once every three time steps

public:
	Ant();
	Ant(int r, int c);
	bool move();
	bool breed();
	bool antStep();
	 ~Ant();

};

#endif /* ANT_H_ */
