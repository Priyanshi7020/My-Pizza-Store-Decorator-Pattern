#include <iostream>
#include <string>
using namespace std;
// Common super class interface for pizza
class Pizza {
public:
    string description = "Unknown Pizza";
    virtual string getDescription() {
        return description;
    }
    virtual double cost() = 0;
    virtual ~Pizza() = default;
};

// Concrete pizza classes
class ThickCrustPizza : public Pizza {
public:
    ThickCrustPizza() {
        description = "Thick Crust Pizza";
    }

    double cost() override {
        return 10.99;
    }
};

class ThinCrustPizza : public Pizza {
public:
    ThinCrustPizza() {
        description = "Thin Crust Pizza";
    }

    double cost() override {
        return 9.99;
    }
};

// Decorators or toppings
class ToppingDecorator : public Pizza {
protected:
    Pizza* pizza;

public:
    explicit ToppingDecorator(Pizza* pizza) : pizza(pizza) {}

    string getDescription() override {
        return pizza->getDescription();
    }

    double cost() override {
        return pizza->cost();
    }

    virtual ~ToppingDecorator() override {
        delete pizza;
    }
};

// Concrete classes for pizza toppings
class Cheese : public ToppingDecorator {
public:
     Cheese(Pizza* pizza) : ToppingDecorator(pizza) {}

    string getDescription() override {
        return pizza->getDescription() + ", Cheese";
    }

    double cost() override {
        return pizza->cost() + 1.50;
    }
};

class Olives : public ToppingDecorator {
public:
    Olives(Pizza* pizza) : ToppingDecorator(pizza) {}

    string getDescription() override {
        return pizza->getDescription() + ", Olives";
    }

    double cost() override {
        return pizza->cost() + 2.00;
    }
};

class Peppers : public ToppingDecorator {
public:
    Peppers(Pizza* pizza) : ToppingDecorator(pizza) {}

    string getDescription() override {
        return pizza->getDescription() + ", Peppers";
    }

    double cost() override {
        return pizza->cost() + 1.75;
    }
};

int main() {
    // Example usage
    Pizza* pizza = new ThickCrustPizza();
    cout << "Description: " << pizza->getDescription() << "\n";
    cout << "Cost: $" << pizza->cost() << "\n";

    // Adding toppings
    pizza = new Cheese(pizza);
    pizza = new Olives(pizza);

    cout << "Description: " << pizza->getDescription() << "\n";
    cout << "Cost: $" << pizza->cost() << "\n";

    delete pizza;  // Clean up memory

    return 0;
}
