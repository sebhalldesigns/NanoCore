#include "NObject.h"

// compile-time class definition example

const Class SubClass = &(ClassDef) {
    .Name = "SubClass",
    .Base = NObject
};




int main() {
    
    // runtime class registration example 

    ClassDef MyClass_Def = {
        .Name = "MyClass",
        .Base = SubClass
    };

    Class MyClass = Class_Register(MyClass_Def);

    return 0;
}