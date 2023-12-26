#!/bin/bash

# Vérifie si ImageMagick est installé
if ! command -v convert &>/dev/null; then
  echo "ImageMagick n'est pas installé. Veuillez l'installer en utilisant 'sudo apt-get install imagemagick'."
  exit 1
fi

# Nom du fichier d'entrée
fichier_entree="void.xpm"

# Nom du fichier de sortie
fichier_sortie="void_r.xpm"

# Redimensionne l'image avec ImageMagick
convert "$fichier_entree" -resize 100x100\> "$fichier_sortie"

echo "L'image a été redimensionnée avec succès et enregistrée sous le nom '$fichier_sortie'."

