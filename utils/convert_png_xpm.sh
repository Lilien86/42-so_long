#!/bin/bash

# Répertoire contenant les fichiers .png que vous souhaitez convertir
repertoire_source="/home/lilien/Documents/42-so_long/Pixelarium - GrassLands/Pack content/Sprites/Tileset"

# Convertit tous les fichiers .png en .xpm dans le répertoire source
for fichier_png in "$repertoire_source"/*.png; do
    [ -f "$fichier_png" ] || continue  # Vérifie si le fichier est valide
    nom_base=$(basename "$fichier_png" .png)
    convert "$fichier_png" "$repertoire_source/$nom_base.xpm"
    
    # Supprime le fichier .png après la conversion
    rm "$fichier_png"
done

