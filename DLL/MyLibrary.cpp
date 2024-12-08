#include "pch.h"
#include "MyLibrary.h"
#include <vector>
#include <string>
#include <iostream>

struct Object {
    int id;
    std::string name;
};

static std::vector<Object> objects;

extern "C" {

    
    MYLIBRARY_API void CreateObject(int id, const char* name) {
        objects.push_back({ id, name });
        std::cout << "Object created: ID = " << id << ", Name = " << name << std::endl;
    }

    
    MYLIBRARY_API bool EditObject(int id, const char* newName) {
        for (auto& obj : objects) {
            if (obj.id == id) {
                obj.name = newName;
                std::cout << "Object edited: ID = " << id << ", New Name = " << newName << std::endl;
                return true;
            }
        }
        return false;
    }

    
    MYLIBRARY_API const char* GetObjectFields(int id) {
        for (const auto& obj : objects) {
            if (obj.id == id) {
                return obj.name.c_str();
            }
        }
        return "Object not found";
    }

   
    MYLIBRARY_API bool DeleteMyObject(int id) {
        for (auto it = objects.begin(); it != objects.end(); ++it) {
            if (it->id == id) {
                objects.erase(it);
                std::cout << "Object deleted: ID = " << id << std::endl;
                return true;
            }
        }
        return false;
    }

    
    MYLIBRARY_API void ListAllObjects() {
        std::cout << "Object List:" << std::endl;
        for (const auto& obj : objects) {
            std::cout << "ID: " << obj.id << ", Name: " << obj.name << std::endl;
        }
    }
}
