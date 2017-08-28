#ifndef TILE_H_DEF
#define TILE_H_DEF

typedef struct tile_s {
	tile_s *next;
	int64_t x, y;
	uint32_t type;
} tile_t;

tile_t* tile_new(int64_t x, int64_t y, uint32_t type);
void tile_delete(tile_t *tile);

void tile_changeType(tile_t *tile, uint32_t type);
void tile_print(tile_t *tile);

#endif

