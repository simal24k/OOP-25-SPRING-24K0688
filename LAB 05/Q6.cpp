#include <iostream>
using namespace std;

class RenderSystem {
public:
    void drawStuff() const {
        cout << "Drawing game visuals..." << endl;
    }
};

class ControlManager {
public:
    void handleControls() const {
        cout << "Handling player controls..." << endl;
    }
};

class MotionCalculator {
public:
    void calcMotion() const {
        cout << "Calculating game motion..." << endl;
    }
};

class GamingCore {
    RenderSystem visuals;    
    ControlManager controls; 
    MotionCalculator motion; 
public:
    void startGame() const {
        cout << "Starting the gaming core!" << endl;
        controls.handleControls();
        motion.calcMotion();
        visuals.drawStuff();
        cout << "Game running smooth!" << endl;
    }
};

int main() {
    GamingCore myGame;
    myGame.startGame();

    return 0;
}
