SUBMODULES!=	find ../../ -maxdepth 1 -mindepth 1 -type d ! -name "bindings" ! -name "plot" | cut -c 7-

.PHONY: all

gen_submodules:
	./gen_submodules.sh ${SUBMODULES}

all: gen_submodules
	for m in $(SUBMODULES); do \
		$(MAKE) -C $$m; \
	done
	$(MAKE) -C plot

clean:
	for m in $(SUBMODULES); do \
		rm -rf $$m; \
	done
	$(MAKE) -C plot clean

cleandir: clean
	$(MAKE) -C plot cleandir

install:
	for m in $(SUBMODULES); do \
		$(MAKE) -C $$m install; \
	done
	$(MAKE) -C plot install
