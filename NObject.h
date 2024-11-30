#ifndef NOBJECT_H
#define NOBJECT_H

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct ClassDef* Class;
typedef struct ParameterDef* Parameter;
typedef struct ObjectDef* Object;


typedef union {
    uintptr_t Value;
    uint8_t UInt8;
    uint16_t UInt16;
    uint32_t UInt32;
    uint64_t UInt64;
    int8_t Int8;
    int16_t Int16;
    int32_t Int32;
    int64_t Int64;
    float Float;
    double Double;
    bool Bool;
    const char* String;
} Value;


typedef struct ParameterDef {
    const char* Name;
    Class Type;
} ParameterDef;

typedef struct Field {
    Parameter Parameter;
    Value Value;
} Field;

typedef enum 
{
    CLASS_TYPE_OBJECT,
    CLASS_TYPE_UINT8,
    CLASS_TYPE_UINT16,
    CLASS_TYPE_UINT32,
    CLASS_TYPE_UINT64,
    CLASS_TYPE_INT8,
    CLASS_TYPE_INT16,
    CLASS_TYPE_INT32,
    CLASS_TYPE_INT64,
    CLASS_TYPE_FLOAT,
    CLASS_TYPE_DOUBLE,
    CLASS_TYPE_BOOL,
    CLASS_TYPE_STRING
} ClassType;




typedef struct ClassDef {
    const char* Name;
    ClassType Type;
    Class Base;
    Parameter* Parameters;
    size_t ParameterCount;
} ClassDef;




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






typedef struct ObjectDef {
    Class Class;
    Field* Fields;
    size_t FieldCount;
} ObjectDef;

Object Object_New(Class class)
{
    if (!class) {
        fprintf(stderr, "Object must have a class\n");
        exit(EXIT_FAILURE);
    }

    ObjectDef *object = (ObjectDef*)malloc(sizeof(ObjectDef));
    object->Class = class;

    printf("Creating object of class %s\n", class->Name);

    return object;
}


const Class System_UInt8 = &(ClassDef) {
    .Name = "System_UInt8",
    .Type = CLASS_TYPE_UINT8,
};

const Class System_String = &(ClassDef) {
    .Name = "System_String",
    .Type = CLASS_TYPE_STRING,
};

const Parameter NObject_Name = &(ParameterDef) {
    .Name = "Name",
    .Type = System_String
};

const Class NObject = &(ClassDef) {
    .Name = "NObject",
    .Base = NULL,
    .Parameters = (Parameter[]) {
        NObject_Name,
    },
    .ParameterCount = 1
};

#endif // NOBJECT_H