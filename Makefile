
CC = g++
CFLAGES = -Iinclude -Isrc
VPATH = include:src:.
OBJS = arena.o mstring.o test_main.o
TARGET = test

$(TARGET):$(OBJSDIR) $(OBJS)
	$(CC) -o $(TARGET) $(OBJSDIR)/*.o $(CFLAGES) -g

$(OBJS):%.o:%.cc
	$(CC) -c $(CFLAGES) $< -o $(OBJSDIR)/$@

$(OBJSDIR):
	 mkdir -p ./$@

.PHONY: clean
clean:
	rm -rf $(OBJSDIR)/$(OBJS) $(TARGET) 


