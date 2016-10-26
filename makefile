compile: randPlan.c
	gcc randPlan.c -o randPlan

clean:
	rm *~ *.out *.txt randPlan

run: randPlan
	./randPlan
