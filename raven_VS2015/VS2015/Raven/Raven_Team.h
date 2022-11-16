#ifndef RAVEN_TEAM_H
#define RAVEN_TEAM_H
//-----------------------------------------------------------------------------
//
//  Name:   Raven_Team.h
//
//  Author: Tristan Badana
//
//  Desc: Team of Raven Bot
//-----------------------------------------------------------------------------

#include "game/MovingEntity.h"
#include "misc/utils.h"
#include "Raven_TargetingSystem.h"

struct Telegram;
class Raven_Bot;


class Raven_Team
{
private:

	//Leader of the team
	Raven_Bot*						m_leader;
	//Members of the team
	std::vector<Raven_Bot*>			m_members;
	//Team color
	int								m_icolor;


	//teams shouldn't be copied, only created or respawned
	Raven_Team(const Raven_Team&);
	Raven_Team& operator=(const Raven_Team&);


public:

	Raven_Team(Raven_Bot* leader);
	virtual ~Raven_Team();

	bool         HandleMessage(const Telegram& msg);
	void         Write(std::ostream& os)const {/*not implemented*/ }
	void         Read(std::ifstream& is) {/*not implemented*/ }

	void		 AddMember(Raven_Bot* newMem);
	void		 Describe();

	//methods for accessing attribute data
	Raven_Bot*					Leader()const { return m_leader; }
	std::vector<Raven_Bot*>		Members()const { return m_members; }
	int							Color()const { return m_icolor; }

};




#endif