/** 
 * Squelette pour classe générique Tableau<T>.
 * TP1 -- Tableau dynamique générique
 * UQAM / Département d'informatique
 * INF3105 - Structures de données et algorithmes (Automne 2022)
 */

#if !defined(_TABLEAU___H_)
#define _TABLEAU___H_

#include <assert.h>

template <class T>
class Tableau{

  public:
    Tableau(int capacite_initiale=4);
		Tableau(const Tableau & autre);
    ~Tableau();

	  /** 
		 * description:  ajoute un élément à la fin.
		 *
		 * @param  			 une référence vers un paramètre de type T.
		 */
    void ajouter(const T & element);
  
		/** 
		 * description:  retourne le nombre d'éléments dans le 
		 * 							 tableau. Cette fonction ne doit pas modifier 
		 * 							 le tableau courant.
		 *
		 * @return       un entier représentant la taille du tableau 
		 *               courant.
		 */
    int taille() const;

		/** 
		 * description:  insère un élément à la position 'index'. Les
		 * 							 éléments à partir de index sont décalés d'une 
		 * 							 postion vers la droite.
		 *
		 * @param        - une référence vers un paramètre de type T.
		 * 							 - un entier représentant la position où sera 
		 * 							 inséré l'élément.
		 */
    void inserer(const T & element, int index = 0);

		/** 
		 * description:  enlève un élément à la position 'index'. Les
		 * 							 éléments après index sont décalés d'une postion
		 * 							 vers la gauche.
		 *
		 * @param        un entier représentant la position d'où sera 
		 * 						 	 enlevé l'élément.
		 */
    void enlever(int index = 0);

		/** 
		 * description:  compte le nombre d'occurrence d'un élément dans
		 * 							 le tableau. Cette fonction ne doit pas modifier 
		 * 							 le tableau courant. 
		 *
		 * @param        une référence vers un paramètre de type T.
		 *
		 * @return       un entier représentant le nombre de fois que
		 * 							 l'élément apparaît dans le tableau courant.
		 */
    int occurrence(const T & element) const;

		/**
		 * description:  vide le tableau sans libérer la mémoire.
		 */ 
		void vider();

		/**
		* description:   élimine tous les doublants dans le tableau
		* 							 courant.
		*/
		void unique();

		/**
		 * description:  surcharge des opérateurs
		 * 									- d'accès []
		 * 									- d'accès et de mondification []
		 * 									- d'égalité ==
		 * 									- d'affectation de tableau =
		 */
    const T & operator [] (int index) const;
    T & operator [] (int index);
    bool operator == (const Tableau<T> & autre) const;
    Tableau<T> & operator = (const Tableau<T> & autre);

  private:
    T * elements;
    int nbElements;
    int capacite;

	/**
	 * description:  surcharge de l'opérateur d'affichage <<. Cet 
	 * 							 opérateur permettra d'afficher, sur une ligne, 
	 * 							 les éléments d'un tableau séparé par un 
	 * 							 point-virgule (;).
	 */
	template <typename U>	
	friend std::ostream & operator << (std::ostream &, const Tableau<U> &);
};

template <class T>
Tableau<T>::Tableau(int capacite_initiale) {
	// À compléter
}

template <class T>
Tableau<T>::Tableau(const Tableau & autre) {
	// À compléter
}

template <class T>
Tableau<T>::~Tableau() {
	// À compléter
}

template <class T>
void Tableau<T>::vider() {
	// À compléter
}

template <class T>
void Tableau<T>::redimensionner(int nouvCapacite){
	// À compléter
}

template <class T>
int Tableau<T>::taille() const {
	// À compléter
}

template <class T>
void Tableau<T>::ajouter(const T & item) {
	// À compléter
}

template <class T>
void Tableau<T>::inserer(const T & element, int index) {
	// À compléter
}

template <class T>
void Tableau<T>::enlever(int index) {
	// À compléter
}

template <class T>
int Tableau<T>::occurrence(const T & element) const {
	// À compléter
}

template <class T>
void Tableau<T>::unique() {
	// À compléter
}

template <class T>
const T & Tableau<T>::operator [] (int index) const {
	// À compléter
}

template <class T>
T & Tableau<T>::operator [] (int index) {
	// À compléter
}

template <class T>
Tableau<T> & Tableau<T>::operator = (const Tableau<T> & autre) {
	// À compléter
	return * this;
}

template <class T>
bool Tableau<T>::operator == (const Tableau<T> & autre) const {
	// À compléter
}

template <typename U>
std::ostream & operator << (std::ostream & os, const Tableau<U> & tab) {
	// À compléter
}

#endif
