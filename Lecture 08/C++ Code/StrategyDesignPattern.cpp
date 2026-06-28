#include <iostream>
using namespace std;

// --- Strategy Interface for Walk ---
class WalkableRobot {
public:
    virtual void walk() = 0;
    virtual ~WalkableRobot() {}
};

// --- Concrete Strategies for walk ---
class NormalWalk : public WalkableRobot {
public:
    void walk() override { 
        cout << "Walking normally..." << endl; 
    }
};

class NoWalk : public WalkableRobot {
public:
    void walk() override { 
        cout << "Cannot walk." << endl; 
    }
};


// --- Strategy Interface for Talk ---
class TalkableRobot {
public:
    virtual void talk() = 0;
    virtual ~TalkableRobot() {}
};

// --- Concrete Strategies for Talk ---
class NormalTalk : public TalkableRobot {
public:
    void talk() override { 
        cout << "Talking normally..." << endl; 
    }
};

class NoTalk : public TalkableRobot {
public:
    void talk() override { 
        cout << "Cannot talk." << endl; 
    }
};

// --- Strategy Interface for Fly ---
class FlyableRobot {
public:
    virtual void fly() = 0;
    virtual ~FlyableRobot() {}
};

class NormalFly : public FlyableRobot {
public:
    void fly() override { 
        cout << "Flying normally..." << endl; 
    }
};

class NoFly : public FlyableRobot {
public:
    void fly() override { 
        cout << "Cannot fly." << endl; 
    }
};

// --- Robot Base Class ---
class Robot {
protected:
    WalkableRobot* walkBehavior;
    TalkableRobot* talkBehavior;
    FlyableRobot* flyBehavior;

public:
    Robot(WalkableRobot* w, TalkableRobot* t, FlyableRobot* f) {
        this->walkBehavior = w;
        this->talkBehavior = t;
        this->flyBehavior = f;
    }
       
    void walk() { 
        walkBehavior->walk(); 
    }
    void talk() { 
        talkBehavior->talk(); 
    }
    void fly() { 
        flyBehavior->fly(); 
    }

    virtual void projection() = 0; // Abstract method for subclasses
};

// --- Concrete Robot Types ---
class CompanionRobot : public Robot {
public:
    CompanionRobot(WalkableRobot* w, TalkableRobot* t, FlyableRobot* f)
        : Robot(w, t, f) {}

    void projection() override {
        cout << "Displaying friendly companion features..." << endl;
    }
};

class WorkerRobot : public Robot {
public:
    WorkerRobot(WalkableRobot* w, TalkableRobot* t, FlyableRobot* f)
        : Robot(w, t, f) {}

    void projection() override {
        cout << "Displaying worker efficiency stats..." << endl;
    }
};

// --- Main Function ---
int main() {
    cout << "Robot 1's Behaviour" << endl;
    Robot *robot1 = new CompanionRobot(new NormalWalk(), new NormalTalk(), new NoFly());
    robot1->walk();
    robot1->talk();
    robot1->fly();
    robot1->projection();
    
    cout << "--------------------" << endl;
    cout << "Robot 2's Behaviour" << endl;

    Robot *robot2 = new WorkerRobot(new NoWalk(), new NoTalk(), new NormalFly());
    robot2->walk();
    robot2->talk();
    robot2->fly();
    robot2->projection();

    return 0;
}




// #include<iostream>
// using namespace std;

// //Base Class of walk
// class walkable{
//     public:
//     virtual void walk()=0;
// };
// //concrete class of Walkable
// class noWalk : public walkable{
//     public:
//     void walk(){
//         cout<<" Cant walk";
//     }
// };
// class normalWalk : public walkable{
//     public:
//     void walk(){
//         cout<<" Can walk";
//     }
// };

// //Base Class of talk
// class talkable{
//     public:
//     virtual void talk()=0;
// };
// //concrete class of talkable
// class noTalk : public talkable{
//     public:
//     void talk(){
//         cout<<" Cant talk";
//     }
// };
// class normalTalk : public talkable{
//     public:
//     void talk(){
//         cout<<" Can talk";
//     }
// };


// //Base Class of fly
// class flyable{
//     public:
//     virtual void fly()=0;
// };
// //concrete class of Walkable
// class noFly : public flyable{
//     public:
//     void fly(){
//         cout<<" Cant fly";
//     }
// };
// class normalFly : public flyable{
//     public:
//     void fly(){
//         cout<<" Can fly";
//     }
// };

// class Robot{
//     public:
//     walkable* w;
//     talkable* t;
//     flyable* f;
//     Robot(walkable* w,talkable* t, flyable* f){
//         this->f=f;
//         f->fly();
//         this->t=t;
//         t->talk();
//         this->w=w;
//         w->walk();
//     }
//     // void walk(){
//     //     w->walk();
//     // }
//     // void talk(){
//     //     t->talk();
//     // }
//     // void fly(){
//     //     f->fly();
//     // }
// };
// int main(){
//     Robot* r = new Robot(new normalWalk(),new normalTalk(), new normalFly());
//     return 0;
// }