#include "Game.h"

// Render loop
void Game::render() {
    
    for (auto i = 0; i < objects.size(); ++i){
        objects[i].render(); 
    } 

    
}
