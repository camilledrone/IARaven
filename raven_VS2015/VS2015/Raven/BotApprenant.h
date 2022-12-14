#pragma once
#include "Raven_Bot.h"
#include "Raven_Game.h"
#include "./code_source_reseaux_neuronnes/CData.h"
#include "./code_source_reseaux_neuronnes/CNeuralNet.h"

class BotApprenant : public Raven_Bot
{
private:
	CNeuralNet m_ModeleAppris;

public:

	BotApprenant(Raven_Game* world, Vector2D pos);
	~BotApprenant();


	void Update();


};

