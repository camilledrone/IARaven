#include "Raven_Team.h"
#include "Raven_Bot.h"

#include "Messaging/Telegram.h"
#include "Raven_Messages.h"
#include "Messaging/MessageDispatcher.h"

#include "Debug/DebugConsole.h"

#include <algorithm>

//-------------------------- ctor ---------------------------------------------
Raven_Team::Raven_Team(Raven_Bot* leader) :
    m_leader(leader),
    m_members(NULL)
{

}

//-------------------------------- dtor ---------------------------------------
//-----------------------------------------------------------------------------
Raven_Team::~Raven_Team()
{
    debug_con << "deleting team with leader " << m_leader->ID() << ")" << "";

    delete m_leader;
    for each (Raven_Bot * member in m_members)
    {
        delete member;
    }
}

//--------------------------- HandleMessage -----------------------------------
//-----------------------------------------------------------------------------
bool Raven_Team::HandleMessage(const Telegram& msg)
{
    // TODO
    ////first see if the current goal accepts the message
    //if (GetBrain()->HandleMessage(msg)) return true;

    ////handle any messages not handles by the goals
    //switch (msg.Msg)
    //{
    //case Msg_TakeThatMF:

    //    //just return if already dead or spawning
    //    if (isDead() || isSpawning()) return true;

    //    //the extra info field of the telegram carries the amount of damage
    //    ReduceHealth(DereferenceToType<int>(msg.ExtraInfo));

    //    //if this bot is now dead let the shooter know
    //    if (isDead())
    //    {
    //        Dispatcher->DispatchMsg(SEND_MSG_IMMEDIATELY,
    //            ID(),
    //            msg.Sender,
    //            Msg_YouGotMeYouSOB,
    //            NO_ADDITIONAL_INFO);
    //    }

    //    return true;

    //case Msg_YouGotMeYouSOB:

    //    IncrementScore();

    //    //the bot this bot has just killed should be removed as the target
    //    m_pTargSys->ClearTarget();

    //    return true;

    //case Msg_GunshotSound:

    //    //add the source of this sound to the bot's percepts
    //    GetSensoryMem()->UpdateWithSoundSource((Raven_Bot*)msg.ExtraInfo);

    //    return true;

    //case Msg_UserHasRemovedBot:
    //{

    //    Raven_Bot* pRemovedBot = (Raven_Bot*)msg.ExtraInfo;

    //    GetSensoryMem()->RemoveBotFromMemory(pRemovedBot);

    //    //if the removed bot is the target, make sure the target is cleared
    //    if (pRemovedBot == GetTargetSys()->GetTarget())
    //    {
    //        GetTargetSys()->ClearTarget();
    //    }

    //    return true;
    //}


    //default: return false;
    //}
    return false;
}

//--------------------------- AddMember ---------------------------------------
// 
// add a member to the team
//-----------------------------------------------------------------------------
void Raven_Team::AddMember(Raven_Bot* newMem) {
    // if newMem not already a member of the team
    if (!(std::find(m_members.begin(), m_members.end(), newMem) != m_members.end()))
    {
        m_members.push_back(newMem);
        newMem->SetTeam(this);
    }

}


//---------------------------- Describe ---------------------------------------
// 
// prints the leader and the members of the team
//-----------------------------------------------------------------------------
void Raven_Team::Describe() {
    debug_con << "Leader of the team is : " << "";
    debug_con << m_leader->ID() << "";
    debug_con << "Members of the team are : " << "";
    for each (Raven_Bot* member in m_members)
    {
        debug_con << member->ID() << "";
    }
}