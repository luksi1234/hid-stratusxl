!#/bin/bash

DIRECTORY=/home/pi/RetroPie-Setup/scriptmodules/supplementary
FILE=/tmp/stratusxl.sh

echo Download and install module script for Retropie Setup

if [ -d "$DIRECTORY" ]; then
  echo "$DIRECTORY does exist."
  wget -O /tmp/stratusxl.sh https://raw.githubusercontent.com/luksi1234/stratusxl/main/RetroPie-Setup/scriptmodules/supplementary/stratusxl.sh
else
  echo "$DIRECTORY does not exist."
  exit
fi

if [ -f "$FILE" ]; then
    echo "$FILE exists."  
    mv $FILE $DIRECTORY
else 
    echo "$FILE does not exist."
    exit
fi


