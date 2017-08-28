#include "map.h"

map_t* map_new() {
	map_t map = (map_t) malloc(sizeof(map_t));
	map->start = tile_new(0, 0, 0);
	return map;
}

void map_delete(map_t *map) {
	tile_delete(map->start);
}

tile_t* map_getTile(map_t *map, int64_t x, int64_t y) {
	tile_t tile = map->start;
	while(tile) {
		if(tile->x == x && tile->y == y) return tile;
		tile = tile->next;
	}
	return NULL;
}

tile_t* map_getPreTile(map_t *map, int64_t x, int64_t y) {
	tile_t tile = map->start;
	if(!tile) return NULL;
	while(tile->next) {
		if(tile->next->x == x && tile->next->y == y) return tile;
		tile = tile->next;
	}
	return NULL;
}

tile_t* map_getPostTile(map_t *map, int64_t x, int64_t y) {
	tile_t tile = map->start;
	while(tile) {
		if(tile->x == x && tile->y == y) return tile->next;
		tile = tile->next;
	}
	return NULL;
}

void map_addTile(map_t *map, tile_t *tile) {
	tile->next = NULL;
	tile_t t = map->start;
	if(!t) return;
	while(t->next) t = t->next;
	t->next = tile;
}

void map_updateTile(map_t *map, int64_t x, int64_t y, tile_t *tile) {
	tile_t *t = map_getTile(map, x, y), *tnext = t->next;
	memcpy(t, tile, sizeof(tile_t));
	t->next = tnext;
}

void map_deleteTile(map_t *map, int64_t x, int64_t y) {
	tile_t *t = map_getPreTile(map, x, y), *tp = t->next->next;
	free(t->next);
	t->next = tp;
}

void map_print(map_t *map) {
	tile_t tile = map->start;
	while(tile) {
		tile_print(tile);
		tile = tile->next;
	}
}
