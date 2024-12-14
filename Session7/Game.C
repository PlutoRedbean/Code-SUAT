#include "Game.h"
#include "Player.h"
#include "Bullet.h"

Game::Game() {
    gui.init();
    pl = new Player(this);
}

void Game::addBullet(size_t r, size_t c){
    bullets.push_back(new Bullet(this, r, c));
}

void Game::update(){
    gui.clear();
    int c = gui.get();
    pl->update(c);
    list<Bullet*>::iterator bi = bullets.begin();
    while(bi != bullets.end()){
        (*bi)->update();
        if ((*bi)->out() == true) {
            delete *bi;
            bi = bullets.erase(bi);
        }
        bi++;
    }
}