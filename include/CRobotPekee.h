//******************************************************** 
// Auteur MP Pinaud
// date : 07/09/2020
// fichier: Robot.h
// Interface de la classe CRobotPekee qui am�liore le pilotage
// d'un robot Pekee
// Enonc� : Sprint2

// Historique :03/11/2020 : Enonc� Sprint 3
// Ajout de laposition pour suivre le robot
//********************************************************
#pragma once
#include "libRobotPekee.h"

#include "CPosition.h"


class CRobotPekee : protected WRobotPekee
{

public:
	//********************************************************
	// m�thode: CRobotPekee
	// r�le: Constructeur de la classe CRobotPekee. Il effectue la 
	//			connexion au robot r�el ou au robot simul�
	// param�tres d'entr�e:
	//  adrIP : adresse  pour se connecter au robot r�el 
	//			ou simul� (dans ce cas vaut localhost)
	//  n    : nom du robot
	//********************************************************
	CRobotPekee( char * n = "Pekee", char * adrIP = "localhost");


	//********************************************************
	// m�thode: ~CRobotPekee
	// r�le: Destructeur de la classe CRobotPekee. Il effectue la 
	//			deconnexion au robot r�el ou au robot simul�
	//********************************************************
	~CRobotPekee(void);
	
	

	//********************************************************
	// m�thode: est_connecte
	// r�le: indique si la connexion au robot reel ou simul� 
	//       est effective
	//********************************************************
	bool est_connecte(void);

	//**********************************************************************
	// M�thode : position
	// R�le : indique la poistion courante du robot
	// Sorties:	abs : noabscisse, ord : ordonn�e, angle en radian
	//**********************************************************************
	void donner_position(float &abs, float &ord, float &angle);
	
	//********************************************************
	// m�thode: avancer
	// r�le: avance le robot 
	//********************************************************
	void avancer();

	//********************************************************
	// m�thode: reculer
	// r�le: reculer le robot 
	//********************************************************
	void reculer();

	//********************************************************
	// m�thode: tournerG
	// r�le: fait tourner le robot vers la gauche
	//********************************************************
	void tournerG();

	//********************************************************
	// m�thode: tournerD
	// r�le: fait tourner le robot vers la droite
	//********************************************************
	void tournerD();

	//********************************************************
	// m�thode: avancer
	// r�le: avance le robot sur une distance
	// param�tres d'entr�e:
	//	distance : distance � parcourir en m
	//	vitesseT : vitesse de translation en mm/s 
	//********************************************************
	 void avancer(float distance, int vitesseT= 100);

	 //********************************************************
	// m�thode: reculer
	// r�le: fait reculer le robot sur une distance
	// param�tres d'entr�e:
	//	distance : distance � parcourir en m
	//	vitesseT : vitesse de translation en mm/s 
	//********************************************************
	 void reculer(float distance, int vitesseT= 100);

	//**********************************************************************
	// Fonction : clignoter_robot
	// R�le : fait clignoter le robot
	// Entr�es :	nb : nombre de fois o� le robot clignote
	//**********************************************************************
	void clignoter(int nb);

	

	
private :

	bool connexion;		// indique si la connexion au robot s'est faite

	char nom [15];		// nom du robot
	char adresseIP[15];	// adresse de connexion au robot

	CPosition position; // position courante du robot

};
