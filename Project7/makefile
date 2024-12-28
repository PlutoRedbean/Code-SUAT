CC = g++
CCFLAGS = -g -w 
CCLIBS = -lncurses
mygame: main.o Gui.o Game.o Player.o Bullet.o Tank.o Bomb.o Item.o
	$(CC) $(CCFLAGS) -o mygame main.o Gui.o Game.o Player.o Bullet.o Tank.o Bomb.o Item.o $(CCLIBS)

Gui.o: Gui.h Gui.C
	$(CC) $(CCFLAGS) -c -o Gui.o Gui.C

Game.o: Game.h Game.C
	$(CC) $(CCFLAGS) -c -o Game.o Game.C

main.o: main.C
	$(CC) $(CCFLAGS) -c -o main.o main.C

Item.o: Item.h Item.C
	$(CC) $(CCFLAGS) -c -o Item.o Item.C

Bullet.o: Bullet.h Bullet.C
	$(CC) $(CCFLAGS) -c -o Bullet.o Bullet.C

Player.o: Player.h Player.C
	$(CC) $(CCFLAGS) -c -o Player.o Player.C

Tank.o: Tank.h Tank.C
	$(CC) $(CCFLAGS) -c -o Tank.o Tank.C

Bomb.o: Bomb.h Bomb.C
	$(CC) $(CCFLAGS) -c -o Bomb.o Bomb.C

clean:
	rm -rf mygame *.o
