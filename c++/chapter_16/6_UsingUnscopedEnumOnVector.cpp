#include <vector>
#include <iostream>

namespace Students
{
    enum Names
    {
        kenny,       // 0
        kyle,        // 1
        stan,        // 2
        butters,     // 3
        cartman,     // 4
        max_students // 5
    };
}

int main(){
   std::vector testscores{10, 20, 30, 40, 50};
   
   testscores[Students::kenny] = 100;
    testscores[Students::kyle] = 90;
    testscores[Students::stan] = 80;
    testscores[Students::butters] = 70;
    testscores[Students::cartman] = 60;
    // Print the test scores
    for(const auto &score : testscores){
        std::cout << score << " ";
    }
    std::cout << std::endl;

}