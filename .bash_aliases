alias aur_update='for dir in ~/aur/*; do (cd "$dir" && pwd && git pull); done'
alias syncthing='syncthing -no-browser'
alias newsboat_news='newsboat -r -u ~/.newsboat/urls_news -c ~/.newsboat/cache_news.db -C ~/.newsboat/config_news'
alias newsboat_video='newsboat -r -u ~/.newsboat/urls_videos -c ~/.newsboat/cache_videos.db -C ~/.newsboat/config_videos'
alias newsboat_downloads='newsboat -r -u ~/.newsboat/urls_downloads -c ~/.newsboat/cache_downloads.db -C ~/.newsboat/config_downloads'
alias getBatt='upower -i /org/freedesktop/UPower/devices/battery_BAT0'
alias getBattBrief='upower -i /org/freedesktop/UPower/devices/battery_BAT0 | grep -E "state|time\ to\ |percentage"'
alias getBattPercent="upower -i /org/freedesktop/UPower/devices/battery_BAT0 | grep 'percentage' | awk '{print $2}'":
alias getAudioMaster="amixer sget Master | grep 'Right:' | awk -F'[][]' '{print $2}'"
alias dim="echo $(tput cols)x$(tput lines)"
alias systemstats='echo "== Disks ==" && df -h && echo "== Memory ==" && free -h && echo "== CPU ==" && cat /proc/cpuinfo | grep "cpu MHz" && echo "== TEMP ==" && sensors | grep "°C"'
