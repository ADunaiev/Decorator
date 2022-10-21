#include<iostream>


class Component {
public:
    virtual ~Component() {}
    virtual std::string Operation() const = 0;
};

class ConcreteComponent : public Component {
public:
    std::string Operation() const override {
        return "ConcreteComponent";
    }
};

class Decorator : public Component {
protected:
    Component* component_;

public:
    Decorator(Component* component) : component_(component) {
    }

    std::string Operation() const override {
        return this->component_->Operation();
    }
};

class DecoratorStar : public Decorator {

public:
    DecoratorStar(Component* component) : Decorator(component) {
    }
    std::string Operation() const override {
        return "***** " + Decorator::Operation() + " *****";
    }
};

class DecoratorSlash : public Decorator {
public:
    DecoratorSlash(Component* component) : Decorator(component) {
    }

    std::string Operation() const override {
        return "//// " + Decorator::Operation() + " /////";
    }
};


class DecoratorLines : public Decorator {
public:
    DecoratorLines(Component* component) : Decorator(component) {
    }

    std::string Operation() const override {


        return "\n--------------------------------------------\n" + 
                Decorator::Operation() + 
               "\n--------------------------------------------\n";
    }
};

class DecoratorWaves : public Decorator {
public:
    DecoratorWaves(Component* component) : Decorator(component) {
    }

    std::string Operation() const override {


        return "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" +
            Decorator::Operation() +
               "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    }
};

void ClientCode(Component* component) {

    std::cout << "RESULT: " << component->Operation();

}

int main() {

    Component* simple = new ConcreteComponent;
    std::cout << "Client: I've got a simple component:\n";
    ClientCode(simple);
    std::cout << "\n\n";

    Component* decorator1 = new DecoratorStar(simple);
    Component* decorator2 = new DecoratorSlash(decorator1);
    Component* decorator3 = new DecoratorLines(decorator2);
    Component* decorator4 = new DecoratorWaves(decorator3);
    std::cout << "Client: Now I've got a decorated component:\n";
    ClientCode(decorator4);
    std::cout << "\n";

    delete simple;
    delete decorator1;
    delete decorator2;
    delete decorator3;
    delete decorator4;

    return 0;
}