#include "rogue.h"

Entity* crtMnstr( start_pos )
Position *start_pos;
{
	Entity* newMnstr = calloc ( 1, sizeof ( Entity ) );
	
	newMnstr->pos.y = start_pos->y;
	newMnstr->pos.x = start_pos->x;
	newMnstr->ch = 'M';
	
	return newMnstr;
}

void moveMstr( monster, newPos )
Entity *monster;
Position *newPos;
{
	if ( map[ newPos->y ][ newPos->x ].walkable )
	{
		monster->pos.y = newPos->y;
		monster->pos.x = newPos->x;
	}
}