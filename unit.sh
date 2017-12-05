printf "______\n"
printf "MAKE:\n"
printf "______\n"
make re
printf "______\n"
printf "UNIT TESTS:\n"
printf "______\n"
printf "./my_ls -l -aR RECURSIVE\n"
./my_ls -l -aR; echo $?
printf "\n"
printf "./my_ls -l -at SORT\n"
./my_ls -l -at; echo $?
printf "\n"
printf "./my_ls -lr -at REVERSE\n"
./my_ls -lr -at; echo $?
printf "\n"
printf "./my_ls -lR lib/ include/\n"
./my_ls -l lib/ include/; echo $?
printf "______\n"
printf "CLEAN:\n"
printf "______\n"
make fclean
