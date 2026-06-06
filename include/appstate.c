#pragma once

#include "raylib.h"
#include "networking.h"
#include <stdbool.h>

typedef enum {
    APP_STATE_MAIN_MENU,
    APP_STATE_CONNECT_MENU,
    APP_STATE_IN_GAME
} AppState;

struct App {
    AppState state;
    bool shouldQuitApplication;
    MouseCursor currentMouseCursor;
    ServerInstance *server;
    ClientInstance *client;
} App = {0};

bool ShouldExitApplication() {
    return WindowShouldClose() || App.shouldQuitApplication;
}