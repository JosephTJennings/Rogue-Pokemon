#ifndef pokemonGen_H
# define pokemonGen_H
#include "db_parse.h"
#include <vector>

std::vector<pokemon_move_db> getPossibleMoves(int pokemon_id, int move_id);
std::vector<pokemon_stats_db> getBaseStats(int pokemon_id);
pokemon_db addPokemonEncounter(int level);
int levelUpHealth(pokemon_db poke, int level);
int levelUpStat(pokemon_db poke, int level);
pokemon_db levelUp(pokemon_db poke, int level);
std::vector<pokemon_db> addPokemonStarters();


#endif