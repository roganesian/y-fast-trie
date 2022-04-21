#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <stack>
#include <map>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>


class State {
private:

protected:
    std::stack<State*> *states;
    sf::RenderWindow *window;
    std::map<std::string, int> *valid_keys;
    std::map<std::string, int> key_binds;
    bool exit;
    bool is_in_console;
    float key_timer;
    float key_timer_max;

    sf::Vector2i mouse_pos_screen;
    sf::Vector2i mouse_pos_window;
    sf::Vector2f mouse_pos_view;
    
    // Resources
    //std::map<std::string, sf::Texture> textures;

    // Functions
    virtual void initKeyBinds() = 0;

public:
    State(sf::RenderWindow *window, std::map<std::string, int> *valid_keys, std::stack<State*> *states);
    virtual ~State();

    const bool &getExit() const;
    const bool getKeyTimer();

    void exitState();
    void inConsoleState();
    void outConsoleState();

    virtual void updateMousePositions();
    virtual void updateKeyTime(const float &dt);
    virtual void updateInput(const float &dt) = 0;
    virtual void update(const float &dt) = 0;
    virtual void render(sf::RenderTarget *target = nullptr) = 0;
};