#include "FollowLeaderGoal_Evaluator.h"
#include "../navigation/Raven_PathPlanner.h"
#include "../Raven_ObjectEnumerations.h"
#include "../lua/Raven_Scriptor.h"
#include "misc/Stream_Utility_Functions.h"
#include "Raven_Feature.h"

#include "Goal_Think.h"
#include "Raven_Goal_Types.h"
#include <Debug/DebugConsole.h>




//---------------- CalculateDesirability -------------------------------------
//-----------------------------------------------------------------------------
double FollowLeaderGoal_Evaluator::CalculateDesirability(Raven_Bot* pBot)
{
	if (pBot->GetTeam()) {
		if (pBot->GetTeam()->Leader() != pBot) {
			double Desirability = 0.04;

			Desirability *= m_dCharacterBias;

			return Desirability;
		}
		else {
			return 0;
		}
		
	}
	else {
		return 0;
	}
	
}

//----------------------------- SetGoal ---------------------------------------
//-----------------------------------------------------------------------------
void FollowLeaderGoal_Evaluator::SetGoal(Raven_Bot* pBot)
{
	Vector2D position;
	position = Vector2D(15, 15);
	position = pBot->GetTeam()->Leader()->Pos() - position;
	pBot->GetBrain()->AddGoal_FollowLeader(position);
}

//-------------------------- RenderInfo ---------------------------------------
//-----------------------------------------------------------------------------
void FollowLeaderGoal_Evaluator::RenderInfo(Vector2D Position, Raven_Bot* pBot)
{
	gdi->TextAtPos(Position, "EX: " + ttos(CalculateDesirability(pBot), 2));
}