/************************************************************************************
** Author: Elizabeth Graalum
** Date: May 23rd, 2018
** Description:
************************************************************************************/

#include <iostream>
#include "squareGame.hpp"

int main()
{
	squareGame game;

	while (game.finished() == 0)	// loop until a winner is found
	{
		game.next_turn();	// game loop
	}

return 0;
}
