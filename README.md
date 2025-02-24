# cub3D

## Overview
cub3D is a raycasting project that renders a first-person 3D graphical representation of a maze, inspired by Wolfenstein 3D. The project utilizes the MiniLibX graphics library and implements fundamental raycasting principles to simulate a pseudo-3D environment.

## 🚀 Features
- **Raycasting rendering** for realistic 3D visualization
- **Smooth window management** (minimizing, switching, etc.)
- **Wall textures based on direction** (North, South, East, West)
- **Custom floor and ceiling colors**
- **Player movement** using `W`, `A`, `S`, `D`
- **Camera rotation** using arrow keys
- **Clean program exit** via `ESC` key or window close button
- **Configurable map format** (`*.cub`)

## ⚙️ Installation & Compilation
### Prerequisites
- `make`
- `MiniLibX`
- `libft` (custom standard function library)

### Compilation
To compile cub3D, run:
```sh
make
```
This will generate the `cub3D` executable.

To compile cub3D bonus (see [Bonus Features](#-bonus-features)), run:
```sh
make bonus
```
This will generate the `cub3D_bonus` executable.

### Cleaning
To remove object files:
```sh
make clean
```
To remove the executable and object files:
```sh
make fclean
```
To recompile everything:
```sh
make re
```

```sh
make re_bonus
```

## 🔧 Usage
Run the program with a valid `.cub` map file:
```sh
./cub3D map/example.cub
```

```sh
./cub3D_bonus map/example.cub
```

### 🎮 Controls
| Key | Action |
|------|---------|
| `W` | Move forward |
| `A` | Move left |
| `S` | Move backward |
| `D` | Move right |
| `←` | Look left |
| `→` | Look right |
| `SHIFT` | Increase player speed |
| `ESC` | Exit game |
| Window close | Exit game |
| `P` | Open door (bonus) |


## 📜 Map Format
The map must be provided in a `.cub` file and follow specific formatting rules:
### Elements
- **Wall textures:**
  ```
  NO ./path_to_north_texture
  SO ./path_to_south_texture
  WE ./path_to_west_texture
  EA ./path_to_east_texture
  ```
- **Floor & ceiling colors:**
  ```
  F 220,100,0  # RGB format
  C 225,30,0
  ```
- **Map layout:**
  - `1` - Wall
  - `0` - Empty space
  - `N`, `S`, `E`, `W` - Player start position
  - `D` - Door (bonus)
  ```
  111111
  100101
  101001
  1100N1
  111111
  ```
- The map must be fully enclosed by walls (`1`).
- Elements must appear before the map in the file.

## 🏆 Bonus Features
The bonus version includes:
- **Wall collision detection**
- **Minimap system**
- **Doors that open and close**
- **Mouse-controlled rotation**

## 📝 License
This project is developed as part of the 42 curriculum and follows its academic integrity guidelines.


