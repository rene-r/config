#!/bin/bash

#  From https://gist.github.com/csivanich/10914698

# Dependencies:
# i3lock
# scrot (optional but default)

IMAGE=/tmp/i3lock.png
SCREENSHOT="scrot $IMAGE" # 0.46s

BLURTYPE="0x5" 
#BLURTYPE="0x2"
#BLURTYPE="5x2"
#BLURTYPE="2x8"
#BLURTYPE="2x3"

# Get the screenshot, add the blur and lock the screen with it
$SCREENSHOT
convert $IMAGE -blur $BLURTYPE $IMAGE
i3lock -i $IMAGE
rm $IMAGE
