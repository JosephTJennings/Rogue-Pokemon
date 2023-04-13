#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <vector>
#include <iostream>

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

pokemon_db addPokemonEncounter(int level){
    int pokemonIndex = rand() % 1093;
    pokemon_db newPokemon = pokemons[pokemonIndex];
    cout << "test...\n";
    vector<pokemon_move_db> possibleMoves = getPossibleMoves(newPokemon.species_id, 1);
    vector<pokemon_move_db> moveSet;
    int count = 2;
    while(possibleMoves.size() < 1) {
        possibleMoves = getPossibleMoves(newPokemon.species_id, count);
        count++;
    }
    cout << "test...\n";
    for(int i = 0; i < 2; i++) {
        int randMoveIndex = rand() % possibleMoves.size();
        moveSet.push_back(possibleMoves[randMoveIndex]);
    }
    newPokemon.moveset = moveSet;
    newPokemon.level = level;
    newPokemon.is_default = (rand() % 8192 == 0) ? 0 : 1;
    return newPokemon;
}

void printPokemonInfo(pokemon_db poke) {
    cout <<"STARTING PRINT...\n";
    cout << poke.identifier << ", level: " << poke.level << ", stats: " << " \n";
    cout << "moves (move_id): ";
    for(int i = 0; i < (int)(poke.moveset.size()); i++){
        cout << poke.moveset[i].move_id << " ";
    }
    cout << "\n";
}
//pokemon_db addPokemonStarter();