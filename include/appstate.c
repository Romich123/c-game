#include "raylib.h"
#include <stdbool.h>

static bool shouldQuitApplication = false;
static MouseCursor currentMouseCursor = MOUSE_CURSOR_DEFAULT;

bool ShouldExitApplication() {
    return !WindowShouldClose() && !shouldQuitApplication;
}