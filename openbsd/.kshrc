export PS1='$USER:$PWD $ '
#export PS1='$USER:$PWD \! $ '
#export PS1='$USER (${PWD##*/}) $ '
alias syncthing='syncthing -no-browser'
alias newsboat_news='newsboat -r -u ~/.newsboat/urls_news -c ~/.newsboat/cache_news.db -C ~/.newsboat/config_news'
alias newsboat_video='newsboat -r -u ~/.newsboat/urls_videos -c ~/.newsboat/cache_videos.db -C ~/.newsboat/config_videos'
alias newsboat_downloads='newsboat -r -u ~/.newsboat/urls_downloads -c ~/.newsboat/cache_downloads.db -C ~/.newsboat/config_downloads'
alias ls='ls -lahF'
alias jdownloader='/usr/local/jdk-11/bin/java -jar $HOME/bin/jdownloader/JDownloader.jar'

# load my ~/.profile file to define ENV
. ~/.profile
