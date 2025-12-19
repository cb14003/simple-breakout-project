#ifndef GAME_H
#define GAME_H

#include <cstddef>

constexpr char VOID = ' ';
constexpr char WALL = '#';
constexpr char BLOCKS = '@';
constexpr char PADDLE = 'P';
constexpr char BOUNDARY = '!';
constexpr char BALL = '*';

struct level {
    size_t rows = 0, columns = 0;
    char* data = nullptr;
};

enum game_state {
    menu_state,
    level_select_state,
    in_game_state,
    paused_state,
    victory_state
};

inline float victory_timer = 0.0f;
inline float victory_animation_angle = 0.0f;

inline char level_1_data[] = {
    '#', '#', '#', '#', '#', '#', '#', '#', '#',
    '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#',
    '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#',
    '#', ' ', '@', '@', '@', '@', '@', ' ', '#',
    '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#',
    '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#',
    '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#',
    '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#',
    '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#',
    '#', ' ', ' ', ' ', '*', ' ', ' ', ' ', '#',
    '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#',
    '#', ' ', ' ', 'P', ' ', ' ', ' ', ' ', '#',
    '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'
};
inline level level_1 = {
    13, 9,
    level_1_data
};

inline char level_2_data[] = {
    '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#',
    '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#',
    '#', ' ', '@', ' ', ' ', ' ', '@', ' ', ' ', ' ', '@', ' ', '#',
    '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#',
    '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#',
    '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#',
    '#', ' ', '@', ' ', ' ', ' ', '@', ' ', ' ', ' ', '@', ' ', '#',
    '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#',
    '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#',
    '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#',
    '#', ' ', '@', ' ', ' ', ' ', '*', ' ', ' ', ' ', '@', ' ', '#',
    '#', ' ', ' ', ' ', ' ', 'P', ' ', ' ', ' ', ' ', ' ', ' ', '#',
    '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'
};
inline level level_2 = {
    13, 13,
    level_2_data
};

inline constexpr size_t level_count = 2;
inline level levels[level_count] = {
    level_1, level_2
};

inline game_state game_state = menu_state;

inline bool victory_initialized = false;

#endif // GAME_H
