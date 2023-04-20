#ifndef IO_H
# define IO_H

# include "pair.h"
# include "pokemon.h"
# include "character.h"

class character;

void io_init_terminal(void);
void io_reset_terminal(void);
void io_display(void);
void io_handle_input(pair_t dest);
void io_queue_message(const char *format, ...);
void io_battle(character *aggressor, character *defender);
void io_encounter_pokemon();
void io_choose_starter();
void io_trainerBattle(npc* n);
void io_wildBattle(pokemon* enemy);
#endif
