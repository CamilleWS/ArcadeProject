//
// EPITECH PROJECT, 2019
// Arcade
// File description:
// src
//

#include "../include/interface.hpp"

template<>
IGameModule *DLLoader<IGameModule>::getInstance(const std::string &path) {
    static int i = 0;
    const std::string comp(".so");
    if (path.find(comp) == std::string::npos) {
        print_usage();
        exit(84);
    }
    void *handle = dlopen(path.c_str(), RTLD_LAZY);

    if (!handle) {
        std::cout << dlerror() << std::endl;
        print_usage();
        exit(84);
    }
    if (!dlsym(handle, "gamecheck") && i%2==0) {
        print_usage();
        i++;
    }
    


    IGameModule *(*entryPoint)(void);
    void *fptr = dlsym(handle, "entryPoint");

    entryPoint = (IGameModule *(*)())fptr;
    if (!entryPoint) {
        return NULL;
    }
    IGameModule *instance = entryPoint();
    instance->init();
    instance->setHandle(handle);
    instance->setName(pathToName(path));
    return (instance);
}

template<>
IDisplayModule *DLLoader<IDisplayModule>::getInstance(const std::string &path) {
    const std::string comp(".so");
    if (path.find(comp) == std::string::npos) {
        print_usage();
        exit(84);
    }
    void *handle = dlopen(path.c_str(), RTLD_LAZY);

    if (!handle) {
        std::cout << dlerror() << std::endl;
        exit(84);
    }

    if (!dlsym(handle, "libcheck")) {
        print_usage();
        exit (84);
    }

    IDisplayModule *(*entryPoint)(void);
    void *fptr = dlsym(handle, "entryPoint");

    entryPoint = (IDisplayModule *(*)())fptr;
    if (!entryPoint) {
        return NULL;
    }
    IDisplayModule *instance = entryPoint();
    instance->init();
    instance->setHandle(handle);
    instance->setName(pathToName(path));
    return (instance);
}
