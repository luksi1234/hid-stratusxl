!#/bin/bash

DIRECTORY=/home/pi/RetroPie-Setup/scriptmodules/supplementary
FILE=/tmp/repropie_install.sh

echo Download and install module script for Retropie Setup

if [ -d "$DIRECTORY" ]; then
  echo "$DIRECTORY does exist."
  wget -O /tmp/repropie_install.sh https://github.com/luksi1234/stratusxl/raw/main/install/repropie_install.sh
fi

if [ -f "$FILE" ]; then
    echo "$FILE exists."
    mv $FILE $DIRECTORY
else 
    echo "$FILE does not exist."
    exit
fi


