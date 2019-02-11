if empty(glob('~/.vim/autoload/plug.vim'))
  silent !curl -fLo ~/.vim/autoload/plug.vim --create-dirs
    \ https://raw.githubusercontent.com/junegunn/vim-plug/master/plug.vim
  autocmd VimEnter * PlugInstall --sync | source $MYVIMRC
endif

"nnoremap <buffer> <F9> :exec '!python' shellescape(@%, 1)<cr>
"you can find followings at https://stackoverflow.com/questions/12030965/change-the-mapping-of-f5-on-the-basis-of-specific-file-type
autocmd Filetype c,cpp  nnoremap <buffer> <F5> :update<Bar>execute '!make '.shellescape(expand('%:r'), 1)<CR>
autocmd Filetype python nnoremap <buffer> <F5> :update<Bar>execute '!python '.shellescape(@%, 1)<CR>
autocmd Filetype java   nnoremap <buffer> <F5> :update<Bar>execute '!javac '.shellescape(@%, 1)<CR>
"enable 256 color
set t_Co=256
syntax on

" Specify a directory for plugins
" - For Neovim: ~/.local/share/nvim/plugged
" - Avoid using standard Vim directory names like 'plugin'
call plug#begin('~/.vim/plugged')

"make vim sinsible
Plug 'tpope/vim-sensible'
"VIM-MARKDOWN: Supports .md file and syntax highlight
Plug 'godlygeek/tabular'
Plug 'plasticboy/vim-markdown'
"FUGITIVE allow using git in vim
Plug 'tpope/vim-fugitive'
"Vim-airline gives you powerful status bar
Plug 'vim-airline/vim-airline'
"syntax checker
Plug 'scrooloose/syntastic'
"Color Scheme colorscheme mystictutor
Plug 'caksoylar/vim-mysticaltutor'
"colorscheme Distinguished
Plug 'Lokaltog/vim-distinguished'
"draculai
Plug 'dracula/vim', { 'as': 'dracula' }
"javascript syntax
"Plug 'jelera/vim-javascript-syntax'
"YouCompeleteMe
Plug 'Valloric/YouCompleteMe'
"html emmet
Plug 'mattn/emmet-vim'
"autopairs
Plug 'jiangmiao/auto-pairs'
"NERDTree
Plug 'scrooloose/nerdtree'
"Surround
Plug 'tpope/vim-surround'


"Initialize plugin system
call plug#end()
"apply colorscheme
"colorscheme mysticaltutor
"colorscheme distinguished
colorscheme dracula
"followings are syntastics recommended settings.
set statusline+=%#warningmsg#
set statusline+=%{SyntasticStatuslineFlag()}
set statusline+=%*

let g:syntastic_always_populate_loc_list = 1
let g:syntastic_auto_loc_list = 1
let g:syntastic_check_on_open = 1
let g:syntastic_check_on_wq = 0 

" Basic Setting that we need
"syntax on
set number
"set relativenumber
set hlsearch
set ignorecase
"followings are replace TABs with x amount of spaces
set expandtab
set shiftwidth=4
set tabstop=4
"set softtabstop=4
"https://stackoverflow.com/questions/1562633/setting-vim-whitespace-preferences-by-filetype
autocmd Filetype html setlocal ts=2 sw=2 expandtab
autocmd Filetype ruby setlocal ts=2 sw=2 expandtab
"autocmd Filetype javascript setlocal ts=4 sw=4 sts=0 noexpandtab
autocmd Filetype python setlocal ts=4 sw=4 expandtab
autocmd FileType javascript setlocal ts=2 sw=2 expandtab


filetype plugin indent on

"end


"autocmd FileType make setlocal noexpandtab

" Key Setting - resize windows
let mapleader = ","
nnoremap <silent> <Leader>= :exe "resize +3"<CR>
nnoremap <silent> <Leader>- :exe "resize -3"<CR>
nnoremap <silent> <Leader>] :exe "vertical resize +8"<CR>
nnoremap <silent> <Leader>[ :exe "vertical resize -8"<CR>

nnoremap <silent> <Leader>+ :exe "resize " . (winheight(0) * 3/2)<CR>
nnoremap <silent> <Leader>_ :exe "resize " . (winheight(0) * 2/3)<CR>
nnoremap <silent> <Leader>} :exe "vertical resize " . (winheight(0) * 3/2)<CR>
nnoremap <silent> <Leader>{ :exe "vertical resize " . (winheight(0) * 2/3)<CR>
"vim split windows "
nmap <silent> <A-Up> :wincmd k<CR>
nmap <silent> <A-Down> :wincmd j<CR>
nmap <silent> <A-Left> :wincmd h<CR>
nmap <silent> <A-Right> :wincmd l<CR>
"buffer
nnoremap <leader>q :bp<CR>
nnoremap <leader>w :bn<CR>

""NERDTreeToggle to F2
map <c-b> :NERDTreeToggle<CR>
"Delete ^g prefix
let g:NERDTreeNodeDelimiter = "\u00a0"
let NERDTreeQuitOnOpen = 1

"YCM
let g:ycm_autoclose_preview_window_after_completion = 0
let g:ycm_add_preview_to_completeopt = 1
let g:ycm_seed_identifiers_with_syntax = 1
