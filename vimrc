" Minimum vimrc, used for ACM practices & real contest
" Settings that should be on by default
syntax on
set bg=dark       " Dark background
set bs=2          " backspace should work as we expect
set autoindent
set ruler         " show cursor position in bottom line
set nu            " show line number
set hlsearch      " highlight search result
" y and d put stuff into system clipboard (so that other apps can see it)
set clipboard=unnamed,unnamedplus
set nowrap
set textwidth=0
set cindent
set timeoutlen=100

" Tab related stuffs
set shiftwidth=4  " tab size = 4
set expandtab
set softtabstop=4
set shiftround    " when shifting non-aligned set of lines, align them to next tabstop

" Searching
set incsearch     " show first match when start typing
set ignorecase    " default should ignore case
set smartcase     " use case sensitive if I use uppercase

function! MyTabCompletion()
  if col('.')>1 && strpart( getline('.'), col('.')-2, 3 ) =~ '^\w'
    return "\<C-P>"
  else
    return "\<Tab>"
  endif
endfunction
inoremap <Tab> <C-R>=MyTabCompletion()<CR>
function! MyComment()
  let l = getline('.')
  if l =~ '^\s*\/\/'
    let l = substitute(l, '\/\/', '', '')
  else
    let l = '//' . l
  endif
  call setline(line('.'), l)
endfunction
nnoremap <C-c> :call MyComment()<CR>

function! CPPSET()
  nnoremap <buffer> <F9> :w<cr>:!g++ % -O2 -o %< -std=c++11 -I ./<cr>:!clear;./%<<cr>
  nnoremap <buffer> <F8> :w<cr>:!g++ % -O2 -o %< -std=c++11 -I ./<cr>
endfunction

function! JAVASET()
  nnoremap <buffer> <F8> :!javac %<cr>
  nnoremap <buffer> <F9> :!javac %<cr>:!clear;java %< %<cr>
endfunction

autocmd FileType cpp    call CPPSET()
autocmd FileType java   call JAVASET()
