#ifndef TILE_H_DEF
#define TILE_H_DEF

#include "tile.h"

typedef struct map_s {
	tile_t *start;
} map_t;

map_t* map_new();
void map_delete(map_t *map);

tile_t* map_getTile(map_t *map, int64_t x, int64_t y);
tile_t* map_getPreTile(map_t *map, int64_t x, int64_t y);
tile_t* map_getPostTile(map_t *map, int64_t x, int64_t y);

void map_addTile(map_t *map, tile_t *tile);
void map_updateTile(map_t *map, int64_t x, int64_t y, tile_t *tile);
void map_deleteTile(map_t *map, int64_t x, int64_t y);

void map_print(map_t *map);

#endif

