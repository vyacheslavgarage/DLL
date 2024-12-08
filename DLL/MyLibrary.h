#pragma once

#ifdef MYLIBRARY_EXPORTS
#define MYLIBRARY_API __declspec(dllexport)
#else
#define MYLIBRARY_API __declspec(dllimport)
#endif

extern "C" {
    MYLIBRARY_API void CreateObject(int id, const char* name);
    MYLIBRARY_API bool EditObject(int id, const char* newName);
    MYLIBRARY_API const char* GetObjectFields(int id);
    MYLIBRARY_API bool DeleteMyObject(int id);
    MYLIBRARY_API void ListAllObjects();
}
