
JAVASRC := $(wildcard *.java)
JAVAOBJ := $(patsubst %.java, %.class, $(JAVASRC))

.PHONY: all clean

all: $(JAVAOBJ)

%.class: %.java
	javac $<

clean:
	rm -f $(JAVAOBJ)

