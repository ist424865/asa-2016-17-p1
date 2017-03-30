all: application.c
	@gcc -o application application.c
	@./application < input/1.txt > 1.out
	@./application < input/2.txt > 2.out
	@./application < input/3.txt > 3.out
	@./application < input/4.txt > 4.out
	@cat 1.out
	@echo "\n"
	@cat 2.out
	@echo "\n"
	@cat 3.out
	@echo "\n"
	@cat 4.out
	@echo "\n"