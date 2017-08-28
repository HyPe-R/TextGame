#include "tile.h"

tile_t* tile_new(int64_t x, int64_t y, uint32_t type) {
	tile_t *tile = (tile_t*) malloc(sizeof(tile_t));
	tile->next = NULL;
	tile->x = x;
	tile->y = y;
	tile->type = type;
	return tile;
}

void tile_delete(tile_t *tile) {
	if(tile->next) tile_delete(tile->next);
	free(tile);
}

void tile_changeType(tile_t *tile, uint32_t type) {
	tile->type = type;
}

void tile_print(tile_t *tile) {
	printf("(%i, %i) T:%i", tile->x, tile->y, tile->type);
}

