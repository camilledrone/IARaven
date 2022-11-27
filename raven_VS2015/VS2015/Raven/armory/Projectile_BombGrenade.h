#ifndef BOMBGRENADE_H
#define BOMBGRENADE_H
#pragma warning (disable:4786)
//-----------------------------------------------------------------------------
//
//  Name:   BombGrenade.h
//
//  Author: Camille Boucher
//
//  Desc:   class to implement a bomb grenade type projectile
//
//-----------------------------------------------------------------------------
#include "Raven_Projectile.h"

class Raven_Bot;



class BombGrenade : public Raven_Projectile
{
private:

	//tests the trajectory of the shell for an impact
	void TestForImpact();

public:

	BombGrenade(Raven_Bot* shooter, Vector2D target);

	void Render();

	void Update();

};


#endif