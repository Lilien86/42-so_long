#!/bin/bash

# Répertoire contenant les fichiers .png que vous souhaitez convertir
repertoire_source="/nfs/homes/lauger/Documents/PROJECT/cercle 3/so_long/Pixelarium/newSprite"

# Convertit tous les fichiers .png en .xpm dans le répertoire source
for fichier_png in "$repertoire_source"/*.jpg; do
    [ -f "$fichier_png" ] || continue  # Vérifie si le fichier est valide
    nom_base=$(basename "$fichier_png" .jpg)
    convert "$fichier_png" "$repertoire_source/$nom_base.xpm"
    
    # Supprime le fichier .png après la conversion
    rm "$fichier_png"
done

