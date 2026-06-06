#include "raylib.h"
#include <stdint.h>

#define ASSETS_tileSize 16

#define ASSETS_tilePadding 1

#define ASSETS_tilesVerticalCount 32
#define ASSETS_tilesHorizontalCount 32

#define ASSETS_index(x, y) (x + y * ASSETS_tilesHorizontalCount)

#define ASSETS_totalTilesCount (ASSETS_tilesVerticalCount * ASSETS_tilesHorizontalCount)

static struct {
    Image tileSet;
    Texture2D tileSetTexture;
} Assets;

void LoadAllAssets() {
    Assets.tileSet = LoadImage("assets/tileset_legacy.png");
    Assets.tileSetTexture = LoadTextureFromImage(Assets.tileSet);
}

void DrawFromTileSet(uint16_t tileIndex, Rectangle dest) {
    int tileX = tileIndex % ASSETS_tilesHorizontalCount;
    int tileY = tileIndex / ASSETS_tilesHorizontalCount;

    Rectangle source = {
        (float)(tileX * (ASSETS_tileSize + ASSETS_tilePadding)),
        (float)(tileY * (ASSETS_tileSize + ASSETS_tilePadding)),
        (float)ASSETS_tileSize,
        (float)ASSETS_tileSize};

    DrawTexturePro(Assets.tileSetTexture, source, dest, (Vector2){0, 0}, 0, WHITE);
}

void CleanUpAssets() {
    UnloadImage(Assets.tileSet);
    UnloadTexture(Assets.tileSetTexture);
}