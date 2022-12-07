# Smart Pointers

![C++](https://img.shields.io/badge/C%2B%2B-17-blue)
![GitHub repo size](https://img.shields.io/github/repo-size/AgnesePortera/smart-pointers)
![GitHub](https://img.shields.io/github/license/AgnesePortera/smart-pointers?style=plastic)
![GitHub](https://img.shields.io/github/last-commit/AgnesePortera/smart-pointers)

C++ provides absolute flexibility with memory management, including allocation, deallocation etc.

There are some potentially problems related to uninitialized pointers, memory leaks, dangling pointers or exception safety, because there is no owner of a pointer.

Smart pointers can help. They can only point to heap allocated memory, they are automatically deleted when no more used and also they apply the RAII (Resource Acquisition Is Initialization).
There are different types of smart pointers:
* unique pointers (`unique_ptr`)
* shared pointers (`shared_ptr`)
* weak pointers (`weak_ptr`)

Add always `#include <memory>` for using them.

Smart pointers are defined by class templates, wrapped around a raw pointer. There are overloaded operators:
* deference (\*)
* member selection (->)
* pointer arithmetic not supported (+,- etc.)

Also custom deleters are included.

## Unique pointers
`unique_ptr<T>`:
* points to an object of type T on the heap
* it is unique for an object on the heap
* owns what it points to
* can be assigned but not copied
* can be moved
* when the pointer is destroyed, what is point is automatically destroyed

Useful methods: `get()`, `reset()`, `make_unique<T>(init_value)`

## Shared Pointers
`shared_ptr<T>`
* Points to an object of type T on the heap
* It is not unique, there can many shared_ptr pointing to the same object on the heap
* Establishes shared ownership 
* Can be assigned and copied
* Can be moved
* When the use count is zero, the managed object is destroyed

Useful methods: `use_count()`, `make_shared\<T>(init_value)`

## Weak Pointers
`weak_ptr<T>`
* Points to an object of type T on the heap
* Does not partecipate in owning relationship
* Always created from a shared_ptr
* Does NOT increment or decrement reference to use_count
* Used to prevent strong reference cycles which could prevent objects from being deleted

