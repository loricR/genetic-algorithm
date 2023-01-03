# projetRN40

# Rapport
https://docs.google.com/document/d/1sEoBOtt0RUNII2THmEehxezxlCvopfiUlR470SkHu3o/edit?usp=sharing

#Lexique

== correspond au test d'égalité

!= correspond au test "différent"

% correspond à l'opération "reste de la division euclidienne" ou "modulo"

rand(), fonction qui retourne un entier aléatoire

ajoutt_indiv(Individu, Bit) -> Individu, Fonction qui ajoute un Bit en tête d'une liste de Bits

supprt_indiv(Individu) -> Individu, Fonction qui supprime le premier élément de l'Individu

ajoutq_indiv(Individu, Bit) -> Individu, Fonction qui ajoute un Bit en fin d'une liste de Bits

supprq_indiv(Individu) -> Individu, Fonction qui supprime le dernier élément de l'Individu

vide_indiv(Individu) -> booléen, Fonction qui retourne vrai si Individu est vide

creer_indiv() -> Individu, Fonction qui retourne un Individu vide

val_indiv(Individu) -> Bit, Fonction qui retourne la valeur d'un Individu

suc_indiv(Individu) -> Individu, Fonction qui retourne l'élément suivant


ajoutt_pop(Population, Individu) -> Population, Fonction qui ajoute un Individu en tête d'une liste d'Individus

supprt_pop(Population) -> Individu, Fonction qui supprime le premier élément de la Population

ajoutq_pop(Population, Individu) -> Population, Fonction qui ajoute un Individu en fin d'une liste d'Individus

supprq_pop(Population) -> Individu, Fonction qui supprime le dernier élément de la Population

vide_pop(Population) -> booléen, Fonction qui retourne vrai si une Population est vide

creer_pop() -> Population, Fonction qui retourne une Population vide

val_pop(Population) -> Individu, Fonction qui retourne la valeur d'une Population

suc_pop(Population) -> Population, Fonction qui retourne l'élément suivant





		



initPop(taillePop : entier) -> Population
Donnees: taillePop un entier representant la taille voulue de la population
Resultat: Population (une liste d'Individus) generee aleatoirement
Lexique: 
     creer_pop() -> Population, Fonction qui retourne une Population vide
     ajoutt_pop(Population, Individu) -> Population, Fonction qui ajoute un Individu 
     en tete d'une liste d'Individus
     initIndiv_recursif(longIndiv : entier) -> Individu, Fonction qui retourne 
     un Individu de taille longIndiv


	Si taillePop == 0 Alors 
		initPop(taillePop) = creer_pop()
	Sinon
		initPop(taillePop) = ajoutt_pop(initPop(taillePop-1), initIndiv_recursif(8))
	Fsi


triQualiteDec(p1 : Population, p2 : Population) -> void
Donnees: p1 la population a trier et p2 le dernier individu de la population a trier
Resultat: Population triee par qualite decroissante des Individus
Lexique: 
     partition(Population p1, Population p2) la fonction qui echange des individus dans 
     une population sous certaines conditions
     creer_pop() -> Population, Fonction qui retourne une Population vide
     suc_pop(Population) -> Population, Fonction qui retourne l'element suivant


	Si p1 != p2 Alors
		pivot = partition(p1,p2)
		Si pivot != creer_pop() et suc(pivot) != creer_pop() Alors
			triQualiteDec(p1,p2) = triQualiteDec(suc_pop(pivot), p2)
		Sinon Si pivot != creer_pop() et p1 != pivot Alors
			triQualiteDec(p1,p2) = triQualiteDec(p1, pivot)
		FSi
	Fsi
		

partition(p1 : Population, p2 : Population) -> Population
Donnees: p1 et p2 deux individus d'une population
Resultat: Population avec certains individus echanges
Lexique: 
     qualiteIndiv(Individu i) la fonction qui renvoie la qualite associee a un individu
     creer_pop() -> Population, Fonction qui retourne une Population vide
     val_pop(Population) -> Individu, Fonction qui retourne la valeur d'une Population
	 suc_pop(Population) -> Population, Fonction qui retourne l'element suivant


	pivot = p1
	actuel = p1
	Tant que actuel != creer_pop() et actuel != p2 Faire
		Si(qualiteIndiv(val_pop(actuel))) > qualiteIndiv(val_pop(p2))) Alors
			pivot = p1
			temp = val_pop(p1)
			val_pop(p1) = val_pop(actuel)
			val_pop(actuel) = temp
		FSi
		actuel = suc_pop(actuel)
	FTantQue
	temp = val_pop(p1)
	val_pop(p1) = val_pop(p2)
	val_pop(p2) = temp
	
	partition(p1,p2) = pivot



meilleursIndiv(l : Population, tSelect : entier) -> Population
Donnees: l la Population de base
         tSelect l'entier correspondant a l'endroit ou il faut tronquer la Population
Resultat: Population des meilleurs Individus en tronquant la liste et en la completant 
par recopie des tSelect premiers elements
Lexique:
     TriQualiteDec(Population) -> Population, Fonction qui trie une Population par 
     ordre decroissant de qualite d'Individu
     vide_pop(Population) -> booleen, Fonction qui retourne vrai si une Population est vide
     creer_pop() -> Population, Fonction qui retourne une Population vide
     ajoutq_pop(Population, Individu) -> Population, Fonction qui ajoute un Individu
     en fin d'une liste d'Individus
     val_pop(Population) -> Individu, Fonction qui retourne la valeur d'une Population
     suc_pop(Population) -> Population, Fonction qui retourne l'element suivant
     tete_pop(Population) -> Population, Fonction qui retourne la tete d'une Population


	l = triQualiteDec(l)
	i = creer_pop()
	TantQue tSelect > 0 Faire
		i = ajoutq_pop(i, val(l))
		l = suc(l)
		tSelect = tSelect-1
	FTantQue
	TantQue non(vide_pop(l)) Faire
		TantQue non(vide_pop(i)) et non(vide_pop(l)) Faire
        		val_pop(l) = val_pop(i)
        		i = suc_pop(i)
        		l = suc_pop(l)
		FTantQue
		i = tete_pop(i)
   	 FTantQue



croiserPop(p : Population, pCroise : reel) -> Population
Donnees: p la Population qu'il faut croiser
         pCroise la probabilite de croisement pour un Individu
Resultat: Population constituee d'Individus selectionnes aleatoirement
deux a deux dans la Population de base et croises entre eux
Lexique : 
     creer_indiv() -> Individu, Fonction qui retourne un Individu vide
     randIndiv(Population) -> Individu, Fonction qui choisit un individu aleatoire 
     dans une Population
     compteur_pop(Population) -> Entier, Fonction qui mesure la taille de la population p
     creer_pop() -> Population, Fonction qui retourne une Population vide
     ajoutq_pop(Population, Individu) -> Population, Fonction qui ajoute un Individu 
     en fin d'une liste d'Individus
     croiserListes(reel, Individu, Individu) -> Individu, Fonction qui renvoie un Individu
     comme melange des deux Individus en parametres


	i = creer_indiv()
	j = creer_indiv()
	p2 = creer_pop()
	TantQue compteur_pop(p2) != compteur_pop(p) Faire
		Faire 
			i = randIndiv(p)
			j = randIndiv(p)		
		TantQue i == j 			
		FinFaireTantQue

		p2 = ajoutq_pop(p2, croiserListes(pCroise, i, j)
	FTantQue
