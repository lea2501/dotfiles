# $OpenBSD: dot.profile,v 1.7 2020/01/24 02:09:51 okan Exp $
#
# sh/ksh initialization

export PATH HOME TERM
export LC_CTYPE=en_US.UTF-8
export GTK_IM_MODULE=xim # without this GTK apps will use their own compose key settings
export LESSCHARSET=utf-8 # not strictly necessary, but for when you view Unicode files in less

# load git prompt
#. ~/src/sh-prompt-simple/prompt.sh
