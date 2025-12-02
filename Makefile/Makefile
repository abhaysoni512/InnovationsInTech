.DEFAULT_GOAL := create_files
#if we want make_dir and create_files run in single command use
all: make_dir create_files

make_dir:
	mkdir -p d1 d2 d3  
#- p means don't do anything

#create files
create_files:
	touch f1.c f2.c f3.c

clear:
	-rm f3.c
	rm -rf d3
#to ignore errors use - : make: [clear] Error 1 (ignored)

