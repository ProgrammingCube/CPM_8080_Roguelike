#include "rogue.h"

Entity* player;
Entity** monsters;
Tile** map;

int main()
{
	Position *start_pos;

	cursSetp();

	puts("Press any key to continue...");
	ranSeed();

	map = crtMpTls();
	start_pos = setupMap();
	player = crtPlyer( start_pos );	/* wth, I need to read the aztec c
					   manual more why does this work */

	gameLoop();

	clseGame();

	return 0;
}