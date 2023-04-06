#ifndef POKEMON_H
# define POKEMON_H

class pokemon {
    public:
    virtual ~pokemon() {}
    int id;
    std::string identifier;
    int species_id;
    int height;
    int weight;
    int base_experience;
    int order_is_default;
};

struct pokemon_moves {
    //pokemon_id,version_group_id,move_id,pokemon_move_method_id,level,order
    int pokemon_id;
    int version_group_id;
    int move_id;
    int pokemon_move_method_id;
    int level;
    int order;
};

struct pokemon_species {
    //id,identifier,generation_id,evolves_from_species_id,evolution_chain_id,color_id,shape_id,habitat_id,gender_rate,capture_rate,
    //base_happiness,is_baby,hatch_counter,has_gender_differences,growth_rate_id,forms_switchable,is_legendary,is_mythical,order,conquest_order
    int id;
    std::string identifier;
    int generation_id;
    int evolves_from_species_id;
    int evolution_chain_id;
    int color_id;
    int shape_id;
    int habitat_id;
    int gender_rate;
    int capture_rate;
    int base_happiness;
    int is_baby;
    int hatch_counter;
    int has_gender_differences;
    int growth_rate_id;
    int forms_switchable;
    int is_legendary;
    int is_mythical;
    int order;
    int conquest_order;

};

struct pokemon_stats {
    //pokemon_id,stat_id,base_stat,effort
    int pokemon_id;
    int stat_id;
    int base_stat;
    int effort;
};

struct pokemon_types {
    //pokemon_id,type_id,slot
    int pokemon_id;
    int type_id;
    int slot;
};

struct moves {
    //id,identifier,generation_id,type_id,power,pp,accuracy,priority,target_id,damage_class_id,
    //effect_id,effect_chance,contest_type_id,contest_effect_id,super_contest_effect_id
    int id;
    std::string identifier;
    int generation_id;
    int type_id;
    int power;
    int pp;
    int accuracy;
    int priority;
    int target_id;
    int damage_class_id;
    int effect_id;
    int effect_chance;
    int contest_type_id;
    int contest_effect_id;
    int super_contest_effect_id;
};

struct experience{
    //growth_rate_id,level,experience
    int growth_rate_id;
    int level;
    int experience;
};

struct type_names{
    //type_id,local_language_id,name
    int type_id;
    int local_language_id;
    std::string name;
};

struct stats{
    //id,damage_class_id,identifier,is_battle_only,game_index
    int id;
    int damage_class_id;
    std::string identifier;
    int is_battle_only;
    int game_index;
};

#endif