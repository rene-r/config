#!/bin/sh

PID=$(pgrep -u $USER gnome-session)

export DBUS_SESSION_BUS_ADDRESS=$(grep -z DBUS_SESSION_BUS_ADDRESS /proc/$PID/environ|cut -d= -f2-)


# /usr/bin/gsettings set org.gnome.shell.extensions.user-theme name 'Flat-Plat-Dark'
# /usr/bin/gsettings set org.gnome.desktop.interface gtk-theme 'Flat-Plat-Dark'
/usr/bin/gsettings set org.gnome.desktop.background picture-uri 'file://WALLPAPER-PATH'
# /usr/bin/gsettings --schemadir ~/.local/share/gnome-shell/extensions/drop-down-terminal@gs-extensions.zzrough.org set org.zzrough.gs-extensions.drop-down-terminal background-color 'rgb(33,33,33)'
