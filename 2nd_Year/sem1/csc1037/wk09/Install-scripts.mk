SCRIPTS := $(wildcard [a-z]*)
INSTALL_DIR := $(HOME)/local/bin

.PHONY: install

install: $(INSTALL_DIR)
	install -v -m 0555 $(SCRIPTS) $(INSTALL_DIR)

$(INSTALL_DIR):
	mkdir -p $(INSTALL_DIR)

