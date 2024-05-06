#include "rogue.h"

void cursSetp()
{
	initscr();
	noecho();
	curs_set( 0 );
}

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