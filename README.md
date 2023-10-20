# So_long

C'est le premier projet graphique du Cursus, nous pouvons choisir entre 3 options - FdF, Fractol et so_long - qui couvrent en général différents domaines, mais tous les 3 sont des projets graphiques. Le so_long consiste en un jeu, que nous codons à partir de zéro à l'aide de la bibliothèque graphique MiniLibx. Cela implique une série de validations de la carte passée en argument, des vérifications pour éviter les fuites de mémoire, l'ingénierie du jeu, la gestion des fenêtres, des événements, des cartes.

## Maps

Vous pouvez utiliser n'importe quel type de carte, à condition qu'elle respecte les règles ci-dessous :

 - La carte doit être un fichier .ber

 - Et ne peut contenir que ces caractères :
   
| OBJET | CHAR |
| :--: | :--: |
|1 |Mur|
|0 |Sol|
|C |Pièce|
|E |Sortie|
|P |Joueur|
|M| Ennemi|

 - La carte doit être rectangulaire et entourée des murs '1'.

 - La carte doit contenir au moins une sortie, un objet à collectionner et une position de départ.

 - La carte doit etre realisable (sortie et piece ateignable).


## Contrôles

|OBJET| CLÉ|
| :--: | :--: |
|W ou ⬆️ |Monter|
|A ou ⬅️ |Déplacement vers la gauche|
|S ou ⬇️ |Descendre|
|D ou ➡️ |Déplacement vers la droite|
|Esc ou ❌ |Fermer le jeu|

1.Utilisez WASD ou les touches fléchées pour vous déplacer.

2.Après avoir récupéré tous les sacs de pièces de monnaie, la sortie s'ouvre et vous pouvez vous échapper en bas.

3.Vous pouvez fermer le jeu en cliquant sur la croix rouge sur le cadre de la fenêtre ou en appuyant sur Esc.

### Exemple avec la map demomap.ber

![Exemple avec la map demomap.ber](https://github.com/Maxime2i/So_long/assets/43725047/4bb2fd3a-2fb4-402e-afdb-ab831669399b)
