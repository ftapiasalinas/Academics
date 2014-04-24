cd /run/media/sahil/Sahil\'s\ Gallery/Documents/Dropbox/Academics/sem\ 3-2/CP\ PA\ docs/Lab2/Memory
# ls * is same as ls -R .
ls -R . | cat > ../MemoryContents.txt
ls * | grep -c '.txt' | cat >> ../MemoryContents.txt
