#include "Header.h"


int main() {
    MakeUp * nudeMakeup = new Nude;
    cout << nudeMakeup->getDescription() << " " << nudeMakeup->cost() << "$" << endl;
    nudeMakeup = new Glitter(nudeMakeup);
    cout << nudeMakeup->getDescription() << " " << nudeMakeup->cost() << "$" << endl;
    
    cout << endl;
    MakeUp *shiningMakeup = new Shining;
    cout << shiningMakeup->getDescription() << " " << shiningMakeup->cost() << "$" << endl;
    shiningMakeup = new BrigthLipstick(shiningMakeup);
    shiningMakeup = new Baking(shiningMakeup);
    cout << shiningMakeup->getDescription() << " " << shiningMakeup->cost() << "$" << endl;
    return 0;
}
