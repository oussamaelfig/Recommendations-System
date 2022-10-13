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
class Tableau
{

public:
    Tableau(int capacite_initiale = 4);
    Tableau(const Tableau &autre);
    ~Tableau();

   

    /**
     * description:  ajoute un élément à la fin.
     *
     * @param  			 une référence vers un paramètre de type T.
     */
    void ajouter(const T &element);

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
    void inserer(const T &element, int index = 0);

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
    int occurrence(const T &element) const;

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
    const T &operator[](int index) const;
    T &operator[](int index);
    bool operator==(const Tableau<T> &autre) const;
    Tableau<T> &operator=(const Tableau<T> &autre);

private:
    T *elements;
    int nbElements;
    int capacite;

    void triFusion(int min, int max);
    void fusionner(int min, int milieu, int max);
     // redimensionner un tablea en doublant sa capacite
    void redimensionner(int nouvCapacite);
    /**
     * description:  surcharge de l'opérateur d'affichage <<. Cet
     * 							 opérateur permettra d'afficher, sur une ligne,
     * 							 les éléments d'un tableau séparé par un
     * 							 point-virgule (;).
     */
    template <typename U>
    friend std::ostream &operator<<(std::ostream &, const Tableau<U> &);
};

template <class T>
Tableau<T>::Tableau(int capacite_initiale)
{
    capacite = capacite_initiale;
    nbElements = 0;
    elements = new T[capacite];
}

template <class T>
Tableau<T>::Tableau(const Tableau &autre)
{
    capacite = autre.capacite;
    nbElements = autre.nbElements;
    elements = new T[capacite];

    for (int i = 0; i < nbElements; i++)
    {
        elements[i] = autre.elements[i];
    }
}

template <class T>
Tableau<T>::~Tableau()
{
    delete[] elements;
    elements = nullptr;
}

template <class T>
void Tableau<T>::vider()
{
    nbElements = 0;
}

template <class T>
void Tableau<T>::redimensionner(int nouvCapacite)
{
    capacite = nouvCapacite;
    T *tmp = new T[capacite];
    for (int i = 0; i < nbElements; i++)
    {
        tmp[i] = elements[i];
    }

    delete[] elements;
    elements = tmp;
}

template <class T>
int Tableau<T>::taille() const
{
    return nbElements;
}

template <class T>
void Tableau<T>::ajouter(const T &item)
{
    if (nbElements >= capacite)
    {
        redimensionner(capacite * 2);
    }
    elements[nbElements++] = item;
}

template <class T>
void Tableau<T>::inserer(const T &element, int index)
{
    assert(index >= 0);
    // redimensionner
    if (nbElements == capacite)
    {
        redimensionner(capacite * 2);
    }
    // decaler
    for (int i = nbElements; i > index; i--)
    {
        elements[i] = elements[i - 1];
    }

    // ajouter
    elements[index] = element;
    nbElements++;
}

template <class T>
void Tableau<T>::enlever(int index)
{
    assert(index >= 0 && index <= nbElements);
    for (int i = index; i < nbElements - 1; i++)
    {
        elements[i] = elements[i + 1];
    }
    nbElements--;
}

template <class T>
int Tableau<T>::occurrence(const T &element) const
{
    int res = 0;
    for (int i = 0; i < nbElements; i++)
        if (element == elements[i])
            res++;
    return res;
}

template <class T>
void Tableau<T>::fusionner(int min, int milieu, int max)
{
    int longueur1 = milieu - min + 1;
    int longueur2 = max - milieu;

    T tab1[longueur1];
    T tab2[longueur2];

    for (int i = 0; i < longueur1; i++)
    {
        tab1[i] = elements[min + i];
    }
    for (int i = 0; i < longueur2; i++)
    {
        tab2[i] = elements[milieu + i + 1];
    }

    int i = 0;
    int j = 0;
    int k = min;

    while (i < longueur1 && j < longueur2)
    {
        if (tab1[i] <= tab2[j])
        {
            elements[k] = tab1[i];
            i++;
        }
        else
        {
            elements[k] = tab2[j];
            j++;
        }
        k++;
    }

    while (i < longueur1)
    {
        elements[k] = tab1[i];
        i++;
        k++;
    }
    
    while (j < longueur2)
    {
        elements[k] = tab2[j];
        j++;
        k++;
    }
}

template <class T>
void Tableau<T>::triFusion(int min, int max)
{
    if (min < max)
    {
        int milieu = (min + max) / 2;
        triFusion(min, milieu);
        triFusion(milieu + 1, max);
        fusionner(min, milieu, max);
    }
}

template <class T>
void Tableau<T>::unique()
{
    // tri fusion -->O(nlogn) et on traverse le tableau par la suite delete doublons.
    if (taille() <= 1)
    {
        return;
    }
   // triRapide(0, taille() - 1);
    triFusion(0, taille() - 1);
    T temp = elements[0];
    T *buff = new T[capacite];
    int j = 0;
    buff[j] = elements[j];
    nbElements = 0;
    for (int i = 1; i < capacite; i++)
    {
        if (buff[j] != elements[i])
        {
            buff[j + 1] = elements[i];
            ++nbElements;
            ++j;
        }
    }
    delete[] elements;
    elements = buff;
}

template <class T>
const T &Tableau<T>::operator[](int index) const
{
    assert(index < nbElements);
    assert(index >= 0);
    return elements[index];
}

template <class T>
T &Tableau<T>::operator[](int index)
{
    assert(index < nbElements);
    assert(index >= 0);
    return elements[index];
}

template <class T>
Tableau<T> &Tableau<T>::operator=(const Tableau<T> &autre)
{
    if (this == &autre)
    {
        return *this;
    }
    nbElements = autre.nbElements;
    if (capacite < autre.nbElements)
    {
        delete[] elements;
        capacite = autre.capacite;
        elements = new T[capacite];
    }

    for (int i = 0; i < nbElements; i++)
    {
        elements[i] = autre.elements[i];
    }

    return *this;
}

template <class T>
bool Tableau<T>::operator==(const Tableau<T> &autre) const
{
    // if t1==t2
    if (this == &autre)
    {
        return true;
    }
    if (nbElements != autre.nbElements)
    {
        return false;
    }
    for (int i = 0; i < nbElements; i++)
    {
        if (elements[i] != autre.elements[i])
        {
            return false;
        }
    }

    return true;
}

template <typename U>
std::ostream &operator<<(std::ostream &os, const Tableau<U> &tab)
{

    for (int i = 0; i < tab.nbElements; i++)
    {
        os << tab.elements[i] << ";";
    }
    return os;
}

#endif
