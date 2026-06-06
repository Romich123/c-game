#include "raylib.h"
#include "appstate.c"
#include "networking.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    InitNetwork();

    SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_WINDOW_ALWAYS_RUN);
    InitWindow(800, 450, "Main window");

    SetTargetFPS(200);
    SetExitKey(KEY_NULL);

    while (!ShouldExitApplication()) {
        BeginDrawing();
        currentMouseCursor = MOUSE_CURSOR_DEFAULT;

        SetMouseCursor(currentMouseCursor);
        EndDrawing();
    }

    CloseWindow();
    CleanupNetwork();
    return 0;
}