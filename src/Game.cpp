#include "Game.h"

// Render loop
void Game::render() {
    for (auto i = 0; i < objects.size(); ++i) {
        Object* object = objects[i];
        object->render();
        tournestp = tournestp +0.005;
    }
    objects[1]->tx = -cos(tournestp)*14 ;
    objects[1]->ty = sin(tournestp)*12 -10;
    objects[1]->tz = sin(tournestp)*9 -60;

    objects[2]->tx = -cos(tournestp-0.5)*16 ;
    objects[2]->ty = -sin(tournestp-0.5)*12 -10;
    objects[2]->tz = sin(tournestp-0.5)*9 -60;


    
   
}
