TARGET=add-nbo
CXXFLAGS=-g

all: $(TARGET)

$(TARGET): add-nbo.o
	$(LINK.c) $^  $(LOADLIBES) $(LDLIBS) -o $@

clean:
	rm -f $(TARGET)
	rm -f *.0
