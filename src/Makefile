dirs := $(shell find . -maxdepth 1 -type d)
dirs := $(patsubst ./%,%,$(dirs))
DIRS := $(filter-out .%, $(dirs))

all:
	        @for dir in $(DIRS); do make -C $$dir;  echo; done
			cp */*.h ../include/Kid

clean:
	        @for dir in $(DIRS); do make -C $$dir clean; echo; done

cleanall:
	        @for dir in $(DIRS); do make -C $$dir cleanall; echo; done

install:
	        @for dir in $(DIRS); do make -C $$dir cleanall; echo; done
	        @echo "do nothing"

uninstall:
	        @echo "do nothing"

