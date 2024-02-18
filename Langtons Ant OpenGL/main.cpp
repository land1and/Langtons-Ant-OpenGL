#include <iostream>
#include <string>
#include <GLFW/glfw3.h>
#include "i2.hpp"

#define GRID_SIZE 500
#define GRID_SIZE_MINUS_ONE (GRID_SIZE - 1)
#define ITERATIONS_PER_FRAME 10

void draw_pixels(unsigned char* grid) {
    //glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);
    for (int y = 0; y < GRID_SIZE; y++) {
        for (int x = 0; x < GRID_SIZE; x++) {
            const unsigned char pixel = grid[y * GRID_SIZE + x] * 255;
            glColor3ub(pixel, pixel, pixel);
            glVertex2i(x, y);
        }
    }
    glEnd();
}

int main() {
    if (!glfwInit()) {
        return -1;
    }
    GLFWwindow* window = glfwCreateWindow(GRID_SIZE, GRID_SIZE, "Langtons Ant", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glViewport(0, 0, GRID_SIZE, GRID_SIZE);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, GRID_SIZE, GRID_SIZE, 0, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    unsigned char grid[GRID_SIZE * GRID_SIZE] = {};
    i2 ant_position(GRID_SIZE / 2, GRID_SIZE / 2);
    i2 ant_direction(-1, 0);
    int iterations = 0;
    while (!glfwWindowShouldClose(window)) {
        for (int i = 0; i < ITERATIONS_PER_FRAME; i++) {
            const int index = ant_position.y * GRID_SIZE + ant_position.x;
            ant_direction = grid[index] ? i2(ant_direction.y, -ant_direction.x) : i2(-ant_direction.y, ant_direction.x);
            ant_position += ant_direction;
            grid[index] = grid[index] ? 0 : 1;
            if (ant_position.x < 0 || ant_position.x > GRID_SIZE_MINUS_ONE || ant_position.y < 0 || ant_position.y > GRID_SIZE_MINUS_ONE) {
                glfwSetWindowShouldClose(window, 1);
                break;
            }
            iterations++;
        }
        draw_pixels(grid);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    printf("finished with %d iterations", iterations);
    glfwTerminate();
    return 0;
}