//********************************************************
// Auteur MP Pinaud
// date : 06/10/2020
// fichier: Position.h
// Interface de la classe repr�sentant une position
//********************************************************

#pragma once

class CPosition
{
public:

	//*************************************************************************
	// M�thode: CPosition
	// R�le: Constructeur de la classe point qui initialise l'abscisse, 
	//       l'ordonn�e et l'angle de la position
	// Param�tres d'entr�e:
	//		x: abscisse du point
	//		y : ordonn�e du point
	//      	theta : angle
	//*************************************************************************
	CPosition(const float x=0, const float y=0, const float theta = 0);



	//********************************************************
	// M�thode: deplacer
	// r�le: d�place la position
	// param�tres d'entr�e:
	//		d:  distance parcourue
	//********************************************************
	void deplacer(const float d);

	//********************************************************
    	// M�thode: orienter
    	// r�le: change l'angle par rapport � l'axe des abscisse
    	// param�tres d'entr�e:
    	//		theta:  nouvel angle
    	//********************************************************
    	void orienter(const float theta);

    	//********************************************************
    	// M�thode: coordonn�es
    	// r�le: indique l'abscisse et l'ordonn�e de la position
    	// param�tres de sortie:
	//		x: abscisse du point
	//		y : ordonn�e du point
    	//********************************************************
    	void coordonnees (float &x, float &y);

    	//********************************************************
    	// M�thode: orientation
    	// r�le: indique l'angle par rapport � l'axe des abscisses
    	// Retour: l'angle de la position
    	//********************************************************
    	float orientation();

	private:
		float abs; // abscisse
		float ord; // ordonn�e
		float angle; // angle par rapport � l'axe des abscisses
};
