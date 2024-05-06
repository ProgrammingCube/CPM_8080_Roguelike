#include "rogue.h"

Room* crteRoom( y, x, height, width )
unsigned char y, x, height, width;
{
	Room *newRoom;

	newRoom = calloc( 1, sizeof( newRoom ) );

	newRoom->pos.y = y;
	newRoom->pos.x = x;
	newRoom->height = height;
	newRoom->width = width;
	newRoom->center.y = y + ( unsigned char )( height / 2 );
	newRoom->center.x = x + ( unsigned char )( width / 2 );

	return newRoom;
}

void addRoom( room )
Room *room;
{
	unsigned char x, y;
	for ( y = room->pos.y; y < room->pos.y + room->height; y++ )
	{
		for ( x = room->pos.x; x < room->pos.x + room->height; x++ )
		{
			map[ y ][ x ].ch = '.';
			map[ y ][ x ].walkable = true;
		}
	}
}

void cnRmCtrs( c_One, c_Two )
Position* c_One;
Position* c_Two;
{
	Position temp;
	int temp1_1, temp1_2;
	int temp2_1, temp2_2;
	int temp3_1, temp3_2;
	int temp4_1, temp4_2;
	temp.x = c_One->x;
	temp.y = c_One->y;

	while ( true )
	{
		temp1_1 = ( temp.x - 1 ) - c_Two->x;
		temp1_2 = temp.x - c_Two->x;
		temp2_1 = ( temp.x + 1 ) - c_Two->x;
		temp2_2 = temp.x - c_Two->x;
		temp3_1 = ( temp.y + 1 ) - c_Two->y;
		temp3_2 = temp.y - c_Two->y;
		temp4_1 = ( temp.y - 1 ) - c_Two->y;
		temp4_2 = temp.y - c_Two->y;

		if ( abs( temp1_1 ) < abs( temp1_2 ) )
			temp.x--;
		else if ( abs( temp2_1 ) < abs( temp2_2 ) )
			temp.x++;
		else if ( abs( temp3_1 ) < abs( temp3_2 ) )
			temp.y++;
		else if ( abs( temp4_1 ) < abs( temp4_2 ) )
			temp.y--;
		else
			break;

		map[ temp.y ][ temp.x ].ch = '.';
		map[ temp.y ][ temp.x ].walkable = true;
	}
}