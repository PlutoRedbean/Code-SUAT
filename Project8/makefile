CC = g++
CCFLAGS = -g -w
CCLIBS = -lncurses
mygame: main.o Gui.o Game.o Item.o Player.o Bullet.o Tank.o RemovableItem.o EnemyTank.o Mine.o Medpack.o
	$(CC) $(CCFLAGS) -o mygame main.o Gui.o Game.o Item.o Player.o Bullet.o Tank.o RemovableItem.o EnemyTank.o Mine.o Medpack.o $(CCLIBS)

Gui.o: Gui.h Gui.C
	$(CC) $(CCFLAGS) -c -o Gui.o Gui.C

Game.o: Game.h Game.C
	$(CC) $(CCFLAGS) -c -o Game.o Game.C

Mine.o: Mine.C
	$(CC) $(CCFLAGS) -c -o Mine.o Mine.C

Medpack.o: Medpack.C
	$(CC) $(CCFLAGS) -c -o Medpack.o Medpack.C

main.o: main.C
	$(CC) $(CCFLAGS) -c -o main.o main.C

Item.o: Item.C Item.h
	$(CC) $(CCFLAGS) -c -o Item.o Item.C

Bullet.o: Bullet.h Bullet.C
	$(CC) $(CCFLAGS) -c -o Bullet.o Bullet.C

Player.o: Player.h Player.C
	$(CC) $(CCFLAGS) -c -o Player.o Player.C

Tank.o: Tank.h Tank.C
	$(CC) $(CCFLAGS) -c -o Tank.o Tank.C

RemovableItem.o: RemovableItem.h RemovableItem.C
	$(CC) $(CCFLAGS) -c -o RemovableItem.o RemovableItem.C

EnemyTank.o: EnemyTank.h EnemyTank.C
	$(CC) $(CCFLAGS) -c -o EnemyTank.o EnemyTank.C

clean:
	rm -rf mygame *.o
