PROGRAMNAME = colortable
srcdir = src

colortable: colortable.o $(srcdir)/color.h color.o
	gcc colortable.o color.o -o colortable

colortable.o: $(srcdir)/colortable.c $(srcdir)/color.h
	gcc -c $(srcdir)/colortable.c

color.o: $(srcdir)/color.c $(srcdir)/color.h
	gcc -c $(srcdir)/color.c

clean:
	rm -rf $(PROGRAMNAME) *.o
