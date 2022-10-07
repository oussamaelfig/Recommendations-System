/**
 * Squelette pour classe Membre.
 * TP1 -- Tableau dynamique générique
 * UQAM / Département d'informatique
 * INF3105 - Structures de données et algorithmes (Automne 2022)
 */

#if !defined(__MEMBRE_H__)
#define __MEMBRE_H__

#include <string>
#include "tableau.h"

class Membre
{
public:
	Membre();
	Membre(std::string id_);
	~Membre();

	/**
	 * description:   retourne l'id du membre courant. Cette fonction ne doit
	 * 							 pas modifier le membre courant.
	 *
	 * @return  			 l'id du membre courant, un objet de type std::string.
	 */
	std::string identifiant() const;

	/**
	 * description:   retourne un objet de type Tableau<std::string> les
	 * 							 favoris du membre courant. Cette fonction ne doit pas
	 * 							 modifier le membre courant.
	 *
	 * @return  			 un objet de type Tableau<std::string> avec les favoris
	 * 							 du membre courant.
	 */
	Tableau<std::string> favoris() const;

	/**
	 * description:   ajoute un nouveau contenu (série ou film) au favoris.
	 *
	 * @param 				 une référence vers un string qui représente une
	 * 							 série ou un film. Ce paramètre ne doit pas être
	 * 							 modifé par la fonction.
	 */
	void ajouterFavori(const std::string &content);

	/**
	 * description:   retourne un objet de type Tableau<std::string> qui
	 * 							 contient les favoris du membre 'autre' qui ne sont
	 * 							 pas des favoris du membre courant.
	 * 							 Cette fonction ne doit pas modifier le membre courant.
	 *
	 * @param  		   une référence vers un objet de type Membre. Ce paramètre
	 * 							 ne doit pas être modifé par la fonction.
	 *
	 * @return  		   un objet de type Tableau<std::string> contenant des
	 * 							 favoris du membre 'autre' qui ne sont pas des favoris du
	 * 							 membre courant.
	 */
	Tableau<std::string> suggestion(const Membre &autre) const;

	/**
	 * description:   retourne un objet de type Tableau<std::string> qui contient
	 * 							 les favoris de tous les membres qui ne sont pas des favoris
	 * 							 du membre courant.
	 * 							 Attention, le tableau retourné ne contient pas de contenu
	 * 							 en double ! Chaque série ou film ne doit apparaître qu'une
	 * 							 seule fois.
	 *    						 Cette fonction ne doit pas modifier le membre courant.
	 *
	 * @param         une référence vers un objet de type Tableau<Membre> qui
	 * 							 contient plusieurs éléments de type Membre.
	 * 							 Attention, le membre courant peut en faire partie !
	 *
	 * @return  		   un objet de type Tableau<std::string> contenant les favoris
	 * 							 de tous les membres qui ne sont pas des favoris du membre
	 * 							 courant.
	 */
	Tableau<std::string> suggestion(const Tableau<Membre> &com) const;

	Tableau<std::string> favs;

private:
	std::string id;

	/**
	 * description:  surcharge des opérateurs de comparaisons ==, !=, <= et >=
	 * 							 Deux membres sont égaux si leurs id sont égaux. Ils sont
	 * 							 donc différents si leur id sont différents. De même,
	 * 							 un membre A est <= (respectivement >=) à un membre B ssi
	 * 							 A.id <= B.id (respectivement A.id >= B.id).
	 * 							 Les comparaisons ==, !=, <= et >= entres les ids sont au
	 * 							 sens des compraisons des string.
	 *
	 * @param        une référence vers un objet de type Membre. Ce paramètre
	 * 							 ne doit pas être modifé par la surcharge des opérateurs.
	 *
	 * @return       un booléen indiquant si les opérateurs ==, <= et >= sont
	 * 							 vérifiés.
	 */
	friend bool operator==(const Membre &, const Membre &);
	friend bool operator!=(const Membre &, const Membre &);
	friend bool operator<=(const Membre &, const Membre &);
	friend bool operator>=(const Membre &, const Membre &);
};

Membre::Membre()
{
}

Membre::Membre(std::string id_) : id(id_)
{
}

Membre::~Membre()
{
}

bool operator==(const Membre &un, const Membre &deux)
{
	return (un.id == deux.id);
}

bool operator!=(const Membre &un, const Membre &deux)
{
	return (un.id != deux.id);
}

bool operator<=(const Membre &un, const Membre &deux)
{
	return (un.id <= deux.id);
}

bool operator>=(const Membre &un, const Membre &deux)
{
	return (un.id >= deux.id);
}

std::string Membre::identifiant() const
{
	return this->id;
}
Tableau<std::string> Membre::favoris() const
{
	return this->favs;
}

void Membre::ajouterFavori(const std::string &content)
{
	favs.ajouter(content);
}

Tableau<std::string> Membre::suggestion(const Membre &autre) const
{
	Tableau<std::string> resultat;

	for (int i = 0; i < autre.favs.taille(); i++)
	{
		int j;
		for (j = 0; j < this->favs.taille(); j++)
		{
			if (autre.favs[i] == this->favs[j])
			{
				break;
			}
		}
		if (j == this->favs.taille())
		{
			resultat.ajouter(autre.favs[i]);
		}
	}

	return resultat;
}


Tableau<std::string> Membre::suggestion(const Tableau<Membre> &com) const
{
	// À compléter
	Tableau<std::string> resultat;
	Tableau<std::string> buff;
	for (int i = 0; i < com.taille(); i++)
	{
		buff = suggestion(com[i]);
		for (int j = 0; j < buff.taille(); j++)
		{
			if(resultat.occurrence(buff[j]) == 0 ){
				resultat.ajouter(buff[j]);
			}
		}
	}
	return resultat;
}

#endif
