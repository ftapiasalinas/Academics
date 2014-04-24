# `` allows the output of find as the argument for cat
#
cd /run/media/sahil/Sahil\'s\ Gallery/Documents/Dropbox/Academics/sem\ 3-2/CP\ PA\ docs/Lab2/Memory
cat `grep '' -R . | ls */file1.txt` > Cache/file3.txt
