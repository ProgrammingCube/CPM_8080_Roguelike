#include "rogue.h"

Entity* crtPlyer( start_pos )
Position *start_pos;
{
	Entity* newPlayr = calloc ( 1, sizeof ( Entity ) );
	
	newPlayr->pos.y = start_pos->y;
	newPlayr->pos.x = start_pos->x;
	newPlayr->ch = '@';
	
	return newPlayr;
}

void hndlInpt( input )
char input;
{
	Position newPos;
	newPos.y = player->pos.y;
	newPos.x = player->pos.x;

	switch( input )
	{
		/* move up */
		case 'k':
			newPos.y--;
			break;
		/* move down */
		case 'j':
			newPos.y++;
			break;
		/* move left */
		case 'h':
			newPos.x--;
			break;
		/* move right */
		case 'l':
			newPos.x++;
			break;
		default:
			break;
	}

	movePlyr( &newPos );
}

void movePlyr( newPos )
Position *newPos;
{
	if ( map[ newPos->y ][ newPos->x ].walkable )
	{
		player->pos.y = newPos->y;
		player->pos.x = newPos->x;
	}
}