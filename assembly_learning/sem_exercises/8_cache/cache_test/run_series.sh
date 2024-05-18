file="cache.log"
line_max=9000
n_runs=5

tmp="${file}.tmp"

# header
echo '"line_size" "n" "GetOrder1" "GetOrder2"' > $tmp

# compile and run
for (( line_size = 8; line_size <= line_max; line_size *= 2 ))
do
	g++ -O3 -DLINE_SIZE="$((line_size - 4))" -o prog cache.cpp
	for (( i = 0; i <= n_runs; ++i ))
	do
		./prog >> $tmp
	done
done

rm ./prog
mv $tmp $file
