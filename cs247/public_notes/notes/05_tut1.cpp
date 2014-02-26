// Static v.s. Const variables:
//
// Static and constant variables cannot be modified, but in different scopes. Static -> different in all children. Constant -> in all instances.
// 
// Polymorphism:
// 
// i.e: "overrides", or "operator overloading"

class Pet {
    //The Pet class has the feed method, which is virtual:
    //By being virtual, we are able to prevent 
    virtual void feed();
}

class Goldfish : public Dog {
    // In the goldfish class, we re-implement the feed method. This is called with higher priority than parent.feed();
    static void feed();
}

void move(Pet p) {
    /* code goes here */
}
//Object slicing:
int main() {
    // When youc all move with goldfish as an element, it drops the identification, and is treated as a pet
    Goldfish g = new Goldfish();
    move(g);
}
