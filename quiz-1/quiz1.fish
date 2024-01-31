mkdir quiz-1
cd quiz-1
touch report.txt
mkdir myfiles
cd myfiles
set words[1] "chair"
set words[2] "banana"
set words[3] "tomato"
for i in (seq 10367 10375)
	mkdir folder$i
	touch folder$i/file$i.txt
	set file_path "/home/kpapadak/myfiles/folder$i/folder$i.txt"
	for j in (seq 1 20)
		echo $words[(random 1 3)] >> folder$i/file$i.txt
		end
	echo "$file_path" >> ../report.txt
	set count_chair (grep -o -w 'chair' folder$i/file$i.txt | wc -l)
	set count_banana (grep -o -w 'banana' folder$i/file$i.txt | wc -l)  
	set count_tomato (grep -o -w 'tomato' folder$i/file$i.txt | wc -l)
	echo "$count_chair chair" >> ../report.txt
	echo "$count_banana banana" >> ../report.txt
	echo "$count_tomato tomato" >> ../report.txt
	echo " " >> ../report.txt
end
