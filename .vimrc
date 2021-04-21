" Specify a directory for plugins
" " - For Neovim: stdpath('data') . '/plugged'
" " - Avoid using standard Vim directory names like 'plugin'
call plug#begin('~/.vim/plugged')
Plug 'scrooloose/nerdtree'
Plug 'tpope/vim-surround'
Plug 'scrooloose/syntastic'
Plug 'vim-airline/vim-airline'
Plug 'scrooloose/nerdcommenter'
Plug 'majutsushi/tagbar'
Plug 'ekalinin/dockerfile.vim'
Plug 'elzr/vim-json'
Plug 'w0rp/ale'
Plug 'flazz/vim-colorschemes'

" Initialize plugin system
call plug#end()

set number
set showmatch
set visualbell

set smartcase
set ignorecase
 
set shiftwidth=4
set softtabstop=4

set ruler

set undolevels=1000
set backspace=indent,eol,start

"set spell
"set spelllang=en,es

filetype indent on
filetype plugin on
syntax on

autocmd FileType java set breakindentopt=shift:4

"NERDTree
" Start NERDTree when Vim starts with a directory argument.
autocmd StdinReadPre * let s:std_in=1
autocmd VimEnter * if argc() == 1 && isdirectory(argv()[0]) && !exists('s:std_in') |
    \ execute 'NERDTree' argv()[0] | wincmd p | enew | execute 'cd '.argv()[0] | endif

" Exit Vim if NERDTree is the only window left.
autocmd BufEnter * if tabpagenr('$') == 1 && winnr('$') == 1 && exists('b:NERDTree') && b:NERDTree.isTabTree() |
    \ quit | endif
