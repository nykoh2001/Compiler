samples=("bubble" "factorial" "mod" "pal" "perfect" "retval" "test")

for s in "${samples[@]}"
do
  ./ucodei ./Samples/$s.uco ../output/$s.txt &
done