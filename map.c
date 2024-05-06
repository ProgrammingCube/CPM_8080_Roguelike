#include "rogue.h"

Tile** crtMpTls()
{
	unsigned char x, y;
	Tile** tiles = calloc( MAP_HGHT, sizeof( Tile* ) );

	for ( y = 0; y < MAP_HGHT; y++ )
	{
		tiles[ y ] = calloc( MAP_WDTH, sizeof( Tile ) );
		for ( x = 0; x < MAP_WDTH; x++ )
		{
			tiles[ y ][ x ].ch = '#';
			tiles[ y ][ x ].walkable = false;
		}
	}

	return tiles;
}

Position* setupMap()
{
	unsigned char x, y, i, height, width, n_rooms;
	Position *start_pos;
	Room* rooms;
	n_rooms = ( rand() * 11 ) + 5;
	rooms = calloc( n_rooms, sizeof( Room ) );
	start_pos = calloc( 1, sizeof( Position ) );
	

	for ( i = 0; i < n_rooms; i++ )
	{
		y = ( rand() % ( MAP_HGHT - 10 ) ) + 1;
		x = ( rand() % ( MAP_WDTH - 20 ) ) + 1;
		height = ( rand() % 7 ) + 3;
		width = ( rand() % 15 ) + 5;
		rooms[ i ] = *crteRoom( y, x, height, width );	/* This is an
								array of pointers */
		addRoom( &rooms[ i ] );

		if ( i > 0 )
		{
			cnRmCtrs( &rooms[ i - 1 ].center, &rooms[ i ].center );
		}
	}

	start_pos->y = rooms[ 0 ].center.y;
	start_pos->x = rooms[ 0 ].center.x;

	free( rooms );

	return start_pos;
}

void freeMap()
{
	unsigned char y;
	for ( y = 0; y < MAP_HGHT; y++ )
		free( map[ y ] );
	free( map );
}