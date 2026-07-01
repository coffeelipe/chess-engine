#include "app_events.hpp"
#include "sdl_fwd.hpp"

class SDLManager
{
public:
    bool init();
    SDL_Window *getWindow();
    SDL_Renderer *getRenderer();
    void clear();

    bool waitEvent(AppEvent &event);

private:
    void mapEventType(const SDL_Event& sdlEvent, AppEvent& event);

    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;
};
