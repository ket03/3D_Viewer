.PHONY: install uninstall dist clean
CC=g++
CFLAGS=-Wall -Wextra -Werror -std=c++17

install: uninstall
	make clean
	mkdir build
	cd src && qmake && make && make clean && rm Makefile && cd ../ && mv src/viewer.app build

uninstall:
	rm -rf build*

dvi:
	open README.md

dist: install
	rm -rf Viewer/
	mkdir Viewer/
	mkdir Viewer/src
	mv ./build/viewer.app Viewer/src/
	tar cvzf Viewer.tgz Viewer/
	rm -rf Viewer/
	rmdir build

clean:
	cd src && rm -rf *.a && rm -rf *.o  && rm -rf *.dSYM && rm -rf *.out && rm -rf $(EXECUTABLE) && rm -rf CPPLINT.cfg 
	cd src && rm -rf *.info && rm -rf Dist_SmartCalc && rm -rf *tgz && rm -rf build && rm -rf .qmake.stash