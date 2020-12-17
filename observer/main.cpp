#include "file.hpp"


int main(int argc, const char * argv[]) {
    Man Andrey;
    FunnyCats FC(5);
    FunnyDogs FD(1);
    Andrey.display();
    Andrey.subscribe(&FC);
    Andrey.subscribe(&FD);
    Andrey.display();
    FC.addPost();
    FD.addPost();
    Andrey.display();
    
    Woman Alice;
    Alice.subscribe(&FC);
    FC.addPost();
    Alice.display();
    Andrey.display();
    return 0;
}
