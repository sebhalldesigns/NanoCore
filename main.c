#include "NObject.h"

// compile-time class definition example

const Class SubClass = &(ClassDef) {
    .Name = "SubClass",
    .Base = NObject
};

Object subClassObject = &(ObjectDef) {
    .Class = SubClass,
    .Fields = (Field[]) {
        { .Parameter = NObject_Name, .Value.String = "SubClass" }
    }
};


int main() {
    
    // runtime class registration example 

    ClassDef MyClass_Def = {
        .Name = "MyClass",
        .Base = SubClass
    };

    Class MyClass = Class_Register(MyClass_Def);

    Object myObject = Object_New(MyClass);

    printf("myObject->Class->Name: %s\n", subClassObject->Class->Name);
    printf("myObject->Fields[0].Parameter->Name: %s\n", NObject_Name->Name);

    return 0;
}

