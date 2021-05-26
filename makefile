all: 1linkedlist.c 2array.c 3arrayBS.c 4BST.c 5hash.c basic.h data.c main.c searcheddata.c myc.h
	gcc 1linkedlist.c 2array.c 3arrayBS.c 4BST.c 5hash.c data.c main.c searcheddata.c -o a.out
	./a.out -d 1e4 -q 1e3 -ll -arr -bs -bst -hash
	./a.out -d 1e4 -q 1e4 -ll -arr -bs -bst -hash
	./a.out -d 1e4 -q 1e5 -ll -arr -bs -bst -hash
	./a.out -d 1e5 -q 1e3 -ll -arr -bs -bst -hash
	./a.out -d 1e5 -q 1e4 -ll -arr -bs -bst -hash
	./a.out -d 1e5 -q 1e5 -ll -arr -bs -bst -hash
	./a.out -d 1e6 -q 1e3 -ll -arr -bs -bst -hash
	./a.out -d 1e6 -q 1e4 -ll -arr -bs -bst -hash
	./a.out -d 1e6 -q 1e5 -ll -arr -bs -bst -hash