//******************************************************** 
// Auteur MP Pinaud
// date : 07/10/2020
// fichier: CRobotPekee.cpp
// Enonc� : Sprint 2

// Historique :03/11/2020  Enonc� Sprint 3
// Modification ds m�thodes de d�placement du robot pour suivre sa position
//********************************************************
#include <iostream>
using namespace std;

#include "..\include\CRobotPekee.h"

//********************************************************
// m�thode: CRobotPekee
// r�le: Constructeur de la classe CRobotPekee. Il effectue la 
//			connexion au robot r�el ou au robot simul�
// param�tres d'entr�e:

//  adrIP : adresse  pour se connecter au robot r�el 
//			ou simul� (dans ce cas vaut localhost)
//  n    : nom du robot
//********************************************************
CRobotPekee::CRobotPekee( char * n, char * adrIP)

{	

	strcpy (this->nom, n);
	
	strcpy (this->adresseIP, adrIP);
	if (this-> Connect(adrIP,n))
		this->connexion = true;
	else
		this->connexion = false;
}

//********************************************************
// m�thode: ~CRobotPekee
// r�le: Destructeur de la classe CRobotPekee. Il effectue la 
//			deconnexion au robot r�el ou au robot simul�
//********************************************************
CRobotPekee::~CRobotPekee(void)
{
	if (this->connexion)
	{
		if (this->Disconnect())
			this->connexion = false;
	}
}


//**********************************************************************
// Fonction : position
// R�le : indique la poistion courante du robot
// sortie:	abs : noabscisse, ord : ordonn�e, angle en radian
//**********************************************************************
void CRobotPekee::donner_position(float &abs, float & ord, float & angle)
{
		this->position.coordonnees(abs,ord);

		angle=this->position.orientation();

}

//********************************************************
// m�thode: avancer
// r�le: avance le robot �
//********************************************************
void CRobotPekee::avancer()
{
	float x= 0,y= 0,angle = 0;

	this->ResetPosition();
	this->SetSpeed(100, 0);
	Sleep(300);
	this->GetPosition(x,y,angle);
	Sleep(300);

	this->position.deplacer(x);
	
}
//********************************************************
// m�thode: reculer
// r�le: reculer le robot 
//********************************************************
void CRobotPekee::reculer()
{
	float x= 0,y= 0,angle = 0;

	this->ResetPosition();
	this->SetSpeed(-100, 0);
	Sleep(300);
	this->GetPosition(x,y,angle);
	Sleep(300);

	this->position.deplacer(x);
}

//********************************************************
// m�thode: tournerG
// r�le: fait tourner le robot vers la gauche
//********************************************************
void CRobotPekee::tournerG()
{

	float x= 0,y= 0,angle = 0;

	this->ResetPosition();
	this->SetSpeed(0, -45);
	Sleep(300);
	this->GetPosition(x,y,angle);
	Sleep(300);

	this->position.orienter(angle);
}
	


//********************************************************
// m�thode: tournerD
// r�le: fait tourner le robot vers la droite
//********************************************************
void CRobotPekee::tournerD()
{
	float x= 0,y= 0,angle = 0;

	this->ResetPosition();
	this->SetSpeed(0, 45);
	Sleep(300);
	this->GetPosition(x,y,angle);
	Sleep(300);

	this->position.orienter(angle);
	
}

//********************************************************
// m�thode: avancer
// r�le: avance le robot sur une distance
// param�tres d'entr�e:
//	distance : distance � parcourir en m
//	vitesseT : vitesse de translation en mm/s 
//********************************************************
void CRobotPekee::avancer(float distance, int vitesseT)
{
	float X, Y;		// position en m�tres
	float angle ;	//  angle de rotation compris entre -2PI et 2PI
	bool res;
	// on r�initialise la position 
	res = this->SetPosition(0,0,0);
	Sleep(100);
	X = 0;
	while( abs(X) < distance)  // valeur absolue de X
	{
		this->SetSpeed(vitesseT,0);
		Sleep(100);
		bool  res = this->GetPosition (X,Y,angle);
		Sleep(150);
	}

	this->position.deplacer(X);
}

//********************************************************
// m�thode: reculer
// r�le: fait reculer le robot sur une distance
// param�tres d'entr�e:
//	distance : distance � parcourir en m
//	vitesseT : vitesse de translation en mm/s 
//********************************************************
void CRobotPekee::reculer (float distance, int vitesseT)
{
	
	this->avancer(distance, -vitesseT);
}

//**********************************************************************
// Fonction : clignoter_robot
// R�le : fait clignoter le robot
// Entr�es :	nb : nombre de fois o� le robot clignote
//**********************************************************************
void CRobotPekee::clignoter(int nb)
{
	int i; 
	for (i = 0; i < nb; i++)
	{
		this->LedOn();
		Sleep(200);
		this->LedOff();
		Sleep(200);
	}
}

//********************************************************
// m�thode: est_connecte
// r�le: indique si la connexion au robot reel ou simul� 
//       est effective
//********************************************************
bool CRobotPekee::est_connecte(void)
{
	return this->connexion;
}


