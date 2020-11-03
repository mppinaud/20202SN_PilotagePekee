//********************************************************
// Auteur MP Pinaud
// date : 06/10/2020
// fichier: Position.cpp
// Code des fonctions de la classe repr�sentant une position
// Historique :
//********************************************************
#include <iostream>
using namespace std;
#include "CPosition.h"



//*************************************************************************
// M�thode: CPosition
// R�le: Constructeur de la classe point qui initialise l'abscisse et
//       l'ordonn�e et l'angle d'une position
// Param�tres d'entr�e:
//		x: abscisse du point
//		y : ordonn�e du point
//              theta : angle
//*************************************************************************
CPosition::CPosition(const float x, const float y, const float theta)
{
	this->abs = x;
	this->ord = y;
	this->angle = theta;
}



//********************************************************
// M�thode: deplacer
// r�le: d�place la position
// param�tres d'entr�e:
//		d:  distance parcourue
//********************************************************
void CPosition::deplacer(const float d)
{
	this ->abs = this ->abs + d * cos(this->angle);
	this ->ord = this ->ord + d * sin(this->angle);
}

//********************************************************
// M�thode: orienter
// r�le: change l'angle par rapport � l'axe des abscisse
// param�tres d'entr�e:
//		theta:  nouvel angle
//********************************************************
void CPosition::orienter(const float theta)
{
	this ->angle = this ->angle + theta;
}


//********************************************************
// M�thode: coordonn�es
// r�le: indique l'abscisse et l'ordonn�e de la position
// param�tres de sortie:
//		x: abscisse du point
//		y : ordonn�e du point
//********************************************************
    void CPosition::coordonnees (float &x, float &y)
    {
        x = this->abs;
        y = this->ord;
    }

//********************************************************
// M�thode: orientation
// r�le: indique l'angle par rapport � l'axe des abscisses
// Retour: l'angle de la position
//********************************************************
    float CPosition::orientation()
    {
        return (this->angle);
    }