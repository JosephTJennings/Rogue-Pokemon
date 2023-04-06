#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <vector>
#include <fstream>
#include <sstream>
#include <limits.h>
#include <iostream>

#include "pokemon.h"

//using std::string;
//using std::vector;
using namespace std;

static vector<pokemon> getPokemonCSV(string filePath) {
    vector<pokemon> pokeList;
    vector<string> row;
    fstream file;
    string line, element;

    file.open(filePath + "pokemon.csv", ios::in);

    getline(file, line);
    while(getline(file, line)) {
        row.clear();
        stringstream ss(line);
        cout << line << "\n";
        while(getline(ss, element, ',')) {
            if(element == "") element = to_string(INT_MAX);
            row.push_back(element);
        }
        if(row.size() != 6) row.push_back(to_string(INT_MAX));
        pokemon tmp;
        tmp.id = stoi(row[0]);
        tmp.identifier = row[1];
        tmp.species_id = stoi(row[2]);
        tmp.height = stoi(row[3]);
        tmp.weight = stoi(row[4]);
        tmp.base_experience = stoi(row[5]);
        tmp.order_is_default = stoi(row[6]);
        pokeList.push_back(tmp);
    }
    return pokeList;
}

static vector<pokemon_moves> getPokemonMoves(string filePath) {
    vector<pokemon_moves> moveList;
    vector<string> row;
    fstream file;
    string line, element;

    file.open(filePath + "pokemon_moves.csv", ios::in);

    getline(file, line);
    while(getline(file, line)) {
        row.clear();
        stringstream ss(line);
        cout << line << "\n";
        while(getline(ss, element, ',')) {
            if(element == "") element = to_string(INT_MAX);
            row.push_back(element);
        }
        if(row.size() != 6) row.push_back(to_string(INT_MAX));
        pokemon_moves tmp;
        //pokemon_id,version_group_id,move_id,pokemon_move_method_id,level,order
        tmp.pokemon_id = stoi(row[0]);
        tmp.version_group_id = stoi(row[1]);
        tmp.pokemon_move_method_id = stoi(row[2]);
        tmp.level = stoi(row[3]);
        tmp.order = stoi(row[4]);
        moveList.push_back(tmp);
    }
    return moveList;
}

static vector<pokemon_species> getPokemonSpecies(string filePath) {
    vector<pokemon_species> pokeList;
    vector<string> row;
    fstream file;
    string line, element;

    file.open(filePath + "pokemon_species.csv", ios::in);

    getline(file, line);
    while(getline(file, line)) {
        row.clear();
        stringstream ss(line);
        cout << line << "\n";
        while(getline(ss, element, ',')) {
            if(element.empty()) element = to_string(INT_MAX);
            row.push_back(element);
        }
        if(row.size() != 20) row.push_back(to_string(INT_MAX));

        //id,identifier,generation_id,evolves_from_species_id,evolution_chain_id,color_id,shape_id,habitat_id,gender_rate,capture_rate,
        //base_happiness,is_baby,hatch_counter,has_gender_differences,growth_rate_id,forms_switchable,is_legendary,is_mythical,order,conquest_order
        pokemon_species tmp;
        tmp.id = stoi(row[0]);
        tmp.identifier = row[1];
        tmp.generation_id = stoi(row[2]);
        tmp.evolves_from_species_id = stoi(row[3]);
        tmp.evolution_chain_id = stoi(row[4]);
        tmp.color_id = stoi(row[5]);
        tmp.shape_id = stoi(row[6]);
        tmp.habitat_id = stoi(row[7]);
        tmp.gender_rate = stoi(row[8]);
        tmp.capture_rate = stoi(row[9]);
        tmp.base_happiness = stoi(row[10]);
        tmp.is_baby = stoi(row[11]);
        tmp.hatch_counter = stoi(row[12]);
        tmp.has_gender_differences = stoi(row[13]);
        tmp.growth_rate_id = stoi(row[14]);
        tmp.forms_switchable = stoi(row[15]);
        tmp.is_legendary = stoi(row[16]);
        tmp.is_mythical = stoi(row[17]);
        tmp.order = stoi(row[18]);
        tmp.conquest_order = stoi(row[19]);
        pokeList.push_back(tmp);
    }
    return pokeList;
}

static vector<pokemon_stats> getPokemonStats(string filePath) {
    vector<pokemon_stats> moveList;
    vector<string> row;
    fstream file;
    string line, element;

    file.open(filePath + "pokemon_stats.csv", ios::in);

    getline(file, line);
    while(getline(file, line)) {
        row.clear();
        stringstream ss(line);
        cout << line << "\n";
        while(getline(ss, element, ',')) {
            if(element == "") element = to_string(INT_MAX);
            row.push_back(element);
        }
        if(row.size() != 4) row.push_back(to_string(INT_MAX));
        pokemon_stats tmp;
        //pokemon_id,stat_id,base_stat,effort
        tmp.pokemon_id = stoi(row[0]);
        tmp.stat_id = stoi(row[1]);
        tmp.base_stat = stoi(row[2]);
        tmp.effort = stoi(row[3]);
        moveList.push_back(tmp);
    }
    return moveList;
}

