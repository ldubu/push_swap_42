#!/bin/bash
setopt shwordsplit
make -f Makefile -C number_generator/
make -f Makefile -C ../
mv number_generator/generator ./
mv ../push_swap ./
mv ../libft.a ./
chmod 777 generator
chmod 777 push_swap
i=0
moyennet=0
moyennec=0
moyenned=0
moyennea=0
pire3=0
pire5=0
pire100=0
pire500=0



echo -e "\n                   \033[1;34mTEST   3 NOMBRES\033[0;0m\n"
while [ $i -le 25 ]
do
	arg=$(./generator 3 -10 5)
	retour=$(./push_swap $arg | ./checker_linux $arg)
	coup=$(./push_swap $arg | wc -l)
if [ $retour = "KO" ]; then
		ok=$(echo -e "	\033[1;31m"$retour"\033[0;0m" $arg $(./push_swap $arg))
	elif [ $retour = "Error" ]; then
		ok=$(echo -e "	\033[1;31m"$retour"\033[0;0m")
	else
		ok=$(echo -e "	\033[1;32m"$retour"\033[0;0m")
	fi
	((moyennet = moyennet + coup))
	if [ $coup -gt $pire3 ]; then
		((pire3 = coup))
	fi
	if [ $coup -lt 4 ]; then
		nbr=$(echo -e "	\033[32m"$coup"\033[0m")
	else
		nbr=$(echo -e "	\033[1;31m"$coup"\033[0;0m")
	fi
	echo -e "\033[1;34mTest $i:\033[0;0m" $ok $nbr 
	((i++))
done


echo -e "\n                   \033[1;34mTEST   5 NOMBRES\033[0;0m\n"
while [ $i -le 75 ]
do
	arg=$(./generator 5 -10 5)
	retour=$(./push_swap $arg | ./checker_linux $arg)
	coup=$(./push_swap $arg | wc -l)
if [ $retour = "KO" ]; then
		ok=$(echo -e "	\033[1;31m"$retour"\033[0;0m" $arg $(./push_swap $arg))
	elif [ $retour = "Error" ]; then
		ok=$(echo -e "	\033[1;31m"$retour"\033[0;0m")
	else
		ok=$(echo -e "	\033[1;32m"$retour"\033[0;0m")
	fi
	((moyennec = moyennec + coup))
	if [ $coup -gt $pire5 ]; then
		((pire5 = coup))
	fi
	if [ $coup -lt 13 ]; then
		nbr=$(echo -e "	\033[32m"$coup"\033[0m")
	else
		nbr=$(echo -e "	\033[1;31m"$coup"\033[0;0m")
	fi
	echo -e "\033[1;34mTest $i:\033[0;0m" $ok $nbr 
	((i++))
done


echo -e "\n                   \033[1;34mTEST 100 NOMBRES\033[0;0m\n"
while [ $i -le 125 ]
do
	arg=$(./generator 100 -400 200)
	retour=$(./push_swap $arg | ./checker_linux $arg)
	coup=$(./push_swap $arg | wc -l)
	if [ $retour = "KO" ]; then
		ok=$(echo -e "	\033[1;31m"$retour"\033[0;0m" $arg $(./push_swap $arg))
	elif [ $retour = "Error" ]; then
		ok=$(echo -e "	\033[1;31m"$retour"\033[0;0m")
	else
		ok=$(echo -e "	\033[1;32m"$retour"\033[0;0m")
	fi
	((moyenned = moyenned + coup))
	if [ $coup -gt $pire100 ]; then
		((pire100 = coup))
	fi
	if [ $coup -lt 1501 ]; then
		nbr=$(echo -e "	\033[32m"$coup"\033[0m")
	else
		nbr=$(echo -e "	\033[1;31m"$coup"\033[0;0m")
	fi
	echo -e "\033[1;34mTest $i:\033[0;0m" $ok $nbr 
	((i++))
done


