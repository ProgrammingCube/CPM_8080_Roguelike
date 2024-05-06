#include "rogue.h"

void cursSetp()
{
	initscr();
	noecho();
	curs_set( 0 );
}

/* what is going on with this, doesn't trigger every key hit */
void ranSeed()
{
	do
	{
		rand();
	}
	while ( ! ( kbhit() ) );
}

void gameLoop()
{
	char ch;
	do
	{
		if ( ch == 'q' )
			break;
		
		hndlInpt( ch );
		drwAll();
	}
	while ( ch = getch() );
}

void clseGame()
{
	endwin();
	free( player );
}