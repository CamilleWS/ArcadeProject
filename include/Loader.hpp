/*
** EPITECH PROJECT, 2017
** main
** File description:
** main
*/


#ifndef _Loader_HPP_
#define _Loader_HPP_

template<typename T>
class DLLoader {
	public:
    	DLLoader() {}
    	~DLLoader() {}

    	T *getInstance(const std::string &path) {
        	void * handle = dlopen(path.c_str(), RTLD_LAZY);

        	if (!handle) {
            	std::cout << dlerror() << std::endl;
            	exit(84);
        	}
        	T *(*entryPoint)(void);
        	void *fptr = dlsym(handle, "entryPoint");

        	entryPoint = (T *(*)())fptr;
        	T *instance = entryPoint();
        	instance->init();
        	instance->setHandle(handle);
        	instance->setName(pathToName(path));
        	return (instance);
    	}

    	int destroyInstance(T *instance) {
        	instance->stop();
        	return (dlclose(instance->getHandle()));

    	}
    	std::string pathToName(const std::string &path)
    	{
        	std::string name = path;

        	if (path.find("SFML") != std::string::npos) {
            	name = "SFML";
        	}
        	if (path.find("NCURSE") != std::string::npos) {
            	name = "NCURSE";
        	}
        	if (path.find("ALLEGRO") != std::string::npos) {
            	name = "ALLEGRO";
        	}
        	if (path.find("NIBBLER") != std::string::npos) {
            	name = "NIBBLER";
        	}
        	if (path.find("SOLARFOX") != std::string::npos) {
            	name = "SOLARFOX";
        	}
        	return (name);
    	}
	private:
};

#endif

