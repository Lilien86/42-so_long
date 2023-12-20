#!/bin/bash

# Vérifie si ImageMagick est installé
if ! command -v convert &>/dev/null; then
  echo "ImageMagick n'est pas installé. Veuillez l'installer en utilisant 'sudo apt-get install imagemagick'."
  exit 1
fi

# Crée un dossier "modif" s'il n'existe pas déjà
mkdir -p modif

# Parcours tous les fichiers XPM du dossier actuel
for fichier_entree in *.xpm; do
  if [ -f "$fichier_entree" ]; then
    # Crée le nom de fichier de sortie dans le dossier "modif"
    fichier_sortie="modif/${fichier_entree%.*}_100x100.xpm"

    # Redimensionne l'image à exactement 100x100 pixels avec ImageMagick
    convert "$fichier_entree" -resize 100x100! "$fichier_sortie"

    echo "L'image '$fichier_entree' a été redimensionnée avec succès à exactement 100x100 pixels et enregistrée dans le dossier 'modif' sous le nom '$fichier_sortie'."
  fi
done

echo "Toutes les images XPM ont été redimensionnées avec succès à exactement 100x100 pixels et enregistrées dans le dossier 'modif'."

