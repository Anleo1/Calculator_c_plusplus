#define BUILDING_PLUGIN
#include "Function.h"
#include <cmath>
#include <string>

class Sin : public Function {
public:
    std::string getName() const override {
        return "sin";
    }
    
    double evaluate(double argument) const override {
        return std::sin(argument);
    }
};

extern "C" {
    PLUGIN_API Function* createFunction() {
        return new Sin();
    }
    
    PLUGIN_API void destroyFunction(Function* function) {
        delete function;
    }
}
