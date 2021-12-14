" Specify a directory for plugins
" " - For Neovim: stdpath('data') . '/plugged'
" " - Avoid using standard Vim directory names like 'plugin'

set number

" Show matching words during a search.
set showmatch

set visualbell

" Override the ignorecase option if searching for capital letters.
" This will allow you to search specifically for capital letters.
set smartcase

" Enable auto completion menu after pressing TAB.
set wildmenu

" Make wildmenu behave like similar to Bash completion.
set wildmode=list:longest

" There are certain files that we would never want to edit with Vim.
" Wildmenu will ignore files with these extensions.
set wildignore=*.docx,*.jpg,*.png,*.gif,*.pdf,*.pyc,*.exe,*.flv,*.img,*.xlsx

" Ignore capital letters during search.
set ignorecase
 
set shiftwidth=4
set softtabstop=4

set ruler

" Set the commands to save in history default number is 20.
set undolevels=1000
set backspace=indent,eol,start

set background=dark

set expandtab!

"set spell
"set spelllang=en,es

set pastetoggle=<F3>

filetype on
filetype indent on
filetype plugin on
syntax on

" Show partial command you type in the last line of the screen.
set showcmd

" Do not save backup files.
set nobackup

" Highlight cursor line underneath the cursor horizontally.
" set cursorline

" Highlight cursor line underneath the cursor vertically.
" set cursorcolumn

autocmd FileType java set breakindentopt=shift:4

"NERDTree
" Start NERDTree when Vim starts with a directory argument.
autocmd StdinReadPre * let s:std_in=1
autocmd VimEnter * if argc() == 1 && isdirectory(argv()[0]) && !exists('s:std_in') |
    \ execute 'NERDTree' argv()[0] | wincmd p | enew | execute 'cd '.argv()[0] | endif

" Exit Vim if NERDTree is the only window left.
autocmd BufEnter * if tabpagenr('$') == 1 && winnr('$') == 1 && exists('b:NERDTree') && b:NERDTree.isTabTree() |
    \ quit | endif
