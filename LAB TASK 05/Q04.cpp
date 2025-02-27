#include <iostream>
#include <unistd.h> 

using namespace std;

class Blend {
public:
    void blendJuice() {
        cout << "Blending Juice...\n";
        for (int i = 0; i < 5; i++) {
            cout << "Blending... " << (i + 1) << " sec\n";
            sleep(1);
        }
        cout << "Blending Complete!\n";
    }
};

class Grind {
public:
    void grindJuice() {
        cout << "Grinding Juice...\n";
        sleep(5);
        cout << "Grinding Complete!\n";
    }
};

class JuiceMaker {
    Blend blender;
    Grind grinder;
public:
    void makeJuice() {
        cout << "Selecting Fruits for Juice...\n";
        blender.blendJuice();
        grinder.grindJuice();
        cout << "Your Juice is Ready!\n";
    }
};

int main() {
    JuiceMaker myJuicer;
    myJuicer.makeJuice();
    return 0;
}