static vector<pokemon_types> getPokemonTypes(string filePath) {
    vector<pokemon_types> moveList;
    vector<string> row;
    fstream file;
    string line, element;

    file.open(filePath + "pokemon_types.csv", ios::in);

    getline(file, line);
    while(getline(file, line)) {
        row.clear();
        stringstream ss(line);
        cout << line << "\n";
        while(getline(ss, element, ',')) {
            if(element == "") element = to_string(INT_MAX);
            row.push_back(element);
        }
        if(row.size() != 3) row.push_back(to_string(INT_MAX));
        pokemon_types tmp;
        //pokemon_id,stat_id,base_stat,effort
        tmp.pokemon_id = stoi(row[0]);
        tmp.type_id = stoi(row[1]);
        tmp.slot = stoi(row[2]);
        moveList.push_back(tmp);
    }
    return moveList;
}

static vector<moves> getMoves(string filePath) {
    vector<moves> pokeList;
    vector<string> row;
    fstream file;
    string line, element;

    file.open(filePath + "moves.csv", ios::in);

    getline(file, line);
    while(getline(file, line)) {
        row.clear();
        stringstream ss(line);
        cout << line << "\n";
        while(getline(ss, element, ',')) {
            if(element.empty()) element = to_string(INT_MAX);
            row.push_back(element);
        }
        if(row.size() != 15) row.push_back(to_string(INT_MAX));

        moves tmp;
        tmp.id = stoi(row[0]);
        tmp.identifier = row[1];
        tmp.generation_id = stoi(row[2]);
        tmp.type_id = stoi(row[3]);
        tmp.power = stoi(row[4]);
        tmp.pp = stoi(row[5]);
        tmp.accuracy = stoi(row[6]);
        tmp.priority = stoi(row[7]);
        tmp.target_id = stoi(row[8]);
        tmp.damage_class_id = stoi(row[9]);
        tmp.effect_id = stoi(row[10]);
        tmp.effect_chance = stoi(row[11]);
        tmp.contest_type_id = stoi(row[12]);
        tmp.contest_effect_id = stoi(row[13]);
        tmp.super_contest_effect_id = stoi(row[14]);
        pokeList.push_back(tmp);
    }
    return pokeList;
}

static vector<experience> getExperience(string filePath) {
    vector<experience> moveList;
    vector<string> row;
    fstream file;
    string line, element;

    file.open(filePath + "experience.csv", ios::in);

    getline(file, line);
    while(getline(file, line)) {
        row.clear();
        stringstream ss(line);
        cout << line << "\n";
        while(getline(ss, element, ',')) {
            if(element == "") element = to_string(INT_MAX);
            row.push_back(element);
        }
        if(row.size() != 3) row.push_back(to_string(INT_MAX));
        experience tmp;
        tmp.growth_rate_id = stoi(row[0]);
        tmp.level = stoi(row[1]);
        tmp.experience = stoi(row[2]);
        moveList.push_back(tmp);
    }
    return moveList;
}

static vector<type_names> getTypeNames(string filePath) {
    vector<type_names> moveList;
    vector<string> row;
    fstream file;
    string line, element;

    file.open(filePath + "type_names.csv", ios::in);

    getline(file, line);
    while(getline(file, line)) {
        row.clear();
        stringstream ss(line);
        while(getline(ss, element, ',')) {
            if(element == "") element = to_string(INT_MAX);
            row.push_back(element);
        }
        if(row.size() != 3) row.push_back(to_string(INT_MAX));
        if(stoi(row[1]) != 9) continue;
        type_names tmp;
        tmp.type_id = stoi(row[0]);
        tmp.local_language_id = stoi(row[1]);
        tmp.name = row[2];
        moveList.push_back(tmp);
    }
    for(long unsigned i = 0; i < moveList.size(); i++) {
        type_names typeN = moveList[i];
        cout << typeN.type_id << "," << typeN.local_language_id << "," << typeN.name << "\n";
    }

    return moveList;
}

static vector<stats> getStats(string filePath) {
    vector<stats> moveList;
    vector<string> row;
    fstream file;
    string line, element;

    file.open(filePath + "experience.csv", ios::in);

    getline(file, line);
    while(getline(file, line)) {
        row.clear();
        stringstream ss(line);
        cout << line << "\n";
        while(getline(ss, element, ',')) {
            if(element == "") element = to_string(INT_MAX);
            row.push_back(element);
        }
        if(row.size() != 4) row.push_back(to_string(INT_MAX));
        stats tmp;
        tmp.damage_class_id = stoi(row[0]);
        tmp.identifier = row[1];
        tmp.is_battle_only = stoi(row[2]);
        tmp.game_index = stoi(row[3]);
        moveList.push_back(tmp);
    }
    return moveList;
}

/**
int main(int argc, char *argv[]){
    string filePath = "";
    vector<pokemon> pokemonList = getPokemonCSV(filePath);
    cout << pokemonList.size() << "\n";
    vector<pokemon_moves> pokemonMoves = getPokemonMoves(filePath);
    cout << pokemonMoves.size() << " " << pokemonMoves[pokemonMoves.size() / 2].pokemon_id << "\n";
    vector<pokemon_species> pokemonSpecies = getPokemonSpecies(filePath);
    cout << pokemonSpecies.size() << " " << pokemonSpecies[pokemonSpecies.size() / 2].identifier << "\n";
    vector<pokemon_stats> pokemonStats = getPokemonStats(filePath);
    cout << pokemonStats.size() << " " << pokemonStats[pokemonStats.size() / 2].pokemon_id << "\n";
    vector<pokemon_types> pokemonTypes = getPokemonTypes(filePath);
    cout << pokemonTypes.size() << " " << pokemonTypes[pokemonTypes.size() / 2].pokemon_id << "\n";
}

**/