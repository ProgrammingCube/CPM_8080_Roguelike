#include "rogue.h"

void drawMap()
{
	unsigned char x, y;
	for (  y = 0; y < MAP_HGHT; y++ )
	{
		for ( x = 0; x < MAP_WDTH; x++ )
		{
			mvaddch( y, x, map[ y ][ x ].ch );
		}
	}
}

void drwEnity( entity )
Entity *entity;
{
	mvaddch( entity->pos.y, entity->pos.x, entity->ch );
}

void drwMntrs( monsters )
Entity** monsters;
{
	
}

void drwAll()
{
	clear();
	drawMap();
	drwMntrs( monsters );
	drwEnity( player );	/* wth, I thought I couldn't pass via stack */
}