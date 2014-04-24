# piping is of extensive use here. sequence of commands is
# file we put to standard output the contents of both file1.txt and file2.txt of MM directory
# sort the numbers by using the option -n to sort numerically
# then we use tee to send this output to both terminal and file16.txt
# now we use combination of head and tail to get the fifth and sixth line and then close the pipe by 
# sending this output generated as input to file17.txt
cd /run/media/sahil/Sahil\'s\ Gallery/Documents/Dropbox/Academics/sem\ 3-2/CP\ PA\ docs/Lab2/Memory
cat MM/file2.txt MM/file1.txt | sort -n | tee MM/file16.txt | head -6 | tail -2 | cat > MM/file17.txt
