#include "raylib.h"
#include "appstate.c"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void ServerLoop() {
}

void ClientLoop() {
}

int main(void) {
    InitNetwork();

    SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_WINDOW_ALWAYS_RUN);
    InitWindow(800, 450, "Main window");

    SetTargetFPS(60);
    SetExitKey(KEY_NULL);

    while (!ShouldExitApplication()) {
        BeginDrawing();
        currentMouseCursor = MOUSE_CURSOR_DEFAULT;

        EndDrawing();
    }

    CloseWindow();
    CleanupNetwork();
    return 0;
}