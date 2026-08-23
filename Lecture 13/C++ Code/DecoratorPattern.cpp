// Decorator Pattern in C++

#include <iostream>
#include <string>

using namespace std;

// Component Interface: defines a common interface for Mario and all power-up decorators.
class Character {
public:
    virtual string getAbilities() const = 0;
    virtual ~Character() {}  // Virtual destructor
};

// Concrete Component: Basic Mario character with no power-ups.
class Mario : public Character {
public:
    string getAbilities() const override {
        return "Mario";
    }
};

// Abstract Decorator: CharacterDecorator "is-a" Charatcer and "has-a" Character.
class CharacterDecorator : public Character {
protected:
    Character* character;  // Wrapped component
public:
    CharacterDecorator(Character* c){
        this->character = c;
    }
};

// Concrete Decorator: Height-Increasing Power-Up.
class HeightUp : public CharacterDecorator {
public:
    HeightUp(Character* c) : CharacterDecorator(c) { }

    string getAbilities() const override {
        return character->getAbilities() + " with HeightUp";
    }
};

// Concrete Decorator: Gun Shooting Power-Up.
class GunPowerUp : public CharacterDecorator {
public:
    GunPowerUp(Character* c) : CharacterDecorator(c) { }
    
    string getAbilities() const override {
        return character->getAbilities() + " with Gun";
    }
};

// Concrete Decorator: Star Power-Up (temporary ability).
class StarPowerUp : public CharacterDecorator {
public:
    StarPowerUp(Character* c) : CharacterDecorator(c) { }
    
    string getAbilities() const override {
        return character->getAbilities() + " with Star Power (Limited Time)";
    }
    
    ~StarPowerUp() {
        cout << "Destroying StarPowerUp Decorator" << endl;
    }
};

int main() {
    // Create a basic Mario character.
    Character* mario = new Mario();
    cout << "Basic Character: " << mario->getAbilities() << endl;

    // Decorate Mario with a HeightUp power-up.
    mario = new HeightUp(mario);
    cout << "After HeightUp: " << mario->getAbilities() << endl;

    // Decorate Mario further with a GunPowerUp.
    mario = new GunPowerUp(mario);
    cout << "After GunPowerUp: " << mario->getAbilities() << endl;

    // Finally, add a StarPowerUp decoration.
    mario = new StarPowerUp(mario);
    cout << "After StarPowerUp: " << mario->getAbilities() << endl;

    delete mario;

    return 0;
}




//Coffee example of decorator pattern
#include <iostream>
#include <string>

using namespace std;

class Icoffee{
    public:
    virtual string getCoffee() = 0;
};

class coffee: public Icoffee{
    public:
    string getCoffee(){
        return "Serve coffee ";
    }
};

//now i've to option, ki hr trh ki combination wali coffee ke liey alg alg class bnao using inheritance jo ki bhot hi class ho jaengi, which can acuse class exposion.
//2nd hm decorator pattern ka use kr skte h --- isme hm ek decortor class bnaenge jinme alg alg trh ke options ki class milk, chocolate, sugar etc options honge user ko jis combination ki coffee chahiye hogi user un class ko wrap krke pass kr dega aur uske combination ki coffee usey mil jaegi.

class coffeeDecorator: public Icoffee{
    public:
    Icoffee* c;
    coffeeDecorator(Icoffee* c){
        this->c=c;
    }
};

class milk : public coffeeDecorator{
    public:
    milk(Icoffee* c) : coffeeDecorator(c){ }
    string getCoffee(){
        return c->getCoffee() + "with milk ";
    }
};

class chocolate : public coffeeDecorator{
    public:
    chocolate(Icoffee* c) : coffeeDecorator(c){}

    string getCoffee(){
        return c->getCoffee() + "with chocolate ";
    }
};

int main(){
    Icoffee *c = new coffee();
    cout<<c->getCoffee()<<endl;

    c = new milk(c);
    cout<<c->getCoffee()<<endl;

    c = new chocolate(c);
    cout<<c->getCoffee()<<endl;
}


