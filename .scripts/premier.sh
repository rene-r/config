#! /bin/bash

echo "le script est lancé..."

#echo "clavier fr"
#setxkbmap fr

#echo "OK"

sudo wpa_supplicant -B -i wlo1 -c /etc/wpa_supplicant/example.conf
echo "carte wifi de merde OK"
#echo "request IP"
#dhcpcd wlo1
