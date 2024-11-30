#ifndef NOBJECT_H
#define NOBJECT_H

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

typedef struct ClassDef* Class;

typedef struct ClassDef {
    const char* Name;
    Class Base;
} ClassDef;

const Class NObject = &(ClassDef) {
    .Name = "NObject",
    .Base = NULL
};


Class Class_Register(ClassDef classDef)
{   
    if (!classDef.Name) {
        fprintf(stderr, "ClassDef must have a name\n");
        exit(EXIT_FAILURE);
    }

    if (!classDef.Base) {
        printf("Registering base class %s\n", classDef.Name);
    } 
    else 
    {
        printf("Registering class %s with base class %s\n", classDef.Name, classDef.Base->Name);
    }

    ClassDef *classDefPtr = (ClassDef*)malloc(sizeof(ClassDef));
    *classDefPtr = classDef;
    return classDefPtr;
}

#endif // NOBJECT_H