PATH=/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/opt/X11/bin:/usr/texbin:$HOME/.brew/bin
#HISTFILE=~/.zshrc_history
#SAVEHIST=5000
HISTSIZE=5000

setopt inc_append_history
setopt share_history

#if [[ -f ~/.myzshrc ]]; then
#  source ~/.myzshrc
#fi

USER=`/usr/bin/whoami`
export USER
GROUP=`/usr/bin/id -gn $user`
export GROUP
MAIL="$USER@student.42.fr"
export MAIL
#export TERM=ansi
alias l='ls -G'
alias ll='ls -Gla'
alias c='cd ..'
alias g='gcc -Wall -Wextra -Werror'
autoload -U promptinit
promptinit
prompt adam2
alias lk='lockscreen "Un jour Linux vaincra. Mais pas demain, on recompile le kernel."'
alias lk1='lockscreen "~/ sweet ~/"'
alias co='ssh pi@81.64.8.88'
alias gc='git clone'
alias gp='git pull'
alias ga='git add'
alias gm='git commit -m'
alias emacs='echo "NON. VIM." ; sleep 3; vim'
#### ALIAS SUBLIVIM V.0 ####
alias vi="vim"
alias norminator="~/.vim/shells/norminator"
alias -s py="vim"
alias -s php="vim"
alias -s c="vim"
alias -s cpp="vim"
alias -s yml="vim"
alias -s js="vim"
alias -s css="vim"
alias -s scss="vim"
alias -s json="vim"
alias -s twig="vim"
alias -s html="vim"
#### END ALIAS SUBLIVIM ####
