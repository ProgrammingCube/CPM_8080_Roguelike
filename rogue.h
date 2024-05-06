#ifndef	ROGUE_H
#define	ROGUE_H

/* put library redefines here */
/* cpm.lib */
#undef	putchar(x)
#define	putchar(x)	cpm_putc(x)
#define	getch()		cpm_getch()
#define	puts(x)		cpm_puts(x)
#define	memset(x)	cpm_memset(x)
/* curses.lib */
#define	clear()		cpm_clr()

#define	false	0
#define	true	1
#define	rand()	( int )( ran() * 1000 )
#define abs(x)  ( ( x < 0 ) ? -x : x )
#define	kbhit()	bdos( 6, 255 )


/* constants */
#define	MAP_HGHT	25
#define	MAP_WDTH	100

typedef struct
{
	unsigned char y;
	unsigned char x;
} Position;

typedef struct
{
	char ch;
	char walkable;
} Tile;

typedef struct
{
	unsigned char height;
	unsigned char width;
	Position pos;
	Position center;
} Room;

typedef struct
{
	Position pos;
	char ch;
} Entity;

/* player.c functions */
Entity* crtPlyer();
void hndlInpt();
void movePlyr();

/* room.c functions */
Room* crteRoom();
void addRoom();
void cnRmCtrs();
/* int abs(); */

/* engine.c functions */
void cursSetp();
void ranSeed();
void gameLoop();
void clseGame();

/* map.c functions */
Tile** crtMpTls();
Position* setupMap();
void freeMap();

/* draw.c functions */
void drawMap();
void drwEnity();
void drwMntrs();
void drwAll();

/* monster.c functions */
Entity* crtMnstr();
void moveMstr();

/* externs */
extern Entity* player;
extern Entity** monsters;
extern Tile** map;
extern double ran();

#endif