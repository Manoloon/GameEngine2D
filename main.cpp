#include "GESource/Game.h"
#include "GESource/GameEngine.h"

int main()
{
    //Game g("Config.txt");
    GameEngine g("Config.txt");
    g.run();
}
