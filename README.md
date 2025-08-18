# Tetris-c-


x = colonne de 0 à BOARD_WIDTH-1 (gauche → droite)

y = ligne de 0 à BOARD_HEIGHT-1 (haut → bas)

Origine en haut-gauche

Grille locale de la pièce (5×5)

indices (i, j) avec i = ligne 0..4, j = colonne 0..4

pivot au centre de ce 5×5, c’est (pivot_i, pivot_j) = (2,2)

shape[i][j] vaut 0 (vide), 1 (bloc), 2 (pivot)

Piece stocke :
	type (0..6),
	rotation (0..3),
	la position du pivot dans le board : (x, y).
