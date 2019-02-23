/*
 * Tests2.cpp
 *
 *  Created on: Feb 7, 2019
 *      Author: student
 */

#include "Tests2.h"
#include "Grid.h"
#include "Ant.h"
#include <iostream>
#include <stdio.h>


Tests2::Tests2() {
	// TODO Auto-generated constructor stub
	//initialize the grid
}

bool Tests2::doTests()
{
	bool results;
	//establish a grid
	bool ok1 = gridTest();
	//populate it with ants
	bool ok2 = makeAntsTest();
	//see whether they move
	bool ok3 = antsMoveTest();
	//see whether they breed
	bool ok4 = antsBreedTest();
	//see whether they die?
	bool ok5 = antsDieTest();//maybe if they wander off?
	//populate with doodlebugs
	bool ok6 = makeDoodlesTest();
	//see whether they move
	bool ok7 = doodleMoveTest();
	//see whether they breed
	bool ok8 = doodleBreedTest();
	//see whether they eat ants
	bool ok9 = doodleEatTest();
	//see whether they die
	bool ok10 = doodleDietest();
	bool ok11 = OrganismTest();
	results = ok1 && ok2 && ok3 && ok4 && ok5 && ok6 && ok7 && ok8 && ok9 && ok10 && ok11;
	return results;
}

/** Test the Grid class by constructing a grid object and calling the
 * getCellOccupant() method on a random cell, then using the setCellOccupant
 * to ant, and checking if the getCellOccupant returns ant, then
 * destructs the grid
 *  @return true if the initialized grid does not have a occupant in a
 *  random cell and if once you use the setter method, the occupant
 *  status changes to the set enumeration (empty, ant or doodlebug)
 */
bool Tests2::gridTest()
{
	bool result = true;
	bool ok1 = true;
	bool ok2 = true;
	std::cout << "Running the grid test" << std::endl;
	Grid myGrid = Grid(8);
	if(myGrid.getCellOccupant(2, 3)!=empty)
	{
		std::cout << "Cell not initially empty" << std::endl;
		ok1 = false;
	}
	std::cout << "second grid test" << std::endl;
	myGrid.setCellOccupant(2, 3, ant);
	if(myGrid.getCellOccupant(2, 3)!=ant)
	{
		std::cout << "Cell not set to ant" << std::endl;
		ok2 = false;
	}
	std::cout << "third grid test" << std::endl;
	myGrid.~Grid();
	result = ok1 && ok2;
	return result;
}
/** Test the Ant class by constructing a grid object and setting a cell
 *  occupant to ant, then it creates an ant object
 *  @return true if the initialized grid does not have a occupant in a
 *  random cell and if once you use the setter method, the occupant
 *  status changes to the set enumeration (empty, ant or doodlebug)
 */
bool Tests2::makeAntsTest()
{
	bool result = true;
	bool ok1 = true;
	bool ok2 = true;
	std::cout << "Running the make ants test" << std::endl;

	Grid* myGrid_p = new Grid(9);
	if(myGrid_p->getCellOccupant(1, 2)!=empty)
	{
		std::cout << "Cell 1,2 not initially empty" << std::endl;
	}
	myGrid_p->setCellOccupant(1, 2, ant);
	if(myGrid_p->getCellOccupant(1, 2)!=ant)
	{
		std::cout << "Cell not set to ant" << std::endl;
		ok1 = false;
	}
	Ant* a1 = new Ant(3,4);
	if(myGrid_p->getCellOccupant(3, 4)!=empty)
	{
		std::cout << "Cell 3,4 not initially empty" << std::endl;
	}
	myGrid_p->setCellOccupant(3, 4, doodlebug);
	if(myGrid_p->getCellOccupant(3, 4)!=doodlebug)
	{
		std::cout << "Cell not set to doodlebug" << std::endl;
		ok2 = false;
	}
	myGrid_p->setCellOccupant(3, 4, empty);
	delete a1;
	delete myGrid_p;
	result = ok1 && ok2;
	return result;
}

bool Tests2::OrganismTest()
{
	bool result = true;
	bool ok1 = true;
	bool ok2 = true;
	bool ok3 = true;
	std::cout << "Running the Organism Methods test" << std::endl;

	Grid* myGrid_t = new Grid(9);
	if(myGrid_t->getCellOccupant(3, 4)!=empty)
	{
		std::cout << "Cell 3,4 not initially empty" << std::endl;
	}
	Ant* a3 = new Ant(3,4);
	myGrid_t->setCellOccupant(3, 4, ant);
	Ant* a4 = new Ant(3,5);
	myGrid_t->setCellOccupant(3, 5, ant);
	Ant* a5 = new Ant(8,6);
	myGrid_t->setCellOccupant(8, 6, ant);


	int numNeighbors1 = a3->howManyNeighbors(3, 4, myGrid_t);
	printf("numNeighbors1: %d \n", numNeighbors1);
	if(numNeighbors1 != 3){
		ok1 = false;
		printf("did not find neighbor\n");
	}

	int n = myGrid_t->getNumCells();
	printf("nRows %d \n", n);
	int numNeighbors2 = a5->howManyNeighbors(8, 6, myGrid_t);
	printf("numNeighbors2: %d \n", numNeighbors2);
	if(numNeighbors2 != 3){
		ok2 = false;
		printf("found a non-existent neighbor neighbor\n");
	}
//	int arr[] = {*(a3->getRandCell(3, 4, myGrid_t))};
//	printf("arr: %d ", arr[0]);
//	printf(" %d \n", arr[1]);
//	if((arr[0] == 4 && arr[1] == 4) || (arr[0] == 3 && arr[1] == 2) ||
//	   (arr[0] == 2 && arr[1] == 4)){
//		ok3 = false;
//		printf("GetRandCell returned a cell that was not empty");
//	}


	result = ok1 && ok2 && ok3;
	return result;
}

bool Tests2::antsMoveTest()
{
	bool result = true;
	std::cout << "Running the move ants test" << std::endl;
	return result;
}
bool Tests2::antsBreedTest()
{
	bool result = true;
	std::cout << "Running the breed ants test" << std::endl;
	return result;
}
bool Tests2::antsDieTest()
{
	bool result = true;
	std::cout << "Running the ants die test" << std::endl;
	return result;
}
bool Tests2::makeDoodlesTest()
{
	bool result = true;
	std::cout << "Running the make doodlebugs test" << std::endl;
	return result;
}
bool Tests2::doodleMoveTest()
{
	bool result = true;
	std::cout << "Running the move doodlebugs test" << std::endl;
	return result;
}
bool Tests2::doodleBreedTest()
{
	bool result = true;
	std::cout << "Running the breed doodlebugs test" << std::endl;
	return result;
}
bool Tests2::doodleEatTest()
{
	bool result = true;
	std::cout << "Running the eat ant test" << std::endl;
	return result;
}
bool Tests2::doodleDietest()
{
	bool result = true;
	std::cout << "Running the doodlebug dies test" << std::endl;
	return result;
}

Tests2::~Tests2() {
	// TODO Auto-generated destructor stub
}

