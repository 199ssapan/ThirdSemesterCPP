#include <iostream>
#include <vector>
#include "Rat.hpp"
#include "Tree.hpp"
#include "Bird.hpp"

int main() {
    
    std::vector<Object*> objects = std::vector<Object*>();
    Tree* tree = (Tree*) new Tree();
    Rat* rat = (Rat*) new Rat();
    Bird* bird = (Bird*) new Bird();
    objects.push_back((Object*)tree);
    objects.push_back((Object*)rat);
    objects.push_back((Object*)bird);
    for (int i = 0; i < 3; i++)
    {
        objects[i]->Do();
        objects[i]->Draw();
    }
    return 0;
}