JAVASRC := $(wildcard *.java)
JAVAOBJ := $(patsubst %.java, %.class, $(JAVASRC))

.PHONY: all

all: $(JAVAOBJ)

%.class: %.java
	javac $<