echo -e "\n                   \033[1;34mTEST 500 NOMBRES\033[0;0m\n"
while [ $i -le 175 ]
do
	arg=$(./generator 500 -400 200)
	retour=$(./push_swap $arg | ./checker_linux $arg)
	coup=$(./push_swap $arg | wc -l)
	if [ $retour = "KO" ]; then
		ok=$(echo -e "	\033[1;31m"$retour"\033[0;0m" $arg $(./push_swap $arg))
	elif [ $retour = "Error" ]; then
		ok=$(echo -e "	\033[1;31m"$retour"\033[0;0m")
	else
		ok=$(echo -e "	\033[1;32m"$retour"\033[0;0m")
	fi
	((moyennea = moyennea + coup))
	if [ $coup -gt $pire500 ]; then
		((pire500 = coup))
	fi
	if [ $coup -lt 11500 ]; then
		nbr=$(echo -e "	\033[32m"$coup"\033[0m")
	else
		nbr=$(echo -e "	\033[1;31m"$coup"\033[0;0m")
	fi
	echo -e "\033[1;34mTest $i:\033[0;0m" $ok $nbr 
	((i++))
done


((moyennet = moyennet / 25))
((moyennec = moyennec / 50))
((moyenned = moyenned / 50))
((moyennea = moyennea / 50))
point100=0
point500=0
note=0
if [ $pire3 -gt 3 ]; then
	message3=$(echo -e "	\033[1;35mTu as plus de 3 coup! KO\033[0;0m")
fi
if [ $pire5 -gt 12 ]; then
	message5=$(echo -e "	\033[1;35mTu as plus de 12 coup! KO\033[0;0m")
fi
if [ $moyenned -gt 1500 ]; then
	message100=$(echo -e "	\033[1;35mTu as plus de 1500 coup! KO\033[0;0m")
elif [ $moyenned -gt 1300 ]; then
	message100=$(echo -e "	\033[1;35m(1 point)\033[0;0m");
	((point100 = 1))
elif [ $moyenned -gt 1100 ]; then
	message100=$(echo -e "	\033[1;35m(2 point)\033[0;0m");
	((point100 = 2))
elif [ $moyenned -gt 900 ]; then
	message100=$(echo -e "	\033[1;35m(3 point)\033[0;0m");
	((point100 = 3))
elif [ $moyenned -gt 900 ]; then
	message100=$(echo -e "	\033[1;35m(4 point)\033[0;0m");
	((point100 = 4))
else
	message100=$(echo -e "	\033[1;35m(5 point)\033[0;0m");
	((point100 = 5))
fi

if [ $moyennea -gt 11500 ]; then
	message500=$(echo -e "	\033[1;35mTu as plus de 1500 coup! KO\033[0;0m")
elif [ $moyennea -gt 10000 ]; then
	message500=$(echo -e "	\033[1;35m(1 point)\033[0;0m");
	((point500 = 1))
elif [ $moyennea -gt 8500 ]; then
	message500=$(echo -e "	\033[1;35m(2 point)\033[0;0m");
	((point500 = 2))
elif [ $moyennea -gt 7000 ]; then
	message500=$(echo -e "	\033[1;35m(3 point)\033[0;0m");
	((point500 = 3))
elif [ $moyennea -gt 5500 ]; then
	message500=$(echo -e "	\033[1;35m(4 point)\033[0;0m");
	((point500 = 4))
else
	message500=$(echo -e "	\033[1;35m(5 point)\033[0;0m");
	((point500 = 5))
fi
((note = 4 * point100 + 6 * point500 + 50))
echo -e "\n\n\033[1;4;34mNombre de coup moyen:\033[0;0m\n"
echo -e "-liste de   3 moyenne =" "\033[35m$moyennet\033[0m" $message3
echo -e "-liste de   5 moyenne =" "\033[35m$moyennec\033[0m" $message5
echo -e "-liste de 100 moyenne =" "\033[35m$moyenned\033[0m" $message100
echo -e "pire resultat pour 100 =" $pire100
echo -e "-liste de 500 moyenne =" "\033[35m$moyennea\033[0m" $message500
echo -e "pire resultat pour 500 =" $pire500 "\n"
normi=$(norminette ../*/*.c ../*/*.h | grep Error | wc -l)
if [ $normi -gt 0 ]; then
	echo -e "\033[1;31mNORME ERROR\033[0;0m"
fi
echo -e "NOTE = " "\033[1;35m$note %\033[0;0m"
echo -e "La note est calculee sur la base qu'un point pour 100 equivaut a 4% et un pour 500 equivaut a 6%."
echo -e "Elle est la a but indicatif et ne correspond pas forcement a ce que vous aurez a la correction."
echo -e "De plus je me base sur le fait que les points sont accorde en fonction de la moyenne du nombre de coups et non du pire nombres d'instructions."
