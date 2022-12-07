# smart-pointers

![C++](https://img.shields.io/badge/C%2B%2B-17-blue)
![GitHub repo size](https://img.shields.io/github/repo-size/AgnesePortera/smart-pointers)
![GitHub](https://img.shields.io/github/license/AgnesePortera/smart-pointers?style=plastic)
![GitHub](https://img.shields.io/github/last-commit/AgnesePortera/smart-pointers)

C++ provides absolute flexibility with memory management, including allocation, deallocation etc.
There are some potentially problems related to uninitialized pointers, memory leaks, dangling pointers or exception safety, because there is no owner of a pointer.

Smart pointers can help. They can only point to heap allocated memory, they are automatically deleted when no more used and also they apply the RAII.
