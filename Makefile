.PHONY : clean cleanall

teste : teste.o mod.o
	gcc -o teste teste.o mod.o

clean:
	rm -f *.o

cleanall: clean
	rm -f teste
