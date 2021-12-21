all : tp1_compile tp2_compile
	
start_com:
	@echo "------------------------------"
	@echo "Start compile."

tp1_compile:start_com Form.o testprogram1.o
	
	g++ -o testprogram1.out testprogram1.o Form.o -O3
	@echo "End compile."
	@echo "------------------------------"

tp2_compile:start_com Trace.o Vector.o testprogram2.o
	
	g++ -o testprogram2.out testprogram2.o Trace.o Vector.o -O3
	@echo "End compile."
	@echo "------------------------------"

testprogram1.o:
	g++ testprogram1.cpp -c -O3

Form.o:
	g++ Form.cpp -c

testprogram2.o:
	g++ -D__TRACE__ testprogram2.cpp -c -O3
	@# g++ testprogram2.cpp -c -O3

Trace.o:
	g++ Trace.cpp -c

Vector.o:
	g++ Vector.cpp -c

dep:
	@echo "nothing"

clean:
	@echo "------------------------------"
	@echo "Start clean."
	rm -f testprogram2.out -f testprogram1.out *.o
	@echo "Finished clean."
	@echo "------------------------------"

