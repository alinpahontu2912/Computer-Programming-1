build: codeinvim vectsecv ninel nomogram

vectsecv: vectsecv.c
	gcc -Wall -Wextra -std=c99 vectsecv.c -o vectsecv

codeinvim: codeinvim.c
	gcc -Wall -Wextra -std=c99 codeinvim.c -o codeinvim

ninel: ninel.c
	gcc -Wall -Wextra -std=c99 ninel.c -o ninel 

nonogram: nonogram.c
	gcc -Wall -Wextra -std=c99 nomogram.c -o nomogram

clean: 
	-f codeinvim vectsecv ninel nomogram