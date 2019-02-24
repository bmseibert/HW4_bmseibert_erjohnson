/*
 * Tests2.h
 *
 *  Created on: Feb 7, 2019
 *      Author: Everett Johnson and Ben Seibert
 */

#ifndef TESTS2_H_
#define TESTS2_H_

class Tests2 {
public:
	Tests2();
	bool doTests();
	bool gridTest();
	bool makeAntsTest();
	bool OrganismTest();
	bool antsMoveTest();
	bool antsBreedTest();
	bool antsDieTest();
	bool makeDoodlesTest();
	bool doodleMoveTest();
	bool doodleBreedTest();
	bool doodleEatTest();
	bool doodleDietest();
	bool organismNeighborTest();
	bool organismRandCellTest();


	virtual ~Tests2();
};

#endif /* TESTS2_H_ */
