#ifndef ENGINE_H
#define ENGINE_H
#include <chrono>


class Engine {
    public:
    void run();
    Engine();

    private:
    bool running;
};

#endif //ENGINE_H