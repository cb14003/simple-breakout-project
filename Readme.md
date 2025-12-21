# Simple Breakout - Classic Arcade Game

Project Overview

**Simple Breakout** is a classic arcade game implemented in C++ using the Raylib graphics library. The player controls a platform, bouncing a ball and destroying blocks across six unique levels. The project demonstrates the application of procedural programming, modularity, and graphics principles.

---

##  Features

### **1. Core Gameplay**
-  **Six unique levels** with varying block layouts and obstacles
-  **Ball physics** with realistic bounces off walls, blocks, and platforms
-  **Platform controls** (A/D or ←/→ keys)
-  **Block destruction** upon collision with the ball

### **2. Menu System and User Interface (UI/UX)**
-  **Main Menu** with "Start Game" option
-  **Level Select Menu** (press 1-6 to select a level)
-  **Pause Screen** (ESC to pause, resume, or exit to the menu)
-  **Victory Screen** with animation and statistics
-  **Game Over Screen** with final score
-  **Skin Shop** (T to access from the main menu)
-  **In-Game Interface** displaying:
- Current Level
- Number of Remaining Blocks
- Current Score

### **3. Economy System**
-  **Points System** (+100 points for each destroyed block)
-  **Bonus Points** (+1000 points for completing a level)
-  **Coins System**:
- 100 points = 10 coins
- Coins accumulate throughout the game
- Points reset when starting a new level
- Coins display in the main menu and level select menu

### **4. Ball Skin Shop**
- **Four different skins for the ball**:
- **Basic Ball** (basic, free) - `ball0.png`
- **Fire Ball** (cost: 100 coins) - `ball1.png`
- **Ice Ball** (cost: 200 coins) - `ball2.png`
- **Gold Ball** (cost: 300 coins) - `ball3.png`
- **Purchase and equip mechanics**:
- Shop navigation (W/S or Up/Down keys)
- Purchasing skins with coins (ENTER)
- Equipping already purchased skins
- Visual highlighting of the selected and equipped skin
- Skin preview in the shop

### **5. Sound System**
- **Background Music** (plays throughout the game)
- **Collision Sound Effects**:
- Ball hitting a wall
- Block breaking
- Platform bouncing
- 
- **System Sounds**:
- Menu selection (selecting_sound)
- Level victory (win_sound)
- Loss (lose_sound)
- Long victory sound (victory_sound)
- Long defeat sound (losing_sound)

### **6. Graphics and Visual Effects**
- **Downloadable textures** for all game elements:
- Walls, blocks, platform
- Ball sprites (1 frame for each skin)
- **Custom pixel font** (ARCADECLASSIC.TTF)
- **Victory menu animation** (flying balls)
- **Smooth game state transitions**

---
Project Structure

**Source Files**

| File | Purpose |
|------|-----------|
| `breakout.cpp` | Main game loop, `main()` function, `update()` and `draw()` functions |
| `game.h/.cpp` | Definitions of structures, levels, global variables, game state |
| `graphics.h/.cpp` | All drawing functions: menu, game field, interface |
| `assets.h/.cpp` | Loading and unloading resources (textures, sounds, fonts) |
| `level.h/.cpp` | Level logic: loading, collision checking, working with level data |
| `ball.h/.cpp` | Ball logic: movement, collisions, spawning |
| `paddle.h/.cpp` | Paddle logic: movement, bounding |
| `sprite.h/.cpp` | Sprite structure and functions |

### **Assets**

| Directory | Contents |
|------------|------------|
| `data/images/` | Graphic resources: `wall.png`, `block.png`, `paddle.png`, `ball0-3.png` |
| `data/sounds/` | Sound files: `win.wav`, `lose.wav`, `victory.wav`, `selecting.wav`, `background.wav`, etc. |
| `data/fonts/` | Fonts: `ARCADECLASSIC.TTF` |

### **Configuration files**
- `CMakeLists.txt` - CMake build system configuration

---

Build and Run Instructions

### **System Requirements**
- **CMake** (version 3.15+)
- **C++ Compiler** (MSVC, GCC 9+, Clang 10+)
- **vcpkg Dependency Manager** (for installing Raylib)
- **Raylib Library** (installed via vcpkg)

**Step-by-Step Build**

1. **Cloning the Repository**
```bash
git clone ...
cd simple-breakout-project
```

2. **Installing Dependencies via vcpkg**
```bash
vcpkg install raylib:x64-windows # For Windows
# or
vcpkg install raylib:x64-linux # For Linux
```

3. **Project Configuration with CMake**
```bash
cmake -B build -S . -DCMAKE_TOOLCHAIN_FILE=[PATH_TO_VCPKG]/scripts/buildsystems/vcpkg.cmake

# Example for Windows (vcpkg in C:/src/vcpkg):
cmake -B build -S . -DCMAKE_TOOLCHAIN_FILE=C:/src/vcpkg/scripts/buildsystems/vcpkg.cmake
```

4. **Building the Project**
```bash
cmake --build build --config Release
```

5. **Running the Game**
```bash
# Windows
./build/Release/breakout.exe

# Linux/macOS
./build/breakout
```

**Setting the Working Directory in CLion**
To load resources correctly, set the working directory:
1. In the `Run` menu → `Edit Configurations`
2. Select the `breakout` target
3. In the `Working directory` field, enter: `$ProjectFileDir$`
4. Save and run

Game Controls

### **Basic Controls**
| Action | Keys |
|----------|---------|
| Platform move left | `A` or `←` |
| Platform move right | `D` or `→` |
| Pause/resume game | `ESC` |
| Exit game | `Q` |

### **Menu Controls**
| Context | Action | Keys |
|----------|----------|-----|
| Main Menu | Start Game | `ENTER` |
| Main Menu | Open Shop | `T` |
| Level Select | Select Level 1-6 | `1`-`6` |
| Level Select | Return to Menu | `M` |
| Shop | Navigate Up/Down | `W`/`S` or `↑`/`↓` |
| Shop | Buy/Equip Skin | `ENTER` |
| Shop | Return to Menu | `M` |
| Pause Screen | Resume Game | `ESC` |
| Pause Screen | Level Select | `S` |
| Pause Screen | Main Menu | `M` |
| Win/Loss Screen | Replay Level | `ENTER` |
| Win/Loss Screen | Next Level | `N` |
| Win/Loss Screen | Previous Level | `B` |
| Win/Loss Screen | Level Select | `S` |

---

**State Machine**
The game uses a state machine with 7 states:
1. **menu_state** - Main menu
2. **level_select_state** - Level selection
3. **in_game_state** - Active game
4. **paused_state** - Paused game
5. **victory_state** - Level victory
6. **game_over_state** - Defeat
7. **shop_state** - Skin shop

Technologies and libraries used

- Programming language: C++17
- Graphics library: [Raylib 4.5](https://www.raylib.com)
- Build system: CMake 3.20+
- Dependency management: vcpkg
- Font: ARCADECLASSIC (pixel font)

---

## Author

- Developer: Bermet Chintemirova
- Course: Introduction to Programming
- Institution: American University of Central Asia
- This project is for educational purposes and demonstrates the application of procedural programming principles, graphics, and sound in C++.