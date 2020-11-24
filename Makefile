all:
	@echo ------------ Setting up files ------------------------
	@echo ""
	@echo Compiling all files
	@gcc a1q1.c -o q1
	@gcc a1q2a.c -o q2a
	@gcc a1q2b.c -o q2b
	@gcc a1q3.c -o q3

	@echo Creating bin/
	@mkdir bin

	@echo Setting up all binaries in bin/
	@mv q1 bin/
	@mv q2a bin/
	@mv q2b bin/
	@mv q3 bin/
	@mv executables.txt bin/

	@echo Organizing Files
	@cd bin && mkdir Question1 && mv q1 Question1/
	@cd bin && mkdir Question2 && mv q2* Question2/
	@cd bin && mkdir Question3 && mv q3 Question3/
	@cd bin && mv executables.txt Question2/
	@echo ""

	@echo --------------------------------------------------
	@echo [+] Find all executables in bin/ folder
	@echo --------------------------------------------------

	@echo ""
	@echo ------------- Installation Finished -------------------
	@echo ""
