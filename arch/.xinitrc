#!/bin/sh

userresources=$HOME/.Xresources
usermodmap=$HOME/.Xmodmap
sysresources=/etc/X11/xinit/.Xresources
sysmodmap=/etc/X11/xinit/.Xmodmap

# merge in defaults and keymaps

if [ -f $sysresources ]; then
    xrdb -merge $sysresources
fi

if [ -f $sysmodmap ]; then
    xmodmap $sysmodmap
fi

if [ -f "$userresources" ]; then
    xrdb -merge "$userresources"
fi

if [ -f "$usermodmap" ]; then
    xmodmap "$usermodmap"
fi

# Set xrandr
#if [ "$(xrandr | grep 'HDMI1 connected')" != "" ]; then
#    xrandr --output HDMI1 --mode 1920x1080
#    xrandr --output eDP1 --off
#fi

# start some nice programs
picom -b --config ~/.picom.conf
#volumeicon &
#./src/scripts/setWallpaperSolid.sh "#8E00FF" &
./src/scripts/setWallpaperRandomPicture.sh &
#xsetroot -solid '#9400D3' &
#xsetroot -solid '#6a329f' &
#xsetroot -solid '#000000' &
#feh --bg-scale ~/pictures/wallpapers/rainbow-wallpaper-desktop_3080151.png &
#feh --bg-scale ~/pictures/wallpapers/680-summer-forest-after-the-rain_dark.jpg &
#feh --bg-scale ~/pictures/wallpapers/programming_doom_code_1920x1080_wallpaper_Wallpaper_HD_2560x1440_www.paperhi.com-violet.jpg &
#feh --bg-scale ~/pictures/wallpapers/8f00ff.png &
#feh --bg-scale ~/pictures/wallpapers/9400d3.png &
#feh --bg-scale ~/pictures/wallpapers/wallpaper_black.jpg &
#feh --bg-scale ~/pictures/wallpapers/wallpaper_00610_peace_2560x1600.jpg &
#feh --bg-scale $(find ~/pictures/wallpapers/*.* -type f | shuf -n 1) &
#xbindkeys &
#autocutsel -fork &
autocutsel -selection PRIMARY -fork &
#syncthing --no-browser &

#if [ -d /etc/X11/xinit/xinitrc.d ] ; then
# for f in /etc/X11/xinit/xinitrc.d/?*.sh ; do
#  [ -x "$f" ] && . "$f"
# done
# unset f
#fi

# dwm statusbar
#dwmstatus 2>&1 >/dev/null &
#slstatus 2>&1 >/dev/null &

# dwm status
# Statusbar loop
while true; do
   xsetroot -name "$( date +"%Y-%m-%d %H:%M" )"
   sleep 1m    # Update time every minute
done &

# Fixing misbehaving Java applications
wmname compiz
export AWT_TOOLKIT=MToolkit

setxkbmap -layout latam -variant deadtilde

#exec startxfce4
#exec startlxde
#exec i3
exec ~/src/scripts/startdwm
#exec dwm
#exec cwm
