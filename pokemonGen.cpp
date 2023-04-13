#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <unistd.h>

#include "db_parse.h"

using namespace std;

static vector<pokemon_move_db> getPossibleMoves(int pokemon_id, int move_id){
    int left = 0;
    int right = 528239 - 1;
    int moveIndex = 0;
    vector<pokemon_move_db> possibleMoves;
    //cout << "bs...\n";
    while(left <= right) {
        int mid = (left + right) / 2;
        if(pokemon_moves[mid].pokemon_id < pokemon_id) left = mid + 1;
        else if(pokemon_moves[mid].pokemon_id > pokemon_id) right = mid - 1;
        else {
            moveIndex = mid;
            break;
        }
    }

    int tmp = moveIndex;
    while(pokemon_moves[tmp].pokemon_id == pokemon_id) { //find first occurence of the pokemon_id move
        moveIndex = tmp;
        tmp--;
    }
    while(pokemon_moves[moveIndex].pokemon_id == pokemon_id) {
        if(pokemon_moves[moveIndex].pokemon_move_method_id == move_id) possibleMoves.push_back(pokemon_moves[moveIndex]);
        moveIndex++;
    }
    return possibleMoves;
}

static vector<pokemon_stats_db> getBaseStats(int pokemon_id) {
    int left = 0;
    int right = 6553 - 1;
    int moveIndex = 0;
    vector<pokemon_stats_db> statList;
    //cout << "bs...\n";
    while(left <= right) {
        int mid = (left + right) / 2;
        if(pokemon_stats[mid].pokemon_id < pokemon_id) left = mid + 1;
        else if(pokemon_stats[mid].pokemon_id > pokemon_id) right = mid - 1;
        else {
            moveIndex = mid;
            break;
        }
    }

    int tmp = moveIndex;
    while(pokemon_stats[tmp].pokemon_id == pokemon_id) { //find first occurence of the pokemon_id move
        moveIndex = tmp;
        tmp--;
    }
    while(pokemon_stats[moveIndex].pokemon_id == pokemon_id) {
        statList.push_back(pokemon_stats[moveIndex]);
        moveIndex++;
    }
    return statList;
}

pokemon_db addPokemonEncounter(int level){
    int pokemonIndex = rand() % 1093;
    pokemon_db newPokemon = pokemons[pokemonIndex];
    vector<pokemon_move_db> possibleMoves = getPossibleMoves(newPokemon.species_id, 1);
    vector<pokemon_move_db> moveSet;

    int count = 2;
    while(possibleMoves.size() < 1) {
        possibleMoves = getPossibleMoves(newPokemon.species_id, count);
        count++;
    }
    for(int i = 0; i < 2; i++) {
        int randMoveIndex = rand() % possibleMoves.size();
        moveSet.push_back(possibleMoves[randMoveIndex]);
    }
    newPokemon.moveset = moveSet;
    newPokemon.level = level;
    newPokemon.is_default = (rand() % 8192 == 0) ? 0 : 1;
    newPokemon.baseStats = getBaseStats(newPokemon.species_id);
    newPokemon.IVS = newPokemon.baseStats;
    // increment for random IV's
    newPokemon.IVS[0].base_stat = rand() % 16;
    newPokemon.IVS[1].base_stat = rand() % 16;
    newPokemon.IVS[2].base_stat = rand() % 16;
    newPokemon.IVS[3].base_stat = rand() % 16;
    newPokemon.IVS[4].base_stat = rand() % 16;
    newPokemon.IVS[5].base_stat = rand() % 16; 
    return newPokemon;
}

int levelUpHealth(pokemon_db poke, int level){
    return (((poke.baseStats[0].base_stat + poke.IVS[0].base_stat) * level) / 100) + level + 10;
}

int levelUpStat(pokemon_db poke, int level) {
    return (((poke.baseStats[0].base_stat + poke.IVS[0].base_stat) * level) / 100) + 5;    
}

pokemon_db levelUp(pokemon_db poke, int level) {
    poke.baseStats[0].base_stat = levelUpHealth(poke, level);
    poke.baseStats[1].base_stat = levelUpStat(poke, level);
    poke.baseStats[2].base_stat = levelUpStat(poke, level);
    poke.baseStats[3].base_stat = levelUpStat(poke, level);
    poke.baseStats[4].base_stat = levelUpStat(poke, level);
    poke.baseStats[5].base_stat = levelUpStat(poke, level);
    return poke;
}

vector<pokemon_db> addPokemonStarters() {
    vector<pokemon_db> starters;
    for(int i = 0; i < 3; i++) {
        pokemon_db newPoke = addPokemonEncounter(1);
        for(int j = 0; j < (int) starters.size(); j++) {
            while(newPoke.id == starters[j].id) {
                newPoke = addPokemonEncounter(1);
            }
        }
        newPoke = levelUp(newPoke, 1);
        starters.push_back(newPoke);
    }
    return starters;
}