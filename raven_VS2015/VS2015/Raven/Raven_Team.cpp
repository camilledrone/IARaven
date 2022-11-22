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
    m_members(NULL),
    m_icolor(RandInt(0,13))
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
    // TODO (voir comment gérer l'ExtraInfo pour pouvoir envoyer dans le message
    //// la cible à focus)
    //int tempSender = msg.Sender;
    //void* pTargetID = msg.ExtraInfo;

    ////handle any messages not handles by the goals
    //switch (msg.Msg)
    //{
    //case Msg_AllUnitsFocusTarget:
    //    debug_con << "All members of teams focussing : " << &pTargetID << "";
    //    // Checks if the sender of the message is the Leader of the team
    //    if (tempSender != Leader()->ID()) {
    //        debug_con << "You must be the leader of the team to order that !" << "";
    //        return true;
    //    }

    //    // Send a message to all team members telling which enemy they should focus
    //    for each (Raven_Bot * member in m_members)
    //    {
    //        Dispatcher->DispatchMsg(SEND_MSG_IMMEDIATELY,
    //            member->ID(),
    //            msg.Sender,
    //            Msg_FocusTarget,
    //            pTargetID);
    //    }

    //    // Send a message to the leader for the same reason
    //    Dispatcher->DispatchMsg(SEND_MSG_IMMEDIATELY,
    //        Leader()->ID(),
    //        msg.Sender,
    //        Msg_FocusTarget,
    //        pTargetID);


    //    return true;


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