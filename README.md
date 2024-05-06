# Roguelike for the Intel 8080 (CP/M)

## What is this?
This is my attempt to create more games for the venerable [Intel 8080](https://en.wikipedia.org/wiki/Intel_8080). So many games are written for the [Zilog Z80](https://en.wikipedia.org/wiki/Zilog_Z80), and while no beef, I think that the 8080 deserves a gaming life that it never really got with its much more powerful, versitile step brother.

## Did I make this all on my own?
No, absolutely not! While this is not the [first](https://github.com/ProgrammingCube/CmdRogue) roguelike I've made, nor even the [first](https://github.com/ProgrammingCube/SymRogue) retro computer roguelike I've made, I used this very VERY handy [tutorial](https://dev.to/ignaoya/series/13852) for heavy inspiration.

I directly ported the entire tutorial over, changing only to the old K&R syntax and using my [homebrew CP/M libraries](https://github.com/ProgrammingCube/CPM_Aztec_C_Libraries) as well as changing things from int to char as applicable. In the future, as I add more features, I really plan on getting down and gritty; optimizing the game so its actually playable.

## If I just ported modern computer code, how fast does it run now?
A cool 30 seconds per frame, nearly EXACT. Don't get me started on room generation times!

I know this can be sped up a ton, look at [Rogue](https://groups.google.com/g/imsai8080esp/c/gRAjnK-aN0I) for CP/M and how fast and awesome it runs! Sure, its on a Z80, but still!

## How can I build this?
Use my [CP/M libaries](https://github.com/ProgrammingCube/CPM_Aztec_C_Libraries) as well as Aztec C 1.06D. The build command is:
```
cc rogue
as rogue
cc player
as player
cc monster
as monster
cc engine
as engine
cc map
as map
cc draw
as draw
cc -E500 room
as room
cc monster
as monster
ln rogue.o player.o monster.o engine.o map.o draw.o room.o -lcurses -lcpm -lm -lc -o rogue.com
```
I know Aztec C will eventually reach a library limit, so I need to figure that out...later...
