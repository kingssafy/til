if empty(glob('~/.vim/autoload/plug.vim'))
  silent !curl -fLo ~/.vim/autoload/plug.vim --create-dirs
    \ https://raw.githubusercontent.com/junegunn/vim-plug/master/plug.vim
  autocmd VimEnter * PlugInstall --sync | source $MYVIMRC
endif

nnoremap <buffer> <F9> :exec '!python' shellescape(@%, 1)<cr>

"enable 256 color
set t_Co=256


" Specify a directory for plugins
" - For Neovim: ~/.local/share/nvim/plugged
" - Avoid using standard Vim directory names like 'plugin'
call plug#begin('~/.vim/plugged')

"make vim sinsible
Plug 'tpope/vim-sensible'
"VIM-MARKDOWN: Supports .md file and syntax highlight
Plug 'plasticboy/vim-markdown'
"FUGITIVE allow using git in vim
Plug 'tpope/vim-fugitive'
"Vim-airline gives you powerful status bar
Plug 'vim-airline/vim-airline'
"syntax checker
Plug 'scrooloose/syntastic'
"Color Scheme
Plug 'caksoylar/vim-mysticaltutor'
"Python autocomplete
Plug 'davidhalter/jedi-vim'
"autopairs
Plug 'jiangmiao/auto-pairs'
"NERDTree
Plug 'scrooloose/nerdtree'



" Initialize plugin system
call plug#end()
"apply colorscheme
colorscheme mysticaltutor
"followings are syntastics recommended settings.
set statusline+=%#warningmsg#
set statusline+=%{SyntasticStatuslineFlag()}
set statusline+=%*

let g:syntastic_always_populate_loc_list = 1
let g:syntastic_auto_loc_list = 1
let g:syntastic_check_on_open = 1
let g:syntastic_check_on_wq = 0 

" Basic Setting that we need
syntax on
set number
"set relativenumber
set hlsearch
set ignorecase
"followings are replace TABs with x amount of spaces
set expandtab
set shiftwidth=4
set tabstop=4
"set softtabstop=4
filetype plugin indent on

"end


"autocmd FileType make setlocal noexpandtab

" Key Setting - resize windows
nnoremap <silent> <Leader>= :exe "resize +3"<CR>
nnoremap <silent> <Leader>- :exe "resize -3"<CR>
nnoremap <silent> <Leader>] :exe "vertical resize +8"<CR>
nnoremap <silent> <Leader>[ :exe "vertical resize -8"<CR>

nnoremap <silent> <Leader>+ :exe "resize " . (winheight(0) * 3/2)<CR>
nnoremap <silent> <Leader>_ :exe "resize " . (winheight(0) * 2/3)<CR>
nnoremap <silent> <Leader>} :exe "vertical resize " . (winheight(0) * 3/2)<CR>
nnoremap <silent> <Leader>{ :exe "vertical resize " . (winheight(0) * 2/3)<CR>


"NERDTreeToggle to F2
map <F2> :NERDTreeToggle<CR>
"Delete ^g prefix
let g:NERDTreeNodeDelimiter = "\u00a0"
let NERDTreeQuitOnOpen = 1
