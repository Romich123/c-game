#include "raylib.h"
#include "appstate.c"
#include "networking.h"
#include "game.c"
#include "assets.c"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

int main(void) {
    InitNetwork();

    SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_WINDOW_ALWAYS_RUN);
    InitWindow(800, 450, "Main window");
    LoadAllAssets();

    SetTargetFPS(60);
    SetExitKey(KEY_NULL);

    App.server = Server_Create(0, 0);

    printf("Server is running on: %" PRIu16 "\n", App.server->port);

    while (!ShouldExitApplication()) {
        BeginDrawing();
        ClearBackground((Color){71, 45, 60, 255});
        App.currentMouseCursor = MOUSE_CURSOR_DEFAULT;

        SetMouseCursor(App.currentMouseCursor);
        EndDrawing();
    }

    Server_CleanUp(App.server);
    CleanUpAssets();
    CleanupNetwork();
    CloseWindow();
    return 0;
}