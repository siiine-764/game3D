#include <stdio.h>
#include <math.h>

#define TILE_SIZE 32
#define MAP_NUM_ROWS 11
#define MAP_NUM_COLS 15
#define WINDOW_WIDTH (MAP_NUM_COLS * TILE_SIZE)
#define WINDOW_HEIGHT (MAP_NUM_ROWS * TILE_SIZE)
#define FOV_ANGLE (60 * (M_PI / 180))
#define WALL_STRIP_WIDTH 1
#define NUM_RAYS (WINDOW_WIDTH / WALL_STRIP_WIDTH)


#define GRID_WIDTH 20  // Replace with your actual grid dimensions
#define GRID_HEIGHT 15  // Replace with your actual grid dimensions


int grid[MAP_NUM_ROWS][MAP_NUM_COLS] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
    {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
    {1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

typedef struct {
    float x;
    float y;
    float radius;
    int turnDirection;
    int walkDirection;
    float rotationAngle;
    float moveSpeed;
    float rotationSpeed;
} Player;

typedef struct {
    float rayAngle;
} Ray;

int hasWallAt(float x, float y) {
    if (x < 0 || x > WINDOW_WIDTH || y < 0 || y > WINDOW_HEIGHT) {
        return 0;
    }
    
    // Use the floor function from the math library
    int mapGridIndexX = (int)floor(x / TILE_SIZE);
    int mapGridIndexY = (int)floor(y / TILE_SIZE);
    
    // Assuming this.grid is a 2D array of integers
    // Replace this with the actual name of your grid variable
    // Make sure it's defined in the current scope
    // You may need to pass the grid as a parameter or declare it globally.
    // For now, let's assume it's a global variable.
    int this_grid[][];

    // Check if mapGridIndexX and mapGridIndexY are within bounds
    if (mapGridIndexX < 0 || mapGridIndexX >= GRID_WIDTH || mapGridIndexY < 0 || mapGridIndexY >= GRID_HEIGHT) {
        return 0;
    }
    
    return this_grid[mapGridIndexY][mapGridIndexX] != 0;
}


// int hasWallAt(float x, float y) {
//     if (x < 0 || x > WINDOW_WIDTH || y < 0 || y > WINDOW_HEIGHT) {
//         return 1;
//     }
//     int mapGridIndexX = (int)(x / TILE_SIZE);
//     int mapGridIndexY = (int)(y / TILE_SIZE);
//     return grid[mapGridIndexY][mapGridIndexX] != 0;
// }

void update(Player *player) {
    player->rotationAngle += player->turnDirection * player->rotationSpeed;

    float moveStep = player->walkDirection * player->moveSpeed;

    float newPlayerX = player->x + cos(player->rotationAngle) * moveStep;
    float newPlayerY = player->y + sin(player->rotationAngle) * moveStep;

    if (!hasWallAt(newPlayerX, newPlayerY)) {
        player->x = newPlayerX;
        player->y = newPlayerY;
    }
}


void render(Player player, Ray rays[NUM_RAYS]) {
    // Render the player and rays here
}

void castAllRays(Player player, Ray rays[NUM_RAYS]) {
    int columnId = 0;
    float rayAngle = player.rotationAngle - (FOV_ANGLE / 2);

    for (int i = 0; i < NUM_RAYS; i++) {
        Ray ray;
        ray.rayAngle = rayAngle;
        rays[i] = ray;
        rayAngle += FOV_ANGLE / NUM_RAYS;
        columnId++;
    }
}

int main() {
    Player player;
    player.x = WINDOW_WIDTH / 2;
    player.y = WINDOW_HEIGHT / 2;
    player.radius = 3;
    player.turnDirection = 0;
    player.walkDirection = 0;
    player.rotationAngle = M_PI / 2;
    player.moveSpeed = 2.0;
    player.rotationSpeed = 2 * (M_PI / 180);

    Ray rays[NUM_RAYS];

    // Initialize the player and rays

    while (1) {
        // Handle input (e.g., arrow keys)
        // Update the player
        // Cast all rays
        // Render the scene
    }

    return 0;
}
