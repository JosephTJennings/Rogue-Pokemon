#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <vector>
#include <iostream>

#include "db_parse.h"
#include "pokemon.h"

using namespace std;

static vector<pokemon_move_db> getPossibleMoves(int pokemon_id, int move_id){
    int left = 0;
    int right = sizeof(pokemon_moves) - 1;
    int moveIndex = 0;
    vector<pokemon_move_db> possibleMoves;
    while(left <= right) {
        int mid = left + right / 2;
        if(pokemon_moves[mid].pokemon_id > pokemon_id) left = mid + 1;
        else if(pokemon_moves[mid].pokemon_id > pokemon_id) right = mid - 1;
        else moveIndex = mid;
    }

    int tmp = moveIndex;
    while(pokemon_moves[tmp].pokemon_id != pokemon_id) { //find first occurence of the pokemon_id move
        moveIndex = tmp;
        tmp--;
    }
    while(pokemon_moves[moveIndex].pokemon_id != pokemon_id) {
        if(pokemon_moves[moveIndex].pokemon_move_method_id == move_id) possibleMoves.push_back(pokemon_moves[moveIndex]);
        moveIndex++;
    }

    return possibleMoves;
}

static pokemon_db addPokemonEncounter(int level){
    int pokemonIndex = rand() % sizeof(pokemon_db);
    pokemon_db newPokemon = pokemons[pokemonIndex];
    vector<pokemon_move_db> possibleMoves = getPossibleMoves(newPokemon.species_id, 1);
    vector<pokemon_move_db> moveSet;
    int count = 2;
    while(sizeof(possibleMoves) < 1) {
        possibleMoves = getPossibleMoves(newPokemon.species_id, count);
        count++;
    }
    for(int i = 0; i < 2; i++) {
        int randMoveIndex = rand() % sizeof(possibleMoves);
        moveSet.push_back(possibleMoves[randMoveIndex]);
    }
    newPokemon.moveset = moveSet;
    newPokemon.level = level;
    newPokemon.is_default = (rand() % 8192 == 0) ? 0 : 1;
}

static void printPokemonInfo(pokemon_db poke) {
    cout << poke.identifier << ", level: " << poke.level << ", stats: " << " \n";
    cout << "moves (move_id): ";
    for(int i = 0; i < sizeof(poke.moveset); i++){
        cout << poke.moveset[i].move_id << " ";
    }
    cout << "\n";
}
static pokemon_db addPokemonStarter();