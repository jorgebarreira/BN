for teste in t1 t2 t3 
do
echo $teste 
./Batalha_Naval < Testes/$teste.in | diff - Testes/$teste.out
done

