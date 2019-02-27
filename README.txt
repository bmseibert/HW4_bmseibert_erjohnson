~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
~~ Ants and Doodlebugs Simulation ~~
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

~~ By Everett Johnson and Ben Seibert

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

~~ RULES ~~

This program involves a simulation of a grid of n-by-n squares, some of which may be occupied 
by organisms. 
There are two kinds of organisms — doodlebugs (the predators) and ants (the prey). 
Only one organism may occupy a cell at a time. Time is simulated in steps. 
Each organism attempts to perform some action every step. 
No action may cause an organism to move off the edges of the grid.

Ants behave as follows:
    • Move. For every step, each ant enumerates its adjacent cells — up, down, left, or 
right — and randomly selects an unoccupied one that is on the grid 
(Note: For this assignment, a cell has a maximum of four neighbors; no diagonal moves are
allowed). 
If all adjacent cells are occupied or off the edges of the grid, the ant does not move but 
rather remains in its current location.
    • Breed. If an ant survives for at least three time steps, at the end of the third time 
step (i.e., after moving) the ant gives birth to a new ant in an adjacent cell (i.e., up, 
down, left, or right). 
If more than one empty cell is available, it chooses one at random. 
If no empty cell is available, no birth occurs (but the ant is free to try breeding again on 
the next time step).
Once an offspring is produced, an ant cannot produce another offspring until it has survived 
three additional steps.


Doodlebugs behave as follows:
    • Move. For every time step, each doodlebug moves to an adjacent cell containing an ant 
and eats that ant. 
If more than one adjacent cell contains an ant, one is chosen at random. 
The ant that was eaten is removed from the grid. 
If no adjacent cell (i.e., up, down, left, or right) contains an ant, the doodlebug moves 
according to the same rules as ants. 
Note that a doodlebug cannot eat another doodlebug.
    • Starvation. If a doodlebug has not eaten an ant within three time steps, at the end 
of the third time step, it dies of starvation and is removed from the grid.
    • Breed. If a doodlebug survives for at least eight time steps, at the end of the eighth
time step it spawns off a new doodlebug in the same manner as an ant. 
If no adjacent cell is empty, no breeding occurs. 
Once an offspring is produced, a doodlebug cannot produce another offspring until it has 
survived eight additional steps. Starvation takes precedence over breeding; 
that is, a starving doodlebug cannot breed.

During each time step, the doodlebugs act before the ants.  
That is, a doodlebug may eat an ant that was about to move and possibly to breed; as a 
result, that ant is dead and can no longer do either.

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

~ RUNNING THE PROGRAM ~

In order to run my program, the user needs to put arguments for the function

./PA5 gridSize #doodlebugs #ants #time_steps seed pause

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
What each variable does is specified below: 

    1. gridSize — an integer representing the number of cells along one dimension of the grid 
(defaulting to 20)
    2. #doodlebugs — an integer indicating the number of doodlebugs (default 5)
    3. #ants — an integer indicating the number of ants (default 100)
    4. #time_steps — the number of time steps to play (default 1000)
    5. seed — an integer indicating the seed for the random number generator, with zero meaning 
to use the current time as the seed (default seed value is 1)
    6. pause — an indication as to whether to pause. Blank or zero means do not pause. 
A non-negative value n means pause and print the grid after each nth step. 
Wait for one character input before continuing.

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
~Note: The user does not type the square brackets; they 
are used to denote that this argument is optional. 
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

~INPUTTING ARGUMENTS~

In order to input these arguments the user needs to navigate to the Run Configurations in
eclipse (Run >> RunConfigurations) and then to the arguments tab (Run Configurations >>
C/C++ Application >> HW2 Debug >> Arguments). In this window type in the command verbatum 
with all of the specified data above. 

Once all of the necessary arguments are specified, press Apply and then Run. 


~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

~PROBLEMS THAT WE HAD~ 

One of the issues that we have been having was debugging the code when we step. 
For some reason we also had an issue going through and grabbing a cell or grabbing and 
changing values.
This was fixed by adding functions to the grid instead of the cell class. 

Another problem that we had was setting up the github shared repo that we could use back and 
forth because the make file and other files were being shared so we had to tell git to ignore 
them.



~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

~ BORROWED CODE & HOW IT WORKS~

All borrowed code came directly from the professors and had none to little affect on the broad program.
We did not need the majority of it and ended up rewriting the majority of it. 



~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~











