// Character Class

#include "defs.h"


class character 
{
	public:
		character(char_stats const & statSeed);

		// load_character

		void copy_cstat(char_stats & to_copy) const;
		void copy_rstat(root_stats & to_copy) const;
		void copy_bstat(battle_stats & to_copy) const;

		int equip_item(const int slot, item const & to_equip);
		int remove_item(const int slot);
		//copy_items
		int set_skill(const int slot, skill const & to_add);
		int remove_skill(const int slot);
		//copy_skills

		int displayBasic();
		int displayStats();
		int displayDerived();
		int displayEquip();
		int displaySkill();
		
		//act
		//react
		//move
		
		
	private:
		void update_stats();

		char_stats    cstats;
		root_stats    rstats; 
		battle_stats  bstats;
		item          equip[EQUIP];
		skill         skills[SKILLS];
};

struct cnode {
	cnode();
  character * current_char; 
	cnode * next;
};

class char_list
{
	public:
		char_list();
		~char_list();
		int add_character(character const & to_add);
		int remove_character(character const & to_remove);
		int find_character(character const & match) const;
	
	private:

};
