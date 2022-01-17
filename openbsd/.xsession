export ENV=$HOME/.kshrc

# disable bell
xset b off

# load changes in X settings
xrdb -merge ~/.Xresources

# synchronize copy buffers
autocutsel &

# reduce sound to not destroy my ears
sndioctl -f snd/1 output.level=0.3

# compositor for faster windows drawing
picom &

#xsetroot -solid grey &
#xterm -bg black -fg white +sb &
./src/scripts/setWallpaperRandomPicture.ksh

# start syncthing
#syncthing --no-browser &

cwm
