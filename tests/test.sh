#!/bin/bash
setopt shwordsplit
make -f Makefile -C number_generator/
make -f Makefile -C ../
mv number_generator/generator ./
mv ../push_swap ./
mv ../libft.a ./
chmod 777 generator
i=0
moyennet=0
moyennec=0
moyenned=0
echo -e "                   \033[34mTEST 3 NOMBRE\n"
while [ $i -le 25 ]
do
	arg=$(./generator 3 -10 5)
	retour=$(./push_swap $arg | ./checker_linux $arg)
	coup=$(./push_swap $arg | wc -l)
	if [ $retour = "KO" ]; then
		ok=$(echo -e "	\033[31m"$retour"\033[0m" $arg $(./push_swap $arg))
	elif [ $retour = "Error" ]; then
		ok=$(echo -e "	\033[31m"$retour"\033[0m")
	else
		ok=$(echo -e "	\033[32m"$retour"\033[0m")
	fi
	((moyennet = moyennet + coup))
	if [ $coup -lt 4 ]; then
		nbr=$(echo -e "	\033[32m"$coup"\033[0m")
	else
		nbr=$(echo -e "	\033[31m"$coup"\033[0m" $arg "more than 12!" $(./push_swap $arg))
	fi
	echo -e "\033[34mTest $i:" $ok $nbr 
	((i++))
done

echo -e "\n                 \033[34mTEST 5 NOMBRE\n"
while [ $i -le 125 ]
do
	arg=$(./generator 5 -10 5)
	retour=$(./push_swap $arg | ./checker_linux $arg)
	coup=$(./push_swap $arg | wc -l)
	if [ $retour = "KO" ]; then
		ok=$(echo -e "	\033[31m"$retour"\033[0m" $arg $(./push_swap $arg))
	elif [ $retour = "Error" ]; then
		ok=$(echo -e "	\033[31m"$retour"\033[0m")
	else
		ok=$(echo -e "	\033[32m"$retour"\033[0m")
	fi
	((moyennec = moyennec + coup))
	if [ $coup -lt 13 ]; then
		nbr=$(echo -e "	\033[32m"$coup"\033[0m")
	else
		nbr=$(echo -e "	\033[31m"$coup"\033[0m" $arg "more than 12!" $(./push_swap $arg))
	fi
	echo -e "\033[34mTest $i:" $ok $nbr 
	((i++))
done
echo -e "\n                 \033[34mTEST 100 NOMBRE\n"
while [ $i -le 625 ]
do
	arg=$(./generator 100 -200 100)
	#echo -e $arg
	retour=$(./push_swap $arg | ./checker_linux $arg)
	coup=$(./push_swap $arg | wc -l)
	if [ $retour = "KO" ]; then
		ok=$(echo -e "	\033[31m"$retour"\033[0m" $arg $(./push_swap $arg))
	elif [ $retour = "Error" ]; then
		ok=$(echo -e "	\033[31m"$retour"\033[0m")
	else
		ok=$(echo -e "	\033[32m"$retour"\033[0m")
	fi
	((moyenned = moyenned + coup))
	if [ $coup -lt 1500 ]; then
		nbr=$(echo -e "	\033[32m"$coup"\033[0m")
	else
		nbr=$(echo -e "	\033[31m"$coup"\033[0m")
	fi
	echo -e "\033[34mTest $i:" $ok $nbr 
	((i++))
done
((moyennet = moyennet / 25))
((moyennec = moyennec /100))
((moyenned = moyenned /500))
echo -e "\033[34mNombre de coup moyen:\033[0m"
echo -e "-liste de 3 moyenne =" "\033[35m$moyennet\033[0m"
echo -e "-liste de 5 moyenne =" "\033[35m$moyennec\033[0m"
echo -e "-liste de 100 moyenne =" "\033[35m$moyenned\033[0m"